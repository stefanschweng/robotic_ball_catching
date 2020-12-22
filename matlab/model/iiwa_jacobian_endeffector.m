function tmpreturn = iiwa_jacobian_endeffector(q)
  m = [0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0;];
  t1 = q(5);
  t2 = cos(t1);
  t3 = q(2);
  t4 = sin(t3);
  t5 = t2 * t4;
  t6 = q(6);
  t7 = sin(t6);
  t10 = q(3);
  t11 = cos(t10);
  t12 = cos(t3);
  t13 = t12 * t11;
  t14 = cos(t6);
  t16 = 0.1520e0 * t14 + 0.4000e0;
  t18 = -0.1520e0 * t7 * t5 + t16 * t13;
  t19 = q(4);
  t20 = sin(t19);
  t22 = cos(t19);
  t25 = sin(t1);
  t26 = sin(t10);
  t27 = t26 * t25;
  t28 = t11 * t2 * t22 - t27;
  t29 = t28 * t12;
  t31 = 0.1520e0 * t7 * t29;
  t32 = t22 * t16;
  t34 = (t32 + 0.4200e0) * t4;
  t36 = q(1);
  t37 = sin(t36);
  t41 = t26 * t2;
  t43 = t11 * t25;
  t44 = t22 * t41 + t43;
  t45 = t7 * t44;
  t47 = -t20 * t16 * t26 + 0.1520e0 * t45;
  t48 = cos(t36);
  m(1,1) = t37 * (t18 * t20 - t31 - t34) - t48 * t47;
  t50 = t2 * t20;
  t51 = t7 * t50;
  t52 = 0.1520e0 * t51;
  t53 = t32 + t52 + 0.4200e0;
  t58 = 0.1520e0 * t22 * t7 * t2;
  t59 = -t16 * t20 + t58;
  t62 = 0.1520e0 * t7 * t27;
  t65 = t12 * t53 - t4 * (t11 * t59 - t62);
  m(1,2) = t48 * t65;
  t66 = -t59;
  t71 = t26 * t66 - 0.1520e0 * t11 * t7 * t25;
  t72 = t12 * t71;
  t75 = t11 * t66 + t62;
  m(1,3) = t37 * t75 + t48 * t72;
  t77 = -t18;
  t79 = t11 * t2;
  t86 = t22 * t77 - (0.1520e0 * t12 * t7 * t79 + t16 * t4) * t20;
  t88 = t32 + t52;
  m(1,4) = t26 * t37 * t88 + t48 * t86;
  t93 = t13 * t22 + t20 * t4;
  t95 = t12 * t41;
  t96 = t25 * t93 + t95;
  t100 = -t22 * t25 * t26 + t79;
  t101 = t100 * t37;
  m(1,5) = -0.1520e0 * t7 * (t48 * t96 + t101);
  t106 = t20 * t5 + t29;
  t111 = t11 * t12 * t20 - t22 * t4;
  t117 = t20 * t26;
  m(1,6) = 0.1520e0 * t48 * (t106 * t14 + t111 * t7) - 0.1520e0 * t37 * (t117 * t7 + t14 * t44);
  m(1,7) = 0.0e0;
  m(2,1) = t48 * (t20 * t77 + t31 + t34) - t47 * t37;
  m(2,2) = t65 * t37;
  m(2,3) = t48 * (t11 * (-t16 * t20 + t58) - t62) + t37 * t72;
  m(2,4) = -t26 * t48 * t88 + t37 * t86;
  t137 = t100 * t48;
  m(2,5) = -0.1520e0 * t7 * (t37 * t96 - t137);
  m(2,6) = 0.1520e0 * t14 * (t106 * t37 + t44 * t48) + 0.1520e0 * (t111 * t37 + t117 * t48) * t7;
  m(2,7) = 0.0e0;
  m(3,1) = 0.0e0;
  m(3,2) = t12 * t75 - t4 * t53;
  m(3,3) = -t4 * t71;
  m(3,4) = t11 * t4 * t88 + t12 * t59;
  m(3,5) = 0.1520e0 * (t4 * (t22 * t43 + t41) - t12 * t25 * t20) * t7;
  t169 = t11 * t4;
  t172 = t12 * t22 + t169 * t20;
  m(3,6) = -0.1520e0 * t14 * (-t12 * t50 + t28 * t4) - 0.1520e0 * t7 * t172;
  m(3,7) = 0.0e0;
  m(4,1) = 0.0e0;
  m(4,2) = -t37;
  m(4,3) = t4 * t48;
  t175 = t12 * t48;
  m(4,4) = t11 * t37 + t175 * t26;
  m(4,5) = t20 * (-t11 * t175 + t26 * t37) + t22 * t4 * t48;
  t186 = -t25 * t93 - t95;
  m(4,6) = t186 * t48 - t101;
  t191 = t106 * t7 - t111 * t14;
  t195 = -t14 * t20 * t26 + t45;
  m(4,7) = t191 * t48 - t195 * t37;
  m(5,1) = 0.0e0;
  m(5,2) = t48;
  m(5,3) = t4 * t37;
  t197 = t12 * t37;
  m(5,4) = -t11 * m(5,2) + t197 * t26;
  m(5,5) = t20 * (-t11 * t197 - t26 * m(5,2)) + t22 * t4 * t37;
  m(5,6) = t186 * t37 + t137;
  m(5,7) = t191 * t37 + t195 * m(5,2);
  m(6,1) = 0.1e1;
  m(6,2) = 0.0e0;
  m(6,3) = t12;
  t209 = t26 * t4;
  m(6,4) = -t209;
  m(6,5) = t172;
  m(6,6) = t25 * (t169 * t22 - t20 * m(6,3)) + t2 * t209;
  m(6,7) = t4 * (t11 * t14 * t20 - t28 * t7) + (t14 * t22 + t51) * m(6,3);
  tmpreturn = m;