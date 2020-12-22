#pragma once

struct AxisSensor {
  //Sensor data
  double motor_torque_feedback; //Nm
  double torque; //Nm
  double position; //rad
  double temperature; //K

  double position_filtered; //rad
  double velocity_filtered; //rad/s
  double torque_filtered; //Nm
  double torque_derivative_filtered; //Nm/s
};
