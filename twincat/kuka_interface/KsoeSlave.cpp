///////////////////////////////////////////////////////////////////////////////
// KsoeSlave.cpp
#include "TcPch.h"
#pragma hdrstop

#include "KsoeSlave.h"

USHORT KsoeSlave::crcTable[256]={
  0x0000, 0xE54F, 0x2FD1, 0xCA9E, 0x5FA2, 0xBAED, 0x7073, 0x953C, 0xBF44, 0x5A0B, 0x9095, 0x75DA, 0xE0E6, 0x05A9, 0xCF37, 0x2A78,
  0x9BC7, 0x7E88, 0xB416, 0x5159, 0xC465, 0x212A, 0xEBB4, 0x0EFB, 0x2483, 0xC1CC, 0x0B52, 0xEE1D, 0x7B21, 0x9E6E, 0x54F0, 0xB1BF,
  0xD2C1, 0x378E, 0xFD10, 0x185F, 0x8D63, 0x682C, 0xA2B2, 0x47FD, 0x6D85, 0x88CA, 0x4254, 0xA71B, 0x3227, 0xD768, 0x1DF6, 0xF8B9,
  0x4906, 0xAC49, 0x66D7, 0x8398, 0x16A4, 0xF3EB, 0x3975, 0xDC3A, 0xF642, 0x130D, 0xD993, 0x3CDC, 0xA9E0, 0x4CAF, 0x8631, 0x637E,
  0x40CD, 0xA582, 0x6F1C, 0x8A53, 0x1F6F, 0xFA20, 0x30BE, 0xD5F1, 0xFF89, 0x1AC6, 0xD058, 0x3517, 0xA02B, 0x4564, 0x8FFA, 0x6AB5,
  0xDB0A, 0x3E45, 0xF4DB, 0x1194, 0x84A8, 0x61E7, 0xAB79, 0x4E36, 0x644E, 0x8101, 0x4B9F, 0xAED0, 0x3BEC, 0xDEA3, 0x143D, 0xF172,
  0x920C, 0x7743, 0xBDDD, 0x5892, 0xCDAE, 0x28E1, 0xE27F, 0x0730, 0x2D48, 0xC807, 0x0299, 0xE7D6, 0x72EA, 0x97A5, 0x5D3B, 0xB874,
  0x09CB, 0xEC84, 0x261A, 0xC355, 0x5669, 0xB326, 0x79B8, 0x9CF7, 0xB68F, 0x53C0, 0x995E, 0x7C11, 0xE92D, 0x0C62, 0xC6FC, 0x23B3,
  0x819A, 0x64D5, 0xAE4B, 0x4B04, 0xDE38, 0x3B77, 0xF1E9, 0x14A6, 0x3EDE, 0xDB91, 0x110F, 0xF440, 0x617C, 0x8433, 0x4EAD, 0xABE2,
  0x1A5D, 0xFF12, 0x358C, 0xD0C3, 0x45FF, 0xA0B0, 0x6A2E, 0x8F61, 0xA519, 0x4056, 0x8AC8, 0x6F87, 0xFABB, 0x1FF4, 0xD56A, 0x3025,
  0x535B, 0xB614, 0x7C8A, 0x99C5, 0x0CF9, 0xE9B6, 0x2328, 0xC667, 0xEC1F, 0x0950, 0xC3CE, 0x2681, 0xB3BD, 0x56F2, 0x9C6C, 0x7923,
  0xC89C, 0x2DD3, 0xE74D, 0x0202, 0x973E, 0x7271, 0xB8EF, 0x5DA0, 0x77D8, 0x9297, 0x5809, 0xBD46, 0x287A, 0xCD35, 0x07AB, 0xE2E4,
  0xC157, 0x2418, 0xEE86, 0x0BC9, 0x9EF5, 0x7BBA, 0xB124, 0x546B, 0x7E13, 0x9B5C, 0x51C2, 0xB48D, 0x21B1, 0xC4FE, 0x0E60, 0xEB2F,
  0x5A90, 0xBFDF, 0x7541, 0x900E, 0x0532, 0xE07D, 0x2AE3, 0xCFAC, 0xE5D4, 0x009B, 0xCA05, 0x2F4A, 0xBA76, 0x5F39, 0x95A7, 0x70E8,
  0x1396, 0xF6D9, 0x3C47, 0xD908, 0x4C34, 0xA97B, 0x63E5, 0x86AA, 0xACD2, 0x499D, 0x8303, 0x664C, 0xF370, 0x163F, 0xDCA1, 0x39EE,
  0x8851, 0x6D1E, 0xA780, 0x42CF, 0xD7F3, 0x32BC, 0xF822, 0x1D6D, 0x3715, 0xD25A, 0x18C4, 0xFD8B, 0x68B7, 0x8DF8, 0x4766, 0xA229
};

KsoeSlave::KsoeSlave(CTcTrace *trace,int connection_id,void *input_buffer,void *output_buffer, PDSParameters* parameters, const AxisLimits* limits, const Axis* axis1) :
	KsoeSlave(trace, connection_id, input_buffer, output_buffer, parameters, limits, axis1, NULL)
{
}

KsoeSlave::KsoeSlave(CTcTrace *trace, int connection_id, void *input_buffer, void *output_buffer, PDSParameters* parameters, const AxisLimits* limits, const Axis* axis1, const Axis* axis2) {
  this->trace=trace;
  this->type=type;
  this->connection_id=connection_id;
  this->input_buffer=input_buffer;
  this->output_buffer=output_buffer;
  this->parameters=parameters;
  this->axis1=axis1;
  this->axis2=axis2;
  this->limits=limits;
  type=(axis2==NULL?KsoeSlaveType::PDS1:KsoeSlaveType::PDS23);
  //Initialize the (currently unknown) motor temperature to 300 K
  this->motor_temperature=300;
  this->position1_filter=new PT1(axis1->position_filter_f_0);
  this->velocity1_filter=new DT1(axis1->velocity_filter_f_0);
  this->torque1_filter=new PT1(axis1->torque_filter_f_0);
  this->torque_derivative1_filter=new DT1(axis1->torque_derivative_filter_f_0);
  if(type==KsoeSlaveType::PDS23) {
    this->position2_filter=new PT1(axis2->position_filter_f_0);
    this->velocity2_filter=new DT1(axis2->velocity_filter_f_0);
    this->torque2_filter=new PT1(axis2->torque_filter_f_0);
    this->torque_derivative2_filter=new DT1(axis2->torque_derivative_filter_f_0);
  }
  else {
    this->position2_filter=NULL;
    this->velocity2_filter=NULL;
    this->torque2_filter=NULL;
    this->torque_derivative2_filter=NULL;
  }
  reset();
}

KsoeSlave::~KsoeSlave() {
  delete position1_filter;
  delete velocity1_filter;
  delete torque1_filter;
  delete torque_derivative1_filter;
  if(type==KsoeSlaveType::PDS23) {
    delete position2_filter;
    delete velocity2_filter;
    delete torque2_filter;
    delete torque_derivative2_filter;
  }
}

