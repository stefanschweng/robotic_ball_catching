///////////////////////////////////////////////////////////////////////////////
// Robot.cpp
#include "TcPch.h"
#pragma hdrstop

#include "Robot.h"

Robot::Robot(RobotParameters *parameters, AxisLimits *limits, ITComObjectServer *com_object_server, CTcTrace *trace) {
  this->com_object_server=com_object_server;
  this->trace=trace;
  this->parameters=parameters;
  this->reset_state_counter=ROBOT_RESET_TICKS;
  this->limits=limits;
  soft_stop_counter=0;
  slave[0]=new KsoeSlave(trace, parameters->ksoe_slave_parameters[0].connection_id, parameters->ksoe_slave_parameters[0].input_buffer,
    parameters->ksoe_slave_parameters[0].output_buffer,&parameters->ksoe_slave_parameters[0].pds_parameters,limits,&parameters->axis[0]);
  slave[1]=new KsoeSlave(trace, parameters->ksoe_slave_parameters[1].connection_id, parameters->ksoe_slave_parameters[1].input_buffer,
    parameters->ksoe_slave_parameters[1].output_buffer,&parameters->ksoe_slave_parameters[1].pds_parameters,limits,&parameters->axis[1],&parameters->axis[2]);
  slave[2]=new KsoeSlave(trace, parameters->ksoe_slave_parameters[2].connection_id, parameters->ksoe_slave_parameters[2].input_buffer,
    parameters->ksoe_slave_parameters[2].output_buffer,&parameters->ksoe_slave_parameters[2].pds_parameters,limits,&parameters->axis[3],&parameters->axis[4]);
  slave[3]=new KsoeSlave(trace, parameters->ksoe_slave_parameters[3].connection_id, parameters->ksoe_slave_parameters[3].input_buffer,
    parameters->ksoe_slave_parameters[3].output_buffer,&parameters->ksoe_slave_parameters[3].pds_parameters,limits,&parameters->axis[5],&parameters->axis[6]);
  if(parameters->fsoe_slave_parameters.input_buffer!=NULL &&
    parameters->fsoe_slave_parameters.output_buffer!=NULL &&
    parameters->fsoe_slave_parameters.connection_id!=0 &&
    parameters->fsoe_slave_parameters.slave_address!=0) {
    mft=new FsoeSlave(trace, parameters->fsoe_slave_parameters.connection_id, parameters->fsoe_slave_parameters.slave_address,
      (MFT_FSoE_Inputs*)parameters->fsoe_slave_parameters.input_buffer, (MFT_FSoE_Outputs*)parameters->fsoe_slave_parameters.output_buffer,
      parameters->NSR_INDICATOR,parameters->NSR_INPUT);
  }
  else {
    mft=NULL;
    trace->Log(tlAlways, "%s Robot::Robot(): Robot created without MFT.", parameters->name);
  }
  InitAmsPort(com_object_server, 2000);
  temperature_request_counter=MAXULONG;
  trace->Log(tlAlways,"%s Robot::Robot(): Robot created successfully.", parameters->name);
  last_collective_state=KsoeState::NONE;
}

Robot::~Robot() {
  for(int i = 0;i<ROBOT_NUM_SLAVE;i++) {
    safe_delete(slave[i]);
  }
  safe_delete(mft);
  ShutdownAmsPort();
  trace->Log(tlAlways,"%s Robot::Robot(): Robot deleted.", parameters->name);
}

