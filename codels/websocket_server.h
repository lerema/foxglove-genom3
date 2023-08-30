#ifndef CODELS_WEBSOCKET_SERVER_H_
#define CODELS_WEBSOCKET_SERVER_H_

#include "foxglove/websocket/base64.hpp"
#include "foxglove/websocket/websocket_notls.hpp"
#include "foxglove/websocket/websocket_server.hpp"
#include "foxglove/generated/SceneUpdate_generated.h"


#include <chrono>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <thread>

namespace foxglove {
template <>
inline void Server<foxglove::WebSocketNoTls>::setupTlsHandler() {}

static uint64_t nanosecondsSinceEpoch() {
  return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count());
}

static auto createQuaternionFromAxisAngle(flatbuffers::FlatBufferBuilder& builder, double x,
                                          double y, double z, double angle) {
  double s = std::sin(angle / 2);
  return foxglove::CreateQuaternion(builder, x * s, y * s, z * s, std::cos(angle / 2));
}

class FoxgloveWebsocketServer {
    public:
        FoxgloveWebsocketServer(const std::string &address, const uint16_t port)
            : address_(address), port_(port)
            {
                const auto logHandler = [](foxglove::WebSocketLogLevel, char const* msg) {
                    std::cout << msg << std::endl;
                };

                server_ = std::make_unique<foxglove::Server<foxglove::WebSocketNoTls>>("Foxglove Websocket Server", logHandler, options_);

                // Set handlers
                handlers_.subscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle) {
                    std::cout << "first client subscribed to " << chanId << std::endl;
                };
                handlers_.unsubscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle) {
                    std::cout << "last client unsubscribed from " << chanId << std::endl;
                };

                // Set up server
                server_->setHandlers(std::move(handlers_));
                server_->start(address_, port_);

                // Set defaults for flatbuffers
                builder_.ForceDefaults(true);

                // Set up signal thread
                signal_thread_ = std::thread([&]() {
                    waitOnSignal();
                    server_->stop();
                });
            }
        
        FoxgloveWebsocketServer()
            {
                const auto logHandler = [](foxglove::WebSocketLogLevel, char const* msg) {
                    std::cout << msg << std::endl;
                };

                server_ = std::make_unique<foxglove::Server<foxglove::WebSocketNoTls>>("Foxglove Websocket Server", logHandler, options_);

                // Set handlers
                handlers_.subscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle) {
                    std::cout << "first client subscribed to " << chanId << std::endl;
                };
                handlers_.unsubscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle) {
                    std::cout << "last client unsubscribed from " << chanId << std::endl;
                };
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

                // Set defaults for flatbuffers
                builder_.ForceDefaults(true);

                // Set up signal thread
                signal_thread_ = std::thread([&]() {
                    waitOnSignal();
                    server_->stop();
                });
            }

            void addChannel(const std::string &topic_name, const std::string &schema_name)
            {
                std::map<std::string, std::string> channel_data;
                channel_data["topic_name"] = topic_name;
                channel_data["schema_name"] = schema_name;
                channel_data_.push_back(channel_data);
            }

            bool addChannels() {
                for (auto &channel_data : channel_data_) {
                    auto topic_name = channel_data["topic_name"];
                    auto schema_name = channel_data["schema_name"];
                    auto schema = foxglove::base64Encode(schema_name);
                    
                    channel_ids_ = server_->addChannels({{
                        .topic = topic_name,
                        .encoding = "flatbuffer",
                        .schemaName = schema_name,
                        .schema = schema,
                    }});

                    std::cout << "added channel " << topic_name << std::endl;
                }
                return true;
            }

            bool waitOnSignal()
            {
                websocketpp::lib::asio::signal_set signals_(server_->getEndpoint().get_io_service(), SIGINT, SIGTERM);
                signals_.async_wait([&](std::error_code const& ec, int sig) {
                if (ec) {
                    std::cerr << "signal error: " << ec.message() << std::endl;
                    return false;
                    }
                    std::cerr << "received signal " << sig << ", shutting down" << std::endl;
                });
                return true;
            }

            void sendData(const std::string &topic_name, const std::string &data)
            {
                const auto now = nanosecondsSinceEpoch();
                auto timestamp = foxglove::Time(now / 1'000'000'000, now % 1'000'000'000);

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
                if (!foxglove::VerifySceneUpdateBuffer(verifier)) {
                std::cerr << "Flatbuffer verification failed" << std::endl;
                }

                auto chanId = channel_ids_.front();
                server_->broadcastMessage(chanId, now, builder_.GetBufferPointer(), builder_.GetSize());
            }



        private:
            std::string address_;
            uint16_t port_;
            foxglove::ServerOptions options_;
            foxglove::ServerHandlers<foxglove::ConnHandle> handlers_;
            std::unique_ptr<foxglove::Server<foxglove::WebSocketNoTls>> server_;

            std::vector<std::map<std::string, std::string>> channel_data_;
            std::vector<foxglove::ChannelId> channel_ids_;

            // Flatbuffers
            flatbuffers::FlatBufferBuilder builder_;

            // Thread
            std::thread signal_thread_;

}; // class FoxgloveWebsocketServer
} // namespace foxglove
#endif // CODELS_WEBSOCKET_SERVER_H_