void KsoeSlave::reset() {
  trace->Log(tlVerbose, "%2d KsoeSlave::reset()",connection_id);
  memset(output_buffer,0,sizeof(PDS1_Rx));
  ((PDS1_Rx*)output_buffer)->Command=(unsigned char)KsoeState::RESET;
  motor_control_counter=0;
  sequence_number_master=KSOESLAVE_SEQUENCE_NUMBER_INITIAL;
  sequence_number_slave=KSOESLAVE_SEQUENCE_NUMBER_INITIAL;
  communication_toggle_bit=false;
  state_machine_counter=0;
  state_variable=0;
  previous_command_slave=KsoeState::NONE;
  motion_watchdog1=0;
  motion_watchdog2=0;
  motion_state_target=MotionState::STOP;
  motion_state1=MotionState::STOP;
  motion_state2=MotionState::STOP;
  state=KsoeState::RESET;
  last_error=KsoeSlaveError::NONE;
  motion_error=KsoeSlaveError::NONE;
  sensor_error=KsoeSlaveError::NONE;
  motion_warning=KsoeSlaveWarning::NONE;
  sensor_warning=KsoeSlaveWarning::NONE;
  axis1_control_motor_torque_nan=false;
  axis2_control_motor_torque_nan=false;
  axis1_control_motor_torque_limit=false;
  axis2_control_motor_torque_limit=false;
  axis1_control_motor_torque_saturated=false;
  axis2_control_motor_torque_saturated=false;
  axis1_sensor_position_soft_limit=false;
  axis2_sensor_position_soft_limit=false;
  axis1_sensor_torque_limit=false;
  axis2_sensor_torque_limit=false;
  axis1_sensor_velocity_limit=false;
  axis2_sensor_velocity_limit=false;
  position1_filter->reset();
  velocity1_filter->reset();
  torque1_filter->reset();
  torque_derivative1_filter->reset();
  if(type==KsoeSlaveType::PDS23) {
    position2_filter->reset();
    velocity2_filter->reset();
    torque2_filter->reset();
    torque_derivative2_filter->reset();
  }
}

void KsoeSlave::increaseSequenceNumber() {
  //Zero is not allowed
  sequence_number_master++;
  if(sequence_number_master==0) {
    sequence_number_master=1;
  }
  sequence_number_slave++;
  if(sequence_number_slave==0) {
    sequence_number_slave=1;
  }
}

USHORT KsoeSlave::previousSequenceNumber(USHORT s) {
  //Zero is not allowed
  if(s==0x0001) {
    s=0xFFFF;
  }
  else {
    s--;
  }
  return s;
}

void KsoeSlave::statemachine(DWORD dc_time_L) {
  //Call stateMachine() every 12 ms.
  state_machine_counter++;
  if(state_machine_counter<(12000/125)) return;
  state_machine_counter=0;
  
  PDS1_Tx* input=(PDS1_Tx*)input_buffer;
  PDS1_Rx* output=(PDS1_Rx*)output_buffer;

  KsoeState command_slave=(KsoeState)(input->Command);
  unsigned char* output_data=(unsigned char*)&output->Used_Time_stamp;
  unsigned char* input_data=(unsigned char*)&input->Time_stamp;
  int pos;

  /*
  trace->Log(tlVerbose,"%2d KsoeSlave::statemachine(): M <- S, %02x  %02x %02x %02x %02x %02x %02x, 0x%04x",connection_id,
    input->Command, input_data[0], input_data[1], input_data[2], input_data[3], input_data[4], input_data[5], sequence_number_master);
  */

  //Don't proceed if there are non-acknowledged errors.
  if(last_error!=KsoeSlaveError::NONE) return;

  //If the slaves issues a RESET command while the master is not in the
  //RESET state, then accept this state and implicitly perform a reset as well.
  if((input->Command&0xFE)==(unsigned char)KsoeState::RESET &&
    state!=KsoeState::RESET) {
    trace->Log(tlError, "%2d KsoeSlave::statemachine(): Slave requested reset.", connection_id);
    setLastError(KsoeSlaveError::SLAVE_RESET);
  }
  //The state machine is called every 12 ms. By this time, the slave should have
  //responded with the same command byte as the master sent to it (with the
  //exception of the communication toggle bit, bit0 of the Command byte).
  else if(previous_command_slave==command_slave ||
    (input->Command&0xFE)!=(output->Command&0xFE)) {
    trace->Log(tlError, "%2d KsoeSlave::statemachine(): Slave responded with wrong command 0x%02x or didn't update its response.", connection_id, input->Command);
    setLastError(KsoeSlaveError::WRONG_COMMAND);
  }
  else {
    //At this point, the slave must have arrived at the exact same state as the master.
    //Therefore, checking of the slave state is not necessary anymore.
    switch(state) {
      case KsoeState::RESET:
        //Assumes, that the function reset() was called to arrive in this state. Therefore,
        //all outputs are reset to zero already.

        //Slave is in RESET-State: Go to SESSION-State.
        output->Command=(unsigned char)KsoeState::SESSION;
        output_data[0]=LOBYTE(KSOESLAVE_SEQUENCE_NUMBER_START);
        output_data[1]=HIBYTE(KSOESLAVE_SEQUENCE_NUMBER_START);
        setState(KsoeState::SESSION);
        break;

      case KsoeState::SESSION:
        sequence_number_master=KSOESLAVE_SEQUENCE_NUMBER_START;
        sequence_number_slave=(((USHORT)input_data[1])<<8)+(USHORT)input_data[0];
        output->Command=(unsigned char)KsoeState::CONNECTION;
        output->Connection_ID=connection_id;
        output_data[0]=LOBYTE(output->Connection_ID);
        output_data[1]=HIBYTE(output->Connection_ID);
        output_data[2]=LOBYTE(output->Connection_ID);
        output_data[3]=HIBYTE(output->Connection_ID);
        setState(KsoeState::CONNECTION);
        break;

      case KsoeState::CONNECTION:
        //Directly go to the PARAMETER state and start sending parameters
        state_variable=0;
        setState(KsoeState::PARAMETER);
        //fall through
      case KsoeState::PARAMETER:
        output->Command=(unsigned char)KsoeState::PARAMETER;
        pos=state_variable*6;
        for(int i = 0;i<6;i++) {
          if((pos+i)<parameters->length) {
            output_data[i]=parameters->data[pos+i];
          }
          else {
            output_data[i]=0;
          }
        }
        pos+=6;
        if(pos>=parameters->length) {
          state_variable=-1;
          setState(KsoeState::PROCESS_DATA);
        }
        else {
          state_variable++;
        }
        increaseSequenceNumber();
        break;

      case KsoeState::PROCESS_DATA:
        if(state_variable==-1) {
          //Initialize the state and process data variables.
          output->VMT_Challenge=0xC2;
          state_variable=0;
        }
        else {
          //Check the slave VMT response
          if(input->VMT_Response!=(unsigned char)-(char)output->VMT_Challenge) {
            trace->Log(tlError, "%2d KsoeSlave::statemachine(): Wrong VMT Response 0x%02x (Challenge was 0x%02x).",
              connection_id, input->VMT_Response, output->VMT_Challenge);
            setLastError(KsoeSlaveError::WRONG_VMT_RESPONSE);
            break;
          }
          //Update the VMT challenge
          output->VMT_Challenge=output->VMT_Challenge*5+3;
        }
        output->Command=(unsigned char)KsoeState::PROCESS_DATA;
        //Master sets his Used_Time_stamp to 2.75 ms behind the DC time.
        output->Used_Time_stamp=(DWORD)(dc_time_L-2750000LL);
        increaseSequenceNumber();
        break;

      default:
        trace->Log(tlError, "%2d KsoeSlave::statemachine(): Unknown State 0x%02x.", connection_id, state);
        setLastError(KsoeSlaveError::UNKNOWN_STATE);
        break;
    }
    if(communication_toggle_bit) {
      output->Command|=0x01;
    }
    communication_toggle_bit=!communication_toggle_bit;
    previous_command_slave=(KsoeState)input->Command;
  }
  /*
  trace->Log(tlVerbose,"%2d KsoeSlave::statemachine(): M -> S, %02x  %02x %02x %02x %02x %02x %02x, 0x%04x",connection_id,
    output->Command, output_data[0], output_data[1], output_data[2], output_data[3], output_data[4], output_data[5], sequence_number_slave);
  */
}

