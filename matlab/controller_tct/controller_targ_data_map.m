  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (controller_P)
    ;%
      section.nData     = 49;
      section.data(49)  = dumData; %prealloc
      
	  ;% controller_P.filter_tau_T_1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_P.filter_tau_p_T_1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7;
	
	  ;% controller_P.filter_tau_p_slow_T_1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 14;
	
	  ;% controller_P.filter_tau_slow_T_1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 21;
	
	  ;% controller_P.filter_theta_p_T_1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% controller_P.filter_theta_p_slow_T_1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 35;
	
	  ;% controller_P.filter_theta_slow_T_1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 42;
	
	  ;% controller_P.sensor_torque_offset
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 49;
	
	  ;% controller_P.tau_fm_hat_Y0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 56;
	
	  ;% controller_P.L_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 57;
	
	  ;% controller_P.tau_c_plus_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 64;
	
	  ;% controller_P.tau_c_minus_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 71;
	
	  ;% controller_P.E_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 78;
	
	  ;% controller_P.tau_v_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 85;
	
	  ;% controller_P.use_theta_p_hat_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 92;
	
	  ;% controller_P.use_q_p_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 93;
	
	  ;% controller_P.subtract_model_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 94;
	
	  ;% controller_P.Constant_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 95;
	
	  ;% controller_P.tau_d_gravcomp_q_Y0
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 102;
	
	  ;% controller_P.GravitationcompensationK_D_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 103;
	
	  ;% controller_P.slope_factor_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 104;
	
	  ;% controller_P.tau_d_joint_ea_Y0
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 105;
	
	  ;% controller_P.JointbasedEALinearizationK_I_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 106;
	
	  ;% controller_P.JointbasedEALinearizationK_0_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 107;
	
	  ;% controller_P.JointbasedEALinearizationK_1_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 108;
	
	  ;% controller_P.Constant_Value_h
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 109;
	
	  ;% controller_P.Constant6_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 116;
	
	  ;% controller_P.Constant2_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 117;
	
	  ;% controller_P.Constant16_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 118;
	
	  ;% controller_P.Constant15_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 119;
	
	  ;% controller_P.Constant14_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 120;
	
	  ;% controller_P.Constant13_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 121;
	
	  ;% controller_P.Constant12_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 122;
	
	  ;% controller_P.Gain1_Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 123;
	
	  ;% controller_P.Constant5_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 124;
	
	  ;% controller_P.Constant11_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 125;
	
	  ;% controller_P.Constant17_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 126;
	
	  ;% controller_P.T_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 127;
	
	  ;% controller_P.Constant_Value_hg
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 128;
	
	  ;% controller_P.FictionCompensationEnabled_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 135;
	
	  ;% controller_P.MotionEnableValue_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 136;
	
	  ;% controller_P.MotionDisableValue_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 137;
	
	  ;% controller_P.Constant22_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 138;
	
	  ;% controller_P.Constant4_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 139;
	
	  ;% controller_P.Constant7_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 140;
	
	  ;% controller_P.Constant8_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 141;
	
	  ;% controller_P.Constant9_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 142;
	
	  ;% controller_P.Constant10_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 143;
	
	  ;% controller_P.Constant23_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 144;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_P.RigidBodyControllerSelector_Value
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_P.JointTargetPositionSelector_Value
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_P.ManualSwitch4_CurrentSetting
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 4;
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
    ;% Auto data (controller_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_B.robot_model_g
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% controller_B.Subtract
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_B.MultiportSwitch
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 7;
	
	  ;% controller_B.q_d
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 14;
	
	  ;% controller_B.Gain1
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 35;
	
	  ;% controller_B.tau_singularperturbation
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 42;
	
	  ;% controller_B.theta_slow
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 49;
	
	  ;% controller_B.theta_p_slow
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 56;
	
	  ;% controller_B.theta_p
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 63;
	
	  ;% controller_B.tau_slow
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 70;
	
	  ;% controller_B.tau_p_slow
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 77;
	
	  ;% controller_B.tau_p
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 84;
	
	  ;% controller_B.tau
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 91;
	
	  ;% controller_B.tau_d
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 98;
	
	  ;% controller_B.e
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 105;
	
	  ;% controller_B.e_p
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 112;
	
	  ;% controller_B.tau_d_m
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 119;
	
	  ;% controller_B.barrier
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 126;
	
	  ;% controller_B.output
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 133;
	
	  ;% controller_B.Add2
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 140;
	
	  ;% controller_B.tau_fm_hat
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 147;
	
	  ;% controller_B.tau_f_model
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controller_B.TmpSignalConversionAtSFunctionInport4
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_B.ManualSwitch4
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 3;
	
	  ;% controller_B.TmpSignalConversionAtSFunctionInport7
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% controller_B.enable1
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_B.enable2
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_B.enable3
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_B.enable4
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_B.enable5
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_B.enable6
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_B.enable7
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_B.enable8
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_B.enable9
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_B.enable10
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 4;
    
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
    ;% Auto data (controller_DW)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% controller_DW.last_start
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_DW.last_stop
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_DW.started
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_DW.q__0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_DW.q__T
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% controller_DW.t
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 17;
	
	  ;% controller_DW.T
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% controller_DW.x
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% controller_DW.x_l
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% controller_DW.x_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% controller_DW.x_e
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 40;
	
	  ;% controller_DW.x_lu
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 47;
	
	  ;% controller_DW.x_c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 54;
	
	  ;% controller_DW.x_ly
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 61;
	
	  ;% controller_DW.last_application_button
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 68;
	
	  ;% controller_DW.e_I
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 69;
	
	  ;% controller_DW.x_theta_p_hat
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 76;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controller_DW.JointbasedEALinearization_SubsysRanBC
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_DW.Gravitationcompensationqbased_SubsysRanBC
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_DW.FrictionCompensation_SubsysRanBC
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% controller_DW.last_start_not_empty
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_DW.last_stop_not_empty
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_DW.q__0_not_empty
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_DW.q__T_not_empty
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_DW.T_not_empty
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_DW.x_not_empty
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_DW.x_not_empty_j
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_DW.x_not_empty_l
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_DW.x_not_empty_p
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_DW.x_not_empty_i
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_DW.x_not_empty_p2
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_DW.x_not_empty_h
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_DW.last_application_button_not_empty
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_DW.e_I_not_empty
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_DW.JointbasedEALinearization_MODE
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_DW.Gravitationcompensationqbased_MODE
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 3854984600;
  targMap.checksum1 = 2241605594;
  targMap.checksum2 = 2804006287;
  targMap.checksum3 = 3241428159;

