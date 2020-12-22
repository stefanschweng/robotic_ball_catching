function tmpreturn = iiwa_reduced_inertia_matrix(q, param)
  m = [0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0; 0 0 0 0 0 0 0;];
  t1 = q(6);
  t2 = sin(t1);
  t3 = t2 * param.s__l7x;
  t4 = param.l__6 + param.s__l7z;
  t5 = t4 * param.m__l7;
  t6 = q(7);
  t7 = cos(t6);
  t8 = t7 * t5;
  t9 = t8 * t3;
  t10 = 0.2e1 * t9;
  t11 = param.s__l7y * param.m__l7;
  t12 = sin(t6);
  t13 = t12 * t4;
  t14 = t13 * t11;
  t15 = param.m__l6 * param.s__l6x;
  t16 = param.s__l6y * t15;
  t17 = t14 + t16;
  t18 = 0.2e1 * t17;
  t22 = param.m__l6 * param.s__l6y;
  t23 = -t4 * param.m__l7 + t22;
  t24 = param.l__4 + param.l__5;
  t25 = t24 * t23;
  t26 = 0.2e1 * t25;
  t28 = cos(t1);
  t29 = t28 * (t18 * t2 - t10 - t26);
  t30 = q(4);
  t31 = sin(t30);
  t32 = param.l__2 + param.l__3;
  t33 = t32 * t31;
  t34 = t7 * param.s__l7x;
  t36 = t12 * param.s__l7y;
  t37 = param.m__l7 * t36;
  t38 = param.m__l7 * t34 + t15 - t37;
  t39 = t38 * t33;
  t40 = q(5);
  t41 = sin(t40);
  t42 = t7 ^ 2;
  t44 = param.s__l7x * param.s__l7y;
  t45 = t44 * param.m__l7 * t42;
  t46 = 0.2e1 * t45;
  t47 = param.s__l7x ^ 2;
  t48 = param.s__l7y ^ 2;
  t49 = t47 - t48;
  t51 = param.m__l7 * t49 - param.I__l7xx + param.I__l7yy;
  t52 = t51 * t12;
  t53 = t7 * t52;
  t54 = param.s__l7x * param.m__l7;
  t55 = param.s__l7y * t54;
  t56 = param.d__5 - param.s__l6z;
  t57 = t56 * t15;
  t58 = -t46 - t53 + t55 + t57;
  t59 = t58 * t41;
  t63 = t5 - t22;
  t64 = t2 * t63;
  t65 = param.m__l5 * param.s__l5x;
  t66 = t64 + t65;
  t67 = t66 * t32;
  t69 = 0.2e1 * t31 * t67;
  t70 = t2 * param.s__l7y;
  t71 = t8 * t70;
  t72 = t13 * t54;
  t73 = t56 * t22;
  t74 = t72 + t73;
  t75 = t74 * t2;
  t77 = param.s__l5x * param.s__l5y * param.m__l5;
  t78 = t71 + t75 + t77;
  t79 = t41 * t78;
  t82 = cos(t40);
  t84 = (param.l__4 ^ 2);
  t86 = 2 * param.l__4 * param.l__5;
  t87 = param.l__5 ^ 2;
  t88 = (param.s__l6x ^ 2);
  t89 = param.l__2 ^ 2;
  t91 = 2 * param.l__2 * param.l__3;
  t92 = param.l__3 ^ 2;
  t93 = t56 ^ 2;
  t96 = param.s__l5y ^ 2;
  t97 = param.s__l5z ^ 2;
  t100 = (param.d__1 ^ 2);
  t103 = (param.s__l2y ^ 2);
  t104 = (param.s__l2z ^ 2);
  t109 = -param.m__l7 * t49 + param.I__l7xx - param.I__l7yy;
  t110 = t42 * t109;
  t112 = t55 * t12 * t7;
  t113 = 0.2e1 * t112;
  t117 = (param.l__6 + param.s__l7y + param.s__l7z) * (param.s__l7y - param.s__l7z - param.l__6) * param.m__l7;
  t118 = (param.s__l6y ^ 2);
  t119 = -t88 + t118;
  t120 = param.m__l6 * t119;
  t121 = t110 + t113 - t117 + t120 + param.I__l6xx - param.I__l6yy + param.I__l7yy - param.I__l7zz;
  t122 = t28 ^ 2;
  t123 = t121 * t122;
  t124 = t7 * t4;
  t125 = t124 * t54;
  t126 = -t125 + t14 + t16;
  t127 = t2 * t126;
  t128 = t28 * t127;
  t129 = 0.2e1 * t128;
  t133 = (param.l__6 + param.s__l7x + param.s__l7z) * (param.s__l7x - param.s__l7z - param.l__6) * param.m__l7;
  t134 = (param.d__5 + param.s__l6y - param.s__l6z);
  t135 = (param.d__5 - param.s__l6y - param.s__l6z);
  t137 = (param.m__l6 * t135 * t134);
  t138 = param.s__l5x ^ 2;
  t139 = (-t138 + t96);
  t140 = (param.m__l5 * t139);
  t141 = t123 + t129 + t110 + t113 + t133 + t137 + t140 + param.I__l5xx - param.I__l5yy + param.I__l6yy - param.I__l6zz - param.I__l7xx + param.I__l7zz;
  t142 = t82 ^ 2;
  t143 = t142 * t141;
  t144 = -t58;
  t145 = t28 * t144;
  t146 = t145 + t71 + t75 + t77;
  t149 = 0.2e1 * t82 * t146 * t41;
  t150 = 0.2e1 * t49;
  t152 = 0.2e1 * param.I__l7xx;
  t153 = 0.2e1 * param.I__l7yy;
  t155 = t42 * (param.m__l7 * t150 - t152 + t153);
  t160 = t34 * (t2 * t24 / 0.2e1 + t36) * param.m__l7;
  t161 = 0.4e1 * t160;
  t162 = -t37 + t15;
  t163 = t162 * t24;
  t165 = 0.2e1 * t2 * t163;
  t169 = t48 - (param.l__4 + param.l__5 + param.s__l7x) * (param.s__l7x - param.l__4 - param.l__5);
  t170 = param.m__l7 * t169;
  t171 = (param.s__l6x + param.d__5 - param.s__l6z);
  t172 = (param.d__5 - param.s__l6x - param.s__l6z);
  t174 = -t171 * t172 + t84 + t86 + t87;
  t175 = param.m__l6 * t174;
  t176 = param.m__l5 * t84;
  t178 = param.l__4 * param.m__l5;
  t180 = 2 * param.s__l5z * t178;
  t181 = (-t96 + t97);
  t182 = param.m__l5 * t181;
  t183 = (param.s__l4x ^ 2);
  t184 = (param.s__l4y ^ 2);
  t185 = (-t183 + t184);
  t186 = (param.m__l4 * t185);
  t187 = t180 + t182 - param.I__l7yy + param.I__l7xx + t186 + param.I__l4xx - param.I__l4yy + param.I__l5yy - param.I__l5zz - param.I__l6xx + param.I__l6zz;
  t189 = cos(t30);
  t190 = t189 ^ 2;
  t192 = -t126;
  t193 = 0.2e1 * t192;
  t194 = t122 * t193;
  t196 = t42 * t2 * t51;
  t197 = t12 * t2;
  t203 = t34 * param.m__l7 * (param.s__l7y * t197 + param.l__4 / 0.2e1 + param.l__5 / 0.2e1);
  t204 = 0.2e1 * t203;
  t209 = t2 * t25;
  t210 = param.l__4 + param.s__l5z;
  t211 = t210 * t65;
  t212 = t194 + t28 * (-t196 + t204 + t2 * (-t117 + t120 + param.I__l6xx - param.I__l6yy + param.I__l7yy - param.I__l7zz) + t163) - t125 - t209 + t14 + t16 + t211;
  t213 = t82 * t212;
  t214 = t124 * t11;
  t215 = t214 + t72 + t73;
  t216 = t215 * t41;
  t217 = t28 * t216;
  t219 = t55 * t42 * t2;
  t220 = 0.2e1 * t219;
  t221 = t51 * t197;
  t223 = -t11 * t24 + t221;
  t225 = -t55 - t57;
  t227 = t12 * t24;
  t228 = t227 * t54;
  t230 = param.m__l6 * t56 * t24;
  t231 = param.m__l5 * param.s__l5y;
  t232 = t210 * t231;
  t234 = t41 * (t2 * t225 + t223 * t7 + t220 - t228 + t230 - t232);
  t236 = param.s__l4y * param.s__l4x * param.m__l4;
  t240 = 0.2e1 * t189 * t31 * (t213 - t217 + t234 + t236);
  t241 = 0.4e1 * t112;
  t242 = 0.2e1 * t117;
  t243 = -t119;
  t244 = 2 * t243;
  t245 = param.m__l6 * t244;
  t246 = 0.2e1 * param.I__l6xx;
  t247 = 0.2e1 * param.I__l6yy;
  t248 = 0.2e1 * param.I__l7zz;
  t249 = t155 - t241 + t242 + t245 - t246 + t247 - t153 + t248;
  t251 = (t138 - t97);
  t253 = (param.d__3 ^ 2);
  t255 = 2 * param.d__3 * param.s__l4z;
  t256 = param.s__l4z ^ 2;
  t257 = t253 - t255 - t184 + t256;
  t259 = param.s__l3x ^ 2;
  t260 = param.s__l3y ^ 2;
  t261 = -t259 + t260;
  t263 = -t84 - t86 - t87 - t88 + t118;
  t265 = t143 + t190 * (t143 + t149 + t123 + t29 + t155 - t161 - t165 + t170 + t175 + t176 + t187) + t240 + t149 + t165 - t180 + param.I__l7yy - t176 + t122 * t249 + (param.m__l5 * t251) + (param.m__l4 * t257) + param.m__l3 * t261 + (param.m__l6 * t263);
  t266 = 0.4e1 * t9;
  t268 = -0.4e1 * t17;
  t276 = 0.2e1 * t7 * (t2 * t24 + t36) * t54;
  t280 = -t48 + (param.l__4 + param.l__5 + param.l__6 + param.s__l7z) * (param.s__l7z - param.l__4 - param.l__5 + param.l__6);
  t282 = t28 * (t2 * t268 + t26 + t266) + t276 + t110 + param.m__l7 * t280 - param.I__l3yy - param.I__l4zz - param.I__l5xx - param.I__l6yy - param.I__l7zz + param.I__l6xx + param.I__l3xx + param.I__l4yy + param.I__l5zz;
  t284 = q(3);
  t285 = cos(t284);
  t286 = t285 ^ 2;
  t288 = 0.4e1 * t126;
  t289 = t122 * t288;
  t297 = 0.2e1 * t125;
  t298 = 0.2e1 * t209;
  t299 = 0.2e1 * t14;
  t300 = 0.2e1 * t16;
  t301 = 0.2e1 * t211;
  t304 = 0.2e1 * t217;
  t306 = -t223;
  t309 = -t225;
  t312 = 0.2e1 * t228;
  t313 = 0.2e1 * t230;
  t314 = 2 * t232;
  t316 = t41 * (0.2e1 * t2 * t309 + 0.2e1 * t306 * t7 - 0.4e1 * t219 + t312 - t313 + t314);
  t317 = 0.2e1 * t236;
  t320 = t42 * t51;
  t321 = param.m__l6 * t243;
  t322 = t320 - t113 + t117 + t321 - param.I__l6xx + param.I__l6yy - param.I__l7yy + param.I__l7zz;
  t323 = t122 * t322;
  t325 = -param.m__l5 * t139;
  t326 = t323 - t129 + t320 - t113 - t133 - t137 + t325 - param.I__l5xx + param.I__l5yy - param.I__l6yy + param.I__l6zz + param.I__l7xx - param.I__l7zz;
  t327 = t326 * t31;
  t328 = t142 * t327;
  t331 = t38 * t32;
  t332 = -0.2e1 * t31 * t59 - t331;
  t338 = t31 * t322;
  t339 = t122 * t338;
  t341 = t17 * t2 - t25 - t9;
  t345 = t155 - t161 - t165 + t170 + t175 + t176 + t180 + t182 - param.I__l7yy + param.I__l7xx + t186 + param.I__l4xx - param.I__l4yy + param.I__l5yy - param.I__l5zz - param.I__l6xx + param.I__l6zz;
  t347 = t7 * t11;
  t348 = t12 * param.s__l7x;
  t349 = param.m__l7 * t348;
  t350 = param.m__l6 * t56;
  t351 = -t347 - t349 + t350 - t231;
  t353 = param.s__l4x * param.m__l4;
  t355 = (t351 * t41 + t353) * t32;
  t359 = t32 * t23 * t31;
  t360 = -t359 - t216;
  t363 = t7 * t2 * t54;
  t364 = -t162;
  t365 = t2 * t364;
  t366 = param.m__l7 * t24;
  t367 = param.m__l6 * t24;
  t368 = param.s__l4y * param.m__l4;
  t369 = param.s__l5z * param.m__l5;
  t371 = t32 * (-t363 + t365 + t366 + t367 + t368 + t369 + t178);
  t373 = param.m__l3 * param.s__l3z;
  t374 = param.s__l3x * t373;
  t376 = param.l__2 * param.m__l3 * param.s__l3x;
  t379 = sin(t284);
  t380 = t215 * t28;
  t381 = t306 * t7;
  t382 = t2 * t309;
  t383 = t380 - t220 + t381 + t382 + t228 - t230 + t232;
  t385 = t41 * t126;
  t387 = 0.2e1 * t122 * t385;
  t389 = t2 * (t117 + t321 - param.I__l6xx + param.I__l6yy - param.I__l7yy + param.I__l7zz);
  t390 = t196 - t204 + t389 - t163;
  t391 = t390 * t41;
  t393 = -t209 - t125 + t14 + t16 + t211;
  t394 = t41 * t393;
  t395 = param.d__3 - param.s__l4z;
  t396 = t395 * t368;
  t404 = t41 * t322;
  t406 = t122 * t31 * t404;
  t407 = t2 * t41;
  t408 = t31 * t126;
  t411 = 0.2e1 * t28 * t408 * t407;
  t412 = t320 - t113 - t133 - t137 + t325 - param.I__l5xx + param.I__l5yy - param.I__l6yy + param.I__l6zz + param.I__l7xx - param.I__l7zz;
  t414 = t31 * t412 * t41;
  t415 = -t56;
  t417 = param.m__l6 * t415 + t231 + t347 + t349;
  t418 = t417 * t32;
  t422 = t41 * t331;
  t423 = t31 * t58;
  t424 = t422 + t423;
  t425 = t379 * t424;
  t428 = -t74 * t2;
  t429 = t395 * t353;
  t430 = -t71 + t428 - t77 + t429;
  t434 = t41 * t66;
  t436 = param.m__l4 * t395;
  t439 = param.l__2 * (param.s__l3y * param.m__l3 + t436);
  t440 = param.l__3 * t436;
  t442 = param.s__l3z * param.s__l3y * param.m__l3;
  t448 = q(2);
  t449 = sin(t448);
  t451 = cos(t448);
  t455 = 0.2e1 * t31 * t355;
  t456 = 0.4e1 * t45;
  t457 = 0.2e1 * t53;
  t458 = 0.2e1 * t55;
  t460 = t456 + t457 - t458 - 0.2e1 * t57;
  t462 = 0.2e1 * t71;
  t464 = 0.2e1 * t74 * t2;
  t465 = 0.2e1 * t77;
  t468 = t41 * t326;
  t470 = t28 * t58;
  t471 = t142 * (t28 * t460 + t462 + t464 + t465) + t82 * t468 + t470 - t71 + t428 - t77 + t429;
  t474 = t82 * t31 * t383;
  t477 = 0.2e1 * t122 * t41 * t408;
  t478 = t28 * t31;
  t479 = t478 * t391;
  t480 = -t393;
  t483 = t31 * (t41 * t480 - t396);
  t485 = param.s__l3x * param.s__l3y * param.m__l3;
  t489 = 0.2e1 * t285 * (t189 * t471 - t474 + t477 + t479 + t483 + t485) * t379;
  t490 = t28 * t63;
  t495 = param.m__l4 + param.m__l3;
  t496 = t89 * t495;
  t499 = (2 * param.l__3 * param.m__l4) + 0.2e1 * t373;
  t500 = param.l__2 * t499;
  t501 = param.s__l1x ^ 2;
  t502 = param.s__l1y ^ 2;
  t505 = t29 + t82 * (t28 * (0.2e1 * t39 + 0.2e1 * t59) + t69 - 0.2e1 * t79) + param.m__l6 * (t84 + t86 + t87 + t88 + t89 + t91 + t92 + t93) + param.m__l5 * (t89 + t91 + t92 + t96 + t97) + (param.m__l2 * (-2 * param.d__1 * param.s__l2z + t100 + t103 + t104)) + t286 * (t265 + t282) - 0.2e1 * t451 * t449 * (t285 * (t190 * (t82 * (t289 + t28 * (0.2e1 * t196 - 0.4e1 * t203 + t2 * (t242 + t245 - t246 + t247 - t153 + t248) - 0.2e1 * t163) + t297 + t298 - t299 - t300 - t301) + t304 + t316 - t317) + t189 * (-t328 + t82 * (t28 * t332 + 0.2e1 * t31 * t79 - t67) - t339 + 0.2e1 * t28 * t31 * t341 + t31 * t345 - t355) + t213 + t28 * t360 + t31 * t371 + t234 - t374 - t376 + t236) + t189 * (-t28 * t391 + t383 * t82 - t387 + t394 + t396) * t379 + 0.2e1 * t142 * t31 * t379 * t146 + t82 * (t406 - t411 + t414 + t418) * t379 + t28 * t425 + t31 * t430 * t379 + t434 * t32 * t379 + t379 * (t439 + t440 + t442) + (param.s__l2y * param.s__l2x * param.m__l2)) + t455 - t165 + t180 + t489 + 0.2e1 * t189 * t32 * (t490 - t363 + t365 + t366 + t367 + t368 + t369 + t178) + t496 + t500 + (t501 + t502) * param.m__l1;
  t506 = param.m__l4 * t92;
  t515 = t142 * t326;
  t517 = -t18 * t2;
  t523 = t42 * (-param.m__l7 * t150 + t152 - t153);
  t525 = -param.m__l7 * t169;
  t527 = -param.m__l6 * t174;
  t530 = -param.m__l5 * t181;
  t532 = -param.m__l4 * t185;
  t533 = -t180 + t530 + param.I__l7yy - param.I__l7xx + t532 - param.I__l4xx + param.I__l4yy - param.I__l5yy + param.I__l5zz + param.I__l6xx - param.I__l6zz;
  t534 = t515 - t149 + t323 + t28 * (t10 + t517 + t26) + t523 + t161 + t165 + t525 + t527 - t176 + t533;
  t535 = t190 * t534;
  t536 = param.s__l3z ^ 2;
  t541 = 0.2e1 * t82 * t31 * t212;
  t542 = t31 * t215;
  t543 = t41 * t542;
  t544 = t23 * t32;
  t546 = 0.2e1 * t543 + 0.2e1 * t544;
  t550 = 0.2e1 * t371;
  t555 = -(param.m__l6 * t244) + t153 + t241 - t242 + t246 - t247 - t248 + t523;
  t556 = t122 * t555;
  t565 = (2 * param.m__l5 * t139) + 0.2e1 * param.I__l5xx - 0.2e1 * param.I__l5yy - 0.2e1 * param.I__l6zz + 0.4e1 * t128 + 0.2e1 * t133 + 0.2e1 * t137 - t152 + t241 + t247 + t248 + t523 + t556;
  t567 = param.s__l2x ^ 2;
  t577 = -t455 - t489 - t129 - t506 + param.m__l6 * (t118 - t89 - t91 - t92 - t93) + param.m__l5 * (-t89 - t91 - t92 + t138 - t96) - t89 * t495 - param.l__2 * t499 + t535 - t113 + param.I__l7xx + param.m__l3 * (t260 - t536) + t189 * (-t541 + t28 * t546 + t31 * (t316 - t317) - t550) + t142 * t565 + (param.m__l2 * (t567 - t103)) + t82 * (t28 * (-0.2e1 * t39 - 0.4e1 * t59) - t69 + 0.4e1 * t79);
  t588 = t28 * (-t2 * t268 - t26 - t266);
  t590 = -param.m__l7 * t280;
  t592 = -param.m__l6 * t263;
  t593 = -t240 - t149 - t165 + t180 + t535 + t515 - param.I__l7yy + t176 + t556 - t276 + t588 + t590 + t592;
  t595 = -param.m__l5 * t251;
  t597 = -param.m__l4 * t257;
  t599 = -param.m__l3 * t261;
  t600 = t595 + t597 + t599 + t320 + param.I__l3yy + param.I__l4zz + param.I__l5xx + param.I__l6yy + param.I__l7zz - param.I__l6xx - param.I__l3xx - param.I__l4yy - param.I__l5zz;
  t603 = (param.m__l4 * (t253 - t255 - t183 + t256)) + param.m__l7 * (-t47 + (param.l__2 + param.l__3 + param.l__6 + param.s__l7z) * (param.s__l7z - param.l__2 - param.l__3 + param.l__6)) + t286 * (t593 + t600) + t323 + t320 - param.I__l2xx - param.I__l3yy - param.I__l4zz - param.I__l5xx - param.I__l6yy - param.I__l7zz + param.I__l2yy + param.I__l3zz + param.I__l5yy + param.I__l6zz + param.I__l4xx;
  t605 = t451 ^ 2;
  t609 = 0.2e1 * t7 * t366 * t3;
  t612 = t32 ^ 2;
  t615 = t183 + t184;
  t616 = t615 * param.m__l4;
  t617 = t506 + t605 * (t577 + t603) + t515 - t609 + t176 + param.m__l3 * (t259 + t536) + param.m__l7 * (t48 + t47 + t84 + t86 + t87 + t612) + t616 + t123 + param.I__l2xx + param.I__l3yy + param.I__l4zz + param.I__l5xx + param.I__l6yy + param.I__l7zz + param.I__l1zz;
  m(1,1) = t505 + t617;
  t618 = t415 * t15;
  t620 = t456 + t457 - t458 + 0.2e1 * t618;
  t622 = t415 * t22;
  t623 = t214 + t72 - t622;
  t630 = -param.m__l6 * t135 * t134;
  t631 = t323 - t129 + t320 - t113 - t133 + t630 + t325 - param.I__l5xx + param.I__l5yy - param.I__l6yy + param.I__l6zz + param.I__l7xx - param.I__l7zz;
  t634 = -t46 - t53 + t55 - t618;
  t635 = t28 * t634;
  t636 = -t623;
  t637 = t2 * t636;
  t638 = t142 * (0.2e1 * t2 * t623 + t28 * t620 + t465) + t82 * t41 * t631 + t635 + t637 - t77 + t429;
  t640 = t28 * t623;
  t641 = t2 * t634;
  t642 = t7 * t24;
  t643 = t642 * t11;
  t645 = param.m__l6 * t415 * t24;
  t646 = t640 + t641 + t643 + t228 + t645 + t232;
  t648 = t82 * t31 * t646;
  t649 = t31 * t41;
  t650 = t2 * t322;
  t651 = t38 * t24;
  t652 = t650 - t651;
  t653 = t28 * t652;
  t654 = t653 * t649;
  t659 = t2 * t651;
  t660 = 0.2e1 * t659;
  t662 = t121 * t2 + t651;
  t664 = t28 * t662 - t125 + t14 + t16 + t194 - t209 + t211;
  t665 = t82 * t664;
  t666 = t636 * t41;
  t667 = t28 * t666;
  t668 = -t634;
  t676 = t28 * t668;
  t677 = t2 * t623;
  t678 = t676 + t677 + t77;
  t681 = 0.2e1 * t82 * t678 * t41;
  t682 = t142 * t631;
  t685 = t28 * (t193 * t2 + t26);
  t689 = param.m__l6 * (t171 * t172 - t84 - t86 - t87);
  t693 = -t660 - 0.2e1 * t189 * t31 * (t665 + t667 + t41 * (t2 * t668 - t228 - t232 - t643 - t645) + t236) - t681 + t180 - t113 + t190 * (t682 - t681 + t323 + t685 + t660 + t523 + t241 + t525 + t689 - t176 + t533) - param.I__l7yy + t176 + t556 + t590 + t592 + t595 + t597;
  t697 = t599 + t28 * (t2 * t288 - t26) + t682 + t320 + param.I__l3yy + param.I__l4zz + param.I__l5xx + param.I__l6yy + param.I__l7zz - param.I__l6xx - param.I__l3xx - param.I__l4yy - param.I__l5zz;
  t702 = t41 * t652;
  t703 = t28 * t702;
  t709 = t320 - t113 - t133 + t630 + t325 - param.I__l5xx + param.I__l5yy - param.I__l6yy + param.I__l6zz + param.I__l7xx - param.I__l7zz;
  t711 = t41 * t31 * t709;
  t719 = t41 * t67;
  t727 = 0.2e1 * t651;
  t734 = 0.2e1 * t643;
  t740 = t31 * t631;
  t754 = t31 * (t127 - t25);
  t757 = t660 + t523 + t241 + t525 + t689 - t176 - t180 + t530 + param.I__l7yy - param.I__l7xx + t532 - param.I__l4xx + param.I__l4yy - param.I__l5yy + param.I__l5zz + param.I__l6xx - param.I__l6zz;
  t761 = -t193;
  t762 = t122 * t761;
  t768 = -t2 * t38;
  t771 = t31 * (t768 + t366 + t367 + t369 + t178 + t368) * t32;
  t779 = t394 + t396;
  t782 = param.d__1 - param.s__l2z;
  m(1,2) = 0.2e1 * t286 * (t189 * t638 + t477 + t483 + t485 - t648 + t654) * t449 + t285 * (t379 * t449 * (t693 + t697) - t451 * (t189 * (t646 * t82 - t387 + t394 + t396 - t703) + 0.2e1 * t142 * t31 * t678 + t82 * (t406 - t411 + t711 + t418) + t28 * (t31 * t634 + t422) + t31 * (t637 - t77 + t429) + t719 + t439 + t440 + t442)) - t379 * t451 * (t190 * (t82 * (-t122 * t288 + t28 * (t2 * t555 + t727) - t298 - t297 + t299 + t300 + t301) + 0.2e1 * t667 + t41 * (t2 * t620 - t312 - t314 - 0.2e1 * t645 - t734) + t317) + t189 * (t142 * t740 + t82 * (t28 * (-0.2e1 * t31 * t41 * t668 + t331) - 0.2e1 * t31 * (t677 + t77) * t41 + t67) + t339 - 0.2e1 * t28 * t754 + t31 * t757 + t355) + t82 * (t762 + t653 + t209 + t125 - t14 - t16 - t211) + t28 * (t359 - t666) - t771 + t41 * (t641 + t643 + t228 + t645 + t232) + t374 + t376 - t236) - t189 * t638 * t449 + t449 * (-(param.m__l2 * param.s__l2x * t782) + t31 * t779 - t477 - t485 + t648 - t654) - t782 * param.s__l2y * param.m__l2 * t451;
  t791 = t41 * (t144 * t2 - t228 + t230 - t232 - t643);
  t792 = t665 - t217 + t791 + t236;
  t800 = t379 * t215;
  t803 = t215 * t2;
  t810 = t2 * t58;
  t811 = t810 + t643 + t228 - t230 + t232;
  t815 = t285 * t338;
  t816 = t126 * t379;
  t818 = 0.2e1 * t41 * t816;
  t826 = t660 + t523 + t241 + t525 + t527 - t176 - t180 + t530 + param.I__l7yy - param.I__l7xx + t532 - param.I__l4xx + param.I__l4yy - param.I__l5yy + param.I__l5zz + param.I__l6xx - param.I__l6zz;
  t830 = (t41 * t417 - t353) * t32;
  t836 = t379 * t31;
  t837 = t145 + t803 + t77;
  t846 = t2 * t31;
  t857 = -t360;
  t861 = t811 * t41;
  t865 = -t215 * t2;
  t872 = t837 * t41;
  t874 = 0.2e1 * t82 * t872;
  t881 = t28 * t25;
  t883 = param.s__l7z ^ 2;
  t885 = 0.2e1 * param.l__6 * param.s__l7z;
  t886 = param.l__6 ^ 2;
  t887 = t24 ^ 2;
  t891 = param.m__l6 * (t84 + t86 + t87 + t88 + t118);
  t893 = param.m__l5 * (t138 + t97);
  t895 = param.m__l4 * (t253 - t255 + t184 + t256);
  t897 = (t259 + t260) * param.m__l3;
  t898 = t190 * (t515 - t874 + t323 + t685 + t660 + t523 + t241 + t525 + t527 - t176 + t533) - 0.2e1 * t189 * t31 * t792 + t143 + t874 - 0.2e1 * t881 - t660 + t320 - t113 + param.m__l7 * (t48 + t883 + t885 + t886 + t887) + t891 + t176 + t180 + t893 + param.I__l7xx + t895 + param.I__l5yy + param.I__l6zz + t897 + param.I__l3zz + param.I__l4xx;
  m(1,3) = t449 * (0.2e1 * t190 * t285 * t792 + t189 * (t142 * t285 * t327 + t82 * (t28 * (-t285 * t332 - t800) + t285 * (-0.2e1 * t31 * t41 * (t803 + t77) + t67) - t379 * t811) + t122 * (t815 + t818) + t28 * (-0.2e1 * t285 * t754 + t379 * t702) + t285 * (t31 * t826 - t830) - t379 * t779) - 0.2e1 * t142 * t837 * t836 + t82 * (t122 * (t285 * t761 - t404 * t836) + t28 * (0.2e1 * t379 * t385 * t846 + t285 * t652) + t285 * t480 - t379 * (t414 + t418)) + t28 * (t285 * t857 - t425) + t285 * (-t771 + t861 + t374 + t376 - t236) - t379 * (t31 * (t865 - t77 + t429) + t719 + t439 + t440 + t442)) + t898 * t451;
  t900 = t379 * t322;
  t902 = t285 * t58;
  t914 = t285 * t189;
  t918 = t379 * t58;
  t935 = t2 * t23 - t65;
  t938 = -t220 + t381 + t382 + t228 - t230 + t232;
  t944 = t41 * t285;
  t949 = t31 * t390;
  t958 = t351 * t32;
  t965 = -t24;
  t969 = (param.m__l6 * t965 + param.m__l7 * t965 + t162 * t2 - t178 + t363 - t368 - t369) * t32;
  t981 = t48 + t47 + t887;
  t982 = param.m__l7 * t981;
  t983 = t84 + t86 + t87 + t88 + t93;
  t984 = param.m__l6 * t983;
  t985 = t96 + t97;
  t986 = param.m__l5 * t985;
  t987 = -t609 - t165 + t982 + t984 + t176 + t180 + t986 + t616 + param.I__l4zz + param.I__l5xx + param.I__l6yy + param.I__l7zz;
  t991 = t470 - t71 + t428 - t77;
  t997 = t189 * t215;
  t1003 = t122 * t189;
  t1010 = t393 * t189;
  t1013 = t395 * param.s__l4y;
  t1014 = t1013 * param.m__l4 * t189;
  m(1,4) = t449 * (t142 * (-t122 * t900 + t28 * (0.2e1 * t189 * t902 + 0.2e1 * t2 * t816) - 0.2e1 * t189 * t285 * t78 - t709 * t379) + t82 * (-t122 * t914 * t404 + t28 * (t41 * (0.2e1 * t127 * t914 - 0.2e1 * t918) - t31 * (-t215 * t285 + t331 * t379)) + t41 * (-t189 * t285 * t709 + 0.2e1 * t379 * t78) + t31 * (t32 * t379 * t935 + t285 * t938)) + t122 * (-0.2e1 * t408 * t944 + t900) + t28 * (-t944 * t949 + t189 * (t379 * t544 - t902) - 0.2e1 * t341 * t379) + t41 * (t285 * t393 - t379 * t958) * t31 + t189 * (-t285 * t430 + t379 * t969) + t31 * (-param.s__l4x * t32 * t379 + param.s__l4y * t285 * t395) * param.m__l4 - t987 * t379) + (-0.2e1 * t142 * t991 * t31 + t82 * (t406 + t28 * (-0.2e1 * t127 * t649 + t997) + t711 + t938 * t189) - 0.2e1 * t1003 * t385 + t28 * (-t189 * t390 * t41 + t423) + t41 * t1010 + t1014 + t31 * t430) * t451;
  t1031 = 0.2e1 * t126 * t846;
  t1034 = t189 * t331;
  t1048 = t41 * t958;
  t1049 = t4 ^ 2;
  t1051 = param.m__l7 * (t47 + t1049);
  t1053 = param.m__l6 * (t118 + t93);
  t1055 = (t138 + t96) * param.m__l5;
  t1056 = t110 + t113 + t1051 + t1053 + t1055 + param.I__l5zz + param.I__l6xx + param.I__l7yy;
  t1057 = t1056 * t31;
  t1077 = t31 * t393;
  m(1,5) = t449 * (t122 * (-0.2e1 * t126 * t189 * t285 * t82 + t815 + t818) + t28 * (t82 * (t285 * (t189 * t662 + t331) - t800) + t285 * (-t189 * t216 - t1031) + t41 * t379 * (-t1034 + t650 - t651)) + t82 * (t285 * (t1010 + t67) - (-t189 * t958 + t228 - t230 + t232 + t643 + t810) * t379) + t285 * (-t189 * t861 + t1048 + t1057) - t41 * t379 * (t189 * t67 - t125 + t14 + t16 - t209 + t211)) + t451 * (t122 * (t189 * t322 + 0.2e1 * t408 * t82) + t28 * (t31 * t652 * t82 - 0.2e1 * t127 * t189 + t543) - t82 * t1077 + t189 * t1056 + t41 * t31 * t811);
  t1085 = t189 * t24 + param.l__2 + param.l__3;
  t1094 = t48 + t1049;
  t1095 = param.m__l7 * t1094;
  t1096 = t88 + t118;
  t1097 = t1096 * param.m__l6;
  t1098 = t320 - t113 + t1095 + param.I__l7xx + t1097 + param.I__l6zz;
  t1102 = t82 * t58;
  t1107 = t189 * t32;
  t1108 = t1107 * t23 * t82;
  t1109 = t82 * t25;
  t1114 = t82 * t215;
  t1119 = t189 * t38;
  t1136 = t189 * t58;
  m(1,6) = t449 * (t41 * (t28 * (-t1085 * t23 * t285 + t918) + t2 * (-t1085 * t285 * t38 - t800) + t1098 * t914) + t28 * (t285 * (-t1102 * t189 - t542) - t379 * (t1108 + t1109 - t39)) + t2 * (t285 * (t1114 * t189 - t423) - t379 * (t1119 * t32 * t82 + t651 * t82 + t359)) + t1098 * t379 * t82) - (t41 * (-t881 - t659 + t320 - t113 + t1095 + t1097 + param.I__l6zz + param.I__l7xx) * t31 + t28 * (-t423 * t82 + t997) + (t542 * t82 + t1136) * t2) * t451;
  t1142 = param.s__l7x * t189;
  t1143 = t285 * t4;
  t1145 = t379 * param.s__l7y;
  t1146 = t1107 + param.l__4 + param.l__5;
  t1148 = -t1142 * t1143 + t1145 * t1146;
  t1152 = param.s__l7x * t379;
  t1154 = param.s__l7y * t1143 * t189 + t1146 * t1152;
  t1163 = (param.s__l7x * t1085 * t285 - t1145 * t4) * param.m__l7;
  t1168 = param.s__l7y * t1085 * t285 + t1152 * t4;
  t1174 = (t47 + t48) * param.m__l7 + param.I__l7zz;
  t1175 = t189 * t1174;
  t1179 = t41 * param.m__l7;
  t1189 = t4 * param.s__l7x;
  t1198 = t4 * param.s__l7y;
  t1207 = t1174 * t2;
  t1211 = t34 - t36;
  t1216 = -t1211 * t28 * t5 + t11 * t227 - t54 * t642 + t1207;
  t1219 = param.m__l7 * t649;
  t1220 = t24 * param.s__l7y;
  t1223 = t24 * param.s__l7x;
  m(1,7) = t449 * (t82 * (-t28 * (t1148 * t7 + t1154 * t12) * param.m__l7 + t7 * t1163 - t12 * t1168 * param.m__l7 - t1175 * t2 * t285) + t28 * (-t1163 * t12 * t41 - t1168 * t1179 * t7 + t1174 * t285 * t31) - t7 * (t41 * t1154 + (t1145 * t32 - t1189 * t285) * t846) * param.m__l7 + t12 * (t41 * t1148 - (t1152 * t32 + t1198 * t285) * t846) * param.m__l7 + t1207 * t41 * t379) + t451 * (t82 * t1216 * t31 + t28 * (t12 * t1219 * t1223 + t1219 * t1220 * t7 + t1175) + (t7 * (param.s__l7y * t649 + t1142 * t2) - (-param.s__l7x * t649 + t189 * t70) * t12) * t5);
  m(2,1) = m(1,2);
  t1253 = t55 * t42 * t407;
  t1254 = 0.2e1 * t1253;
  t1256 = t7 * t223 * t41;
  t1258 = t2 * t309 * t41;
  t1259 = -t228 + t230 - t232;
  t1294 = t28 * t38;
  t1296 = (t1294 + t64 + t65) * t32;
  t1300 = 0.2e1 * t285 * (t474 - t477 - t479 + t31 * (-t7 * t4 * t41 * t54 - t407 * t25 + t41 * (t14 + t16 + t211) + t396) - t485) * t379 + t189 * (-0.2e1 * t286 * t31 * (t1259 * t41 + t1254 + t1256 - t1258 + t213 - t217 + t236) - 0.2e1 * t285 * t379 * t471 + t541 - t28 * t546 + t31 * (0.2e1 * t1259 * t41 + 0.4e1 * t1253 + 0.2e1 * t1256 - 0.2e1 * t1258 + t317) + t550) + 0.2e1 * t31 * (-t11 * t7 * t41 + t41 * (-t349 + t350 - t231) + t353) * t32 + t190 * (t285 + 0.1e1) * (t285 - 0.1e1) * t534 - t129 + t496 + t500 + t506 + t113 + ((t567 + t103) * param.m__l2) + param.I__l7yy + 0.2e1 * t82 * t31 * t1296;
  t1307 = param.s__l6z ^ 2;
  t1310 = param.d__5 ^ 2;
  t1315 = t515 - t149 + t556 + t588 + t320 - t276 - t165 + t590 + t592 + t176 + t180 + t595;
  t1316 = -param.I__l7yy + t597 + param.I__l6yy + param.I__l7zz - param.I__l6xx + t599 - param.I__l3xx + param.I__l3yy - param.I__l4yy + param.I__l4zz + param.I__l5xx - param.I__l5zz;
  t1319 = t110 + t323 + (param.m__l4 * (t253 - t255 + t183 + t256)) + param.m__l3 * (t260 + t536) + param.m__l5 * (t89 + t91 + t92 + t138 + t96) + param.m__l6 * (-(2 * param.d__5 * param.s__l6z) + t118 + t1307 + t1310 + t612) + param.m__l7 * (t47 + t883 + t885 + t886 + t612) + t286 * (t1315 + t1316) + param.I__l6xx + param.I__l3xx + param.I__l2zz + param.I__l4yy + param.I__l5zz;
  m(2,2) = t1300 + t1319;
  t1338 = t123 + t28 * (t2 * t761 - t26) - t660 + t155 - t241 + t170 + t175 + t176 + t180 + t182 - param.I__l7yy + param.I__l7xx + t186 + param.I__l4xx - param.I__l4yy + param.I__l5yy - param.I__l5zz - param.I__l6xx + param.I__l6zz;
  t1348 = t82 * (t380 + t810 + t643 + t228 - t230 + t232);
  t1359 = t32 * t41;
  m(2,3) = t379 * (t190 * (t82 * (t289 + t28 * (t2 * t249 - t727) + t298 + t297 - t299 - t300 - t301) + t304 + t41 * (-t2 * t460 + t312 - t313 + t314 + t734) - t317) + t189 * (-t328 + t82 * (0.2e1 * t31 * t872 - t1296) + t31 * t1338 + t830) + t665 + t31 * t32 * (t490 + t768 + t366 + t367 + t369 + t178 + t368) - t217 + t791 - t374 - t376 + t236) - (t189 * (t1348 - t387 - t703 + t394 + t396) + 0.2e1 * t142 * t837 * t31 + t82 * (t31 * t468 + t418) + t31 * (t470 + t865 - t77 + t429) + t1294 * t1359 + t719 + t439 + t440 + t442) * t285;
  t1363 = t123 + t129 + t110 + t113 + t133 - t630 + t140 + param.I__l5xx - param.I__l5yy + param.I__l6yy - param.I__l6zz - param.I__l7xx + param.I__l7zz;
  t1389 = t142 * t1363 + t82 * (t28 * (t41 * t460 - t39) + t41 * (t462 + t464 + t465) + t32 * t935 * t31) + t323 + t28 * (t189 * t544 + t10 + t26 + t517) - t1359 * t351 * t31 + t189 * t969 - t33 * t353 + t609 + t165 - param.m__l7 * t981 - param.m__l6 * t983 - t176 - t180 - param.m__l5 * t985 - (t615 * param.m__l4) - param.I__l4zz - param.I__l5xx - param.I__l6yy - param.I__l7zz;
  m(2,4) = t285 * t1389 + t379 * (-0.2e1 * t142 * t189 * t991 + t82 * (t1003 * t404 + t28 * (-0.2e1 * t127 * t189 * t41 - t542) + t41 * t189 * t709 - t31 * t938) + t477 + t28 * (t41 * t949 + t1136) - t41 * t1077 + t189 * t430 - t1013 * param.m__l4 * t31);
  t1414 = t126 * t82;
  t1420 = t652 * t82 + t216;
  t1425 = t82 * t480;
  m(2,5) = t379 * (t122 * (0.2e1 * t1414 * t189 - t338) + t28 * (t1420 * t189 - t331 * t82 + t1031) + t189 * (t1425 + t861) - t82 * t67 - t1048 - t1057) - (-t387 + t28 * (t1119 * t1359 + t1114 - t702) - t189 * t32 * (t351 * t82 - t434) + t82 * t811 + t394) * t285;
  t1459 = t2 * t82;
  t1462 = -param.m__l7 * t1094;
  t1464 = -t1096 * param.m__l6;
  m(2,6) = t379 * (t28 * (t189 * (t23 * t24 * t41 + t1102) + t41 * t544 + t542) + t189 * (-t82 * t803 - (-t659 + t320 - t113 + t1095 + t1097 + param.I__l6zz + param.I__l7xx) * t41) + t2 * t424) - t285 * (t28 * (t144 * t41 + t1108 + t1109 - t39) + t1034 * t1459 + t82 * (t659 + t110 + t113 + t1462 + t1464 - param.I__l6zz - param.I__l7xx) + t857 * t2);
  t1470 = t28 * t4;
  t1471 = t1470 + param.l__4 + param.l__5;
  t1474 = t41 * param.s__l7y;
  t1476 = t24 * t28 + param.l__6 + param.s__l7z;
  t1480 = t32 * param.s__l7x;
  t1482 = t28 * t32;
  t1490 = param.s__l7x * t41;
  t1494 = t32 * param.s__l7y;
  m(2,7) = t379 * (-t7 * (t189 * (param.s__l7x * t1471 * t82 - t1474 * t1476) + t82 * t1480 - t1482 * t1474 + t1189 * t846) * param.m__l7 + t12 * (t189 * (param.s__l7y * t1471 * t82 + t1476 * t1490) + t82 * t1494 + t1482 * t1490 + t1198 * t846) * param.m__l7 + t1174 * (t1459 * t189 - t478)) - (t7 * (t189 * t32 * (param.s__l7y * t28 * t82 + t1490) + t82 * t1476 * param.s__l7y + t1470 * t1490 + t41 * t1223 + t1494 * t846) * param.m__l7 + t12 * (t189 * t32 * (param.s__l7x * t28 * t82 - t1474) + t82 * t1476 * param.s__l7x - t1470 * t1474 - t41 * t1220 + t1480 * t846) * param.m__l7 - t1174 * t407) * t285;
  m(3,1) = m(1,3);
  m(3,2) = m(2,3);
  t1537 = 0.2e1 * t28 * t192 * t2;
  t1538 = t323 + t1537 + t320 - t113 - t133 - t137 + t325 - param.I__l5xx + param.I__l5yy - param.I__l6yy + param.I__l6zz + param.I__l7xx - param.I__l7zz;
  t1540 = t63 * t24;
  t1544 = t364 * t24;
  t1545 = t2 * t1544;
  t1546 = 0.2e1 * t1545;
  t1561 = t123 - t1537 + t110 + t113 + t133 + t137 + t140 + param.I__l5xx - param.I__l5yy + param.I__l6yy - param.I__l6zz - param.I__l7xx + param.I__l7zz;
  t1563 = t28 * t1540;
  m(3,3) = t190 * (t142 * t1538 - t149 + t323 + t28 * (t10 + t517 - 0.2e1 * t1540) + t523 + t161 - t1546 + t525 + t689 - t176 + t533) + 0.2e1 * t189 * (t82 * (t762 + t28 * (t196 - t204 + t389 + t1544) + t125 - t2 * t1540 - t14 - t16 - t211) + t217 - t1254 - t1256 + t1258 - t1259 * t41 - t236) * t31 + t142 * t1561 + t149 + 0.2e1 * t1563 + t320 - t276 + t1546 + param.m__l7 * (t84 + t86 + t87 + t886 + t885 + t48 + t883) + t891 + t176 + t180 + t893 + param.I__l7xx + t895 + param.I__l5yy + param.I__l6zz + param.I__l4xx + t897 + param.I__l3zz;
  t1567 = t72 - t622;
  m(3,4) = 0.2e1 * t142 * (t1567 * t2 + t676 + t71 + t77) * t31 + t82 * (t41 * t740 + (t640 - t220 + t381 + t2 * (t55 - t618) + t228 + t645 + t232) * t189) + t41 * t212 * t189 + t31 * (-t1567 * t2 + t429 + t635 - t71 - t77) + t1014;
  m(3,5) = t31 * (0.2e1 * t122 * t1414 + t1420 * t28 + t1425 + t861) + t189 * (t323 - t129 + t110 + t113 + t1051 + t1053 + param.I__l7yy + t1055 + param.I__l5zz + param.I__l6xx);
  t1594 = -t1563 + t110 + 0.2e1 * t160 - t1545 + t1462 + t1464 - param.I__l6zz - param.I__l7xx;
  m(3,6) = t31 * (t41 * t1594 + (-0.2e1 * t42 * param.m__l7 * t28 * t44 + t7 * (-t28 * t52 - t5 * t70) + t28 * t309 - t75) * t82) - t189 * (-t220 + t7 * (t11 * t1470 - t221) + t28 * t74 + t382);
  t1617 = param.s__l7y * t7 + t348;
  t1618 = t1476 * t1617;
  t1626 = param.m__l7 * t1211 * t2 * t4 + t1174 * t28;
  m(3,7) = t31 * (t1179 * t1618 + t1216 * t82) + t1626 * t189;
  m(4,1) = m(1,4);
  m(4,2) = m(2,4);
  m(4,3) = m(3,4);
  m(4,4) = 0.2e1 * t41 * t82 * t991 + param.I__l4zz + param.I__l5xx + param.I__l6yy + param.I__l7zz + t123 - t165 + t176 + t180 + t29 + t515 - t609 + t616 + t982 + t984 + t986;
  m(4,5) = t41 * t664 + t1348;
  m(4,6) = t82 * t1594 - t41 * (t470 - t803);
  m(4,7) = param.m__l7 * t1618 * t82 - t1216 * t41;
  m(5,1) = m(1,5);
  m(5,2) = m(2,5);
  m(5,3) = m(3,5);
  m(5,4) = m(4,5);
  m(5,5) = t323 + t1537 + t110 + t113 + t1051 + t1053 + param.I__l7yy + param.I__l6xx + t1055 + param.I__l5zz;
  m(5,6) = t2 * (-t109 * t12 * t7 + t46 - t55 - t57) - t380;
  m(5,7) = t1626;
  m(6,1) = m(1,6);
  m(6,2) = m(2,6);
  m(6,3) = m(3,6);
  m(6,4) = m(4,6);
  m(6,5) = m(5,6);
  m(6,6) = t1098;
  m(6,7) = -t1617 * t5;
  m(7,1) = m(1,7);
  m(7,2) = m(2,7);
  m(7,3) = m(3,7);
  m(7,4) = m(4,7);
  m(7,5) = m(5,7);
  m(7,6) = m(6,7);
  m(7,7) = t1174;
  tmpreturn = m;