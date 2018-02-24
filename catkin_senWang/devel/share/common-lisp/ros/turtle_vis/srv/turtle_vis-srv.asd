
(cl:in-package :asdf)

(defsystem "turtle_vis-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "send_desired_pose" :depends-on ("_package_send_desired_pose"))
    (:file "_package_send_desired_pose" :depends-on ("_package"))
  ))