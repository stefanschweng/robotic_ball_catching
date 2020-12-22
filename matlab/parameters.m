%clear;

addpath model;

load bus;

% OptiTrack buses
load Marker_bus;
load RigidBody_bus;

% Radius around the robot wherein the ball data gets processed
ball_processing_radius = 5;

% Timing
timing = struct();
timing.T_optitrack = 4e-3;
timing.T_iiwa = 125e-6;
timing.T_optiTask = 50e-6;
timing.cycle_time_ratio = timing.T_optitrack/timing.T_optiTask;

%Robot parameters
param_robot=struct();
%Robot base
param_robot.hanging=false;
if(param_robot.hanging)
  param_robot.R_0=[1,0,0;0,-1,0;0,0,-1];
  param_robot.p_0=[0;0;1.9];
else
  param_robot.R_0=eye(3);
  param_robot.p_0=[0;0;0];
end
%Number of links
param_robot.n=7;
%Gravity
g=9.81;
if(param_robot.hanging)
  %Gravity: -9.81 (acting upwards with respect to the standing robot)
  param_robot.g=-g;
else
  param_robot.g=g;
end
%Friction
param_robot.beta=0;
%Link length
param_robot.l__0=0.1525;
param_robot.l__1=0.2075;
param_robot.l__2=0.2325;
param_robot.l__3=0.1875;
param_robot.l__4=0.2125;
param_robot.l__5=0.1875;
param_robot.l__6=0.0796;
param_robot.l__7=0.0724;
%Offsets for coordinate systems along world y-axis
param_robot.d__1=0.013;
param_robot.d__3=0.011;
param_robot.d__5=0.062;
%Link masses
param_robot.m__l1=6.495;
param_robot.m__l2=8.807;
param_robot.m__l3=2.8;
param_robot.m__l4=5.283;
param_robot.m__l5=1.889;
param_robot.m__l6=2.32;
param_robot.m__l7=0.863;
%Link center of gravity
param_robot.s__l1x=0;
param_robot.s__l1y=-0.01439;
param_robot.s__l1z=0.102503;
param_robot.s__l2x=-0.000012;
param_robot.s__l2y=-0.06472;
param_robot.s__l2z=0.017804;
param_robot.s__l3x=-0.000208;
param_robot.s__l3y=0.01601;
param_robot.s__l3z=0.087283;
param_robot.s__l4x=-0.000203;
param_robot.s__l4y=0.098639;
param_robot.s__l4z=0.022478;
param_robot.s__l5x=-0.000057;
param_robot.s__l5y=-0.014468;
param_robot.s__l5z=0.062938;
param_robot.s__l6x=-0.000363;
param_robot.s__l6y=-0.016982;
param_robot.s__l6z=0.042269;
param_robot.s__l7x=0.001904;
param_robot.s__l7y=-0.000093;
param_robot.s__l7z=0.018862;
%Link moments of inertia
param_robot.I__l1xx=0.0690761441316632;
param_robot.I__l1yy=0.0711085586914514;
param_robot.I__l1zz=0.0200625854402119;
param_robot.I__l2xx=0.0824701683534692;
param_robot.I__l2yy=0.0164110968055191;
param_robot.I__l2zz=0.0873510892661361;
param_robot.I__l3xx=0.0230152941318817;
param_robot.I__l3yy=0.0228661554143474;
param_robot.I__l3zz=0.0554482283748983;
param_robot.I__l4xx=0.0472789668341968;
param_robot.I__l4yy=0.00964726804146909;
param_robot.I__l4zz=0.0466529007761679;
param_robot.I__l5xx=0.0138359953358589;
param_robot.I__l5yy=0.0116859337751969;
param_robot.I__l5zz=0.00571863785412578;
param_robot.I__l6xx=0.00732758787216765;
param_robot.I__l6yy=0.00477633755783711;
param_robot.I__l6zz=0.00606797638550296;
param_robot.I__l7xx=0.000884;
param_robot.I__l7yy=0.000888;
param_robot.I__l7zz=0.001105;
%Gear ratios for each link
param_robot.n__1=160;
param_robot.n__2=160;
param_robot.n__3=160;
param_robot.n__4=160;
param_robot.n__5=100;
param_robot.n__6=160;
param_robot.n__7=160;
param_robot.N=diag([param_robot.n__1,param_robot.n__2,param_robot.n__3,param_robot.n__4,param_robot.n__5,param_robot.n__6,param_robot.n__7]);
%Rotor moments of inertia
%A__i is taken as TorqueOfInertia (M00i.xml). As a consequence, the rotor
%by itself has the same inertia around every axis.
%B__i is taken as the sum of TorqueOfInertia (M00i.xml) and
%ExtTorqueOfInertia (Ai.xml)
%Only the component B__i is multiplied by the gear ratio n__i^2, since the
%rotation of the rotor is amplified by n__i: theta__i=q__i*n__i and the
%inertia is therefor amplified by n__i^2. The other axes A__i are not
%amplified and therefore stay small.
param_robot.I__r1xx=0.000185;
param_robot.I__r1yy=param_robot.I__r1xx;
param_robot.I__r1zz=0.000185+0.000238166953125;
param_robot.I__r2xx=0.000185;
param_robot.I__r2yy=param_robot.I__r2xx;
param_robot.I__r2zz=0.000185+0.000238166953125;
param_robot.I__r3xx=0.000129;
param_robot.I__r3yy=param_robot.I__r3xx;
param_robot.I__r3zz=0.000129+6.20384375e-005;
param_robot.I__r4xx=0.000129;
param_robot.I__r4yy=param_robot.I__r4xx;
param_robot.I__r4zz=0.000129+6.20384375e-005;
param_robot.I__r5xx=7.5e-05;
param_robot.I__r5yy=param_robot.I__r5xx;
param_robot.I__r5zz=7.5e-05+7.20968e-005;
param_robot.I__r6xx=1.5e-05;
param_robot.I__r6yy=param_robot.I__r6xx;
param_robot.I__r6zz=1.5e-05+3.51125e-006;
param_robot.I__r7xx=1.5e-05;
param_robot.I__r7yy=param_robot.I__r7xx;
param_robot.I__r7zz=1.5e-05+3.51125e-006;
%Moments of inertia of the rotors
param_robot.B=diag([param_robot.n__1^2*param_robot.I__r1zz,...
    param_robot.n__2^2*param_robot.I__r2zz,...
    param_robot.n__3^2*param_robot.I__r3zz,...
    param_robot.n__4^2*param_robot.I__r4zz,...
    param_robot.n__5^2*param_robot.I__r5zz,...
    param_robot.n__6^2*param_robot.I__r6zz,...
    param_robot.n__7^2*param_robot.I__r7zz]);
