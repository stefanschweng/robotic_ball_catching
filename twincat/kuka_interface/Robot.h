#pragma once

#include"TcDef.h"
#include"TcRtInterfaces.h"
#include"Axis.h"
#include"AxisControl.h"
#include"AxisSensor.h"
#include"KsoeSlave.h"
#include"KsoeSlaveParameters.h"
#include"AdsR0.h"
#include"FsoeSlave.h"
#include"AxisLimits.h"

#define ROBOT_NUM_AXIS 7
#define ROBOT_NUM_SLAVE 4
#define ROBOT_RESET_TICKS (5000000/125) //Ticks
#define ROBOT_SOFT_STOP_TICKS (500000/125) //Ticks
#include"RobotParameters.h"

struct RobotParameters;

class Robot : public CAdsR0FifoPort {
  private:
    ITcRTimeTaskPtr task;
    CTcTrace *trace;
    KsoeSlave *slave[ROBOT_NUM_SLAVE];
    FsoeSlave *mft;
    ITComObjectServer *com_object_server;
    RobotParameters *parameters;
    KsoeState last_collective_state;

    DWORD temperature_request_counter;
    DWORD reset_state_counter;
    DWORD soft_stop_counter;
    AxisLimits *limits;

    bool checkLastErrorAndReset();
    bool hasWarning();
    bool hasValidInput();
    void gravitationVector(double *q, double *g, bool hanging);

  public:
    Robot(RobotParameters *parameters, AxisLimits *limits, ITComObjectServer *com_object_server, CTcTrace *trace);
    ~Robot();
    KsoeState getCollectiveState();
    bool isMotionEnabled();
    void enableMotion();
    void performSoftStop();
    void disableMotion();
    void ReadSensor(AxisSensor *input, MFTSensor *input_mft);
    void WriteControl(AxisSensor *input, AxisControl *output, DWORD dc_time_L);

    //CAds
    virtual void AdsReadCon(AmsAddr& rAddr, ULONG invokeId, ULONG result, ULONG cbLength, PVOID pData);
};
