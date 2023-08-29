// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MODELPRIMITIVE_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_MODELPRIMITIVE_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 9,
             "Non-compatible flatbuffers version included");

namespace foxglove {

struct Color;
struct ColorBuilder;

struct Quaternion;
struct QuaternionBuilder;

struct Vector3;
struct Vector3Builder;

struct Pose;
struct PoseBuilder;

struct ModelPrimitive;
struct ModelPrimitiveBuilder;

inline const ::flatbuffers::TypeTable *ColorTypeTable();

inline const ::flatbuffers::TypeTable *QuaternionTypeTable();

inline const ::flatbuffers::TypeTable *Vector3TypeTable();

inline const ::flatbuffers::TypeTable *PoseTypeTable();

inline const ::flatbuffers::TypeTable *ModelPrimitiveTypeTable();

/// A color in RGBA format
struct Color FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ColorBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ColorTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_R = 4,
    VT_G = 6,
    VT_B = 8,
    VT_A = 10
  };
  /// Red value between 0 and 1
  double r() const {
    return GetField<double>(VT_R, 1.0);
  }
  /// Green value between 0 and 1
  double g() const {
    return GetField<double>(VT_G, 1.0);
  }
  /// Blue value between 0 and 1
  double b() const {
    return GetField<double>(VT_B, 1.0);
  }
  /// Alpha value between 0 and 1
  double a() const {
    return GetField<double>(VT_A, 1.0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_R, 8) &&
           VerifyField<double>(verifier, VT_G, 8) &&
           VerifyField<double>(verifier, VT_B, 8) &&
           VerifyField<double>(verifier, VT_A, 8) &&
           verifier.EndTable();
  }
};

struct ColorBuilder {
  typedef Color Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_r(double r) {
    fbb_.AddElement<double>(Color::VT_R, r, 1.0);
  }
  void add_g(double g) {
    fbb_.AddElement<double>(Color::VT_G, g, 1.0);
  }
  void add_b(double b) {
    fbb_.AddElement<double>(Color::VT_B, b, 1.0);
  }
  void add_a(double a) {
    fbb_.AddElement<double>(Color::VT_A, a, 1.0);
  }
  explicit ColorBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Color> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Color>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Color> CreateColor(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    double r = 1.0,
    double g = 1.0,
    double b = 1.0,
    double a = 1.0) {
  ColorBuilder builder_(_fbb);
  builder_.add_a(a);
  builder_.add_b(b);
  builder_.add_g(g);
  builder_.add_r(r);
  return builder_.Finish();
}

/// A [quaternion](https://eater.net/quaternions) representing a rotation in 3D space
struct Quaternion FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef QuaternionBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return QuaternionTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_X = 4,
    VT_Y = 6,
    VT_Z = 8,
    VT_W = 10
  };
  /// x value
  double x() const {
    return GetField<double>(VT_X, 0.0);
  }
  /// y value
  double y() const {
    return GetField<double>(VT_Y, 0.0);
  }
  /// z value
  double z() const {
    return GetField<double>(VT_Z, 0.0);
  }
  /// w value
  double w() const {
    return GetField<double>(VT_W, 1.0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_X, 8) &&
           VerifyField<double>(verifier, VT_Y, 8) &&
           VerifyField<double>(verifier, VT_Z, 8) &&
           VerifyField<double>(verifier, VT_W, 8) &&
           verifier.EndTable();
  }
};

struct QuaternionBuilder {
  typedef Quaternion Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_x(double x) {
    fbb_.AddElement<double>(Quaternion::VT_X, x, 0.0);
  }
  void add_y(double y) {
    fbb_.AddElement<double>(Quaternion::VT_Y, y, 0.0);
  }
  void add_z(double z) {
    fbb_.AddElement<double>(Quaternion::VT_Z, z, 0.0);
  }
  void add_w(double w) {
    fbb_.AddElement<double>(Quaternion::VT_W, w, 1.0);
  }
  explicit QuaternionBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Quaternion> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Quaternion>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Quaternion> CreateQuaternion(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    double x = 0.0,
    double y = 0.0,
    double z = 0.0,
    double w = 1.0) {
  QuaternionBuilder builder_(_fbb);
  builder_.add_w(w);
  builder_.add_z(z);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

/// A vector in 3D space that represents a direction only
struct Vector3 FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef Vector3Builder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return Vector3TypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_X = 4,
    VT_Y = 6,
    VT_Z = 8
  };
  /// x coordinate length
  double x() const {
    return GetField<double>(VT_X, 1.0);
  }
  /// y coordinate length
  double y() const {
    return GetField<double>(VT_Y, 1.0);
  }
  /// z coordinate length
  double z() const {
    return GetField<double>(VT_Z, 1.0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_X, 8) &&
           VerifyField<double>(verifier, VT_Y, 8) &&
           VerifyField<double>(verifier, VT_Z, 8) &&
           verifier.EndTable();
  }
};

