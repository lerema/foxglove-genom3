// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_COMPRESSEDIMAGE_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_COMPRESSEDIMAGE_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 9,
             "Non-compatible flatbuffers version included");

namespace foxglove {

struct Time;

struct CompressedImage;
struct CompressedImageBuilder;

inline const ::flatbuffers::TypeTable *TimeTypeTable();

inline const ::flatbuffers::TypeTable *CompressedImageTypeTable();

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Time FLATBUFFERS_FINAL_CLASS {
 private:
  uint32_t sec_;
  uint32_t nsec_;

 public:
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return TimeTypeTable();
  }
  Time()
      : sec_(0),
        nsec_(0) {
  }
  Time(uint32_t _sec, uint32_t _nsec)
      : sec_(::flatbuffers::EndianScalar(_sec)),
        nsec_(::flatbuffers::EndianScalar(_nsec)) {
  }
  /// Represents seconds of UTC time since Unix epoch 1970-01-01T00:00:00Z
  uint32_t sec() const {
    return ::flatbuffers::EndianScalar(sec_);
  }
  /// Nano-second fractions from 0 to 999,999,999 inclusive
  uint32_t nsec() const {
    return ::flatbuffers::EndianScalar(nsec_);
  }
};
FLATBUFFERS_STRUCT_END(Time, 8);

/// A compressed image
struct CompressedImage FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef CompressedImageBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return CompressedImageTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TIMESTAMP = 4,
    VT_FRAME_ID = 6,
    VT_DATA = 8,
    VT_FORMAT = 10
  };
  /// Timestamp of image
  const foxglove::Time *timestamp() const {
    return GetStruct<const foxglove::Time *>(VT_TIMESTAMP);
  }
  /// Frame of reference for the image. The origin of the frame is the optical center of the camera. +x points to the right in the image, +y points down, and +z points into the plane of the image.
  const ::flatbuffers::String *frame_id() const {
    return GetPointer<const ::flatbuffers::String *>(VT_FRAME_ID);
  }
  /// Compressed image data
  const ::flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const ::flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  /// Image format
  /// 
  /// Supported values: `webp`, `jpeg`, `png`
  const ::flatbuffers::String *format() const {
    return GetPointer<const ::flatbuffers::String *>(VT_FORMAT);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<foxglove::Time>(verifier, VT_TIMESTAMP, 4) &&
           VerifyOffset(verifier, VT_FRAME_ID) &&
           verifier.VerifyString(frame_id()) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           VerifyOffset(verifier, VT_FORMAT) &&
           verifier.VerifyString(format()) &&
           verifier.EndTable();
  }
};

struct CompressedImageBuilder {
  typedef CompressedImage Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_timestamp(const foxglove::Time *timestamp) {
    fbb_.AddStruct(CompressedImage::VT_TIMESTAMP, timestamp);
  }
  void add_frame_id(::flatbuffers::Offset<::flatbuffers::String> frame_id) {
    fbb_.AddOffset(CompressedImage::VT_FRAME_ID, frame_id);
  }
  void add_data(::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(CompressedImage::VT_DATA, data);
  }
  void add_format(::flatbuffers::Offset<::flatbuffers::String> format) {
    fbb_.AddOffset(CompressedImage::VT_FORMAT, format);
  }
  explicit CompressedImageBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<CompressedImage> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<CompressedImage>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<CompressedImage> CreateCompressedImage(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const foxglove::Time *timestamp = nullptr,
    ::flatbuffers::Offset<::flatbuffers::String> frame_id = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data = 0,
    ::flatbuffers::Offset<::flatbuffers::String> format = 0) {
  CompressedImageBuilder builder_(_fbb);
  builder_.add_format(format);
  builder_.add_data(data);
  builder_.add_frame_id(frame_id);
  builder_.add_timestamp(timestamp);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<CompressedImage> CreateCompressedImageDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const foxglove::Time *timestamp = nullptr,
    const char *frame_id = nullptr,
    const std::vector<uint8_t> *data = nullptr,
    const char *format = nullptr) {
  auto frame_id__ = frame_id ? _fbb.CreateString(frame_id) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  auto format__ = format ? _fbb.CreateString(format) : 0;
  return foxglove::CreateCompressedImage(
      _fbb,
      timestamp,
      frame_id__,
      data__,
      format__);
}

inline const ::flatbuffers::TypeTable *TimeTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_UINT, 0, -1 },
    { ::flatbuffers::ET_UINT, 0, -1 }
  };
  static const int64_t values[] = { 0, 4, 8 };
  static const char * const names[] = {
    "sec",
    "nsec"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_STRUCT, 2, type_codes, nullptr, nullptr, values, names
  };
  return &tt;
}

inline const ::flatbuffers::TypeTable *CompressedImageTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_SEQUENCE, 0, 0 },
    { ::flatbuffers::ET_STRING, 0, -1 },
    { ::flatbuffers::ET_UCHAR, 1, -1 },
    { ::flatbuffers::ET_STRING, 0, -1 }
  };
  static const ::flatbuffers::TypeFunction type_refs[] = {
    foxglove::TimeTypeTable
  };
  static const char * const names[] = {
    "timestamp",
    "frame_id",
    "data",
    "format"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 4, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const foxglove::CompressedImage *GetCompressedImage(const void *buf) {
  return ::flatbuffers::GetRoot<foxglove::CompressedImage>(buf);
}

inline const foxglove::CompressedImage *GetSizePrefixedCompressedImage(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<foxglove::CompressedImage>(buf);
}

inline bool VerifyCompressedImageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::CompressedImage>(nullptr);
}

inline bool VerifySizePrefixedCompressedImageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::CompressedImage>(nullptr);
}

inline void FinishCompressedImageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::CompressedImage> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCompressedImageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::CompressedImage> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_COMPRESSEDIMAGE_FOXGLOVE_H_