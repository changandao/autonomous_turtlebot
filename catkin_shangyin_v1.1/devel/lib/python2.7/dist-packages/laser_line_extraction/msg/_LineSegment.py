# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from laser_line_extraction/LineSegment.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class LineSegment(genpy.Message):
  _md5sum = "0b798f1cd276e61d7015b3e32ccd5c78"
  _type = "laser_line_extraction/LineSegment"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32 radius
float32 angle
float32[4] covariance
float32[2] start
float32[2] end
"""
  __slots__ = ['radius','angle','covariance','start','end']
  _slot_types = ['float32','float32','float32[4]','float32[2]','float32[2]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       radius,angle,covariance,start,end

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LineSegment, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.radius is None:
        self.radius = 0.
      if self.angle is None:
        self.angle = 0.
      if self.covariance is None:
        self.covariance = [0.] * 4
      if self.start is None:
        self.start = [0.] * 2
      if self.end is None:
        self.end = [0.] * 2
    else:
      self.radius = 0.
      self.angle = 0.
      self.covariance = [0.] * 4
      self.start = [0.] * 2
      self.end = [0.] * 2

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
      _x = self
      buff.write(_get_struct_2f().pack(_x.radius, _x.angle))
      buff.write(_get_struct_4f().pack(*self.covariance))
      buff.write(_get_struct_2f().pack(*self.start))
      buff.write(_get_struct_2f().pack(*self.end))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.radius, _x.angle,) = _get_struct_2f().unpack(str[start:end])
      start = end
      end += 16
      self.covariance = _get_struct_4f().unpack(str[start:end])
      start = end
      end += 8
      self.start = _get_struct_2f().unpack(str[start:end])
      start = end
      end += 8
      self.end = _get_struct_2f().unpack(str[start:end])
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
      _x = self
      buff.write(_get_struct_2f().pack(_x.radius, _x.angle))
      buff.write(self.covariance.tostring())
      buff.write(self.start.tostring())
      buff.write(self.end.tostring())
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
      _x = self
      start = end
      end += 8
      (_x.radius, _x.angle,) = _get_struct_2f().unpack(str[start:end])
      start = end
      end += 16
      self.covariance = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=4)
      start = end
      end += 8
      self.start = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=2)
      start = end
      end += 8
      self.end = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=2)
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
