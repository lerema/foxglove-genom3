// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_VECTOR2_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_VECTOR2_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

namespace foxglove {

struct Vector2;

/// A vector in 2D space that represents a direction only
struct Vector2 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_X = 4,
    VT_Y = 6
  };
  /// x coordinate length
  double x() const {
    return GetField<double>(VT_X, 1.0);
  }
  /// y coordinate length
  double y() const {
    return GetField<double>(VT_Y, 1.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_X) &&
           VerifyField<double>(verifier, VT_Y) &&
           verifier.EndTable();
  }
};

struct Vector2Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_x(double x) {
    fbb_.AddElement<double>(Vector2::VT_X, x, 1.0);
  }
  void add_y(double y) {
    fbb_.AddElement<double>(Vector2::VT_Y, y, 1.0);
  }
  explicit Vector2Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  Vector2Builder &operator=(const Vector2Builder &);
  flatbuffers::Offset<Vector2> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Vector2>(end);
    return o;
  }
};

inline flatbuffers::Offset<Vector2> CreateVector2(
    flatbuffers::FlatBufferBuilder &_fbb,
    double x = 1.0,
    double y = 1.0) {
  Vector2Builder builder_(_fbb);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

inline const foxglove::Vector2 *GetVector2(const void *buf) {
  return flatbuffers::GetRoot<foxglove::Vector2>(buf);
}

inline const foxglove::Vector2 *GetSizePrefixedVector2(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<foxglove::Vector2>(buf);
}

inline bool VerifyVector2Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::Vector2>(nullptr);
}

inline bool VerifySizePrefixedVector2Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::Vector2>(nullptr);
}

inline void FinishVector2Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::Vector2> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedVector2Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::Vector2> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_VECTOR2_FOXGLOVE_H_