%Joint stiffness from 181023_Stiffness Measurement
param_robot.K__1=60000;
param_robot.K__2=60000;
param_robot.K__3=40000;
param_robot.K__4=40000;
param_robot.K__5=40000;
param_robot.K__6=20000;
param_robot.K__7=20000;
param_robot.K=diag([param_robot.K__1,param_robot.K__2,param_robot.K__3,param_robot.K__4,param_robot.K__5,param_robot.K__6,param_robot.K__7]);
%Maximum joint torque
tau_max = [320.00,320.00,176.00,176.00,110.00,40.00,40.00];
saturation = 0.50;
param_robot.tau_max=diag(tau_max);
param_robot.tau_saturation_max=tau_max*saturation;
clear tau_max saturation;

% joint angle limits
param_robot.q_limit_upper=[170;120;170;120;170;120;175]*pi/180;
param_robot.q_limit_lower=-param_robot.q_limit_upper;

% joint velocities limits
param_robot.q_p_limit_upper=[85;85;100;75;130;135;135]*pi/180;
param_robot.q_p_limit_lower=-param_robot.q_p_limit_upper;

param_controller.g=g;
clear g;
param_controller.T_a=timing.T_iiwa;

param_controller.singular_perturbation=struct();
param_controller.singular_perturbation.K_tau=[4;4;4;5;3;2.5;2.5];
param_controller.singular_perturbation.D_tau=[0.015;0.015;0.015;0.02;0.01;0.01;0.01];

% homogeneous transf. for starting position
x__0 = eye(4);
x__0(4,4) = 0;
x__0(1:3,4) = positions.start;

param_initial_condition=struct();
[~,param_initial_condition.q__0]=inverse_kinematics_analytic(x__0,param_robot);
param_initial_condition.theta__0=param_initial_condition.q__0+param_robot.K\iiwa_gravitational_force(param_initial_condition.q__0,param_robot);
param_initial_condition.q__p_0=zeros(param_robot.n,1);
param_initial_condition.theta__p_0=zeros(param_robot.n,1);

param_visualization.retardation=1;

param_sensor=struct();
param_sensor.T_a=param_controller.T_a;

param_nullspace=struct();
param_nullspace.q_limit_upper=[170;120;170;120;170;120;175;90]*pi/180;
param_nullspace.q_limit_lower=-param_nullspace.q_limit_upper;
param_nullspace.q_limit_range=10*ones(param_robot.n+1,1)*pi/180;
param_nullspace.q_limit_slope=1*ones(param_robot.n+1,1);
param_nullspace.q_limit_gain=50*ones(param_robot.n+1,1);
param_nullspace.barrierfunction=true;

%% Filter settings
filter_tau_T_1=1./(2*pi*[400;400;400;400;500;1000;1000]);
filter_tau_p_T_1=filter_tau_T_1;
filter_theta_p_T_1=filter_tau_T_1;

%Slow filters for rigid body controllers
filter_tau_slow_T_1=1./(2*pi*[200;200;200;200;200;200;200]);
filter_tau_p_slow_T_1=filter_tau_slow_T_1;
filter_theta_slow_T_1=filter_tau_slow_T_1;
filter_theta_p_slow_T_1=filter_tau_slow_T_1;

%Torque sensor offsets, measured and identified by Bischof on 25.06.2018
sensor_torque_offset=[0.53;-0.095;-0.189;0.07;-0.058;0.0025;-0.12];

%Filter for the second derivative of the path parameter theta
filter_theta_pp_T_1=1/(2*pi*10);
filter_q_pp_T_1=filter_tau_T_1;

%% Attach load to the endeffector
param_load=struct();
switch 0
  case 1
    % Left shoe last UK 8.5 including adapter, center of mass with respect to
    % endeffector frame.
    param_load.m=1.476;
    param_load.s_x=0.03361;
    param_load.s_y=-0.00094;
    param_load.s_z=param_robot.l__7+0.10927;
  otherwise
    %No load
    param_load.m=0;
    param_load.s_x=0;
    param_load.s_y=0;
    param_load.s_z=0;
end
%Integrate the load into link 7
tmp=([param_robot.s__l7x;param_robot.s__l7y;param_robot.s__l7z]*param_robot.m__l7...
  +[param_load.s_x;param_load.s_y;param_load.s_z]*param_load.m)/(param_robot.m__l7+param_load.m);
param_robot.s__l7x=tmp(1);
param_robot.s__l7y=tmp(2);
param_robot.s__l7z=tmp(3);
param_robot.m__l7=param_robot.m__l7+param_load.m;
clear('tmp');
