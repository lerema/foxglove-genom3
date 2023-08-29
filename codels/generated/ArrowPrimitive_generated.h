// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ARROWPRIMITIVE_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_ARROWPRIMITIVE_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

#include "Color_generated.h"
#include "Pose_generated.h"
#include "Quaternion_generated.h"
#include "Vector3_generated.h"

namespace foxglove {

struct ArrowPrimitive;

/// A primitive representing an arrow
struct ArrowPrimitive FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSE = 4,
    VT_SHAFT_LENGTH = 6,
    VT_SHAFT_DIAMETER = 8,
    VT_HEAD_LENGTH = 10,
    VT_HEAD_DIAMETER = 12,
    VT_COLOR = 14
  };
  /// Position of the arrow's tail and orientation of the arrow. Identity orientation means the arrow points in the +x direction.
  const Pose *pose() const {
    return GetPointer<const Pose *>(VT_POSE);
  }
  /// Length of the arrow shaft
  double shaft_length() const {
    return GetField<double>(VT_SHAFT_LENGTH, 0.0);
  }
  /// Diameter of the arrow shaft
  double shaft_diameter() const {
    return GetField<double>(VT_SHAFT_DIAMETER, 0.0);
  }
  /// Length of the arrow head
  double head_length() const {
    return GetField<double>(VT_HEAD_LENGTH, 0.0);
  }
  /// Diameter of the arrow head
  double head_diameter() const {
    return GetField<double>(VT_HEAD_DIAMETER, 0.0);
  }
  /// Color of the arrow
  const Color *color() const {
    return GetPointer<const Color *>(VT_COLOR);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSE) &&
           verifier.VerifyTable(pose()) &&
           VerifyField<double>(verifier, VT_SHAFT_LENGTH) &&
           VerifyField<double>(verifier, VT_SHAFT_DIAMETER) &&
           VerifyField<double>(verifier, VT_HEAD_LENGTH) &&
           VerifyField<double>(verifier, VT_HEAD_DIAMETER) &&
           VerifyOffset(verifier, VT_COLOR) &&
           verifier.VerifyTable(color()) &&
           verifier.EndTable();
  }
};

struct ArrowPrimitiveBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pose(flatbuffers::Offset<Pose> pose) {
    fbb_.AddOffset(ArrowPrimitive::VT_POSE, pose);
  }
  void add_shaft_length(double shaft_length) {
    fbb_.AddElement<double>(ArrowPrimitive::VT_SHAFT_LENGTH, shaft_length, 0.0);
  }
  void add_shaft_diameter(double shaft_diameter) {
    fbb_.AddElement<double>(ArrowPrimitive::VT_SHAFT_DIAMETER, shaft_diameter, 0.0);
  }
  void add_head_length(double head_length) {
    fbb_.AddElement<double>(ArrowPrimitive::VT_HEAD_LENGTH, head_length, 0.0);
  }
  void add_head_diameter(double head_diameter) {
    fbb_.AddElement<double>(ArrowPrimitive::VT_HEAD_DIAMETER, head_diameter, 0.0);
  }
  void add_color(flatbuffers::Offset<Color> color) {
    fbb_.AddOffset(ArrowPrimitive::VT_COLOR, color);
  }
  explicit ArrowPrimitiveBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ArrowPrimitiveBuilder &operator=(const ArrowPrimitiveBuilder &);
  flatbuffers::Offset<ArrowPrimitive> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ArrowPrimitive>(end);
    return o;
  }
};

inline flatbuffers::Offset<ArrowPrimitive> CreateArrowPrimitive(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Pose> pose = 0,
    double shaft_length = 0.0,
    double shaft_diameter = 0.0,
    double head_length = 0.0,
    double head_diameter = 0.0,
    flatbuffers::Offset<Color> color = 0) {
  ArrowPrimitiveBuilder builder_(_fbb);
  builder_.add_head_diameter(head_diameter);
  builder_.add_head_length(head_length);
  builder_.add_shaft_diameter(shaft_diameter);
  builder_.add_shaft_length(shaft_length);
  builder_.add_color(color);
  builder_.add_pose(pose);
  return builder_.Finish();
}

inline const foxglove::ArrowPrimitive *GetArrowPrimitive(const void *buf) {
  return flatbuffers::GetRoot<foxglove::ArrowPrimitive>(buf);
}

inline const foxglove::ArrowPrimitive *GetSizePrefixedArrowPrimitive(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<foxglove::ArrowPrimitive>(buf);
}

inline bool VerifyArrowPrimitiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::ArrowPrimitive>(nullptr);
}

inline bool VerifySizePrefixedArrowPrimitiveBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::ArrowPrimitive>(nullptr);
}

inline void FinishArrowPrimitiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::ArrowPrimitive> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedArrowPrimitiveBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::ArrowPrimitive> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_ARROWPRIMITIVE_FOXGLOVE_H_
