function tmpreturn = iiwa_homogeneous_transformation_endeffector(q, param)
  m = [0 0 0 0; 0 0 0 0; 0 0 0 0;];
  t1 = q(5);
  t2 = cos(t1);
  t3 = q(6);
  t4 = cos(t3);
  t5 = t4 * t2;
  t6 = q(4);
  t7 = cos(t6);
  t9 = sin(t3);
  t10 = sin(t6);
  t12 = t10 * t9 + t5 * t7;
  t13 = q(3);
  t14 = cos(t13);
  t16 = sin(t13);
  t17 = t16 * t4;
  t18 = sin(t1);
  t19 = t18 * t17;
  t20 = t12 * t14 - t19;
  t21 = q(2);
  t22 = cos(t21);
  t24 = sin(t21);
  t27 = -t10 * t5 + t7 * t9;
  t28 = t27 * t24;
  t29 = t20 * t22 - t28;
  t30 = q(7);
  t31 = cos(t30);
  t33 = sin(t30);
  t36 = t16 * t2;
  t37 = t14 * t18 * t7 + t36;
  t41 = t10 * t18 * t24 + t22 * t37;
  t44 = q(1);
  t45 = cos(t44);
  t47 = sin(t44);
  t51 = t14 * t18 * t4 + t12 * t16;
  t56 = -t16 * t18 * t7 + t14 * t2;
  m(1,1) = t45 * (t29 * t31 - t33 * t41) - (t31 * t51 + t33 * t56) * t47;
  t62 = -t12 * t14 + t19;
  t67 = t33 * (t22 * t62 + t28) - t41 * t31;
  t72 = t31 * t56 - t33 * t51;
  m(1,2) = t45 * t67 - t47 * t72;
  t76 = t16 * t18;
  t77 = t14 * t2 * t7 - t76;
  t79 = t24 * t2;
  t88 = t9 * (t10 * t79 + t22 * t77) + (-t10 * t14 * t22 + t24 * t7) * t4;
  t92 = t14 * t18 + t36 * t7;
  t95 = -t10 * t17 + t9 * t92;
  m(1,3) = t45 * t88 - t47 * t95;
  t97 = param.l__6 + param.l__7;
  t98 = t9 * t97;
  t101 = t4 * t97 + param.l__4 + param.l__5;
  t109 = t7 * t101;
  t112 = t10 * (-t101 * t14 * t22 + t79 * t98) + t9 * t77 * t97 * t22 + (t109 + param.l__2 + param.l__3) * t24;
  t117 = -t10 * t101 * t16 + t92 * t98;
  m(1,4) = t112 * t45 - t117 * t47;
  m(2,1) = t31 * (t29 * t47 + t45 * t51) - (t41 * t47 - t45 * t56) * t33;
  m(2,2) = t45 * t72 + t47 * t67;
  m(2,3) = t45 * t95 + t47 * t88;
  m(2,4) = t112 * t47 + t117 * t45;
  t134 = -t27;
  m(3,1) = t31 * (t134 * t22 + t24 * t62) + (-t10 * t18 * t22 + t24 * t37) * t33;
  m(3,2) = t24 * (t20 * t33 + t31 * t37) - t22 * (t10 * t18 * t31 + t134 * t33);
  m(3,3) = t24 * (t10 * t14 * t4 - t77 * t9) + (t10 * t2 * t9 + t4 * t7) * t22;
  t163 = t9 * t2;
  m(3,4) = t22 * (t10 * t163 * t97 + param.l__2 + param.l__3 + t109) + t24 * (t14 * (-t163 * t7 * t97 + t101 * t10) + t98 * t76) + param.l__0 + param.l__1;
  tmpreturn = m;