void Robot::ReadSensor(AxisSensor *input, MFTSensor *input_mft) {
  // handle pending ADS indications and confirmations
  CheckOrders();

  if(reset_state_counter!=0) {
    reset_state_counter--;
  }
  //Do not operate as long as the input from the slaves is not yet valid.
  if(hasValidInput() && !reset_state_counter) {
    temperature_request_counter++;
    //Request the temperature of all slaves every 5 seconds (at a cycle time of 125 µs)
    //ADS Request should work as soon as the slave is in state OP.
    if(temperature_request_counter>=5000000/125) {
      temperature_request_counter=0;
      DWORD nOffset=(0x2200<<16)|(0x000a);
      AmsAddr addr;
      addr.netId=parameters->netid;
      for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
        addr.port=parameters->ksoe_slave_parameters[i].slave_address;
        //Use slave address as request number to later store the received data.
        AdsReadReq(addr, addr.port, ADSIGRP_CANOPEN_SDO, nOffset, 2);
      }
    }

    //Only proceed if there are no error states present.
    if(!checkLastErrorAndReset()) {
      slave[0]->checkCrcReadSensor(&input[0], NULL);
      slave[1]->checkCrcReadSensor(&input[1], &input[2]);
      slave[2]->checkCrcReadSensor(&input[3], &input[4]);
      slave[3]->checkCrcReadSensor(&input[5], &input[6]);
      checkLastErrorAndReset();
    }
  }
  else {
    for(int i=0;i<ROBOT_NUM_AXIS;i++) {
      input[i].motor_torque_feedback=0;
      input[i].position=0;
      input[i].torque=0;
    }
  }
  if(mft!=NULL && input_mft!=NULL) {
    if(!reset_state_counter) {
      mft->ReadSensor(input_mft);
    }
  }

  KsoeState collective_state=getCollectiveState();
  if(collective_state!=last_collective_state &&
    collective_state!=KsoeState::NONE) {
    trace->Log(tlInfo, "%s Robot::CycleUpdate(): Collective state %s (0x%02x) -> %s (0x%02x).",
      parameters->name,toString(last_collective_state),last_collective_state,toString(collective_state),collective_state);
    if(collective_state==KsoeState::PROCESS_DATA) {
      trace->Log(tlAlways, "%s Robot::CycleUpdate(): Robot is now fully initialized.",parameters->name);
    }
    last_collective_state=collective_state;
  }
}

void Robot::WriteControl(AxisSensor *input, AxisControl *output, DWORD dc_time_L) {
  bool axes_enabled;
  //Do not operate as long as the input from the slaves is not yet valid.
  //Only proceed if there are no error states present.
  if(hasValidInput() && !reset_state_counter && !checkLastErrorAndReset()) {
    if(soft_stop_counter==0 && isMotionEnabled() && hasWarning()) {
      soft_stop_counter=ROBOT_SOFT_STOP_TICKS;
      if(mft!=NULL) {
        mft->setLEDState(LEDState::RED);
      }
    }
    if(soft_stop_counter!=0) {
      double q[ROBOT_NUM_AXIS];
      double g[ROBOT_NUM_AXIS];
      for(int i=0;i<ROBOT_NUM_AXIS;i++) {
        q[i]=input[i].position;
      }
      gravitationVector(q, g, limits->robot_hanging);
      for(int i=0;i<ROBOT_NUM_AXIS;i++) {
        output[i].motor_torque=g[i];
      }
      //Perform a soft stop by using a P velocity controller
      slave[0]->performSoftStop(&input[0], NULL, &output[0], NULL, dc_time_L);
      slave[1]->performSoftStop(&input[1], &input[2], &output[1], &output[2], dc_time_L);
      slave[2]->performSoftStop(&input[3], &input[4], &output[3], &output[4], dc_time_L);
      slave[3]->performSoftStop(&input[5], &input[6], &output[5], &output[6], dc_time_L);
      //Check if soft stop is completed on all axes. If it is completed,
      //the corresponding motor_enable signal is false.
      axes_enabled=false;
      for(int i=0;i<ROBOT_NUM_AXIS;i++) {
        axes_enabled|=output[i].motor_enable;
      }
      //If any axis is still enabled, continue with soft stop. Otherwise, disable
      //motion completely to end the soft stop phase. This also clears the warning.
      if(axes_enabled) {
        soft_stop_counter--;
        if(soft_stop_counter==0) {
          trace->Log(tlAlways, "%s Robot::WriteControl(): Soft stop time exceeded, disabling motion.", parameters->name);
          disableMotion();
        }
      }
      else {
        soft_stop_counter=0;
        trace->Log(tlAlways, "%s Robot::WriteControl(): Soft stop completed.", parameters->name);
        disableMotion();
      }
    }
    else {
      slave[0]->statemachineWriteControlGenerateCrc(&output[0], NULL, dc_time_L);
      slave[1]->statemachineWriteControlGenerateCrc(&output[1], &output[2], dc_time_L);
      slave[2]->statemachineWriteControlGenerateCrc(&output[3], &output[4], dc_time_L);
      slave[3]->statemachineWriteControlGenerateCrc(&output[5], &output[6], dc_time_L);
    }
    checkLastErrorAndReset();
  }
}

