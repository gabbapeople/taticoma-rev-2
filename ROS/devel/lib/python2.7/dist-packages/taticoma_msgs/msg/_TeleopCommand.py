# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from taticoma_msgs/TeleopCommand.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class TeleopCommand(genpy.Message):
  _md5sum = "175d84f8f67bfd93cb04e6fb561123b6"
  _type = "taticoma_msgs/TeleopCommand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
float32[4] axes
float32[2] a_buttons
uint8[2] p_buttons
uint8[2] buttons

uint8 mode
uint8 gait_mode
"""
  __slots__ = ['axes','a_buttons','p_buttons','buttons','mode','gait_mode']
  _slot_types = ['float32[4]','float32[2]','uint8[2]','uint8[2]','uint8','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       axes,a_buttons,p_buttons,buttons,mode,gait_mode

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TeleopCommand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.axes is None:
        self.axes = [0.] * 4
      if self.a_buttons is None:
        self.a_buttons = [0.] * 2
      if self.p_buttons is None:
        self.p_buttons = b'\0'*2
      if self.buttons is None:
        self.buttons = b'\0'*2
      if self.mode is None:
        self.mode = 0
      if self.gait_mode is None:
        self.gait_mode = 0
    else:
      self.axes = [0.] * 4
      self.a_buttons = [0.] * 2
      self.p_buttons = b'\0'*2
      self.buttons = b'\0'*2
      self.mode = 0
      self.gait_mode = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_4f().pack(*self.axes))
      buff.write(_get_struct_2f().pack(*self.a_buttons))
      _x = self.p_buttons
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_2B().pack(*_x))
      else:
        buff.write(_get_struct_2s().pack(_x))
      _x = self.buttons
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_2B().pack(*_x))
      else:
        buff.write(_get_struct_2s().pack(_x))
      _x = self
      buff.write(_get_struct_2B().pack(_x.mode, _x.gait_mode))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 16
      self.axes = _get_struct_4f().unpack(str[start:end])
      start = end
      end += 8
      self.a_buttons = _get_struct_2f().unpack(str[start:end])
      start = end
      end += 2
      self.p_buttons = str[start:end]
      start = end
      end += 2
      self.buttons = str[start:end]
      _x = self
      start = end
      end += 2
      (_x.mode, _x.gait_mode,) = _get_struct_2B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.axes.tostring())
      buff.write(self.a_buttons.tostring())
      _x = self.p_buttons
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_2B().pack(*_x))
      else:
        buff.write(_get_struct_2s().pack(_x))
      _x = self.buttons
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_2B().pack(*_x))
      else:
        buff.write(_get_struct_2s().pack(_x))
      _x = self
      buff.write(_get_struct_2B().pack(_x.mode, _x.gait_mode))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 16
      self.axes = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=4)
      start = end
      end += 8
      self.a_buttons = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=2)
      start = end
      end += 2
      self.p_buttons = str[start:end]
      start = end
      end += 2
      self.buttons = str[start:end]
      _x = self
      start = end
      end += 2
      (_x.mode, _x.gait_mode,) = _get_struct_2B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4f = None
def _get_struct_4f():
    global _struct_4f
    if _struct_4f is None:
        _struct_4f = struct.Struct("<4f")
    return _struct_4f
_struct_2f = None
def _get_struct_2f():
    global _struct_2f
    if _struct_2f is None:
        _struct_2f = struct.Struct("<2f")
    return _struct_2f
_struct_2B = None
def _get_struct_2B():
    global _struct_2B
    if _struct_2B is None:
        _struct_2B = struct.Struct("<2B")
    return _struct_2B
_struct_2s = None
def _get_struct_2s():
    global _struct_2s
    if _struct_2s is None:
        _struct_2s = struct.Struct("<2s")
    return _struct_2s
