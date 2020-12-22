/*
 * controller_ballcatcher_inv_kin_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_ballcatcher_inv_kin".
 *
 * Model version              : 1.3680
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct 13 22:13:19 2020
 *
 * Target selection: TwinCAT.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "controller_ballcatcher_inv_kin.h"
#include "controller_ballcatcher_inv_kin_private.h"

/* Block parameters (default storage) */
P_controller_ballcatcher_inv_kin_T controller_ballcatcher_inv_kin_P = {
  /* Variable: optitrack_data
   * Referenced by: '<Root>/Parabola'
   */
  {
    { 3.1016510000000004, 3.089226, 3.0765890000000002, 3.063559, 3.050927,
      3.038133, 3.0255080000000003, 3.012891, 3.000238, 2.987452, 2.974803,
      2.962075, 2.94939, 2.9370510000000003, 2.924569, 2.9119620000000004,
      2.899311, 2.886867, 2.8743570000000003, 2.861788, 2.84893, 2.836316,
      2.823769, 2.811272, 2.798678, 2.7860750000000003, 2.7735480000000003,
      2.7608330000000003, 2.7482300000000004, 2.7357630000000004,
      2.7233210000000003, 2.7110510000000003, 2.698478, 2.686013,
      2.6735450000000003, 2.6611040000000004, 2.648718, 2.6360400000000004,
      2.6234580000000003, 2.610981, 2.5986100000000003, 2.586062, 2.573674,
      2.561185, 2.548762, 2.536098, 2.5237190000000003, 2.5114050000000003,
      2.499337, 2.48686, 2.474289, 2.4618320000000002, 2.449561, 2.437333,
      2.424855, 2.412424, 2.3999260000000002, 2.387655, 2.3752470000000003,
      2.362944, 2.3505030000000002, 2.3382880000000004, 2.325784, 2.313378,
      2.3012400000000004, 2.289145, 2.276783, 2.2643820000000003, 2.252084,
      2.239793, 2.227732, 2.215373, 2.2031110000000003, 2.1908480000000004,
      2.1784670000000004, 2.166135, 2.1542440000000003, 2.141998,
      2.1293990000000003, 2.1170850000000003, 2.104867, 2.09276, 2.080614,
      2.068483, 2.056306, 2.043927, 2.0317860000000003, 2.019641, 2.007369,
      1.99536, 1.98322, 1.970956, 1.958654, 1.9463679999999999,
      1.9343229999999998, 1.922238, 1.9100439999999999, 1.8976529999999998,
      1.885591, 1.8735479999999998, 1.861518, 1.8496119999999998, 1.837616,
      1.82548, 1.81342, 1.8010589999999997, 1.789103, 1.777147, 1.765096,
      1.752718, 1.740658, 1.7287289999999997, 1.716626, 1.704686, 1.692115,
      1.6801059999999999, 1.6681599999999999, 1.656191, 1.64422, 1.632546,
      1.620472, 1.608368, 1.596353, 1.5842559999999999, 1.572476, 1.560676,
      1.548433, 1.5361639999999999, 1.52424, 1.5123309999999999,
      1.5003819999999999, 1.488267, 1.4762089999999999, 1.464342,
      1.4523679999999999, 1.4406029999999999, 1.4288239999999999, 1.417036,
      1.4050019999999999, 1.392989, 1.381113, 1.369427, 1.3576329999999999,
      1.345644, 1.333288, 1.3214219999999999, 1.309634, 1.297795, 1.285927,
      1.2739639999999999, 1.262157, 1.250244, 1.238526, 1.226891, 1.215261,
      1.203282, 1.191522, 1.1795229999999999, 1.1679199999999998, 1.156236,
      1.144523, 1.1323809999999999, 1.120439, 1.1086639999999999, 1.096936,
      1.085275, 1.073453, 1.06171, 1.050018, 1.0382799999999999,
      1.0266359999999999, 1.015137, 1.003514, 0.991697, 0.979879, 0.968237,
      0.9567969999999999, 0.94512, 0.93329099999999987, 0.92137399999999992,
      0.90964699999999987, 0.89805399999999991, 0.88655099999999987, 0.874854,
      0.86321, 0.85163600000000006, 0.8400129999999999, 0.82853599999999994,
      0.817102, 0.80566699999999991, 0.79403999999999986, 0.78219899999999987,
      0.77065499999999987, 0.759336, 0.747892, 0.73637700000000006,
      0.72442999999999991, 0.712809, 0.70134799999999986, 0.689986,
      0.67853800000000009, 0.666957, 0.65535999999999994, 0.64388, 0.632493,
      0.62119600000000008, 0.609761, 0.598309, 0.58686299999999991,
      0.57542500000000008, 0.56412400000000007, 0.552961, 0.541566, 0.529596,
      0.518141, 0.50699699999999992, 0.49583000000000005, 0.48452500000000004,
      0.473196, 0.46180099999999996, 0.450514, 0.439093, 0.427839, 0.416614,
      0.40516, 0.39392900000000003, 0.38262999999999997, 0.37155299999999997,
      0.36040600000000006, 0.34935900000000003, 0.337868, 0.32642299999999996,
      0.315062, 0.30419, 0.293194, 0.28200700000000006, 0.27082, 0.259573,
      0.24842599999999998, 0.23727199999999998, 0.226088, 0.214945,
      0.20373900000000006, 0.19268000000000002, 0.18170400000000003,
      0.17077900000000001 },

    { 0.666388, 0.66316400000000009, 0.660007, 0.65634799999999993, 0.653494,
      0.650404, 0.647187, 0.644385, 0.64141500000000007, 0.63832700000000009,
      0.635505, 0.632458, 0.6295170000000001, 0.626557, 0.623529,
      0.62051600000000007, 0.61758, 0.615319, 0.612395, 0.609234, 0.605588,
      0.602679, 0.599672, 0.59674699999999992, 0.59356999999999993, 0.590686,
      0.587834, 0.584894, 0.58197199999999993, 0.57902999999999993, 0.576022,
      0.57306600000000008, 0.570201, 0.56724299999999994, 0.564996,
      0.56187999999999994, 0.55874399999999991, 0.55562899999999993,
      0.55235600000000007, 0.549356, 0.54633599999999993, 0.543301,
      0.54043599999999992, 0.53758900000000009, 0.53472800000000009,
      0.53169700000000009, 0.52872999999999992, 0.5257210000000001,
      0.52286800000000011, 0.520019, 0.517056, 0.51405600000000007,
      0.51109500000000008, 0.5085090000000001, 0.50522899999999993, 0.50227,
      0.499352, 0.49631200000000009, 0.4932939999999999, 0.49039999999999995,
      0.4874989999999999, 0.48466699999999996, 0.48179700000000003,
      0.47879200000000011, 0.4758389999999999, 0.472977, 0.470224, 0.467279,
      0.464307, 0.46121600000000007, 0.458685, 0.455419, 0.45250999999999997,
      0.44959299999999991, 0.44655700000000009, 0.4435070000000001,
      0.44062500000000004, 0.43769100000000005, 0.43486699999999989, 0.432056,
      0.42908100000000005, 0.42611200000000005, 0.423327, 0.420604, 0.417716,
      0.41480500000000009, 0.41176499999999994, 0.40881900000000004,
      0.40578099999999995, 0.40294800000000008, 0.400139, 0.39717800000000003,
      0.394207, 0.3911929999999999, 0.38837499999999991, 0.38554099999999991,
      0.38310599999999995, 0.37976199999999993, 0.37668499999999994,
      0.3737140000000001, 0.371197, 0.3687339999999999, 0.366325,
      0.36325300000000005, 0.360317, 0.35710599999999992, 0.35398299999999994,
      0.35123299999999991, 0.348344, 0.345267, 0.342546, 0.339882,
      0.33697200000000005, 0.33435799999999993, 0.33087200000000005,
      0.32783399999999996, 0.32488399999999995, 0.32221999999999995, 0.319944,
      0.31732000000000005, 0.31449100000000008, 0.31159899999999996,
      0.30837899999999996, 0.30523900000000004, 0.30252499999999993, 0.299655,
      0.29678500000000008, 0.29372899999999991, 0.29109699999999994,
      0.28831399999999996, 0.28566, 0.2826439999999999, 0.27933999999999992,
      0.27635999999999994, 0.2737480000000001, 0.27131100000000008,
      0.26886699999999997, 0.266124, 0.26321700000000003, 0.26015199999999994,
      0.25711799999999996, 0.25423700000000005, 0.25162400000000007, 0.248761,
      0.24546200000000007, 0.24283699999999997, 0.24008999999999991, 0.23746,
      0.23458500000000004, 0.23136299999999999, 0.22834099999999991,
      0.22575100000000003, 0.22337999999999991, 0.22083399999999997,
      0.21838399999999991, 0.21545900000000007, 0.21259800000000006,
      0.20944199999999991, 0.206615, 0.203859, 0.20136700000000007,
      0.1980900000000001, 0.19528199999999996, 0.19218399999999991,
      0.18988800000000006, 0.18724999999999992, 0.1841870000000001,
      0.18114399999999997, 0.17846000000000006, 0.1760219999999999,
      0.17367899999999992, 0.17120800000000003, 0.168412, 0.16552100000000003,
      0.16260999999999992, 0.15956900000000007, 0.15679700000000008,
      0.1542349999999999, 0.15139100000000005, 0.1483810000000001, 0.145702,
      0.14298600000000006, 0.14051100000000005, 0.1375869999999999,
      0.13469299999999995, 0.13186600000000004, 0.12953199999999998,
      0.12720200000000004, 0.12478999999999996, 0.12211599999999989,
      0.11925800000000009, 0.11643599999999998, 0.11334099999999991, 0.11063,
      0.107823, 0.1055060000000001, 0.10238600000000009, 0.0994250000000001,
      0.096921000000000035, 0.094672000000000089, 0.091866, 0.089018999999999959,
      0.086297999999999986, 0.083828000000000014, 0.081463000000000063,
      0.07921099999999992, 0.076208999999999971, 0.07352599999999998,
      0.070721000000000034, 0.068095000000000017, 0.065423999999999927,
      0.062861000000000056, 0.060257999999999923, 0.057404000000000011,
      0.0546549999999999, 0.051846999999999976, 0.049423999999999912,
      0.046969999999999956, 0.044370000000000021, 0.041768000000000027,
      0.0393349999999999, 0.037026, 0.034677000000000069, 0.032121000000000066,
      0.029450999999999894, 0.026628000000000096, 0.023952999999999891,
      0.021366999999999914, 0.018705999999999889, 0.016291999999999973,
      0.013587999999999933, 0.011017000000000055, 0.0084500000000000686,
      0.0058100000000000929, 0.0034849999999999604, 0.00086699999999995114,
      -0.0017120000000000468, -0.0040930000000000133, -0.0063760000000000483,
      -0.00875300000000001, -0.011102999999999974, -0.013615999999999961,
      -0.016085000000000016, -0.018727999999999967, -0.021437999999999957,
      -0.024042000000000008 },

    { 0.241954, 0.26259, 0.282635, 0.302224, 0.322213, 0.341935, 0.361117,
      0.380056, 0.399002, 0.41761, 0.436144, 0.454559, 0.47274, 0.491018,
      0.509223, 0.527034, 0.544527, 0.562166, 0.579758, 0.597046, 0.613602,
      0.630478, 0.647219, 0.663611, 0.679917, 0.695932, 0.711719, 0.727318,
      0.742735, 0.758068, 0.773446, 0.788689, 0.803635, 0.818331, 0.833069,
      0.847637, 0.862154, 0.875942, 0.889516, 0.903411, 0.917156, 0.930685,
      0.94377, 0.956757, 0.969571, 0.981972, 0.994445, 1.007023, 1.019414,
      1.031475, 1.043336, 1.055206, 1.066882, 1.078716, 1.089461, 1.100285,
      1.111322, 1.122376, 1.133158, 1.143406, 1.153544, 1.163562, 1.173213,
      1.182841, 1.192552, 1.202118, 1.211358, 1.220529, 1.229608, 1.238502,
      1.247498, 1.25555, 1.263464, 1.27161, 1.280002, 1.28807, 1.295502,
      1.303078, 1.310073, 1.317078, 1.32397, 1.330793, 1.337528, 1.344064,
      1.35051, 1.356764, 1.362979, 1.368938, 1.374375, 1.379574, 1.384937,
      1.390487, 1.396006, 1.400801, 1.40541, 1.40981, 1.414106, 1.418205,
      1.422277, 1.426325, 1.430018, 1.433664, 1.437103, 1.440843, 1.443993,
      1.447055, 1.44933, 1.451667, 1.454406, 1.457191, 1.459438, 1.461387,
      1.463139, 1.464835, 1.466061, 1.467368, 1.468722, 1.469789, 1.470577,
      1.471491, 1.472375, 1.472891, 1.473291, 1.472893, 1.472462, 1.472336,
      1.472496, 1.472122, 1.471473, 1.470479, 1.469444, 1.468202, 1.466731,
      1.465249, 1.463499, 1.461773, 1.459953, 1.458061, 1.456029, 1.453647,
      1.450722, 1.447546, 1.444695, 1.442033, 1.43921, 1.435868, 1.432148,
      1.428462, 1.424735, 1.42053, 1.416292, 1.411925, 1.407475, 1.402878,
      1.398393, 1.393653, 1.388819, 1.383258, 1.377395, 1.371688, 1.366146,
      1.360851, 1.354885, 1.348974, 1.342313, 1.335905, 1.329202, 1.322274,
      1.315218, 1.308023, 1.300894, 1.293701, 1.286316, 1.278807, 1.270951,
      1.262388, 1.253777, 1.245723, 1.237611, 1.229171, 1.220327, 1.211274,
      1.20236, 1.193147, 1.183643, 1.173946, 1.164042, 1.154182, 1.144409,
      1.134317, 1.124262, 1.11389, 1.102887, 1.091588, 1.080664, 1.069853,
      1.059081, 1.047833, 1.036067, 1.024436, 1.012816, 1.000785, 0.988558,
      0.975931, 0.963388, 0.950944, 0.938381, 0.925661, 0.912585, 0.899316,
      0.88573, 0.872057, 0.858583, 0.845083, 0.831279, 0.817236, 0.802839,
      0.788651, 0.77425, 0.759458, 0.744405, 0.729298, 0.714134, 0.699049,
      0.683783, 0.668319, 0.652615, 0.636569, 0.620326, 0.60415, 0.588245,
      0.57198, 0.555416, 0.538377, 0.521768, 0.504891, 0.487765, 0.47026,
      0.452573, 0.434923, 0.417228, 0.399556, 0.38155, 0.363448, 0.34506,
      0.326513 }
  },

  /* Variable: param_robot
   * Referenced by: '<Root>/Trajectory Generator'
   */
  {
    0,

    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    { 0.0, 0.0, 0.0 },
    7.0,
    9.81,
    0.0,
    0.1525,
    0.2075,
    0.2325,
    0.1875,
    0.2125,
    0.1875,
    0.0796,
    0.0724,
    0.013,
    0.011,
    0.062,
    6.495,
    8.807,
    2.8,
    5.283,
    1.889,
    2.32,
    0.863,
    0.0,
    -0.01439,
    0.102503,
    -1.2e-5,
    -0.06472,
    0.017804,
    -0.000208,
    0.01601,
    0.087283,
    -0.000203,
    0.098639,
    0.022478,
    -5.7e-5,
    -0.014468,
    0.062938,
    -0.000363,
    -0.016982,
    0.042269,
    0.0019040000000000003,
    -9.3e-5,
    0.018862000000000004,
    0.0690761441316632,
    0.0711085586914514,
    0.0200625854402119,
    0.0824701683534692,
    0.0164110968055191,
    0.0873510892661361,
    0.0230152941318817,
    0.0228661554143474,
    0.0554482283748983,
    0.0472789668341968,
    0.00964726804146909,
    0.0466529007761679,
    0.0138359953358589,
    0.0116859337751969,
    0.00571863785412578,
    0.00732758787216765,
    0.00477633755783711,
    0.00606797638550296,
    0.000884,
    0.000888,
    0.001105,
    160.0,
    160.0,
    160.0,
    160.0,
    100.0,
    160.0,
    160.0,

    { 160.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 160.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0 },
    0.000185,
    0.000185,
    0.00042316695312500003,
    0.000185,
    0.000185,
    0.00042316695312500003,
    0.000129,
    0.000129,
    0.0001910384375,
    0.000129,
    0.000129,
    0.0001910384375,
    7.5e-5,
    7.5e-5,
    0.0001470968,
    1.5e-5,
    1.5e-5,
    1.851125e-5,
    1.5e-5,
    1.5e-5,
    1.851125e-5,

    { 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.833074000000002,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.4709679999999998, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.473888, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.473888 },
    60000.0,
    60000.0,
    40000.0,
    40000.0,
    40000.0,
    20000.0,
    20000.0,

    { 60000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 60000.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      20000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20000.0 },

    { 320.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 320.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 176.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 176.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 110.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0 },

    { 160.0, 160.0, 88.0, 88.0, 55.0, 20.0, 20.0 },

    { 2.9670597283903604, 2.0943951023931953, 2.9670597283903604,
      2.0943951023931953, 2.9670597283903604, 2.0943951023931953,
      3.0543261909900763 },

    { -2.9670597283903604, -2.0943951023931953, -2.9670597283903604,
      -2.0943951023931953, -2.9670597283903604, -2.0943951023931953,
      -3.0543261909900763 },

    { 1.4835298641951802, 1.4835298641951802, 1.7453292519943295,
      1.3089969389957472, 2.2689280275926285, 2.3561944901923448,
      2.3561944901923448 },

    { -1.4835298641951802, -1.4835298641951802, -1.7453292519943295,
      -1.3089969389957472, -2.2689280275926285, -2.3561944901923448,
      -2.3561944901923448 }
  },

  /* Variable: positions
   * Referenced by: '<Root>/Trajectory Generator'
   */
  {
    { 0.0, 0.0, 1.332 },

    { 0.4, 0.0, 0.95 },

    { 0.4, 0.0, 0.7 },

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },

    { 1.0, 0.0, 1.0 },

    { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
      1.332, 1.0 }
  },

  /* Variable: estimator_init_struct
   * Referenced by: '<S11>/Parabola Estimator'
   */
  {
    1.0,

    { 3.1016510000000004, 0.0 },

    { 1.0, 0.0, 0.0, 1.0 },

    { 0.666388, 0.0 },

    { 1.0, 0.0, 0.0, 1.0 },

    { 0.241954, 0.0 },

    { 1.0, 0.0, 0.0, 1.0 },
    0.8,
    12772.557684885127,
    5108.865216008141,
    12578.915732383946
  },

  /* Variable: param_controller
   * Referenced by: '<Root>/Parabola'
   */
  {
    9.81,
    0.000125,

    {
      { 4.0, 4.0, 4.0, 5.0, 3.0, 2.5, 2.5 },

      { 0.015, 0.015, 0.015, 0.02, 0.01, 0.01, 0.01 }
    }
  },

  /* Variable: timing
   * Referenced by:
   *   '<Root>/Parabola'
   *   '<S11>/Parabola Estimator'
   */
  {
    0.004,
    0.000125,
    5.0e-5,
    80.0
  },

  /* Variable: filter_tau_p_slow_T_1
   * Referenced by: '<S9>/f_tau_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_tau_slow_T_1
   * Referenced by: '<S9>/f_tau_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_p_slow_T_1
   * Referenced by: '<S9>/f_theta_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_slow_T_1
   * Referenced by: '<S9>/f_theta_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: height_of_catch
   * Referenced by: '<S11>/Parabola Estimator'
   */
  0.9,

  /* Variable: sensor_torque_offset
   * Referenced by: '<S9>/Constant'
   */
  { 0.53, -0.095, -0.189, 0.07, -0.058, 0.0025, -0.12 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant21'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant19'
   */
  1.0,

  /* Computed Parameter: pd_Y0
   * Referenced by: '<S11>/pd'
   */
  0.0,

  /* Computed Parameter: pd_p_Y0
   * Referenced by: '<S11>/pd_p'
   */
  0.0,

  /* Computed Parameter: t_catch_pred_Y0
   * Referenced by: '<S11>/t_catch_pred'
   */
  0.0,

  /* Computed Parameter: use_pred_Y0
   * Referenced by: '<S11>/use_pred'
   */
  0.0,

  /* Computed Parameter: pred_update_Y0
   * Referenced by: '<S11>/pred_update'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Throw_Constant'
   */
  0.0,

  /* Expression: -0.08
   * Referenced by: '<Root>/Constant25'
   */
  -0.08,

  /* Expression: -0.1
   * Referenced by: '<Root>/Constant26'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Constant30'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant27'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant28'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant29'
   */
  0.0,

  /* Expression: 3.6
   * Referenced by: '<Root>/Constant1'
   */
  3.6,

  /* Expression: 0
   * Referenced by: '<Root>/Constant17'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant'
   */
  100.0,

  /* Expression: [0.4;0;0.7]
   * Referenced by: '<Root>/Constant4'
   */
  { 0.4, 0.0, 0.7 },

  /* Expression: 100
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Constant18'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/MotionEnableValue'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/MotionDisableValue'
   */
  0.0,

  /* Computed Parameter: RigidBodyControllerSelector_Value
   * Referenced by: '<Root>/Rigid Body Controller Selector'
   */
  2U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch7_CurrentSetting
   * Referenced by: '<Root>/Manual Switch7'
   */
  0U
};
