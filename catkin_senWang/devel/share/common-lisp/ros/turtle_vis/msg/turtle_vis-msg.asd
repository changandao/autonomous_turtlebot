
(cl:in-package :asdf)

(defsystem "turtle_vis-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DesiredPose" :depends-on ("_package_DesiredPose"))
    (:file "_package_DesiredPose" :depends-on ("_package"))
  ))