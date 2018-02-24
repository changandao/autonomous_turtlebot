;; Auto-generated. Do not edit!


(when (boundp 'turtle_vis::DesiredPose)
  (if (not (find-package "TURTLE_VIS"))
    (make-package "TURTLE_VIS"))
  (shadow 'DesiredPose (find-package "TURTLE_VIS")))
(unless (find-package "TURTLE_VIS::DESIREDPOSE")
  (make-package "TURTLE_VIS::DESIREDPOSE"))

(in-package "ROS")
;;//! \htmlinclude DesiredPose.msg.html


(defclass turtle_vis::DesiredPose
  :super ros::object
  :slots (_x _y _z ))

(defmethod turtle_vis::DesiredPose
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get turtle_vis::DesiredPose :md5sum-) "4a842b65f413084dc2b10fb484ea7f17")
(setf (get turtle_vis::DesiredPose :datatype-) "turtle_vis/DesiredPose")
(setf (get turtle_vis::DesiredPose :definition-)
      "#>>>>TODO: DEFINE 3 FLOATS NAMED: x, y, and theta FOR THIS MSG
float64 x
float64 y
float64 z


")



(provide :turtle_vis/DesiredPose "4a842b65f413084dc2b10fb484ea7f17")