bool Robot::checkLastErrorAndReset() {
  bool reset=false;
  bool emergency=false;
  for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
    KsoeSlaveError error=slave[i]->getLastError();
    if(error!=KsoeSlaveError::NONE) {
      trace->Log(tlError,"%s Robot::checkLastErrorAndReset(): Reset due to error %s (%d) of slave %d.",
        parameters->name,toString(error),(int)error,slave[i]->getConnectionID());
      reset=true;
    }
    error=slave[i]->getMotionError();
    if(error!=KsoeSlaveError::NONE) {
      if(slave[i]->getMotionStateTarget()!=MotionState::STOP) {
        trace->Log(tlError, "%s Robot::checkLastErrorAndReset(): Motion aborted due to error %s (%d) of slave %d.",
          parameters->name, toString(error), (int)error, slave[i]->getConnectionID());
        slave[i]->disableMotion();
      }
      emergency=true;
    }
    error=slave[i]->getSensorError();
    if(error!=KsoeSlaveError::NONE) {
      if(slave[i]->getMotionStateTarget()!=MotionState::STOP) {
        trace->Log(tlError, "%s Robot::checkLastErrorAndReset(): Motion aborted due to sensor error %s (%d) of slave %d.",
          parameters->name, toString(error), (int)error, slave[i]->getConnectionID());
        slave[i]->disableMotion();
      }
      emergency=true;
    }
    if(mft!=NULL) {
      FsoeSlaveError error=mft->getLastError();
      if(error!=FsoeSlaveError::NONE) {
        trace->Log(tlError, "%s Robot::checkLastErrorAndReset(): Reset due to error %s (%d) of slave MFT.",
          parameters->name, toString(error), (int)error);
        reset=true;
      }
      error=mft->getSensorError();
      if(error!=FsoeSlaveError::NONE) {
        trace->Log(tlError, "%s Robot::checkLastErrorAndReset(): Motion aborted due to sensor error %s (%d) of slave MFT.",
          parameters->name, toString(error), (int)error);
        emergency=true;
      }
    }
  }
  if(reset) {
    reset_state_counter=ROBOT_RESET_TICKS;
    for(int i = 0;i<ROBOT_NUM_SLAVE;i++) {
      slave[i]->reset();
    }
    if(mft!=NULL) {
      mft->reset();
    }
  }
  if(emergency) {
    for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
      if(slave[i]->getMotionStateTarget()!=MotionState::STOP) {
        trace->Log(tlError, "%s Robot::checkLastErrorAndReset(): Motion aborted of slave %d due to emergency.",
          parameters->name, slave[i]->getConnectionID());
        slave[i]->disableMotion();
      }
    }
  }
  return reset;
}

bool Robot::hasWarning() {
  bool warning=false;
  for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
    if(slave[i]->getSensorWarning()!=KsoeSlaveWarning::NONE ||
      slave[i]->getMotionWarning()!=KsoeSlaveWarning::NONE) {
      warning=true;
    }
  }
  return warning;
}

bool Robot::isMotionEnabled() {
  for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
    if(slave[i]->isMotionEnabled())
      return true;
  }
  return false;
}

