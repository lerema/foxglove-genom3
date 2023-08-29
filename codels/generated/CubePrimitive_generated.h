// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CUBEPRIMITIVE_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_CUBEPRIMITIVE_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

#include "Color_generated.h"
#include "Pose_generated.h"
#include "Quaternion_generated.h"
#include "Vector3_generated.h"

namespace foxglove {

struct CubePrimitive;

/// A primitive representing a cube or rectangular prism
struct CubePrimitive FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSE = 4,
    VT_SIZE = 6,
    VT_COLOR = 8
  };
  /// Position of the center of the cube and orientation of the cube
  const Pose *pose() const {
    return GetPointer<const Pose *>(VT_POSE);
  }
  /// Size of the cube along each axis
  const Vector3 *size() const {
    return GetPointer<const Vector3 *>(VT_SIZE);
  }
  /// Color of the cube
  const Color *color() const {
    return GetPointer<const Color *>(VT_COLOR);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSE) &&
           verifier.VerifyTable(pose()) &&
           VerifyOffset(verifier, VT_SIZE) &&
           verifier.VerifyTable(size()) &&
           VerifyOffset(verifier, VT_COLOR) &&
           verifier.VerifyTable(color()) &&
           verifier.EndTable();
  }
};

struct CubePrimitiveBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pose(flatbuffers::Offset<Pose> pose) {
    fbb_.AddOffset(CubePrimitive::VT_POSE, pose);
  }
  void add_size(flatbuffers::Offset<Vector3> size) {
    fbb_.AddOffset(CubePrimitive::VT_SIZE, size);
  }
  void add_color(flatbuffers::Offset<Color> color) {
    fbb_.AddOffset(CubePrimitive::VT_COLOR, color);
  }
  explicit CubePrimitiveBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CubePrimitiveBuilder &operator=(const CubePrimitiveBuilder &);
  flatbuffers::Offset<CubePrimitive> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CubePrimitive>(end);
    return o;
  }
};

inline flatbuffers::Offset<CubePrimitive> CreateCubePrimitive(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Pose> pose = 0,
    flatbuffers::Offset<Vector3> size = 0,
    flatbuffers::Offset<Color> color = 0) {
  CubePrimitiveBuilder builder_(_fbb);
  builder_.add_color(color);
  builder_.add_size(size);
  builder_.add_pose(pose);
  return builder_.Finish();
}

inline const foxglove::CubePrimitive *GetCubePrimitive(const void *buf) {
  return flatbuffers::GetRoot<foxglove::CubePrimitive>(buf);
}

inline const foxglove::CubePrimitive *GetSizePrefixedCubePrimitive(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<foxglove::CubePrimitive>(buf);
}

inline bool VerifyCubePrimitiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::CubePrimitive>(nullptr);
}

inline bool VerifySizePrefixedCubePrimitiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::CubePrimitive>(nullptr);
}

inline void FinishCubePrimitiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::CubePrimitive> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCubePrimitiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::CubePrimitive> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_CUBEPRIMITIVE_FOXGLOVE_H_
