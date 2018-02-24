;; Auto-generated. Do not edit!


(when (boundp 'lidar_processing::featureArrayH)
  (if (not (find-package "LIDAR_PROCESSING"))
    (make-package "LIDAR_PROCESSING"))
  (shadow 'featureArrayH (find-package "LIDAR_PROCESSING")))
(unless (find-package "LIDAR_PROCESSING::FEATUREARRAYH")
  (make-package "LIDAR_PROCESSING::FEATUREARRAYH"))

(in-package "ROS")
;;//! \htmlinclude featureArrayH.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass lidar_processing::featureArrayH
  :super ros::object
  :slots (_header _features ))

(defmethod lidar_processing::featureArrayH
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:features __features) (let (r) (dotimes (i 0) (push (instance lidar_processing::feature :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _features __features)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:features
   (&rest __features)
   (if (keywordp (car __features))
       (send* _features __features)
     (progn
       (if __features (setq _features (car __features)))
       _features)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; lidar_processing/feature[] _features
    (apply #'+ (send-all _features :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; lidar_processing/feature[] _features
     (write-long (length _features) s)
     (dolist (elem _features)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; lidar_processing/feature[] _features
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _features (let (r) (dotimes (i n) (push (instance lidar_processing::feature :init) r)) r))
     (dolist (elem- _features)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get lidar_processing::featureArrayH :md5sum-) "aa8d97923860a4e2da8c4709e9639b62")
(setf (get lidar_processing::featureArrayH :datatype-) "lidar_processing/featureArrayH")
(setf (get lidar_processing::featureArrayH :definition-)
      "Header header
feature[] features

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: lidar_processing/feature
float64 r
float64 phi
float64 specifier
int32 knownCorr

")



(provide :lidar_processing/featureArrayH "aa8d97923860a4e2da8c4709e9639b62")


