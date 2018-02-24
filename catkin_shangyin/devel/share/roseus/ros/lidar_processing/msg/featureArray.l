;; Auto-generated. Do not edit!


(when (boundp 'lidar_processing::featureArray)
  (if (not (find-package "LIDAR_PROCESSING"))
    (make-package "LIDAR_PROCESSING"))
  (shadow 'featureArray (find-package "LIDAR_PROCESSING")))
(unless (find-package "LIDAR_PROCESSING::FEATUREARRAY")
  (make-package "LIDAR_PROCESSING::FEATUREARRAY"))

(in-package "ROS")
;;//! \htmlinclude featureArray.msg.html


(defclass lidar_processing::featureArray
  :super ros::object
  :slots (_features ))

(defmethod lidar_processing::featureArray
  (:init
   (&key
    ((:features __features) (let (r) (dotimes (i 0) (push (instance lidar_processing::feature :init) r)) r))
    )
   (send-super :init)
   (setq _features __features)
   self)
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
    ;; lidar_processing/feature[] _features
    (apply #'+ (send-all _features :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; lidar_processing/feature[] _features
     (write-long (length _features) s)
     (dolist (elem _features)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
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

(setf (get lidar_processing::featureArray :md5sum-) "294ea9dc3e8bebad5ac6a69a8fb92eba")
(setf (get lidar_processing::featureArray :datatype-) "lidar_processing/featureArray")
(setf (get lidar_processing::featureArray :definition-)
      "feature[] features

================================================================================
MSG: lidar_processing/feature
float64 r
float64 phi
float64 specifier
int32 knownCorr

")



(provide :lidar_processing/featureArray "294ea9dc3e8bebad5ac6a69a8fb92eba")


