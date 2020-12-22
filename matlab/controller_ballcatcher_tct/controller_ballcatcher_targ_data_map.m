  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (controller_ballcatcher_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_P.param_robot
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_P.timing
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_P.filter_tau_T_1
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_P.filter_tau_p_T_1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_P.filter_tau_p_slow_T_1
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 14;
	
	  ;% controller_ballcatcher_P.filter_tau_slow_T_1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 21;
	
	  ;% controller_ballcatcher_P.filter_theta_p_T_1
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 28;
	
	  ;% controller_ballcatcher_P.filter_theta_p_slow_T_1
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 35;
	
	  ;% controller_ballcatcher_P.filter_theta_slow_T_1
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 42;
	
	  ;% controller_ballcatcher_P.sensor_torque_offset
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 49;
	
	  ;% controller_ballcatcher_P.tau_fm_hat_Y0
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 56;
	
	  ;% controller_ballcatcher_P.L_Value
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 57;
	
	  ;% controller_ballcatcher_P.use_theta_p_hat_Value
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 64;
	
	  ;% controller_ballcatcher_P.use_q_p_Value
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 65;
	
	  ;% controller_ballcatcher_P.subtract_model_Value
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 66;
	
	  ;% controller_ballcatcher_P.tau_c_plus_Value
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 67;
	
	  ;% controller_ballcatcher_P.tau_c_minus_Value
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 74;
	
	  ;% controller_ballcatcher_P.E_Value
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 81;
	
	  ;% controller_ballcatcher_P.tau_v_Value
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 88;
	
	  ;% controller_ballcatcher_P.Constant_Value
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 95;
	
	  ;% controller_ballcatcher_P.tau_d_gravcomp_q_Y0
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 102;
	
	  ;% controller_ballcatcher_P.GravitationcompensationK_D_Value
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 103;
	
	  ;% controller_ballcatcher_P.slope_factor_Value
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 104;
	
	  ;% controller_ballcatcher_P.tau_d_joint_ea_Y0
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 105;
	
	  ;% controller_ballcatcher_P.JointbasedEALinearizationK_I_Value
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 106;
	
	  ;% controller_ballcatcher_P.JointbasedEALinearizationK_0_Value
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 107;
	
	  ;% controller_ballcatcher_P.JointbasedEALinearizationK_1_Value
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 108;
	
	  ;% controller_ballcatcher_P.UnitDelay_InitialCondition
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 109;
	
	  ;% controller_ballcatcher_P.Constant_Value_f
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 110;
	
	  ;% controller_ballcatcher_P.Constant_Value_d
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 111;
	
	  ;% controller_ballcatcher_P.FictionCompensationEnabled_Value
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 118;
	
	  ;% controller_ballcatcher_P.Constant22_Value
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 119;
	
	  ;% controller_ballcatcher_P.Constant4_Value
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 120;
	
	  ;% controller_ballcatcher_P.Constant7_Value
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 121;
	
	  ;% controller_ballcatcher_P.Constant8_Value
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 122;
	
	  ;% controller_ballcatcher_P.Constant9_Value
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 123;
	
	  ;% controller_ballcatcher_P.Constant10_Value
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 124;
	
	  ;% controller_ballcatcher_P.Constant23_Value
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 125;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_P.UnitDelay1_InitialCondition
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_P.ManualSwitch4_CurrentSetting
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Auto data (controller_ballcatcher_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_B.robot_model_f
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_B.Subtract
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_B.q
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_B.q_p
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 14;
	
	  ;% controller_ballcatcher_B.q_pp
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 21;
	
	  ;% controller_ballcatcher_B.q_d
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 28;
	
	  ;% controller_ballcatcher_B.tau_singularperturbation
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 49;
	
	  ;% controller_ballcatcher_B.theta_slow
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 56;
	
	  ;% controller_ballcatcher_B.theta_p_slow
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 63;
	
	  ;% controller_ballcatcher_B.theta_p
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 70;
	
	  ;% controller_ballcatcher_B.tau_slow
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 77;
	
	  ;% controller_ballcatcher_B.tau_p_slow
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 84;
	
	  ;% controller_ballcatcher_B.tau_p
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 91;
	
	  ;% controller_ballcatcher_B.tau
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 98;
	
	  ;% controller_ballcatcher_B.tau_d
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 105;
	
	  ;% controller_ballcatcher_B.e
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 112;
	
	  ;% controller_ballcatcher_B.e_p
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 119;
	
	  ;% controller_ballcatcher_B.tau_d_d
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 126;
	
	  ;% controller_ballcatcher_B.barrier
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 133;
	
	  ;% controller_ballcatcher_B.output
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 140;
	
	  ;% controller_ballcatcher_B.Add2
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 147;
	
	  ;% controller_ballcatcher_B.tau_fm_hat
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 154;
	
	  ;% controller_ballcatcher_B.tau_f_model
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 161;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_B.UnitDelay
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_B.error
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_B.enable1
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_B.enable2
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_ballcatcher_B.enable3
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_ballcatcher_B.enable4
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_ballcatcher_B.enable5
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_ballcatcher_B.enable6
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_ballcatcher_B.enable7
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_B.enable8
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_ballcatcher_B.enable9
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_ballcatcher_B.enable10
	  section.data(11).logicalSrcIdx = 36;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_ballcatcher_B.UnitDelay1
	  section.data(12).logicalSrcIdx = 37;
	  section.data(12).dtTransOffset = 11;
	
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
    nTotSects     = 4;
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
    ;% Auto data (controller_ballcatcher_DW)
    ;%
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_DW.q0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_DW.q0_p
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% controller_ballcatcher_DW.q0_pp
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% controller_ballcatcher_DW.qf
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 22;
	
	  ;% controller_ballcatcher_DW.T_0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% controller_ballcatcher_DW.T_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% controller_ballcatcher_DW.q_
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% controller_ballcatcher_DW.q_p_
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 38;
	
	  ;% controller_ballcatcher_DW.q_pp_
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 45;
	
	  ;% controller_ballcatcher_DW.t_
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 52;
	
	  ;% controller_ballcatcher_DW.traj_update_index_last
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 53;
	
	  ;% controller_ballcatcher_DW.x
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 54;
	
	  ;% controller_ballcatcher_DW.x_d
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 61;
	
	  ;% controller_ballcatcher_DW.x_b
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 68;
	
	  ;% controller_ballcatcher_DW.x_e
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 75;
	
	  ;% controller_ballcatcher_DW.x_d3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 82;
	
	  ;% controller_ballcatcher_DW.x_bm
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 89;
	
	  ;% controller_ballcatcher_DW.x_j
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 96;
	
	  ;% controller_ballcatcher_DW.last_application_button
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 103;
	
	  ;% controller_ballcatcher_DW.e_I
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 104;
	
	  ;% controller_ballcatcher_DW.x_theta_p_hat
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 111;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_DW.JointbasedEALinearization_SubsysRanBC
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_DW.Gravitationcompensationqbased_SubsysRanBC
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_DW.FrictionCompensation_SubsysRanBC
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% controller_ballcatcher_DW.q0_not_empty
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_ballcatcher_DW.started
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_ballcatcher_DW.error_
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_ballcatcher_DW.x_not_empty
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_ballcatcher_DW.x_not_empty_d
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_ballcatcher_DW.x_not_empty_m
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_ballcatcher_DW.x_not_empty_a
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_ballcatcher_DW.x_not_empty_g
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_ballcatcher_DW.x_not_empty_h
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_ballcatcher_DW.x_not_empty_e
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_ballcatcher_DW.last_application_button_not_empty
	  section.data(11).logicalSrcIdx = 36;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_ballcatcher_DW.e_I_not_empty
	  section.data(12).logicalSrcIdx = 37;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_ballcatcher_DW.JointbasedEALinearization_MODE
	  section.data(13).logicalSrcIdx = 38;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_ballcatcher_DW.Gravitationcompensationqbased_MODE
	  section.data(14).logicalSrcIdx = 39;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 1964384509;
  targMap.checksum1 = 2064986566;
  targMap.checksum2 = 3643458704;
  targMap.checksum3 = 72446283;

