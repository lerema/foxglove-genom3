// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TEXTPRIMITIVE_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_TEXTPRIMITIVE_FOXGLOVE_H_

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

struct TextPrimitive;
struct TextPrimitiveBuilder;

inline const ::flatbuffers::TypeTable *ColorTypeTable();

inline const ::flatbuffers::TypeTable *QuaternionTypeTable();

inline const ::flatbuffers::TypeTable *Vector3TypeTable();

inline const ::flatbuffers::TypeTable *PoseTypeTable();

inline const ::flatbuffers::TypeTable *TextPrimitiveTypeTable();

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

/// A primitive representing a text label
struct TextPrimitive FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef TextPrimitiveBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return TextPrimitiveTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSE = 4,
    VT_BILLBOARD = 6,
    VT_FONT_SIZE = 8,
    VT_SCALE_INVARIANT = 10,
    VT_COLOR = 12,
    VT_TEXT = 14
  };
  /// Position of the center of the text box and orientation of the text. Identity orientation means the text is oriented in the xy-plane and flows from -x to +x.
  const foxglove::Pose *pose() const {
    return GetPointer<const foxglove::Pose *>(VT_POSE);
  }
  /// Whether the text should respect `pose.orientation` (false) or always face the camera (true)
  bool billboard() const {
    return GetField<uint8_t>(VT_BILLBOARD, 0) != 0;
  }
  /// Font size (height of one line of text)
  double font_size() const {
    return GetField<double>(VT_FONT_SIZE, 0.0);
  }
  /// Indicates whether `font_size` is a fixed size in screen pixels (true), or specified in world coordinates and scales with distance from the camera (false)
  bool scale_invariant() const {
    return GetField<uint8_t>(VT_SCALE_INVARIANT, 0) != 0;
  }
  /// Color of the text
  const foxglove::Color *color() const {
    return GetPointer<const foxglove::Color *>(VT_COLOR);
  }
  /// Text
  const ::flatbuffers::String *text() const {
    return GetPointer<const ::flatbuffers::String *>(VT_TEXT);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSE) &&
           verifier.VerifyTable(pose()) &&
           VerifyField<uint8_t>(verifier, VT_BILLBOARD, 1) &&
           VerifyField<double>(verifier, VT_FONT_SIZE, 8) &&
           VerifyField<uint8_t>(verifier, VT_SCALE_INVARIANT, 1) &&
           VerifyOffset(verifier, VT_COLOR) &&
           verifier.VerifyTable(color()) &&
           VerifyOffset(verifier, VT_TEXT) &&
           verifier.VerifyString(text()) &&
           verifier.EndTable();
  }
};

struct TextPrimitiveBuilder {
  typedef TextPrimitive Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_pose(::flatbuffers::Offset<foxglove::Pose> pose) {
    fbb_.AddOffset(TextPrimitive::VT_POSE, pose);
  }
  void add_billboard(bool billboard) {
    fbb_.AddElement<uint8_t>(TextPrimitive::VT_BILLBOARD, static_cast<uint8_t>(billboard), 0);
  }
  void add_font_size(double font_size) {
    fbb_.AddElement<double>(TextPrimitive::VT_FONT_SIZE, font_size, 0.0);
  }
  void add_scale_invariant(bool scale_invariant) {
    fbb_.AddElement<uint8_t>(TextPrimitive::VT_SCALE_INVARIANT, static_cast<uint8_t>(scale_invariant), 0);
  }
  void add_color(::flatbuffers::Offset<foxglove::Color> color) {
    fbb_.AddOffset(TextPrimitive::VT_COLOR, color);
  }
  void add_text(::flatbuffers::Offset<::flatbuffers::String> text) {
    fbb_.AddOffset(TextPrimitive::VT_TEXT, text);
  }
  explicit TextPrimitiveBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<TextPrimitive> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<TextPrimitive>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<TextPrimitive> CreateTextPrimitive(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<foxglove::Pose> pose = 0,
    bool billboard = false,
    double font_size = 0.0,
    bool scale_invariant = false,
    ::flatbuffers::Offset<foxglove::Color> color = 0,
    ::flatbuffers::Offset<::flatbuffers::String> text = 0) {
  TextPrimitiveBuilder builder_(_fbb);
  builder_.add_font_size(font_size);
  builder_.add_text(text);
  builder_.add_color(color);
  builder_.add_pose(pose);
  builder_.add_scale_invariant(scale_invariant);
  builder_.add_billboard(billboard);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<TextPrimitive> CreateTextPrimitiveDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<foxglove::Pose> pose = 0,
    bool billboard = false,
    double font_size = 0.0,
    bool scale_invariant = false,
    ::flatbuffers::Offset<foxglove::Color> color = 0,
    const char *text = nullptr) {
  auto text__ = text ? _fbb.CreateString(text) : 0;
  return foxglove::CreateTextPrimitive(
      _fbb,
      pose,
      billboard,
      font_size,
      scale_invariant,
      color,
      text__);
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

inline const ::flatbuffers::TypeTable *TextPrimitiveTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_SEQUENCE, 0, 0 },
    { ::flatbuffers::ET_BOOL, 0, -1 },
    { ::flatbuffers::ET_DOUBLE, 0, -1 },
    { ::flatbuffers::ET_BOOL, 0, -1 },
    { ::flatbuffers::ET_SEQUENCE, 0, 1 },
    { ::flatbuffers::ET_STRING, 0, -1 }
  };
  static const ::flatbuffers::TypeFunction type_refs[] = {
    foxglove::PoseTypeTable,
    foxglove::ColorTypeTable
  };
  static const char * const names[] = {
    "pose",
    "billboard",
    "font_size",
    "scale_invariant",
    "color",
    "text"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 6, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const foxglove::TextPrimitive *GetTextPrimitive(const void *buf) {
  return ::flatbuffers::GetRoot<foxglove::TextPrimitive>(buf);
}

inline const foxglove::TextPrimitive *GetSizePrefixedTextPrimitive(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<foxglove::TextPrimitive>(buf);
}

inline bool VerifyTextPrimitiveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::TextPrimitive>(nullptr);
}

inline bool VerifySizePrefixedTextPrimitiveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::TextPrimitive>(nullptr);
}

inline void FinishTextPrimitiveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::TextPrimitive> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTextPrimitiveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::TextPrimitive> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_TEXTPRIMITIVE_FOXGLOVE_H_