void KsoeSlave::setState(KsoeState s) {
  trace->Log(tlInfo, "%2d KsoeSlave::setState(): %s (0x%02x) -> %s (0x%02x)",connection_id,toString(state),state,toString(s),s);
  state=s;
}

void KsoeSlave::setMotionState1(MotionState s) {
  trace->Log(tlInfo, "%2d KsoeSlave::setMotionState1(): %s (0x%02x) -> %s (0x%02x)",connection_id,toString(motion_state1),motion_state1,toString(s),s);
  motion_state1=s;
}

void KsoeSlave::setMotionState2(MotionState s) {
  trace->Log(tlInfo, "%2d KsoeSlave::setMotionState2(): %s (0x%02x) -> %s (0x%02x)", connection_id, toString(motion_state2), motion_state2, toString(s), s);
  motion_state2=s;
}

void KsoeSlave::setMotionStateTarget(MotionState s) {
  if(s!=MotionState::MOTION) s=MotionState::STOP;
  trace->Log(tlInfo, "%2d KsoeSlave::setMotionStateTarget(): 0x%02x -> 0x%02x",connection_id,motion_state_target,s);
  motion_state_target=s;
}

MotionState KsoeSlave::getMotionStateTarget() {
  return motion_state_target;
}

void KsoeSlave::feedMotionWatchdog1() {
  motion_watchdog1=0;
}

void KsoeSlave::feedMotionWatchdog2() {
  motion_watchdog2=0;
}

void KsoeSlave::checkCrcReadSensor(AxisSensor *input1, AxisSensor *input2) {
  bool pds23=(type==KsoeSlaveType::PDS23 && input2!=NULL);
  PDS1_Tx* input=(PDS1_Tx*)input_buffer;

  //Check in every cycle if the error still persists.
  sensor_error=KsoeSlaveError::NONE;
  sensor_warning=KsoeSlaveWarning::NONE;
  if(checkCrc()) {
    //Calculate the sensor signals. This should always be possible as soon as the slave
    //sends data. Therefore, check only for the reset state.
    if(state==KsoeState::RESET) {
      input1->motor_torque_feedback=0;
      input1->position=0;
      input1->torque=0;
      input1->position_filtered=0;
      input1->velocity_filtered=0;
      input1->torque_filtered=0;
      input1->torque_derivative_filtered=0;
      if(pds23) {
        input2->motor_torque_feedback=0;
        input2->position=0;
        input2->torque=0;
        input2->position_filtered=0;
        input2->velocity_filtered=0;
        input2->torque_filtered=0;
        input2->torque_derivative_filtered=0;
      }
    }
    else {
      //Read the measured motor torque and calculate it to the downthrust side (after the harmonic drive)
      input1->motor_torque_feedback=current2torque(axis1, input->Motor_torque_1*axis1->current_resolution)*axis1->gear_ratio;
      input1->position=((long)input->Position_1)*axis1->position_resolution;
      input1->torque=input->Torque_1*axis1->sensor_torque_resolution;
      input1->position_filtered=position1_filter->updateAndOutput(input1->position);
      input1->velocity_filtered=velocity1_filter->updateAndOutput(input1->position);
      input1->torque_filtered=torque1_filter->updateAndOutput(input1->torque);
      input1->torque_derivative_filtered=torque_derivative1_filter->updateAndOutput(input1->torque);
      input1->temperature=(double)motor_temperature;
      if(pds23) {
        input2->motor_torque_feedback=current2torque(axis2, ((PDS23_Tx*)input)->Motor_torque_2*axis2->current_resolution)*axis2->gear_ratio;
        input2->position=((long)((PDS23_Tx*)input)->Position_2)*axis2->position_resolution;
        input2->torque=((PDS23_Tx*)input)->Torque_2*axis2->sensor_torque_resolution;
        input2->position_filtered=position2_filter->updateAndOutput(input2->position);
        input2->velocity_filtered=velocity2_filter->updateAndOutput(input2->position);
        input2->torque_filtered=torque2_filter->updateAndOutput(input2->torque);
        input2->torque_derivative_filtered=torque_derivative2_filter->updateAndOutput(input2->torque);
        input2->temperature=(double)motor_temperature;
      }
      //Perform all checks on the filtered signals to prevent spontaneous measurement errors from
      //causing an emergency stop.
      //Check soft position limit
      if(fabs_(input1->position)>(axis1->position_limit-limits->position_reserve)) {
        //Position limit for axis 1 was exceeded. Check if the velocity is directed further into the limit.
        KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 1 Position Soft Limit", KsoeSlaveWarning::POSITION_SOFT_LIMIT,
          input1->position>0&&input1->velocity_filtered>KSOESLAVE_VELOCITY_TOLERANCE||
          input1->position<0&&input1->velocity_filtered<-KSOESLAVE_VELOCITY_TOLERANCE,
          axis1_sensor_position_soft_limit);
      }
      if(pds23 && fabs_(input2->position)>(axis2->position_limit-limits->position_reserve)) {
        //Position limit for axis 2 was exceeded. Check if the velocity is directed further into the limit.
        KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 2 Position Soft Limit", KsoeSlaveWarning::POSITION_SOFT_LIMIT,
          input2->position>0&&input2->velocity_filtered>KSOESLAVE_VELOCITY_TOLERANCE||
          input2->position<0&&input2->velocity_filtered<-KSOESLAVE_VELOCITY_TOLERANCE,
          axis2_sensor_position_soft_limit);
      }
      //Check hard position limit
      if(fabs_(input1->position)>(axis1->position_limit-KSOESLAVE_POSITION_LIMIT_DISTANCE)) {
        //Position limit for axis 1 was exceeded. Check if the velocity is directed further into the limit.
        if(input1->position>0&&input1->velocity_filtered>KSOESLAVE_VELOCITY_TOLERANCE||
          input1->position<0&&input1->velocity_filtered<-KSOESLAVE_VELOCITY_TOLERANCE) {
          if(getMotionStateTarget()!=MotionState::STOP) {
            trace->Log(tlError, "%2d KsoeSlave::checkCrcReadSensor(): Motion aborted due to position limit in axis 1 (%.2f °).", connection_id, AXIS_RAD2DEG(input1->position));
          }
          sensor_error=KsoeSlaveError::POSITION_LIMIT_HARD;
        }
      }
      if(pds23 && fabs_(input2->position)>(axis2->position_limit-KSOESLAVE_POSITION_LIMIT_DISTANCE)) {
        //Position limit for axis 2 was exceeded. Check if the velocity is directed further into the limit.
        if(input2->position>0&&input2->velocity_filtered>KSOESLAVE_VELOCITY_TOLERANCE||
          input2->position<0&&input2->velocity_filtered<-KSOESLAVE_VELOCITY_TOLERANCE) {
          if(getMotionStateTarget()!=MotionState::STOP) {
            trace->Log(tlError, "%2d KsoeSlave::checkCrcReadSensor(): Motion aborted due to position limit in axis 2 (%.2f °).", connection_id, AXIS_RAD2DEG(input2->position));
          }
          sensor_error=KsoeSlaveError::POSITION_LIMIT_HARD;
        }
      }
      //Check velocity limit
      KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 1 Velocity Limit", KsoeSlaveWarning::VELOCITY_LIMIT,
        fabs_(input1->velocity_filtered)>axis1->velocity_limit*limits->velocity_limit_fraction,
        axis1_sensor_velocity_limit);
      KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 2 Velocity Limit", KsoeSlaveWarning::VELOCITY_LIMIT,
        pds23 && fabs_(input2->velocity_filtered)>axis2->velocity_limit*limits->velocity_limit_fraction,
        axis2_sensor_velocity_limit);
      //Check sensor torque limit
      KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 1 Sensor Torque Limit", KsoeSlaveWarning::SENSOR_TORQUE_LIMIT,
        fabs_(input1->torque)>=axis1->sensor_nominal_torque*limits->sensor_torque_limit_fraction,
        axis1_sensor_torque_limit);
      KSOESLAVE_HANDLE_SENSOR_WARNING_FLAG("Axis 2 Sensor Torque Limit", KsoeSlaveWarning::SENSOR_TORQUE_LIMIT,
        pds23 && fabs_(input2->torque)>=axis2->sensor_nominal_torque*limits->sensor_torque_limit_fraction,
        axis2_sensor_torque_limit);
    }
  }
  else {
    input1->motor_torque_feedback=0;
    input1->position=0;
    input1->torque=0;
    input1->position_filtered=0;
    input1->velocity_filtered=0;
    input1->torque_filtered=0;
    input1->torque_derivative_filtered=0;
    if(pds23) {
      input2->motor_torque_feedback=0;
      input2->position=0;
      input2->torque=0;
      input2->position_filtered=0;
      input2->velocity_filtered=0;
      input2->torque_filtered=0;
      input2->torque_derivative_filtered=0;
    }
    setLastError(KsoeSlaveError::WRONG_CRC);
    trace->Log(tlError, "%2d KsoeSlave::CycleUpdate(): Wrong CRC.", connection_id);
  }
}

