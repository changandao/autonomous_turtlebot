;; Auto-generated. Do not edit!


(when (boundp 'turtle_vis::send_desired_pose)
  (if (not (find-package "TURTLE_VIS"))
    (make-package "TURTLE_VIS"))
  (shadow 'send_desired_pose (find-package "TURTLE_VIS")))
(unless (find-package "TURTLE_VIS::SEND_DESIRED_POSE")
  (make-package "TURTLE_VIS::SEND_DESIRED_POSE"))
(unless (find-package "TURTLE_VIS::SEND_DESIRED_POSEREQUEST")
  (make-package "TURTLE_VIS::SEND_DESIRED_POSEREQUEST"))
(unless (find-package "TURTLE_VIS::SEND_DESIRED_POSERESPONSE")
  (make-package "TURTLE_VIS::SEND_DESIRED_POSERESPONSE"))

(in-package "ROS")





(defclass turtle_vis::send_desired_poseRequest
  :super ros::object
  :slots (_x _y _z ))

(defmethod turtle_vis::send_desired_poseRequest
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

(defclass turtle_vis::send_desired_poseResponse
  :super ros::object
  :slots (_reply ))

(defmethod turtle_vis::send_desired_poseResponse
  (:init
   (&key
    ((:reply __reply) 0.0)
    )
   (send-super :init)
   (setq _reply (float __reply))
   self)
  (:reply
   (&optional __reply)
   (if __reply (setq _reply __reply)) _reply)
  (:serialization-length
   ()
   (+
    ;; float64 _reply
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _reply
       (sys::poke _reply (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _reply
     (setq _reply (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass turtle_vis::send_desired_pose
  :super ros::object
  :slots ())

(setf (get turtle_vis::send_desired_pose :md5sum-) "6263a555b929382ab066ff6b05ebdd5e")
(setf (get turtle_vis::send_desired_pose :datatype-) "turtle_vis/send_desired_pose")
(setf (get turtle_vis::send_desired_pose :request) turtle_vis::send_desired_poseRequest)
(setf (get turtle_vis::send_desired_pose :response) turtle_vis::send_desired_poseResponse)

(defmethod turtle_vis::send_desired_poseRequest
  (:response () (instance turtle_vis::send_desired_poseResponse :init)))

(setf (get turtle_vis::send_desired_poseRequest :md5sum-) "6263a555b929382ab066ff6b05ebdd5e")
(setf (get turtle_vis::send_desired_poseRequest :datatype-) "turtle_vis/send_desired_poseRequest")
(setf (get turtle_vis::send_desired_poseRequest :definition-)
      "
float64 x
float64 y
float64 z
---
float64 reply





")

(setf (get turtle_vis::send_desired_poseResponse :md5sum-) "6263a555b929382ab066ff6b05ebdd5e")
(setf (get turtle_vis::send_desired_poseResponse :datatype-) "turtle_vis/send_desired_poseResponse")
(setf (get turtle_vis::send_desired_poseResponse :definition-)
      "
float64 x
float64 y
float64 z
---
float64 reply





")



(provide :turtle_vis/send_desired_pose "6263a555b929382ab066ff6b05ebdd5e")