void Robot::enableMotion() {
  if(isMotionEnabled()) {
    trace->Log(tlWarning, "%s Robot::enableMotion(): Motion already enabled. Ignoring request.", parameters->name);
  }
  else {
    bool enable=true;
    for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
      if(!slave[i]->canEnableMotion()) {
        trace->Log(tlError, "%s Robot::enableMotion(): Motion not enabled due to slave %d.", parameters->name, slave[i]->getConnectionID());
        enable=false;
        break;
      }
    }
    if(mft!=NULL && !mft->canEnableMotion()) {
      trace->Log(tlError, "%s Robot::enableMotion(): Motion not enabled due to slave MFT.", parameters->name);
      enable=false;
    }
    //Check if enabling is possible
    if(enable) {
      trace->Log(tlAlways, "%s Robot::enableMotion(): Enabling motion", parameters->name);
      enable=true;
      for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
        if(!slave[i]->enableMotion()) {
          trace->Log(tlError, "%s Robot::enableMotion(): Failed to enable motion due to slave %d", parameters->name, slave[i]->getConnectionID());
          enable=false;
          break;
        }
      }
      if(enable) {
        if(mft!=NULL) {
          mft->setLEDState(LEDState::GREEN);
        }
      }
      else {
        disableMotion();
      }
    }
  }
}

void Robot::performSoftStop() {
  if(soft_stop_counter==0 && isMotionEnabled()) {
    trace->Log(tlAlways, "%s Robot::performSoftStop()", parameters->name);
    soft_stop_counter=ROBOT_SOFT_STOP_TICKS;
    if(mft!=NULL) {
      mft->setLEDState(LEDState::RED);
    }
  }
  else {
    //If the soft stop conditions are not satisfied, perform a hard stop, just
    //to be sure.
    disableMotion();
  }
}

void Robot::disableMotion() {
  if(!isMotionEnabled()) {
    trace->Log(tlWarning, "%s Robot::disableMotion(): Motion already disabled; disabling anyway.", parameters->name);
  }
  trace->Log(tlAlways,"%s Robot::disableMotion()", parameters->name);
  for(int i = 0;i<ROBOT_NUM_SLAVE;i++) {
    slave[i]->disableMotion();
  }
  if(mft!=NULL) {
    mft->setLEDState(LEDState::BLUE);
  }
}

bool Robot::hasValidInput() {
  for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
    if(!slave[i]->hasValidInput()) {
      return false;
    }
  }
  return true;
}

void Robot::AdsReadCon(AmsAddr& rAddr, ULONG invokeId, ULONG nResult, ULONG cbLength, PVOID pData) {
  int slave_index=-1;
  for(int i=0;i<ROBOT_NUM_SLAVE;i++) {
    if(invokeId==parameters->ksoe_slave_parameters[i].slave_address) {
      slave_index=i;
      break;
    }
  }
  if(slave_index==-1) {
    trace->Log(tlError, "%s Robot::AdsReadCon(): Ads request for unknown slave (invokeId=%d, nResult=0x%08x, cbLength=%d, pData=0x%p)",
      parameters->name, invokeId, nResult, cbLength, pData);
  }
  else {
    if(nResult==ADSERR_NOERR && pData!=NULL) {
      USHORT temperature=*((WORD*)pData);
      trace->Log(tlVerbose, "%s Robot::AdsReadCon(): Motor temperature %d=%d K",
        parameters->name, parameters->ksoe_slave_parameters[slave_index].connection_id, temperature);
      slave[slave_index]->setMotorTemperature(temperature);
    }
    else {
      //Set an invalid temperature to signalize an error.
      slave[slave_index]->setMotorTemperature(0);
      trace->Log(tlError, "%s Robot::AdsReadCon(): Ads request failed (invokeId=%d, nResult=0x%08x, cbLength=%d, pData=0x%p)",
        parameters->name, invokeId, nResult, cbLength, pData);
    }
  }
}

