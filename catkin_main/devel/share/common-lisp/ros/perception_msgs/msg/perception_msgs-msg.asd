
(cl:in-package :asdf)

(defsystem "perception_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "PointCloudArray" :depends-on ("_package_PointCloudArray"))
    (:file "_package_PointCloudArray" :depends-on ("_package"))
    (:file "Rect" :depends-on ("_package_Rect"))
    (:file "_package_Rect" :depends-on ("_package"))
    (:file "Rectarray" :depends-on ("_package_Rectarray"))
    (:file "_package_Rectarray" :depends-on ("_package"))
  ))