function [success,q,all_solutions] = inverse_kinematics_analytic(x_d,param,find_minimum_norm)
  elbow_up=true;
  if(nargin<3)
    find_minimum_norm=false;
  end

  success=false;
  q=zeros(7,1);
  all_solutions=[];

  d__bs=param.l__0+param.l__1;
  d__se=param.l__2+param.l__3;
  d__ew=param.l__4+param.l__5;
  d__wt=param.l__6+param.l__7;
  l__bs=[0;0;d__bs];
  l__se=[0;-d__se;0];
  l__ew=[0;0;d__ew];
  l__wt=[0;0;d__wt];
  
  %Transform the desired point x_d to the robot base coordinates.
  H_0=[param.R_0,param.p_0;0,0,0,1];
  H_7=H_0\x_d;

  x_7=H_7(1:3,4);
  R_0_7=H_7(1:3,1:3);
  x__sw=x_7-l__bs-R_0_7*l__wt;
  u__sw=x__sw/norm(x__sw);
  %The angle for joint 4 is solely defined by the distance between shoulder
  %point and wrist point. If this angle is out of the feasible range, no
  %solution can be found.
  tmp=(norm(x__sw)^2-d__se^2-d__ew^2)/(2*d__se*d__ew);
  if(abs(tmp)>1)
    %warning('inverse_kinematics_analytic:tooFar','Target point x_d too far away.');
    return;
  end
  q(4)=acos(tmp);
  if(q(4)>=param.q_limit_upper(4) || q(4)<=param.q_limit_lower(4))
    %warning('inverse_kinematics_analytic:tooClose','Target point x_d too close.');
    return;
  end
  R_3_4 = [cos(q(4)) 0 sin(q(4)); sin(q(4)) 0 -cos(q(4)); 0 1 0;];
  q(1)=atan2(x__sw(2),x__sw(1));
  
  if(elbow_up)
    t1 = cos(q(4));
    t2 = d__ew * t1;
    t4 = sin(q(4));
    t5 = t4 ^ 2;
    t6 = d__ew ^ 2;
    t9 = 0.2e1 * d__se * t2;
    t10 = d__se ^ 2;
    t11 = x__sw(3) ^ 2;
    tmp=(t9 + t6 + t10 - t11) * t6 * t5;
    if(tmp>=0)
      t14 = sqrt(tmp);
      t25 = 0.1e1 / (t9 + t6 + t10);
      q(2) = atan2(0.1e1 / t4 * t25 / d__ew * (t14 * (t2 + d__se) + t6 * x__sw(3) * (t1 + 0.1e1) * (t1 - 0.1e1)), t25 * (d__se * x__sw(3) + x__sw(3) * t2 + t14));
    else
      q=zeros(7,1);
      return;
    end
  else
    if(q(1)>0)
      q(1)=q(1)-pi;
    else
      q(1)=q(1)+pi;
    end
    t1 = cos(q(4));
    t2 = d__ew * t1;
    t4 = sin(q(4));
    t5 = t4 ^ 2;
    t6 = d__ew ^ 2;
    t9 = 0.2e1 * d__se * t2;
    t10 = d__se ^ 2;
    t11 = x__sw(3) ^ 2;
    tmp=(t9 + t6 + t10 - t11) * t6 * t5;
    if(tmp>=0)
      t14 = sqrt(tmp);
      t25 = 0.1e1 / (t9 + t6 + t10);
      q(2) = atan2(0.1e1 / t4 * t25 / d__ew * (t14 * (-d__se - t2) + t6 * x__sw(3) * (t1 + 0.1e1) * (t1 - 0.1e1)), t25 * (d__se * x__sw(3) + x__sw(3) * t2 - t14));
    else
      q=zeros(7,1);
      return;
    end
  end

  R_0_3_o=[cos(q(1)) * cos(q(2)) -cos(q(1)) * sin(q(2)) -sin(q(1)); sin(q(1)) * cos(q(2)) -sin(q(1)) * sin(q(2)) cos(q(1)); -sin(q(2)) -cos(q(2)) 0;];
  A_s=skew(u__sw)*R_0_3_o;
  B_s=-skew(u__sw)^2*R_0_3_o;
  C_s=(u__sw*u__sw')*R_0_3_o;
  %Equivalent formulation for C_s:
  %C_s=(eye(3)+skew(u__sw)^2)*R_0_3_o;
  A_w=R_3_4'*A_s'*R_0_7;
  B_w=R_3_4'*B_s'*R_0_7;
  C_w=R_3_4'*C_s'*R_0_7;

  %Post process solution: A4 has to be inverted to match the implemented
  %robot kinematic model. After this point, q(4) is not used in the
  %calculations anymore.
  q(4)=-q(4);
  q4=q(4);
  
  solution=zeros(7,0);
  psi_list=[linspace(0,pi,9),linspace(-pi/8,-pi,8)];
  if(find_minimum_norm)
    psi=psi_list;
    solution=[atan2(-A_s(2,2)*sin(psi)-B_s(2,2)*cos(psi)-C_s(2,2),-A_s(1,2)*sin(psi)-B_s(1,2)*cos(psi)-C_s(1,2));...
      -A_s(3,2)*sin(psi)-B_s(3,2)*cos(psi)-C_s(3,2);...
      atan2( A_s(3,3)*sin(psi)+B_s(3,3)*cos(psi)+C_s(3,3),-A_s(3,1)*sin(psi)-B_s(3,1)*cos(psi)-C_s(3,1));...
      q4*ones(size(psi));...
      atan2(A_w(2,3)*sin(psi)+B_w(2,3)*cos(psi)+C_w(2,3),A_w(1,3)*sin(psi)+B_w(1,3)*cos(psi)+C_w(1,3));...
      A_w(3,3)*sin(psi)+B_w(3,3)*cos(psi)+C_w(3,3);...
      atan2(A_w(3,2)*sin(psi)+B_w(3,2)*cos(psi)+C_w(3,2),-A_w(3,1)*sin(psi)-B_w(3,1)*cos(psi)-C_w(3,1))];
    solution_valid=all([abs(solution(2,:))<=1;abs(solution(6,:))<=1]);
    solution=solution(:,solution_valid);
    solution(2,:)=acos(solution(2,:));
    solution(6,:)=acos(solution(6,:));
    solution(:)=wrap(solution(:));
    %Calculate all solutions, which can be generated using simple
    %shifting and inverting operations.
    all_solutions=zeros(7,0);
    N=2;
    for i=-N:N
      for j=-N:N
        for k=-N:N
          tmp=solution;
          if(i~=0)
            tmp=[tmp(1,:)+i*pi;...
              (-1)^i*tmp(2,:);...
              tmp(3,:)+i*pi;...
              tmp(4:end,:)];
          end
          if(j~=0)
            tmp=[tmp(1:2,:);...
              tmp(3,:)+j*pi;...
              (-1)^j*tmp(4,:);...
              tmp(5,:)+j*pi;
              tmp(6:end,:)];
          end
          if(k~=0)
            tmp=[tmp(1:4,:);...
              tmp(5,:)+k*pi;...
              (-1)^k*tmp(6,:);...
              tmp(7,:)+k*pi];
          end
          all_solutions=[all_solutions,tmp];
        end
      end
    end
    all_solutions(:)=wrap(all_solutions(:));
    all_solutions_valid=all([all(all_solutions<=param.q_limit_upper);
        all(all_solutions>=param.q_limit_lower)]);
    all_solutions=all_solutions(:,all_solutions_valid);
    all_solutions=uniquetol(all_solutions',1e-12,'ByRows',true)';
    success=size(all_solutions,2)>0;
    if(success)
      [~,i]=min(vecnorm(all_solutions));
      q=all_solutions(:,i);
    else
      q=zeros(7,1);
    end
  else
    for psi=psi_list
      q(1)=atan2(-A_s(2,2)*sin(psi)-B_s(2,2)*cos(psi)-C_s(2,2),...
                 -A_s(1,2)*sin(psi)-B_s(1,2)*cos(psi)-C_s(1,2));
      tmp=-A_s(3,2)*sin(psi)-B_s(3,2)*cos(psi)-C_s(3,2);
      if(abs(tmp)>1)
        continue;
      end
      q(2)=acos(tmp);
      q(3)=atan2( A_s(3,3)*sin(psi)+B_s(3,3)*cos(psi)+C_s(3,3),...
                 -A_s(3,1)*sin(psi)-B_s(3,1)*cos(psi)-C_s(3,1));
      %Restore original q(4)
      q(4)=q4;
      q(5)=atan2(A_w(2,3)*sin(psi)+B_w(2,3)*cos(psi)+C_w(2,3),...
                 A_w(1,3)*sin(psi)+B_w(1,3)*cos(psi)+C_w(1,3));
      tmp= A_w(3,3)*sin(psi)+B_w(3,3)*cos(psi)+C_w(3,3);
      if(abs(tmp)>1)
        continue;
      end
      q(6)=acos(tmp);
      q(7)=atan2(A_w(3,2)*sin(psi)+B_w(3,2)*cos(psi)+C_w(3,2),...
                -A_w(3,1)*sin(psi)-B_w(3,1)*cos(psi)-C_w(3,1));
      q=wrap(q);
      if(q(1)<param.q_limit_lower(1)) %Get the "shoulder left" solution
        q(1)= q(1)+pi;
        q(2)=-q(2);
        q(3)= q(3)+pi;
        q=wrap(q);
      elseif(q(1)>param.q_limit_upper(1)) %Get the "shoulder right" solution
        q(1)= q(1)-pi;
        q(2)=-q(2);
        q(3)= q(3)-pi;
        q=wrap(q);
      end
      if(q(3)<param.q_limit_lower(3)) %Get the "elbow left" solution
        q(3)= q(3)+pi;
        q(4)=-q(4);
        q(5)= q(5)+pi;
        q=wrap(q);
      elseif(q(3)>param.q_limit_upper(3)) %Get the "elbow right" solution
        q(3)= q(3)-pi;
        q(4)=-q(4);
        q(5)= q(5)-pi;
        q=wrap(q);
      end
      if(q(5)<param.q_limit_lower(5) || q(7)<param.q_limit_lower(7)) %Get the "wrist left" solution
        q(5)= q(5)+pi;
        q(6)=-q(6);
        q(7)= q(7)+pi;
        q=wrap(q);
      elseif(q(5)>param.q_limit_upper(5) || q(7)>param.q_limit_upper(7)) %Get the "wrist right" solution
        q(5)= q(5)-pi;
        q(6)=-q(6);
        q(7)= q(7)-pi;
        q=wrap(q);
      end
      if(all(q<=param.q_limit_upper) && ...
        all(q>=param.q_limit_lower))
        success=true;
        break;
      end
    end
    if(~success)
      q=zeros(7,1);
    end
  end
end
