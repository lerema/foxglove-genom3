// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_KEYVALUEPAIR_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_KEYVALUEPAIR_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 9,
             "Non-compatible flatbuffers version included");

namespace foxglove {

struct KeyValuePair;
struct KeyValuePairBuilder;

inline const ::flatbuffers::TypeTable *KeyValuePairTypeTable();

/// A key with its associated value
struct KeyValuePair FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef KeyValuePairBuilder Builder;
  static const ::flatbuffers::TypeTable *MiniReflectTypeTable() {
    return KeyValuePairTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  /// Key
  const ::flatbuffers::String *key() const {
    return GetPointer<const ::flatbuffers::String *>(VT_KEY);
  }
  /// Value
  const ::flatbuffers::String *value() const {
    return GetPointer<const ::flatbuffers::String *>(VT_VALUE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyString(value()) &&
           verifier.EndTable();
  }
};

struct KeyValuePairBuilder {
  typedef KeyValuePair Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_key(::flatbuffers::Offset<::flatbuffers::String> key) {
    fbb_.AddOffset(KeyValuePair::VT_KEY, key);
  }
  void add_value(::flatbuffers::Offset<::flatbuffers::String> value) {
    fbb_.AddOffset(KeyValuePair::VT_VALUE, value);
  }
  explicit KeyValuePairBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<KeyValuePair> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<KeyValuePair>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<KeyValuePair> CreateKeyValuePair(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> key = 0,
    ::flatbuffers::Offset<::flatbuffers::String> value = 0) {
  KeyValuePairBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<KeyValuePair> CreateKeyValuePairDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const char *value = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateString(value) : 0;
  return foxglove::CreateKeyValuePair(
      _fbb,
      key__,
      value__);
}

inline const ::flatbuffers::TypeTable *KeyValuePairTypeTable() {
  static const ::flatbuffers::TypeCode type_codes[] = {
    { ::flatbuffers::ET_STRING, 0, -1 },
    { ::flatbuffers::ET_STRING, 0, -1 }
  };
  static const char * const names[] = {
    "key",
    "value"
  };
  static const ::flatbuffers::TypeTable tt = {
    ::flatbuffers::ST_TABLE, 2, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const foxglove::KeyValuePair *GetKeyValuePair(const void *buf) {
  return ::flatbuffers::GetRoot<foxglove::KeyValuePair>(buf);
}

inline const foxglove::KeyValuePair *GetSizePrefixedKeyValuePair(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<foxglove::KeyValuePair>(buf);
}

inline bool VerifyKeyValuePairBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::KeyValuePair>(nullptr);
}

inline bool VerifySizePrefixedKeyValuePairBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::KeyValuePair>(nullptr);
}

inline void FinishKeyValuePairBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::KeyValuePair> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedKeyValuePairBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<foxglove::KeyValuePair> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_KEYVALUEPAIR_FOXGLOVE_H_
