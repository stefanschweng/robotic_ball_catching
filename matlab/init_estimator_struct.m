height_of_catch = 0.8;

% estimator struct
estimator_init_struct = struct();

estimator_init_struct.alpha0 = 1e5;
estimator_init_struct.px_est_last = [optitrack_data.x(1);0];%[1.7391;-1.8621];%zeros(2,1);
estimator_init_struct.Px_last = estimator_init_struct.alpha0*eye(2);

estimator_init_struct.py_est_last = [optitrack_data.y(1);0];%[1.1293;-1.9438];%zeros(2,1);
estimator_init_struct.Py_last = estimator_init_struct.alpha0*eye(2);

estimator_init_struct.pz_est_last = [optitrack_data.z(1);0];%[1.4722;2.3980];%zeros(2,1);
estimator_init_struct.Pz_last = estimator_init_struct.alpha0*eye(2);

% "Vergessens-Faktor"
estimator_init_struct.q = 1; % 0 < q < 1 (should be close to 1)

% time when the robot starts to move
%estimator_init_struct.t_move_start = 50*timing.T_optitrack;

% generate random seeds for white noise blocks
estimator_init_struct.seed1 = rand() * 23341;
estimator_init_struct.seed2 = rand() * 36854;
estimator_init_struct.seed3 = rand() * 84256;
