#include <math.h>

void tmp (double *q, double param, int cgret[1][7])
{
  int m[1][7];
  double t1;
  double t10;
  double t107;
  double t11;
  double t110;
  double t114;
  double t12;
  double t121;
  double t13;
  double t14;
  double t16;
  double t17;
  double t18;
  double t19;
  double t2;
  double t21;
  double t22;
  double t23;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t3;
  double t30;
  double t31;
  double t32;
  double t34;
  double t35;
  double t37;
  double t39;
  double t4;
  double t40;
  double t44;
  double t45;
  double t47;
  double t49;
  double t5;
  double t51;
  double t54;
  double t6;
  double t7;
  double t8;
  double t9;
  double t91;
  double t96;
  m[0][0] = 0;
  m[0][1] = 0;
  m[0][2] = 0;
  m[0][3] = 0;
  m[0][4] = 0;
  m[0][5] = 0;
  m[0][6] = 0;
  m[0][0] = 0;
  t1 = q[6];
  t2 = cos(t1);
  t3 = 0.1643152e-2 * t2;
  t4 = sin(t1);
  t5 = 0.80259e-4 * t4;
  t6 = -t3 - t5 + 0.84216e-3;
  t7 = q[5];
  t8 = cos(t7);
  t9 = t6 * t8;
  t10 = sin(t7);
  t11 = 0.124370946e0 * t10;
  t12 = t9 - t11 + 0.107673e-3;
  t13 = q[4];
  t14 = cos(t13);
  t16 = 0.80259e-4 * t2;
  t17 = 0.1643152e-2 * t4;
  t18 = -t16 + t17 - 0.73105972e-1;
  t19 = sin(t13);
  t21 = t12 * t14 + t18 * t19 + 0.1072449e-2;
  t22 = q[3];
  t23 = cos(t22);
  t25 = 0.124370946e0 * t8;
  t26 = t6 * t10;
  t27 = t25 + t26 + 0.2314612219e1;
  t28 = sin(t22);
  t29 = t27 * t28;
  t30 = t21 * t23 + t29 + 0.5824e-3;
  t31 = q[2];
  t32 = cos(t31);
  t34 = sin(t31);
  t35 = t18 * t34;
  t37 = -t6;
  t39 = t37 * t8 + t11 - 0.107673e-3;
  t40 = t39 * t34;
  t44 = q[1];
  t45 = cos(t44);
  t47 = t27 * t23;
  t49 = -t18;
  t51 = t39 * t14 + t49 * t19 - 0.1072449e-2;
  t54 = sin(t44);
  m[0][1] = (int) (param.g * ((t30 * t32 + t35 * t14 + t40 * t19 - 0.15810274e-1 * t34 + 0.105684e-3) * t45 - (t47 + t51 * t28 + 0.581448144e1) * t54));
  m[0][2] = (int) (param.g * (-t30 * t34 + t18 * t32 * t14 + t39 * t32 * t19 - 0.15810274e-1 * t32) * t54);
  m[0][3] = (int) (param.g * ((-t21 * t28 + t47) * t32 * t54 + (t23 * t51 - t29) * t45));
  m[0][4] = (int) (param.g * (((-t12 * t19 + t14 * t18) * t23 * t32 - t35 * t19 + t40 * t14) * t54 + (t14 * t49 - t19 * t39) * t28 * t45));
  t91 = -t11 + t9;
  t96 = -t10 * t37 + t25;
  m[0][5] = (int) (param.g * ((((-t26 - t25) * t14 * t23 + t91 * t28) * t32 + t96 * t34 * t19) * t54 + (t14 * t28 * t96 + t23 * t91) * t45));
  t107 = t17 - t16;
  t110 = t5 + t3;
  t114 = t107 * t10;
  t121 = -t107 * t8;
  m[0][6] = (int) (param.g * ((((t107 * t14 * t8 + t110 * t19) * t23 + t114 * t28) * t32 + t110 * t34 * t14 + t121 * t34 * t19) * t54 + (t114 * t23 + (-t110 * t19 + t121 * t14) * t28) * t45));
  cgret[0][0] = m[0][0];
  cgret[0][1] = m[0][1];
  cgret[0][2] = m[0][2];
  cgret[0][3] = m[0][3];
  cgret[0][4] = m[0][4];
  cgret[0][5] = m[0][5];
  cgret[0][6] = m[0][6];
}
