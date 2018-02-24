; Auto-generated. Do not edit!


(cl:in-package lidar_processing-msg)


;//! \htmlinclude feature.msg.html

(cl:defclass <feature> (roslisp-msg-protocol:ros-message)
  ((r
    :reader r
    :initarg :r
    :type cl:float
    :initform 0.0)
   (phi
    :reader phi
    :initarg :phi
    :type cl:float
    :initform 0.0)
   (specifier
    :reader specifier
    :initarg :specifier
    :type cl:float
    :initform 0.0)
   (knownCorr
    :reader knownCorr
    :initarg :knownCorr
    :type cl:integer
    :initform 0))
)

(cl:defclass feature (<feature>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <feature>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'feature)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lidar_processing-msg:<feature> is deprecated: use lidar_processing-msg:feature instead.")))

(cl:ensure-generic-function 'r-val :lambda-list '(m))
(cl:defmethod r-val ((m <feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:r-val is deprecated.  Use lidar_processing-msg:r instead.")
  (r m))

(cl:ensure-generic-function 'phi-val :lambda-list '(m))
(cl:defmethod phi-val ((m <feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:phi-val is deprecated.  Use lidar_processing-msg:phi instead.")
  (phi m))

(cl:ensure-generic-function 'specifier-val :lambda-list '(m))
(cl:defmethod specifier-val ((m <feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:specifier-val is deprecated.  Use lidar_processing-msg:specifier instead.")
  (specifier m))

(cl:ensure-generic-function 'knownCorr-val :lambda-list '(m))
(cl:defmethod knownCorr-val ((m <feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:knownCorr-val is deprecated.  Use lidar_processing-msg:knownCorr instead.")
  (knownCorr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <feature>) ostream)
  "Serializes a message object of type '<feature>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'r))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'phi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'specifier))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'knownCorr)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <feature>) istream)
  "Deserializes a message object of type '<feature>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'phi) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'specifier) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'knownCorr) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<feature>)))
  "Returns string type for a message object of type '<feature>"
  "lidar_processing/feature")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'feature)))
  "Returns string type for a message object of type 'feature"
  "lidar_processing/feature")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<feature>)))
  "Returns md5sum for a message object of type '<feature>"
  "c03949e67c3c314b42ad9c8ad76ea855")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'feature)))
  "Returns md5sum for a message object of type 'feature"
  "c03949e67c3c314b42ad9c8ad76ea855")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<feature>)))
  "Returns full string definition for message of type '<feature>"
  (cl:format cl:nil "float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'feature)))
  "Returns full string definition for message of type 'feature"
  (cl:format cl:nil "float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <feature>))
  (cl:+ 0
     8
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <feature>))
  "Converts a ROS message object to a list"
  (cl:list 'feature
    (cl:cons ':r (r msg))
    (cl:cons ':phi (phi msg))
    (cl:cons ':specifier (specifier msg))
    (cl:cons ':knownCorr (knownCorr msg))
))
