// Auto-generated. Do not edit!

// (in-package lidar_processing.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class feature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.r = null;
      this.phi = null;
      this.specifier = null;
      this.knownCorr = null;
    }
    else {
      if (initObj.hasOwnProperty('r')) {
        this.r = initObj.r
      }
      else {
        this.r = 0.0;
      }
      if (initObj.hasOwnProperty('phi')) {
        this.phi = initObj.phi
      }
      else {
        this.phi = 0.0;
      }
      if (initObj.hasOwnProperty('specifier')) {
        this.specifier = initObj.specifier
      }
      else {
        this.specifier = 0.0;
      }
      if (initObj.hasOwnProperty('knownCorr')) {
        this.knownCorr = initObj.knownCorr
      }
      else {
        this.knownCorr = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type feature
    // Serialize message field [r]
    bufferOffset = _serializer.float64(obj.r, buffer, bufferOffset);
    // Serialize message field [phi]
    bufferOffset = _serializer.float64(obj.phi, buffer, bufferOffset);
    // Serialize message field [specifier]
    bufferOffset = _serializer.float64(obj.specifier, buffer, bufferOffset);
    // Serialize message field [knownCorr]
    bufferOffset = _serializer.int32(obj.knownCorr, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type feature
    let len;
    let data = new feature(null);
    // Deserialize message field [r]
    data.r = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [phi]
    data.phi = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [specifier]
    data.specifier = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [knownCorr]
    data.knownCorr = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lidar_processing/feature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c03949e67c3c314b42ad9c8ad76ea855';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 r
    float64 phi
    float64 specifier
    int32 knownCorr
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new feature(null);
    if (msg.r !== undefined) {
      resolved.r = msg.r;
    }
    else {
      resolved.r = 0.0
    }

    if (msg.phi !== undefined) {
      resolved.phi = msg.phi;
    }
    else {
      resolved.phi = 0.0
    }

    if (msg.specifier !== undefined) {
      resolved.specifier = msg.specifier;
    }
    else {
      resolved.specifier = 0.0
    }

    if (msg.knownCorr !== undefined) {
      resolved.knownCorr = msg.knownCorr;
    }
    else {
      resolved.knownCorr = 0
    }

    return resolved;
    }
};

module.exports = feature;
