; Auto-generated. Do not edit!


(cl:in-package turtle_vis-srv)


;//! \htmlinclude send_desired_pose-request.msg.html

(cl:defclass <send_desired_pose-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0))
)

(cl:defclass send_desired_pose-request (<send_desired_pose-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_desired_pose-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_desired_pose-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtle_vis-srv:<send_desired_pose-request> is deprecated: use turtle_vis-srv:send_desired_pose-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <send_desired_pose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtle_vis-srv:x-val is deprecated.  Use turtle_vis-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <send_desired_pose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtle_vis-srv:y-val is deprecated.  Use turtle_vis-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <send_desired_pose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtle_vis-srv:z-val is deprecated.  Use turtle_vis-srv:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_desired_pose-request>) ostream)
  "Serializes a message object of type '<send_desired_pose-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_desired_pose-request>) istream)
  "Deserializes a message object of type '<send_desired_pose-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_desired_pose-request>)))
  "Returns string type for a service object of type '<send_desired_pose-request>"
  "turtle_vis/send_desired_poseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_desired_pose-request)))
  "Returns string type for a service object of type 'send_desired_pose-request"
  "turtle_vis/send_desired_poseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_desired_pose-request>)))
  "Returns md5sum for a message object of type '<send_desired_pose-request>"
  "6263a555b929382ab066ff6b05ebdd5e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_desired_pose-request)))
  "Returns md5sum for a message object of type 'send_desired_pose-request"
  "6263a555b929382ab066ff6b05ebdd5e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_desired_pose-request>)))
  "Returns full string definition for message of type '<send_desired_pose-request>"
  (cl:format cl:nil "~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_desired_pose-request)))
  "Returns full string definition for message of type 'send_desired_pose-request"
  (cl:format cl:nil "~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_desired_pose-request>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_desired_pose-request>))
  "Converts a ROS message object to a list"
  (cl:list 'send_desired_pose-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
))
;//! \htmlinclude send_desired_pose-response.msg.html

(cl:defclass <send_desired_pose-response> (roslisp-msg-protocol:ros-message)
  ((reply
    :reader reply
    :initarg :reply
    :type cl:float
    :initform 0.0))
)

(cl:defclass send_desired_pose-response (<send_desired_pose-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_desired_pose-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_desired_pose-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtle_vis-srv:<send_desired_pose-response> is deprecated: use turtle_vis-srv:send_desired_pose-response instead.")))

(cl:ensure-generic-function 'reply-val :lambda-list '(m))
(cl:defmethod reply-val ((m <send_desired_pose-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtle_vis-srv:reply-val is deprecated.  Use turtle_vis-srv:reply instead.")
  (reply m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_desired_pose-response>) ostream)
  "Serializes a message object of type '<send_desired_pose-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'reply))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_desired_pose-response>) istream)
  "Deserializes a message object of type '<send_desired_pose-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'reply) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_desired_pose-response>)))
  "Returns string type for a service object of type '<send_desired_pose-response>"
  "turtle_vis/send_desired_poseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_desired_pose-response)))
  "Returns string type for a service object of type 'send_desired_pose-response"
  "turtle_vis/send_desired_poseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_desired_pose-response>)))
  "Returns md5sum for a message object of type '<send_desired_pose-response>"
  "6263a555b929382ab066ff6b05ebdd5e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_desired_pose-response)))
  "Returns md5sum for a message object of type 'send_desired_pose-response"
  "6263a555b929382ab066ff6b05ebdd5e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_desired_pose-response>)))
  "Returns full string definition for message of type '<send_desired_pose-response>"
  (cl:format cl:nil "float64 reply~%~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_desired_pose-response)))
  "Returns full string definition for message of type 'send_desired_pose-response"
  (cl:format cl:nil "float64 reply~%~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_desired_pose-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_desired_pose-response>))
  "Converts a ROS message object to a list"
  (cl:list 'send_desired_pose-response
    (cl:cons ':reply (reply msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'send_desired_pose)))
  'send_desired_pose-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'send_desired_pose)))
  'send_desired_pose-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_desired_pose)))
  "Returns string type for a service object of type '<send_desired_pose>"
  "turtle_vis/send_desired_pose")