function [Tf] = homogeneous_transformation_generation(pd,pd_p,use_pred,state,t_catch_period,t_in,traj_update,T0_in,max_ee_orientation,r_max,t_start)

persistent Tf_;

if isempty(Tf_)
   Tf_ = zeros(4,4);
   Tf_(1:3,1:3) = eye(3);
end

xd = pd(1);
yd = pd(2);
zd = pd(3);

% coder.extrinsic('vrrotvec');
% coder.extrinsic('vrrotvec2mat');

if traj_update  
    if norm(pd_p) > 0
        v = [0;0;1];
        w = pd_p/norm(pd_p);
        
        % if ball following state -> adapt gradient vector w to be less rotated over v
        if state == 2
            k = cross(v,w);
            k = k/norm(k);
            theta = acos(dot(v,w));
%             t_diff = t_in - t_start;
%             period_diff = t_catch_period(2) - t_start;
%             orientation_factor = (t_diff/period_diff)*max_ee_orientation; % put more weight on the ee orientation over time (up to max_ee_orientation)
            theta_new = theta * max_ee_orientation;
            w = v*(cos(theta_new)) + cross(k,v)*sin(theta_new) + k*dot(k,v)*(1-cos(theta_new)); % https://stackoverflow.com/a/32486205
            w = w/norm(w);
        end

        rot = 2*(((v+w)*(v+w)')/((v+w)'*(v+w)))-eye(3); % https://math.stackexchange.com/a/2672702
        rot(1:3,1:2)=rot(1:3,1:2)*(-1);
        Tf_(1:3,1:3) = rot;
    else
        Tf_(1:3,1:3) = eye(3);
    end
    
    if ((state == 2 && use_pred == 0) || xd < 0)
        Tf_ = T0_in;
    else
        r = sqrt(xd^2+yd^2);
        if r > r_max
            xd = r_max*(xd/r);
            yd = r_max*(yd/r);
        end
        Tf_(1:3,4) = [xd;yd;zd];
    end
    
end

Tf = Tf_;
