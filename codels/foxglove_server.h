#ifndef CODELS_WEBSOCKET_SERVER_H_
#define CODELS_WEBSOCKET_SERVER_H_

#include "foxglove/websocket/base64.hpp"
#include "foxglove/websocket/websocket_notls.hpp"
#include "foxglove/websocket/websocket_server.hpp"
#include "foxglove/generated/SceneUpdate_generated.h"
#include "schema.h"

#include <chrono>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <fstream>

namespace foxglove
{
    template <>
    inline void Server<foxglove::WebSocketNoTls>::setupTlsHandler() {}

    static uint64_t nanosecondsSinceEpoch()
    {
        return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count());
    }

    static auto createQuaternionFromAxisAngle(flatbuffers::FlatBufferBuilder &builder, double x,
                                              double y, double z, double angle)
    {
        double s = std::sin(angle / 2);
        return foxglove::CreateQuaternion(builder, x * s, y * s, z * s, std::cos(angle / 2));
    }

    static std::string getFileContents(std::string_view path)
    {
        std::ifstream infile;
        infile.open(path.data(), std::ios::binary | std::ios::in);
        if (!infile)
        {
            throw std::runtime_error("Could not open file " + std::string(path));
        }
        infile.seekg(0, std::ios::end);
        int length = infile.tellg();
        infile.seekg(0, std::ios::beg);
        std::string result(length, '\0');
        infile.read(result.data(), length);
        infile.close();
        return result;
    }

    class FoxgloveWebsocketServer
    {
    public:
        FoxgloveWebsocketServer(const std::string &address, const uint16_t port)
            : address_(address), port_(port)
        {
            const auto logHandler = [](foxglove::WebSocketLogLevel, char const *msg)
            {
                std::cout << msg << std::endl;
            };

            server_ = std::make_unique<foxglove::Server<foxglove::WebSocketNoTls>>("Foxglove Websocket Server", logHandler, options_);

            // Set handlers
            handlers_.subscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle)
            {
                std::cout << "first client subscribed to " << chanId << std::endl;
            };
            handlers_.unsubscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle)
            {
                std::cout << "last client unsubscribed from " << chanId << std::endl;
            };

            // Set up server
            server_->setHandlers(std::move(handlers_));
            server_->start(address_, port_);

            // Set defaults for flatbuffers
            builder_.ForceDefaults(true);

            // Set up signal thread
            signal_thread_ = std::thread([&]()
                                         {
                    waitOnSignal();
                    server_->stop(); });
        }

        FoxgloveWebsocketServer()
        {
            const auto logHandler = [](foxglove::WebSocketLogLevel, char const *msg)
            {
                std::cout << msg << std::endl;
            };

            server_ = std::make_unique<foxglove::Server<foxglove::WebSocketNoTls>>("Foxglove Websocket Genom3 Server", logHandler, options_);

            // Set handlers
            handlers_.subscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle)
            {
                std::cout << "first client subscribed to " << chanId << std::endl;
            };
            handlers_.unsubscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle)
            {
                std::cout << "last client unsubscribed from " << chanId << std::endl;
            };

            // Set defaults for flatbuffers
            builder_.ForceDefaults(true);
        }

        ~FoxgloveWebsocketServer()
        {
            server_->stop();
            signal_thread_.join();
        }

        void startServer(const std::string &address, const uint16_t port)
        {
            // Set up server
            address_ = address;
            port_ = port;

            server_->setHandlers(std::move(handlers_));
            server_->start(address_, port_);

            // Set up signal thread
            signal_thread_ = std::thread([&]()
                                         { waitOnSignal(); });
        }

        void addChannel(const std::string &topic_name, const std::string &schema_name)
        {
            // Create Channel
            foxglove::ChannelWithoutId channel;
            channel.topic = topic_name;
            channel.encoding = "flatbuffer";
            channel.schemaName = schema_name;
            channel.schema = foxglove::base64Encode(getFileContents(schema_.getSchemaDefinitionPath(SchemaDefinition::SceneUpdate)));

            channels_.push_back(channel);

            std::cout << "added channel " << topic_name << std::endl;
        }

        void addChannels()
        {
            channel_ids_ = server_->addChannels(channels_);

            // Map channel ids to channel names
            for (auto &channel_id : channel_ids_)
            {
                auto channel = server_->getChannel(channel_id);
                channel_ids_map_[channel.topic] = channel_id;
                std::cout << "Channel " << channel.topic << " has id " << channel_id << std::endl;
            }
        }

        void
        waitOnSignal()
        {
            websocketpp::lib::asio::signal_set signals_(server_->getEndpoint().get_io_service(), SIGINT);
            signals_.async_wait([&](std::error_code const &ec, int sig)
                                {
                                if (ec)
                                {
                                    std::cerr << "signal error: " << ec.message() << std::endl;
                                    return false;
                                }
                                std::cerr << "received signal " << sig << ", shutting down" << std::endl; });
        }

        void sendData(const std::string &topic_name, const std::string &data)
        {
            const auto now = nanosecondsSinceEpoch();
            auto timestamp = foxglove::Time(now / 1'000'000'000, now % 1'000'000'000);

            builder_.Clear();

            auto pose = foxglove::CreatePose(
                builder_, foxglove::CreateVector3(builder_, 2, 0, 0),
                createQuaternionFromAxisAngle(builder_, 0, 0, 1, double(now) / 1e9 * 0.5));

            auto size = foxglove::CreateVector3(builder_, 1, 1, 1);
            auto color = foxglove::CreateColor(builder_, 0.6, 0.2, 1, 1);
            auto cubeBuilder = foxglove::CubePrimitiveBuilder(builder_);
            cubeBuilder.add_pose(pose);
            cubeBuilder.add_size(size);
            cubeBuilder.add_color(color);
            const auto cube = cubeBuilder.Finish();

            auto frameId = builder_.CreateString("root");
            auto cubes = builder_.CreateVector({cube});
            auto entityBuilder = foxglove::SceneEntityBuilder(builder_);
            entityBuilder.add_timestamp(&timestamp);
            entityBuilder.add_frame_id(frameId);
            entityBuilder.add_cubes(cubes);
            const auto entity = entityBuilder.Finish();

            auto entities = builder_.CreateVector({entity});
            auto updateBuilder = foxglove::SceneUpdateBuilder(builder_);
            updateBuilder.add_entities(entities);
            const auto update = updateBuilder.Finish();
            builder_.Finish(update);

            auto verifier = flatbuffers::Verifier(builder_.GetBufferPointer(), builder_.GetSize());
            if (!foxglove::VerifySceneUpdateBuffer(verifier))
            {
                std::cerr << "Flatbuffer verification failed" << std::endl;
            }

            if (channel_ids_.size() == 0)
            {
                std::cerr << "No channels / port added added" << std::endl;
                return;
            }

            auto chanId = channel_ids_map_.at(topic_name);
            server_->broadcastMessage(chanId, now, builder_.GetBufferPointer(), builder_.GetSize());

            chanId = channel_ids_map_.at("example_pose");
            auto new_pose = foxglove::CreatePose(
                builder_, foxglove::CreateVector3(builder_, 1, 1, 1),
                createQuaternionFromAxisAngle(builder_, 0, 0, 1, double(now) / 1e9 * 0.5));
            builder_.Finish(new_pose);
            server_->broadcastMessage(chanId, now, builder_.GetBufferPointer(), builder_.GetSize());

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

    private:
        std::string address_;
        uint16_t port_;
        foxglove::ServerOptions options_;
        foxglove::ServerHandlers<foxglove::ConnHandle> handlers_;
        std::unique_ptr<foxglove::Server<foxglove::WebSocketNoTls>> server_;

        std::map<std::string, foxglove::ChannelId> channel_ids_map_;
        std::vector<foxglove::ChannelId> channel_ids_;
        std::vector<foxglove::ChannelWithoutId> channels_;

        // Flatbuffers
        flatbuffers::FlatBufferBuilder builder_;

        // Thread
        std::thread signal_thread_;

        // Schema
        Schema schema_;

    }; // class FoxgloveWebsocketServer
} // namespace foxglove
#endif // CODELS_WEBSOCKET_SERVER_H_