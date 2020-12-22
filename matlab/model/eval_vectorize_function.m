% Create vectorize-function 
clc
% state
syms q1 q2 q3 q4 q5 q6 q7 'real'
syms qd1 qd2 qd3 qd4 qd5 qd6 qd7  'real'
syms qdd1 qdd2 qdd3 qdd4 qdd5 qdd6 qdd7 'real'
% control input


q = [q1, q2, q3, q4, q5, q6, q7]';
qd = [qd1, qd2, qd3, qd4, qd5, qd6, qd7]';
qdd = [qdd1,qdd2,qdd3,qdd4,qdd5,qdd6,qd7]';

tau_vectorize = iiwa_reduced_tau_matrix_params_sym(q,qd,qdd);

%x_dot = [sx,sy];
%% export to Matlab function
disp('[Info]: Function generating  <dynamics part>...')

matlabFunction(tau_vectorize, 'file','autogen_tau_vector_params.m',...
               'Vars',{[q;qd],qdd},'Optimize',false,...
               'Comments',' in1 = zt; in2 = ut');


