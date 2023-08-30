// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_BYTEVECTOR_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_BYTEVECTOR_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 9,
             "Non-compatible flatbuffers version included");

namespace foxglove {

struct ByteVector;
struct ByteVectorBuilder;

inline const ::flatbuffers::TypeTable *ByteVectorTypeTable();

/// Used for nesting byte vectors
struct ByteVector FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ByteVectorBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ByteVectorTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_DATA = 4
  };
  const ::flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const ::flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct ByteVectorBuilder {
  typedef ByteVector Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_data(::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(ByteVector::VT_DATA, data);
  }
  explicit ByteVectorBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ByteVector> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ByteVector>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ByteVector> CreateByteVector(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> data = 0) {
  ByteVectorBuilder builder_(_fbb);
  builder_.add_data(data);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ByteVector> CreateByteVectorDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *data = nullptr) {
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return foxglove::CreateByteVector(
      _fbb,
      data__);
}

inline const ::flatbuffers::TypeTable *ByteVectorTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_UCHAR, 1, -1 }
  };
  static const char * const names[] = {
    "data"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 1, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const foxglove::ByteVector *GetByteVector(const void *buf) {
  return ::flatbuffers::GetRoot<foxglove::ByteVector>(buf);
}

inline const foxglove::ByteVector *GetSizePrefixedByteVector(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<foxglove::ByteVector>(buf);
}

inline bool VerifyByteVectorBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::ByteVector>(nullptr);
}

inline bool VerifySizePrefixedByteVectorBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::ByteVector>(nullptr);
}

inline void FinishByteVectorBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::ByteVector> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedByteVectorBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::ByteVector> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_BYTEVECTOR_FOXGLOVE_H_