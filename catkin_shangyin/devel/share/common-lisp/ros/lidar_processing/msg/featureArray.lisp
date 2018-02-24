; Auto-generated. Do not edit!


(cl:in-package lidar_processing-msg)


;//! \htmlinclude featureArray.msg.html

(cl:defclass <featureArray> (roslisp-msg-protocol:ros-message)
  ((features
    :reader features
    :initarg :features
    :type (cl:vector lidar_processing-msg:feature)
   :initform (cl:make-array 0 :element-type 'lidar_processing-msg:feature :initial-element (cl:make-instance 'lidar_processing-msg:feature))))
)

(cl:defclass featureArray (<featureArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <featureArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'featureArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lidar_processing-msg:<featureArray> is deprecated: use lidar_processing-msg:featureArray instead.")))

(cl:ensure-generic-function 'features-val :lambda-list '(m))
(cl:defmethod features-val ((m <featureArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lidar_processing-msg:features-val is deprecated.  Use lidar_processing-msg:features instead.")
  (features m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <featureArray>) ostream)
  "Serializes a message object of type '<featureArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'features))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'features))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <featureArray>) istream)
  "Deserializes a message object of type '<featureArray>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<featureArray>)))
  "Returns string type for a message object of type '<featureArray>"
  "lidar_processing/featureArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'featureArray)))
  "Returns string type for a message object of type 'featureArray"
  "lidar_processing/featureArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<featureArray>)))
  "Returns md5sum for a message object of type '<featureArray>"
  "294ea9dc3e8bebad5ac6a69a8fb92eba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'featureArray)))
  "Returns md5sum for a message object of type 'featureArray"
  "294ea9dc3e8bebad5ac6a69a8fb92eba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<featureArray>)))
  "Returns full string definition for message of type '<featureArray>"
  (cl:format cl:nil "feature[] features~%~%================================================================================~%MSG: lidar_processing/feature~%float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'featureArray)))
  "Returns full string definition for message of type 'featureArray"
  (cl:format cl:nil "feature[] features~%~%================================================================================~%MSG: lidar_processing/feature~%float64 r~%float64 phi~%float64 specifier~%int32 knownCorr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <featureArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'features) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <featureArray>))
  "Converts a ROS message object to a list"
  (cl:list 'featureArray
    (cl:cons ':features (features msg))
))
