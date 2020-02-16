
"use strict";

let SetSpeed = require('./SetSpeed.js')
let TorqueEnable = require('./TorqueEnable.js')
let StopController = require('./StopController.js')
let SetComplianceMargin = require('./SetComplianceMargin.js')
let StartController = require('./StartController.js')
let SetComplianceSlope = require('./SetComplianceSlope.js')
let SetTorqueLimit = require('./SetTorqueLimit.js')
let RestartController = require('./RestartController.js')
let SetCompliancePunch = require('./SetCompliancePunch.js')

module.exports = {
  SetSpeed: SetSpeed,
  TorqueEnable: TorqueEnable,
  StopController: StopController,
  SetComplianceMargin: SetComplianceMargin,
  StartController: StartController,
  SetComplianceSlope: SetComplianceSlope,
  SetTorqueLimit: SetTorqueLimit,
  RestartController: RestartController,
  SetCompliancePunch: SetCompliancePunch,
};
