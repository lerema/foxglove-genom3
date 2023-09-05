#ifndef CODELS_CONVERTOR_H_
#define CODELS_CONVERTOR_H_

#include "acFoxgloveStudio.h"
#include "FoxgloveStudio_c_types.h"

#include "foxglove/generated/RawImage_generated.h"
#include "foxglove/generated/Pose_generated.h"
#include "foxglove/generated/Imu_generated.h"
#include "foxglove/generated/TimedVector3_generated.h"
#include "foxglove/generated/CompressedImage_generated.h"

class Convertor
{
public:
    Convertor(flatbuffers::FlatBufferBuilder &builder);
    ~Convertor();

    flatbuffers::Offset<foxglove::RawImage> *convertToRawImage(const or_sensor_frame *frame);
    // foxglove::Pose *convert(const or_pose_estimator_frame *frame, const genom_context self);
    flatbuffers::Offset<foxglove::CompressedImage> *convert(const or_sensor_frame *image);
    flatbuffers::Offset<foxglove::Imu> *convert(const or_pose_estimator_state *state);
    flatbuffers::Offset<foxglove::TimedVector3> *convertToVec(const or_pose_estimator_state *state);

private:
    flatbuffers::FlatBufferBuilder &builder_;
};

#endif // CODELS_CONVERTOR_H_