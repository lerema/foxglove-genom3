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