KsoeState Robot::getCollectiveState() {
  KsoeState state=slave[0]->getState();
  for(int i=1;i<ROBOT_NUM_SLAVE;i++) {
    if(state!=slave[i]->getState()) {
      state=KsoeState::NONE;
      break;
    }
  }
  return state;
}

//Exported and adapted from "\Dissertation\Kleine Arbeiten\170718_Modell KUKA LBR iiwa complete\iiwa.mw"
void Robot::gravitationVector(double *q, double *g, bool hanging) {
  double G=(hanging?-1.0:1.0)*9.81;
  double t1;
  double t10;
  double t107;
  double t11;
  double t110;
  double t114;
  double t12;
  double t121;
  double t13;
  double t14;
  double t16;
  double t17;
  double t18;
  double t19;
  double t2;
  double t21;
  double t22;
  double t23;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t3;
  double t30;
  double t31;
  double t32;
  double t34;
  double t35;
  double t37;
  double t39;
  double t4;
  double t40;
  double t44;
  double t45;
  double t47;
  double t49;
  double t5;
  double t51;
  double t54;
  double t6;
  double t7;
  double t8;
  double t9;
  double t91;
  double t96;
  g[0]=0;
  g[1]=0;
  g[2]=0;
  g[3]=0;
  g[4]=0;
  g[5]=0;
  g[6]=0;
  t1=q[6];
  t2=cos_(t1);
  t3=0.1643152e-2 * t2;
  t4=sin_(t1);
  t5=0.80259e-4 * t4;
  t6=-t3-t5+0.84216e-3;
  t7=q[5];
  t8=cos_(t7);
  t9=t6 * t8;
  t10=sin_(t7);
  t11=0.124370946e0 * t10;
  t12=t9-t11+0.107673e-3;
  t13=q[4];
  t14=cos_(t13);
  t16=0.80259e-4 * t2;
  t17=0.1643152e-2 * t4;
  t18=-t16+t17-0.73105972e-1;
  t19=sin_(t13);
  t21=t12 * t14+t18 * t19+0.1072449e-2;
  t22=q[3];
  t23=cos_(t22);
  t25=0.124370946e0 * t8;
  t26=t6 * t10;
  t27=t25+t26+0.2314612219e1;
  t28=sin_(t22);
  t29=t27 * t28;
  t30=t21 * t23+t29+0.5824e-3;
  t31=q[2];
  t32=cos_(t31);
  t34=sin_(t31);
  t35=t18 * t34;
  t37=-t6;
  t39=t37 * t8+t11-0.107673e-3;
  t40=t39 * t34;
  t44=q[1];
  t45=cos_(t44);
  t47=t27 * t23;
  t49=-t18;
  t51=t39 * t14+t49 * t19-0.1072449e-2;
  t54=sin_(t44);
  g[1]=(G * ((t30 * t32+t35 * t14+t40 * t19-0.15810274e-1 * t34+0.105684e-3) * t45-(t47+t51 * t28+0.581448144e1) * t54));
  g[2]=(G * (-t30 * t34+t18 * t32 * t14+t39 * t32 * t19-0.15810274e-1 * t32) * t54);
  g[3]=(G * ((-t21 * t28+t47) * t32 * t54+(t23 * t51-t29) * t45));
  g[4]=(G * (((-t12 * t19+t14 * t18) * t23 * t32-t35 * t19+t40 * t14) * t54+(t14 * t49-t19 * t39) * t28 * t45));
  t91=-t11+t9;
  t96=-t10 * t37+t25;
  g[5]=(G * ((((-t26-t25) * t14 * t23+t91 * t28) * t32+t96 * t34 * t19) * t54+(t14 * t28 * t96+t23 * t91) * t45));
  t107=t17-t16;
  t110=t5+t3;
  t114=t107 * t10;
  t121=-t107 * t8;
  g[6]=(G * ((((t107 * t14 * t8+t110 * t19) * t23+t114 * t28) * t32+t110 * t34 * t14+t121 * t34 * t19) * t54+(t114 * t23+(-t110 * t19+t121 * t14) * t28) * t45));
}