void KsoeSlave::statemachineWriteControlGenerateCrc(AxisControl *output1, AxisControl *output2, DWORD dc_time_L) {
  PDS1_Tx* input=(PDS1_Tx*)input_buffer;
  PDS1_Rx* output=(PDS1_Rx*)output_buffer;
  bool pds23=(type==KsoeSlaveType::PDS23 && output2!=NULL);
  double current;

  //First, handle the statmachine
  statemachine(dc_time_L);

  motion_watchdog1++;
  if(motion_watchdog1>=KSOESLAVE_MOTION_WATCHDOG_TICKS) {
    trace->Log(tlError, "%2d KsoeSlave::updateIOs(): Motion aborted by watchdog1 in state %s (0x%02x), target %s (0x%02x).",
      connection_id, toString(motion_state1), motion_state1, toString(motion_state_target), motion_state_target);
    setLastError(KsoeSlaveError::MOTION_WATCHDOG);
  }
  if(pds23) {
    motion_watchdog2++;
    if(motion_watchdog2>=KSOESLAVE_MOTION_WATCHDOG_TICKS) {
      trace->Log(tlError, "%2d KsoeSlave::updateIOs(): Motion aborted by watchdog2 in state %s (0x%02x), target %s (0x%02x).",
        connection_id, toString(motion_state2), motion_state2, toString(motion_state_target), motion_state_target);
      setLastError(KsoeSlaveError::MOTION_WATCHDOG);
    }
  }

  //Clear the motor_control_counter bits
  //0x87FF = 0b1000 0111 1111 1111
  //The motor_control_counter bits are always processed, even if there is an error state.
  input->Motor_status_1&=0x87FF;
  output->Motor_control_1&=0x87FF;
  if(pds23) {
    ((PDS23_Tx*)input)->Motor_status_2&=0x87FF;
    ((PDS23_Rx*)output)->Motor_control_2&=0x87FF;
  }
  //Handle all other IOs only, when there is no error present.
  if(last_error==KsoeSlaveError::NONE) {
    if(state!=KsoeState::PROCESS_DATA) {
      //Always feed the motion watchdog when not in PROCESS_DATA state
      feedMotionWatchdog1();
      feedMotionWatchdog2();
    }
    else {
      //Otherwise, the current motion state is responsible for feeding the motion watchdog

      //Reset slave error states. Only the enabled motors are checked.
      motion_error=KsoeSlaveError::NONE;
      motion_warning=KsoeSlaveWarning::NONE;

      //Acknowledge all sensor states
      output->Ack_mastered_1=input->Position_mastered_1;
      output->Ack_referenced_1=!input->Position_referencing_1;
      output->Ack_GMS_mastered_1=input->GMS_mastered_1;
      output->Ack_GMS_referenced_1=!input->GMS_referencing_1;
      //Not_used_15 == Ack_Brake_released_1
      output->Not_used_15=input->Brake_released_1?0x01:0x00;
      if(pds23) {
        ((PDS23_Rx*)output)->Ack_mastered_2=((PDS23_Tx*)input)->Position_mastered_2;
        ((PDS23_Rx*)output)->Ack_referenced_2=!((PDS23_Tx*)input)->Position_referencing_2;
        ((PDS23_Rx*)output)->Ack_GMS_mastered_2=((PDS23_Tx*)input)->GMS_mastered_2;
        ((PDS23_Rx*)output)->Ack_GMS_referenced_2=!((PDS23_Tx*)input)->GMS_referencing_2;
        //Not_used_21 == Ack_Brake_released_2
        ((PDS23_Rx*)output)->Not_used_21=((PDS23_Tx*)input)->Brake_released_2?0x01:0x00;
      }

      //Acknowledge errors concerning both motors
      KSOESLAVE_HANDLE_ERROR_FLAG("Error SafeOs Runtime", KsoeSlaveError::SAFE_OS_RUNTIME,
        input->Error_SafeOs_Runtime, output->Ack_Error_SafeOs_Runtime);

      if(output1->motor_enable) {
        //KSOESLAVE_HANDLE_ERROR_FLAG() sets local variable "motion_error", if an error is present
        //Only check for errors if the corresponding motor is enabled.
        KSOESLAVE_HANDLE_ERROR_FLAG("Motor error STO intern 1", KsoeSlaveError::MOTOR_SAFE_TORQUE_OFF_INTERN,
          input->Motor_error_STO_intern_1, output->Ack_Motor_error_STO_intern_1);
        KSOESLAVE_HANDLE_ERROR_FLAG("Error static STO 1", KsoeSlaveError::STATIC_SAFE_TORQUE_OFF,
          input->Error_static_STO_1, output->Ack_error_static_STO_1);
        KSOESLAVE_HANDLE_ERROR_FLAG("Motor warning low voltage 1", KsoeSlaveError::MOTOR_WARNING_LOW_VOLTAGE,
          input->Motor_warning_low_voltage_1, output->Ack_Motor_warning_low_voltage_1);
        KSOESLAVE_HANDLE_ERROR_FLAG("HS SBC 1", KsoeSlaveError::HS_SBC,
          input->Error_HS_SBC_1, output->Ack_error_HS_SBC_1);
        KSOESLAVE_HANDLE_ERROR_FLAG("SBC 1", KsoeSlaveError::HS_SBC,
          input->Error_SBC_1, output->Ack_error_SBC_1);
        //Calculate the motor torque from the downthrust desired torque.
        current=torque2current(axis1, output1->motor_torque/axis1->gear_ratio);
        KSOESLAVE_HANDLE_MOTION_WARNING_FLAG("Invalid Motor Torque 1", KsoeSlaveWarning::INVALID_MOTOR_TORQUE,
          isnan_(output1->motor_torque)||!isfinite_(output1->motor_torque),
          axis1_control_motor_torque_nan);
        //current is limited by torque2current() additionally to the nominal current.
        KSOESLAVE_HANDLE_MOTION_WARNING_FLAG("Motor 1 Torque Limit",KsoeSlaveWarning::MOTOR_TORQUE_LIMIT,
          fabs_(output1->motor_torque/axis1->gear_ratio)>=(AXIS_CURRENT_TO_TORQUE(axis1, axis1->nominal_current, motor_temperature)*limits->motor_torque_limit_fraction),
          axis1_control_motor_torque_limit);
        //If there are any slave motor errors until now, disable all motors (torque=0) and stop
        //motion via the outer robot control Robot::WriteControl()
        if(motion_error!=KsoeSlaveError::NONE) {
          output->Motor_torque_1=0;
        }
        else {
          //Saturate the current
          if(fabs_(current)>=(axis1->nominal_current*limits->motor_torque_saturation)) {
            current=axis1->nominal_current*limits->motor_torque_saturation*sgn_(current);
            if(!axis1_control_motor_torque_saturated) {
              trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): Motor 1 saturation active.", connection_id);
            }
            axis1_control_motor_torque_saturated=true;
          }
          else {
            if(axis1_control_motor_torque_saturated) {
              trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): Motor 1 saturation cleared.", connection_id);
            }
            axis1_control_motor_torque_saturated=false;
          }
          output->Motor_torque_1=(short)(current/axis1->current_resolution);
        }

        switch(motion_state1) {
          case MotionState::STOP:
            output->Device_control=0x0000;
            output->Soft_stop_1=1;
            output->Motion_enable_1=0;
            output->Cross_force_compensation_1=axis1->cross_force_compensation; //Aus CrossForceCompParams.xml
            output->Torque_collision_level_1=0;
            output->Motor_control_1=0x0004;
            if(motion_state_target==MotionState::MOTION) {
              setMotionState1(MotionState::MOTION_ENABLE);
            }
            feedMotionWatchdog1();
            break;
          case MotionState::MOTION_ENABLE:
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(motion_state_target);
              feedMotionWatchdog1();
            }
            else if((input->Motor_status_1==0x0021||input->Motor_status_1==0x0060)) {
              output->Soft_stop_1=0;
              output->Motion_enable_1=1;
              output->Motor_control_1=0x0006;
              setMotionState1(MotionState::MOTOR_CONTROL_1);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTOR_CONTROL_1:
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(MotionState::MOTOR_CONTROL_1_STOPPING);
              feedMotionWatchdog1();
            }
            else if(input->Motor_status_1==0x0021) {
              output->Motor_control_1=0x0007;
              setMotionState1(MotionState::MOTOR_CONTROL_2);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTOR_CONTROL_2:
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(MotionState::MOTOR_CONTROL_2_STOPPING);
              feedMotionWatchdog1();
            }
            else if(input->Motor_status_1==0x0033) {
              output->Motor_control_1=0x000f;
              setMotionState1(MotionState::MOTOR_CONTROL_3);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTOR_CONTROL_3:
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(MotionState::MOTOR_CONTROL_3_STOPPING);
              feedMotionWatchdog1();
            }
            else if(input->Motor_status_1==0x0037) {
              output->Motor_control_1=0x800f;
              setMotionState1(MotionState::ENGAGING_MOTION);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::ENGAGING_MOTION:
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(MotionState::DISENGAGING_MOTION);
              feedMotionWatchdog1();
            }
            else if(input->Motor_status_1&0x8000) {
              setMotionState1(MotionState::MOTION);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTION:
            //Do nothing, wait for stop command.
            if(motion_state_target==MotionState::STOP) {
              setMotionState1(MotionState::DISENGAGING_MOTION);
            }
            feedMotionWatchdog1();
            break;
          case MotionState::DISENGAGING_MOTION:
            output->Motor_control_1=0x000f;
            setMotionState1(MotionState::MOTOR_CONTROL_3_STOPPING);
            feedMotionWatchdog1();
            break;
          case MotionState::MOTOR_CONTROL_3_STOPPING:
            if(input->Motor_status_1==0x00037) {
              output->Motor_control_1=0x0007;
              setMotionState1(MotionState::MOTOR_CONTROL_2_STOPPING);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTOR_CONTROL_2_STOPPING:
            if(input->Motor_status_1==0x0033) {
              output->Motor_control_1=0x0006;
              setMotionState1(MotionState::MOTOR_CONTROL_1_STOPPING);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTOR_CONTROL_1_STOPPING:
            if(input->Motor_status_1==0x0021) {
              output->Soft_stop_1=1;
              output->Motion_enable_1=0;
              setMotionState1(MotionState::MOTION_DISABLE);
              feedMotionWatchdog1();
            }
            break;
          case MotionState::MOTION_DISABLE:
            if(input->Actual_STO_1==0&&input->Actual_SBC_1==0) {
              setMotionState1(MotionState::STOP);
              feedMotionWatchdog1();
            }
            break;
        }
      }
      else {
        //Replicate the outputs of the motion state MotionState::STOP
        output->Device_control=0x0000;
        output->Soft_stop_1=1;
        output->Motion_enable_1=0;
        output->Cross_force_compensation_1=axis1->cross_force_compensation; //Aus CrossForceCompParams.xml
        output->Torque_collision_level_1=0;
        output->Motor_control_1=0x0004;
        output->Motor_torque_1=0;
        //Always stay in motion state STOP
        if(motion_state1!=MotionState::STOP) {
          setMotionState1(MotionState::STOP);
        }
        feedMotionWatchdog1();
      }

      if(pds23) {
        if(output2->motor_enable) {
          //KSOESLAVE_HANDLE_ERROR_FLAG() sets local variable "motion_error", if an error is present
          //Only check for errors if the corresponding motor is enabled.
          KSOESLAVE_HANDLE_ERROR_FLAG("Motor error STO intern 2", KsoeSlaveError::MOTOR_SAFE_TORQUE_OFF_INTERN,
            ((PDS23_Tx*)input)->Motor_error_STO_intern_2, ((PDS23_Rx*)output)->Ack_Motor_error_STO_intern_2);
          KSOESLAVE_HANDLE_ERROR_FLAG("Error static STO 2", KsoeSlaveError::STATIC_SAFE_TORQUE_OFF,
            ((PDS23_Tx*)input)->Error_static_STO_2, ((PDS23_Rx*)output)->Ack_error_static_STO_2);
          KSOESLAVE_HANDLE_ERROR_FLAG("Motor warning low voltage 2", KsoeSlaveError::MOTOR_WARNING_LOW_VOLTAGE,
            ((PDS23_Tx*)input)->Motor_warning_low_voltage_2, ((PDS23_Rx*)output)->Ack_Motor_warning_low_voltage_2);
          KSOESLAVE_HANDLE_ERROR_FLAG("HS SBC 2", KsoeSlaveError::HS_SBC,
            ((PDS23_Tx*)input)->Error_HS_SBC_2, ((PDS23_Rx*)output)->Ack_error_HS_SBC_2);
          KSOESLAVE_HANDLE_ERROR_FLAG("SBC 2", KsoeSlaveError::SBC,
            ((PDS23_Tx*)input)->Error_SBC_2, ((PDS23_Rx*)output)->Ack_error_SBC_2);
          //Calculate the motor torque from the downthrust desired torque.
          current=torque2current(axis2, output2->motor_torque/axis2->gear_ratio);
          KSOESLAVE_HANDLE_MOTION_WARNING_FLAG("Invalid Motor Torque 2", KsoeSlaveWarning::INVALID_MOTOR_TORQUE,
            isnan_(output2->motor_torque)||!isfinite_(output2->motor_torque),
            axis2_control_motor_torque_nan);
          KSOESLAVE_HANDLE_MOTION_WARNING_FLAG("Motor 2 Torque Limit", KsoeSlaveWarning::MOTOR_TORQUE_LIMIT,
            fabs_(output2->motor_torque/axis2->gear_ratio)>=(AXIS_CURRENT_TO_TORQUE(axis2, axis2->nominal_current, motor_temperature)*limits->motor_torque_limit_fraction),
            axis2_control_motor_torque_limit);
          //If there are any slave motor errors until now, disable all motors (torque=0) and stop
          //motion via the outer robot control Robot::WriteControl()
          if(motion_error!=KsoeSlaveError::NONE) {
            ((PDS23_Rx*)output)->Motor_torque_2=0;
          }
          else {
            if(fabs_(current)>=(axis2->nominal_current*limits->motor_torque_saturation)) {
              current=axis2->nominal_current*limits->motor_torque_saturation*sgn_(current);
              if(!axis2_control_motor_torque_saturated) {
                trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): Motor 2 saturation active.", connection_id);
              }
              axis2_control_motor_torque_saturated=true;
            }
            else {
              if(axis2_control_motor_torque_saturated) {
                trace->Log(tlWarning, "%2d KsoeSlave::updateIOs(): Motor 2 saturation cleared.", connection_id);
              }
              axis2_control_motor_torque_saturated=false;
            }
            ((PDS23_Rx*)output)->Motor_torque_2=(short)(current/axis2->current_resolution);
          }

          switch(motion_state2) {
            case MotionState::STOP:
              ((PDS23_Rx*)output)->Soft_stop_2=1;
              ((PDS23_Rx*)output)->Motion_enable_2=0;
              ((PDS23_Rx*)output)->Cross_force_compensation_2=axis2->cross_force_compensation;
              ((PDS23_Rx*)output)->Torque_collision_level_2=0;
              ((PDS23_Rx*)output)->Motor_control_2=0x0004;
              if(motion_state_target==MotionState::MOTION) {
                setMotionState2(MotionState::MOTION_ENABLE);
              }
              feedMotionWatchdog2();
              break;
            case MotionState::MOTION_ENABLE:
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(motion_state_target);
                feedMotionWatchdog2();
              }
              else if(((PDS23_Tx*)input)->Motor_status_2==0x0021||((PDS23_Tx*)input)->Motor_status_2==0x0060) {
                ((PDS23_Rx*)output)->Soft_stop_2=0;
                ((PDS23_Rx*)output)->Motion_enable_2=1;
                ((PDS23_Rx*)output)->Motor_control_2=0x0006;
                setMotionState2(MotionState::MOTOR_CONTROL_1);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTOR_CONTROL_1:
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(MotionState::MOTOR_CONTROL_1_STOPPING);
                feedMotionWatchdog2();
              }
              else if(((PDS23_Tx*)input)->Motor_status_2==0x0021) {
                ((PDS23_Rx*)output)->Motor_control_2=0x0007;
                setMotionState2(MotionState::MOTOR_CONTROL_2);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTOR_CONTROL_2:
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(MotionState::MOTOR_CONTROL_2_STOPPING);
                feedMotionWatchdog2();
              }
              else if(((PDS23_Tx*)input)->Motor_status_2==0x0033) {
                ((PDS23_Rx*)output)->Motor_control_2=0x000f;
                setMotionState2(MotionState::MOTOR_CONTROL_3);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTOR_CONTROL_3:
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(MotionState::MOTOR_CONTROL_3_STOPPING);
                feedMotionWatchdog2();
              }
              else if(((PDS23_Tx*)input)->Motor_status_2==0x0037) {
                ((PDS23_Rx*)output)->Motor_control_2=0x800f;
                setMotionState2(MotionState::ENGAGING_MOTION);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::ENGAGING_MOTION:
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(MotionState::DISENGAGING_MOTION);
                feedMotionWatchdog2();
              }
              else if(((PDS23_Tx*)input)->Motor_status_2&0x8000) {
                setMotionState2(MotionState::MOTION);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTION:
              //Do nothing, wait for stop command.
              if(motion_state_target==MotionState::STOP) {
                setMotionState2(MotionState::DISENGAGING_MOTION);
              }
              feedMotionWatchdog2();
              break;
            case MotionState::DISENGAGING_MOTION:
              ((PDS23_Rx*)output)->Motor_control_2=0x000f;
              setMotionState2(MotionState::MOTOR_CONTROL_3_STOPPING);
              feedMotionWatchdog2();
              break;
            case MotionState::MOTOR_CONTROL_3_STOPPING:
              if(((PDS23_Tx*)input)->Motor_status_2==0x0037) {
                ((PDS23_Rx*)output)->Motor_control_2=0x0007;
                setMotionState2(MotionState::MOTOR_CONTROL_2_STOPPING);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTOR_CONTROL_2_STOPPING:
              if(((PDS23_Tx*)input)->Motor_status_2==0x0033) {
                ((PDS23_Rx*)output)->Motor_control_2=0x0006;
                setMotionState2(MotionState::MOTOR_CONTROL_1_STOPPING);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTOR_CONTROL_1_STOPPING:
              if(((PDS23_Tx*)input)->Motor_status_2==0x0021) {
                ((PDS23_Rx*)output)->Soft_stop_2=1;
                ((PDS23_Rx*)output)->Motion_enable_2=0;
                setMotionState2(MotionState::MOTION_DISABLE);
                feedMotionWatchdog2();
              }
              break;
            case MotionState::MOTION_DISABLE:
              if(((PDS23_Tx*)input)->Actual_STO_2==0&&((PDS23_Tx*)input)->Actual_SBC_2==0) {
                setMotionState2(MotionState::STOP);
                feedMotionWatchdog2();
              }
              break;
          }
        }
        else {
          //Replicate the outputs of the motion state MotionState::STOP
          ((PDS23_Rx*)output)->Soft_stop_2=1;
          ((PDS23_Rx*)output)->Motion_enable_2=0;
          ((PDS23_Rx*)output)->Cross_force_compensation_2=axis2->cross_force_compensation;
          ((PDS23_Rx*)output)->Torque_collision_level_2=0;
          ((PDS23_Rx*)output)->Motor_control_2=0x0004;
          ((PDS23_Rx*)output)->Motor_torque_2=0;
          //Always stay in motion state STOP
          if(motion_state2!=MotionState::STOP) {
            setMotionState2(MotionState::STOP);
          }
          feedMotionWatchdog2();
        }
      }
    }
  }

  //Write the new motor_control_counter
  output->Motor_control_1|=(((USHORT)motor_control_counter)<<11);
  if(pds23) {
    ((PDS23_Rx*)output)->Motor_control_2|=(((USHORT)motor_control_counter)<<11);
  }
  motor_control_counter=(motor_control_counter+1)&0x0F;

  //Finally, generate CRC over the data to transmit
  generateCrc();
}

bool KsoeSlave::doCrc(bool generate, KsoePacket* safe_data, USHORT sequence_number) {
  USHORT initCrc;
  USHORT crc;
  USHORT blockNumber;
  BYTE bufferCrc[10];
  BYTE command;
  USHORT connectionID;

  if(safe_data==NULL) {
    return false;
  }
  command=safe_data->Command;
  connectionID=safe_data->Connection_ID;
  initCrc=KsoeSlave::crcTable[LOBYTE(connectionID)];
  initCrc=(initCrc<<8)^KsoeSlave::crcTable[HIBYTE(initCrc)^HIBYTE(connectionID)];
  initCrc=(initCrc<<8)^KsoeSlave::crcTable[HIBYTE(initCrc)^command];
  initCrc=(initCrc<<8)^KsoeSlave::crcTable[HIBYTE(initCrc)^LOBYTE(sequence_number)];
  initCrc=(initCrc<<8)^KsoeSlave::crcTable[HIBYTE(initCrc)^HIBYTE(sequence_number)];

  for(blockNumber=0;blockNumber<5;blockNumber++) {
    USHORT crc_blockNumber=initCrc;
    crc_blockNumber=(crc_blockNumber<<8)^KsoeSlave::crcTable[HIBYTE(crc_blockNumber)^LOBYTE(blockNumber)];
    crc_blockNumber=(crc_blockNumber<<8)^KsoeSlave::crcTable[HIBYTE(crc_blockNumber)^HIBYTE(blockNumber)];

    unsigned char* ptr=(((unsigned char*)&(safe_data->SafeData0))+8*blockNumber);
    bufferCrc[0]=*(ptr);
    bufferCrc[1]=*(ptr+1);
    bufferCrc[2]=*(ptr+2);
    bufferCrc[3]=*(ptr+3);
    bufferCrc[4]=*(ptr);
    bufferCrc[5]=*(ptr+1);
    bufferCrc[6]=*(ptr+2);
    bufferCrc[7]=*(ptr+3);
    bufferCrc[8]=*(ptr+4);
    bufferCrc[9]=*(ptr+5);

    crc=0;
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[0]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[1]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[2]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[3]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[4]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[5]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[6]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[7]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[8]];
    crc=(crc<<8)^KsoeSlave::crcTable[HIBYTE(crc)^bufferCrc[9]];
    crc^=crc_blockNumber;

    if(generate) {
      *((USHORT*)(ptr+6))=crc;
    }
    else {
      if(crc!=*(USHORT*)((ptr+6))) {
        return false;
      }
    }
  }
  return true;
}

