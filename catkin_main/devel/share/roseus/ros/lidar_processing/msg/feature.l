;; Auto-generated. Do not edit!


(when (boundp 'lidar_processing::feature)
  (if (not (find-package "LIDAR_PROCESSING"))
    (make-package "LIDAR_PROCESSING"))
  (shadow 'feature (find-package "LIDAR_PROCESSING")))
(unless (find-package "LIDAR_PROCESSING::FEATURE")
  (make-package "LIDAR_PROCESSING::FEATURE"))

(in-package "ROS")
;;//! \htmlinclude feature.msg.html


(defclass lidar_processing::feature
  :super ros::object
  :slots (_r _phi _specifier _knownCorr ))

(defmethod lidar_processing::feature
  (:init
   (&key
    ((:r __r) 0.0)
    ((:phi __phi) 0.0)
    ((:specifier __specifier) 0.0)
    ((:knownCorr __knownCorr) 0)
    )
   (send-super :init)
   (setq _r (float __r))
   (setq _phi (float __phi))
   (setq _specifier (float __specifier))
   (setq _knownCorr (round __knownCorr))
   self)
  (:r
   (&optional __r)
   (if __r (setq _r __r)) _r)
  (:phi
   (&optional __phi)
   (if __phi (setq _phi __phi)) _phi)
  (:specifier
   (&optional __specifier)
   (if __specifier (setq _specifier __specifier)) _specifier)
  (:knownCorr
   (&optional __knownCorr)
   (if __knownCorr (setq _knownCorr __knownCorr)) _knownCorr)
  (:serialization-length
   ()
   (+
    ;; float64 _r
    8
    ;; float64 _phi
    8
    ;; float64 _specifier
    8
    ;; int32 _knownCorr
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _r
       (sys::poke _r (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _phi
       (sys::poke _phi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _specifier
       (sys::poke _specifier (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _knownCorr
       (write-long _knownCorr s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _r
     (setq _r (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _phi
     (setq _phi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _specifier
     (setq _specifier (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _knownCorr
     (setq _knownCorr (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get lidar_processing::feature :md5sum-) "c03949e67c3c314b42ad9c8ad76ea855")
(setf (get lidar_processing::feature :datatype-) "lidar_processing/feature")
(setf (get lidar_processing::feature :definition-)
      "float64 r
float64 phi
float64 specifier
int32 knownCorr

")



(provide :lidar_processing/feature "c03949e67c3c314b42ad9c8ad76ea855")