struct Vector3Builder {
  typedef Vector3 Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_x(double x) {
    fbb_.AddElement<double>(Vector3::VT_X, x, 1.0);
  }
  void add_y(double y) {
    fbb_.AddElement<double>(Vector3::VT_Y, y, 1.0);
  }
  void add_z(double z) {
    fbb_.AddElement<double>(Vector3::VT_Z, z, 1.0);
  }
  explicit Vector3Builder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Vector3> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Vector3>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Vector3> CreateVector3(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    double x = 1.0,
    double y = 1.0,
    double z = 1.0) {
  Vector3Builder builder_(_fbb);
  builder_.add_z(z);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

/// A position and orientation for an object or reference frame in 3D space
struct Pose FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PoseBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return PoseTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSITION = 4,
    VT_ORIENTATION = 6
  };
  /// Point denoting position in 3D space
  const foxglove::Vector3 *position() const {
    return GetPointer<const foxglove::Vector3 *>(VT_POSITION);
  }
  /// Quaternion denoting orientation in 3D space
  const foxglove::Quaternion *orientation() const {
    return GetPointer<const foxglove::Quaternion *>(VT_ORIENTATION);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSITION) &&
           verifier.VerifyTable(position()) &&
           VerifyOffset(verifier, VT_ORIENTATION) &&
           verifier.VerifyTable(orientation()) &&
           verifier.EndTable();
  }
};

