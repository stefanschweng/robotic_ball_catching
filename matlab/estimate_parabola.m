function [estimations,prediction_update] = estimate_parabola(t_in,point_in,estimator_init_struct,init)

   g = 9.81;
   estimations = struct();
   prediction_update = 0;
   
   % RLS components
   persistent px_est_last Px_last py_est_last Py_last pz_est_last Pz_last estimations_last point_in_last;
   if (isempty(px_est_last) || init)
       px_est_last = [point_in(1);0];
       Px_last = estimator_init_struct.Px_last;
       
       py_est_last = [point_in(2);0];
       Py_last = estimator_init_struct.Py_last;
       
       pz_est_last = [point_in(3);0];
       Pz_last = estimator_init_struct.Pz_last;
       
       estimations_last = struct();
       estimations_last.x0_est = point_in(1);
       estimations_last.vx0_est = 0;
       estimations_last.y0_est = point_in(2);
       estimations_last.vy0_est = 0;
       estimations_last.z0_est = point_in(3);
       estimations_last.vz0_est = 0;
       
       point_in_last = zeros(3,1);
   end

   if (isequal(point_in,zeros(3,1)) || isequal(point_in,point_in_last))
       estimations = estimations_last;
   else
     % input coordinates
     x_in = point_in(1);
     y_in = point_in(2);
     z_in = point_in(3)+g/2*t_in^2; % compensate quadratic term, because it shall not be estimated

     % generate input data vectors
     f1 = @(x) 1;
     fx = @(x) x;

     s_i = [ f1(t_in);...
             fx(t_in) ];


     q = estimator_init_struct.q;
     % estimate x components
     kx_i = (Px_last*s_i)/(q + s_i'*Px_last*s_i);
     Px_i = (1/q)*(Px_last - kx_i*s_i'*Px_last);
     px_est = px_est_last + kx_i*(x_in - s_i'*px_est_last);

     estimations.x0_est = px_est(1);
     estimations.vx0_est = px_est(2);

     % estimate y components
     ky_i = (Py_last*s_i)/(q + s_i'*Py_last*s_i);
     Py_i = (1/q)*(Py_last - ky_i*s_i'*Py_last);
     py_est = py_est_last + ky_i*(y_in - s_i'*py_est_last);

     estimations.y0_est = py_est(1);
     estimations.vy0_est = py_est(2);

     % estimate z components
     kz_i = (Pz_last*s_i)/(q + s_i'*Pz_last*s_i);
     Pz_i = (1/q)*(Pz_last - kz_i*s_i'*Pz_last);
     pz_est = pz_est_last + kz_i*(z_in - s_i'*pz_est_last);

     estimations.z0_est = pz_est(1);
     estimations.vz0_est = pz_est(2);

     % set values for next iteration
     px_est_last = px_est;
     Px_last = Px_i;
     py_est_last = py_est;
     Py_last = Py_i;
     pz_est_last = pz_est;
     Pz_last = Pz_i;
     
     if estimations_last.x0_est ~= estimations.x0_est ||...
         estimations_last.y0_est ~= estimations.y0_est ||...
         estimations_last.z0_est ~= estimations.z0_est ||...
         estimations_last.vx0_est ~= estimations.vx0_est ||...
         estimations_last.vy0_est ~= estimations.vy0_est ||...
         estimations_last.vz0_est ~= estimations.vz0_est
         prediction_update = 1;
     end
     
     estimations_last = estimations;
   end
   
   point_in_last = point_in;
end