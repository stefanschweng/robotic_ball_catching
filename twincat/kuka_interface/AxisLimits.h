#pragma once

struct AxisLimits {
  double velocity_limit_fraction; //1, Fraction of the nominal axis velocity
  double motor_torque_limit_fraction; //1, Maximum torque fraction, which leads to a soft stop when exceeded.
  double motor_torque_saturation; //1, Maximum torque fraction, at which the current input saturates by software.
  double sensor_torque_limit_fraction; //1, Maximum allowed sensor value as fraction of nominal sensor torque
  double position_reserve; //rad, Additional software reserve for the position, which leads to a soft stop when exceeded
  bool robot_hanging; //Specifies in which position the robot is mounted.
};
