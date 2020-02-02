;; Auto-generated. Do not edit!


(when (boundp 'taticoma_msgs::TeleopSerial)
  (if (not (find-package "TATICOMA_MSGS"))
    (make-package "TATICOMA_MSGS"))
  (shadow 'TeleopSerial (find-package "TATICOMA_MSGS")))
(unless (find-package "TATICOMA_MSGS::TELEOPSERIAL")
  (make-package "TATICOMA_MSGS::TELEOPSERIAL"))

(in-package "ROS")
;;//! \htmlinclude TeleopSerial.msg.html


(defclass taticoma_msgs::TeleopSerial
  :super ros::object
  :slots (_axes _a_buttons _p_buttons _buttons _mode _gait_mode ))

(defmethod taticoma_msgs::TeleopSerial
  (:init
   (&key
    ((:axes __axes) (make-array 4 :initial-element 0 :element-type :char))
    ((:a_buttons __a_buttons) (make-array 2 :initial-element 0 :element-type :char))
    ((:p_buttons __p_buttons) (make-array 2 :initial-element 0 :element-type :char))
    ((:buttons __buttons) (make-array 2 :initial-element 0 :element-type :char))
    ((:mode __mode) 0)
    ((:gait_mode __gait_mode) 0)
    )
   (send-super :init)
   (setq _axes __axes)
   (setq _a_buttons __a_buttons)
   (setq _p_buttons __p_buttons)
   (setq _buttons __buttons)
   (setq _mode (round __mode))
   (setq _gait_mode (round __gait_mode))
   self)
  (:axes
   (&optional __axes)
   (if __axes (setq _axes __axes)) _axes)
  (:a_buttons
   (&optional __a_buttons)
   (if __a_buttons (setq _a_buttons __a_buttons)) _a_buttons)
  (:p_buttons
   (&optional __p_buttons)
   (if __p_buttons (setq _p_buttons __p_buttons)) _p_buttons)
  (:buttons
   (&optional __buttons)
   (if __buttons (setq _buttons __buttons)) _buttons)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:gait_mode
   (&optional __gait_mode)
   (if __gait_mode (setq _gait_mode __gait_mode)) _gait_mode)
  (:serialization-length
   ()
   (+
    ;; uint8[4] _axes
    (* 1    4)
    ;; uint8[2] _a_buttons
    (* 1    2)
    ;; uint8[2] _p_buttons
    (* 1    2)
    ;; uint8[2] _buttons
    (* 1    2)
    ;; uint8 _mode
    1
    ;; uint8 _gait_mode
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8[4] _axes
     (princ _axes s)
     ;; uint8[2] _a_buttons
     (princ _a_buttons s)
     ;; uint8[2] _p_buttons
     (princ _p_buttons s)
     ;; uint8[2] _buttons
     (princ _buttons s)
     ;; uint8 _mode
       (write-byte _mode s)
     ;; uint8 _gait_mode
       (write-byte _gait_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8[4] _axes
   (setq _axes (make-array 4 :element-type :char))
   (replace _axes buf :start2 ptr-) (incf ptr- 4)
   ;; uint8[2] _a_buttons
   (setq _a_buttons (make-array 2 :element-type :char))
   (replace _a_buttons buf :start2 ptr-) (incf ptr- 2)
   ;; uint8[2] _p_buttons
   (setq _p_buttons (make-array 2 :element-type :char))
   (replace _p_buttons buf :start2 ptr-) (incf ptr- 2)
   ;; uint8[2] _buttons
   (setq _buttons (make-array 2 :element-type :char))
   (replace _buttons buf :start2 ptr-) (incf ptr- 2)
   ;; uint8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _gait_mode
     (setq _gait_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get taticoma_msgs::TeleopSerial :md5sum-) "a826112f65f9a91607209418c91cb6b7")
(setf (get taticoma_msgs::TeleopSerial :datatype-) "taticoma_msgs/TeleopSerial")
(setf (get taticoma_msgs::TeleopSerial :definition-)
      "
uint8[4] axes
uint8[2] a_buttons
uint8[2] p_buttons
uint8[2] buttons

uint8 mode
uint8 gait_mode



")



(provide :taticoma_msgs/TeleopSerial "a826112f65f9a91607209418c91cb6b7")


