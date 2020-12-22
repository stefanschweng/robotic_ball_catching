  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controller_ballcatcher_inv_kin_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.optitrack_data
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.param_robot
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.positions
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.estimator_init_struct
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.param_controller
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.timing
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.filter_tau_p_slow_T_1
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_P.filter_tau_slow_T_1
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_inv_kin_P.filter_theta_p_slow_T_1
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 14;
	
	  ;% controller_ballcatcher_inv_kin_P.filter_theta_slow_T_1
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 21;
	
	  ;% controller_ballcatcher_inv_kin_P.height_of_catch
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 28;
	
	  ;% controller_ballcatcher_inv_kin_P.sensor_torque_offset
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 29;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant21_Value
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 36;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant19_Value
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 37;
	
	  ;% controller_ballcatcher_inv_kin_P.pd_Y0
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 38;
	
	  ;% controller_ballcatcher_inv_kin_P.pd_p_Y0
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 39;
	
	  ;% controller_ballcatcher_inv_kin_P.t_catch_pred_Y0
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 40;
	
	  ;% controller_ballcatcher_inv_kin_P.use_pred_Y0
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 41;
	
	  ;% controller_ballcatcher_inv_kin_P.pred_update_Y0
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 42;
	
	  ;% controller_ballcatcher_inv_kin_P.Throw_Constant_Value
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 43;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant25_Value
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 44;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant26_Value
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 45;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant30_Value
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 46;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant27_Value
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 47;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant28_Value
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 48;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant29_Value
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 49;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant1_Value
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 50;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant17_Value
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 51;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant_Value
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 52;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant4_Value
	  section.data(24).logicalSrcIdx = 29;
	  section.data(24).dtTransOffset = 53;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant2_Value
	  section.data(25).logicalSrcIdx = 30;
	  section.data(25).dtTransOffset = 56;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant3_Value
	  section.data(26).logicalSrcIdx = 31;
	  section.data(26).dtTransOffset = 57;
	
	  ;% controller_ballcatcher_inv_kin_P.Constant18_Value
	  section.data(27).logicalSrcIdx = 32;
	  section.data(27).dtTransOffset = 58;
	
	  ;% controller_ballcatcher_inv_kin_P.MotionEnableValue_Value
	  section.data(28).logicalSrcIdx = 33;
	  section.data(28).dtTransOffset = 59;
	
	  ;% controller_ballcatcher_inv_kin_P.MotionDisableValue_Value
	  section.data(29).logicalSrcIdx = 34;
	  section.data(29).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.RigidBodyControllerSelector_Value
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_P.ManualSwitch7_CurrentSetting
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controller_ballcatcher_inv_kin_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.robot_model_f
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.BusConversion_InsertedFor_BallPointSelection_at
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.t_in
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_B.t_in_i
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_inv_kin_B.ManualSwitch2
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_ballcatcher_inv_kin_B.ManualSwitch7
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 5;
	
	  ;% controller_ballcatcher_inv_kin_B.Constant
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 6;
	
	  ;% controller_ballcatcher_inv_kin_B.Constant4
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o1
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 10;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o2
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 11;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o3
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 14;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o4
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 17;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o5
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 19;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o6
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 20;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o7
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 21;
	
	  ;% controller_ballcatcher_inv_kin_B.Chart2_sfcn_o8
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 22;
	
	  ;% controller_ballcatcher_inv_kin_B.Switch
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 23;
	
	  ;% controller_ballcatcher_inv_kin_B.Switch1
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 26;
	
	  ;% controller_ballcatcher_inv_kin_B.Switch3
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 29;
	
	  ;% controller_ballcatcher_inv_kin_B.Switch2
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 30;
	
	  ;% controller_ballcatcher_inv_kin_B.Switch4
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 32;
	
	  ;% controller_ballcatcher_inv_kin_B.Subtract
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 33;
	
	  ;% controller_ballcatcher_inv_kin_B.pd
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 40;
	
	  ;% controller_ballcatcher_inv_kin_B.pd_p
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 43;
	
	  ;% controller_ballcatcher_inv_kin_B.use_pred
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 46;
	
	  ;% controller_ballcatcher_inv_kin_B.t_catch_predict
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 47;
	
	  ;% controller_ballcatcher_inv_kin_B.prediction_update
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 49;
	
	  ;% controller_ballcatcher_inv_kin_B.q_d
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 50;
	
	  ;% controller_ballcatcher_inv_kin_B.update_index
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 57;
	
	  ;% controller_ballcatcher_inv_kin_B.theta_slow
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 58;
	
	  ;% controller_ballcatcher_inv_kin_B.theta_p_slow
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 65;
	
	  ;% controller_ballcatcher_inv_kin_B.tau_slow
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 72;
	
	  ;% controller_ballcatcher_inv_kin_B.tau_p_slow
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 79;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.x
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_B.y
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_inv_kin_B.z
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_ballcatcher_inv_kin_B.Tf
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.x_out
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_B.y_out
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_inv_kin_B.z_out
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_B.OR
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_B.y_d
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 6;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controller_ballcatcher_inv_kin_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.estimations_last
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.use_pred_p
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_DW.t_catch_predict_p
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_inv_kin_DW.t_zd
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 3;
	
	  ;% controller_ballcatcher_inv_kin_DW.i
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 4;
	
	  ;% controller_ballcatcher_inv_kin_DW.pd__
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 5;
	
	  ;% controller_ballcatcher_inv_kin_DW.pd_p__
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 8;
	
	  ;% controller_ballcatcher_inv_kin_DW.t_in_last
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 11;
	
	  ;% controller_ballcatcher_inv_kin_DW.t_cnt
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 12;
	
	  ;% controller_ballcatcher_inv_kin_DW.px_est_last
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 13;
	
	  ;% controller_ballcatcher_inv_kin_DW.Px_last
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 15;
	
	  ;% controller_ballcatcher_inv_kin_DW.py_est_last
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 19;
	
	  ;% controller_ballcatcher_inv_kin_DW.Py_last
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 21;
	
	  ;% controller_ballcatcher_inv_kin_DW.pz_est_last
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 25;
	
	  ;% controller_ballcatcher_inv_kin_DW.Pz_last
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 27;
	
	  ;% controller_ballcatcher_inv_kin_DW.point_in_last
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 31;
	
	  ;% controller_ballcatcher_inv_kin_DW.qf
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 34;
	
	  ;% controller_ballcatcher_inv_kin_DW.traj_update_index
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 41;
	
	  ;% controller_ballcatcher_inv_kin_DW.x
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 42;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_d
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 49;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_e
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 56;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_d3
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 63;
	
	  ;% controller_ballcatcher_inv_kin_DW.throw_pers
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 70;
	
	  ;% controller_ballcatcher_inv_kin_DW.i_g
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 71;
	
	  ;% controller_ballcatcher_inv_kin_DW.Tf_
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 72;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.Chart2_sfcn_DWORK0
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.TriggeredSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.Chart2_sfcn_DWORK1
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_DW.Chart2_sfcn_DWORK2
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_inv_kin_DW.t_catch_predict_p_not_empty
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_inv_kin_DW.blocked
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_inv_kin_DW.px_est_last_not_empty
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_ballcatcher_inv_kin_DW.qf_not_empty
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_not_empty
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_not_empty_d
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_not_empty_a
	  section.data(7).logicalSrcIdx = 35;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_ballcatcher_inv_kin_DW.x_not_empty_g
	  section.data(8).logicalSrcIdx = 36;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2361197604;
  targMap.checksum1 = 68105103;
  targMap.checksum2 = 1035230511;
  targMap.checksum3 = 1199079827;

