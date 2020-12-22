function tmpreturn = iiwa_reduced_inertial_rest_params(q)
  m = [0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0;];
  m(1,1) = 0.0e0;
  t1 = q(2);
  t2 = sin(t1);
  t3 = q(7);
  t4 = cos(t3);
  t5 = t4 ^ 2;
  t7 = sin(t3);
  t8 = t7 * t4;
  t10 = -0.611252544e-6 * t5 + 0.142421946e-4 * t8 + 0.3353894419e-4;
  t11 = q(6);
  t12 = cos(t11);
  t15 = 0.3235760644e-3 * t7;
  t17 = sin(t11);
  t20 = q(5);
  t21 = cos(t20);
  t22 = t21 ^ 2;
  t24 = 0.71210973e-5 * t5;
  t25 = 0.305626272e-6 * t8;
  t26 = t24 + t25 - 0.1136958063e-1;
  t27 = t12 ^ 2;
  t28 = t27 * t26;
  t29 = 0.1617880322e-3 * t4;
  t30 = 0.7902461658e-5 * t7;
  t31 = -t29 - t30 + 0.1430156112e-4;
  t32 = t17 * t31;
  t34 = 0.2e1 * t12 * t32;
  t35 = t28 - t34 + t24 + t25 + 0.6654482464e-2;
  t36 = sin(t20);
  t41 = 0.305626272e-6 * t5 - 0.71210973e-5 * t8 - 0.1676947210e-4;
  t42 = t12 * t41;
  t43 = 0.7902461658e-5 * t4;
  t44 = 0.1617880322e-3 * t7;
  t45 = t43 - t44 + 0.7773666734e-3;
  t46 = t17 * t45;
  t47 = t22 * (t12 * t10 + t17 * (-0.1580492332e-4 * t4 + t15 - 0.1554733347e-2) + 0.3115625928e-5) + t21 * t36 * t35 + t42 + t46 + 0.1075175666e-4;
  t48 = q(4);
  t49 = cos(t48);
  t51 = -t45;
  t52 = t51 * t12;
  t53 = t17 * t41;
  t54 = 0.321036000e-4 * t4;
  t55 = 0.6572608000e-3 * t7;
  t56 = t52 + t53 - t54 + t55 - 0.2583810286e-1;
  t57 = sin(t48);
  t59 = t21 * t57 * t56;
  t60 = t31 * t57;
  t63 = 0.2e1 * t27 * t36 * t60;
  t64 = t36 * t57;
  t65 = t17 * t26;
  t66 = 0.6572608000e-3 * t4;
  t67 = 0.321036000e-4 * t7;
  t68 = t65 - t66 - t67 + 0.336864000e-3;
  t69 = t12 * t68;
  t70 = t69 * t64;
  t71 = 0.4974837840e-1 * t17;
  t72 = -t71 + t29 + t30 + 0.1535567465e-4;
  t78 = q(3);
  t79 = cos(t78);
  t80 = t79 ^ 2;
  t85 = -0.6471521288e-3 * t4 - 0.3160984663e-4 * t7 + 0.5720624448e-4;
  t89 = t22 * t35;
  t90 = -t41;
  t91 = t12 * t90;
  t92 = t51 * t17;
  t93 = t91 + t92 + 0.1557812964e-5;
  t94 = t93 * t36;
  t96 = 0.2e1 * t21 * t94;
  t97 = 0.3235760644e-3 * t4;
  t98 = 0.1580492332e-4 * t7;
  t99 = t97 + t98 - 0.2860312224e-4;
  t104 = 0.80259e-4 * t7;
  t105 = 0.1643152e-2 * t4 + t104 - 0.84216e-3;
  t106 = t17 * t105;
  t107 = 0.8000e0 * t106;
  t108 = 0.14242195e-4 * t5;
  t109 = 0.611252544e-6 * t8;
  t111 = t49 ^ 2;
  t112 = t111 * (t89 - t96 + t28 + t12 * (t17 * t99 - 0.9949675680e-1) + t107 - t108 - t109 - 0.7450265349e0);
  t113 = -t108 - t109 + 0.2273916126e-1;
  t115 = t27 * t99;
  t116 = -t26;
  t118 = t17 * t116 + t66 + t67 - 0.336864000e-3;
  t120 = t115 + t118 * t12 + t71 - t29 - t30 - 0.1535567465e-4;
  t121 = t21 * t120;
  t122 = t45 * t36;
  t123 = t12 * t122;
  t124 = t17 * t90;
  t126 = t36 * (t124 + t54 - t55 + 0.2583810286e-1);
  t133 = sin(t78);
  t135 = t21 * t56;
  t136 = t36 * t31;
  t138 = 0.2e1 * t27 * t136;
  t139 = t36 * t68;
  t141 = -t72;
  t142 = t36 * t141;
  t144 = t49 * (t135 - t138 - t12 * t139 + t142 - 0.5981298709e-2);
  t147 = 0.2e1 * t22 * t93 * t57;
  t148 = t36 * t26;
  t150 = t27 * t57 * t148;
  t151 = t36 * t17;
  t155 = t24 + t25 + 0.6654482464e-2;
  t157 = t36 * t57 * t155;
  t158 = 0.337087800e-4 * t4;
  t159 = 0.6901238400e-3 * t7;
  t162 = t36 * t105;
  t164 = t57 * t41;
  t165 = 0.4200e0 * t162 + t164;
  t168 = t57 * (t46 + 0.1075175666e-4);
  t170 = 0.124370946e0 * t17 - 0.107673e-3;
  t171 = t36 * t170;
  t172 = 0.4200e0 * t171;
  t174 = cos(t1);
  t181 = 0.1314521600e-2 * t4;
  t182 = 0.642072000e-4 * t7;
  t185 = 0.9949675680e-1 * t17;
  t190 = 0.642072000e-4 * t4;
  t191 = 0.1314521600e-2 * t7;
  t196 = t35 * t57;
  t197 = t22 * t196;
  t198 = t90 * t36;
  t201 = 0.6901238400e-3 * t4;
  t202 = 0.337087800e-4 * t7;
  t208 = 0.2e1 * t57 * t36 * (t92 + 0.1557812964e-5);
  t209 = 0.5223579732e-1 * t17;
  t212 = t57 * t26;
  t215 = t57 * (t32 + 0.4974837840e-1);
  t219 = t57 * (t107 - t108 - t109 - 0.7450265349e0);
  t222 = 0.80259e-4 * t4 - 0.1643152e-2 * t7 + 0.73105972e-1;
  t224 = 0.4200e0 * t36 * t222;
  t227 = -t99;
  t231 = 0.5223579732e-1 * t57;
  t235 = -t17 * t105;
  t238 = 0.4200e0 * t57 * (t235 + 0.2314612219e1);
  t239 = t53 - t54 + t55 - 0.2583810286e-1;
  t240 = t239 * t36;
  t246 = t142 - 0.5981298709e-2;
  m(1,2) = 0.2e1 * t80 * (t49 * t47 - t59 + t63 + t70 + t57 * (t36 * t72 + 0.5981298709e-2) - 0.9324224e-5) * t2 + t79 * (t133 * t2 * (0.7361834842e0 + t12 * (t17 * t85 + 0.9949675680e-1) + t89 + t112 + t27 * t113 + t24 - 0.2e1 * t49 * t57 * (t121 + t123 + t126 - 0.1057852969e-3) - t96 + t25 - t107) - t174 * (t144 + t147 + t21 * (t150 - 0.2e1 * t12 * t60 * t151 + t157 - t158 + t159 - 0.3070450824e-1) + t12 * t165 + t168 + t172 - 0.1113284276e-1)) - t133 * t174 * (t111 * (t21 * (-t27 * t85 + t12 * (t17 * t113 + t181 + t182 - 0.673728000e-3) + t185 - t97 - t98 - 0.3071134930e-4) + 0.2e1 * t123 + t36 * (t17 * t10 + t190 - t191 + 0.5167620573e-1) - 0.2115705938e-3) + t49 * (t197 + t21 * (t12 * (-0.2e1 * t57 * t198 + t201 + t202 - 0.353707200e-3) - t208 + t209 - 0.452226600e-4) + t27 * t212 - 0.2e1 * t12 * t215 + t219 + t224 - 0.4504285800e-3) + t21 * (t27 * t227 + t69 - t71 + t29 + t30 + 0.1535567465e-4) + t12 * (-t231 - t122) - t238 + t240 - 0.804563223e-4) - t49 * t47 * t2 + t2 * (t59 - t63 - t70 + t57 * t246 + 0.8816518064e-5) - 0.2738227348e-2 * t174;
  t251 = t51 * t36;
  t252 = t12 * t251;
  t253 = t121 - t252 + t126 - 0.1057852969e-3;
  t264 = t133 * t51;
  t272 = t79 * t212;
  t273 = t31 * t133;
  t275 = 0.2e1 * t36 * t273;
  t285 = -0.4200e0 * t36 * t222;
  t291 = t133 * t57;
  t300 = t17 * t57;
  t311 = t251 - t231;
  t325 = t27 * t116;
  t327 = t22 * (t325 + t34 - t24 - t25 - 0.6654482464e-2);
  m(1,3) = t2 * (0.2e1 * t111 * t79 * t253 + t49 * (t22 * t79 * t196 + t21 * (t12 * (t79 * (0.2e1 * t57 * t41 * t36 + t201 + t202 - 0.353707200e-3) - t264) + t79 * (-t208 + t209 - 0.452226600e-4) - t133 * t239) + t27 * (t272 + t275) + t12 * (t133 * t139 - 0.2e1 * t215 * t79) + t79 * (t219 - t285 - 0.4504285800e-3) - t133 * t246) - 0.2e1 * t22 * t93 * t291 + t21 * (t27 * (-t148 * t291 + t227 * t79) + t12 * (0.2e1 * t133 * t136 * t300 + t68 * t79) + t79 * t72 - t133 * (t157 - t158 + t159 - 0.3070450824e-1)) + t12 * (-t133 * t165 + t311 * t79) + t79 * (-t238 + t240 - 0.804563223e-4) - t133 * (t168 + t172 - 0.1113284276e-1)) + (t112 - 0.2e1 * t49 * t57 * t253 + t327 + t96 + 0.9949675680e-1 * t12 - t107 + t24 + t25 + 0.8358076922e0) * t174;
  t331 = t133 * t26;
  t333 = t79 * t41;
  t339 = t4 * t17;
  t340 = 0.7902461658e-5 * t339;
  t341 = t44 - 0.7773666734e-3;
  t342 = t341 * t17;
  t343 = -t340 + t342 + 0.1557812964e-5;
  t350 = t79 * t49;
  t354 = t133 * t41;
  t371 = -t170;
  t374 = t5 * t17;
  t375 = 0.305626272e-6 * t374;
  t376 = t7 * t17;
  t377 = 0.71210973e-5 * t376;
  t379 = t4 * (-t377 - 0.321036000e-4);
  t380 = 0.1676947210e-4 * t17;
  t381 = t375 + t379 - t380 + t55 - 0.2583810286e-1;
  t387 = t36 * t79;
  t398 = 0.71210973e-5 * t374 - 0.3286304e-2 * t4 * (-0.93e-4 * t376 + 0.2000000000e0) - 0.1136958063e-1 * t17 - t67 + 0.336864000e-3;
  t399 = t57 * t398;
  t419 = t104 - 0.84216e-3;
  t420 = t17 * t419;
  t421 = 0.1643152e-2 * t339 + t420 - 0.2314612219e1;
  t425 = -t341 * t17;
  t426 = t340 + t425 + 0.1075175666e-4;
  t435 = 0.1314521600e-2 * t339;
  t436 = 0.8000e0 * t420;
  t441 = t42 + t340 + t425 - 0.1557812964e-5;
  t447 = t49 * t51;
  t453 = t27 * t49;
  t460 = t141 * t49;
  t462 = 0.5981298709e-2 * t49;
  m(1,4) = t2 * (t22 * (-t27 * t331 + t12 * (0.2e1 * t17 * t273 + 0.2e1 * t333 * t49) - 0.2e1 * t49 * t79 * t343 - t155 * t133) + t21 * (-t27 * t350 * t148 + t12 * (t36 * (0.2e1 * t32 * t350 - 0.2e1 * t354) - t57 * (0.4200e0 * t133 * t105 - t79 * t51)) + t36 * (-t155 * t49 * t79 + 0.2e1 * t133 * t343) + t57 * (0.4200e0 * t133 * t371 + t79 * t381)) + t27 * (-0.2e1 * t387 * t60 + t331) + t12 * (-t387 * t399 + t49 * (-0.5223579732e-1 * t133 - t333) - 0.2e1 * (-0.1617880322e-3 * t339 + t17 * (-t30 + 0.1430156112e-4) + 0.4974837840e-1) * t133) + t36 * (-0.4200e0 * t133 * t222 + t79 * t141) * t57 + t49 * (0.4200e0 * t133 * t421 - t79 * t426) + 0.5283e1 * t57 * (0.852600e-4 * t133 - 0.1132178442e-2 * t79) - (-t435 - t436 + 0.7716653098e0) * t133) + (-0.2e1 * t22 * t441 * t57 + t21 * (t150 + t12 * (-0.2e1 * t32 * t64 + t447) + t157 + t381 * t49) - 0.2e1 * t453 * t136 + t12 * (-t36 * t398 * t49 + t164) + t36 * t460 - t462 + t57 * t426) * t174;
  t467 = t49 * t21;
  t479 = 0.2e1 * t31 * t300;
  t482 = t49 * t105;
  t498 = -t24 - t25 + 0.2427161978e-1;
  t499 = t498 * t57;
  t518 = t57 * t51;
  t522 = t57 * t141;
  m(1,5) = t2 * (t27 * (-0.2e1 * t31 * t467 * t79 + t272 + t275) + t12 * (t21 * (t79 * (t49 * t118 + t201 + t202 - 0.353707200e-3) - t264) + t79 * (-t251 * t49 - t479) + t36 * t133 * (-0.4200e0 * t482 + t65 - t66 - t67 + 0.336864000e-3)) + t21 * (t79 * (t460 + t209 - 0.452226600e-4) - (-0.4200e0 * t49 * t222 + t53 - t54 + t55 - 0.2583810286e-1) * t133) + t79 * (-t240 * t49 + t224 + t499) - t36 * t133 * (0.4200e0 * t49 * t170 + t71 - t29 - t30 - 0.1535567465e-4)) + t174 * (t27 * (0.2e1 * t21 * t60 + t26 * t49) + t12 * (t21 * t57 * t68 - 0.2e1 * t32 * t49 + t36 * t518) - t21 * t522 + t49 * t498 + t36 * t57 * t239);
  t530 = 0.4000e0 * t49 + 0.4200e0;
  t531 = t79 * t530;
  t539 = t24 + t25 + 0.1598793304e-1;
  t543 = t21 * t41;
  t547 = 0.5223579732e-1 * t467;
  t548 = 0.4974837840e-1 * t21;
  t550 = 0.4200e0 * t105 * t57;
  t555 = t21 * t51;
  t559 = t105 * t21;
  t571 = 0.4974837840e-1 * t12;
  t572 = 0.4000e0 * t106;
  t579 = t49 * t41;
  m(1,6) = t2 * (t36 * (t12 * (0.124370946e0 * t531 + t354) + t17 * (-t105 * t530 * t79 - t264) + t539 * t350) + t12 * (t79 * (-t49 * t543 - t518) - t133 * (-t547 - t548 - t550)) + t17 * (t79 * (t49 * t555 - t164) - t133 * (0.4200e0 * t49 * t559 + 0.4000e0 * t559 - t231)) + t539 * t133 * t21) - (t36 * (t571 - t572 + t24 + t25 + 0.1598793304e-1) * t57 + t12 * (-t164 * t21 + t447) + (t21 * t518 + t579) * t17) * t174;
  t588 = (0.4200e0 * t49 + 0.4000e0) * t133;
  t590 = -0.187471648e-3 * t350 - 0.93e-4 * t588;
  t594 = -0.9156966e-5 * t350 + 0.1904e-2 * t588;
  t601 = 0.1904e-2 * t531 + 0.9156966e-5 * t133;
  t606 = -0.93e-4 * t531 + 0.187471648e-3 * t133;
  t646 = 0.93e-4 * t7;
  t647 = 0.1904e-2 * t4 + t646;
  t651 = -0.84972706e-1 * t12 * t647 - t66 - t67 + 0.1108136025e-2 * t17;
  t662 = t49 * t17;
  m(1,7) = t2 * (t21 * (-0.863e0 * t12 * (t4 * t590 + t594 * t7) + 0.863e0 * t4 * t601 - 0.863e0 * t7 * t606 - 0.1108136025e-2 * t49 * t17 * t79) + t12 * (-0.863e0 * t4 * t606 * t36 - 0.863e0 * t7 * t36 * t601 + 0.1108136025e-2 * t57 * t79) - 0.863e0 * t4 * (t36 * t594 + (-0.187471648e-3 * t79 - 0.390600e-4 * t133) * t300) + 0.863e0 * t7 * (t36 * t590 - (-0.9156966e-5 * t79 + 0.7996800e-3 * t133) * t300) + 0.1108136025e-2 * t17 * t36 * t133) + t174 * (t21 * t651 * t57 + t12 * (-0.321036000e-4 * t36 * t57 * t4 + 0.6572608000e-3 * t7 * t64 + 0.1108136025e-2 * t49) + 0.84972706e-1 * t4 * (0.1904e-2 * t662 - 0.93e-4 * t64) - 0.84972706e-1 * (-0.93e-4 * t662 - 0.1904e-2 * t64) * t7);
  m(2,1) = m(1,2);
  m(2,2) = 0.0e0;
  t708 = t36 * t196;
  m(2,3) = t133 * (t111 * (t21 * (t27 * t85 + t12 * (-t17 * t113 - t181 - t182 + 0.673728000e-3) - t185 + t97 + t98 + 0.3071134930e-4) + 0.2e1 * t252 + t36 * (-t17 * t10 - t190 + t191 - 0.5167620573e-1) + 0.2115705938e-3) + t49 * (-t197 + t21 * (0.2e1 * t57 * t94 - 0.4200e0 * t12 * t105 - t209 + 0.452226600e-4) + t57 * (t325 + t12 * (t17 * t227 + 0.9949675680e-1) - t107 + t108 + t109 + 0.7450265349e0) + t285 + 0.4504285800e-3) + t121 + 0.4200e0 * t57 * (0.124370946e0 * t12 + t235 + 0.2314612219e1) - t252 + t126 + 0.804563223e-4) - (t144 + t147 + t21 * (t708 - t158 + t159 - 0.3070450824e-1) + t57 * (t42 + t46 + 0.1075175666e-4) + 0.4200e0 * t12 * t162 + t172 - 0.1113284276e-1) * t79;
  m(2,4) = t79 * (t327 + t21 * (t12 * (t10 * t36 - t550) + t36 * (-0.1580492332e-4 * t339 + t17 * (t15 - 0.1554733347e-2) + 0.3115625928e-5) + 0.4200e0 * t371 * t57) + t28 + t12 * (-0.5223579732e-1 * t49 + 0.3235760644e-3 * t339 + t17 * (t98 - 0.2860312224e-4) - 0.9949675680e-1) - 0.4200e0 * t36 * t222 * t57 + 0.4200e0 * t49 * t421 + 0.4504285800e-3 * t57 + t435 + t436 - 0.7716653098e0) + t133 * (-0.2e1 * t22 * t49 * t441 + t21 * (t453 * t148 + t12 * (-0.2e1 * t32 * t36 * t49 - t518) + t36 * t49 * t155 - t57 * t381) + t63 + t12 * (t36 * t399 + t579) - t36 * t522 + t49 * t426 + 0.5981298709e-2 * t57);
  t765 = t31 * t21;
  t771 = t21 * t68 + t251;
  t776 = t21 * t72;
  m(2,5) = t133 * (t27 * (0.2e1 * t49 * t765 - t212) + t12 * (t49 * t771 - 0.4200e0 * t559 + t479) + t49 * (t776 + t240) - 0.4200e0 * t21 * t170 - t224 - t499) - (-t138 + t12 * (0.4200e0 * t49 * t162 + t555 - t139) - 0.4200e0 * t49 * (t21 * t222 - t171) + t21 * t239 + t142) * t79;
  t801 = -t572 + t24 + t25 + 0.1598793304e-1;
  t810 = t17 * t21;
  m(2,6) = t133 * (t12 * (t49 * (t543 - 0.4974837840e-1 * t36) - 0.5223579732e-1 * t36 + t518) + t49 * (-t21 * t92 - t36 * t801) + t17 * t165) - t79 * (t12 * (-t547 - t548 + t198 - t550) + 0.4200e0 * t482 * t810 - t21 * t801 + t311 * t17);
  t820 = t21 * (0.98462e-1 * t12 + 0.4000e0);
  t823 = 0.4000e0 * t12 + 0.98462e-1;
  t824 = t823 * t36;
  t829 = t12 * t36;
  t851 = t12 * t21;
  t857 = t21 * t823;
  m(2,7) = t133 * (-0.863e0 * t4 * (t49 * (0.1904e-2 * t820 + 0.93e-4 * t824) + 0.7996800e-3 * t21 + 0.390600e-4 * t829 + 0.187471648e-3 * t300) + 0.863e0 * t7 * (t49 * (-0.93e-4 * t820 + 0.1904e-2 * t824) - 0.390600e-4 * t21 + 0.7996800e-3 * t829 - 0.9156966e-5 * t300) + 0.1108136025e-2 * t49 * t810 - 0.1108136025e-2 * t12 * t57) - (0.863e0 * t4 * (0.4200e0 * t49 * (-0.93e-4 * t851 + 0.1904e-2 * t36) - 0.93e-4 * t857 + 0.187471648e-3 * t829 + 0.7616000e-3 * t36 - 0.390600e-4 * t300) + 0.863e0 * t7 * (0.4200e0 * t49 * (0.1904e-2 * t851 + 0.93e-4 * t36) + 0.1904e-2 * t857 + 0.9156966e-5 * t829 + 0.372000e-4 * t36 + 0.7996800e-3 * t300) - 0.1108136025e-2 * t151) * t79;
  m(3,1) = m(1,3);
  m(3,2) = m(2,3);
  m(3,3) = 0.0e0;
  m(3,4) = 0.2e1 * t22 * (t91 - t340 + t342 + 0.1557812964e-5) * t57 + t21 * (t708 + (t52 + t375 + t379 - t380 + t55 - 0.2583810286e-1) * t49) + t36 * (t115 - t12 * t398 - t29 + t71 - t30 - 0.1535567465e-4) * t49 + t57 * (t42 + t340 + t425 + 0.1075175666e-4) - t462;
  m(3,5) = t57 * (t12 * t771 + 0.2e1 * t27 * t765 + t240 + t776) + t49 * (t28 - t34 - t24 - t25 + 0.2427161978e-1);
  t909 = -t571 - t24 + 0.3286304e-2 * t4 * (0.2000000000e0 * t17 - t646) + 0.4000e0 * t17 * t419 - 0.1598793304e-1;
  m(3,6) = t57 * (t36 * t909 + (0.305626272e-6 * t5 * t12 + t4 * (-0.71210973e-5 * t12 * t7 + 0.7902461658e-5 * t17) - 0.1676947210e-4 * t12 - t342) * t21) - t49 * (t375 + t4 * (-0.7902461658e-5 * t12 - t377) + t12 * t341 - t380);
  t932 = -0.93e-4 * t4 + 0.1904e-2 * t7;
  t941 = 0.84972706e-1 * t17 * t647 + 0.1108136025e-2 * t12;
  m(3,7) = t57 * (t21 * t651 + 0.863e0 * t823 * t932 * t36) + t941 * t49;
  m(4,1) = m(1,4);
  m(4,2) = m(2,4);
  m(4,3) = m(3,4);
  m(4,4) = 0.0e0;
  m(4,5) = t120 * t36 + t135;
  m(4,6) = t21 * t909 - t36 * (t42 - t92);
  m(4,7) = -t36 * t651 + 0.863e0 * t21 * t823 * t932;
  m(5,1) = m(1,5);
  m(5,2) = m(2,5);
  m(5,3) = m(3,5);
  m(5,4) = m(4,5);
  m(5,5) = 0.0e0;
  m(5,6) = t124 - t52;
  m(5,7) = t941;
  m(6,1) = m(1,6);
  m(6,2) = m(2,6);
  m(6,3) = m(3,6);
  m(6,4) = m(4,6);
  m(6,5) = m(5,6);
  m(6,6) = 0.0e0;
  m(6,7) = t43 - t44;
  m(7,1) = m(1,7);
  m(7,2) = m(2,7);
  m(7,3) = m(3,7);
  m(7,4) = m(4,7);
  m(7,5) = m(5,7);
  m(7,6) = m(6,7);
  m(7,7) = 0.0e0;
  tmpreturn = m;
