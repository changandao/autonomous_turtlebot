; Auto-generated. Do not edit!


(cl:in-package lidar_processing-msg)


;//! \htmlinclude featureArrayH.msg.html

(cl:defclass <featureArrayH> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (features
    :reader features
    :initarg :features
    :type (cl:vector lidar_processing-msg:feature)
   :initform (cl:make-array 0 :element-type 'lidar_processing-msg:feature :initial-element (cl:make-instance 'lidar_processing-msg:feature))))
)

(cl:defclass featureArrayH (<featureArrayH>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <featureArrayH>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'featureArrayH)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lidar_processing-msg:<featureArrayH> is deprecated: use lidar_processing-msg:featureArrayH instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <featureArrayH>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:header-val is deprecated.  Use lidar_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'features-val :lambda-list '(m))
(cl:defmethod features-val ((m <featureArrayH>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:features-val is deprecated.  Use lidar_processing-msg:features instead.")
  (features m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <featureArrayH>) ostream)
  "Serializes a message object of type '<featureArrayH>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'features))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'features))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <featureArrayH>) istream)
  "Deserializes a message object of type '<featureArrayH>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'features) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'features)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'lidar_processing-msg:feature))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<featureArrayH>)))
  "Returns string type for a message object of type '<featureArrayH>"
  "lidar_processing/featureArrayH")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'featureArrayH)))
  "Returns string type for a message object of type 'featureArrayH"
  "lidar_processing/featureArrayH")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<featureArrayH>)))
  "Returns md5sum for a message object of type '<featureArrayH>"
  "aa8d97923860a4e2da8c4709e9639b62")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'featureArrayH)))
  "Returns md5sum for a message object of type 'featureArrayH"
  "aa8d97923860a4e2da8c4709e9639b62")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<featureArrayH>)))
  "Returns full string definition for message of type '<featureArrayH>"
  (cl:format cl:nil "Header header~%feature[] features~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: lidar_processing/feature~%float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'featureArrayH)))
  "Returns full string definition for message of type 'featureArrayH"
  (cl:format cl:nil "Header header~%feature[] features~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: lidar_processing/feature~%float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <featureArrayH>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'features) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <featureArrayH>))
  "Converts a ROS message object to a list"
  (cl:list 'featureArrayH
    (cl:cons ':header (header msg))
    (cl:cons ':features (features msg))
))
