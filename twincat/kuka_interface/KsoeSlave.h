#pragma once

#include "TcDef.h"
#include "TcMath.h"
#include "TcInterfaces.h"
#include "MotionState.h"
#include "KsoeState.h"
#include "KsoeSlaveType.h"
#include "KsoeSlaveError.h"
#include "KsoeSlaveWarning.h"
#include "kuka_interfaceServices.h"
#include "PDSParameters.h"
#include "Axis.h"
#include "AxisLimits.h"
#include "AxisControl.h"
#include "AxisSensor.h"
#include "DT1.h"
#include "PT1.h"

#define KSOESLAVE_SEQUENCE_NUMBER_INITIAL 0x0001
#define KSOESLAVE_SEQUENCE_NUMBER_START   0x1000
#define KSOESLAVE_MOTION_WATCHDOG_TICKS (100000/125) //Ticks, equals 100 ms
#define KSOESLAVE_HANDLE_ERROR_FLAG(name,ksoe_slave_error,errorflag,acknowledgeflag) \
  if((errorflag) && !(acknowledgeflag)) { \
    trace->Log(tlError, "%2d KsoeSlave::updateIOs(): Motion prevented by \"" name "\".", connection_id); \
  } \
  else if(!(errorflag) && (acknowledgeflag)) { \
    trace->Log(tlError, "%2d KsoeSlave::updateIOs(): \"" name "\" cleared.", connection_id); \
  } \
  if((errorflag) && motion_error==KsoeSlaveError::NONE) { \
    motion_error=(ksoe_slave_error); \
  } \
  (acknowledgeflag)=(errorflag)
#define KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG(name,ksoe_slave_warning,warningflag,acknowledgeflag) \
  if((warningflag) && !(acknowledgeflag)) { \
    trace->Log(tlWarning, "%2d KsoeSlave::checkCrcReadSensor(): Soft stop caused by \"" name "\".", connection_id); \
  } \
  else if(!(warningflag) && (acknowledgeflag)) { \
    trace->Log(tlWarning, "%2d KsoeSlave::checkCrcReadSensor(): \"" name "\" cleared.", connection_id); \
  } \
  if((warningflag) && sensor_warning==KsoeSlaveWarning::NONE) { \
    sensor_warning=(ksoe_slave_warning); \
  } \
  (acknowledgeflag)=(warningflag)
#define KSOESLAVE_HANDLE_MOTION_WARNING_FLAG(name,ksoe_slave_warning,warningflag,acknowledgeflag) \
  if((warningflag) && !(acknowledgeflag)) { \
    trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): Soft stop caused by \"" name "\".", connection_id); \
  } \
  else if(!(warningflag) && (acknowledgeflag)) { \
    trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): \"" name "\" cleared.", connection_id); \
  } \
  if((warningflag) && motion_warning==KsoeSlaveWarning::NONE) { \
    motion_warning=(ksoe_slave_warning); \
  } \
  (acknowledgeflag)=(warningflag)

#define KSOESLAVE_FILTER_T_a (125e-6)

//Once the position limit is reached, the robot may be enabled again and only
//velocity away from this limit is allowed. To account for sensor noise, a
//tolerance band is defined additionally, which allows minimal movements further
//into the limit. This tolerance band is defined by KSOESLAVE_VELOCITY_TOLERANCE.
#define KSOESLAVE_VELOCITY_TOLERANCE (0.1*PI/180.0) //rad/s
//hard software limit set x radians from the hardware limit
#define KSOESLAVE_POSITION_LIMIT_DISTANCE (3.0*PI/180) //rad
//Soft stop velocity tolerance
#define KSOESLAVE_SOFT_STOP_VELOCITY_TOLERANCE (0.1*PI/180.0) //rad/s

class KsoeSlave {
  private:
    unsigned char motor_control_counter;
    unsigned int state_machine_counter;
    USHORT sequence_number_master;
    USHORT sequence_number_slave;
    KsoeState state;
    MotionState motion_state1;
    MotionState motion_state2;
    MotionState motion_state_target;
    int motion_watchdog1;
    int motion_watchdog2;
    int state_variable;
    bool communication_toggle_bit;
    int connection_id;
    KsoeState previous_command_slave;
    KsoeSlaveType type;
    void *input_buffer;
    void *output_buffer;
    CTcTrace *trace;
    PDSParameters* parameters;
    const Axis *axis1;
    const Axis *axis2;
    const AxisLimits *limits;
    bool axis1_control_motor_torque_nan;
    bool axis2_control_motor_torque_nan;
    bool axis1_control_motor_torque_limit;
    bool axis2_control_motor_torque_limit;
    bool axis1_control_motor_torque_saturated;
    bool axis2_control_motor_torque_saturated;
    bool axis1_sensor_position_soft_limit;
    bool axis2_sensor_position_soft_limit;
    bool axis1_sensor_torque_limit;
    bool axis2_sensor_torque_limit;
    bool axis1_sensor_velocity_limit;
    bool axis2_sensor_velocity_limit;
    KsoeSlaveError last_error;
    void setLastError(KsoeSlaveError error);
    USHORT motor_temperature;
    KsoeSlaveError motion_error;
    KsoeSlaveError sensor_error;
    KsoeSlaveWarning sensor_warning;
    KsoeSlaveWarning motion_warning;
    PT1* position1_filter;
    PT1* position2_filter;
    DT1* velocity1_filter;
    DT1* velocity2_filter;
    PT1* torque1_filter;
    PT1* torque2_filter;
    DT1* torque_derivative1_filter;
    DT1* torque_derivative2_filter;

    USHORT motor_status1_last;
    USHORT motor_status2_last;

  private:
    static USHORT crcTable[256];
    static USHORT previousSequenceNumber(USHORT s);

    void increaseSequenceNumber();
    void statemachine(DWORD dc_time_L);
    void setState(KsoeState s);
    void setMotionState1(MotionState s);
    void setMotionState2(MotionState s);
    void setMotionStateTarget(MotionState s);

    void feedMotionWatchdog1();
    void feedMotionWatchdog2();
    bool doCrc(bool generate, KsoePacket* safe_data, USHORT sequence_number);
    void generateCrc();
    bool checkCrc();
    
    double torque2current(const Axis *axis, double torque);
    double current2torque(const Axis *axis, double current);

  public:
    KsoeSlave(CTcTrace *trace, int connection_id, void *input_buffer, void *output_buffer, PDSParameters* parameters, const AxisLimits* limits, const Axis* axis1);
    KsoeSlave(CTcTrace *trace, int connection_id, void *input_buffer, void *output_buffer, PDSParameters* parameters, const AxisLimits* limits, const Axis* axis1, const Axis* axis2);
    ~KsoeSlave();
    void statemachineWriteControlGenerateCrc(AxisControl *output1, AxisControl *output2, DWORD dc_time_L);
    void checkCrcReadSensor(AxisSensor *input1, AxisSensor *input2);
    void reset();
    int getConnectionID();
    KsoeSlaveError getLastError();
    KsoeSlaveError getMotionError();
    KsoeSlaveError getSensorError();
    KsoeSlaveWarning getMotionWarning();
    KsoeSlaveWarning getSensorWarning();
    KsoeState getState();
    MotionState getMotionStateTarget();
    bool canEnableMotion();
    bool isMotionEnabled();
    bool enableMotion();
    void disableMotion();
    bool hasValidInput();
    void setMotorTemperature(USHORT motor_temperature);
    void performSoftStop(AxisSensor *input1, AxisSensor *input2, AxisControl *output1, AxisControl *output2, DWORD dc_time_L);
};
