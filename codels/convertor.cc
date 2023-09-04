#include "convertor.h"

Convertor::~Convertor()
{
}

Convertor::Convertor(flatbuffers::FlatBufferBuilder &builder) : builder_(builder)
{
}

flatbuffers::Offset<foxglove::RawImage> *Convertor::convert(const or_sensor_frame *frame)
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