struct PoseBuilder {
  typedef Pose Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_position(::flatbuffers::Offset<foxglove::Vector3> position) {
    fbb_.AddOffset(Pose::VT_POSITION, position);
  }
  void add_orientation(::flatbuffers::Offset<foxglove::Quaternion> orientation) {
    fbb_.AddOffset(Pose::VT_ORIENTATION, orientation);
  }
  explicit PoseBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Pose> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Pose>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Pose> CreatePose(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<foxglove::Vector3> position = 0,
    ::flatbuffers::Offset<foxglove::Quaternion> orientation = 0) {
  PoseBuilder builder_(_fbb);
  builder_.add_orientation(orientation);
  builder_.add_position(position);
  return builder_.Finish();
}

/// A primitive representing a 3D model file loaded from an external URL or embedded data
struct ModelPrimitive FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ModelPrimitiveBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ModelPrimitiveTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSE = 4,
    VT_SCALE = 6,
    VT_COLOR = 8,
    VT_OVERRIDE_COLOR = 10,
    VT_URL = 12,
    VT_MEDIA_TYPE = 14,
    VT_DATA = 16
  };
  /// Origin of model relative to reference frame
  const foxglove::Pose *pose() const {
    return GetPointer<const foxglove::Pose *>(VT_POSE);
  }
  /// Scale factor to apply to the model along each axis
  const foxglove::Vector3 *scale() const {
    return GetPointer<const foxglove::Vector3 *>(VT_SCALE);
  }
  /// Solid color to use for the whole model if `override_color` is true.
  const foxglove::Color *color() const {
    return GetPointer<const foxglove::Color *>(VT_COLOR);
  }
  /// Whether to use the color specified in `color` instead of any materials embedded in the original model.
  bool override_color() const {
    return GetField<uint8_t>(VT_OVERRIDE_COLOR, 0) != 0;
  }
  /// URL pointing to model file. One of `url` or `data` should be provided.
  const ::flatbuffers::String *url() const {
    return GetPointer<const ::flatbuffers::String *>(VT_URL);
  }
  /// [Media type](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types) of embedded model (e.g. `model/gltf-binary`). Required if `data` is provided instead of `url`. Overrides the inferred media type if `url` is provided.
  const ::flatbuffers::String *media_type() const {
    return GetPointer<const ::flatbuffers::String *>(VT_MEDIA_TYPE);
  }
  /// Embedded model. One of `url` or `data` should be provided. If `data` is provided, `media_type` must be set to indicate the type of the data.
  const ::flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const ::flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSE) &&
           verifier.VerifyTable(pose()) &&
           VerifyOffset(verifier, VT_SCALE) &&
           verifier.VerifyTable(scale()) &&
           VerifyOffset(verifier, VT_COLOR) &&
           verifier.VerifyTable(color()) &&
           VerifyField<uint8_t>(verifier, VT_OVERRIDE_COLOR, 1) &&
           VerifyOffset(verifier, VT_URL) &&
           verifier.VerifyString(url()) &&
           VerifyOffset(verifier, VT_MEDIA_TYPE) &&
           verifier.VerifyString(media_type()) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct ModelPrimitiveBuilder {
  typedef ModelPrimitive Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_pose(::flatbuffers::Offset<foxglove::Pose> pose) {
    fbb_.AddOffset(ModelPrimitive::VT_POSE, pose);
  }
  void add_scale(::flatbuffers::Offset<foxglove::Vector3> scale) {
    fbb_.AddOffset(ModelPrimitive::VT_SCALE, scale);
  }
  void add_color(::flatbuffers::Offset<foxglove::Color> color) {
    fbb_.AddOffset(ModelPrimitive::VT_COLOR, color);
  }
  void add_override_color(bool override_color) {
    fbb_.AddElement<uint8_t>(ModelPrimitive::VT_OVERRIDE_COLOR, static_cast<uint8_t>(override_color), 0);
  }
  void add_url(::flatbuffers::Offset<::flatbuffers::String> url) {
    fbb_.AddOffset(ModelPrimitive::VT_URL, url);
  }
  void add_media_type(::flatbuffers::Offset<::flatbuffers::String> media_type) {
    fbb_.AddOffset(ModelPrimitive::VT_MEDIA_TYPE, media_type);
  }
  void add_data(::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(ModelPrimitive::VT_DATA, data);
  }
  explicit ModelPrimitiveBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ModelPrimitive> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ModelPrimitive>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ModelPrimitive> CreateModelPrimitive(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<foxglove::Pose> pose = 0,
    ::flatbuffers::Offset<foxglove::Vector3> scale = 0,
    ::flatbuffers::Offset<foxglove::Color> color = 0,
    bool override_color = false,
    ::flatbuffers::Offset<::flatbuffers::String> url = 0,
    ::flatbuffers::Offset<::flatbuffers::String> media_type = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data = 0) {
  ModelPrimitiveBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_media_type(media_type);
  builder_.add_url(url);
  builder_.add_color(color);
  builder_.add_scale(scale);
  builder_.add_pose(pose);
  builder_.add_override_color(override_color);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ModelPrimitive> CreateModelPrimitiveDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<foxglove::Pose> pose = 0,
    ::flatbuffers::Offset<foxglove::Vector3> scale = 0,
    ::flatbuffers::Offset<foxglove::Color> color = 0,
    bool override_color = false,
    const char *url = nullptr,
    const char *media_type = nullptr,
    const std::vector<uint8_t> *data = nullptr) {
  auto url__ = url ? _fbb.CreateString(url) : 0;
  auto media_type__ = media_type ? _fbb.CreateString(media_type) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return foxglove::CreateModelPrimitive(
      _fbb,
      pose,
      scale,
      color,
      override_color,
      url__,
      media_type__,
      data__);
}

inline const ::flatbuffers::TypeTable *ColorTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 }
  };
  static const char * const names[] = {
    "r",
    "g",
    "b",
    "a"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 4, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const ::flatbuffers::TypeTable *QuaternionTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 }
  };
  static const char * const names[] = {
    "x",
    "y",
    "z",
    "w"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 4, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const ::flatbuffers::TypeTable *Vector3TypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 }
  };
  static const char * const names[] = {
    "x",
    "y",
    "z"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 3, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const ::flatbuffers::TypeTable *PoseTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_SEQUENCE, 0, 0 },
    { ::flatbuffers::ET_SEQUENCE, 0, 1 }
  };
  static const ::flatbuffers::TypeFunction type_refs[] = {
    foxglove::Vector3TypeTable,
    foxglove::QuaternionTypeTable
  };
  static const char * const names[] = {
    "position",
    "orientation"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const ::flatbuffers::TypeTable *ModelPrimitiveTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_SEQUENCE, 0, 0 },
    { ::flatbuffers::ET_SEQUENCE, 0, 1 },
    { ::flatbuffers::ET_SEQUENCE, 0, 2 },
    { ::flatbuffers::ET_BOOL, 0, -1 },
    { ::flatbuffers::ET_STRING, 0, -1 },
    { ::flatbuffers::ET_STRING, 0, -1 },
    { ::flatbuffers::ET_UCHAR, 1, -1 }
  };
  static const ::flatbuffers::TypeFunction type_refs[] = {
    foxglove::PoseTypeTable,
    foxglove::Vector3TypeTable,
    foxglove::ColorTypeTable
  };
  static const char * const names[] = {
    "pose",
    "scale",
    "color",
    "override_color",
    "url",
    "media_type",
    "data"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 7, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const foxglove::ModelPrimitive *GetModelPrimitive(const void *buf) {
  return ::flatbuffers::GetRoot<foxglove::ModelPrimitive>(buf);
}

inline const foxglove::ModelPrimitive *GetSizePrefixedModelPrimitive(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<foxglove::ModelPrimitive>(buf);
}

inline bool VerifyModelPrimitiveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::ModelPrimitive>(nullptr);
}

inline bool VerifySizePrefixedModelPrimitiveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::ModelPrimitive>(nullptr);
}

inline void FinishModelPrimitiveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::ModelPrimitive> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedModelPrimitiveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::ModelPrimitive> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_MODELPRIMITIVE_FOXGLOVE_H_
