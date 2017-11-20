// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pose.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "pose.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace twbTracking {
namespace proto {

namespace {

const ::google::protobuf::Descriptor* Pose_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Pose_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_pose_2eproto() {
  protobuf_AddDesc_pose_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "pose.proto");
  GOOGLE_CHECK(file != NULL);
  Pose_descriptor_ = file->message_type(0);
  static const int Pose_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pose, translation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pose, rotation_),
  };
  Pose_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Pose_descriptor_,
      Pose::default_instance_,
      Pose_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pose, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pose, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Pose));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_pose_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Pose_descriptor_, &Pose::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_pose_2eproto() {
  delete Pose::default_instance_;
  delete Pose_reflection_;
}

void protobuf_AddDesc_pose_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::twbTracking::proto::protobuf_AddDesc_vertex_2eproto();
  ::twbTracking::proto::protobuf_AddDesc_rotation_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\npose.proto\022\021twbTracking.proto\032\014vertex."
    "proto\032\016rotation.proto\"j\n\004Pose\0223\n\013transla"
    "tion\030\001 \002(\0132\036.twbTracking.proto.Translati"
    "on\022-\n\010rotation\030\002 \002(\0132\033.twbTracking.proto"
    ".Rotation", 169);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "pose.proto", &protobuf_RegisterTypes);
  Pose::default_instance_ = new Pose();
  Pose::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_pose_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_pose_2eproto {
  StaticDescriptorInitializer_pose_2eproto() {
    protobuf_AddDesc_pose_2eproto();
  }
} static_descriptor_initializer_pose_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Pose::kTranslationFieldNumber;
const int Pose::kRotationFieldNumber;
#endif  // !_MSC_VER

Pose::Pose()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:twbTracking.proto.Pose)
}

void Pose::InitAsDefaultInstance() {
  translation_ = const_cast< ::twbTracking::proto::Translation*>(&::twbTracking::proto::Translation::default_instance());
  rotation_ = const_cast< ::twbTracking::proto::Rotation*>(&::twbTracking::proto::Rotation::default_instance());
}

Pose::Pose(const Pose& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:twbTracking.proto.Pose)
}

void Pose::SharedCtor() {
  _cached_size_ = 0;
  translation_ = NULL;
  rotation_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Pose::~Pose() {
  // @@protoc_insertion_point(destructor:twbTracking.proto.Pose)
  SharedDtor();
}

void Pose::SharedDtor() {
  if (this != default_instance_) {
    delete translation_;
    delete rotation_;
  }
}

void Pose::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Pose::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Pose_descriptor_;
}

const Pose& Pose::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_pose_2eproto();
  return *default_instance_;
}

Pose* Pose::default_instance_ = NULL;

Pose* Pose::New() const {
  return new Pose;
}

void Pose::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_translation()) {
      if (translation_ != NULL) translation_->::twbTracking::proto::Translation::Clear();
    }
    if (has_rotation()) {
      if (rotation_ != NULL) rotation_->::twbTracking::proto::Rotation::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Pose::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:twbTracking.proto.Pose)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .twbTracking.proto.Translation translation = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_translation()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_rotation;
        break;
      }

      // required .twbTracking.proto.Rotation rotation = 2;
      case 2: {
        if (tag == 18) {
         parse_rotation:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_rotation()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:twbTracking.proto.Pose)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:twbTracking.proto.Pose)
  return false;
#undef DO_
}

void Pose::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:twbTracking.proto.Pose)
  // required .twbTracking.proto.Translation translation = 1;
  if (has_translation()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->translation(), output);
  }

  // required .twbTracking.proto.Rotation rotation = 2;
  if (has_rotation()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->rotation(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:twbTracking.proto.Pose)
}

::google::protobuf::uint8* Pose::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:twbTracking.proto.Pose)
  // required .twbTracking.proto.Translation translation = 1;
  if (has_translation()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->translation(), target);
  }

  // required .twbTracking.proto.Rotation rotation = 2;
  if (has_rotation()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->rotation(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:twbTracking.proto.Pose)
  return target;
}

int Pose::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .twbTracking.proto.Translation translation = 1;
    if (has_translation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->translation());
    }

    // required .twbTracking.proto.Rotation rotation = 2;
    if (has_rotation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->rotation());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Pose::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Pose* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Pose*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Pose::MergeFrom(const Pose& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_translation()) {
      mutable_translation()->::twbTracking::proto::Translation::MergeFrom(from.translation());
    }
    if (from.has_rotation()) {
      mutable_rotation()->::twbTracking::proto::Rotation::MergeFrom(from.rotation());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Pose::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Pose::CopyFrom(const Pose& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Pose::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_translation()) {
    if (!this->translation().IsInitialized()) return false;
  }
  if (has_rotation()) {
    if (!this->rotation().IsInitialized()) return false;
  }
  return true;
}

void Pose::Swap(Pose* other) {
  if (other != this) {
    std::swap(translation_, other->translation_);
    std::swap(rotation_, other->rotation_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Pose::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Pose_descriptor_;
  metadata.reflection = Pose_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace twbTracking

// @@protoc_insertion_point(global_scope)
