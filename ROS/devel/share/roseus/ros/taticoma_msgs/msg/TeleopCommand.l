;; Auto-generated. Do not edit!


(when (boundp 'taticoma_msgs::TeleopCommand)
  (if (not (find-package "TATICOMA_MSGS"))
    (make-package "TATICOMA_MSGS"))
  (shadow 'TeleopCommand (find-package "TATICOMA_MSGS")))
(unless (find-package "TATICOMA_MSGS::TELEOPCOMMAND")
  (make-package "TATICOMA_MSGS::TELEOPCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude TeleopCommand.msg.html


(defclass taticoma_msgs::TeleopCommand
  :super ros::object
  :slots (_axes _a_buttons _p_buttons _buttons _mode _gait_mode ))

(defmethod taticoma_msgs::TeleopCommand
  (:init
   (&key
    ((:axes __axes) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:a_buttons __a_buttons) (make-array 2 :initial-element 0.0 :element-type :float))
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
    ;; float32[4] _axes
    (* 4    4)
    ;; float32[2] _a_buttons
    (* 4    2)
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
     ;; float32[4] _axes
     (dotimes (i 4)
       (sys::poke (elt _axes i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[2] _a_buttons
     (dotimes (i 2)
       (sys::poke (elt _a_buttons i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
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
   ;; float32[4] _axes
   (dotimes (i (length _axes))
     (setf (elt _axes i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[2] _a_buttons
   (dotimes (i (length _a_buttons))
     (setf (elt _a_buttons i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
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

(setf (get taticoma_msgs::TeleopCommand :md5sum-) "175d84f8f67bfd93cb04e6fb561123b6")
(setf (get taticoma_msgs::TeleopCommand :datatype-) "taticoma_msgs/TeleopCommand")
(setf (get taticoma_msgs::TeleopCommand :definition-)
      "
float32[4] axes
float32[2] a_buttons
uint8[2] p_buttons
uint8[2] buttons

uint8 mode
uint8 gait_mode


")



(provide :taticoma_msgs/TeleopCommand "175d84f8f67bfd93cb04e6fb561123b6")


