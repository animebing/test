# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: lm.helloworld.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='lm.helloworld.proto',
  package='lm',
  serialized_pb=_b('\n\x13lm.helloworld.proto\x12\x02lm\"A\n\nhelloworld\x12\n\n\x02id\x18\x01 \x02(\x05\x12\x0b\n\x03str\x18\x02 \x02(\t\x12\x0b\n\x03opt\x18\x03 \x01(\x05\x12\r\n\x05shape\x18\x04 \x03(\x05')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_HELLOWORLD = _descriptor.Descriptor(
  name='helloworld',
  full_name='lm.helloworld',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='lm.helloworld.id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='str', full_name='lm.helloworld.str', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='opt', full_name='lm.helloworld.opt', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='shape', full_name='lm.helloworld.shape', index=3,
      number=4, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=27,
  serialized_end=92,
)

DESCRIPTOR.message_types_by_name['helloworld'] = _HELLOWORLD

helloworld = _reflection.GeneratedProtocolMessageType('helloworld', (_message.Message,), dict(
  DESCRIPTOR = _HELLOWORLD,
  __module__ = 'lm.helloworld_pb2'
  # @@protoc_insertion_point(class_scope:lm.helloworld)
  ))
_sym_db.RegisterMessage(helloworld)


# @@protoc_insertion_point(module_scope)
