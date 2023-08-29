// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SCENEENTITYDELETION_FOXGLOVE_H_
#define FLATBUFFERS_GENERATED_SCENEENTITYDELETION_FOXGLOVE_H_

#include "flatbuffers/flatbuffers.h"

#include "Time_generated.h"

namespace foxglove {

struct SceneEntityDeletion;

/// An enumeration indicating which entities should match a SceneEntityDeletion command
enum SceneEntityDeletionType {
  /// Delete the existing entity on the same topic that has the provided `id`
  SceneEntityDeletionType_MATCHING_ID = 0  /// Delete all existing entities on the same topic
,
  SceneEntityDeletionType_ALL = 1,
  SceneEntityDeletionType_MIN = SceneEntityDeletionType_MATCHING_ID,
  SceneEntityDeletionType_MAX = SceneEntityDeletionType_ALL
};

inline const SceneEntityDeletionType (&EnumValuesSceneEntityDeletionType())[2] {
  static const SceneEntityDeletionType values[] = {
    SceneEntityDeletionType_MATCHING_ID,
    SceneEntityDeletionType_ALL
  };
  return values;
}

inline const char * const *EnumNamesSceneEntityDeletionType() {
  static const char * const names[] = {
    "MATCHING_ID",
    "ALL",
    nullptr
  };
  return names;
}

inline const char *EnumNameSceneEntityDeletionType(SceneEntityDeletionType e) {
  if (e < SceneEntityDeletionType_MATCHING_ID || e > SceneEntityDeletionType_ALL) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesSceneEntityDeletionType()[index];
}

/// Command to remove previously published entities
struct SceneEntityDeletion FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TIMESTAMP = 4,
    VT_TYPE = 6,
    VT_ID = 8
  };
  /// Timestamp of the deletion. Only matching entities earlier than this timestamp will be deleted.
  const Time *timestamp() const {
    return GetStruct<const Time *>(VT_TIMESTAMP);
  }
  /// Type of deletion action to perform
  SceneEntityDeletionType type() const {
    return static_cast<SceneEntityDeletionType>(GetField<uint8_t>(VT_TYPE, 0));
  }
  /// Identifier which must match if `type` is `MATCHING_ID`.
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<Time>(verifier, VT_TIMESTAMP) &&
           VerifyField<uint8_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.VerifyString(id()) &&
           verifier.EndTable();
  }
};

struct SceneEntityDeletionBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_timestamp(const Time *timestamp) {
    fbb_.AddStruct(SceneEntityDeletion::VT_TIMESTAMP, timestamp);
  }
  void add_type(SceneEntityDeletionType type) {
    fbb_.AddElement<uint8_t>(SceneEntityDeletion::VT_TYPE, static_cast<uint8_t>(type), 0);
  }
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(SceneEntityDeletion::VT_ID, id);
  }
  explicit SceneEntityDeletionBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SceneEntityDeletionBuilder &operator=(const SceneEntityDeletionBuilder &);
  flatbuffers::Offset<SceneEntityDeletion> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<SceneEntityDeletion>(end);
    return o;
  }
};

inline flatbuffers::Offset<SceneEntityDeletion> CreateSceneEntityDeletion(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Time *timestamp = 0,
    SceneEntityDeletionType type = SceneEntityDeletionType_MATCHING_ID,
    flatbuffers::Offset<flatbuffers::String> id = 0) {
  SceneEntityDeletionBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_timestamp(timestamp);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<SceneEntityDeletion> CreateSceneEntityDeletionDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Time *timestamp = 0,
    SceneEntityDeletionType type = SceneEntityDeletionType_MATCHING_ID,
    const char *id = nullptr) {
  auto id__ = id ? _fbb.CreateString(id) : 0;
  return foxglove::CreateSceneEntityDeletion(
      _fbb,
      timestamp,
      type,
      id__);
}

inline const foxglove::SceneEntityDeletion *GetSceneEntityDeletion(const void *buf) {
  return flatbuffers::GetRoot<foxglove::SceneEntityDeletion>(buf);
}

inline const foxglove::SceneEntityDeletion *GetSizePrefixedSceneEntityDeletion(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<foxglove::SceneEntityDeletion>(buf);
}

inline bool VerifySceneEntityDeletionBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<foxglove::SceneEntityDeletion>(nullptr);
}

inline bool VerifySizePrefixedSceneEntityDeletionBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<foxglove::SceneEntityDeletion>(nullptr);
}

inline void FinishSceneEntityDeletionBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::SceneEntityDeletion> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedSceneEntityDeletionBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<foxglove::SceneEntityDeletion> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace foxglove

#endif  // FLATBUFFERS_GENERATED_SCENEENTITYDELETION_FOXGLOVE_H_
