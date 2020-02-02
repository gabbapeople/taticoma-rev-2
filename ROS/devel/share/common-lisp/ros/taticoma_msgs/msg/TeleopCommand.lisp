; Auto-generated. Do not edit!


(cl:in-package taticoma_msgs-msg)


;//! \htmlinclude TeleopCommand.msg.html

(cl:defclass <TeleopCommand> (roslisp-msg-protocol:ros-message)
  ((axes
    :reader axes
    :initarg :axes
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0))
   (a_buttons
    :reader a_buttons
    :initarg :a_buttons
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (p_buttons
    :reader p_buttons
    :initarg :p_buttons
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (buttons
    :reader buttons
    :initarg :buttons
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0)
   (gait_mode
    :reader gait_mode
    :initarg :gait_mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass TeleopCommand (<TeleopCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TeleopCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TeleopCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name taticoma_msgs-msg:<TeleopCommand> is deprecated: use taticoma_msgs-msg:TeleopCommand instead.")))

(cl:ensure-generic-function 'axes-val :lambda-list '(m))
(cl:defmethod axes-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:axes-val is deprecated.  Use taticoma_msgs-msg:axes instead.")
  (axes m))

(cl:ensure-generic-function 'a_buttons-val :lambda-list '(m))
(cl:defmethod a_buttons-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:a_buttons-val is deprecated.  Use taticoma_msgs-msg:a_buttons instead.")
  (a_buttons m))

(cl:ensure-generic-function 'p_buttons-val :lambda-list '(m))
(cl:defmethod p_buttons-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:p_buttons-val is deprecated.  Use taticoma_msgs-msg:p_buttons instead.")
  (p_buttons m))

(cl:ensure-generic-function 'buttons-val :lambda-list '(m))
(cl:defmethod buttons-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:buttons-val is deprecated.  Use taticoma_msgs-msg:buttons instead.")
  (buttons m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:mode-val is deprecated.  Use taticoma_msgs-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'gait_mode-val :lambda-list '(m))
(cl:defmethod gait_mode-val ((m <TeleopCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader taticoma_msgs-msg:gait_mode-val is deprecated.  Use taticoma_msgs-msg:gait_mode instead.")
  (gait_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TeleopCommand>) ostream)
  "Serializes a message object of type '<TeleopCommand>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'axes))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'a_buttons))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'p_buttons))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'buttons))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gait_mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TeleopCommand>) istream)
  "Deserializes a message object of type '<TeleopCommand>"
  (cl:setf (cl:slot-value msg 'axes) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'axes)))
    (cl:dotimes (i 4)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'a_buttons) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'a_buttons)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'p_buttons) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'p_buttons)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'buttons) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'buttons)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gait_mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TeleopCommand>)))
  "Returns string type for a message object of type '<TeleopCommand>"
  "taticoma_msgs/TeleopCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TeleopCommand)))
  "Returns string type for a message object of type 'TeleopCommand"
  "taticoma_msgs/TeleopCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TeleopCommand>)))
  "Returns md5sum for a message object of type '<TeleopCommand>"
  "175d84f8f67bfd93cb04e6fb561123b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TeleopCommand)))
  "Returns md5sum for a message object of type 'TeleopCommand"
  "175d84f8f67bfd93cb04e6fb561123b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TeleopCommand>)))
  "Returns full string definition for message of type '<TeleopCommand>"
  (cl:format cl:nil "~%float32[4] axes~%float32[2] a_buttons~%uint8[2] p_buttons~%uint8[2] buttons~%~%uint8 mode~%uint8 gait_mode~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TeleopCommand)))
  "Returns full string definition for message of type 'TeleopCommand"
  (cl:format cl:nil "~%float32[4] axes~%float32[2] a_buttons~%uint8[2] p_buttons~%uint8[2] buttons~%~%uint8 mode~%uint8 gait_mode~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TeleopCommand>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'axes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'a_buttons) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'p_buttons) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'buttons) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TeleopCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'TeleopCommand
    (cl:cons ':axes (axes msg))
    (cl:cons ':a_buttons (a_buttons msg))
    (cl:cons ':p_buttons (p_buttons msg))
    (cl:cons ':buttons (buttons msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':gait_mode (gait_mode msg))
))
