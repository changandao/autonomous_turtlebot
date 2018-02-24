
(cl:in-package :asdf)

(defsystem "lidar_processing-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "feature" :depends-on ("_package_feature"))
    (:file "_package_feature" :depends-on ("_package"))
    (:file "featureArray" :depends-on ("_package_featureArray"))
    (:file "_package_featureArray" :depends-on ("_package"))
    (:file "featureArrayH" :depends-on ("_package_featureArrayH"))
    (:file "_package_featureArrayH" :depends-on ("_package"))
  ))