function tmpreturn = iiwa_tau_reduce_matrix_params(q, q__pp)
  m = [0 0 0 0 0 0 0;];
  t1 = q(6);
  t2 = cos(t1);
  t3 = 0.124370946e0 * t2;
  t4 = sin(t1);
  t5 = q(7);
  t6 = cos(t5);
  t7 = t6 * t4;
  t8 = 0.1643152e-2 * t7;
  t9 = sin(t5);
  t10 = 0.80259e-4 * t9;
  t11 = -t10 + 0.84216e-3;
  t12 = t4 * t11;
  t14 = q(4);
  t15 = cos(t14);
  t18 = q(3);
  t19 = sin(t18);
  t20 = t6 ^ 2;
  t22 = t9 * t6;
  t24 = -0.611252544e-6 * t20 + 0.142421946e-4 * t22 + 0.3353894419e-4;
  t25 = t2 * t24;
  t26 = 0.1580492332e-4 * t7;
  t27 = 0.3235760644e-3 * t9;
  t29 = t4 * (t27 - 0.1554733347e-2);
  t31 = q(5);
  t32 = cos(t31);
  t33 = t32 ^ 2;
  t35 = 0.71210973e-5 * t20;
  t36 = 0.305626272e-6 * t22;
  t37 = t35 + t36 - 0.1136958063e-1;
  t38 = t2 ^ 2;
  t39 = t38 * t37;
  t40 = 0.1617880322e-3 * t6;
  t41 = 0.7902461658e-5 * t9;
  t42 = -t40 - t41 + 0.1430156112e-4;
  t43 = t4 * t42;
  t44 = t2 * t43;
  t45 = 0.2e1 * t44;
  t46 = t39 - t45 + t35 + t36 + 0.6654482464e-2;
  t47 = sin(t31);
  t49 = t32 * t47 * t46;
  t52 = 0.305626272e-6 * t20 - 0.71210973e-5 * t22 - 0.1676947210e-4;
  t53 = t2 * t52;
  t54 = 0.7902461658e-5 * t7;
  t55 = 0.1617880322e-3 * t9;
  t56 = -t55 + 0.7773666734e-3;
  t57 = t4 * t56;
  t58 = t33 * (t25 - t26 + t29 + 0.3115625928e-5) + t49 + t53 + t54 + t57 + 0.1075175666e-4;
  t60 = 0.7902461658e-5 * t6;
  t61 = -t60 + t55 - 0.7773666734e-3;
  t62 = t61 * t2;
  t63 = t20 * t4;
  t64 = 0.305626272e-6 * t63;
  t65 = t9 * t4;
  t66 = 0.71210973e-5 * t65;
  t67 = -t66 - 0.321036000e-4;
  t68 = t6 * t67;
  t69 = 0.1676947210e-4 * t4;
  t70 = 0.6572608000e-3 * t9;
  t71 = t62 + t64 + t68 - t69 + t70 - 0.2583810286e-1;
  t72 = sin(t14);
  t74 = t32 * t72 * t71;
  t75 = t42 * t72;
  t78 = 0.2e1 * t38 * t47 * t75;
  t82 = t6 * (-0.93e-4 * t65 + 0.2000000000e0);
  t85 = 0.321036000e-4 * t9;
  t86 = 0.71210973e-5 * t63 - 0.3286304e-2 * t82 - 0.1136958063e-1 * t4 - t85 + 0.336864000e-3;
  t87 = t86 * t47;
  t88 = t2 * t72;
  t89 = t88 * t87;
  t90 = 0.4974837840e-1 * t4;
  t91 = -t90 + t40 + t41 + 0.1535567465e-4;
  t94 = t72 * (t47 * t91 + 0.5981298709e-2);
  t97 = cos(t18);
  t99 = 0.2e1 * t97 * (t15 * t58 - t74 + t78 + t89 + t94 - 0.9324224e-5) * t19;
  t101 = 0.3160984663e-4 * t9;
  t102 = -0.6471521288e-3 * t6 - t101 + 0.5720624448e-4;
  t103 = t38 * t102;
  t107 = 0.642072000e-4 * t9;
  t110 = 0.3235760644e-3 * t6;
  t111 = 0.9949675680e-1 * t4;
  t112 = 0.1580492332e-4 * t9;
  t115 = t61 * t47;
  t116 = t2 * t115;
  t117 = 0.2e1 * t116;
  t123 = 0.1314521600e-2 * t9;
  t125 = t47 * (0.611252544e-6 * t63 + t6 * (-0.142421946e-4 * t65 - 0.642072000e-4) - 0.3353894419e-4 * t4 + t123 - 0.5167620573e-1);
  t127 = t15 ^ 2;
  t129 = t46 * t72;
  t130 = t33 * t129;
  t131 = t52 * t47;
  t134 = 0.6901238400e-3 * t6;
  t135 = 0.337087800e-4 * t9;
  t136 = -0.2e1 * t72 * t131 - t134 - t135 + 0.353707200e-3;
  t138 = -t56;
  t139 = t138 * t4;
  t140 = -t54 + t139 + 0.1557812964e-5;
  t141 = t47 * t140;
  t144 = 0.5223579732e-1 * t4;
  t147 = t72 * t37;
  t148 = t38 * t147;
  t152 = -0.1617880322e-3 * t7 + t4 * (-t41 + 0.1430156112e-4) + 0.4974837840e-1;
  t156 = 0.14242195e-4 * t20;
  t158 = 0.93e-4 * t9;
  t160 = t6 * (0.2000000000e0 * t4 - t158);
  t161 = 0.6572608e-2 * t160;
  t163 = -t4 * t11;
  t164 = 0.8000e0 * t163;
  t167 = 0.80259e-4 * t6;
  t168 = 0.1643152e-2 * t9;
  t169 = t167 - t168 + 0.73105972e-1;
  t170 = t47 * t169;
  t171 = 0.4200e0 * t170;
  t174 = t110 + t112 - 0.2860312224e-4;
  t175 = t38 * t174;
  t178 = t175 - t2 * t86 - t40 + t90 - t41 - 0.1535567465e-4;
  t179 = t32 * t178;
  t180 = 0.5223579732e-1 * t72;
  t181 = t180 - t115;
  t186 = -t67;
  t189 = t47 * (-t64 + t6 * t186 + t69 - t70 + 0.2583810286e-1);
  t193 = t47 * t42;
  t195 = 0.2e1 * t38 * t193;
  t197 = -t91;
  t198 = t47 * t197;
  t202 = -t52;
  t203 = t2 * t202;
  t204 = t203 - t54 + t139 + 0.1557812964e-5;
  t209 = t47 * t37;
  t211 = t38 * t72 * t209;
  t212 = t47 * t4;
  t216 = t35 + t36 + 0.6654482464e-2;
  t218 = t47 * t72 * t216;
  t219 = 0.337087800e-4 * t6;
  t220 = 0.6901238400e-3 * t9;
  t221 = t211 - 0.2e1 * t2 * t75 * t212 + t218 - t219 + t220 - 0.3070450824e-1;
  t224 = 0.1643152e-2 * t6;
  t225 = t224 + t10 - 0.84216e-3;
  t226 = t47 * t225;
  t228 = t72 * t52;
  t229 = 0.4200e0 * t226 + t228;
  t230 = t19 * t229;
  t232 = t54 + t57 + 0.1075175666e-4;
  t235 = 0.124370946e0 * t4;
  t236 = t235 - 0.107673e-3;
  t242 = q(2);
  t243 = sin(t242);
  t245 = cos(t242);
  t250 = 0.8400e0 * t72 * (t170 - 0.1072449e-2);
  t251 = t33 * t46;
  t254 = 0.2e1 * t32 * t204 * t47;
  t255 = 0.3235760644e-3 * t7;
  t256 = t112 - 0.2860312224e-4;
  t257 = t4 * t256;
  t259 = t2 * (t255 + t257 - 0.9949675680e-1);
  t260 = t251 - t254 + t39 + t259 - t156 + t161 + t164 - 0.7450265349e0;
  t261 = t127 * t260;
  t262 = 0.611252544e-6 * t22;
  t263 = -t156 - t262 + 0.2273916126e-1;
  t264 = t38 * t263;
  t271 = 0.2e1 * t15 * t72 * (t179 - t116 + t189 - 0.1057852969e-3);
  t272 = 0.6471521288e-3 * t7;
  t273 = -t101 + 0.5720624448e-4;
  t276 = t2 * (-t272 + t4 * t273 + 0.9949675680e-1);
  t280 = 0.3286304e-2 * t6 * (0.4000e0 * t4 - t158);
  t282 = t97 ^ 2;
  t286 = 0.2e1 * t32 * t72 * t178;
  t287 = t72 * t61;
  t288 = t47 * t287;
  t290 = 0.2e1 * t288 - 0.1044715946e0;
  t294 = 0.1380247680e-2 * t7;
  t295 = 0.8400e0 * t12;
  t298 = t225 * t72;
  t299 = 0.8400e0 * t298;
  t304 = 0.8400e0 * t72 * t236;
  t308 = -0.2174625923e1 - t99 - t250 + t261 + t33 * (t264 + 0.4e1 * t44 - t156 - t262 - 0.1330896492e-1) + t282 * (0.7361834842e0 - t271 + t264 + t276 + t261 + t35 - t280 - t164 + t251 - t254) + t35 + t39 + t36 - t45 + t15 * (-t286 + t2 * t290 + t72 * (t125 + 0.2115705938e-3) + t294 - t295 - 0.1944274264e1) + t32 * (t2 * (-t299 - 0.4e1 * t131) - t304 + 0.4e1 * t141);
  t309 = t245 ^ 2;
  t311 = 0.1314521600e-2 * t7;
  t312 = -t37;
  t313 = t38 * t312;
  t317 = t2 * (-t255 - t4 * t256 + 0.9949675680e-1);
  t325 = t33 * (t313 + t45 - t35 - t36 - 0.6654482464e-2);
  t328 = -t263;
  t336 = 0.3048455483e1 + 0.8400e0 * t15 * (t3 - t8 + t12 + 0.2314612219e1) + t99 - 0.2e1 * t245 * t243 * (t97 * (t127 * (t32 * (t103 + t2 * (0.142421946e-4 * t63 - 0.6572608e-2 * t82 - 0.2273916126e-1 * t4 - t107 + 0.673728000e-3) + t110 - t111 + t112 + 0.3071134930e-4) + t117 + t125 + 0.2115705938e-3) + t15 * (-t130 + t32 * (t2 * t136 + 0.2e1 * t72 * t141 - t144 + 0.452226600e-4) - t148 + 0.2e1 * t2 * t72 * t152 + t72 * (t156 - t161 - t164 + 0.7450265349e0) - t171 + 0.4504285800e-3) + t179 + t2 * t181 + 0.4200e0 * t72 * (-t8 + t12 + 0.2314612219e1) + t189 + 0.804563223e-4) + t15 * (t32 * t71 - t195 - t2 * t87 + t198 - 0.5981298709e-2) * t19 + 0.2e1 * t33 * t72 * t19 * t204 + t32 * t221 * t19 + t2 * t230 + t72 * t232 * t19 + 0.4200e0 * t47 * t236 * t19 - 0.1113284276e-1 * t19 + 0.683986848e-5) + t250 + t309 * t308 - t311 - t164 + t251 + t313 + t317 + t32 * (t2 * (t299 + 0.2e1 * t131) + t304 - 0.2e1 * t141) + t282 * (-0.7361834842e0 + t325 + t271 - t35 + t280 + t164 + t127 * (t325 + t254 + t313 + t317 + t156 - t161 - t164 + 0.7450265349e0) + t38 * t328 + t2 * (t272 - t4 * t273 - 0.9949675680e-1) + t254);
  t337 = q__pp(1);
  t344 = -t61;
  t345 = t4 * t344;
  t346 = t33 * (t25 + t4 * (-0.1580492332e-4 * t6 + t27 - 0.1554733347e-2) + 0.3115625928e-5) + t49 + t53 + t345 + 0.1075175666e-4;
  t348 = t4 * t52;
  t349 = 0.321036000e-4 * t6;
  t350 = t62 + t348 - t349 + t70 - 0.2583810286e-1;
  t352 = t32 * t72 * t350;
  t353 = t47 * t72;
  t354 = t4 * t37;
  t355 = 0.6572608000e-3 * t6;
  t356 = t354 - t355 - t85 + 0.336864000e-3;
  t357 = t2 * t356;
  t358 = t357 * t353;
  t366 = t61 * t4;
  t367 = t203 + t366 + 0.1557812964e-5;
  t368 = t367 * t47;
  t370 = 0.2e1 * t32 * t368;
  t374 = t4 * t225;
  t375 = 0.8000e0 * t374;
  t377 = t127 * (t251 - t370 + t39 + t2 * (t4 * t174 - 0.9949675680e-1) + t375 - t156 - t262 - 0.7450265349e0);
  t379 = t4 * t312 + t355 + t85 - 0.336864000e-3;
  t381 = t175 + t2 * t379 + t90 - t40 - t41 - 0.1535567465e-4;
  t382 = t32 * t381;
  t383 = t344 * t47;
  t384 = t2 * t383;
  t385 = t4 * t202;
  t387 = t47 * (t385 + t349 - t70 + 0.2583810286e-1);
  t395 = t32 * t350;
  t396 = t47 * t356;
  t399 = t15 * (t395 - t195 - t2 * t396 + t198 - 0.5981298709e-2);
  t402 = 0.2e1 * t33 * t367 * t72;
  t406 = t72 * (t345 + 0.1075175666e-4);
  t407 = t47 * t236;
  t408 = 0.4200e0 * t407;
  t416 = 0.1314521600e-2 * t6;
  t423 = 0.642072000e-4 * t6;
  t428 = t202 * t47;
  t436 = 0.2e1 * t72 * t47 * (t366 + 0.1557812964e-5);
  t440 = t72 * (t43 + 0.4974837840e-1);
  t444 = t72 * (t375 - t156 - t262 - 0.7450265349e0);
  t447 = -t174;
  t448 = t38 * t447;
  t453 = -t225;
  t454 = t4 * t453;
  t457 = 0.4200e0 * t72 * (t454 + 0.2314612219e1);
  t458 = t348 - t349 + t70 - 0.2583810286e-1;
  t459 = t458 * t47;
  t465 = t198 - 0.5981298709e-2;
  t470 = 0.2e1 * t282 * (t15 * t346 - t352 + t78 + t358 + t94 - 0.9324224e-5) * t243 + t97 * (t19 * t243 * (0.7361834842e0 + t2 * (t4 * t102 + 0.9949675680e-1) + t251 + t377 + t264 + t35 - 0.2e1 * t15 * t72 * (t382 + t384 + t387 - 0.1057852969e-3) - t370 + t36 - t375) - t245 * (t399 + t402 + t32 * t221 + t2 * t229 + t406 + t408 - 0.1113284276e-1)) - t19 * t245 * (t127 * (t32 * (-t38 * t102 + t2 * (t4 * t263 + t416 + t107 - 0.673728000e-3) + t111 - t110 - t112 - 0.3071134930e-4) + 0.2e1 * t384 + t47 * (t4 * t24 + t423 - t123 + 0.5167620573e-1) - 0.2115705938e-3) + t15 * (t130 + t32 * (t2 * (-0.2e1 * t72 * t428 + t134 + t135 - 0.353707200e-3) - t436 + t144 - 0.452226600e-4) + t148 - 0.2e1 * t2 * t440 + t444 + t171 - 0.4504285800e-3) + t32 * (t448 + t357 - t90 + t40 + t41 + 0.1535567465e-4) + t2 * (-t180 - t383) - t457 + t459 - 0.804563223e-4) - t15 * t346 * t243 + t243 * (t352 - t78 - t358 + t72 * t465 + 0.8816518064e-5) - 0.2738227348e-2 * t245;
  t471 = q__pp(2);
  t473 = t382 - t116 + t387 - 0.1057852969e-3;
  t481 = t19 * t61;
  t489 = t97 * t147;
  t490 = t42 * t19;
  t492 = 0.2e1 * t47 * t490;
  t500 = -t169;
  t501 = t47 * t500;
  t502 = 0.4200e0 * t501;
  t508 = t19 * t72;
  t517 = t4 * t72;
  t528 = -t181;
  t541 = 0.9949675680e-1 * t2;
  t544 = t243 * (0.2e1 * t127 * t97 * t473 + t15 * (t33 * t97 * t129 + t32 * (t2 * (-t136 * t97 - t481) + t97 * (-t436 + t144 - 0.452226600e-4) - t19 * t458) + t38 * (t489 + t492) + t2 * (t19 * t396 - 0.2e1 * t440 * t97) + t97 * (t444 - t502 - 0.4504285800e-3) - t19 * t465) - 0.2e1 * t33 * t367 * t508 + t32 * (t38 * (-t209 * t508 + t447 * t97) + t2 * (0.2e1 * t19 * t193 * t517 + t356 * t97) + t97 * t91 - t19 * (t218 - t219 + t220 - 0.3070450824e-1)) + t2 * (t528 * t97 - t230) + t97 * (-t457 + t459 - 0.804563223e-4) - t19 * (t406 + t408 - 0.1113284276e-1)) + (t377 - 0.2e1 * t15 * t72 * t473 + t325 + t370 + t541 - t375 + t35 + t36 + 0.8358076922e0) * t245;
  t545 = q__pp(3);
  t547 = t19 * t37;
  t549 = t97 * t52;
  t561 = t97 * t15;
  t565 = t19 * t52;
  t582 = -t236;
  t585 = t64 + t68 - t69 + t70 - 0.2583810286e-1;
  t591 = t47 * t97;
  t596 = t72 * t86;
  t611 = t8 + t163 - 0.2314612219e1;
  t626 = t53 + t54 + t57 - 0.1557812964e-5;
  t632 = t15 * t61;
  t638 = t38 * t15;
  t645 = t197 * t15;
  t647 = 0.5981298709e-2 * t15;
  t651 = t243 * (t33 * (-t38 * t547 + t2 * (0.2e1 * t15 * t549 + 0.2e1 * t4 * t490) - 0.2e1 * t15 * t97 * t140 - t216 * t19) + t32 * (-t38 * t561 * t209 + t2 * (t47 * (0.2e1 * t43 * t561 - 0.2e1 * t565) - t72 * (0.4200e0 * t19 * t225 - t97 * t61)) + t47 * (-t15 * t216 * t97 + 0.2e1 * t140 * t19) + t72 * (0.4200e0 * t19 * t582 + t97 * t585)) + t38 * (-0.2e1 * t591 * t75 + t547) + t2 * (-t591 * t596 + t15 * (-0.5223579732e-1 * t19 - t549) - 0.2e1 * t152 * t19) + t47 * (-0.4200e0 * t19 * t169 + t97 * t197) * t72 + t15 * (0.4200e0 * t19 * t611 - t97 * t232) + 0.5283e1 * t72 * (0.852600e-4 * t19 - 0.1132178442e-2 * t97) - (-t311 - t164 + 0.7716653098e0) * t19) + (-0.2e1 * t33 * t626 * t72 + t32 * (t211 + t2 * (-0.2e1 * t353 * t43 + t632) + t218 + t585 * t15) - 0.2e1 * t638 * t193 + t2 * (-t15 * t47 * t86 + t228) + t47 * t645 - t647 + t72 * t232) * t245;
  t652 = q__pp(4);
  t655 = t15 * t32;
  t667 = 0.2e1 * t42 * t517;
  t670 = t15 * t225;
  t686 = -t35 - t36 + 0.2427161978e-1;
  t687 = t686 * t72;
  t708 = t72 * t197;
  t715 = t243 * (t38 * (-0.2e1 * t42 * t655 * t97 + t489 + t492) + t2 * (t32 * (t97 * (t15 * t379 + t134 + t135 - 0.353707200e-3) - t481) + t97 * (-t115 * t15 - t667) + t47 * t19 * (-0.4200e0 * t670 + t354 - t355 - t85 + 0.336864000e-3)) + t32 * (t97 * (t645 + t144 - 0.452226600e-4) - (-0.4200e0 * t15 * t169 + t348 - t349 + t70 - 0.2583810286e-1) * t19) + t97 * (-t15 * t459 + t171 + t687) - t47 * t19 * (0.4200e0 * t15 * t236 + t90 - t40 - t41 - 0.1535567465e-4)) + t245 * (t38 * (t15 * t37 + 0.2e1 * t32 * t75) + t2 * (t32 * t356 * t72 - 0.2e1 * t15 * t43 + t288) - t32 * t708 + t15 * t686 + t47 * t72 * t458);
  t716 = q__pp(5);
  t719 = 0.4000e0 * t15 + 0.4200e0;
  t720 = t97 * t719;
  t728 = t35 + t36 + 0.1598793304e-1;
  t732 = t32 * t52;
  t736 = 0.5223579732e-1 * t655;
  t737 = 0.4974837840e-1 * t32;
  t738 = 0.4200e0 * t298;
  t743 = t32 * t61;
  t747 = t225 * t32;
  t759 = 0.4974837840e-1 * t2;
  t760 = 0.4000e0 * t374;
  t767 = t15 * t52;
  t773 = t243 * (t47 * (t2 * (0.124370946e0 * t720 + t565) + t4 * (-t225 * t719 * t97 - t481) + t728 * t561) + t2 * (t97 * (-t15 * t732 - t287) - t19 * (-t736 - t737 - t738)) + t4 * (t97 * (t15 * t743 - t228) - t19 * (0.4200e0 * t15 * t747 + 0.4000e0 * t747 - t180)) + t728 * t19 * t32) - (t47 * (t759 - t760 + t35 + t36 + 0.1598793304e-1) * t72 + t2 * (-t228 * t32 + t632) + (t287 * t32 + t767) * t4) * t245;
  t774 = q__pp(6);
  t779 = (0.4200e0 * t15 + 0.4000e0) * t19;
  t781 = -0.187471648e-3 * t561 - 0.93e-4 * t779;
  t785 = -0.9156966e-5 * t561 + 0.1904e-2 * t779;
  t792 = 0.1904e-2 * t720 + 0.9156966e-5 * t19;
  t797 = -0.93e-4 * t720 + 0.187471648e-3 * t19;
  t831 = t47 * t19;
  t837 = 0.1904e-2 * t6 + t158;
  t841 = -0.84972706e-1 * t2 * t837 - t355 - t85 + 0.1108136025e-2 * t4;
  t852 = t15 * t4;
  t865 = t243 * (t32 * (-0.863e0 * t2 * (t6 * t781 + t785 * t9) + 0.863e0 * t6 * t792 - 0.863e0 * t9 * t797 - 0.1108136025e-2 * t15 * t4 * t97) + t2 * (-0.863e0 * t6 * t797 * t47 - 0.863e0 * t9 * t47 * t792 + 0.1108136025e-2 * t72 * t97) - 0.863e0 * t6 * (t47 * t785 + (-0.187471648e-3 * t97 - 0.390600e-4 * t19) * t517) + 0.863e0 * t9 * (t47 * t781 - (-0.9156966e-5 * t97 + 0.7996800e-3 * t19) * t517) + 0.1108136025e-2 * t4 * t831) + t245 * (t32 * t841 * t72 + t2 * (-0.321036000e-4 * t47 * t72 * t6 + 0.6572608000e-3 * t9 * t353 + 0.1108136025e-2 * t15) + 0.84972706e-1 * t6 * (0.1904e-2 * t852 - 0.93e-4 * t353) - 0.84972706e-1 * (-0.93e-4 * t852 - 0.1904e-2 * t353) * t9);
  t866 = q__pp(7);
  m(1,1) = t336 * t337 + t470 * t471 + t544 * t545 + t651 * t652 + t715 * t716 + t773 * t774 + t865 * t866;
  t869 = t2 * t225;
  t870 = t869 + t235 - 0.107673e-3;
  t874 = t6 * t47;
  t898 = t20 * t212;
  t899 = 0.305626272e-6 * t898;
  t901 = t6 * t186 * t47;
  t902 = 0.1676947210e-4 * t212;
  t903 = -t70 + 0.2583810286e-1;
  t923 = 0.2295542151e1 + 0.8400e0 * t32 * t72 * t870 + 0.8400e0 * t72 * (0.80259e-4 * t874 + t47 * (-t168 + 0.73105972e-1) - 0.1072449e-2) + 0.2e1 * t97 * (t74 - t78 - t89 + t72 * (-0.1617880322e-3 * t874 + 0.4974837840e-1 * t212 + t47 * (-t41 - 0.1535567465e-4) - 0.5981298709e-2) + 0.9324224e-5) * t19 + t282 * (t251 - t254 + t264 + t276 + t35 - t280 - t164 + 0.7361834841e0) + t127 * (t97 + 0.1e1) * (t97 - 0.1e1) * t260 + t15 * (-0.2e1 * t282 * t72 * (t179 - t116 - t899 + t901 + t902 + t47 * t903 - 0.1057852969e-3) - 0.2e1 * t97 * t19 * t58 + t286 - t2 * t290 + t72 * (-0.611252544e-6 * t898 + 0.2e1 * t901 + 0.3353894420e-4 * t212 + t47 * (-t123 + 0.5167620573e-1) - 0.2115705938e-3) - t294 + t295 + 0.1944274264e1) - t35 + t39 - t36 - t45;
  t948 = t3 + t454 + 0.2314612219e1;
  t949 = t72 * t948;
  t953 = t47 * t129;
  t962 = t19 * (t127 * (t32 * (t103 + t2 * (t4 * t328 - t416 - t107 + 0.673728000e-3) - t111 + t110 + t112 + 0.3071134930e-4) + t117 + t47 * (-t4 * t24 - t423 + t123 - 0.5167620573e-1) + 0.2115705938e-3) + t15 * (-t130 + t32 * (0.2e1 * t72 * t368 - 0.4200e0 * t869 - t144 + 0.452226600e-4) + t72 * (t313 + t2 * (t4 * t447 + 0.9949675680e-1) - t375 + t156 + t262 + 0.7450265349e0) + t502 + 0.4504285800e-3) + t382 + 0.4200e0 * t949 - t116 + t387 + 0.804563223e-4) - (t399 + t402 + t32 * (t953 - t219 + t220 - 0.3070450824e-1) + t72 * (t53 + t345 + 0.1075175666e-4) + 0.4200e0 * t2 * t226 + t408 - 0.1113284276e-1) * t97;
  t1006 = t97 * (t325 + t32 * (t2 * (t24 * t47 - t738) + t47 * (-t26 + t29 + 0.3115625928e-5) + 0.4200e0 * t582 * t72) + t39 + t2 * (-0.5223579732e-1 * t15 + t255 + t257 - 0.9949675680e-1) - 0.4200e0 * t47 * t169 * t72 + 0.4200e0 * t15 * t611 + 0.4504285800e-3 * t72 + t311 + t164 - 0.7716653098e0) + t19 * (-0.2e1 * t33 * t15 * t626 + t32 * (t638 * t209 + t2 * (-0.2e1 * t15 * t43 * t47 - t287) + t47 * t15 * t216 - t72 * t585) + t78 + t2 * (t47 * t596 + t767) - t47 * t708 + t15 * t232 + 0.5981298709e-2 * t72);
  t1008 = t42 * t32;
  t1014 = t32 * t356 + t115;
  t1019 = t32 * t91;
  t1030 = t32 * t169;
  t1037 = t19 * (t38 * (0.2e1 * t1008 * t15 - t147) + t2 * (t15 * t1014 - 0.4200e0 * t747 + t667) + t15 * (t1019 + t459) - 0.4200e0 * t32 * t236 - t171 - t687) - (-t195 + t2 * (0.4200e0 * t15 * t226 + t743 - t396) - 0.4200e0 * t15 * (t1030 - t407) + t32 * t458 + t198) * t97;
  t1046 = -t760 + t35 + t36 + 0.1598793304e-1;
  t1055 = t4 * t32;
  t1063 = t19 * (t2 * (t15 * (t732 - 0.4974837840e-1 * t47) - 0.5223579732e-1 * t47 + t287) + t15 * (-t1046 * t47 - t32 * t366) + t4 * t229) - t97 * (t2 * (-t736 - t737 + t428 - t738) + 0.4200e0 * t670 * t1055 - t32 * t1046 + t528 * t4);
  t1067 = t32 * (0.98462e-1 * t2 + 0.4000e0);
  t1070 = 0.4000e0 * t2 + 0.98462e-1;
  t1071 = t1070 * t47;
  t1076 = t2 * t47;
  t1097 = t2 * t32;
  t1103 = t32 * t1070;
  t1126 = t19 * (-0.863e0 * t6 * (t15 * (0.1904e-2 * t1067 + 0.93e-4 * t1071) + 0.7996800e-3 * t32 + 0.390600e-4 * t1076 + 0.187471648e-3 * t517) + 0.863e0 * t9 * (t15 * (-0.93e-4 * t1067 + 0.1904e-2 * t1071) - 0.390600e-4 * t32 + 0.7996800e-3 * t1076 - 0.9156966e-5 * t517) + 0.1108136025e-2 * t15 * t1055 - 0.1108136025e-2 * t88) - (0.863e0 * t6 * (0.4200e0 * t15 * (-0.93e-4 * t1097 + 0.1904e-2 * t47) - 0.93e-4 * t1103 + 0.187471648e-3 * t1076 + 0.7616000e-3 * t47 - 0.390600e-4 * t517) + 0.863e0 * t9 * (0.4200e0 * t15 * (0.1904e-2 * t1097 + 0.93e-4 * t47) + 0.1904e-2 * t1103 + 0.9156966e-5 * t1076 + 0.372000e-4 * t47 + 0.7996800e-3 * t517) - 0.1108136025e-2 * t212) * t97;
  t1128 = t2 * t453;
  t1129 = t1128 - t235 + 0.107673e-3;
  t1131 = t32 * t1129 + t501 + 0.1072449e-2;
  t1133 = t15 * t1131 + t949 + 0.5824e-3;
  t1135 = t19 * t500;
  t1137 = t19 * t870;
  t1143 = t15 * t948;
  t1145 = t32 * t870 + t170 - 0.1072449e-2;
  m(1,2) = t337 * t470 + t471 * t923 + t545 * t962 + t652 * t1006 + t716 * t1037 + t774 * t1063 + t866 * t1126 + 0.981e1 * t245 * (t97 * t1133 + t32 * t1135 + t47 * t1137 - 0.15810274e-1 * t19 + 0.105684e-3) - 0.981e1 * t243 * (t1143 + t72 * t1145 + 0.581448144e1);
  t1155 = -0.2e1 * t2 * t4 * t42;
  t1158 = 0.8000e0 * t12;
  t1184 = 0.2e1 * t33 * t204 * t72 + t32 * (t15 * t71 + t953) + t47 * t178 * t15 + t72 * (t53 + t54 + t57 + 0.1075175666e-4) - t647;
  t1193 = t72 * (0.2e1 * t1008 * t38 + t1014 * t2 + t1019 + t459) + t15 * (t39 - t45 - t35 - t36 + 0.2427161978e-1);
  t1197 = -t759 - t35 + 0.3286304e-2 * t160 - 0.4000e0 * t12 - 0.1598793304e-1;
  t1217 = t72 * (t47 * t1197 + (0.305626272e-6 * t20 * t2 + t6 * (-0.71210973e-5 * t2 * t9 + 0.7902461658e-5 * t4) - 0.1676947210e-4 * t2 - t139) * t32) - t15 * (t64 + t6 * (-0.7902461658e-5 * t2 - t66) + t2 * t138 - t69);
  t1222 = -0.93e-4 * t6 + 0.1904e-2 * t9;
  t1231 = 0.84972706e-1 * t4 * t837 + 0.1108136025e-2 * t2;
  t1233 = t72 * (t32 * t841 + 0.863e0 * t1070 * t1222 * t47) + t1231 * t15;
  t1236 = t32 * t500;
  m(1,3) = t337 * t544 + t471 * t962 + t545 * (t127 * (t33 * (t39 + t1155 + t35 + t36 + 0.6654482464e-2) - t254 + t39 + t259 - t156 + t161 - t1158 - 0.7450265349e0) + 0.2e1 * t15 * (t32 * (t448 + t2 * t86 + t40 - t90 + t41 + 0.1535567465e-4) + t116 + t899 - t901 - t902 - t47 * t903 + 0.1057852969e-3) * t72 + t33 * (t313 - t1155 - t35 - t36 - 0.6654482464e-2) + t254 + t541 + t35 - t280 + t1158 + 0.8358076922e0) + t652 * t1184 + t716 * t1193 + t774 * t1217 + t866 * t1233 + 0.981e1 * t243 * (-t19 * t1133 + t97 * t1236 + t47 * t97 * t870 - 0.15810274e-1 * t97);
  t1253 = t381 * t47 + t395;
  t1258 = t32 * t1197 - t47 * (t53 - t366);
  t1265 = -t47 * t841 + 0.863e0 * t32 * t1070 * t1222;
  m(1,4) = t337 * t651 + t471 * t1006 + t545 * t1184 + t652 * (t251 + 0.2e1 * t32 * t626 * t47 + t313 + t317 - t311 - t164 + 0.7716653098e0) + t716 * t1253 + t774 * t1258 + t866 * t1265 + 0.981e1 * t243 * t97 * (-t1131 * t72 + t1143) + 0.981e1 * t245 * (t1145 * t15 - t949);
  t1282 = t385 - t62;
  m(1,5) = t337 * t715 + t471 * t1037 + t545 * t1193 + t652 * t1253 + t716 * (t39 + t1155 - t35 - t36 + 0.2427161978e-1) + t774 * t1282 + t866 * t1231 + 0.981e1 * t243 * (t97 * t15 * (-t1129 * t47 + t1236) - t47 * t1135 + t32 * t1137) + 0.981e1 * t245 * t72 * (-t47 * t870 + t1030);
  t1305 = t60 - t55;
  t1310 = -t235 + t1128;
  t1314 = -t374 + t3;
  m(1,6) = t337 * t773 + t471 * t1063 + t545 * t1217 + t652 * t1258 + t716 * t1282 + t774 * t728 + t866 * t1305 + 0.981e1 * t243 * (t97 * (t15 * t32 * (-t454 - t3) + t72 * t1310) + t47 * t19 * t1314) + 0.981e1 * t245 * (t1314 * t32 * t72 + t1310 * t15);
  t1333 = t168 - t167;
  t1336 = t10 + t224;
  t1340 = t4 * t1333;
  t1347 = -t2 * t1333;
  m(1,7) = t337 * t865 + t471 * t1126 + t545 * t1233 + t652 * t1265 + t716 * t1231 + t774 * t1305 + 0.1108136025e-2 * t866 + 0.981e1 * t243 * (t97 * (t15 * (t1333 * t2 * t32 + t1336 * t47) + t72 * t1340) + t32 * t19 * t1336 + t831 * t1347) + 0.981e1 * t245 * (t15 * t1340 + t72 * (-t1336 * t47 + t1347 * t32));
  tmpreturn = m';
