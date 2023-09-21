#include "convertor.h"
#include "opencv2/opencv.hpp"

Convertor::~Convertor()
{
}

Convertor::Convertor(flatbuffers::FlatBufferBuilder &builder) : builder_(builder)
{
}

flatbuffers::Offset<foxglove::RawImage> *Convertor::convertToRawImage(const or_sensor_frame *frame)
{
    // TODO: Support all image formats
    auto timestamp = foxglove::Time(frame->ts.sec, frame->ts.nsec);
    auto image = foxglove::CreateRawImage(builder_,
                                          &timestamp,
                                          builder_.CreateString("camera"),
                                          frame->width,
                                          frame->height,
                                          builder_.CreateString("rgb8"),
                                          frame->width * 3,
                                          builder_.CreateVector(frame->pixels._buffer, frame->pixels._length));

    return new flatbuffers::Offset<foxglove::RawImage>(image);
}

flatbuffers::Offset<foxglove::Imu> *Convertor::convert(const or_pose_estimator_state *state)
{
    auto timestamp = foxglove::Time(state->ts.sec, state->ts.nsec);
    auto orientation = foxglove::CreateQuaternion(builder_,
                                                  state->att._value.qx,
                                                  state->att._value.qy,
                                                  state->att._value.qz,
                                                  state->att._value.qw);
    auto angular_velocity = foxglove::CreateVector3(builder_,
                                                    state->avel._value.wx,
                                                    state->avel._value.wy,
                                                    state->avel._value.wz);
    auto linear_acceleration = foxglove::CreateVector3(builder_,
                                                       state->acc._value.ax,
                                                       state->acc._value.ay,
                                                       state->acc._value.az);

    auto imu = foxglove::CreateImu(builder_,
                                   &timestamp,
                                   orientation,
                                   angular_velocity,
                                   linear_acceleration);

    return new flatbuffers::Offset<foxglove::Imu>(imu);
}

flatbuffers::Offset<foxglove::TimedVector3> *Convertor::convertToVec(const or_pose_estimator_state *state)
{
    auto timestamp = foxglove::Time(state->ts.sec, state->ts.nsec);
    auto position = foxglove::CreateVector3(builder_,
                                            state->att._value.qx,
                                            state->att._value.qy,
                                            state->att._value.qz);

    auto timed_vector3 = foxglove::CreateTimedVector3(builder_,
                                                      &timestamp,
                                                      position);

    return new flatbuffers::Offset<foxglove::TimedVector3>(timed_vector3);
}

flatbuffers::Offset<foxglove::CompressedImage> *Convertor::convert(const or_sensor_frame *frame)
{
    if (frame->compressed)
    {
      auto timestamp = foxglove::Time(frame->ts.sec, frame->ts.nsec);
      std::vector<uint8_t> compressed = std::vector<uint8_t>(frame->pixels._buffer, frame->pixels._buffer + frame->pixels._length);
      auto image = foxglove::CreateCompressedImage(
          builder_, &timestamp, builder_.CreateString("camera"),
          builder_.CreateVector(compressed),
          builder_.CreateString("jpeg"));

      return new flatbuffers::Offset<foxglove::CompressedImage>(image);
    }

    // Convert the buffer to a cv::Mat
    cv::Mat raw_image(frame->height, frame->width, CV_8UC3, frame->pixels._buffer);
    cv::cvtColor(raw_image, raw_image, cv::COLOR_BGR2RGB);

    // Compression to 50% of original size
    std::vector<uint8_t> compressed;
    std::vector<int> compression_params;
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    compression_params.push_back(50);

    cv::imencode(".jpeg", raw_image, compressed, compression_params);

    auto timestamp = foxglove::Time(frame->ts.sec, frame->ts.nsec);
    auto image = foxglove::CreateCompressedImage(builder_,
                                                 &timestamp,
                                                 builder_.CreateString("camera"),
                                                 builder_.CreateVector(compressed),
                                                 builder_.CreateString("jpeg"));

    return new flatbuffers::Offset<foxglove::CompressedImage>(image);
}

flatbuffers::Offset<foxglove::PoseInFrame> *Convertor::convertToPose(const or_pose_estimator_state *state)
{
    auto timestamp = foxglove::Time(state->ts.sec, state->ts.nsec);
    auto position = foxglove::CreateVector3(builder_,
                                            state->pos._value.x,
                                            state->pos._value.y,
                                            state->pos._value.z);
    auto orientation = foxglove::CreateQuaternion(builder_,
                                                  state->att._value.qx,
                                                  state->att._value.qy,
                                                  state->att._value.qz,
                                                  state->att._value.qw);

    auto pose = foxglove::CreatePose(builder_,
                                     position,
                                     orientation);
    auto pose_in_frame = foxglove::CreatePoseInFrame(builder_,
                                                     &timestamp,
                                                     builder_.CreateString("robot"),
                                                     pose);

    return new flatbuffers::Offset<foxglove::PoseInFrame>(pose_in_frame);
}

flatbuffers::Offset<foxglove::LocationFix> *Convertor::convert(const FoxgloveStudio_solution_s *gps)
{
    auto timestamp = foxglove::Time(gps->ts.sec, gps->ts.nsec);
    foxglove::PositionCovarianceType type = foxglove::PositionCovarianceType_UNKNOWN;
    switch (gps->fix)
    {
    case FoxgloveStudio_fix_none:
        type = foxglove::PositionCovarianceType_UNKNOWN;
        break;
    case FoxgloveStudio_fix_rtk_float:
        type = foxglove::PositionCovarianceType_APPROXIMATED;
        break;
    case FoxgloveStudio_fix_rtk:
        type = foxglove::PositionCovarianceType_KNOWN;
        break;
    default:
        type = foxglove::PositionCovarianceType_UNKNOWN;
        break;
    }
    auto location_fix = foxglove::CreateLocationFix(builder_,
                                                    &timestamp,
                                                    builder_.CreateString("robot"),
                                                    gps->llh.latitude,
                                                    gps->llh.longitude,
                                                    gps->llh.height,
                                                    0,
                                                    type);

    return new flatbuffers::Offset<foxglove::LocationFix>(location_fix);
}