// Auto-generated. Do not edit!

// (in-package taticoma_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class TeleopSerial {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.axes = null;
      this.a_buttons = null;
      this.p_buttons = null;
      this.buttons = null;
      this.mode = null;
      this.gait_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('axes')) {
        this.axes = initObj.axes
      }
      else {
        this.axes = new Array(4).fill(0);
      }
      if (initObj.hasOwnProperty('a_buttons')) {
        this.a_buttons = initObj.a_buttons
      }
      else {
        this.a_buttons = new Array(2).fill(0);
      }
      if (initObj.hasOwnProperty('p_buttons')) {
        this.p_buttons = initObj.p_buttons
      }
      else {
        this.p_buttons = new Array(2).fill(0);
      }
      if (initObj.hasOwnProperty('buttons')) {
        this.buttons = initObj.buttons
      }
      else {
        this.buttons = new Array(2).fill(0);
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('gait_mode')) {
        this.gait_mode = initObj.gait_mode
      }
      else {
        this.gait_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TeleopSerial
    // Check that the constant length array field [axes] has the right length
    if (obj.axes.length !== 4) {
      throw new Error('Unable to serialize array field axes - length must be 4')
    }
    // Serialize message field [axes]
    bufferOffset = _arraySerializer.uint8(obj.axes, buffer, bufferOffset, 4);
    // Check that the constant length array field [a_buttons] has the right length
    if (obj.a_buttons.length !== 2) {
      throw new Error('Unable to serialize array field a_buttons - length must be 2')
    }
    // Serialize message field [a_buttons]
    bufferOffset = _arraySerializer.uint8(obj.a_buttons, buffer, bufferOffset, 2);
    // Check that the constant length array field [p_buttons] has the right length
    if (obj.p_buttons.length !== 2) {
      throw new Error('Unable to serialize array field p_buttons - length must be 2')
    }
    // Serialize message field [p_buttons]
    bufferOffset = _arraySerializer.uint8(obj.p_buttons, buffer, bufferOffset, 2);
    // Check that the constant length array field [buttons] has the right length
    if (obj.buttons.length !== 2) {
      throw new Error('Unable to serialize array field buttons - length must be 2')
    }
    // Serialize message field [buttons]
    bufferOffset = _arraySerializer.uint8(obj.buttons, buffer, bufferOffset, 2);
    // Serialize message field [mode]
    bufferOffset = _serializer.uint8(obj.mode, buffer, bufferOffset);
    // Serialize message field [gait_mode]
    bufferOffset = _serializer.uint8(obj.gait_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TeleopSerial
    let len;
    let data = new TeleopSerial(null);
    // Deserialize message field [axes]
    data.axes = _arrayDeserializer.uint8(buffer, bufferOffset, 4)
    // Deserialize message field [a_buttons]
    data.a_buttons = _arrayDeserializer.uint8(buffer, bufferOffset, 2)
    // Deserialize message field [p_buttons]
    data.p_buttons = _arrayDeserializer.uint8(buffer, bufferOffset, 2)
    // Deserialize message field [buttons]
    data.buttons = _arrayDeserializer.uint8(buffer, bufferOffset, 2)
    // Deserialize message field [mode]
    data.mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [gait_mode]
    data.gait_mode = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'taticoma_msgs/TeleopSerial';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a826112f65f9a91607209418c91cb6b7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    uint8[4] axes
    uint8[2] a_buttons
    uint8[2] p_buttons
    uint8[2] buttons
    
    uint8 mode
    uint8 gait_mode
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TeleopSerial(null);
    if (msg.axes !== undefined) {
      resolved.axes = msg.axes;
    }
    else {
      resolved.axes = new Array(4).fill(0)
    }

    if (msg.a_buttons !== undefined) {
      resolved.a_buttons = msg.a_buttons;
    }
    else {
      resolved.a_buttons = new Array(2).fill(0)
    }

    if (msg.p_buttons !== undefined) {
      resolved.p_buttons = msg.p_buttons;
    }
    else {
      resolved.p_buttons = new Array(2).fill(0)
    }

    if (msg.buttons !== undefined) {
      resolved.buttons = msg.buttons;
    }
    else {
      resolved.buttons = new Array(2).fill(0)
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.gait_mode !== undefined) {
      resolved.gait_mode = msg.gait_mode;
    }
    else {
      resolved.gait_mode = 0
    }

    return resolved;
    }
};

module.exports = TeleopSerial;