void KsoeSlave::generateCrc() {
  doCrc(true,(KsoePacket*)output_buffer,sequence_number_slave);
}

bool KsoeSlave::checkCrc() {
  //Check with the current and previous sequence number.
  //Additionally, check with the initial sequence number. This is necessary for the transition
  //from the initial sequence number to the starting sequence number.
  return doCrc(false,(KsoePacket*)input_buffer,sequence_number_master) ||
    doCrc(false,(KsoePacket*)input_buffer,previousSequenceNumber(sequence_number_master)) ||
    doCrc(false, (KsoePacket*)input_buffer, KSOESLAVE_SEQUENCE_NUMBER_INITIAL);
}

KsoeSlaveError KsoeSlave::getLastError() {
  return last_error;
}

KsoeSlaveError KsoeSlave::getMotionError() {
  return motion_error;
}

KsoeSlaveError KsoeSlave::getSensorError() {
  return sensor_error;
}

KsoeSlaveWarning KsoeSlave::getMotionWarning() {
  return motion_warning;
}

KsoeSlaveWarning KsoeSlave::getSensorWarning() {
  return sensor_warning;
}

void KsoeSlave::setLastError(KsoeSlaveError error) {
  //If there was an error, immediately proceed to the reset state. This clears the
  //output buffer and issues the reset command to the slave.
  trace->Log(tlInfo, "%2d KsoeSlave::setLastError(): %s (%d) -> %s (%d)", connection_id, toString(last_error), (int)last_error, toString(error), (int)error);
  if(error!=KsoeSlaveError::NONE) {
    reset();
  }
  last_error=error;
}

