#include "convertor.h"

Convertor::~Convertor()
{
}

Convertor::Convertor(flatbuffers::FlatBufferBuilder &builder) : builder_(builder)
{
}

flatbuffers::Offset<foxglove::RawImage> Convertor::convert(const or_sensor_frame *frame)
{
    // TODO: Support all image formats
    auto timestamp = foxglove::Time(frame->ts.sec, frame->ts.nsec);
    return foxglove::CreateRawImage(builder_,
                                    &timestamp,
                                    builder_.CreateString("camera"),
                                    frame->width,
                                    frame->height,
                                    builder_.CreateString("rgb8"),
                                    frame->width * 3,
                                    builder_.CreateVector<uint8_t>(frame->pixels._buffer, frame->pixels._length));
}