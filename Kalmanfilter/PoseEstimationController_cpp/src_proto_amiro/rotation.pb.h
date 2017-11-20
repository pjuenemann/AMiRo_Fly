// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rotation.proto

#ifndef PROTOBUF_rotation_2eproto__INCLUDED
#define PROTOBUF_rotation_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace twbTracking {
namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rotation_2eproto();
void protobuf_AssignDesc_rotation_2eproto();
void protobuf_ShutdownFile_rotation_2eproto();

class Rotation;

// ===================================================================

class Rotation : public ::google::protobuf::Message {
 public:
  Rotation();
  virtual ~Rotation();

  Rotation(const Rotation& from);

  inline Rotation& operator=(const Rotation& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Rotation& default_instance();

  void Swap(Rotation* other);

  // implements Message ----------------------------------------------

  Rotation* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Rotation& from);
  void MergeFrom(const Rotation& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // required float z = 3;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 3;
  inline float z() const;
  inline void set_z(float value);

  // @@protoc_insertion_point(class_scope:twbTracking.proto.Rotation)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  float x_;
  float y_;
  float z_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_rotation_2eproto();
  friend void protobuf_AssignDesc_rotation_2eproto();
  friend void protobuf_ShutdownFile_rotation_2eproto();

  void InitAsDefaultInstance();
  static Rotation* default_instance_;
};
// ===================================================================


// ===================================================================

// Rotation

// required float x = 1;
inline bool Rotation::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Rotation::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Rotation::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Rotation::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Rotation::x() const {
  return x_;
}
inline void Rotation::set_x(float value) {
  set_has_x();
  x_ = value;
}

// required float y = 2;
inline bool Rotation::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Rotation::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Rotation::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Rotation::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Rotation::y() const {
  return y_;
}
inline void Rotation::set_y(float value) {
  set_has_y();
  y_ = value;
}

// required float z = 3;
inline bool Rotation::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Rotation::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Rotation::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Rotation::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline float Rotation::z() const {
  return z_;
}
inline void Rotation::set_z(float value) {
  set_has_z();
  z_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace twbTracking

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rotation_2eproto__INCLUDED