int KsoeSlave::getConnectionID() {
  return connection_id;
}

bool KsoeSlave::canEnableMotion() {
  bool enable=true;
  if(last_error!=KsoeSlaveError::NONE) {
    trace->Log(tlError,"%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to last error %s (%d)",connection_id,toString(last_error),(int)last_error);
    enable=false;
  }
  else if(motion_error!=KsoeSlaveError::NONE) {
    trace->Log(tlError, "%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to motion error %s (%d)", connection_id, toString(motion_error), (int)motion_error);
    enable=false;
  }
  else if(motion_warning!=KsoeSlaveWarning::NONE) {
    trace->Log(tlError, "%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to motion warning %s (%d)", connection_id, toString(motion_warning), (int)motion_warning);
    enable=false;
  }
  else if(sensor_error!=KsoeSlaveError::NONE) {
    trace->Log(tlError, "%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to sensor warning %s (%d)", connection_id, toString(sensor_error), (int)sensor_error);
    enable=false;
  }
  else if(sensor_warning!=KsoeSlaveWarning::NONE) {
    trace->Log(tlError, "%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to sensor warning %s (%d)", connection_id, toString(sensor_warning), (int)sensor_warning);
    enable=false;
  }
  else if(state!=KsoeState::PROCESS_DATA) {
    trace->Log(tlError,"%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to slave state %s (%d)",connection_id,toString(state),(int)state);
    enable=false;
  }
  else if(motion_state1!=MotionState::STOP) {
    trace->Log(tlError,"%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to motion state1 %s (%d)",connection_id,toString(motion_state1),(int)motion_state1);
    enable=false;
  }
  else if(motion_state2!=MotionState::STOP) {
    trace->Log(tlError, "%2d KsoeSlave::canEnableMotion(): Cannot enable motion due to motion state2 %s (%d)", connection_id, toString(motion_state2), (int)motion_state2);
    enable=false;
  }
  return enable;
}

bool KsoeSlave::isMotionEnabled() {
  return motion_state_target==MotionState::MOTION;
}

bool KsoeSlave::enableMotion() {
  bool success=false;
  if(canEnableMotion()) {
    setMotionStateTarget(MotionState::MOTION);
    success=true;
  }
  return success;
}

void KsoeSlave::disableMotion() {
  setMotionStateTarget(MotionState::STOP);
}

double KsoeSlave::torque2current(const Axis *axis, double torque) {
  double p, q, current, nominal_torque;
  double temperature=motor_temperature;
  if(isnan_(torque)||!isfinite_(torque)) {
    current=0.0;
  }
  else {
    nominal_torque=AXIS_CURRENT_TO_TORQUE(axis, axis->nominal_current, temperature);
    if(fabs_(torque)>nominal_torque) {
      torque=nominal_torque*sgn_(torque);
    }
    p=axis->a1/axis->a3;
    q=-torque/(1+axis->b1*(temperature-axis->T_ref))/axis->a3;
    current=2.0*sqrt_(-p/3.0)*cos_(1/3.0*acos_(3.0*q/(2.0*p)*sqrt_(-3.0/p))-2.0*PI/3.0);
    if(fabs_(current)>axis->nominal_current) {
      current=axis->nominal_current*sgn_(current);
    }
  }
  return current;
}

double KsoeSlave::current2torque(const Axis *axis, double current) {
  double torque, nominal_torque;
  double temperature=motor_temperature;
  if(fabs_(current)>axis->nominal_current) {
    current=axis->nominal_current*sgn_(current);
  }
  torque=AXIS_CURRENT_TO_TORQUE(axis,current,temperature);
  nominal_torque=AXIS_CURRENT_TO_TORQUE(axis,axis->nominal_current,temperature);
  if(fabs_(torque)>nominal_torque) {
    torque=nominal_torque*sgn_(torque);
  }
  return torque;
}

bool KsoeSlave::hasValidInput() {
  return ((PDS1_Tx*)input_buffer)->Command!=(unsigned char)KsoeState::NONE;
}

void KsoeSlave::setMotorTemperature(USHORT motor_temperature) {
  //Allow temperatures from 0 .. 60 °C
  if(motor_temperature>=273 && motor_temperature<333) {
    this->motor_temperature=motor_temperature;
  }
  else {
    trace->Log(tlError, "%2d KsoeSlave::setMotorTemperature(): Invalid temperature %d K set.", connection_id, motor_temperature);
    setLastError(KsoeSlaveError::INVALID_TEMPERATURE);
  }
}

void KsoeSlave::performSoftStop(AxisSensor *input1, AxisSensor *input2, AxisControl *output1, AxisControl *output2, DWORD dc_time_L) {
  if(output1!=NULL) {
    if(output1->motor_enable) {
      //If the motor is enabled by the outer control, but was stopped by the soft stop
      //feature, the motor_enabled signal is overridden. This prevents, that the axis
      //can be enabled again by "motion_state_target".
      if(motion_state1==MotionState::STOP) {
        output1->motor_enable=false;
      }
      //Check if velocity is within the tolerance band and stop this axis
      else if(fabs_(input1->velocity_filtered)<KSOESLAVE_SOFT_STOP_VELOCITY_TOLERANCE) {
        if(motion_state1==MotionState::MOTION) {
          setMotionState1(MotionState::DISENGAGING_MOTION);
          trace->Log(tlInfo, "%2d KsoeSlave::performSoftStop(): Disabling motion on axis 1.", connection_id);
        }
      }
      else {
        //motor_torque already contains the gravitational torque. Additionally apply
        //a P velocity controller.
        output1->motor_torque+= -axis1->velocity_controller_p*input1->velocity_filtered;
      }
    }
    else {
      output1->motor_torque=0;
    }
  }
  if(output2!=NULL) {
    if(output2->motor_enable) {
      //If the motor is enabled by the outer control, but was stopped by the soft stop
      //feature, the motor_enabled signal is overridden. This prevents, that the axis
      //can be enabled again by "motion_state_target".
      if(motion_state2==MotionState::STOP) {
        output2->motor_enable=false;
      }
      //Check if velocity is within the tolerance band and stop this axis
      else if(fabs_(input2->velocity_filtered)<KSOESLAVE_SOFT_STOP_VELOCITY_TOLERANCE) {
        if(motion_state2==MotionState::MOTION) {
          setMotionState2(MotionState::DISENGAGING_MOTION);
          trace->Log(tlInfo, "%2d KsoeSlave::performSoftStop(): Disabling motion on axis 2.", connection_id);
        }
      }
      else {
        //motor_torque already contains the gravitational torque. Additionally apply
        //a P velocity controller.
        output2->motor_torque+= -axis2->velocity_controller_p*input2->velocity_filtered;
      }
    }
    else {
      output2->motor_torque=0;
    }
  }
  //Disable motion on slave, if both axes are in motor-stop state
  statemachineWriteControlGenerateCrc(output1, output2, dc_time_L);
}

KsoeState KsoeSlave::getState() {
  return state;
}
