/*
	IreCore Database Nov 19 2015
*/

typedef struct{
	int id;
	int stat;
	int value;
} enchant_t;
typedef struct{
	int id;
	int subclass;
} item_subclass_t;
enchant_t enchant_list[] = {
	{    34,    36,    20},
	{    68,     4,     1},
	{    69,     4,     2},
	{    70,     4,     3},
	{   106,     4,     4},
	{   107,     4,     5},
	{   108,     4,     6},
	{   109,     4,     7},
	{   195,    32,    14},
	{   196,    32,    28},
	{   197,    32,    42},
	{   198,    32,    56},
	{   248,     4,     1},
	{   352,     4,     8},
	{   357,     4,     9},
	{   362,     4,    10},
	{   367,     4,    11},
	{   372,     4,    12},
	{   410,     4,    13},
	{   412,     4,    14},
	{   436,    32,    70},
	{   684,     4,    15},
	{   823,     4,     3},
	{   856,     4,     5},
	{   926,     4,     7},
	{   927,     4,     7},
	{   931,    36,     6},
	{  1043,     4,    16},
	{  1044,     4,    17},
	{  1045,     4,    18},
	{  1046,     4,    19},
	{  1047,     4,    20},
	{  1048,     4,    21},
	{  1049,     4,    22},
	{  1050,     4,    23},
	{  1051,     4,    24},
	{  1052,     4,    25},
	{  1053,     4,    26},
	{  1054,     4,    27},
	{  1055,     4,    28},
	{  1056,     4,    29},
	{  1057,     4,    30},
	{  1058,     4,    31},
	{  1059,     4,    32},
	{  1060,     4,    33},
	{  1061,     4,    34},
	{  1062,     4,    35},
	{  1063,     4,    36},
	{  1064,     4,    37},
	{  1065,     4,    38},
	{  1066,     4,    39},
	{  1067,     4,    40},
	{  1203,     4,    41},
	{  1204,     4,    42},
	{  1205,     4,    43},
	{  1206,     4,    44},
	{  1207,     4,    45},
	{  1208,     4,    46},
	{  1289,     4,     1},
	{  1290,     4,     2},
	{  1291,     4,     3},
	{  1292,     4,     4},
	{  1293,     4,     5},
	{  1294,     4,     6},
	{  1295,     4,     7},
	{  1296,     4,     8},
	{  1297,     4,     9},
	{  1298,     4,    10},
	{  1299,     4,    11},
	{  1300,     4,    12},
	{  1301,     4,    13},
	{  1302,     4,    14},
	{  1303,     4,    15},
	{  1304,     4,    16},
	{  1305,     4,    17},
	{  1306,     4,    18},
	{  1307,     4,    19},
	{  1308,     4,    20},
	{  1309,     4,    21},
	{  1310,     4,    22},
	{  1311,     4,    23},
	{  1312,     4,    24},
	{  1313,     4,    25},
	{  1314,     4,    26},
	{  1315,     4,    27},
	{  1316,     4,    28},
	{  1317,     4,    29},
	{  1318,     4,    30},
	{  1319,     4,    31},
	{  1320,     4,    32},
	{  1321,     4,    33},
	{  1322,     4,    34},
	{  1323,     4,    35},
	{  1324,     4,    36},
	{  1325,     4,    37},
	{  1326,     4,    38},
	{  1327,     4,    39},
	{  1328,     4,    40},
	{  1329,     4,    41},
	{  1330,     4,    42},
	{  1331,     4,    43},
	{  1332,     4,    44},
	{  1333,     4,    45},
	{  1334,     4,    46},
	{  1506,     4,     8},
	{  1526,     4,    10},
	{  1531,     4,    10},
	{  1532,     4,    15},
	{  1885,     4,     9},
	{  2484,     4,     5},
	{  2523,    32,    15},
	{  2543,    36,    10},
	{  2563,     4,    15},
	{  2647,     4,    12},
	{  2658,    36,     4},
	{  2668,     4,    20},
	{  2682,     4,    10},
	{  2713,    32,     9},
	{  2751,    32,    14},
	{  2767,    32,     8},
	{  2769,    32,    11},
	{  2771,    32,     8},
	{  2772,    32,    14},
	{  2773,    32,    16},
	{  2775,    32,    11},
	{  2783,    32,    14},
	{  2784,    32,    12},
	{  2785,    32,    13},
	{  2786,    32,     7},
	{  2787,    32,     8},
	{  2838,    32,     7},
	{  2839,    32,    14},
	{  2843,    32,     8},
	{  2844,    32,     8},
	{  2845,    32,    11},
	{  2850,    32,    13},
	{  2857,    32,     2},
	{  2860,    32,     3},
	{  2864,    32,     4},
	{  2873,    32,     4},
	{  2874,    32,     4},
	{  2875,    32,     3},
	{  2879,     4,     3},
	{  2880,    32,     3},
	{  2884,    32,     2},
	{  2885,    32,     2},
	{  2886,    32,     2},
	{  2887,    32,     3},
	{  2892,     4,     4},
	{  2902,    32,     2},
	{  2908,    32,     4},
	{  2909,    32,     2},
	{  2919,     4,     7},
	{  2927,     4,     4},
	{  2934,    32,    10},
	{  2935,    32,    15},
	{  2941,    32,     2},
	{  2951,    32,     4},
	{  2952,    32,     4},
	{  2955,    32,     9},
	{  2994,    32,     5},
	{  2996,    32,     5},
	{  3008,     4,    20},
	{  3010,    32,     7},
	{  3012,    32,     7},
	{  3015,     4,     2},
	{  3092,    32,     3},
	{  3094,    36,     4},
	{  3096,     4,    17},
	{  3152,    32,     2},
	{  3204,    32,     3},
	{  3205,    32,     3},
	{  3227,    32,    10},
	{  3230,     4,    10},
	{  3231,    36,    12},
	{  3234,    32,    18},
	{  3248,    36,    18},
	{  3249,    32,    16},
	{  3263,    32,     4},
	{  3267,    36,     2},
	{  3295,    36,    16},
	{  3301,    32,     3},
	{  3303,    36,     8},
	{  3308,    36,     2},
	{  3309,    36,     3},
	{  3312,     4,     4},
	{  3314,    32,     4},
	{  3316,    32,     3},
	{  3326,    32,     5},
	{  3328,    32,    14},
	{  3332,    32,    25},
	{  3351,    32,     3},
	{  3357,     4,     3},
	{  3362,    36,     3},
	{  3608,    32,    40},
	{  3765,    32,     2},
	{  3778,    36,     4},
	{  3788,    32,    12},
	{  3812,     4,    12},
	{  3823,    32,     8},
	{  3825,    36,     9},
	{  3826,    32,     9},
	{  3831,    36,    12},
	{  3858,    32,     2},
	{  3880,    32,     3},
	{  3882,    32,     4},
	{  4061,    49,    18},
	{  4065,    36,    13},
	{  4068,    36,    20},
	{  4069,    36,    11},
	{  4071,    32,    14},
	{  4075,     4,    20},
	{  4082,    36,    22},
	{  4085,    49,    15},
	{  4087,    32,    10},
	{  4089,    32,    14},
	{  4092,    32,    11},
	{  4094,    49,     9},
	{  4095,    36,    14},
	{  4100,    32,    12},
	{  4101,    32,    15},
	{  4104,    49,     9},
	{  4106,     4,    22},
	{  4107,    49,    22},
	{  4108,    36,    15},
	{  4122,    32,     9},
	{  4123,    49,     2},
	{  4126,    32,     6},
	{  4128,    36,     6},
	{  4130,    32,     4},
	{  4131,    32,     2},
	{  4132,    32,     6},
	{  4135,     4,     2},
	{  4136,     4,     4},
	{  4137,    49,     4},
	{  4138,    49,     6},
	{  4140,    36,     4},
	{  4141,    32,     4},
	{  4146,    36,     2},
	{  4151,    32,     2},
	{  4152,    32,     4},
	{  4153,    32,     6},
	{  4158,     4,     6},
	{  4160,    32,     2},
	{  4161,    32,    20},
	{  4162,    32,    30},
	{  4163,    36,     2},
	{  4164,    36,     4},
	{  4165,    36,     6},
	{  4176,    32,    44},
	{  4194,     4,    10},
	{  4201,     4,    10},
	{  4202,     4,    12},
	{  4208,     4,    12},
	{  4211,    36,     2},
	{  4247,     4,    12},
	{  4249,     4,    12},
	{  4256,     4,    15},
	{  4411,    49,    14},
	{  4415,     4,    16},
	{  4421,    32,    13},
	{  4424,    32,    11},
	{  4426,    36,    12},
	{  4427,    32,    12},
	{  4429,    49,    10},
	{  4430,    36,    24},
	{  4431,    36,    25},
	{  4432,     4,    25},
	{  4433,    49,    25},
	{  4437,    32,    55},
	{  4440,    32,    25},
	{  4701,     4,   200},
	{  4702,     4,   400},
	{  4719,     4,     5},
	{  4739,     4,     5},
	{  4742,     4,     7},
	{  4803,     4,    15},
	{  4823,     4,    19},
	{  4830,     4,     4},
	{  4833,    32,     4},
	{  4834,    49,     4},
	{  4835,    32,     4},
	{  4836,    36,     4},
	{  4837,    36,     4},
	{  4838,    32,     4},
	{  4839,    32,     4},
	{  4840,    32,     4},
	{  4843,    32,     8},
	{  4844,    32,     8},
	{  4845,    36,     8},
	{  4846,    36,     8},
	{  4847,    32,     8},
	{  4849,    49,     8},
	{  4850,    32,     8},
	{  4852,    32,     8},
	{  4853,     4,     8},
	{  4855,    32,    11},
	{  4856,    32,    11},
	{  4857,    36,    11},
	{  4858,    36,    11},
	{  4859,    32,    11},
	{  4861,    49,    11},
	{  4862,    32,    11},
	{  4866,    32,    11},
	{  4868,     4,    11},
	{  4872,     4,    11},
	{  4881,     4,    18},
	{  4885,     4,    19},
	{  4888,     4,    18},
	{  4907,     4,    12},
	{  4911,     4,    20},
	{  4913,     4,    20},
	{  4935,     4,     6},
	{  4992,     4,    11},
	{  5043,    32,     4},
	{  5058,    36,    14},
	{  5060,    49,    10},
	{  5080,    49,    12},
	{  5081,    49,    12},
	{  5094,    36,     8},
	{  5096,    49,     6},
	{  5100,    49,     7},
	{  5101,    49,     7},
	{  5104,    32,     3},
	{  5105,    36,     9},
	{  5116,    36,     6},
	{  5162,     4,     4},
	{  5179,    32,     4},
	{  5181,    32,     4},
	{  5185,    32,     4},
	{  5187,    32,     4},
	{  5188,    32,     8},
	{  5190,    32,     2},
	{  5192,    32,     3},
	{  5196,    32,     4},
	{  5197,    32,     2},
	{  5211,    32,     4},
	{  5212,    32,     2},
	{  5213,    32,     4},
	{  5214,    32,     2},
	{  5215,    32,     3},
	{  5221,     4,     3},
	{  5222,    32,     3},
	{  5223,    32,     2},
	{  5228,    32,     2},
	{  5229,    32,     2},
	{  5230,    32,     3},
	{  5235,     4,     4},
	{  5236,     4,     2},
	{  5241,    32,     2},
	{  5243,    32,     2},
	{  5246,     4,     4},
	{  5247,     4,     2},
	{  5250,     4,     8},
	{  5253,     4,     2},
	{  5254,    36,     2},
	{  5264,    32,     2},
	{  5265,    32,     2},
	{  5266,    36,     4},
	{  5267,    36,     6},
	{  5281,    32,   100},
	{  5284,    32,    30},
	{  5285,    32,    40},
	{  5292,    36,    40},
	{  5293,    49,    40},
	{  5294,    59,    40},
	{  5295,    40,    40},
	{  5297,    36,    30},
	{  5298,    36,   100},
	{  5299,    49,    30},
	{  5300,    49,   100},
	{  5301,    59,    30},
	{  5302,    59,   100},
	{  5303,    40,    30},
	{  5304,    40,   100},
	{  5310,    32,   100},
	{  5311,    36,   100},
	{  5312,    49,   100},
	{  5313,    59,   100},
	{  5314,    40,   100},
	{  5317,    32,    75},
	{  5318,    36,    75},
	{  5319,    49,    75},
	{  5320,    59,    75},
	{  5321,    40,    75},
	{  5324,    32,    50},
	{  5325,    36,    50},
	{  5326,    49,    50},
	{  5327,    59,    50},
	{  5328,    40,    50},
	{     0,     0,     0},
};

enchant_t gem_list[] = {
	{ 23095,     4,     6},
	{ 23098,     4,     3},
	{ 23101,    32,     6},
	{ 23103,    32,     6},
	{ 23111,     4,     3},
	{ 23114,    32,    12},
	{ 23116,    32,    12},
	{ 24027,     4,     8},
	{ 24048,    32,    16},
	{ 24051,    32,    16},
	{ 24054,     4,     4},
	{ 24058,     4,     4},
	{ 24066,    32,     8},
	{ 25890,    32,    28},
	{ 25894,    32,    24},
	{ 25895,    32,    24},
	{ 28119,    32,    10},
	{ 28120,    32,    10},
	{ 28290,    32,    12},
	{ 28458,     4,     4},
	{ 28467,    32,     8},
	{ 28468,    32,     8},
	{ 28469,    32,     8},
	{ 28556,    32,    10},
	{ 30546,     4,     5},
	{ 30548,    32,    10},
	{ 30550,    32,    10},
	{ 30559,     4,     5},
	{ 30560,    32,     5},
	{ 30565,    32,     5},
	{ 30571,     4,     8},
	{ 30584,     4,     5},
	{ 30587,     4,     5},
	{ 30593,    32,     4},
	{ 30598,     4,     8},
	{ 30604,     4,     5},
	{ 30605,    32,    10},
	{ 30606,    32,    10},
	{ 31118,     4,     5},
	{ 31860,    32,    12},
	{ 31861,    32,    16},
	{ 31866,    32,     6},
	{ 32193,     4,    10},
	{ 32205,    32,    20},
	{ 32206,    32,    10},
	{ 32207,    32,    20},
	{ 32210,    32,    20},
	{ 32211,     4,     5},
	{ 32217,     4,     5},
	{ 32224,    32,    10},
	{ 32639,    32,     4},
	{ 32640,    32,    12},
	{ 33140,    32,    24},
	{ 33141,    32,    24},
	{ 33142,    32,    24},
	{ 33143,    32,    24},
	{ 34220,    32,    19},
	{ 35315,    36,    16},
	{ 35761,    36,    20},
	{ 38546,    32,    10},
	{ 38550,    32,    10},
	{ 39900,     4,     6},
	{ 39909,    32,    12},
	{ 39910,    36,    12},
	{ 39914,    32,    12},
	{ 39915,    32,    12},
	{ 39918,    36,    12},
	{ 39933,    32,     6},
	{ 39934,     4,     3},
	{ 39940,    36,     6},
	{ 39947,     4,     3},
	{ 39948,     4,     3},
	{ 39949,     4,     3},
	{ 39950,     4,     3},
	{ 39951,     4,     3},
	{ 39966,    36,     6},
	{ 39967,    36,     6},
	{ 39974,    32,     6},
	{ 39975,    32,     6},
	{ 39978,    36,     6},
	{ 39980,    32,     6},
	{ 39981,    32,     6},
	{ 39983,    36,     6},
	{ 39985,    32,     6},
	{ 39986,    32,     6},
	{ 39989,    36,     6},
	{ 39990,    32,     6},
	{ 39991,    32,     6},
	{ 39992,    36,     6},
	{ 39996,     4,     8},
	{ 40002,    32,    16},
	{ 40003,    36,    16},
	{ 40013,    32,    16},
	{ 40014,    32,    16},
	{ 40017,    36,    16},
	{ 40022,     4,     4},
	{ 40033,    32,     8},
	{ 40034,    36,     8},
	{ 40037,     4,     4},
	{ 40038,     4,     4},
	{ 40039,     4,     4},
	{ 40040,     4,     4},
	{ 40041,     4,     4},
	{ 40058,    36,     8},
	{ 40059,    36,     8},
	{ 40086,    32,     8},
	{ 40088,    32,     8},
	{ 40091,    36,     8},
	{ 40095,    32,     8},
	{ 40096,    32,     8},
	{ 40098,    32,     8},
	{ 40099,    32,     8},
	{ 40100,    32,     8},
	{ 40101,    32,     8},
	{ 40104,    36,     8},
	{ 40105,    36,     8},
	{ 40106,    36,     8},
	{ 40111,     4,    10},
	{ 40117,    32,    20},
	{ 40118,    36,    20},
	{ 40124,    32,    20},
	{ 40125,    32,    20},
	{ 40128,    36,    20},
	{ 40129,     4,     5},
	{ 40140,    32,    10},
	{ 40141,    36,    10},
	{ 40142,     4,     5},
	{ 40143,     4,     5},
	{ 40144,     4,     5},
	{ 40145,     4,     5},
	{ 40146,     4,     5},
	{ 40162,    36,    10},
	{ 40163,    36,    10},
	{ 40165,    32,    10},
	{ 40166,    32,    10},
	{ 40169,    36,    10},
	{ 40171,    32,    10},
	{ 40172,    32,    10},
	{ 40174,    36,    10},
	{ 40176,    32,    10},
	{ 40177,    32,    10},
	{ 40179,    36,     5},
	{ 40180,    32,    10},
	{ 40181,    32,    10},
	{ 40182,    36,    10},
	{ 41285,    32,    21},
	{ 41307,    32,    25},
	{ 41335,    32,    21},
	{ 41339,    32,    21},
	{ 41379,    32,    21},
	{ 41381,    32,    21},
	{ 41385,    36,    21},
	{ 41389,    32,    21},
	{ 41432,     4,     7},
	{ 41436,    32,    14},
	{ 41437,    36,    14},
	{ 41446,    36,    14},
	{ 41447,    32,    14},
	{ 41448,    32,    14},
	{ 41453,    36,     7},
	{ 41456,    32,     7},
	{ 41461,     4,     4},
	{ 41465,    36,     7},
	{ 41466,    36,     7},
	{ 41467,    36,     7},
	{ 41468,    32,     7},
	{ 41469,    32,     7},
	{ 41470,    32,     7},
	{ 41472,    32,     7},
	{ 41474,    36,     7},
	{ 41475,    32,     7},
	{ 41477,    32,     7},
	{ 41478,    32,     7},
	{ 41481,    32,     7},
	{ 41482,    36,     7},
	{ 41483,     4,     4},
	{ 41488,     4,     4},
	{ 41489,     4,     4},
	{ 41492,     4,     4},
	{ 41498,    36,     7},
	{ 41499,     4,     4},
	{ 42142,     4,    10},
	{ 42149,    32,    20},
	{ 42150,    36,    20},
	{ 42153,    32,    20},
	{ 42154,    36,    20},
	{ 42156,    32,    20},
	{ 44076,    32,     9},
	{ 44081,    32,     9},
	{ 44082,    32,     9},
	{ 44087,    32,     9},
	{ 45862,     4,    10},
	{ 45987,    32,    20},
	{ 52081,     4,     6},
	{ 52085,    36,    12},
	{ 52089,    32,    12},
	{ 52091,    32,    12},
	{ 52093,    36,    12},
	{ 52094,    49,    12},
	{ 52095,     4,     3},
	{ 52099,    36,     6},
	{ 52101,     4,     3},
	{ 52105,    36,     6},
	{ 52107,    36,     6},
	{ 52108,     4,     3},
	{ 52111,     4,     3},
	{ 52114,     4,     3},
	{ 52118,    36,     6},
	{ 52121,    32,     6},
	{ 52122,    32,    12},
	{ 52124,    36,     6},
	{ 52125,    36,     6},
	{ 52126,    49,     6},
	{ 52128,    32,     6},
	{ 52129,    32,     7},
	{ 52131,    49,     7},
	{ 52132,    36,     7},
	{ 52133,    36,     7},
	{ 52135,    32,    20},
	{ 52136,    32,     7},
	{ 52139,    36,     7},
	{ 52143,     4,     4},
	{ 52146,     4,     4},
	{ 52149,     4,     4},
	{ 52150,    36,     7},
	{ 52152,    36,     7},
	{ 52156,     4,     4},
	{ 52158,    36,     7},
	{ 52162,     4,     4},
	{ 52163,    49,    14},
	{ 52164,    36,    14},
	{ 52166,    32,    14},
	{ 52168,    32,    14},
	{ 52172,    36,    14},
	{ 52176,     4,     7},
	{ 52203,    36,     8},
	{ 52206,     4,     8},
	{ 52213,     4,     4},
	{ 52214,     4,     4},
	{ 52218,    36,     8},
	{ 52219,    49,    16},
	{ 52221,    36,     8},
	{ 52222,     4,     4},
	{ 52223,    32,     8},
	{ 52224,    36,     8},
	{ 52225,    36,     8},
	{ 52228,    32,    16},
	{ 52230,    36,    16},
	{ 52231,    49,     8},
	{ 52232,    36,    16},
	{ 52235,    32,    16},
	{ 52237,    32,     8},
	{ 52240,     4,     4},
	{ 52241,    32,    16},
	{ 52243,     4,     4},
	{ 52249,    36,     8},
	{ 52255,     4,     8},
	{ 52260,    36,    16},
	{ 52264,    32,    16},
	{ 52266,    32,    16},
	{ 52268,    36,    16},
	{ 52269,    49,    16},
	{ 52289,    49,    22},
	{ 52291,    32,    22},
	{ 52298,    32,    22},
	{ 52300,    32,    22},
	{ 52301,    32,    22},
	{ 54616,     4,    50},
	{ 59478,    32,    42},
	{ 59479,    36,    42},
	{ 59480,    49,    42},
	{ 59489,    36,    42},
	{ 59493,    32,    42},
	{ 63696,     4,     5},
	{ 63697,     4,    15},
	{ 68358,     4,     4},
	{ 68779,     4,    11},
	{ 71817,    32,    20},
	{ 71823,    32,    20},
	{ 71824,    36,    10},
	{ 71825,    49,    10},
	{ 71826,    49,    10},
	{ 71827,    49,    10},
	{ 71828,    32,    10},
	{ 71831,    32,    10},
	{ 71832,    36,    10},
	{ 71833,    36,    10},
	{ 71834,    32,    10},
	{ 71836,    36,    10},
	{ 71837,    32,    10},
	{ 71838,    49,    10},
	{ 71841,    36,    10},
	{ 71843,     4,     5},
	{ 71845,    36,    10},
	{ 71847,     4,     5},
	{ 71849,    36,    10},
	{ 71851,     4,     5},
	{ 71853,    36,    10},
	{ 71856,     4,     5},
	{ 71858,    36,    10},
	{ 71861,     4,     5},
	{ 71863,    36,    10},
	{ 71866,     4,     5},
	{ 71870,    36,    10},
	{ 71873,     4,     5},
	{ 71874,    32,    20},
	{ 71876,    36,    20},
	{ 71877,    49,    20},
	{ 71880,    36,    20},
	{ 71883,     4,    10},
	{ 76502,    32,    16},
	{ 76508,    32,    16},
	{ 76509,    36,     8},
	{ 76510,    32,     8},
	{ 76513,    32,     8},
	{ 76517,    32,     8},
	{ 76518,    36,     8},
	{ 76519,    36,     8},
	{ 76520,    32,     8},
	{ 76522,    36,     8},
	{ 76523,    32,     8},
	{ 76524,    49,     8},
	{ 76527,    36,     8},
	{ 76529,     4,     4},
	{ 76531,    36,     8},
	{ 76533,     4,     4},
	{ 76535,    36,    16},
	{ 76537,     4,     4},
	{ 76539,    36,     8},
	{ 76542,     4,     4},
	{ 76544,    36,     8},
	{ 76547,     4,     4},
	{ 76549,    36,     8},
	{ 76552,     4,     4},
	{ 76556,    36,     8},
	{ 76559,     4,     4},
	{ 76561,    36,    16},
	{ 76564,     4,     8},
	{ 76565,    32,    16},
	{ 76567,    36,    16},
	{ 76568,    49,    16},
	{ 76570,    32,    20},
	{ 76575,    32,    20},
	{ 76576,    36,    10},
	{ 76577,    32,    10},
	{ 76580,    32,    10},
	{ 76583,    32,    10},
	{ 76584,    36,    10},
	{ 76585,    36,    10},
	{ 76586,    32,    10},
	{ 76588,    36,    10},
	{ 76589,    32,    10},
	{ 76590,    49,    10},
	{ 76595,     4,     5},
	{ 76597,    36,    10},
	{ 76599,     4,     5},
	{ 76601,    36,    20},
	{ 76603,     4,     5},
	{ 76605,    36,    10},
	{ 76608,     4,     5},
	{ 76610,    36,    10},
	{ 76613,     4,     5},
	{ 76615,    36,    10},
	{ 76618,     4,     5},
	{ 76622,    36,    10},
	{ 76625,     4,     5},
	{ 76627,    36,    20},
	{ 76630,     4,    10},
	{ 76631,    32,    20},
	{ 76633,    36,    20},
	{ 76634,    49,    20},
	{ 76636,    32,    20},
	{ 76641,    32,    10},
	{ 76642,    36,    10},
	{ 76643,    32,    10},
	{ 76646,    32,    10},
	{ 76649,    32,    10},
	{ 76650,    36,    10},
	{ 76651,    36,    10},
	{ 76652,    32,    10},
	{ 76654,    36,    10},
	{ 76655,    32,    10},
	{ 76656,    49,    10},
	{ 76659,    36,    10},
	{ 76661,     4,     5},
	{ 76663,    36,    10},
	{ 76665,     4,     5},
	{ 76667,    36,    20},
	{ 76669,     4,     5},
	{ 76671,    36,    10},
	{ 76674,     4,     5},
	{ 76676,    36,    10},
	{ 76679,     4,     5},
	{ 76681,    36,    10},
	{ 76684,     4,     5},
	{ 76688,    36,    10},
	{ 76691,     4,     5},
	{ 76693,    36,    20},
	{ 76696,     4,    10},
	{ 76697,    32,    20},
	{ 76699,    36,    20},
	{ 76700,    49,    20},
	{ 76886,     4,    14},
	{ 76887,    49,    27},
	{ 76890,    32,    27},
	{ 76892,    32,    27},
	{ 76893,    32,    27},
	{ 77130,    32,    10},
	{ 77131,    49,    10},
	{ 77136,     4,     5},
	{ 77137,    36,    10},
	{ 77141,    36,    10},
	{ 77154,    32,    10},
	{ 77541,    32,    38},
	{ 77542,    36,    38},
	{ 77543,    36,    38},
	{ 77545,    32,    38},
	{ 77547,    49,    38},
	{ 83141,     4,    10},
	{ 83142,    36,    20},
	{ 83143,    49,    20},
	{ 83144,    32,    20},
	{ 83146,    32,    20},
	{ 83147,    36,    20},
	{ 88911,    32,    12},
	{ 88913,    36,    12},
	{ 88914,    36,    12},
	{ 88915,    32,    12},
	{ 88916,    36,    12},
	{ 88918,    32,    12},
	{ 88919,    32,    12},
	{ 88920,    49,    12},
	{ 88921,    32,    12},
	{ 88923,    32,    12},
	{ 88924,    36,    12},
	{ 88932,     4,     6},
	{ 88933,    36,    12},
	{ 88936,     4,     6},
	{ 88938,     4,     6},
	{ 88939,    36,    12},
	{ 88944,    36,    12},
	{ 88945,     4,     6},
	{ 88946,     4,     6},
	{ 88949,    36,    12},
	{ 88950,    36,    24},
	{ 88952,    36,    12},
	{ 88954,     4,     6},
	{ 88956,    36,    12},
	{ 88961,     4,     6},
	{ 89674,     4,     5},
	{ 89675,     4,     4},
	{ 89676,     4,     5},
	{ 89677,     4,     6},
	{ 93404,     4,     5},
	{ 93408,     4,     5},
	{ 93705,    32,    10},
	{ 93706,    32,     8},
	{ 93707,    32,    10},
	{ 93708,    32,    12},
	{ 95346,    32,    20},
	{ 95347,    32,    20},
	{ 97311,    36,    20},
	{ 97312,    36,    10},
	{ 97939,     4,     5},
	{ 98025,    32,    16},
	{ 98026,    32,    16},
	{ 98027,    36,     8},
	{ 98028,    36,     8},
	{ 98088,    49,    16},
	{ 98089,    36,     8},
	{ 98090,    32,    16},
	{115803,    32,    35},
	{115804,    36,    35},
	{115805,    49,    35},
	{115806,    59,    35},
	{115807,    40,    35},
	{115809,    32,    50},
	{115811,    36,    50},
	{115812,    49,    50},
	{115813,    59,    50},
	{115814,    40,    50},
	{127414,    32,    50},
	{127415,    36,    50},
	{127416,    49,    50},
	{127760,    32,    75},
	{127761,    36,    75},
	{127762,    49,    75},
	{127763,    59,    75},
	{127764,    40,    75},
	{     0,     0,     0},
};

int plate_list[] = {
	  7936,// Ornate Mithril Boots
	 13731,// [PH] Brilliant Dawn Gauntlets
	 13737,// [PH] Shining Dawn Gauntlets
	 13743,// [PH] Plate Bracers of the Brilliant Dawn
	 13744,// [PH] Plate Bracers of the Rising Dawn
	 13745,// [PH] Plate Bracers of the Shining Dawn
	 13771,// [PH] Plate Chestguard of the Brilliant Dawn
	 13772,// [PH] Plate Chestguard of the Rising Dawn
	 13773,// [PH] Plate Chestguard of the Shining Dawn
	 13783,// [PH] Plate Leggings of the Brilliant Dawn
	 13784,// [PH] Plate Leggings of the Rising Dawn
	 13785,// [PH] Plate Leggings of the Shining Dawn
	 13797,// [PH] Shining Dawn Helm
	 13807,// [PH] Plate Boots of the Brilliant Dawn
	 13808,// [PH] Plate Boots of the Rising Dawn
	 13809,// [PH] Plate Boots of the Shining Dawn
	 14554,// Cloudkeeper Legplates
	 22416,// Dreadnaught Breastplate
	 22425,// Redemption Tunic
	 23072,// Fists of the Unrelenting
	 23363,// Titanic Breastplate
	 23482,// Fel Iron Plate Gloves
	 23484,// Fel Iron Plate Belt
	 23487,// Fel Iron Plate Boots
	 23488,// Fel Iron Plate Pants
	 23489,// Fel Iron Breastplate
	 23506,// Adamantite Plate Bracers
	 23507,// Adamantite Breastplate
	 23508,// Adamantite Plate Gloves
	 23509,// Enchanted Adamantite Breastplate
	 23510,// Enchanted Adamantite Belt
	 23511,// Enchanted Adamantite Boots
	 23512,// Enchanted Adamantite Leggings
	 23513,// Flamebane Breastplate
	 23514,// Flamebane Gloves
	 23515,// Flamebane Bracers
	 23516,// Flamebane Helm
	 23517,// Felsteel Gloves
	 23518,// Felsteel Leggings
	 23519,// Felsteel Helm
	 23520,// Ragesteel Gloves
	 23521,// Ragesteel Helm
	 23522,// Ragesteel Breastplate
	 23523,// Khorium Pants
	 23524,// Khorium Belt
	 23525,// Khorium Boots
	 23532,// Gauntlets of the Iron Tower
	 23533,// Steelgrip Gauntlets
	 23535,// Helm of the Stalwart Defender
	 23536,// Oathkeeper's Helm
	 23537,// Black Felsteel Bracers
	 23538,// Bracers of the Green Fortress
	 23539,// Blessed Bracers
	 24363,// Unscarred Breastplate
	 24364,// Azureplate Greaves
	 24456,// Greaves of the Iron Guardian
	 24457,// Truth Bearer Shoulderguards
	 24458,// Studded Girdle of Virtue
	 24463,// Pauldrons of Brute Force
	 24544,// Gladiator's Plate Chestpiece
	 24545,// Gladiator's Plate Helm
	 24546,// Gladiator's Plate Shoulders
	 24547,// Gladiator's Plate Legguards
	 24549,// Gladiator's Plate Gauntlets
	 24942,// Bloodscale Belt
	 24943,// Bloodscale Sabatons
	 24944,// Bloodscale Breastplate
	 24945,// Bloodscale Gauntlets
	 24946,// Bloodscale Helm
	 24947,// Bloodscale Legguards
	 24948,// Bloodscale Pauldrons
	 24949,// Bloodscale Bracers
	 24950,// Bogslayer Belt
	 24951,// Bogslayer Sabatons
	 24952,// Bogslayer Breastplate
	 24953,// Bogslayer Gauntlets
	 24954,// Bogslayer Helm
	 24955,// Bogslayer Legplates
	 24956,// Bogslayer Pauldrons
	 24957,// Bogslayer Bracers
	 24958,// Khan'aish Girdle
	 24959,// Khan'aish Greaves
	 24960,// Khan'aish Breastplate
	 24961,// Khan'aish Gloves
	 24962,// Khan'aish Helmet
	 24963,// Khan'aish Legplates
	 24964,// Khan'aish Epaulets
	 24965,// Khan'aish Bracers
	 24966,// Talonguard Girdle
	 24967,// Talonguard Greaves
	 24968,// Talonguard Armor
	 24969,// Talonguard Gloves
	 24970,// Talonguard Helmet
	 24971,// Talonguard Legplates
	 24972,// Talonguard Epaulets
	 24973,// Talonguard Bracers
	 24974,// Reaver Girdle
	 24975,// Reaver Greaves
	 24976,// Reaver Armor
	 24977,// Reaver Gloves
	 24978,// Reaver Helmet
	 24979,// Reaver Legplates
	 24980,// Reaver Epaulets
	 24981,// Reaver Bracers
	 24982,// Boulderfist Belt
	 24983,// Boulderfist Greaves
	 24984,// Boulderfist Armor
	 24985,// Boulderfist Gloves
	 24986,// Boulderfist Helm
	 24987,// Boulderfist Legplates
	 24988,// Boulderfist Epaulets
	 24989,// Boulderfist Bracers
	 24990,// Warmaul Belt
	 24991,// Warmaul Greaves
	 24992,// Warmaul Breastplate
	 24993,// Warmaul Gloves
	 24994,// Warmaul Helmet
	 24995,// Warmaul Legplates
	 24996,// Warmaul Epaulets
	 24997,// Warmaul Vambraces
	 24998,// Bloodfist Girdle
	 24999,// Bloodfist Greaves
	 25000,// Bloodfist Breastplate
	 25001,// Bloodfist Gloves
	 25002,// Bloodfist Helmet
	 25003,// Bloodfist Legplates
	 25004,// Bloodfist Epaulets
	 25005,// Bloodfist Vambraces
	 25006,// Conqueror's Girdle
	 25007,// Conqueror's Greaves
	 25008,// Conqueror's Breastplate
	 25009,// Conqueror's Gauntlets
	 25010,// Conqueror's Helmet
	 25011,// Conqueror's Legplates
	 25012,// Conqueror's Epaulets
	 25013,// Conqueror's Vambraces
	 25014,// Shattered Hand Belt
	 25015,// Shattered Hand Sabatons
	 25016,// Shattered Hand Breastplate
	 25017,// Shattered Hand Gauntlets
	 25018,// Shattered Hand Helmet
	 25019,// Shattered Hand Legplates
	 25020,// Shattered Hand Epaulets
	 25021,// Shattered Hand Vambraces
	 25022,// Warlord's Iron-Girdle
	 25023,// Warlord's Sabatons
	 25024,// Warlord's Iron-Breastplate
	 25025,// Warlord's Iron-Gauntlets
	 25026,// Warlord's Iron-Helm
	 25027,// Warlord's Iron-Legplates
	 25028,// Warlord's Iron-Epaulets
	 25029,// Warlord's Iron-Vambraces
	 25478,// Defender's Gauntlets
	 25481,// Brianium Gauntlets
	 25502,// Lightbearer's Gauntlets
	 25511,// Thunderforge Leggings
	 25522,// Marshstrider's Spaulders
	 25530,// Helm of Natural Purity
	 25557,// Salvaged Ango'rosh Pauldrons
	 25566,// Judicator's Gauntlets
	 25569,// Murkblood Avenger's Chestplate
	 25573,// QR 9863 Warrior Chest
	 25585,// Murkblood Avenger's Legplates
	 25589,// Clefthoof Helm
	 25593,// Windroc Greaves
	 25597,// Vindicator's Cinch
	 25602,// Bog Walker's Belt
	 25615,// Feralfen Champion's Boots
	 25623,// Bracers of the Battle Cleric
	 25781,// Segmented Breastplate
	 25788,// Dauntless Handguards
	 25797,// Crushing Grasp
	 25819,// Breastplate of the Warbringer
	 25922,// Fearless Girdle
	 25929,// Cenarion Thicket Legplates
	 25942,// Faith Bearer's Gauntlets
	 25948,// Girdle of the Penitent
	 25956,// Nexus-Bracers of Vigor
	 25958,// Eagle Engraved Bracers
	 25967,// Eagle Crested Pauldrons
	 25977,// Helm of Lupine Ferocity
	 26464,// 68 TEST Green Warrior Belt
	 26465,// 68 TEST Green Warrior Boot
	 27408,// Hope Bearer Helm
	 27420,// Uther's Ceremonial Warboots
	 27427,// Durotan's Battle Harness
	 27447,// Bracers of Just Rewards
	 27455,// Irondrake Faceguard
	 27457,// Life Bearer's Gauntlets
	 27459,// Vambraces of Daring
	 27475,// Gauntlets of the Bold
	 27487,// Bloodlord Legplates
	 27489,// Virtue Bearer's Vambraces
	 27497,// Doomplate Gauntlets
	 27505,// Ruby Helm of the Just
	 27520,// Greathelm of the Unbreakable
	 27527,// Greaves of the Shatterer
	 27535,// Gauntlets of the Righteous
	 27539,// Justice Bearer's Pauldrons
	 27548,// Girdle of Many Blessings
	 27639,// Slayer's Waistguard
	 27644,// Avenger's Waistguard
	 27653,// Slayer's Leggings
	 27654,// Avenger's Legplates
	 27672,// Girdle of the Immovable
	 27702,// Gladiator's Lamellar Chestpiece
	 27703,// Gladiator's Lamellar Gauntlets
	 27704,// Gladiator's Lamellar Helm
	 27705,// Gladiator's Lamellar Legguards
	 27706,// Gladiator's Lamellar Shoulders
	 27715,// Circle's Stalwart Helmet
	 27718,// Aldor Defender's Legplates
	 27721,// Expedition Footgear
	 27725,// Expedition Mantle
	 27739,// Spaulders of the Righteous
	 27748,// Cassock of the Loyal
	 27755,// Girdle of Gallantry
	 27771,// Doomplate Shoulderguards
	 27788,// Bloodsworn Warboots
	 27790,// Mask of Penance
	 27798,// Gauntlets of Vindication
	 27803,// Shoulderguards of the Bold
	 27813,// Boots of the Colossus
	 27839,// Legplates of the Righteous
	 27844,// Pauldrons of Swift Retribution
	 27847,// Fanblade Pauldrons
	 27870,// Doomplate Legguards
	 27879,// Gladiator's Scaled Chestpiece
	 27880,// Gladiator's Scaled Gauntlets
	 27881,// Gladiator's Scaled Helm
	 27882,// Gladiator's Scaled Legguards
	 27883,// Gladiator's Scaled Shoulders
	 27884,// Ornate Boots of the Sanctified
	 27893,// Ornate Leggings of the Venerated
	 27897,// Breastplate of Many Graces
	 27906,// Crimsonforge Breastplate
	 27918,// Bands of Syth
	 27965,// TEST 130 Epic Paladin DPS Chest
	 27977,// Legplates of the Bold
	 27985,// Deathforge Girdle
	 28069,// Golden Cenarion Greaves
	 28167,// Sha'tari Wrought Armguards
	 28175,// Mag'hari Warlord's Legplates
	 28176,// Sha'tari Wrought Greaves
	 28180,// Myrmidon's Headdress
	 28203,// Breastplate of the Righteous
	 28205,// Breastplate of the Bold
	 28207,// Pauldrons of the Crimson Flight
	 28221,// Boots of the Watchful Heart
	 28225,// Doomplate Warhelm
	 28262,// Jade-Skull Breastplate
	 28285,// Helm of the Righteous
	 28318,// Obsidian Clodstompers
	 28324,// Gauntlets of Cruel Intention
	 28337,// Breastplate of Righteous Fury
	 28350,// Warhelm of the Bold
	 28375,// Rubium War-Girdle
	 28381,// General's Plate Bracers
	 28383,// General's Plate Greaves
	 28385,// General's Plate Belt
	 28390,// Thatia's Self-Correcting Gauntlets
	 28403,// Doomplate Chestguard
	 28483,// Breastplate of Kings
	 28484,// Bulwark of Kings
	 28485,// Bulwark of the Ancient Kings
	 28494,// Ravenguard's Greaves
	 28498,// Ravenguard's Baldric
	 28502,// Vambraces of Courage
	 28505,// Gauntlets of Renewed Hope
	 28512,// Bracers of Justice
	 28518,// Iron Gauntlets of the Maiden
	 28559,// Exorcist's Plate Helm
	 28560,// Exorcist's Lamellar Helm
	 28566,// Crimson Girdle of the Indomitable
	 28569,// Boots of Valiance
	 28593,// Eternium Greathelm
	 28597,// Panzar'Thar Breastplate
	 28608,// Ironstriders of Urgency
	 28621,// Wrynn Dynasty Greaves
	 28641,// General's Lamellar Belt
	 28642,// General's Lamellar Greaves
	 28643,// General's Lamellar Bracers
	 28644,// General's Scaled Belt
	 28645,// General's Scaled Greaves
	 28646,// General's Scaled Bracers
	 28662,// Breastplate of the Lightbinder
	 28666,// Pauldrons of the Justice-Seeker
	 28679,// Grand Marshal's Lamellar Chestpiece
	 28680,// Grand Marshal's Lamellar Gauntlets
	 28681,// Grand Marshal's Lamellar Helm
	 28683,// Grand Marshal's Lamellar Shoulders
	 28699,// Grand Marshal's Plate Chestpiece
	 28700,// Grand Marshal's Plate Gauntlets
	 28701,// Grand Marshal's Plate Helm
	 28702,// Grand Marshal's Plate Legguards
	 28703,// Grand Marshal's Plate Shoulders
	 28709,// Grand Marshal's Scaled Chestpiece
	 28710,// Grand Marshal's Scaled Gauntlets
	 28711,// Grand Marshal's Scaled Helm
	 28712,// Grand Marshal's Scaled Legguards
	 28713,// Grand Marshal's Scaled Shoulders
	 28724,// Grand Marshal's Lamellar Legguards
	 28733,// Girdle of Truth
	 28743,// Mantle of Abrahmis
	 28747,// Battlescar Boots
	 28748,// Legplates of the Innocent
	 28761,// Exorcist's Scaled Helm
	 28775,// Thundering Greathelm
	 28779,// Girdle of the Endless Pit
	 28795,// Bladespire Warbands
	 28824,// Gauntlets of Martial Perfection
	 28831,// High Warlord's Lamellar Chestpiece
	 28832,// High Warlord's Lamellar Gauntlets
	 28833,// High Warlord's Lamellar Helm
	 28834,// High Warlord's Lamellar Legguards
	 28835,// High Warlord's Lamellar Shoulders
	 28851,// High Warlord's Plate Chestpiece
	 28852,// High Warlord's Plate Gauntlets
	 28853,// High Warlord's Plate Helm
	 28854,// High Warlord's Plate Legguards
	 28855,// High Warlord's Plate Shoulders
	 28861,// High Warlord's Scaled Chestpiece
	 28862,// High Warlord's Scaled Gauntlets
	 28863,// High Warlord's Scaled Helm
	 28864,// High Warlord's Scaled Legguards
	 28865,// High Warlord's Scaled Shoulders
	 28983,// Marshal's Lamellar Belt
	 28984,// Marshal's Lamellar Bracers
	 28985,// Marshal's Lamellar Greaves
	 28995,// Marshal's Plate Belt
	 28996,// Marshal's Plate Bracers
	 28997,// Marshal's Plate Greaves
	 28998,// Marshal's Scaled Belt
	 28999,// Marshal's Scaled Bracers
	 29000,// Marshal's Scaled Greaves
	 29011,// Warbringer Greathelm
	 29012,// Warbringer Chestguard
	 29015,// Warbringer Legguards
	 29016,// Warbringer Shoulderguards
	 29017,// Warbringer Handguards
	 29019,// Warbringer Breastplate
	 29020,// Warbringer Gauntlets
	 29021,// Warbringer Battle-Helm
	 29022,// Warbringer Greaves
	 29023,// Warbringer Shoulderplates
	 29061,// Justicar Diadem
	 29062,// Justicar Chestpiece
	 29063,// Justicar Leggings
	 29064,// Justicar Pauldrons
	 29065,// Justicar Gloves
	 29066,// Justicar Chestguard
	 29067,// Justicar Handguards
	 29068,// Justicar Faceguard
	 29069,// Justicar Legguards
	 29070,// Justicar Shoulderguards
	 29071,// Justicar Breastplate
	 29072,// Justicar Gauntlets
	 29073,// Justicar Crown
	 29074,// Justicar Greaves
	 29075,// Justicar Shoulderplates
	 29127,// Vindicator's Hauberk
	 29134,// Gauntlets of the Chosen
	 29184,// Timewarden's Leggings
	 29237,// Warpath Bracers
	 29238,// Lion's Heart Girdle
	 29239,// Eaglecrest Warboots
	 29252,// Bracers of Dignity
	 29253,// Girdle of Valorous Deeds
	 29254,// Boots of the Righteous Path
	 29312,// Cover of Righteous Fury
	 29316,// Warchief's Mantle
	 29325,// Flesh Beast's Metal Greaves
	 29337,// The Exarch's Protector
	 29342,// Consortium Plated Legguards
	 29463,// Amber Bands of the Aggressor
	 29774,// Kirin'Var Defender's Chausses
	 29783,// Legguards of the Resolute Defender
	 29786,// Kirin'Var Defender's Greaves
	 29789,// Andrethan's Masterwork
	 29791,// Reinforced Heaume
	 29807,// Engraved Cattleman's Buckle
	 29812,// Blued Steel Gauntlets
	 29950,// Greaves of the Bloodwarder
	 29959,// Spiritualist's Gauntlets
	 29965,// Girdle of the Righteous Path
	 29969,// Sparky's Discarded Helmet
	 29980,// Midrealm Leggings
	 29983,// Fel-Steel Warhelm
	 29998,// Royal Gauntlets of Silvermoon
	 30002,// Boot's Boots
	 30005,// Overmaster's Shoulders
	 30016,// X-52 Technician's Helm
	 30027,// Boots of Courage Unending
	 30031,// Red Havoc Boots
	 30032,// Red Belt of Battle
	 30033,// Boots of the Protector
	 30034,// Belt of the Guardian
	 30048,// Brighthelm of Justice
	 30053,// Pauldrons of the Wardancer
	 30057,// Bracers of Eradication
	 30065,// Glowing Breastplate of Truth
	 30074,// Heavy Earthforged Breastplate
	 30081,// Warboots of Obliteration
	 30084,// Pauldrons of the Argent Sentinel
	 30096,// Girdle of the Invulnerable
	 30102,// Krakken-Heart Breastplate
	 30112,// Glorious Gauntlets of Crestfall
	 30113,// Destroyer Chestguard
	 30114,// Destroyer Handguards
	 30115,// Destroyer Greathelm
	 30116,// Destroyer Legguards
	 30117,// Destroyer Shoulderguards
	 30118,// Destroyer Breastplate
	 30119,// Destroyer Gauntlets
	 30120,// Destroyer Battle-Helm
	 30121,// Destroyer Greaves
	 30122,// Destroyer Shoulderblades
	 30123,// Crystalforge Chestguard
	 30124,// Crystalforge Handguards
	 30125,// Crystalforge Faceguard
	 30126,// Crystalforge Legguards
	 30127,// Crystalforge Shoulderguards
	 30129,// Crystalforge Breastplate
	 30130,// Crystalforge Gauntlets
	 30131,// Crystalforge War-Helm
	 30132,// Crystalforge Greaves
	 30133,// Crystalforge Shoulderbraces
	 30134,// Crystalforge Chestpiece
	 30135,// Crystalforge Gloves
	 30136,// Crystalforge Greathelm
	 30137,// Crystalforge Leggings
	 30138,// Crystalforge Pauldrons
	 30225,// Junior Technician 3rd Grade Bracers
	 30254,// Zephyrion's Belt
	 30258,// Chestplate of A'dal
	 30264,// Area 52 Engineering Gloves
	 30267,// Zaxxis Gloves
	 30270,// Scavenged Breastplate
	 30275,// Mech Tech Shoulders
	 30291,// Nexus-Guard's Pauldrons
	 30296,// Lost Chestplate of the Reverent
	 30299,// Starcaller's Plated Legguards
	 30330,// Starcaller's Plated Belt
	 30334,// Starcaller's Plated Stompers
	 30337,// Protectorate Headplate
	 30352,// Demolisher's Bracers
	 30371,// Lightwarden's Girdle
	 30375,// Gauntlets of the Vanquisher
	 30380,// Girdle of the Lost Vindicator
	 30381,// Kaylaan's Spaulders
	 30386,// Bloodguard's Greaves
	 30400,// Thadell's Bracers
	 30402,// Field Agent's Bracers
	 30486,// Merciless Gladiator's Plate Chestpiece
	 30487,// Merciless Gladiator's Plate Gauntlets
	 30488,// Merciless Gladiator's Plate Helm
	 30489,// Merciless Gladiator's Plate Legguards
	 30490,// Merciless Gladiator's Plate Shoulders
	 30491,// General's Plate Greaves Tier 2
	 30533,// Vanquisher's Legplates
	 30536,// Greaves of the Martyr
	 30641,// Boots of Elusion
	 30678,// Lurker's Girdle
	 30683,// Glider's Greaves
	 30687,// Ravager's Bracers
	 30705,// Spaulders of Slaughter
	 30731,// Faceguard of the Endless Watch
	 30740,// Ripfiend Shoulderplates
	 30741,// Topaz-Studded Battlegrips
	 30765,// Heavy Draenic Breastplate
	 30766,// Inferno Tempered Leggings
	 30767,// Inferno Tempered Gauntlets
	 30768,// Inferno Tempered Boots
	 30769,// Inferno Tempered Chestguard
	 30771,// Heavy Draenic Bracers
	 30777,// Aldor Heavy Belt
	 30861,// Furious Shackles
	 30862,// Blessed Adamantite Bracers
	 30866,// Blood-Stained Pauldrons
	 30878,// Glimmering Steel Mantle
	 30896,// Glory of the Defender
	 30897,// Girdle of Hope
	 30903,// Legguards of Endless Rage
	 30904,// Savior's Grasp
	 30915,// Belt of Seething Fury
	 30959,// Torn-Heart Family Tunic
	 30960,// Runed Sketh'lon Legplates
	 30961,// Ash-Covered Helm
	 30962,// Borak's Belt of Bravery
	 30964,// Skybreaker's Pauldrons
	 30966,// Singed Vambraces
	 30967,// The Hands of Fate
	 30968,// Earthmender's Plated Boots
	 30969,// Onslaught Gauntlets
	 30970,// Onslaught Handguards
	 30972,// Onslaught Battle-Helm
	 30974,// Onslaught Greathelm
	 30975,// Onslaught Breastplate
	 30976,// Onslaught Chestguard
	 30977,// Onslaught Greaves
	 30978,// Onslaught Legguards
	 30979,// Onslaught Shoulderblades
	 30980,// Onslaught Shoulderguards
	 30982,// Lightbringer Gauntlets
	 30983,// Lightbringer Gloves
	 30985,// Lightbringer Handguards
	 30987,// Lightbringer Faceguard
	 30988,// Lightbringer Greathelm
	 30989,// Lightbringer War-Helm
	 30990,// Lightbringer Breastplate
	 30991,// Lightbringer Chestguard
	 30992,// Lightbringer Chestpiece
	 30993,// Lightbringer Greaves
	 30994,// Lightbringer Leggings
	 30995,// Lightbringer Legguards
	 30996,// Lightbringer Pauldrons
	 30997,// Lightbringer Shoulderbraces
	 30998,// Lightbringer Shoulderguards
	 31105,// Overlord's Helmet of Second Sight
	 31115,// Uvuros Plated Spaulders
	 31151,// Girdle of Siege
	 31152,// Chestguard of Illumination
	 31155,// Drakescale Breastplate
	 31159,// Felstone Pauldrons
	 31163,// Nethersteel Handguards
	 31176,// Rockwurm Plate Handguards
	 31180,// Gauntlets of the Skullsplitter
	 31188,// Crocolisk Scale Vambraces
	 31195,// Voidplate Girdle
	 31202,// Girdle of Divine Blessing
	 31209,// Chimaerascale Legplates
	 31213,// Abyssal Plate Sabatons
	 31217,// Crimson Beholder Eye
	 31221,// Illidari Vambraces
	 31227,// Feathered Girdle
	 31232,// Grim Sabatons
	 31276,// Boots of Zealotry
	 31284,// Bracers of Recklessness
	 31298,// Legguards of the Shattered Hand
	 31315,// Goblin Girdle
	 31320,// Chestguard of Exile
	 31364,// Wildguard Breastplate
	 31367,// Wildguard Leggings
	 31368,// Wildguard Helm
	 31369,// Iceguard Breastplate
	 31370,// Iceguard Leggings
	 31371,// Iceguard Helm
	 31421,// Sentinel Armbands
	 31428,// Commander Skyshadow's Gloves
	 31432,// Explorer's Boots
	 31436,// Sylvanaar Champion's Shoulders
	 31441,// Clocktock's Jumpers
	 31445,// Last Year's "In" Belt
	 31455,// Muscle Toning Belt
	 31459,// Soul Saver's Chest Plate
	 31460,// Sha'tari Vindicator's Waistguard
	 31473,// Ogre Defiler's Handguards
	 31480,// Ogre Beater's Belt
	 31483,// Gor'drek's Pauldrons
	 31488,// Boots of the Ancient-Killer
	 31519,// Inkling's Leggings
	 31520,// Blackwing Helm
	 31521,// Expedition Defender's Shoulders
	 31534,// Whiteknuckle Gauntlets
	 31540,// Fairweather's Wristguards
	 31548,// Blackened Chestplate
	 31549,// Leonine Breastplate
	 31576,// Slatesteel Helm
	 31577,// Slatesteel Shoulders
	 31578,// Slatesteel Breastplate
	 31579,// Slatesteel Girdle
	 31580,// Slatesteel Leggings
	 31581,// Slatesteel Boots
	 31582,// Slatesteel Bracers
	 31583,// Slatesteel Gauntlets
	 31613,// Gladiator's Ornamented Chestguard
	 31614,// Gladiator's Ornamented Gloves
	 31616,// Gladiator's Ornamented Headcover
	 31618,// Gladiator's Ornamented Legplates
	 31619,// Gladiator's Ornamented Spaulders
	 31630,// Grand Marshal's Ornamented Chestplate
	 31631,// Grand Marshal's Ornamented Gloves
	 31632,// Grand Marshal's Ornamented Headguard
	 31633,// Grand Marshal's Ornamented Leggings
	 31634,// Grand Marshal's Ornamented Spaulders
	 31635,// High Warlord's Ornamented Chestplate
	 31636,// High Warlord's Ornamented Gloves
	 31637,// High Warlord's Ornamented Headguard
	 31638,// High Warlord's Ornamented Leggings
	 31639,// High Warlord's Ornamented Spaulders
	 31686,// Nether Protector's Chest
	 31690,// Belt of the Soul Saver
	 31714,// Nether Drake Wristguards
	 31765,// Redeemer's Plate
	 31787,// Stalwart Girdle
	 31794,// Sha'tari Vindicator's Legplates
	 31819,// Noble Plate Pauldrons
	 31992,// Merciless Gladiator's Lamellar Chestpiece
	 31993,// Merciless Gladiator's Lamellar Gauntlets
	 31995,// Merciless Gladiator's Lamellar Legguards
	 31996,// Merciless Gladiator's Lamellar Shoulders
	 31997,// Merciless Gladiator's Lamellar Helm
	 32020,// Merciless Gladiator's Ornamented Chestguard
	 32021,// Merciless Gladiator's Ornamented Gloves
	 32022,// Merciless Gladiator's Ornamented Headcover
	 32023,// Merciless Gladiator's Ornamented Legplates
	 32024,// Merciless Gladiator's Ornamented Spaulders
	 32039,// Merciless Gladiator's Scaled Chestpiece
	 32040,// Merciless Gladiator's Scaled Gauntlets
	 32041,// Merciless Gladiator's Scaled Helm
	 32042,// Merciless Gladiator's Scaled Legguards
	 32043,// Merciless Gladiator's Scaled Shoulders
	 32072,// Gauntlets of Dissension
	 32073,// Spaulders of Dementia
	 32083,// Faceguard of Determination
	 32084,// Helmet of the Steadfast Champion
	 32153,// Chancellor's Lamellar Chestpiece
	 32154,// Chancellor's Lamellar Gauntlets
	 32155,// Chancellor's Lamellar Helm
	 32156,// Chancellor's Lamellar Legguards
	 32157,// Chancellor's Lamellar Shoulders
	 32158,// Chancellor's Ornamented Chestplate
	 32159,// Chancellor's Ornamented Gloves
	 32160,// Chancellor's Ornamented Headguard
	 32161,// Chancellor's Ornamented Leggings
	 32162,// Chancellor's Ornamented Spaulders
	 32163,// Chancellor's Plate Chestpiece
	 32164,// Chancellor's Plate Gauntlets
	 32165,// Chancellor's Plate Helm
	 32166,// Chancellor's Plate Legguards
	 32167,// Chancellor's Plate Shoulders
	 32168,// Chancellor's Scaled Chestpiece
	 32169,// Chancellor's Scaled Gauntlets
	 32170,// Chancellor's Scaled Helm
	 32171,// Chancellor's Scaled Legguards
	 32172,// Chancellor's Scaled Shoulders
	 32232,// Eternium Shell Bracers
	 32243,// Pearl Inlaid Boots
	 32245,// Tide-Stomper's Greaves
	 32250,// Pauldrons of Abyssal Fury
	 32263,// Praetorian's Legguards
	 32267,// Boots of the Resilient
	 32268,// Myrmidon's Treads
	 32278,// Grips of Silent Justice
	 32279,// The Seeker's Wristguards
	 32280,// Gauntlets of Enforcement
	 32333,// Girdle of Stability
	 32341,// Leggings of Divine Retribution
	 32342,// Girdle of Mighty Resolve
	 32345,// Dreadboots of the Legion
	 32354,// Crown of Empowered Fate
	 32365,// Heartshatter Breastplate
	 32373,// Helm of the Illidari Shatterer
	 32401,// Shadesteel Girdle
	 32402,// Shadesteel Sabots
	 32403,// Shadesteel Bracers
	 32404,// Shadesteel Greaves
	 32414,// Tom's Legs A
	 32415,// Tom's Legs B
	 32416,// Tom's Legs C
	 32417,// Tom's Legs 1
	 32418,// Tom's Legs 2
	 32419,// Tom's Legs 3
	 32461,// Furious Gizmatic Goggles
	 32472,// Justicebringer 2000 Specs
	 32473,// Tankatronic Goggles
	 32512,// Girdle of Lordaeron's Fallen
	 32515,// Wristguards of Determination
	 32521,// Faceplate of the Impenetrable
	 32529,// Heretic's Gauntlets
	 32568,// Swiftsteel Bracers
	 32570,// Swiftsteel Shoulders
	 32571,// Dawnsteel Bracers
	 32573,// Dawnsteel Shoulders
	 32606,// Girdle of the Lightbearer
	 32608,// Pillager's Gauntlets
	 32648,// Vortex Walking Boots
	 32778,// Boots of Righteous Fortitude
	 32789,// Veteran's Lamellar Greaves
	 32793,// Veteran's Plate Greaves
	 32794,// Veteran's Scaled Greaves
	 32801,// Veteran's Lamellar Belt
	 32805,// Veteran's Plate Belt
	 32806,// Veteran's Scaled Belt
	 32813,// Veteran's Lamellar Bracers
	 32818,// Veteran's Plate Bracers
	 32819,// Veteran's Scaled Bracers
	 32866,// Ascendant's Boots
	 32871,// Horns of the Illidari
	 32982,// General's Ornamented Belt
	 32983,// General's Ornamented Bracers
	 32984,// General's Ornamented Greaves
	 32985,// Marshal's Ornamented Belt
	 32986,// Marshal's Ornamented Bracers
	 32987,// Marshal's Ornamented Greaves
	 32988,// Veteran's Ornamented Belt
	 32989,// Veteran's Ornamented Bracers
	 32990,// Veteran's Ornamented Greaves
	 33173,// Ragesteel Shoulders
	 33191,// Jungle Stompers
	 33207,// Implacable Guardian Sabatons
	 33215,// Bloodstained Elven Battlevest
	 33216,// Chestguard of Hidden Purpose
	 33279,// Iron-Tusk Girdle
	 33299,// Spaulders of the Advocate
	 33303,// Skullshatter Warboots
	 33327,// Mask of Introspection
	 33331,// Chain of Unleashed Rage
	 33404,// Ice-Bound Plate Belt
	 33405,// Ice-Bound Plate Boots
	 33406,// Ice-Bound Plate Bracers
	 33407,// Ice-Bound Plate Chestpiece
	 33408,// Ice-Bound Plate Gloves
	 33409,// Ice-Bound Plate Pants
	 33410,// Ice-Bound Plate Shoulderpads
	 33412,// Frost-Worn Plate Belt
	 33413,// Frost-Worn Plate Boots
	 33414,// Frost-Worn Plate Bracers
	 33415,// Frost-Worn Plate Chestpiece
	 33416,// Frost-Worn Plate Gloves
	 33417,// Frost-Worn Plate Pants
	 33419,// Frost-Worn Plate Shoulderpads
	 33421,// Battleworn Tuskguard
	 33435,// Frost-Worn Plate Helmet
	 33440,// Ice-Bound Plate Helmet
	 33446,// Girdle of Stromgarde's Hope
	 33473,// Chestguard of the Warlord
	 33481,// Pauldrons of Stone Resolve
	 33501,// Bloodthirster's Wargreaves
	 33512,// Furious Deathgrips
	 33513,// Eternium Rage-Shackles
	 33514,// Pauldrons of Gruesome Fate
	 33515,// Unwavering Legguards
	 33516,// Bracers of the Ancient Phalanx
	 33517,// Bonefist Gauntlets
	 33518,// High Justicar's Legplates
	 33519,// Handguards of the Templar
	 33520,// Vambraces of the Naaru
	 33522,// Chestguard of the Stoic Guardian
	 33523,// Sabatons of the Righteous Defender
	 33524,// Girdle of the Protector
	 33695,// Vengeful Gladiator's Lamellar Chestpiece
	 33696,// Vengeful Gladiator's Lamellar Gauntlets
	 33697,// Vengeful Gladiator's Lamellar Helm
	 33698,// Vengeful Gladiator's Lamellar Legguards
	 33699,// Vengeful Gladiator's Lamellar Shoulders
	 33722,// Vengeful Gladiator's Ornamented Chestguard
	 33723,// Vengeful Gladiator's Ornamented Gloves
	 33724,// Vengeful Gladiator's Ornamented Headcover
	 33725,// Vengeful Gladiator's Ornamented Legplates
	 33726,// Vengeful Gladiator's Ornamented Spaulders
	 33728,// Vengeful Gladiator's Plate Chestpiece
	 33729,// Vengeful Gladiator's Plate Gauntlets
	 33730,// Vengeful Gladiator's Plate Helm
	 33731,// Vengeful Gladiator's Plate Legguards
	 33732,// Vengeful Gladiator's Plate Shoulders
	 33749,// Vengeful Gladiator's Scaled Chestpiece
	 33750,// Vengeful Gladiator's Scaled Gauntlets
	 33751,// Vengeful Gladiator's Scaled Helm
	 33752,// Vengeful Gladiator's Scaled Legguards
	 33753,// Vengeful Gladiator's Scaled Shoulders
	 33808,// The Horseman's Helm
	 33810,// Amani Mask of Death
	 33811,// Vindicator's Plate Belt
	 33812,// Vindicator's Plate Greaves
	 33813,// Vindicator's Plate Bracers
	 33888,// Vindicator's Lamellar Belt
	 33889,// Vindicator's Lamellar Bracers
	 33890,// Vindicator's Lamellar Greaves
	 33903,// Vindicator's Ornamented Belt
	 33904,// Vindicator's Ornamented Bracers
	 33905,// Vindicator's Ornamented Greaves
	 33909,// Vindicator's Scaled Belt
	 33910,// Vindicator's Scaled Bracers
	 33911,// Vindicator's Scaled Greaves
	 34167,// Legplates of the Holy Juggernaut
	 34180,// Felfury Legplates
	 34192,// Pauldrons of Perseverance
	 34193,// Spaulders of the Thalassian Savior
	 34215,// Warharness of Reckless Fury
	 34216,// Heroic Judicator's Chestguard
	 34219,// Armor Test Item
	 34240,// Gauntlets of the Soothed Soul
	 34243,// Helm of Burning Righteousness
	 34341,// Borderland Paingrips
	 34345,// Crown of Anasterian
	 34352,// Borderland Fortress Grips
	 34354,// Mayhem Projection Goggles
	 34357,// Hard Khorium Goggles
	 34377,// Hard Khorium Battleplate
	 34378,// Hard Khorium Battlefists
	 34379,// Sunblessed Breastplate
	 34380,// Sunblessed Gauntlets
	 34381,// Felstrength Legplates
	 34382,// Judicator's Legguards
	 34388,// Pauldrons of Berserking
	 34389,// Spaulders of the Thalassian Defender
	 34394,// Breastplate of Agony's Aversion
	 34395,// Noble Judicator's Chestguard
	 34400,// Crown of Dath'Remar
	 34401,// Helm of Uther's Resolve
	 34431,// Lightbringer Bands
	 34432,// Lightbringer Bracers
	 34433,// Lightbringer Wristguards
	 34441,// Onslaught Bracers
	 34442,// Onslaught Wristguards
	 34485,// Lightbringer Girdle
	 34487,// Lightbringer Belt
	 34488,// Lightbringer Waistguard
	 34546,// Onslaught Belt
	 34547,// Onslaught Waistguard
	 34559,// Lightbringer Treads
	 34560,// Lightbringer Stompers
	 34561,// Lightbringer Boots
	 34568,// Onslaught Boots
	 34569,// Onslaught Treads
	 34601,// Shoulderplates of Everlasting Pain
	 34605,// Breastplate of Fierce Survival
	 34612,// Greaves of the Penitent Knight
	 34615,// Netherforce Chestplate
	 34700,// Gauntlets of Divine Blessings
	 34789,// Bracers of Slaughter
	 34795,// Helm of Sanctification
	 34807,// Sunstrider Warboots
	 34921,// Ecclesiastical Cuirass
	 34922,// Greaves of Pacification
	 34923,// Waistguard of Reparation
	 34939,// Chestplate of Stoicism
	 34940,// Sunguard Legplates
	 34941,// Girdle of the Fearless
	 34942,// Breastplate of Ire
	 34943,// Legplates of Unending Fury
	 34944,// Girdle of Seething Rage
	 34945,// Shattrath Protectorate's Breastplate
	 34946,// Inscribed Legplates of the Aldor
	 34947,// Blue's Greaves of the Righteous Guardian
	 35027,// Brutal Gladiator's Lamellar Chestpiece
	 35028,// Brutal Gladiator's Lamellar Gauntlets
	 35029,// Brutal Gladiator's Lamellar Helm
	 35030,// Brutal Gladiator's Lamellar Legguards
	 35031,// Brutal Gladiator's Lamellar Shoulders
	 35059,// Brutal Gladiator's Ornamented Chestguard
	 35060,// Brutal Gladiator's Ornamented Gloves
	 35061,// Brutal Gladiator's Ornamented Headcover
	 35062,// Brutal Gladiator's Ornamented Legplates
	 35063,// Brutal Gladiator's Ornamented Spaulders
	 35066,// Brutal Gladiator's Plate Chestpiece
	 35067,// Brutal Gladiator's Plate Gauntlets
	 35068,// Brutal Gladiator's Plate Helm
	 35069,// Brutal Gladiator's Plate Legguards
	 35070,// Brutal Gladiator's Plate Shoulders
	 35088,// Brutal Gladiator's Scaled Chestpiece
	 35089,// Brutal Gladiator's Scaled Gauntlets
	 35090,// Brutal Gladiator's Scaled Helm
	 35091,// Brutal Gladiator's Scaled Legguards
	 35092,// Brutal Gladiator's Scaled Shoulders
	 35140,// Guardian's Lamellar Greaves
	 35145,// Guardian's Ornamented Greaves
	 35146,// Guardian's Plate Greaves
	 35148,// Guardian's Scaled Greaves
	 35155,// Guardian's Lamellar Belt
	 35160,// Guardian's Ornamented Belt
	 35161,// Guardian's Plate Belt
	 35163,// Guardian's Scaled Belt
	 35170,// Guardian's Lamellar Bracers
	 35175,// Guardian's Ornamented Bracers
	 35176,// Guardian's Plate Bracers
	 35178,// Guardian's Scaled Bracers
	 35185,// Justicebringer 3000 Specs
	 35402,// Crusader's Ornamented Chestplate
	 35403,// Crusader's Ornamented Gloves
	 35404,// Crusader's Ornamented Headguard
	 35405,// Crusader's Ornamented Leggings
	 35406,// Crusader's Ornamented Spaulders
	 35407,// Savage Plate Chestpiece
	 35408,// Savage Plate Gauntlets
	 35409,// Savage Plate Helm
	 35410,// Savage Plate Legguards
	 35411,// Savage Plate Shoulders
	 35412,// Crusader's Scaled Chestpiece
	 35413,// Crusader's Scaled Gauntlets
	 35414,// Crusader's Scaled Helm
	 35415,// Crusader's Scaled Legguards
	 35416,// Crusader's Scaled Shoulders
	 35476,// Crusader's Ornamented Spaulders
	 35477,// Crusader's Scaled Gauntlets
	 35478,// Savage Plate Helm
	 35574,// Chestplate of the Northern Lights
	 35588,// Forlorn Breastplate of War
	 35593,// Steel Bear Trap Bracers
	 35602,// Chiseled Stalagmite Pauldrons
	 35603,// Greaves of the Blue Flight
	 35604,// Insulating Bindings
	 35608,// Crawler-Emblem Belt
	 35614,// Volazj's Sabatons
	 35637,// Muradin's Lost Greaves
	 35639,// Brighthelm of Guarding
	 35643,// Spaulders of Ichoron
	 35651,// Plate Claws of the Dragon
	 35653,// Girdle of the Mystical Prison
	 35656,// Aura Focused Gauntlets
	 35670,// Brann's Lost Mining Helmet
	 35678,// Ironshaper's Legplates
	 35822,// Scavenged Tirasian Plate
	 35835,// Antique Reinforced Legguards
	 35843,// Ramshorn-Inlaid Shoulders
	 35848,// Munificent Legguards
	 35862,// Light-Bound Chestguard
	 35866,// Master Artilleryman Boots
	 35875,// Beneficent Skullcap
	 35879,// Gold-Plated Coldsteel Girdle
	 35883,// Silversteel Gauntlets
	 35887,// Loam-Stained Greaves
	 35891,// Runeplate Helm
	 35895,// Emeraldscale Pauldrons
	 35899,// Bloodbinder's Girdle
	 35903,// Onyx Grips
	 35910,// Shaleground Bracers
	 35916,// Worgblood Berserker's Hauberk
	 35920,// Feather-Lined Shoulderpads
	 35924,// Arcanum-Bound Bracers
	 35928,// Cold-Forged Bronze Legplates
	 35934,// Ghoul-Crushing Stompers
	 36291,// Westguard Belt
	 36292,// Westguard Greaves
	 36293,// Westguard Armor
	 36294,// Westguard Gloves
	 36295,// Westguard Helm
	 36296,// Westguard Legplates
	 36297,// Westguard Epaulets
	 36298,// Westguard Bracers
	 36299,// Coldrock Girdle
	 36300,// Coldrock Sabatons
	 36301,// Coldrock Breastplate
	 36302,// Coldrock Gauntlets
	 36303,// Coldrock Helmet
	 36304,// Coldrock Legplates
	 36305,// Coldrock Pauldrons
	 36306,// Coldrock Bracers
	 36307,// Baleheim Belt
	 36308,// Baleheim Greaves
	 36309,// Baleheim Armor
	 36310,// Baleheim Gloves
	 36311,// Baleheim Helmet
	 36312,// Baleheim Legguards
	 36313,// Baleheim Epaulets
	 36314,// Baleheim Vambraces
	 36315,// Wyrmskull Girdle
	 36316,// Wyrmskull Sabatons
	 36317,// Wyrmskull Breastplate
	 36318,// Wyrmskull Gauntlets
	 36319,// Wyrmskull Helm
	 36320,// Wyrmskull Legplates
	 36321,// Wyrmskull Epaulets
	 36322,// Wyrmskull Bracers
	 36323,// Halgrind Belt
	 36324,// Halgrind Greaves
	 36325,// Halgrind Carapace
	 36326,// Halgrind Gloves
	 36327,// Halgrind Helmet
	 36328,// Halgrind Legplates
	 36329,// Halgrind Epaulets
	 36330,// Halgrind Bracers
	 36331,// Grizzlemaw Belt
	 36332,// Grizzlemaw Sabatons
	 36333,// Grizzlemaw Armor
	 36334,// Grizzlemaw Gauntlets
	 36335,// Grizzlemaw Helm
	 36336,// Grizzlemaw Legplates
	 36337,// Grizzlemaw Epaulets
	 36338,// Grizzlemaw Vambraces
	 36339,// Bloodmar Girdle
	 36340,// Bloodmar Sabatons
	 36341,// Bloodmar Breastplate
	 36342,// Bloodmar Gauntlets
	 36343,// Bloodmar Helm
	 36344,// Bloodmar Legplates
	 36345,// Bloodmar Pauldrons
	 36346,// Bloodmar Vambraces
	 36347,// Jormungar Girdle
	 36348,// Jormungar Sabatons
	 36349,// Jormungar Breastplate
	 36350,// Jormungar Gauntlets
	 36351,// Jormungar Helmet
	 36352,// Jormungar Legplates
	 36353,// Jormungar Pauldrons
	 36354,// Jormungar Bracers
	 36355,// Frostpaw Belt
	 36356,// Frostpaw Greaves
	 36357,// Frostpaw Armor
	 36358,// Frostpaw Gauntlets
	 36359,// Frostpaw Helmet
	 36360,// Frostpaw Legguards
	 36361,// Frostpaw Epaulets
	 36362,// Frostpaw Vambraces
	 36363,// Magnataur Girdle
	 36364,// Magnataur Sabatons
	 36365,// Magnataur Breastplate
	 36366,// Magnataur Gauntlets
	 36367,// Magnataur Helm
	 36368,// Magnataur Legplates
	 36369,// Magnataur Pauldrons
	 36370,// Magnataur Bracers
	 36371,// Kraken Girdle
	 36372,// Kraken Greaves
	 36373,// Kraken Breastplate
	 36374,// Kraken Gauntlets
	 36375,// Kraken Helm
	 36376,// Kraken Legplates
	 36377,// Kraken Epaulets
	 36378,// Kraken Vambraces
	 36379,// Golem Girdle
	 36380,// Golem Sabatons
	 36381,// Golem Breastplate
	 36382,// Golem Gauntlets
	 36383,// Golem Helmet
	 36384,// Golem Legplates
	 36385,// Golem Pauldrons
	 36386,// Golem Vambraces
	 36387,// Revenant Belt
	 36388,// Revenant Greaves
	 36389,// Revenant Armor
	 36390,// Revenant Gauntlets
	 36391,// Revenant Helmet
	 36392,// Revenant Legguards
	 36393,// Revenant Epaulets
	 36394,// Revenant Bracers
	 36395,// Necropolis Girdle
	 36396,// Necropolis Sabatons
	 36397,// Necropolis Breastplate
	 36398,// Necropolis Gloves
	 36399,// Necropolis Helm
	 36400,// Necropolis Legplates
	 36401,// Necropolis Epaulets
	 36402,// Necropolis Vambraces
	 36867,// HF BLUE Plate DPS Chest
	 36887,// Mightstone Pauldrons
	 36938,// Mightstone Breastplate
	 36950,// Wing Commander's Breastplate
	 36952,// Girdle of Obscuring
	 36969,// Helm of the Ley-Guardian
	 36974,// Eregos' Ornamented Chestguard
	 36977,// Bindings of the Construct
	 36995,// Fists of Loken
	 37004,// Plainwatcher Legplates
	 37009,// Moral Sabatons
	 37040,// Svala's Bloodied Shackles
	 37052,// Reanimated Armor
	 37056,// Harpooner's Striders
	 37062,// Crown of Forgotten Kings
	 37066,// Ancient Royal Legguards
	 37068,// Berserker's Sabatons
	 37082,// Slaughterhouse Sabatons
	 37088,// Spiked Metal Cilice
	 37109,// Discarded Silver Hand Spaulders
	 37115,// Crusader's Square Pauldrons
	 37135,// Arcane-Shielded Helm
	 37150,// Rift Striders
	 37152,// Girdle of Ice
	 37171,// Flame-Bathed Steel Girdle
	 37175,// Glassy Silver Bracers
	 37178,// Strategist's Belt
	 37182,// Helmet of the Constructor
	 37193,// Staggering Legplates
	 37217,// Golden Limb Bands
	 37237,// Chitin Shell Greathelm
	 37240,// Flamebeard's Bracers
	 37241,// Ancient Aligned Girdle
	 37263,// Legplates of the Oculus Guardian
	 37288,// Catalytic Bands
	 37292,// Ley-Guardian's Legguards
	 37362,// Leggings of Protective Auras
	 37363,// Gauntlets of Dragon Wrath
	 37367,// Echoing Stompers
	 37376,// Ferocious Pauldrons of the Rhino
	 37379,// Skadi's Iron Belt
	 37395,// Ornamented Plate Regalia
	 37466,// BT59 Plate Physical Chest4
	 37468,// HF28 Plate Physical Boots4
	 37469,// BT57 Plate Healer Bracer2
	 37470,// BT56 Plate Physical Shoulders4
	 37471,// Girdle of Ripped Space
	 37472,// BT49 Plate Physical Bracer
	 37473,// BT48 Plate Healer Head2
	 37474,// BT47 Plate Physical Boots3
	 37475,// Benign Crusader's Plate
	 37476,// Gorge's Breastplate of Bloodrage
	 37477,// Lost Crusader Chestplate
	 37478,// Amberplate Grips
	 37479,// Amberplate Legguards
	 37480,// Mightstone Helm
	 37481,// Chestguard of Salved Wounds
	 37482,// Mightstone Legplates
	 37483,// Seabone Heaume
	 37484,// Mendicant's Treads
	 37485,// Clam Collector Gauntlets
	 37486,// Landlocked Wristguards
	 37487,// Seabone Legplates
	 37505,// Battle Leader's Breastplate
	 37506,// Bogstrok Plate Gloves
	 37507,// Chilled Shoulderplates
	 37508,// Sinking Pauldrons
	 37509,// Seething Waistguard
	 37510,// Wristguards of Edification
	 37511,// Crucible Waistguard
	 37512,// Gauntlets of the Crimson Guardian
	 37513,// Helm of the Crimson Drakonid
	 37514,// Freed Shackles
	 37515,// Lost Crusader Waistguard
	 37516,// Chilled Greaves
	 37517,// Chilled Pauldrons
	 37518,// Amberplate Waistguard
	 37519,// Amberplate Headguard
	 37522,// Earthborn Greaves
	 37590,// Bands of Fading Light
	 37612,// Bonegrinder Breastplate
	 37618,// Greaves of Ancient Evil
	 37620,// Bracers of the Herald
	 37625,// Web Winder Gloves
	 37627,// Snake Den Spaulders
	 37632,// Mojo Frenzy Greaves
	 37633,// Ground Tremor Helm
	 37635,// Pauldrons of the Colossus
	 37645,// Horn-Tipped Gauntlets
	 37650,// Shardling Legguards
	 37658,// Sun-Emblazoned Chestplate
	 37668,// Bands of the Stoneforge
	 37670,// Sjonnir's Girdle
	 37671,// Refined Ore Gloves
	 37672,// Patina-Coated Breastplate
	 37675,// Legplates of Steel Implants
	 37682,// Bindings of Dark Will
	 37688,// Legplates of the Infinite Drakonid
	 37690,// Pauldrons of Destiny
	 37698,// Spaulders of Elder's Square
	 37699,// Festival Lane Girdle
	 37712,// Terrace Defence Boots
	 37717,// Legs of Physical Regeneration
	 37722,// Breastplate of Undeath
	 37729,// Grips of Sculptured Icicles
	 37735,// Ziggurat Imprinted Chestguard
	 37743,// Legguards of Brutalization
	 37782,// Gauntlets of the Cheerful Hearth
	 37783,// Blood-Tempered Spaulders
	 37785,// Girdle of the Howling Berserker
	 37786,// Legguards of the Forlorn Seas
	 37787,// Greathelm of the Unyielding Bull
	 37789,// Gauntlets of Disembowelment
	 37790,// Belt of Crystalline Tears
	 37792,// Agin's Crushing Carapace
	 37793,// Skullcage of Eternal Terror
	 37795,// Grips of the Valiant Champion
	 37801,// Waistguard of the Risen Knight
	 37814,// Iron Dwarf Smith Pauldrons
	 37826,// The General's Steel Girdle
	 37847,// Skywall Striders
	 37849,// Planetary Helm
	 37862,// Gauntlets of the Water Revenant
	 37874,// Gauntlets of Capture
	 37891,// Cast Iron Shackles
	 38084,// Crustacean Stompers
	 38085,// Belt of the Emerald Guardian
	 38086,// Vigilant Skullcap
	 38087,// Sea Rusted Gauntlets
	 38088,// Breastplate of Nature's Ire
	 38092,// Crystalplate Pauldrons
	 38093,// Dalaran Sentry Wristbraces
	 38094,// Dalaran Sentry Headguard
	 38095,// Legplates of the Conquered Knight
	 38096,// Crystalplate Legguards
	 38097,// Experimental Utility Belt
	 38100,// Crystalplate Gauntlets
	 38101,// Stonepath Sabatons
	 38102,// Stonepath Gauntlets
	 38103,// Petrified Bone Chestguard
	 38104,// Stonepath Helm
	 38105,// Stonepath Pauldrons
	 38106,// Petrified Bone Footguards
	 38107,// Stonepath Chestguard
	 38108,// Conscript's Ruby Waistguard
	 38109,// Wraithshimmer Legplates
	 38110,// Legplates of the Agmar Preserver
	 38111,// Wyrmbane Wristguards
	 38112,// Bark Covered Pauldrons
	 38114,// Chestplate of the Ruby Champion
	 38115,// Sabatons of the Enforcer
	 38116,// Plated Magnataur Leggings
	 38117,// Dreadtalon's Clutch
	 38118,// Bite-Proof Grips
	 38524,// Carapace of the Scarlet Commander
	 38533,// Girdle of Forceful Annihilation
	 38534,// Purity-Anointed Warbands
	 38541,// Implacable Zombie Crushers
	 39072,// Blacksoul Protector's Hauberk
	 39075,// Waywalker's Girdle
	 39076,// Golem-Rider's Greaves
	 39077,// Skull-Reshaper's Helm
	 39078,// Whispering Stompers
	 39079,// Bracers of the Chaperon
	 39080,// Grips of Flawed Temper
	 39081,// Spiritforged Helm
	 39082,// Shocksteel Shoulderguards
	 39083,// Cobalt Shoulders
	 39084,// Cobalt Helm
	 39085,// Cobalt Chestpiece
	 39086,// Cobalt Legplates
	 39087,// Cobalt Belt
	 39088,// Cobalt Boots
	 39089,// Spiritforged Legguards
	 39090,// Chestplate of Untimely Rewards
	 39091,// Blood-Spattered Spaulders
	 39092,// Thought-Purifying Protector
	 39093,// Chestguard of Expressed Fury
	 39094,// Load-Bearing Girdle
	 39095,// Hammer-Holder's Gauntlets
	 39096,// Snaptooth Legplates
	 39097,// Sabatons of Crushed Humanity
	 39098,// Rusty Cave Stompers
	 39099,// Carapace of the Fallen
	 39100,// Plated Bracelet of the Skies
	 39102,// Icewalker's Spikes
	 39104,// Hardened Bone Wrist Protectors
	 39105,// Girdle of Growing Vines
	 39108,// Bloodstained Helmet
	 39139,// Ravaging Sabatons
	 39168,// Worg-Rendering Shoulderguards
	 39172,// Bone-Polished Iceplate Shoulders
	 39174,// Legguards of Dissolved Hope
	 39175,// Leggings of Forceful Purification
	 39179,// Charged Earthlink Grips
	 39180,// Handguards of the Sanguine Gladiator
	 39188,// Chivalric Chestguard
	 39195,// Bracers of Lost Sentiments
	 39197,// Gauntlets of the Master
	 39198,// Frostblight Pauldrons
	 39228,// Web Cocoon Grips
	 39234,// Plague-Impervious Boots
	 39235,// Bone-Framed Bracers
	 39239,// Chestplate of the Risen Soldier
	 39249,// Shoulderplates of Bloodshed
	 39258,// Legplates of Inescapable Death
	 39260,// Helm of the Corrupted Mind
	 39261,// Tainted Girdle of Mending
	 39262,// Gauntlets of Combined Strength
	 39267,// Abomination Shoulderblades
	 39280,// Leggings of Innumerable Barbs
	 39293,// Blackened Legplates of Feugen
	 39298,// Waistguard of the Tutor
	 39306,// Plated Gloves of Relief
	 39345,// Girdle of the Ascended Phantom
	 39369,// Sabatons of Deathlike Gloom
	 39395,// Thane's Tainted Greathelm
	 39398,// Massive Skeletal Ribcage
	 39403,// Helm of the Unsubmissive
	 39448,// Helm of Brutal Slaughter
	 39449,// Wristguards of Titanic Vengeance
	 39450,// Bug-Smashing Pauldrons
	 39451,// Pauldrons of the Silent Mist
	 39452,// Roaming Wristguards
	 39453,// Rhino-Tail Girdle
	 39454,// Handguards of Transient Friendship
	 39455,// Cracked Nest Stabilizer
	 39457,// Zepik's Grounded Legplates
	 39458,// Cultbreaker's Chestguard
	 39459,// Preservative-Stained Gauntlets
	 39460,// Sabatons of the Rampaging Construct
	 39461,// Muck-Stained Carapace
	 39462,// Legplates of the Northern Expedition
	 39463,// Norrington's Burnished Breastplate
	 39464,// Lifegiver's Ward
	 39465,// Pathfinding Treads
	 39466,// Boots of Dominance
	 39467,// Minion Bracers
	 39471,// Gutbuster of Aldur'thar
	 39503,// Bronzed Dome Protector
	 39508,// Stonebound Chestguard
	 39534,// Pauldrons of the Lightning Revenant
	 39535,// Ionar's Girdle
	 39605,// Heroes' Dreadnaught Helmet
	 39606,// Heroes' Dreadnaught Battleplate
	 39607,// Heroes' Dreadnaught Legplates
	 39608,// Heroes' Dreadnaught Shoulderplates
	 39609,// Heroes' Dreadnaught Gauntlets
	 39610,// Heroes' Dreadnaught Greathelm
	 39611,// Heroes' Dreadnaught Breastplate
	 39612,// Heroes' Dreadnaught Legguards
	 39613,// Heroes' Dreadnaught Pauldrons
	 39617,// Heroes' Scourgeborne Battleplate
	 39618,// Heroes' Scourgeborne Gauntlets
	 39619,// Heroes' Scourgeborne Helmet
	 39620,// Heroes' Scourgeborne Legplates
	 39621,// Heroes' Scourgeborne Shoulderplates
	 39622,// Heroes' Dreadnaught Handguards
	 39623,// Heroes' Scourgeborne Chestguard
	 39624,// Heroes' Scourgeborne Handguards
	 39625,// Heroes' Scourgeborne Faceguard
	 39626,// Heroes' Scourgeborne Legguards
	 39627,// Heroes' Scourgeborne Pauldrons
	 39628,// Heroes' Redemption Headpiece
	 39629,// Heroes' Redemption Tunic
	 39630,// Heroes' Redemption Greaves
	 39631,// Heroes' Redemption Spaulders
	 39632,// Heroes' Redemption Gloves
	 39633,// Heroes' Redemption Chestpiece
	 39634,// Heroes' Redemption Gauntlets
	 39635,// Heroes' Redemption Helm
	 39636,// Heroes' Redemption Legplates
	 39637,// Heroes' Redemption Shoulderplates
	 39638,// Heroes' Redemption Breastplate
	 39639,// Heroes' Redemption Handguards
	 39640,// Heroes' Redemption Faceguard
	 39641,// Heroes' Redemption Legguards
	 39642,// Heroes' Redemption Shoulderguards
	 39680,// Vambraces of the Vengeance Bringer
	 39703,// Rescinding Grips
	 39704,// Pauldrons of Unnatural Death
	 39706,// Sabatons of Sudden Reprisal
	 39717,// Inexorable Sabatons
	 39723,// Fire-Scorched Greathelm
	 39725,// Epaulets of the Grieving Servant
	 39726,// Callous-Hearted Gauntlets
	 39729,// Bracers of the Tyrant
	 39759,// Ablative Chitin Girdle
	 39760,// Helm of Diminished Pride
	 39764,// Bindings of the Hapless Prey
	 39767,// Undiminished Battleplate
	 39778,// Bloodletter's Legplates
	 39782,// Thick Bracers of Battle
	 39790,// Gauntlets of the Altar
	 39795,// Boots of the Altar
	 39801,// Boots of the Rescuer
	 39805,// Chestplate of the Altar
	 39817,// Brazen Offender's Shoulderplates
	 39841,// Ancestral Girdle
	 39845,// Ancestral Gauntlets
	 39847,// Ancestral War Boots
	 39849,// Belt of Divine Ancestry
	 39851,// Ribbed Helm of Servitude
	 39855,// Gauntlets of the Gatherer
	 39860,// Vindicator's Bracers of Sacrifice
	 39877,// Belt of the Betrayer
	 39882,// Carved Bone Helm
	 39888,// Scourgebane Pauldrons
	 39890,// Purifier's Pantaloons
	 39891,// Brazen Offender's Helm
	 39893,// Ancestral Chestplates
	 40185,// Shoulderguards of Opportunity
	 40187,// Poignant Sabatons
	 40188,// Gauntlets of the Disobedient
	 40203,// Breastplate of Tormented Rage
	 40204,// Legguards of the Apostle
	 40206,// Iron-Spring Jumpers
	 40210,// Chestguard of Bitter Charms
	 40240,// Greaves of Turbulence
	 40241,// Girdle of Unity
	 40259,// Waistguard of Divine Grace
	 40261,// Crude Discolored Battlegrips
	 40263,// Fleshless Girdle
	 40274,// Bracers of Liberation
	 40278,// Girdle of Chivalry
	 40279,// Chestguard of the Exhausted
	 40293,// Helm of Towering Rage
	 40294,// Riveted Abomination Leggings
	 40295,// Greathelm of the Titan Protectorate
	 40297,// Sabatons of Endurance
	 40298,// Faceguard of the Succumbed
	 40306,// Bracers of the Unholy Knight
	 40307,// TEST ARMOR DEATH KNIGHT HELM
	 40316,// Gauntlets of Guiding Touch
	 40317,// Girdle of Razuvious
	 40318,// Legplates of Double Strikes
	 40320,// Faithful Steel Sabatons
	 40328,// Helm of Vital Protection
	 40330,// Bracers of Unrelenting Attack
	 40332,// Abetment Bracers
	 40334,// Burdened Shoulderplates
	 40347,// Zeliek's Gauntlets
	 40363,// Bone-Inlaid Legguards
	 40365,// Breastplate of Frozen Pain
	 40366,// Platehelm of the Great Wyrm
	 40377,// Noble Birthright Pauldrons
	 40414,// Shoulderguards of the Undaunted
	 40428,// Titan's Outlook
	 40440,// Brutal Gladiator's Dreadplate Chestpiece
	 40441,// Brutal Gladiator's Dreadplate Gauntlets
	 40442,// Brutal Gladiator's Dreadplate Helm
	 40443,// Brutal Gladiator's Dreadplate Legguards
	 40444,// Brutal Gladiator's Dreadplate Shoulders
	 40446,// Dragon Brood Legguards
	 40453,// Chestplate of the Great Aspects
	 40481,// ICECROWN TEST GOD BP
	 40511,// Focusing Energy Epaulets
	 40525,// Valorous Dreadnaught Battleplate
	 40527,// Valorous Dreadnaught Gauntlets
	 40528,// Valorous Dreadnaught Helmet
	 40529,// Valorous Dreadnaught Legplates
	 40530,// Valorous Dreadnaught Shoulderplates
	 40544,// Valorous Dreadnaught Breastplate
	 40545,// Valorous Dreadnaught Handguards
	 40546,// Valorous Dreadnaught Greathelm
	 40547,// Valorous Dreadnaught Legguards
	 40548,// Valorous Dreadnaught Pauldrons
	 40550,// Valorous Scourgeborne Battleplate
	 40552,// Valorous Scourgeborne Gauntlets
	 40554,// Valorous Scourgeborne Helmet
	 40556,// Valorous Scourgeborne Legplates
	 40557,// Valorous Scourgeborne Shoulderplates
	 40559,// Valorous Scourgeborne Chestguard
	 40563,// Valorous Scourgeborne Handguards
	 40565,// Valorous Scourgeborne Faceguard
	 40567,// Valorous Scourgeborne Legguards
	 40568,// Valorous Scourgeborne Pauldrons
	 40569,// Valorous Redemption Tunic
	 40570,// Valorous Redemption Gloves
	 40571,// Valorous Redemption Headpiece
	 40572,// Valorous Redemption Greaves
	 40573,// Valorous Redemption Spaulders
	 40574,// Valorous Redemption Chestpiece
	 40575,// Valorous Redemption Gauntlets
	 40576,// Valorous Redemption Helm
	 40577,// Valorous Redemption Legplates
	 40578,// Valorous Redemption Shoulderplates
	 40579,// Valorous Redemption Breastplate
	 40580,// Valorous Redemption Handguards
	 40581,// Valorous Redemption Faceguard
	 40583,// Valorous Redemption Legguards
	 40584,// Valorous Redemption Shoulderguards
	 40589,// Legplates of Sovereignty
	 40590,// Elevated Lair Pauldrons
	 40591,// Melancholy Sabatons
	 40592,// Boots of Healing Energies
	 40650,// LK ARENA TEST WARRIOR BRACERS 213
	 40669,// Tempered Saronite Belt
	 40671,// Tempered Saronite Boots
	 40672,// Tempered Saronite Breastplate
	 40673,// Tempered Saronite Helm
	 40674,// Tempered Saronite Legplates
	 40675,// Tempered Saronite Shoulders
	 40688,// Verdungo's Barbarian Cord
	 40689,// Waistguard of Living Iron
	 40691,// Magroth's Meditative Cincture
	 40733,// Wristbands of the Sentinel Huntress
	 40734,// Bracers of Dalaran's Parapets
	 40735,// Zartson's Jungle Vambraces
	 40742,// Bladed Steelboots
	 40743,// Kyzoc's Ground Stompers
	 40745,// Sabatons of Rapid Recovery
	 40755,// Enticing Sabatons
	 40778,// Savage Gladiator's Plate Chestpiece
	 40779,// Savage Gladiator's Dreadplate Chestpiece
	 40780,// Savage Gladiator's Scaled Chestpiece
	 40781,// Hateful Gladiator's Dreadplate Chestpiece
	 40782,// Hateful Gladiator's Scaled Chestpiece
	 40783,// Hateful Gladiator's Plate Chestpiece
	 40784,// Deadly Gladiator's Dreadplate Chestpiece
	 40785,// Deadly Gladiator's Scaled Chestpiece
	 40786,// Deadly Gladiator's Plate Chestpiece
	 40787,// Furious Gladiator's Dreadplate Chestpiece
	 40788,// Furious Gladiator's Scaled Chestpiece
	 40789,// Furious Gladiator's Plate Chestpiece
	 40790,// Relentless Gladiator's Plate Chestpiece
	 40791,// Relentless Gladiator's Dreadplate Chestpiece
	 40792,// Relentless Gladiator's Scaled Chestpiece
	 40797,// Savage Gladiator's Plate Gauntlets
	 40798,// Savage Gladiator's Scaled Gauntlets
	 40799,// Savage Gladiator's Dreadplate Gauntlets
	 40801,// Hateful Gladiator's Plate Gauntlets
	 40802,// Hateful Gladiator's Scaled Gauntlets
	 40803,// Hateful Gladiator's Dreadplate Gauntlets
	 40804,// Deadly Gladiator's Plate Gauntlets
	 40805,// Deadly Gladiator's Scaled Gauntlets
	 40806,// Deadly Gladiator's Dreadplate Gauntlets
	 40807,// Furious Gladiator's Plate Gauntlets
	 40808,// Furious Gladiator's Scaled Gauntlets
	 40809,// Furious Gladiator's Dreadplate Gauntlets
	 40810,// Relentless Gladiator's Plate Gauntlets
	 40811,// Relentless Gladiator's Dreadplate Gauntlets
	 40812,// Relentless Gladiator's Scaled Gauntlets
	 40816,// Savage Gladiator's Plate Helm
	 40817,// Savage Gladiator's Dreadplate Helm
	 40818,// Savage Gladiator's Scaled Helm
	 40819,// Hateful Gladiator's Plate Helm
	 40820,// Hateful Gladiator's Dreadplate Helm
	 40821,// Hateful Gladiator's Scaled Helm
	 40823,// Deadly Gladiator's Plate Helm
	 40824,// Deadly Gladiator's Dreadplate Helm
	 40825,// Deadly Gladiator's Scaled Helm
	 40826,// Furious Gladiator's Plate Helm
	 40827,// Furious Gladiator's Dreadplate Helm
	 40828,// Furious Gladiator's Scaled Helm
	 40829,// Relentless Gladiator's Plate Helm
	 40830,// Relentless Gladiator's Dreadplate Helm
	 40831,// Relentless Gladiator's Scaled Helm
	 40836,// Savage Gladiator's Plate Legguards
	 40837,// Savage Gladiator's Dreadplate Legguards
	 40838,// Savage Gladiator's Scaled Legguards
	 40840,// Hateful Gladiator's Plate Legguards
	 40841,// Hateful Gladiator's Dreadplate Legguards
	 40842,// Hateful Gladiator's Scaled Legguards
	 40844,// Deadly Gladiator's Plate Legguards
	 40845,// Deadly Gladiator's Dreadplate Legguards
	 40846,// Deadly Gladiator's Scaled Legguards
	 40847,// Furious Gladiator's Plate Legguards
	 40848,// Furious Gladiator's Dreadplate Legguards
	 40849,// Furious Gladiator's Scaled Legguards
	 40850,// Relentless Gladiator's Plate Legguards
	 40851,// Relentless Gladiator's Dreadplate Legguards
	 40852,// Relentless Gladiator's Scaled Legguards
	 40856,// Savage Gladiator's Plate Shoulders
	 40857,// Savage Gladiator's Dreadplate Shoulders
	 40858,// Savage Gladiator's Scaled Shoulders
	 40859,// Hateful Gladiator's Plate Shoulders
	 40860,// Hateful Gladiator's Dreadplate Shoulders
	 40861,// Hateful Gladiator's Scaled Shoulders
	 40862,// Deadly Gladiator's Plate Shoulders
	 40863,// Deadly Gladiator's Dreadplate Shoulders
	 40864,// Deadly Gladiator's Scaled Shoulders
	 40866,// Furious Gladiator's Plate Shoulders
	 40868,// Furious Gladiator's Dreadplate Shoulders
	 40869,// Furious Gladiator's Scaled Shoulders
	 40870,// Relentless Gladiator's Plate Shoulders
	 40871,// Relentless Gladiator's Dreadplate Shoulders
	 40872,// Relentless Gladiator's Scaled Shoulders
	 40877,// Hateful Gladiator's Girdle of Triumph
	 40878,// Hateful Gladiator's Greaves of Triumph
	 40879,// Deadly Gladiator's Girdle of Triumph
	 40880,// Deadly Gladiator's Greaves of Triumph
	 40881,// Furious Gladiator's Girdle of Triumph
	 40882,// Furious Gladiator's Greaves of Triumph
	 40883,// Relentless Gladiator's Girdle of Triumph
	 40884,// Relentless Gladiator's Greaves of Triumph
	 40887,// Hateful Gladiator's Bracers of Triumph
	 40888,// Deadly Gladiator's Bracers of Triumph
	 40889,// Furious Gladiator's Bracers of Triumph
	 40890,// Relentless Gladiator's Bracers of Triumph
	 40898,// Savage Gladiator's Ornamented Chestguard
	 40904,// Hateful Gladiator's Ornamented Chestguard
	 40905,// Deadly Gladiator's Ornamented Chestguard
	 40907,// Furious Gladiator's Ornamented Chestguard
	 40910,// Relentless Gladiator's Ornamented Chestguard
	 40918,// Savage Gladiator's Ornamented Gloves
	 40925,// Hateful Gladiator's Ornamented Gloves
	 40926,// Deadly Gladiator's Ornamented Gloves
	 40927,// Furious Gladiator's Ornamented Gloves
	 40928,// Relentless Gladiator's Ornamented Gloves
	 40930,// Savage Gladiator's Ornamented Headcover
	 40931,// Hateful Gladiator's Ornamented Headcover
	 40932,// Deadly Gladiator's Ornamented Headcover
	 40933,// Furious Gladiator's Ornamented Headcover
	 40934,// Relentless Gladiator's Ornamented Headcover
	 40936,// Savage Gladiator's Ornamented Legplates
	 40937,// Hateful Gladiator's Ornamented Legplates
	 40938,// Deadly Gladiator's Ornamented Legplates
	 40939,// Furious Gladiator's Ornamented Legplates
	 40940,// Relentless Gladiator's Ornamented Legplates
	 40942,// Spiked Cobalt Helm
	 40943,// Spiked Cobalt Legplates
	 40949,// Spiked Cobalt Boots
	 40950,// Spiked Cobalt Shoulders
	 40951,// Spiked Cobalt Chestpiece
	 40952,// Spiked Cobalt Gauntlets
	 40953,// Spiked Cobalt Belt
	 40954,// Spiked Cobalt Bracers
	 40955,// Horned Cobalt Helm
	 40956,// Reinforced Cobalt Shoulders
	 40957,// Reinforced Cobalt Helm
	 40958,// Reinforced Cobalt Legplates
	 40959,// Reinforced Cobalt Chestpiece
	 40960,// Savage Gladiator's Ornamented Spaulders
	 40961,// Hateful Gladiator's Ornamented Spaulders
	 40962,// Deadly Gladiator's Ornamented Spaulders
	 40963,// Furious Gladiator's Ornamented Spaulders
	 40964,// Relentless Gladiator's Ornamented Spaulders
	 40966,// Hateful Gladiator's Girdle of Salvation
	 40972,// Hateful Gladiator's Bracers of Salvation
	 40973,// Hateful Gladiator's Greaves of Salvation
	 40974,// Deadly Gladiator's Girdle of Salvation
	 40975,// Deadly Gladiator's Greaves of Salvation
	 40976,// Furious Gladiator's Girdle of Salvation
	 40977,// Furious Gladiator's Greaves of Salvation
	 40978,// Relentless Gladiator's Girdle of Salvation
	 40979,// Relentless Gladiator's Greaves of Salvation
	 40982,// Deadly Gladiator's Bracers of Salvation
	 40983,// Furious Gladiator's Bracers of Salvation
	 40984,// Relentless Gladiator's Bracers of Salvation
	 41114,// Tempered Saronite Gauntlets
	 41116,// Tempered Saronite Bracers
	 41126,// Brilliant Saronite Legplates
	 41127,// Brilliant Saronite Gauntlets
	 41128,// Brilliant Saronite Boots
	 41129,// Brilliant Saronite Breastplate
	 41189,// Chestplate of Conquest
	 41190,// Legplates of Conquest
	 41344,// Helm of Command
	 41345,// Daunting Legplates
	 41346,// Righteous Greaves
	 41347,// Savage Saronite Legplates
	 41348,// Savage Saronite Walkers
	 41349,// Savage Saronite Gauntlets
	 41350,// Savage Saronite Skullshield
	 41351,// Savage Saronite Pauldrons
	 41352,// Savage Saronite Waistguard
	 41353,// Savage Saronite Hauberk
	 41354,// Savage Saronite Bracers
	 41355,// Vengeance Bindings
	 41356,// Righteous Gauntlets
	 41357,// Daunting Handguards
	 41386,// Spiked Titansteel Helm
	 41387,// Tempered Titansteel Helm
	 41388,// Brilliant Titansteel Helm
	 41391,// Spiked Titansteel Treads
	 41392,// Tempered Titansteel Treads
	 41394,// Brilliant Titansteel Treads
	 41759,// Shackles of Perpetual Friendship
	 41763,// Leggings of the Canny Chief
	 41845,// Life-Light Pauldrons
	 41846,// Clutch of the Storm Giant
	 41932,// Links of the Terrified Deity
	 41974,// Cobalt Bracers
	 41975,// Cobalt Gauntlets
	 42549,// Armored Titanium Goggles
	 42552,// Charged Titanium Specs
	 42625,// Gladiator's Plate Chestpiece
	 42626,// Gladiator's Plate Gauntlets
	 42627,// Gladiator's Plate Helm
	 42628,// Gladiator's Plate Legguards
	 42629,// Gladiator's Plate Shoulders
	 42630,// Gladiator's Scaled Chestpiece
	 42631,// Gladiator's Scaled Gauntlets
	 42632,// Gladiator's Scaled Helm
	 42633,// Gladiator's Scaled Legguards
	 42634,// Gladiator's Scaled Shoulders
	 42635,// Gladiator's Ornamented Chestguard
	 42636,// Gladiator's Ornamented Gloves
	 42637,// Gladiator's Ornamented Headcover
	 42638,// Gladiator's Ornamented Legplates
	 42639,// Gladiator's Ornamented Spaulders
	 42654,// Gladiator's Dreadplate Chestpiece
	 42655,// Gladiator's Dreadplate Gauntlets
	 42656,// Gladiator's Dreadplate Helm
	 42657,// Gladiator's Dreadplate Legguards
	 42658,// Gladiator's Dreadplate Shoulders
	 42723,// Ornate Saronite Bracers
	 42724,// Ornate Saronite Gauntlets
	 42725,// Ornate Saronite Hauberk
	 42726,// Ornate Saronite Legplates
	 42727,// Ornate Saronite Pauldrons
	 42728,// Ornate Saronite Skullshield
	 42729,// Ornate Saronite Waistguard
	 42730,// Ornate Saronite Walkers
	 42765,// Gauntlets of the Disturbed Giant
	 42767,// Invigorating Sabatons
	 42768,// Boots of the Unbowed Protector
	 42825,// Polished Tusk Shackles
	 42826,// Goblin Damage Absorber
	 42827,// Rockshaper's Resolve
	 42829,// Plated Skullguard
	 42830,// Ring of Jokkum
	 42832,// Coldblooded Legplates
	 42833,// Jawbreakers
	 42834,// Mantle of Long Winter
	 42835,// Backhanded Grips
	 42836,// Rockshaper Stompers
	 42876,// Light-Touched Mantle
	 42877,// Chestguard of the Frozen Ascent
	 42878,// Vrykul Training Helm
	 42879,// Crown of Hyldnir
	 42880,// Astrid's Riding Gloves
	 42881,// Bjornrittar's Chilled Legguards
	 42882,// Thorim's Grasp
	 42883,// Iva's Boots
	 42884,// Steel-Tipped Snowboots
	 42885,// Mountaineer's Helm
	 42949,// Polished Spaulders of Valor
	 43068,// Blessed Spaulders of Undead Slaying
	 43069,// Blessed Breastplate of Undead Slaying
	 43070,// Blessed Gauntlets of Undead Slaying
	 43071,// Blessed Legplates of Undead Slaying
	 43163,// Legplates of the Vengeful Mendicant
	 43168,// Clasp of the Fallen Demi-God
	 43174,// Trollkickers
	 43176,// Slippers of the Mojo Dojo
	 43184,// Tundra Pauldrons
	 43197,// Pauldrons of Extinguished Hatred
	 43198,// Mantle of Volkhan
	 43203,// Iron Colossus Legplates
	 43209,// Breastplate of Jagged Stone
	 43213,// Gauntlets of Vigilance
	 43279,// Battlechest of the Twilight Cult
	 43280,// Faceguard of the Hammer Clan
	 43310,// Engraved Chestplate of Eck
	 43353,// Void Sentry Legplates
	 43387,// Shoulderplates of the Beholder
	 43402,// The Obliterator Greaves
	 43405,// Sabatons of Erekem
	 43500,// Bolstered Legplates
	 43586,// Icebane Chestguard
	 43587,// Icebane Girdle
	 43588,// Icebane Treads
	 43739,// Dreadnaught Battleplate
	 43740,// Dreadnaught Breastplate
	 43741,// Dreadnaught Gauntlets
	 43742,// Dreadnaught Greathelm
	 43743,// Dreadnaught Handguards
	 43744,// Dreadnaught Helmet
	 43745,// Dreadnaught Legguards
	 43746,// Dreadnaught Legplates
	 43747,// Dreadnaught Pauldrons
	 43748,// Dreadnaught Shoulderplates
	 43793,// Redemption Breastplate
	 43794,// Redemption Chestpiece
	 43795,// Redemption Faceguard
	 43796,// Redemption Gauntlets
	 43797,// Redemption Gloves
	 43798,// Redemption Greaves
	 43799,// Redemption Handguards
	 43800,// Redemption Headpiece
	 43801,// Redemption Helm
	 43802,// Redemption Legguards
	 43803,// Redemption Legplates
	 43804,// Redemption Shoulderguards
	 43805,// Redemption Shoulderplates
	 43806,// Redemption Spaulders
	 43807,// Redemption Tunic
	 43809,// Scourgeborne Battleplate
	 43811,// Scourgeborne Chestguard
	 43812,// Scourgeborne Faceguard
	 43813,// Scourgeborne Gauntlets
	 43814,// Scourgeborne Handguards
	 43815,// Scourgeborne Helmet
	 43816,// Scourgeborne Legguards
	 43817,// Scourgeborne Legplates
	 43818,// Scourgeborne Pauldrons
	 43819,// Scourgeborne Shoulderplates
	 43831,// Enchanted Plate Waistguard
	 43842,// Jayde's Reinforced Handguards
	 43844,// Ebon Pauldrons
	 43845,// Legplates of Dominion
	 43846,// Helmet of the Dedicated
	 43847,// Demolisher's Grips
	 43848,// Bracers of Icy Resolve
	 43860,// Brilliant Saronite Belt
	 43864,// Brilliant Saronite Bracers
	 43865,// Brilliant Saronite Pauldrons
	 43870,// Brilliant Saronite Helm
	 43930,// Accelerator Stompers
	 43938,// Belt of Rising Hope
	 43939,// Breastplate of Splattered Blood
	 43940,// Plated Legs of the Unholy
	 43941,// Grimy Saronite Pauldrons
	 43942,// Jotunheim Shackles
	 43943,// Gauntlets of the Holy Gladiator
	 43944,// Rings of Nergeld
	 43945,// Blackened Breastplate of the Vault
	 43946,// Chestplate of the Glacial Crusader
	 43947,// Stability Girdle
	 43989,// Remembrance Girdle
	 43994,// Belabored Legplates
	 44000,// Dragonstorm Breastplate
	 44006,// Obsidian Greathelm
	 44031,// The Darkspeaker's Iron Walkers
	 44038,// Battlescar Spirebands
	 44040,// The Crusader's Resolution
	 44043,// Girdle of Eternal Memory
	 44046,// The Argent Crown
	 44057,// Ivory-Reinforced Chestguard
	 44058,// Whalebone Carapace
	 44099,// Strengthened Stockade Pauldrons
	 44100,// Pristine Lightforge Spaulders
	 44111,// Gold Star Spaulders
	 44112,// Glimmershell Shoulder Protectors
	 44120,// Giant-Sized Gauntlets
	 44121,// Sparkly Shiny Gloves
	 44123,// Discarded Titanium Legplates
	 44176,// Girdle of the Warrior Magi
	 44183,// Fireproven Gauntlets
	 44195,// Spaulders of the Giant Lords
	 44197,// Bracers of Accorded Courtesy
	 44198,// Breastplate of the Solemn Council
	 44201,// Sabatons of Draconic Vigor
	 44205,// Legplates of Bloody Reprisal
	 44239,// Standard Issue Legguards
	 44240,// Special Issue Legplates
	 44243,// Toxin-Tempered Sabatons
	 44247,// Fang-Deflecting Faceguard
	 44296,// Helm of Purified Thoughts
	 44306,// Death-Inured Sabatons
	 44312,// Wapach's Spaulders of Solidarity
	 44341,// Bracers of Reverence
	 44345,// Dalaran Warden's Legplates
	 44349,// Warchief's Legplates of Carnage
	 44352,// Shoulderplates of the Abolished
	 44357,// Besieging Breastplate
	 44361,// Greaves of the Traitor
	 44362,// Expelling Gauntlets
	 44369,// Disavowed Bracers
	 44373,// Pauldrons of Reconnaissance
	 44381,// Pauldrons of Morbidus
	 44383,// Battleplate of Unheard Ovation
	 44399,// Gauntlets of The Culling
	 44407,// Silver-Plated Battlechest
	 44411,// Platehelm of Irate Revenge
	 44412,// Faceguard of Punishment
	 44596,// Wrynn's Legplates of Carnage
	 44649,// Crystalbark's Toenail
	 44670,// Soul-Sealed Belt
	 44677,// Eternal Observer's Legplates
	 44691,// Aotona's Collar
	 44695,// Corroded Faceguard
	 44742,// Mechanized Snow Goggles
	 44894,// Titan-Forged Greaves of Salvation
	 44895,// Titan-Forged Greaves of Triumph
	 44901,// Titan-Forged Plate Headcover of Salvation
	 44902,// Titan-Forged Plate Helm of Triumph
	 44949,// Unbreakable Healing Amplifiers
	 45107,// Iron Riveted War Helm
	 45111,// Mimiron's Inferno Couplings
	 45134,// Plated Leggings of Ruination
	 45139,// Dragonslayer's Brace
	 45140,// Razorscale Shoulderguards
	 45160,// Girdle of Valorous Defeat
	 45161,// Girdle of Embers
	 45163,// Stanchions of Unseatable Furor
	 45166,// Charred Saronite Greaves
	 45167,// Lifeforge Breastplate
	 45182,// Gauntlets of Shattered Pride
	 45216,// Gauntlets of Mending Touch
	 45217,// Clinch of Savage Fury
	 45218,// Blood-Caked Stompers
	 45225,// Steelbreaker's Embrace
	 45226,// Ancient Iron Heaume
	 45228,// Handguards of the Enclave
	 45241,// Belt of Colossal Rage
	 45248,// Clockwork Legplates
	 45251,// Shoulderplates of the Deconstructor
	 45252,// Horologist's Wristguards
	 45264,// Decimator's Armguards
	 45267,// Saronite Plated Legguards
	 45268,// Gloves of the Pythonic Guardian
	 45269,// Unfaltering Armguards
	 45283,// Flamewatch Armguards
	 45295,// Gilded Steel Legplates
	 45299,// Dragonsteel Faceplate
	 45304,// Stormtempered Girdle
	 45305,// Breastplate of the Afterlife
	 45310,// Gauntlets of the Iron Furnace
	 45320,// Shoulderplates of the Eternal
	 45321,// Pauldrons of Tempered Will
	 45330,// Greaves of Iron Intensity
	 45334,// Unbreakable Chestguard
	 45335,// Valorous Darkruned Chestguard
	 45336,// Valorous Darkruned Faceguard
	 45337,// Valorous Darkruned Handguards
	 45338,// Valorous Darkruned Legguards
	 45339,// Valorous Darkruned Pauldrons
	 45340,// Valorous Darkruned Battleplate
	 45341,// Valorous Darkruned Gauntlets
	 45342,// Valorous Darkruned Helmet
	 45343,// Valorous Darkruned Legplates
	 45344,// Valorous Darkruned Shoulderplates
	 45370,// Valorous Aegis Gloves
	 45371,// Valorous Aegis Greaves
	 45372,// Valorous Aegis Headpiece
	 45373,// Valorous Aegis Spaulders
	 45374,// Valorous Aegis Tunic
	 45375,// Valorous Aegis Battleplate
	 45376,// Valorous Aegis Gauntlets
	 45377,// Valorous Aegis Helm
	 45379,// Valorous Aegis Legplates
	 45380,// Valorous Aegis Shoulderplates
	 45381,// Valorous Aegis Breastplate
	 45382,// Valorous Aegis Faceguard
	 45383,// Valorous Aegis Handguards
	 45384,// Valorous Aegis Legguards
	 45385,// Valorous Aegis Shoulderguards
	 45424,// Valorous Siegebreaker Breastplate
	 45425,// Valorous Siegebreaker Greathelm
	 45426,// Valorous Siegebreaker Handguards
	 45427,// Valorous Siegebreaker Legguards
	 45428,// Valorous Siegebreaker Pauldrons
	 45429,// Valorous Siegebreaker Battleplate
	 45430,// Valorous Siegebreaker Gauntlets
	 45431,// Valorous Siegebreaker Helmet
	 45432,// Valorous Siegebreaker Legplates
	 45433,// Valorous Siegebreaker Shoulderplates
	 45434,// Greaves of the Rockmender
	 45445,// Breastplate of the Devoted
	 45452,// Frostplate Greaves
	 45472,// Warhelm of the Champion
	 45481,// Gauntlets of Ruthless Reprisal
	 45487,// Handguards of Revitalization
	 45501,// Boots of the Underdweller
	 45502,// Helm of the Faceless
	 45505,// Belt of Clinging Hope
	 45542,// Greaves of the Stonewarder
	 45550,// Belt of the Titans
	 45551,// Indestructible Plate Girdle
	 45552,// Plate Girdle of Righteousness
	 45559,// Battlelord's Plate Boots
	 45560,// Spiked Deathdealers
	 45561,// Treads of Destiny
	 45594,// Legplates of the Endless Void
	 45599,// Sabatons of Lifeless Night
	 45663,// Armbands of Bedlam
	 45676,// Chestplate of Vicious Potency
	 45680,// Armbands of the Construct
	 45697,// Shoulderguards of the Solemn Watch
	 45698,// Sabatons of the Iron Watcher
	 45708,// Archaedas' Lost Legplates
	 45712,// Chestplate of Titanic Fury
	 45824,// Belt of the Singing Blade
	 45825,// Shieldwarder Girdle
	 45826,// Girdle of Unyielding Trust
	 45833,// Bladebreaker Gauntlets
	 45834,// Gauntlets of the Royal Watch
	 45835,// Gauntlets of Serene Blessing
	 45841,// Legplates of the Violet Champion
	 45842,// Wyrmguard Legplates
	 45843,// Legguards of the Peaceful Covenant
	 45888,// Bitter Cold Armguards
	 45928,// Gauntlets of the Thunder God
	 45935,// Ironbark Faceguard
	 45936,// Legplates of Flourishing Resolve
	 45975,// Cable of the Metrognome
	 45982,// Fused Alloy Legplates
	 45988,// Greaves of the Iron Army
	 45997,// Gauntlets of the Wretched
	 46028,// Faceguard of the Eyeless Horror
	 46037,// Shoulderplates of the Celestial Watch
	 46039,// Breastplate of the Timeless
	 46041,// Starfall Girdle
	 46057,// Titan-Forged Chestguard of Salvation
	 46058,// Titan-Forged Breastplate of Triumph
	 46071,// Titan-Forged Girdle of Salvation
	 46072,// Titan-Forged Girdle of Triumph
	 46111,// Conqueror's Darkruned Battleplate
	 46113,// Conqueror's Darkruned Gauntlets
	 46115,// Conqueror's Darkruned Helmet
	 46116,// Conqueror's Darkruned Legplates
	 46117,// Conqueror's Darkruned Shoulderplates
	 46118,// Conqueror's Darkruned Chestguard
	 46119,// Conqueror's Darkruned Handguards
	 46120,// Conqueror's Darkruned Faceguard
	 46121,// Conqueror's Darkruned Legguards
	 46122,// Conqueror's Darkruned Pauldrons
	 46146,// Conqueror's Siegebreaker Battleplate
	 46148,// Conqueror's Siegebreaker Gauntlets
	 46149,// Conqueror's Siegebreaker Shoulderplates
	 46150,// Conqueror's Siegebreaker Legplates
	 46151,// Conqueror's Siegebreaker Helmet
	 46152,// Conqueror's Aegis Shoulderplates
	 46153,// Conqueror's Aegis Legplates
	 46154,// Conqueror's Aegis Battleplate
	 46155,// Conqueror's Aegis Gauntlets
	 46156,// Conqueror's Aegis Helm
	 46162,// Conqueror's Siegebreaker Breastplate
	 46164,// Conqueror's Siegebreaker Handguards
	 46166,// Conqueror's Siegebreaker Greathelm
	 46167,// Conqueror's Siegebreaker Pauldrons
	 46169,// Conqueror's Siegebreaker Legguards
	 46173,// Conqueror's Aegis Breastplate
	 46174,// Conqueror's Aegis Handguards
	 46175,// Conqueror's Aegis Faceguard
	 46176,// Conqueror's Aegis Legguards
	 46177,// Conqueror's Aegis Shoulderguards
	 46178,// Conqueror's Aegis Tunic
	 46179,// Conqueror's Aegis Gloves
	 46180,// Conqueror's Aegis Headpiece
	 46181,// Conqueror's Aegis Greaves
	 46182,// Conqueror's Aegis Spaulders
	 46213,// Aegis Battleplate
	 46214,// Aegis Breastplate
	 46215,// Aegis Faceguard
	 46216,// Aegis Gauntlets
	 46217,// Aegis Gloves
	 46218,// Aegis Greaves
	 46219,// Aegis Handguards
	 46220,// Aegis Headpiece
	 46221,// Aegis Helm
	 46222,// Aegis Legguards
	 46223,// Aegis Legguards
	 46224,// Aegis Legplates
	 46225,// Aegis Shoulderguards
	 46226,// Aegis Shoulderplates
	 46227,// Aegis Spaulders
	 46228,// Aegis Tunic
	 46232,// Darkruned Battleplate
	 46233,// Darkruned Chestguard
	 46234,// Darkruned Faceguard
	 46235,// Darkruned Gauntlets
	 46236,// Darkruned Handguards
	 46237,// Darkruned Helmet
	 46238,// Darkruned Legguards
	 46239,// Darkruned Legplates
	 46240,// Darkruned Pauldrons
	 46241,// Darkruned Shoulderplates
	 46278,// Siegebreaker Battleplate
	 46279,// Siegebreaker Breastplate
	 46280,// Siegebreaker Gauntlets
	 46281,// Siegebreaker Greathelm
	 46282,// Siegebreaker Helmet
	 46283,// Siegebreaker Handguards
	 46284,// Siegebreaker Legguards
	 46285,// Siegebreaker Legplates
	 46286,// Siegebreaker Pauldrons
	 46287,// Siegebreaker Shoulderplates
	 46331,// Conqueror's Terrorblade Boots
	 46340,// Adamant Handguards
	 46345,// Bracers of Righteous Reformation
	 46961,// Boneshatter Armplates
	 46962,// Chestplate of the Towering Monstrosity
	 46967,// Boneshatter Armplates
	 46968,// Chestplate of the Towering Monstrosity
	 46985,// Boots of the Courageous
	 46986,// Boots of the Courageous
	 46997,// Dawnbreaker Greaves
	 46999,// Bloodbath Belt
	 47002,// Bloodbath Belt
	 47003,// Dawnbreaker Greaves
	 47052,// Legguards of Feverish Dedication
	 47057,// Legplates of Failing Light
	 47061,// Legguards of Feverish Dedication
	 47067,// Legplates of Failing Light
	 47072,// Girdle of Bloodied Scars
	 47076,// Girdle of Bloodied Scars
	 47082,// Chestplate of the Frostborn Hero
	 47086,// Chestplate of the Frostborn Hero
	 47093,// Vambraces of the Broken Bond
	 47098,// Vambraces of the Broken Bond
	 47108,// Bracers of the Shieldmaiden
	 47111,// Bracers of the Shieldmaiden
	 47121,// Legguards of Ascension
	 47132,// Legguards of Ascension
	 47142,// Breastplate of the Frozen Lake
	 47147,// Breastplate of the Frozen Lake
	 47150,// Greaves of the 7th Legion
	 47154,// Greaves of the 7th Legion
	 47171,// Legguards of Abandoned Fealty
	 47172,// Helm of the Bested Gallant
	 47176,// Breastplate of the Imperial Joust
	 47195,// Belt of the Forgotten Martyr
	 47197,// Gauntlets of the Stouthearted Crusader
	 47199,// Greaves of the Grand Paladin
	 47201,// Boots of Heartfelt Repentance
	 47207,// Belt of the Forgotten Martyr
	 47212,// Mercy's Hold
	 47220,// Helm of the Violent Fray
	 47227,// Girdle of the Pallid Knight
	 47229,// Girdle of Arrogant Downfall
	 47234,// Gloves of Bitter Reprisal
	 47240,// Gloves of Bitter Reprisal
	 47253,// Boneshatter Vambraces
	 47254,// Hauberk of the Towering Monstrosity
	 47263,// Sabatons of the Courageous
	 47268,// Bloodbath Girdle
	 47269,// Dawnbreaker Sabatons
	 47273,// Legplates of Feverish Dedication
	 47279,// Leggings of Failing Light
	 47283,// Belt of Bloodied Scars
	 47288,// Chestplate of the Frostwolf Hero
	 47294,// Bracers of the Broken Bond
	 47298,// Armguards of the Shieldmaiden
	 47304,// Legplates of Ascension
	 47310,// Chestplate of the Frozen Lake
	 47312,// Greaves of the Saronite Citadel
	 47323,// Girdle of the Forgotten Martyr
	 47330,// Gauntlets of Bitter Reprisal
	 47414,// Boneshatter Vambraces
	 47415,// Hauberk of the Towering Monstrosity
	 47424,// Sabatons of the Courageous
	 47429,// Bloodbath Girdle
	 47430,// Dawnbreaker Sabatons
	 47434,// Legplates of Feverish Dedication
	 47440,// Leggings of Failing Light
	 47444,// Belt of Bloodied Scars
	 47449,// Chestplate of the Frostwolf Hero
	 47455,// Bracers of the Broken Bond
	 47459,// Armguards of the Shieldmaiden
	 47465,// Legplates of Ascension
	 47471,// Chestplate of the Frozen Lake
	 47473,// Greaves of the Saronite Citadel
	 47484,// Girdle of the Forgotten Martyr
	 47492,// Gauntlets of Bitter Reprisal
	 47495,// Legplates of Relentless Onslaught
	 47497,// Helm of the Crestfallen Challenger
	 47502,// Majestic Silversmith Shoulderplates
	 47503,// Legplates of the Argent Armistice
	 47510,// Trueheart Girdle
	 47511,// Plated Greaves of Providence
	 47514,// Regal Aurous Shoulderplates
	 47565,// Vambraces of Unholy Command
	 47567,// Gauntlets of Revelation
	 47570,// Saronite Swordbreakers
	 47571,// Saronite Swordbreakers
	 47572,// Titanium Spikeguards
	 47573,// Titanium Spikeguards
	 47574,// Sunforged Bracers
	 47575,// Sunforged Bracers
	 47589,// Titanium Razorplate
	 47590,// Titanium Razorplate
	 47591,// Breastplate of the White Knight
	 47592,// Breastplate of the White Knight
	 47593,// Sunforged Breastplate
	 47594,// Sunforged Breastplate
	 47609,// Gauntlets of Rising Anger
	 47611,// Dreadscale Armguards
	 47614,// Girdle of the Impaler
	 47615,// Belt of the Frozen Reach
	 47674,// Helm of Thunderous Rampage
	 47675,// Faceplate of Thunderous Rampage
	 47677,// Faceplate of the Honorbound
	 47678,// Headplate of the Honorbound
	 47680,// Armguards of the Nether Lord
	 47681,// Heaume of the Restless Watch
	 47682,// Helm of the Restless Watch
	 47696,// Shoulderplates of Trembling Rage
	 47697,// Pauldrons of Trembling Rage
	 47698,// Shoulderplates of Enduring Order
	 47699,// Shoulderguards of Enduring Order
	 47701,// Shoulderplates of the Cavalier
	 47702,// Pauldrons of the Cavalier
	 47711,// Girdle of the Nether Champion
	 47717,// Faceplate of the Silver Champion
	 47720,// Pauldrons of the Silver Defender
	 47738,// Sabatons of the Lingering Vortex
	 47811,// Chestguard of the Warden
	 47830,// Legplates of the Silver Hand
	 47836,// Legplates of the Immortal Spider
	 47851,// Gauntlets of Mounting Anger
	 47852,// Dreadscale Bracers
	 47858,// Girdle of the Frozen Reach
	 47859,// Belt of the Impaler
	 47869,// Armplates of the Nether Lord
	 47870,// Belt of the Nether Champion
	 47876,// Sunreaver Champion's Faceplate
	 47877,// Sunreaver Defender's Pauldrons
	 47885,// Greaves of the Lingering Vortex
	 47896,// Stoneskin Chestplate
	 47902,// Legplates of Redeemed Blood
	 47908,// Sunwalker Legguards
	 47917,// Gauntlets of Rising Anger
	 47918,// Dreadscale Armguards
	 47924,// Belt of the Frozen Reach
	 47925,// Girdle of the Impaler
	 47935,// Armguards of the Nether Lord
	 47937,// Girdle of the Nether Champion
	 47943,// Faceplate of the Silver Champion
	 47944,// Pauldrons of the Silver Defender
	 47952,// Sabatons of the Lingering Vortex
	 47964,// Chestguard of the Warden
	 47970,// Legplates of the Silver Hand
	 47976,// Legplates of the Immortal Spider
	 47990,// Gauntlets of Mounting Anger
	 47991,// Dreadscale Bracers
	 47997,// Girdle of the Frozen Reach
	 47998,// Belt of the Impaler
	 48008,// Armplates of the Nether Lord
	 48009,// Belt of the Nether Champion
	 48015,// Sunreaver Champion's Faceplate
	 48016,// Sunreaver Defender's Pauldrons
	 48024,// Greaves of the Lingering Vortex
	 48041,// Stoneskin Chestplate
	 48047,// Legplates of the Redeemed Blood Knight
	 48053,// Sunwalker Legguards
	 48371,// Wrynn's Helmet of Conquest
	 48372,// Wrynn's Battleplate of Conquest
	 48373,// Wrynn's Legplates of Conquest
	 48374,// Wrynn's Shoulderplates of Conquest
	 48375,// Wrynn's Gauntlets of Conquest
	 48376,// Wrynn's Battleplate of Triumph
	 48377,// Wrynn's Gauntlets of Triumph
	 48378,// Wrynn's Helmet of Triumph
	 48379,// Wrynn's Legplates of Triumph
	 48380,// Wrynn's Shoulderplates of Triumph
	 48381,// Wrynn's Shoulderplates of Triumph
	 48382,// Wrynn's Legplates of Triumph
	 48383,// Wrynn's Helmet of Triumph
	 48384,// Wrynn's Gauntlets of Triumph
	 48385,// Wrynn's Battleplate of Triumph
	 48386,// Hellscream's Battleplate of Conquest
	 48387,// Hellscream's Gauntlets of Conquest
	 48388,// Hellscream's Helmet of Conquest
	 48389,// Hellscream's Legplates of Conquest
	 48390,// Hellscream's Shoulderplates of Conquest
	 48391,// Hellscream's Battleplate of Triumph
	 48392,// Hellscream's Gauntlets of Triumph
	 48393,// Hellscream's Helmet of Triumph
	 48394,// Hellscream's Legplates of Triumph
	 48395,// Hellscream's Shoulderplates of Triumph
	 48396,// Hellscream's Battleplate of Triumph
	 48397,// Hellscream's Gauntlets of Triumph
	 48398,// Hellscream's Helmet of Triumph
	 48399,// Hellscream's Legplates of Triumph
	 48400,// Hellscream's Shoulderplates of Triumph
	 48429,// Wrynn's Greathelm of Conquest
	 48430,// Wrynn's Greathelm of Triumph
	 48433,// Wrynn's Greathelm of Triumph
	 48436,// Wrynn's Breastplate of Conquest
	 48445,// Wrynn's Legguards of Conquest
	 48446,// Wrynn's Legguards of Triumph
	 48447,// Wrynn's Legguards of Triumph
	 48448,// Wrynn's Pauldrons of Conquest
	 48449,// Wrynn's Handguards of Conquest
	 48450,// Wrynn's Breastplate of Triumph
	 48451,// Wrynn's Breastplate of Triumph
	 48452,// Wrynn's Handguards of Triumph
	 48453,// Wrynn's Handguards of Triumph
	 48454,// Wrynn's Pauldrons of Triumph
	 48455,// Wrynn's Pauldrons of Triumph
	 48456,// Hellscream's Breastplate of Conquest
	 48457,// Hellscream's Handguards of Conquest
	 48458,// Hellscream's Greathelm of Conquest
	 48459,// Hellscream's Legguards of Conquest
	 48460,// Hellscream's Pauldrons of Conquest
	 48461,// Hellscream's Breastplate of Triumph
	 48462,// Hellscream's Handguards of Triumph
	 48463,// Hellscream's Greathelm of Triumph
	 48464,// Hellscream's Legguards of Triumph
	 48465,// Hellscream's Pauldrons of Triumph
	 48466,// Hellscream's Breastplate of Triumph
	 48467,// Hellscream's Handguards of Triumph
	 48468,// Hellscream's Greathelm of Triumph
	 48469,// Hellscream's Legguards of Triumph
	 48470,// Hellscream's Pauldrons of Triumph
	 48472,// Thassarian's Helmet of Conquest
	 48474,// Thassarian's Battleplate of Conquest
	 48476,// Thassarian's Legplates of Conquest
	 48478,// Thassarian's Shoulderplates of Conquest
	 48480,// Thassarian's Gauntlets of Conquest
	 48481,// Thassarian's Battleplate of Triumph
	 48482,// Thassarian's Gauntlets of Triumph
	 48483,// Thassarian's Helmet of Triumph
	 48484,// Thassarian's Legplates of Triumph
	 48485,// Thassarian's Shoulderplates of Triumph
	 48486,// Thassarian's Shoulderplates of Triumph
	 48487,// Thassarian's Legplates of Triumph
	 48488,// Thassarian's Helmet of Triumph
	 48489,// Thassarian's Gauntlets of Triumph
	 48490,// Thassarian's Battleplate of Triumph
	 48491,// Koltira's Battleplate of Triumph
	 48492,// Koltira's Gauntlets of Triumph
	 48493,// Koltira's Helmet of Triumph
	 48494,// Koltira's Legplates of Triumph
	 48495,// Koltira's Shoulderplates of Triumph
	 48496,// Koltira's Shoulderplates of Triumph
	 48497,// Koltira's Legplates of Triumph
	 48498,// Koltira's Helmet of Triumph
	 48499,// Koltira's Gauntlets of Triumph
	 48500,// Koltira's Battleplate of Triumph
	 48501,// Koltira's Battleplate of Conquest
	 48502,// Koltira's Gauntlets of Conquest
	 48503,// Koltira's Helmet of Conquest
	 48504,// Koltira's Legplates of Conquest
	 48505,// Koltira's Shoulderplates of Conquest
	 48529,// Thassarian's Faceguard of Conquest
	 48531,// Thassarian's Chestguard of Conquest
	 48533,// Thassarian's Legguards of Conquest
	 48535,// Thassarian's Pauldrons of Conquest
	 48537,// Thassarian's Handguards of Conquest
	 48538,// Thassarian's Chestguard of Triumph
	 48539,// Thassarian's Handguards of Triumph
	 48540,// Thassarian's Faceguard of Triumph
	 48541,// Thassarian's Legguards of Triumph
	 48542,// Thassarian's Pauldrons of Triumph
	 48543,// Thassarian's Pauldrons of Triumph
	 48544,// Thassarian's Legguards of Triumph
	 48545,// Thassarian's Faceguard of Triumph
	 48546,// Thassarian's Handguards of Triumph
	 48547,// Thassarian's Chestguard of Triumph
	 48548,// Koltira's Chestguard of Triumph
	 48549,// Koltira's Handguards of Triumph
	 48550,// Koltira's Faceguard of Triumph
	 48551,// Koltira's Legguards of Triumph
	 48552,// Koltira's Pauldrons of Triumph
	 48553,// Koltira's Pauldrons of Triumph
	 48554,// Koltira's Legguards of Triumph
	 48555,// Koltira's Faceguard of Triumph
	 48556,// Koltira's Handguards of Triumph
	 48557,// Koltira's Chestguard of Triumph
	 48558,// Koltira's Chestguard of Conquest
	 48559,// Koltira's Handguards of Conquest
	 48560,// Koltira's Faceguard of Conquest
	 48561,// Koltira's Legguards of Conquest
	 48562,// Koltira's Pauldrons of Conquest
	 48564,// Turalyon's Headpiece of Conquest
	 48566,// Turalyon's Tunic of Conquest
	 48568,// Turalyon's Greaves of Conquest
	 48572,// Turalyon's Spaulders of Conquest
	 48574,// Turalyon's Gloves of Conquest
	 48575,// Turalyon's Tunic of Triumph
	 48576,// Turalyon's Gloves of Triumph
	 48577,// Turalyon's Headpiece of Triumph
	 48578,// Turalyon's Greaves of Triumph
	 48579,// Turalyon's Spaulders of Triumph
	 48580,// Turalyon's Spaulders of Triumph
	 48581,// Turalyon's Greaves of Triumph
	 48582,// Turalyon's Headpiece of Triumph
	 48583,// Turalyon's Gloves of Triumph
	 48584,// Turalyon's Tunic of Triumph
	 48585,// Liadrin's Spaulders of Triumph
	 48586,// Liadrin's Greaves of Triumph
	 48587,// Liadrin's Headpiece of Triumph
	 48588,// Liadrin's Gloves of Triumph
	 48589,// Liadrin's Tunic of Triumph
	 48590,// Liadrin's Spaulders of Triumph
	 48591,// Liadrin's Greaves of Triumph
	 48592,// Liadrin's Headpiece of Triumph
	 48593,// Liadrin's Gloves of Triumph
	 48594,// Liadrin's Tunic of Triumph
	 48595,// Liadrin's Spaulders of Conquest
	 48596,// Liadrin's Greaves of Conquest
	 48597,// Liadrin's Headpiece of Conquest
	 48598,// Liadrin's Gloves of Conquest
	 48599,// Liadrin's Tunic of Conquest
	 48602,// Turalyon's Battleplate of Conquest
	 48603,// Turalyon's Gauntlets of Conquest
	 48604,// Turalyon's Helm of Conquest
	 48605,// Turalyon's Legplates of Conquest
	 48606,// Turalyon's Shoulderplates of Conquest
	 48607,// Turalyon's Battleplate of Triumph
	 48608,// Turalyon's Gauntlets of Triumph
	 48609,// Turalyon's Helm of Triumph
	 48610,// Turalyon's Legplates of Triumph
	 48611,// Turalyon's Shoulderplates of Triumph
	 48612,// Turalyon's Shoulderplates of Triumph
	 48613,// Turalyon's Legplates of Triumph
	 48614,// Turalyon's Helm of Triumph
	 48615,// Turalyon's Gauntlets of Triumph
	 48616,// Turalyon's Battleplate of Triumph
	 48617,// Liadrin's Battleplate of Triumph
	 48618,// Liadrin's Gauntlets of Triumph
	 48619,// Liadrin's Helm of Triumph
	 48620,// Liadrin's Legplates of Triumph
	 48621,// Liadrin's Shoulderplates of Triumph
	 48622,// Liadrin's Shoulderplates of Triumph
	 48623,// Liadrin's Legplates of Triumph
	 48624,// Liadrin's Helm of Triumph
	 48625,// Liadrin's Gauntlets of Triumph
	 48626,// Liadrin's Battleplate of Triumph
	 48627,// Liadrin's Shoulderplates of Conquest
	 48628,// Liadrin's Legplates of Conquest
	 48629,// Liadrin's Helm of Conquest
	 48630,// Liadrin's Gauntlets of Conquest
	 48631,// Liadrin's Battleplate of Conquest
	 48632,// Turalyon's Breastplate of Conquest
	 48633,// Turalyon's Handguards of Conquest
	 48634,// Turalyon's Faceguard of Conquest
	 48635,// Turalyon's Legguards of Conquest
	 48636,// Turalyon's Shoulderguards of Conquest
	 48637,// Turalyon's Shoulderguards of Triumph
	 48638,// Turalyon's Legguards of Triumph
	 48639,// Turalyon's Faceguard of Triumph
	 48640,// Turalyon's Handguards of Triumph
	 48641,// Turalyon's Breastplate of Triumph
	 48642,// Turalyon's Breastplate of Triumph
	 48643,// Turalyon's Handguards of Triumph
	 48644,// Turalyon's Faceguard of Triumph
	 48645,// Turalyon's Legguards of Triumph
	 48646,// Turalyon's Shoulderguards of Triumph
	 48647,// Liadrin's Shoulderguards of Triumph
	 48648,// Liadrin's Legguards of Triumph
	 48649,// Liadrin's Faceguard of Triumph
	 48650,// Liadrin's Handguards of Triumph
	 48651,// Liadrin's Breastplate of Triumph
	 48652,// Liadrin's Breastplate of Conquest
	 48653,// Liadrin's Handguards of Conquest
	 48654,// Liadrin's Faceguard of Conquest
	 48655,// Liadrin's Legguards of Conquest
	 48656,// Liadrin's Shoulderguards of Conquest
	 48657,// Liadrin's Breastplate of Triumph
	 48658,// Liadrin's Handguards of Triumph
	 48659,// Liadrin's Faceguard of Triumph
	 48660,// Liadrin's Legguards of Triumph
	 48661,// Liadrin's Shoulderguards of Triumph
	 48685,// Polished Breastplate of Valor
	 48860,// Hellscream's Battleplate 
	 48861,// Hellscream's Gauntlets 
	 48862,// Hellscream's Helmet 
	 48863,// Hellscream's Legplates 
	 48864,// Hellscream's Shoulderplates 
	 48865,// Wrynn's Battleplate 
	 48866,// Wrynn's Gauntlets 
	 48867,// Wrynn's Helmet 
	 48868,// Wrynn's Legplates 
	 48869,// Wrynn's Shoulderplates 
	 48870,// Hellscream's Breastplate 
	 48871,// Hellscream's Greathelm 
	 48872,// Hellscream's Handguards 
	 48873,// Hellscream's Legguards 
	 48874,// Hellscream's Pauldrons 
	 48875,// Wrynn's Breastplate 
	 48876,// Wrynn's Greathelm 
	 48877,// Wrynn's Handguards 
	 48878,// Wrynn's Legguards 
	 48879,// Wrynn's Pauldrons 
	 48880,// Koltira's Battleplate 
	 48881,// Koltira's Gauntlets 
	 48882,// Koltira's Helmet 
	 48883,// Koltira's Legplates 
	 48884,// Koltira's Shoulderplates 
	 48885,// Thassarian's Battleplate 
	 48886,// Thassarian's Gauntlets 
	 48887,// Thassarian's Helmet 
	 48888,// Thassarian's Legplates 
	 48889,// Thassarian's Shoulderplates 
	 48890,// Koltira's Chestguard
	 48891,// Koltira's Faceguard 
	 48892,// Koltira's Handguards 
	 48893,// Koltira's Legguards 
	 48894,// Koltira's Pauldrons
	 48895,// Thassarian's Chestguard
	 48896,// Thassarian's Faceguard 
	 48897,// Thassarian's Handguards 
	 48898,// Thassarian's Legguards 
	 48899,// Thassarian's Pauldrons
	 48900,// Turalyon's Tunic 
	 48901,// Turalyon's Spaulders 
	 48902,// Turalyon's Headpiece 
	 48903,// Turalyon's Greaves 
	 48904,// Turalyon's Gloves 
	 48905,// Liadrin's Tunic 
	 48906,// Liadrin's Spaulders 
	 48907,// Liadrin's Headpiece 
	 48908,// Liadrin's Greaves 
	 48909,// Liadrin's Gloves 
	 48910,// Liadrin's Battleplate 
	 48911,// Liadrin's Gauntlets 
	 48912,// Liadrin's Helm 
	 48913,// Liadrin's Legplates 
	 48914,// Liadrin's Shoulderplates 
	 48915,// Turalyon's Battleplate 
	 48916,// Turalyon's Gauntlets 
	 48917,// Turalyon's Helm 
	 48918,// Turalyon's Legplates 
	 48919,// Turalyon's Shoulderplates 
	 48922,// Liadrin's Breastplate 
	 48923,// Liadrin's Faceguard 
	 48924,// Liadrin's Handguards 
	 48925,// Liadrin's Legguards 
	 48926,// Liadrin's Shoulderguards 
	 48927,// Turalyon's Breastplate 
	 48928,// Turalyon's Faceguard 
	 48929,// Turalyon's Handguards 
	 48930,// Turalyon's Legguards 
	 48931,// Turalyon's Shoulderguards 
	 48977,// Titan-Forged Bracers of Salvation
	 48978,// Titan-Forged Bracers of Triumph
	 48992,// Titan-Forged Plate Legguards of Salvation
	 48993,// Titan-Forged Plate Legguards of Triumph
	 49126,// The Horseman's Horrific Helm
	 49320,// Faceguard of Wrath
	 49321,// Greathelm of Wrath
	 49323,// Judgement Cover
	 49324,// Judgement Helmet
	 49325,// Judgement Helm
	 49332,// Frostforged Ringhelm
	 49333,// Frostforged Helmet
	 49466,// Frostforged Helm
	 49467,// Frostforged Greathelm
	 49474,// Judgement Hood
	 49475,// Judgement Heaume
	 49476,// Judgement Crown
	 49478,// Helmet of Wrath
	 49479,// Helm of Wrath
	 49784,// Minister's Number One Legplates
	 49791,// Lost Reliquary Chestguard
	 49794,// Legplates of Frozen Granite
	 49795,// Sollerets of Suffering
	 49797,// Brace Guards of the Starless Night
	 49808,// Bent Gold Belt
	 49816,// Scourgelord's Frigid Chestplate
	 49819,// Skeleton Lord's Cranium
	 49829,// Valonforth's Tarnished Pauldrons
	 49843,// Crystalline Citadel Gauntlets
	 49851,// Greathelm of the Silver Hand
	 49853,// Titanium Links of Lore
	 49855,// Plated Grips of Korth'azz
	 49902,// Puresteel Legplates
	 49903,// Legplates of Painful Death
	 49904,// Pillars of Might
	 49905,// Protectors of Life
	 49906,// Hellfrozen Bonegrinders
	 49907,// Boots of Kingly Upheaval
	 49951,// Gendarme's Cuirass
	 49960,// Bracers of Dark Reckoning
	 49964,// Legguards of Lost Hope
	 49980,// Rusted Bonespike Pauldrons
	 49983,// Blood-Soaked Saronite Stompers
	 49986,// Broken Ram Skull Helm
	 49995,// Fallen Lord's Handguards
	 50002,// Polar Bear Claw Bracers
	 50003,// Boneguard Commander's Pauldrons
	 50010,// Waistband of Righteous Fury
	 50020,// Raging Behemoth's Shoulderplates
	 50024,// Blightborne Warplate
	 50027,// Rot-Resistant Breastplate
	 50036,// Belt of Broken Bones
	 50037,// Fleshrending Gauntlets
	 50060,// Faceplate of the Forgotten
	 50072,// Landsoul's Horned Greathelm
	 50075,// Taldaram's Plated Fists
	 50078,// Ymirjar Lord's Battleplate
	 50079,// Ymirjar Lord's Gauntlets
	 50080,// Ymirjar Lord's Helmet
	 50081,// Ymirjar Lord's Legplates
	 50082,// Ymirjar Lord's Shoulderplates
	 50094,// Scourgelord Battleplate
	 50095,// Scourgelord Gauntlets
	 50096,// Scourgelord Helmet
	 50097,// Scourgelord Legplates
	 50098,// Scourgelord Shoulderplates
	 50175,// Crypt Keeper's Bracers
	 50187,// Coldwraith Links
	 50190,// Grinning Skull Greatboots
	 50192,// Scourge Reaver's Legplates
	 50194,// Weeping Gauntlets
	 50199,// Leggings of Dying Candles
	 50207,// Black Spire Sabatons
	 50208,// Pauldrons of the Souleater
	 50215,// Recovered Reliquary Boots
	 50229,// Legguards of the Frosty Depths
	 50230,// Malykriss Vambraces
	 50234,// Shoulderplates of Frozen Blood
	 50272,// Frost Wyrm Ribcage
	 50284,// Rusty Frozen Fingerguards
	 50285,// Icebound Bronze Cuirass
	 50294,// Chestpiece of High Treason
	 50305,// Grinning Skull Boots
	 50311,// Second Helm of the Executioner
	 50324,// Lightsworn Shoulderplates
	 50325,// Lightsworn Legplates
	 50326,// Lightsworn Helmet
	 50327,// Lightsworn Gauntlets
	 50328,// Lightsworn Battleplate
	 50416,// Boots of the Funeral March
	 50451,// Belt of the Lonely Noble
	 50606,// Gendarme's Cuirass
	 50611,// Bracers of Dark Reckoning
	 50612,// Legguards of Lost Hope
	 50617,// Rusted Bonespike Pauldrons
	 50620,// Coldwraith Links
	 50623,// Leggings of Dying Candles
	 50624,// Scourge Reaver's Legplates
	 50625,// Grinning Skull Greatboots
	 50632,// Boots of the Funeral March
	 50639,// Blood-Soaked Saronite Stompers
	 50640,// Broken Ram Skull Helm
	 50650,// Fallen Lord's Handguards
	 50659,// Polar Bear Claw Bracers
	 50660,// Boneguard Commander's Pauldrons
	 50667,// Waistband of Righteous Fury
	 50674,// Raging Behemoth's Shoulderplates
	 50680,// Rot-Resistant Breastplate
	 50681,// Blightborne Warplate
	 50690,// Fleshrending Gauntlets
	 50691,// Belt of Broken Bones
	 50701,// Faceplate of the Forgotten
	 50712,// Landsoul's Horned Greathelm
	 50716,// Taldaram's Plated Fists
	 50721,// Crypt Keeper's Bracers
	 50772,// Ancient Skeletal Boots
	 50775,// Corrupted Silverplate Leggings
	 50779,// Deathspeaker Zealot's Helm
	 50786,// Ghoul Commander's Cuirass
	 50788,// Bone Drake's Enameled Boots
	 50796,// Bracers of Pale Illumination
	 50801,// Blade-Scored Carapace
	 50802,// Gargoyle Spit Bracers
	 50808,// Deathforged Legplates
	 50811,// Festering Fingerguards
	 50846,// Ymirjar Lord's Pauldrons
	 50847,// Ymirjar Lord's Legguards
	 50848,// Ymirjar Lord's Greathelm
	 50849,// Ymirjar Lord's Handguards
	 50850,// Ymirjar Lord's Breastplate
	 50853,// Scourgelord Pauldrons
	 50854,// Scourgelord Legguards
	 50855,// Scourgelord Faceguard
	 50856,// Scourgelord Handguards
	 50857,// Scourgelord Chestguard
	 50860,// Lightsworn Shoulderguards
	 50861,// Lightsworn Legguards
	 50862,// Lightsworn Faceguard
	 50863,// Lightsworn Handguards
	 50864,// Lightsworn Chestguard
	 50865,// Lightsworn Spaulders
	 50866,// Lightsworn Greaves
	 50867,// Lightsworn Headpiece
	 50868,// Lightsworn Gloves
	 50869,// Lightsworn Tunic
	 50965,// Castle Breaker's Battleplate
	 50967,// Festergut's Gaseous Gloves
	 50968,// Cataclysmic Chestguard
	 50969,// Chestplate of Unspoken Truths
	 50976,// Gauntlets of Overexposure
	 50977,// Gatecrasher's Gauntlets
	 50978,// Gauntlets of the Kraken
	 50987,// Malevolent Girdle
	 50989,// Lich Killer's Lanyard
	 50991,// Verdigris Chain Belt
	 51000,// Flesh-Shaper's Gurney Strap
	 51014,// Scalpel-Sharpening Shoulderguards
	 51018,// Chestplate of Septic Stitches
	 51025,// Battle-Maiden's Legguards
	 51125,// Sanctified Scourgelord Shoulderplates
	 51126,// Sanctified Scourgelord Legplates
	 51127,// Sanctified Scourgelord Helmet
	 51128,// Sanctified Scourgelord Gauntlets
	 51129,// Sanctified Scourgelord Battleplate
	 51130,// Sanctified Scourgelord Pauldrons
	 51131,// Sanctified Scourgelord Legguards
	 51132,// Sanctified Scourgelord Handguards
	 51133,// Sanctified Scourgelord Faceguard
	 51134,// Sanctified Scourgelord Chestguard
	 51160,// Sanctified Lightsworn Shoulderplates
	 51161,// Sanctified Lightsworn Legplates
	 51162,// Sanctified Lightsworn Helmet
	 51163,// Sanctified Lightsworn Gauntlets
	 51164,// Sanctified Lightsworn Battleplate
	 51165,// Sanctified Lightsworn Tunic
	 51166,// Sanctified Lightsworn Spaulders
	 51167,// Sanctified Lightsworn Headpiece
	 51168,// Sanctified Lightsworn Greaves
	 51169,// Sanctified Lightsworn Gloves
	 51170,// Sanctified Lightsworn Shoulderguards
	 51171,// Sanctified Lightsworn Legguards
	 51172,// Sanctified Lightsworn Handguards
	 51173,// Sanctified Lightsworn Faceguard
	 51174,// Sanctified Lightsworn Chestguard
	 51210,// Sanctified Ymirjar Lord's Shoulderplates
	 51211,// Sanctified Ymirjar Lord's Legplates
	 51212,// Sanctified Ymirjar Lord's Helmet
	 51213,// Sanctified Ymirjar Lord's Gauntlets
	 51214,// Sanctified Ymirjar Lord's Battleplate
	 51215,// Sanctified Ymirjar Lord's Pauldrons
	 51216,// Sanctified Ymirjar Lord's Legguards
	 51217,// Sanctified Ymirjar Lord's Handguards
	 51218,// Sanctified Ymirjar Lord's Greathelm
	 51219,// Sanctified Ymirjar Lord's Breastplate
	 51220,// Sanctified Ymirjar Lord's Breastplate
	 51221,// Sanctified Ymirjar Lord's Greathelm
	 51222,// Sanctified Ymirjar Lord's Handguards
	 51223,// Sanctified Ymirjar Lord's Legguards
	 51224,// Sanctified Ymirjar Lord's Pauldrons
	 51225,// Sanctified Ymirjar Lord's Battleplate
	 51226,// Sanctified Ymirjar Lord's Gauntlets
	 51227,// Sanctified Ymirjar Lord's Helmet
	 51228,// Sanctified Ymirjar Lord's Legplates
	 51229,// Sanctified Ymirjar Lord's Shoulderplates
	 51265,// Sanctified Lightsworn Chestguard
	 51266,// Sanctified Lightsworn Faceguard
	 51267,// Sanctified Lightsworn Handguards
	 51268,// Sanctified Lightsworn Legguards
	 51269,// Sanctified Lightsworn Shoulderguards
	 51270,// Sanctified Lightsworn Gloves
	 51271,// Sanctified Lightsworn Greaves
	 51272,// Sanctified Lightsworn Headpiece
	 51273,// Sanctified Lightsworn Spaulders
	 51274,// Sanctified Lightsworn Tunic
	 51275,// Sanctified Lightsworn Battleplate
	 51276,// Sanctified Lightsworn Gauntlets
	 51277,// Sanctified Lightsworn Helmet
	 51278,// Sanctified Lightsworn Legplates
	 51279,// Sanctified Lightsworn Shoulderplates
	 51305,// Sanctified Scourgelord Chestguard
	 51306,// Sanctified Scourgelord Faceguard
	 51307,// Sanctified Scourgelord Handguards
	 51308,// Sanctified Scourgelord Legguards
	 51309,// Sanctified Scourgelord Pauldrons
	 51310,// Sanctified Scourgelord Battleplate
	 51311,// Sanctified Scourgelord Gauntlets
	 51312,// Sanctified Scourgelord Helmet
	 51313,// Sanctified Scourgelord Legplates
	 51314,// Sanctified Scourgelord Shoulderplates
	 51359,// Wrathful Gladiator's Girdle of Salvation
	 51360,// Wrathful Gladiator's Greaves of Salvation
	 51361,// Wrathful Gladiator's Bracers of Salvation
	 51362,// Wrathful Gladiator's Girdle of Triumph
	 51363,// Wrathful Gladiator's Greaves of Triumph
	 51364,// Wrathful Gladiator's Bracers of Triumph
	 51383,// Spaulders of the Blood Princes
	 51386,// Throatrender Handguards
	 51413,// Wrathful Gladiator's Dreadplate Chestpiece
	 51414,// Wrathful Gladiator's Dreadplate Gauntlets
	 51415,// Wrathful Gladiator's Dreadplate Helm
	 51416,// Wrathful Gladiator's Dreadplate Legguards
	 51418,// Wrathful Gladiator's Dreadplate Shoulders
	 51468,// Wrathful Gladiator's Ornamented Chestguard
	 51469,// Wrathful Gladiator's Ornamented Gloves
	 51470,// Wrathful Gladiator's Ornamented Headcover
	 51471,// Wrathful Gladiator's Ornamented Legplates
	 51473,// Wrathful Gladiator's Ornamented Spaulders
	 51474,// Wrathful Gladiator's Scaled Chestpiece
	 51475,// Wrathful Gladiator's Scaled Gauntlets
	 51476,// Wrathful Gladiator's Scaled Helm
	 51477,// Wrathful Gladiator's Scaled Legguards
	 51479,// Wrathful Gladiator's Scaled Shoulders
	 51541,// Wrathful Gladiator's Plate Chestpiece
	 51542,// Wrathful Gladiator's Plate Gauntlets
	 51543,// Wrathful Gladiator's Plate Helm
	 51544,// Wrathful Gladiator's Plate Legguards
	 51545,// Wrathful Gladiator's Plate Shoulders
	 51555,// Tightening Waistband
	 51556,// Veincrusher Gauntlets
	 51563,// Taiga Bindings
	 51564,// Ironrope Belt of Ymirjar
	 51580,// Titan-Forged Shoulderplates of Triumph
	 51581,// Titan-Forged Shoulderplates of Salvation
	 51586,// Emerald Saint's Spaulders
	 51682,// Scourgelord Shoulderplates
	 51683,// Scourgelord Legplates
	 51684,// Scourgelord Helmet
	 51685,// Scourgelord Gauntlets
	 51686,// Scourgelord Battleplate
	 51687,// Scourgelord Chestguard
	 51688,// Scourgelord Handguards
	 51689,// Scourgelord Faceguard
	 51690,// Scourgelord Legguards
	 51691,// Scourgelord Pauldrons
	 51717,// Lightsworn Battleplate
	 51718,// Lightsworn Gauntlets
	 51719,// Lightsworn Helmet
	 51720,// Lightsworn Legplates
	 51721,// Lightsworn Shoulderplates
	 51722,// Lightsworn Tunic
	 51723,// Lightsworn Gloves
	 51724,// Lightsworn Headpiece
	 51725,// Lightsworn Greaves
	 51726,// Lightsworn Spaulders
	 51727,// Lightsworn Chestguard
	 51728,// Lightsworn Handguards
	 51729,// Lightsworn Faceguard
	 51730,// Lightsworn Legguards
	 51731,// Lightsworn Shoulderguards
	 51767,// Ymirjar Lord's Shoulderplates
	 51768,// Ymirjar Lord's Legplates
	 51769,// Ymirjar Lord's Helmet
	 51770,// Ymirjar Lord's Gauntlets
	 51771,// Ymirjar Lord's Battleplate
	 51772,// Ymirjar Lord's Breastplate
	 51773,// Ymirjar Lord's Handguards
	 51774,// Ymirjar Lord's Greathelm
	 51775,// Ymirjar Lord's Legguards
	 51776,// Ymirjar Lord's Pauldrons
	 51782,// Etched Dragonbone Girdle
	 51786,// Legplates of Aetheric Strife
	 51787,// Scourge Fanged Stompers
	 51816,// Scourge Fanged Stompers
	 51817,// Legplates of Aetheric Strife
	 51821,// Etched Dragonbone Girdle
	 51824,// Emerald Saint's Spaulders
	 51831,// Ironrope Belt of Ymirjar
	 51832,// Taiga Bindings
	 51835,// Veincrusher Gauntlets
	 51836,// Tightening Waistband
	 51844,// Throatrender Handguards
	 51847,// Spaulders of the Blood Princes
	 51854,// Battle-Maiden's Legguards
	 51861,// Chestplate of Septic Stitches
	 51865,// Scalpel-Sharpening Shoulderguards
	 51879,// Flesh-Shaper's Gurney Strap
	 51886,// Festergut's Gaseous Gloves
	 51892,// Festering Fingerguards
	 51895,// Deathforged Legplates
	 51901,// Gargoyle Spit Bracers
	 51902,// Blade-Scored Carapace
	 51907,// Bracers of Pale Illumination
	 51915,// Bone Drake's Enameled Boots
	 51917,// Ghoul Commander's Cuirass
	 51924,// Deathspeaker Zealot's Helm
	 51928,// Corrupted Silverplate Leggings
	 51931,// Ancient Skeletal Boots
	 53111,// Scion's Treads
	 53112,// Bracers of the Heir
	 53121,// Surrogate Belt
	 53125,// Apocalypse's Advance
	 53129,// Treads of Impending Resurrection
	 53487,// Foreshadow Steps
	 53491,// Twilight Offering Bands
	 53494,// Girdle of Oblation
	 53500,// Tectonic Plate
	 53505,// Salamander Skin
	 54544,// Scrapped Spaulders
	 54552,// Retaliation Gauntlets
	 54559,// Bracers of the Heir
	 54564,// Scion's Treads
	 54565,// Surrogate Belt
	 54578,// Apocalypse's Advance
	 54579,// Treads of Impending Resurrection
	 54586,// Foreshadow Steps
	 54850,// Hardened Obsidium Bracers
	 54852,// Hardened Obsidium Gauntlets
	 54853,// Hardened Obsidium Belt
	 54854,// Hardened Obsidium Boots
	 54876,// Hardened Obsidium Shoulders
	 55022,// Hardened Obsidium Legguards
	 55023,// Hardened Obsidium Helm
	 55024,// Hardened Obsidium Breastplate
	 55025,// Redsteel Bracers
	 55026,// Redsteel Gauntlets
	 55027,// Redsteel Belt
	 55028,// Redsteel Boots
	 55029,// Redsteel Shoulders
	 55030,// Redsteel Legguards
	 55031,// Redsteel Helm
	 55032,// Redsteel Breastplate
	 55033,// Stormforged Bracers
	 55034,// Stormforged Gauntlets
	 55035,// Stormforged Belt
	 55036,// Stormforged Boots
	 55037,// Stormforged Shoulders
	 55038,// Stormforged Legguards
	 55039,// Stormforged Helm
	 55040,// Stormforged Breastplate
	 55058,// Hardened Elementium Hauberk
	 55059,// Hardened Elementium Girdle
	 55060,// Elementium Deathplate
	 55061,// Elementium Girdle of Pain
	 55062,// Light Elementium Chestguard
	 55063,// Light Elementium Belt
	 55071,// Bloodied Pyrium Bracers
	 55072,// Bloodied Pyrium Gauntlets
	 55073,// Bloodied Pyrium Belt
	 55074,// Bloodied Pyrium Boots
	 55075,// Bloodied Pyrium Shoulders
	 55076,// Bloodied Pyrium Legguards
	 55077,// Bloodied Pyrium Helm
	 55078,// Bloodied Pyrium Breastplate
	 55079,// Ornate Pyrium Bracers
	 55080,// Ornate Pyrium Gauntlets
	 55081,// Ornate Pyrium Belt
	 55082,// Ornate Pyrium Boots
	 55083,// Ornate Pyrium Shoulders
	 55084,// Ornate Pyrium Legguards
	 55085,// Ornate Pyrium Helm
	 55086,// Ornate Pyrium Breastplate
	 55207,// Harp Shell Pauldrons
	 55229,// Anomuran Helm
	 55249,// Triton Legplates
	 55254,// Abalone Plate Armor
	 55260,// Alpheus Legguards
	 55268,// Bracers of Cooled Anger
	 55274,// Beauty's Plate
	 55488,// Dreadmaul Vambraces
	 55489,// Rethban Vambraces
	 55490,// Jasperlode Vambraces
	 55491,// Direforge Vambraces
	 55492,// Fargodeep Vambraces
	 55493,// Ravencrest Vambraces
	 55494,// Stonewrought Vambraces
	 55495,// Crystalvein Vambraces
	 55496,// Steelgrill Vambraces
	 55497,// Dreadmaul Breastplate
	 55498,// Rethban Breastplate
	 55499,// Jasperlode Breastplate
	 55500,// Direforge Breastplate
	 55501,// Fargodeep Breastplate
	 55502,// Ravencrest Breastplate
	 55503,// Stonewrought Breastplate
	 55504,// Crystalvein Breastplate
	 55505,// Steelgrill Breastplate
	 55506,// Dreadmaul Sabatons
	 55507,// Rethban Sabatons
	 55508,// Jasperlode Sabatons
	 55509,// Direforge Sabatons
	 55510,// Fargodeep Sabatons
	 55511,// Ravencrest Sabatons
	 55512,// Stonewrought Sabatons
	 55513,// Crystalvein Sabatons
	 55514,// Steelgrill Sabatons
	 55515,// Dreadmaul Gauntlets
	 55516,// Rethban Gauntlets
	 55517,// Jasperlode Gauntlets
	 55518,// Direforge Gauntlets
	 55519,// Fargodeep Gauntlets
	 55520,// Ravencrest Gauntlets
	 55521,// Stonewrought Gauntlets
	 55522,// Crystalvein Gauntlets
	 55523,// Steelgrill Gauntlets
	 55524,// Dreadmaul Helm
	 55525,// Rethban Helm
	 55526,// Jasperlode Helm
	 55527,// Direforge Helm
	 55528,// Fargodeep Helm
	 55529,// Ravencrest Helm
	 55530,// Stonewrought Helm
	 55531,// Crystalvein Helm
	 55532,// Steelgrill Helm
	 55533,// Dreadmaul Legplates
	 55534,// Rethban Legplates
	 55535,// Jasperlode Legplates
	 55536,// Direforge Legplates
	 55537,// Fargodeep Legplates
	 55538,// Ravencrest Legplates
	 55539,// Stonewrought Legplates
	 55540,// Crystalvein Legplates
	 55541,// Steelgrill Legplates
	 55542,// Dreadmaul Pauldrons
	 55543,// Rethban Pauldrons
	 55544,// Jasperlode Pauldrons
	 55545,// Direforge Pauldrons
	 55546,// Fargodeep Pauldrons
	 55547,// Ravencrest Pauldrons
	 55548,// Stonewrought Pauldrons
	 55549,// Crystalvein Pauldrons
	 55550,// Steelgrill Pauldrons
	 55551,// Dreadmaul Girdle
	 55552,// Rethban Girdle
	 55553,// Jasperlode Girdle
	 55554,// Direforge Girdle
	 55555,// Fargodeep Girdle
	 55556,// Ravencrest Girdle
	 55557,// Stonewrought Girdle
	 55558,// Crystalvein Girdle
	 55559,// Steelgrill Girdle
	 55779,// Raz's Pauldrons
	 55784,// Clutches of Dying Light
	 55792,// Cinnabar Shoulders
	 55797,// Hematite Plate Gloves
	 55803,// Belt of the Ringworm
	 55831,// Headcover of Fog
	 55842,// Legguards of Winnowing Wind
	 55848,// Lunar Halo
	 55855,// Darksky Treads
	 55856,// Greaves of Wu the Elder
	 55862,// Greaves of Wu the Younger
	 55867,// Sand Dune Belt
	 55992,// Armguards of Unearthly Light
	 56093,// Breastplate of the Risen Land
	 56099,// Fingers of Light
	 56104,// Legguards of Noon
	 56118,// Belt of the Forgemaster
	 56124,// Earthshape Pauldrons
	 56135,// Bracers of Umbral Mending
	 56272,// Harp Shell Pauldrons
	 56278,// Anomuran Helm
	 56283,// Triton Legplates
	 56291,// Abalone Plate Armor
	 56294,// Alpheus Legguards
	 56301,// Bracers of Cooled Anger
	 56308,// Beauty's Plate
	 56318,// Raz's Pauldrons
	 56323,// Clutches of Dying Light
	 56330,// Cinnabar Shoulders
	 56336,// Hematite Plate Gloves
	 56341,// Belt of the Ringworm
	 56358,// Headcover of Fog
	 56367,// Legguards of Winnowing Wind
	 56374,// Lunar Halo
	 56378,// Darksky Treads
	 56381,// Greaves of Wu the Elder
	 56387,// Greaves of Wu the Younger
	 56392,// Sand Dune Belt
	 56416,// Armguards of Unearthly Light
	 56425,// Breastplate of the Risen Land
	 56428,// Fingers of Light
	 56435,// Legguards of Noon
	 56447,// Belt of the Forgemaster
	 56452,// Earthshape Pauldrons
	 56464,// Bracers of Umbral Mending
	 57260,// Nemesis Crushers
	 57264,// Chestplate of Viridian Renewal
	 57268,// Forgemaster's Shattered Shackle
	 57271,// Silver Spur Boots
	 57277,// Crown of Chelonian Freedom
	 57284,// Grips of Arcane Imprisonment
	 57287,// Gauntlets of Guerilla Fury
	 57290,// Druidic Guardian Plate
	 57300,// Greaves of Violent Revenge
	 57303,// Heatbinder Wristplates
	 57309,// Chestplate of Exceptional Expectations
	 57312,// Discarded Juggernaut Plating
	 57320,// Embercrusher Grips
	 57323,// Deathseed Crushers
	 57332,// Legplates of Persuasion
	 57342,// Rescuers Shoulderguards
	 57345,// Razorproof Greaves
	 57349,// Helm of the Mendicant
	 57357,// Anvilcrush Bracers
	 57360,// Shoulderguards of Empty Memory
	 57363,// Invidious Casque
	 57366,// Girdle of the Ancient Wolf
	 57370,// Belt of Binding Purification
	 57380,// Girdle of Gar'gol
	 57855,// Alpha Bracers
	 57856,// Omega Breastplate
	 57861,// Helm of Setesh
	 57869,// Omega Breastplate
	 57870,// Alpha Bracers
	 57873,// Helm of Setesh
	 57913,// Beech Green Belt
	 57914,// Girdle of the Mountains
	 57915,// Belt of Barred Clouds
	 58096,// Breastplate of Raging Fury
	 58097,// Greaves of Gallantry
	 58098,// Helm of Easeful Death
	 58099,// Reaping Gauntlets
	 58100,// Pauldrons of the High Requiem
	 58101,// Chestplate of the Steadfast
	 58102,// Greaves of Splendor
	 58103,// Helm of the Proud
	 58104,// Sunburnt Pauldrons
	 58105,// Numbing Handguards
	 58106,// Chestguard of Dancing Waves
	 58107,// Legguards of the Gentle
	 58108,// Crown of the Blazing Sun
	 58109,// Pauldrons of the Forlorn
	 58110,// Gloves of Curious Conscience
	 58195,// Woe Breeder's Boots
	 58197,// Rock Furrow Boots
	 58198,// Eternal Pathfinders
	 59117,// Jumbotron Power Belt
	 59118,// Electron Inductor Coils
	 59216,// Life Force Chargers
	 59221,// Massacre Treads
	 59225,// Plated Fists of Provocation
	 59311,// Burden of Mortality
	 59316,// Battleplate of Ancient Kings
	 59317,// Legguards of the Unseeing
	 59328,// Molten Tantrum Boots
	 59340,// Breastplate of Avenging Flame
	 59342,// Belt of Absolute Zero
	 59344,// Dragon Bone Warhelm
	 59352,// Flash Freeze Gauntlets
	 59356,// Pauldrons of the Apocalypse
	 59359,// Reinforced Bio-Optic Killshades
	 59448,// Specialized Bio-Optic Killshades
	 59450,// Belt of the Blackhand
	 59464,// Treads of Savage Beatings
	 59465,// Corehammer's Riveted Girdle
	 59470,// Bracers of Impossible Strength
	 59471,// Pauldrons of the Great Ettin
	 59476,// Legguards of the Emerald Brood
	 59486,// Battleplate of the Apocalypse
	 59487,// Helm of Maddening Whispers
	 59497,// Shackles of the End of Days
	 59503,// Terrastra's Legguards
	 59505,// Gravitational Pull
	 59509,// Glaciated Helm
	 59601,// Submariner's Weighted Treads
	 59604,// Submariner's Weighted Treads
	 59618,// Chestguard of Cognitive Dissonance
	 59621,// Eel-Slayer Legguards
	 59624,// Eel-Slayer Legguards
	 59629,// Riptide Legguards
	 59632,// Riptide Legguards
	 59636,// Spikemender Shoulderplates
	 59639,// Spikemender Shoulderplates
	 59641,// Chemical-Stained Shoulderplates
	 59644,// Chemical-Stained Shoulderplates
	 59648,// Handguards of the Severed Starfish
	 59651,// Grips of the Severed Starfish
	 59653,// Explosively Decompressed Stompers
	 59656,// Explosively Decompressed Stompers
	 59673,// True Beacon Shoulderplates
	 59676,// True Beacon Shoulderplates
	 59693,// Gloves of Transcription
	 59696,// Gloves of Transcription
	 59699,// Liminal Greathelm
	 59702,// Liminal Greathelm
	 59717,// Chestguard of Alarming Dreams
	 59720,// Chestguard of Alarming Dreams
	 59723,// Meiofauna Wristguards
	 59726,// Sea Star Wristwraps
	 59730,// Oddly Revealing Chestguard
	 59733,// Chestplate of Fragrant Desire
	 59735,// Helm of the Crushed Overseer
	 59738,// Helm of the Crushed Overseer
	 59747,// Polychaete Footguards
	 59756,// Drill-Guide Belt
	 59759,// Super-Sized Stompers
	 59762,// Wentletrap Legplates
	 59765,// Damplight Chestplate
	 59768,// Bracers of Burbling Freedom
	 59772,// Bracers of Burbling Freedom
	 59779,// Girdle of Calcified Blackfin
	 59785,// Pounded Pewter Links
	 59795,// Harp Shell Shoulderplates
	 59799,// Schooner-Savior's Grips
	 59802,// Wheelman's Shattered Grasp
	 59901,// Heaving Plates of Protection
	 60228,// Bracers of the Mat'redor
	 60229,// War-Torn Crushers
	 60234,// Bindings of Bleak Betrayal
	 60323,// Earthen Battleplate
	 60324,// Earthen Legplates
	 60325,// Earthen Helmet
	 60326,// Earthen Gauntlets
	 60327,// Earthen Pauldrons
	 60328,// Earthen Faceguard
	 60329,// Earthen Chestguard
	 60330,// Earthen Legguards
	 60331,// Earthen Shoulderguards
	 60332,// Earthen Handguards
	 60339,// Magma Plated Battleplate
	 60340,// Magma Plated Gauntlets
	 60341,// Magma Plated Helmet
	 60342,// Magma Plated Legplates
	 60343,// Magma Plated Pauldrons
	 60344,// Reinforced Sapphirium Battleplate
	 60345,// Reinforced Sapphirium Gauntlets
	 60346,// Reinforced Sapphirium Helmet
	 60347,// Reinforced Sapphirium Legplates
	 60348,// Reinforced Sapphirium Pauldrons
	 60349,// Magma Plated Chestguard
	 60350,// Magma Plated Handguards
	 60351,// Magma Plated Faceguard
	 60352,// Magma Plated Legguards
	 60353,// Magma Plated Shoulderguards
	 60354,// Reinforced Sapphirium Chestguard
	 60355,// Reinforced Sapphirium Handguards
	 60356,// Reinforced Sapphirium Faceguard
	 60357,// Reinforced Sapphirium Legguards
	 60358,// Reinforced Sapphirium Shoulderguards
	 60359,// Reinforced Sapphirium Headguard
	 60360,// Reinforced Sapphirium Breastplate
	 60361,// Reinforced Sapphirium Greaves
	 60362,// Reinforced Sapphirium Mantle
	 60363,// Reinforced Sapphirium Gloves
	 60408,// Vicious Gladiator's Dreadplate Chestpiece
	 60409,// Vicious Gladiator's Dreadplate Gauntlets
	 60410,// Vicious Gladiator's Dreadplate Helm
	 60411,// Vicious Gladiator's Dreadplate Legguards
	 60412,// Vicious Gladiator's Dreadplate Shoulders
	 60413,// Vicious Gladiator's Scaled Chestpiece
	 60414,// Vicious Gladiator's Scaled Gauntlets
	 60415,// Vicious Gladiator's Scaled Helm
	 60416,// Vicious Gladiator's Scaled Legguards
	 60417,// Vicious Gladiator's Scaled Shoulders
	 60418,// Vicious Gladiator's Plate Chestpiece
	 60419,// Vicious Gladiator's Plate Gauntlets
	 60420,// Vicious Gladiator's Plate Helm
	 60421,// Vicious Gladiator's Plate Legguards
	 60422,// Vicious Gladiator's Plate Shoulders
	 60505,// Vicious Gladiator's Clasp of Cruelty
	 60506,// Vicious Gladiator's Greaves of Salvation
	 60507,// Vicious Gladiator's Bracers of Salvation
	 60508,// Vicious Gladiator's Girdle of Cruelty
	 60509,// Vicious Gladiator's Warboots of Cruelty
	 60510,// Vicious Gladiator's Bracers of Triumph
	 60512,// Vicious Gladiator's Armplates of Alacrity
	 60513,// Vicious Gladiator's Warboots of Alacrity
	 60514,// Vicious Gladiator's Girdle of Triumph
	 60515,// Vicious Gladiator's Bracers of Salvation
	 60516,// Vicious Gladiator's Greaves of Alacrity
	 60517,// Vicious Gladiator's Girdle of Salvation
	 60518,// Vicious Gladiator's Girdle of Salvation
	 60519,// Vicious Gladiator's Greaves of Salvation
	 60520,// Vicious Gladiator's Bracers of Prowess
	 60521,// Vicious Gladiator's Girdle of Prowess
	 60522,// Vicious Gladiator's Greaves of Triumph
	 60523,// Vicious Gladiator's Armplates of Proficiency
	 60524,// Vicious Gladiator's Bracers of Triumph
	 60525,// Vicious Gladiator's Greaves of Triumph
	 60526,// Vicious Gladiator's Girdle of Triumph
	 60527,// Vicious Gladiator's Girdle of Triumph
	 60528,// Vicious Gladiator's Greaves of Triumph
	 60529,// Vicious Gladiator's Bracers of Triumph
	 60539,// Vicious Gladiator's Clasp of Meditation
	 60540,// Vicious Gladiator's Greaves of Meditation
	 60541,// Vicious Gladiator's Bracers of Meditation
	 60601,// Vicious Gladiator's Ornamented Chestguard
	 60602,// Vicious Gladiator's Ornamented Gloves
	 60603,// Vicious Gladiator's Ornamented Headcover
	 60604,// Vicious Gladiator's Ornamented Legplates
	 60605,// Vicious Gladiator's Ornamented Spaulders
	 61400,// Size-Cutting Bracers
	 61407,// Rune-Scribed Gauntlets
	 61412,// Fungus-Stained Legplates
	 61416,// Girdle of Bolete Explosion
	 61418,// Terrath's Rocky Spaulders
	 61421,// Petrified Stone Bracers
	 61424,// Geodecrack Shoulderguards
	 61427,// Gyreworm Waistguard
	 61430,// Stonebound Legplates
	 61436,// Gateshattering Hauberk
	 61439,// Gateshattering Hauberk
	 61442,// Tonguecarver Greathelm
	 61445,// Helm of Silenced Blathering
	 61454,// Catapult Loader's Gloves
	 61457,// Troggzor's Crystalline Plate
	 61463,// Earthswell Belt
	 61466,// Bell-Ringer's Skullcap
	 61481,// Mercury Treads
	 61484,// Midnight Service Treads
	 61487,// Rough Stone Carapace
	 61502,// Deepstone Treads
	 61931,// Polished Helm of Valor
	 62023,// Polished Legplates of Valor
	 62075,// Perforated Plate Shoulderpads
	 62076,// Perforated Plate Pants
	 62077,// Perforated Plate Gloves
	 62078,// Perforated Plate Chestpiece
	 62080,// Perforated Plate Boots
	 62090,// Perforated Plate Belt
	 62095,// Perforated Plate Bracers
	 62104,// Perforated Plate Helmet
	 62105,// Bleached Plate Pants
	 62106,// Bleached Plate Gloves
	 62126,// Bleached Plate Chestpiece
	 62127,// Bleached Plate Shoulderpads
	 62128,// Bleached Plate Bracers
	 62129,// Bleached Plate Boots
	 62130,// Bleached Plate Belt
	 62134,// Bleached Plate Helmet
	 62355,// Stone-Wrapped Greaves
	 62359,// Peacemaker's Breastplate
	 62365,// World Keeper's Gauntlets
	 62382,// Waywatcher's Boots
	 62384,// Belt of the Ferocious Wolf
	 62408,// Gauntlets of Rattling Bones
	 62410,// Grinning Fang Helm
	 62418,// Boots of Sullen Rock
	 62428,// Crown of Wings
	 62430,// Gryphon Talon Gauntlets
	 62432,// Gryphon Rider's Boots
	 62438,// Drystone Greaves
	 62448,// Sun King's Girdle
	 62449,// Sandguard Bracers
	 63093,// Twilight's Hammer Shoulders
	 63434,// Gloves of the Greymane Wall
	 63444,// Baron Silverlaine's Greaves
	 63450,// Phantom Armor
	 63453,// Iron Will Girdle
	 63457,// Shackles of Undeath
	 63458,// Lord Walden's Breastplate
	 63462,// Helm of Untold Stories
	 63464,// Greaves of the Misguided
	 63470,// Missing Diplomat's Pauldrons
	 63474,// Gear-Marked Gauntlets
	 63476,// Gearbreaker's Bindings
	 63478,// Stonemason's Helm
	 63483,// Guildmaster's Greaves
	 63490,// Sky Strider Belt
	 63491,// Thunder Wall Belt
	 63495,// Tempest Keeper Belt
	 63500,// Sky Strider Greaves
	 63501,// Thunder Wall Greaves
	 63504,// Tempest Keeper Leggings
	 63531,// Daybreaker Helm
	 63701,// Treads of Terror
	 63705,// Treads of Terror
	 63709,// Lava-Melted Legplates
	 63712,// Bracers of Gleaming Shards
	 63715,// Grips of the Damned Mind
	 63718,// Grips of the Damned Mind
	 63727,// Klem's Rusted Gauntlets
	 63730,// Klem's Rusted Gauntlets
	 63737,// Wound-Heart Bracers
	 63740,// Muffled Bracers
	 63748,// Gatecrasher Shoulderguards
	 63751,// Signal Smoke Shoulderpads
	 63757,// Wyrmhunter Spaulders
	 63763,// Gate-Breaker Treads
	 63766,// Commander's Stompers
	 63770,// Helm of Durable Hatred
	 63773,// Gatekeeper's Helm
	 63775,// Helm of Verdant Explosion
	 63782,// Weeping Scar Cover
	 63784,// Heartsmoke Legplates
	 63800,// Clear-Eyed Waistguard
	 63805,// Furybound Waistplate
	 63809,// Legplates of Riven Futures
	 63812,// Legplates of Cooled Magma
	 63815,// Wound-Binder Chestguard
	 63818,// Blundy's Breastplate
	 63827,// Skyshredder Battleplate
	 63831,// Flynn's Favorite Chestplate
	 63835,// Dunwald's Finest Bindings
	 63844,// Ogre-Slayer Chestplate
	 63847,// Keg-Sized Chestplate
	 63850,// Krazzworks Climbing Belt
	 63853,// Gryphon-Seeker Waistplate
	 63856,// Crazed Pilot's Gloves
	 63859,// Stormhammer Gauntlets
	 63862,// Tool-Bracing Armguards
	 63865,// Weapon-Bearer Bracers
	 63868,// Skyfallen Plate Belt
	 63871,// Stoutwaist Girdle
	 63874,// Legguards of Samophlangination
	 63878,// Legplates of Remnants
	 63882,// Treads of the Common Man
	 63885,// Tank-Defending Treads
	 63894,// Heartblood Gauntlets
	 63897,// Coregrip Gauntlets
	 63900,// Shredder-Salvage Spaulders
	 63903,// Song-Reflecting Spaulders
	 63913,// Twilight-Heart Shoulderplates
	 63918,// Detective's Shoulderplates
	 63922,// Awestruck Bracers
	 63925,// Scavenger Bracers
	 64683,// Bloodthirsty Gladiator's Armplates of Alacrity
	 64684,// Bloodthirsty Gladiator's Armplates of Proficiency
	 64704,// Bloodthirsty Gladiator's Bracers of Meditation
	 64705,// Bloodthirsty Gladiator's Bracers of Prowess
	 64715,// Bloodthirsty Gladiator's Clasp of Cruelty
	 64716,// Bloodthirsty Gladiator's Clasp of Meditation
	 64735,// Bloodthirsty Gladiator's Dreadplate Chestpiece
	 64736,// Bloodthirsty Gladiator's Dreadplate Gauntlets
	 64737,// Bloodthirsty Gladiator's Dreadplate Helm
	 64738,// Bloodthirsty Gladiator's Dreadplate Legguards
	 64739,// Bloodthirsty Gladiator's Dreadplate Shoulders
	 64753,// Bloodthirsty Gladiator's Girdle of Cruelty
	 64754,// Bloodthirsty Gladiator's Girdle of Prowess
	 64756,// Bloodthirsty Gladiator's Greaves of Alacrity
	 64757,// Bloodthirsty Gladiator's Greaves of Meditation
	 64802,// Bloodthirsty Gladiator's Ornamented Chestguard
	 64803,// Bloodthirsty Gladiator's Ornamented Gloves
	 64804,// Bloodthirsty Gladiator's Ornamented Headcover
	 64805,// Bloodthirsty Gladiator's Ornamented Legplates
	 64806,// Bloodthirsty Gladiator's Ornamented Spaulders
	 64811,// Bloodthirsty Gladiator's Plate Chestpiece
	 64812,// Bloodthirsty Gladiator's Plate Gauntlets
	 64813,// Bloodthirsty Gladiator's Plate Helm
	 64814,// Bloodthirsty Gladiator's Plate Legguards
	 64815,// Bloodthirsty Gladiator's Plate Shoulders
	 64843,// Bloodthirsty Gladiator's Scaled Chestpiece
	 64844,// Bloodthirsty Gladiator's Scaled Gauntlets
	 64845,// Bloodthirsty Gladiator's Scaled Helm
	 64846,// Bloodthirsty Gladiator's Scaled Legguards
	 64847,// Bloodthirsty Gladiator's Scaled Shoulders
	 64869,// Bloodthirsty Gladiator's Warboots of Alacrity
	 64870,// Bloodthirsty Gladiator's Warboots of Cruelty
	 64933,// Gladiator's Scaled Shoulders
	 64934,// Gladiator's Scaled Legguards
	 64935,// Gladiator's Scaled Helm
	 64936,// Gladiator's Scaled Gauntlets
	 64937,// Gladiator's Scaled Chestpiece
	 64943,// Gladiator's Plate Shoulders
	 64944,// Gladiator's Plate Legguards
	 64945,// Gladiator's Plate Helm
	 64946,// Gladiator's Plate Gauntlets
	 64947,// Gladiator's Plate Chestpiece
	 64948,// Gladiator's Ornamented Spaulders
	 64949,// Gladiator's Ornamented Legplates
	 64950,// Gladiator's Ornamented Headcover
	 64951,// Gladiator's Ornamented Gloves
	 64952,// Gladiator's Ornamented Chestguard
	 64978,// Gladiator's Dreadplate Shoulders
	 64979,// Gladiator's Dreadplate Legguards
	 64980,// Gladiator's Dreadplate Helm
	 64981,// Gladiator's Dreadplate Gauntlets
	 64982,// Gladiator's Dreadplate Chestpiece
	 65011,// Corehammer's Riveted Girdle
	 65012,// Treads of Savage Beatings
	 65022,// Belt of the Blackhand
	 65027,// Pauldrons of the Apocalypse
	 65031,// Flash Freeze Gauntlets
	 65038,// Dragon Bone Warhelm
	 65040,// Belt of Absolute Zero
	 65042,// Breastplate of Avenging Flame
	 65051,// Molten Tantrum Boots
	 65061,// Legguards of the Unseeing
	 65062,// Battleplate of Ancient Kings
	 65067,// Burden of Mortality
	 65071,// Plated Fists of Provocation
	 65075,// Massacre Treads
	 65080,// Life Force Chargers
	 65085,// Electron Inductor Coils
	 65086,// Jumbotron Power Belt
	 65096,// Daybreaker Helm
	 65101,// Heaving Plates of Protection
	 65115,// Glaciated Helm
	 65119,// Gravitational Pull
	 65121,// Terrastra's Legguards
	 65127,// Shackles of the End of Days
	 65130,// Helm of Maddening Whispers
	 65131,// Battleplate of the Apocalypse
	 65137,// Legguards of the Emerald Brood
	 65142,// Pauldrons of the Great Ettin
	 65143,// Bracers of Impossible Strength
	 65179,// Magma Plated Battleplate
	 65180,// Magma Plated Gauntlets
	 65181,// Magma Plated Helmet
	 65182,// Magma Plated Legplates
	 65183,// Magma Plated Pauldrons
	 65184,// Magma Plated Chestguard
	 65185,// Magma Plated Handguards
	 65186,// Magma Plated Faceguard
	 65187,// Magma Plated Legguards
	 65188,// Magma Plated Shoulderguards
	 65214,// Reinforced Sapphirium Battleplate
	 65215,// Reinforced Sapphirium Gauntlets
	 65216,// Reinforced Sapphirium Helmet
	 65217,// Reinforced Sapphirium Legplates
	 65218,// Reinforced Sapphirium Pauldrons
	 65219,// Reinforced Sapphirium Breastplate
	 65220,// Reinforced Sapphirium Gloves
	 65221,// Reinforced Sapphirium Headguard
	 65222,// Reinforced Sapphirium Greaves
	 65223,// Reinforced Sapphirium Mantle
	 65224,// Reinforced Sapphirium Chestguard
	 65225,// Reinforced Sapphirium Handguards
	 65226,// Reinforced Sapphirium Faceguard
	 65227,// Reinforced Sapphirium Legguards
	 65228,// Reinforced Sapphirium Shoulderguards
	 65264,// Earthen Battleplate
	 65265,// Earthen Gauntlets
	 65266,// Earthen Helmet
	 65267,// Earthen Legplates
	 65268,// Earthen Pauldrons
	 65269,// Earthen Chestguard
	 65270,// Earthen Handguards
	 65271,// Earthen Faceguard
	 65272,// Earthen Legguards
	 65273,// Earthen Shoulderguards
	 65369,// Sky Strider Belt
	 65370,// Thunder Wall Belt
	 65375,// Tempest Keeper Belt
	 65379,// Sky Strider Greaves
	 65380,// Thunder Wall Greaves
	 65385,// Tempest Keeper Leggings
	 65518,// Vicious Gladiator's Ornamented Spaulders
	 65519,// Vicious Gladiator's Ornamented Legplates
	 65520,// Vicious Gladiator's Ornamented Headcover
	 65521,// Vicious Gladiator's Ornamented Gloves
	 65522,// Vicious Gladiator's Ornamented Chestguard
	 65580,// Vicious Gladiator's Plate Shoulders
	 65581,// Vicious Gladiator's Plate Legguards
	 65582,// Vicious Gladiator's Plate Helm
	 65583,// Vicious Gladiator's Plate Gauntlets
	 65584,// Vicious Gladiator's Plate Chestpiece
	 65585,// Vicious Gladiator's Scaled Shoulders
	 65586,// Vicious Gladiator's Scaled Legguards
	 65590,// Vicious Gladiator's Scaled Helm
	 65591,// Vicious Gladiator's Scaled Gauntlets
	 65592,// Vicious Gladiator's Scaled Chestpiece
	 65593,// Vicious Gladiator's Dreadplate Shoulders
	 65594,// Vicious Gladiator's Dreadplate Legguards
	 65595,// Vicious Gladiator's Dreadplate Helm
	 65596,// Vicious Gladiator's Dreadplate Gauntlets
	 65597,// Vicious Gladiator's Dreadplate Chestpiece
	 65605,// Vicious Gladiator's Greaves of Alacrity
	 65606,// Vicious Gladiator's Greaves of Meditation
	 65607,// Vicious Gladiator's Warboots of Cruelty
	 65608,// Vicious Gladiator's Warboots of Alacrity
	 65654,// Belt of a Thousand Deaths
	 65740,// Fallen Brotherhood Gauntlets
	 65743,// Helm of Vicious Direction
	 65773,// Gloves of Gnomebliteration
	 65786,// Colossus Smasher Breastplate
	 65789,// Caimas' Spaulders
	 65796,// Qebnet Greaves
	 65800,// Bracers of the Dark Pyramid
	 65806,// Sunwatcher's Legplates
	 65809,// Gloves of the Stela
	 65817,// Grave Protector Shoulderplates
	 65822,// Hevna's Eye Socket
	 65825,// Helm of the Siltwater Slayer
	 65828,// Great General's Crown
	 65831,// Pharoah's Burial Spaulders
	 65834,// Weaponseeker Bracers
	 65837,// Legplates of Heilopolis
	 65841,// Tomb-Curse Chestplate
	 65845,// Misappropriated Girdle of Khartut
	 65848,// False-Face Mask
	 65852,// Gauntlets of Delicate Aim
	 65858,// Bullet-Pierced Chestplate
	 65861,// Statue Climbers
	 65865,// Ankh-Inscribed Bracers
	 65868,// Canopic Chestplate
	 65871,// Guardian-Killer Waistplate
	 65874,// Rediscovered Delta Walkers
	 65884,// Femurbreak Stompers
	 65887,// Staffseeker Shoulderplates
	 66884,// Raz's Breastplate
	 66891,// Pauldrons of Unholy Rituals
	 66901,// Greaves of Orsis
	 66907,// Captain Hadan's Pauldrons
	 66909,// Ramkahen Front Boots
	 66911,// Offline Greaves
	 66913,// Repository Gauntlets
	 66933,// Breastplate of the Witness
	 66977,// Pauldrons of Toil
	 66979,// Bracers of Bloody Business
	 66980,// Girdle of Heated Deeds
	 66982,// Greaves of the Outcast Knight
	 66983,// Helm of Fatal Vision
	 66986,// Troubled Steps
	 66989,// Endwyn's Flickering Gauntlets
	 66992,// Harbinger's Breastplate
	 67024,// Breastplate of Solemn Vows
	 67032,// Firm-Set Treads
	 67043,// Greaves of Sullen Earth
	 67050,// Ben-Son's Royal Crown
	 67057,// Oath-Bound Gauntlets
	 67067,// Belt of Guardianship
	 67099,// Waistguard of New Days
	 67109,// Gauntlets of Chattering Valves
	 67115,// Soulheart Bindings
	 67122,// Helm of Holy Visions
	 67141,// Corefire Legplates
	 67143,// Icebone Hauberk
	 67144,// Pauldrons of Edward the Odd
	 67233,// Sussurating Treads of Shok'sharak
	 67235,// Garr's Girdle of Memories
	 67238,// Terborus's Rotating Bands
	 69552,// Bracers of Hidden Purpose
	 69557,// Jungle Striders
	 69558,// Spiritshield Mask
	 69562,// Boots of Bad Mojo
	 69573,// Pauldrons of Sacrifice
	 69582,// Skullpiercer Pauldrons
	 69583,// Legguards of the Unforgiving
	 69587,// Chestplate of Hubris
	 69588,// Skullcrusher Warboots
	 69593,// Battleplate of the Amani Empire
	 69595,// Fetish Greaves
	 69599,// Pauldrons of Ambition
	 69604,// Coils of Hate
	 69608,// Deathcharged Wristguards
	 69614,// Roaring Mask of Bethekk
	 69617,// Plumed Medicine Helm
	 69619,// Bone Plate Handguards
	 69633,// Plunderer's Gauntlets
	 69641,// Troll Skull Chestplate
	 69801,// Amani Armguards
	 69842,// Garr's Reinforced Girdle of Memories
	 69887,// Burnished Helm of Might
	 69888,// Burnished Legplates of Might
	 69889,// Burnished Breastplate of Might
	 69890,// Burnished Pauldrons of Might
	 69936,// Fists of Fury
	 69937,// Eternal Elementium Handguards
	 69938,// Holy Flame Gauntlets
	 69946,// Warboots of Mighty Lords
	 69947,// Mirrored Boots
	 69948,// Emberforged Elementium Boots
	 70004,// Bloodthirsty Pyrium Breastplate
	 70005,// Bloodthirsty Pyrium Boots
	 70006,// Bloodthirsty Pyrium Gauntlets
	 70007,// Bloodthirsty Pyrium Helm
	 70008,// Bloodthirsty Pyrium Legguards
	 70009,// Bloodthirsty Pyrium Shoulders
	 70010,// Bloodthirsty Pyrium Belt
	 70011,// Bloodthirsty Pyrium Bracers
	 70012,// Bloodthirsty Ornate Pyrium Breastplate
	 70013,// Bloodthirsty Ornate Pyrium Boots
	 70014,// Bloodthirsty Ornate Pyrium Gauntlets
	 70015,// Bloodthirsty Ornate Pyrium Helm
	 70016,// Bloodthirsty Ornate Pyrium Legguards
	 70017,// Bloodthirsty Ornate Pyrium Shoulders
	 70018,// Bloodthirsty Ornate Pyrium Belt
	 70019,// Bloodthirsty Ornate Pyrium Bracers
	 70108,// Pyrelord Greaves
	 70116,// Gauntlets of Living Obsidium
	 70117,// Belt of Living Obsidium
	 70120,// Rickety Belt
	 70121,// Ricket's Gun Show
	 70244,// Ruthless Gladiator's Dreadplate Chestpiece
	 70245,// Ruthless Gladiator's Dreadplate Gauntlets
	 70246,// Ruthless Gladiator's Dreadplate Helm
	 70247,// Ruthless Gladiator's Dreadplate Legguards
	 70248,// Ruthless Gladiator's Dreadplate Shoulders
	 70249,// Ruthless Gladiator's Scaled Chestpiece
	 70250,// Ruthless Gladiator's Scaled Gauntlets
	 70251,// Ruthless Gladiator's Scaled Helm
	 70252,// Ruthless Gladiator's Scaled Legguards
	 70253,// Ruthless Gladiator's Scaled Shoulders
	 70254,// Ruthless Gladiator's Plate Chestpiece
	 70255,// Ruthless Gladiator's Plate Gauntlets
	 70256,// Ruthless Gladiator's Plate Helm
	 70257,// Ruthless Gladiator's Plate Legguards
	 70258,// Ruthless Gladiator's Plate Shoulders
	 70319,// Ruthless Gladiator's Clasp of Cruelty
	 70320,// Ruthless Gladiator's Girdle of Cruelty
	 70321,// Ruthless Gladiator's Warboots of Cruelty
	 70322,// Ruthless Gladiator's Armplates of Alacrity
	 70323,// Ruthless Gladiator's Warboots of Alacrity
	 70324,// Ruthless Gladiator's Greaves of Alacrity
	 70325,// Ruthless Gladiator's Bracers of Prowess
	 70326,// Ruthless Gladiator's Girdle of Prowess
	 70327,// Ruthless Gladiator's Armplates of Proficiency
	 70332,// Ruthless Gladiator's Clasp of Meditation
	 70333,// Ruthless Gladiator's Greaves of Meditation
	 70334,// Ruthless Gladiator's Bracers of Meditation
	 70353,// Ruthless Gladiator's Ornamented Chestguard
	 70354,// Ruthless Gladiator's Ornamented Gloves
	 70355,// Ruthless Gladiator's Ornamented Headcover
	 70356,// Ruthless Gladiator's Ornamented Legplates
	 70357,// Ruthless Gladiator's Ornamented Spaulders
	 70415,// Ruthless Gladiator's Ornamented Spaulders
	 70416,// Ruthless Gladiator's Ornamented Legplates
	 70417,// Ruthless Gladiator's Ornamented Headcover
	 70418,// Ruthless Gladiator's Ornamented Gloves
	 70419,// Ruthless Gladiator's Ornamented Chestguard
	 70477,// Ruthless Gladiator's Plate Shoulders
	 70478,// Ruthless Gladiator's Plate Legguards
	 70479,// Ruthless Gladiator's Plate Helm
	 70480,// Ruthless Gladiator's Plate Gauntlets
	 70481,// Ruthless Gladiator's Plate Chestpiece
	 70482,// Ruthless Gladiator's Scaled Shoulders
	 70483,// Ruthless Gladiator's Scaled Legguards
	 70487,// Ruthless Gladiator's Scaled Helm
	 70488,// Ruthless Gladiator's Scaled Gauntlets
	 70489,// Ruthless Gladiator's Scaled Chestpiece
	 70490,// Ruthless Gladiator's Dreadplate Shoulders
	 70491,// Ruthless Gladiator's Dreadplate Legguards
	 70492,// Ruthless Gladiator's Dreadplate Helm
	 70493,// Ruthless Gladiator's Dreadplate Gauntlets
	 70494,// Ruthless Gladiator's Dreadplate Chestpiece
	 70502,// Ruthless Gladiator's Greaves of Alacrity
	 70503,// Ruthless Gladiator's Greaves of Meditation
	 70504,// Ruthless Gladiator's Warboots of Cruelty
	 70505,// Ruthless Gladiator's Warboots of Alacrity
	 70513,// Vicious Gladiator's Armplates of Alacrity
	 70514,// Vicious Gladiator's Armplates of Proficiency
	 70529,// Vicious Gladiator's Bracers of Meditation
	 70530,// Vicious Gladiator's Bracers of Prowess
	 70540,// Vicious Gladiator's Clasp of Cruelty
	 70541,// Vicious Gladiator's Clasp of Meditation
	 70558,// Vicious Gladiator's Dreadplate Chestpiece
	 70559,// Vicious Gladiator's Dreadplate Gauntlets
	 70560,// Vicious Gladiator's Dreadplate Helm
	 70561,// Vicious Gladiator's Dreadplate Legguards
	 70562,// Vicious Gladiator's Dreadplate Shoulders
	 70573,// Vicious Gladiator's Girdle of Cruelty
	 70574,// Vicious Gladiator's Girdle of Prowess
	 70575,// Vicious Gladiator's Greaves of Alacrity
	 70576,// Vicious Gladiator's Greaves of Meditation
	 70615,// Vicious Gladiator's Ornamented Chestguard
	 70616,// Vicious Gladiator's Ornamented Gloves
	 70617,// Vicious Gladiator's Ornamented Headcover
	 70618,// Vicious Gladiator's Ornamented Legplates
	 70619,// Vicious Gladiator's Ornamented Spaulders
	 70623,// Vicious Gladiator's Plate Chestpiece
	 70624,// Vicious Gladiator's Plate Gauntlets
	 70625,// Vicious Gladiator's Plate Helm
	 70626,// Vicious Gladiator's Plate Legguards
	 70627,// Vicious Gladiator's Plate Shoulders
	 70648,// Vicious Gladiator's Scaled Chestpiece
	 70649,// Vicious Gladiator's Scaled Gauntlets
	 70650,// Vicious Gladiator's Scaled Helm
	 70651,// Vicious Gladiator's Scaled Legguards
	 70652,// Vicious Gladiator's Scaled Shoulders
	 70667,// Vicious Gladiator's Warboots of Alacrity
	 70668,// Vicious Gladiator's Warboots of Cruelty
	 70734,// Greathelm of the Voracious Maw
	 70737,// Spaulders of Recurring Flame
	 70739,// Lavaworm Legplates
	 70912,// Cracked Obsidian Stompers
	 70913,// Legplates of Frenzied Devotion
	 70914,// Carapace of Imbibed Flame
	 70916,// Helm of Blazing Glory
	 70917,// Flickering Handguards
	 70920,// Bracers of the Fiery Path
	 70921,// Pauldrons of Roaring Flame
	 70933,// Girdle of the Indomitable Flame
	 70937,// Bracers of Regal Force
	 70941,// Shoulderguards of the Molten Giant
	 70942,// Legguards of the Molten Giant
	 70943,// Handguards of the Molten Giant
	 70944,// Faceguard of the Molten Giant
	 70945,// Chestguard of the Molten Giant
	 70946,// Immolation Shoulderguards
	 70947,// Immolation Legguards
	 70948,// Immolation Faceguard
	 70949,// Immolation Handguards
	 70950,// Immolation Chestguard
	 70951,// Elementium Deathplate Shoulderguards
	 70952,// Elementium Deathplate Legguards
	 70953,// Elementium Deathplate Handguards
	 70954,// Elementium Deathplate Faceguard
	 70955,// Elementium Deathplate Chestguard
	 70988,// Clutch of the Firemother
	 70993,// Fireskin Gauntlets
	 71004,// Earthcrack Bracers
	 71007,// Grips of the Raging Giant
	 71021,// Uncrushable Belt of Fury
	 71026,// Bracers of the Dread Hunter
	 71028,// Legplates of Absolute Control
	 71029,// Arachnaflame Treads
	 71043,// Spaulders of Manifold Eyes
	 71058,// Elementium Deathplate Breastplate
	 71059,// Elementium Deathplate Gauntlets
	 71060,// Elementium Deathplate Helmet
	 71061,// Elementium Deathplate Greaves
	 71062,// Elementium Deathplate Pauldrons
	 71063,// Immolation Battleplate
	 71064,// Immolation Gauntlets
	 71065,// Immolation Helmet
	 71066,// Immolation Legplates
	 71067,// Immolation Pauldrons
	 71068,// Battleplate of the Molten Giant
	 71069,// Gauntlets of the Molten Giant
	 71070,// Helmet of the Molten Giant
	 71071,// Legplates of the Molten Giant
	 71072,// Pauldrons of the Molten Giant
	 71091,// Immolation Breastplate
	 71092,// Immolation Gloves
	 71093,// Immolation Headguard
	 71094,// Immolation Greaves
	 71095,// Immolation Mantle
	 71250,// Cinch of the Flaming Ember
	 71253,// Belt of the Seven Seals
	 71260,// Bracers of Imperious Truths
	 71261,// Gigantiform Bracers
	 71326,// The Horseman's Horrific Helmet
	 71342,// Casque of Flame
	 71344,// Breastplate of Shifting Visions
	 71351,// Treads of the Penitent Man
	 71398,// Belt of the Seven Seals
	 71399,// Cinch of the Flaming Ember
	 71400,// Girdle of the Indomitable Flame
	 71404,// Arachnaflame Treads
	 71405,// Carapace of Imbibed Flame
	 71413,// Spaulders of Manifold Eyes
	 71418,// Earthcrack Bracers
	 71419,// Fireskin Gauntlets
	 71420,// Cracked Obsidian Stompers
	 71426,// Grips of the Raging Giant
	 71430,// Greathelm of the Voracious Maw
	 71431,// Lavaworm Legplates
	 71432,// Spaulders of Recurring Flame
	 71439,// Clutch of the Firemother
	 71443,// Uncrushable Belt of Fury
	 71444,// Legplates of Frenzied Devotion
	 71452,// Bracers of the Dread Hunter
	 71453,// Legplates of Absolute Control
	 71458,// Flickering Handguards
	 71459,// Helm of Blazing Glory
	 71465,// Casque of Flame
	 71469,// Breastplate of Shifting Visions
	 71470,// Bracers of the Fiery Path
	 71475,// Treads of the Penitent Man
	 71476,// Elementium Deathplate Breastplate
	 71477,// Elementium Deathplate Gauntlets
	 71478,// Elementium Deathplate Helmet
	 71479,// Elementium Deathplate Greaves
	 71480,// Elementium Deathplate Pauldrons
	 71481,// Elementium Deathplate Chestguard
	 71482,// Elementium Deathplate Handguards
	 71483,// Elementium Deathplate Faceguard
	 71484,// Elementium Deathplate Legguards
	 71485,// Elementium Deathplate Shoulderguards
	 71512,// Immolation Battleplate
	 71513,// Immolation Gauntlets
	 71514,// Immolation Helmet
	 71515,// Immolation Legplates
	 71516,// Immolation Pauldrons
	 71517,// Immolation Breastplate
	 71518,// Immolation Gloves
	 71519,// Immolation Headguard
	 71520,// Immolation Greaves
	 71521,// Immolation Mantle
	 71522,// Immolation Chestguard
	 71523,// Immolation Handguards
	 71524,// Immolation Faceguard
	 71525,// Immolation Legguards
	 71526,// Immolation Shoulderguards
	 71583,// Bracers of Imperious Truths
	 71584,// Gigantiform Bracers
	 71585,// Bracers of Regal Force
	 71599,// Helmet of the Molten Giant
	 71600,// Battleplate of the Molten Giant
	 71601,// Gauntlets of the Molten Giant
	 71602,// Legplates of the Molten Giant
	 71603,// Pauldrons of the Molten Giant
	 71604,// Chestguard of the Molten Giant
	 71605,// Handguards of the Molten Giant
	 71606,// Faceguard of the Molten Giant
	 71607,// Legguards of the Molten Giant
	 71608,// Shoulderguards of the Molten Giant
	 71612,// Pauldrons of Roaring Flame
	 71982,// Pyrium Legplates of Purified Evil
	 71983,// Unstoppable Destroyer's Legplates
	 71984,// Foundations of Courage
	 71991,// Soul Redeemer Bracers
	 71992,// Bracers of Destructive Strength
	 71993,// Titanguard Wristplates
	 72332,// Ruthless Gladiator's Dreadplate Chestpiece
	 72333,// Ruthless Gladiator's Dreadplate Gauntlets
	 72334,// Ruthless Gladiator's Dreadplate Helm
	 72335,// Ruthless Gladiator's Dreadplate Legguards
	 72336,// Ruthless Gladiator's Dreadplate Shoulders
	 72378,// Ruthless Gladiator's Scaled Chestpiece
	 72379,// Ruthless Gladiator's Scaled Gauntlets
	 72380,// Ruthless Gladiator's Scaled Helm
	 72381,// Ruthless Gladiator's Scaled Legguards
	 72382,// Ruthless Gladiator's Scaled Shoulders
	 72383,// Ruthless Gladiator's Clasp of Cruelty
	 72384,// Ruthless Gladiator's Clasp of Meditation
	 72385,// Ruthless Gladiator's Greaves of Alacrity
	 72386,// Ruthless Gladiator's Greaves of Meditation
	 72387,// Ruthless Gladiator's Bracers of Prowess
	 72388,// Ruthless Gladiator's Bracers of Meditation
	 72389,// Ruthless Gladiator's Ornamented Chestguard
	 72390,// Ruthless Gladiator's Ornamented Gloves
	 72391,// Ruthless Gladiator's Ornamented Headcover
	 72392,// Ruthless Gladiator's Ornamented Legplates
	 72393,// Ruthless Gladiator's Ornamented Spaulders
	 72394,// Ruthless Gladiator's Girdle of Accuracy
	 72395,// Ruthless Gladiator's Girdle of Prowess
	 72396,// Ruthless Gladiator's Warboots of Cruelty
	 72397,// Ruthless Gladiator's Warboots of Alacrity
	 72398,// Ruthless Gladiator's Armplates of Proficiency
	 72399,// Ruthless Gladiator's Armplates of Alacrity
	 72464,// Ruthless Gladiator's Plate Chestpiece
	 72465,// Ruthless Gladiator's Plate Gauntlets
	 72466,// Ruthless Gladiator's Plate Helm
	 72467,// Ruthless Gladiator's Plate Legguards
	 72468,// Ruthless Gladiator's Plate Shoulders
	 72800,// Gauntlets of Temporal Interference
	 72801,// Breastplate of Sorrow
	 72803,// Girdle of Lost Heroes
	 72807,// Waistguard of Lost Time
	 72815,// Bloodhoof Legguards
	 72817,// Time Altered Legguards
	 72818,// Breastplate of Tarnished Bronze
	 72819,// Chrono Boots
	 72820,// Crown of Epochs
	 72821,// Temporal Pauldrons
	 72832,// Girdle of the Queen's Champion
	 72842,// Annihilan Helm
	 72843,// Helm of Power
	 72853,// Arcurion Legguards
	 72861,// Pauldrons of the Dragonblight
	 72864,// Pauldrons of Conviction
	 72872,// Time Strand Gauntlets
	 72879,// Boots of the Treacherous Path
	 72881,// Treads of the Past
	 72918,// Ebonsoul Breastplate
	 72919,// Ebonsoul Sabatons
	 72920,// Ebonsoul Gauntlets
	 72921,// Ebonsoul Helm
	 72922,// Ebonsoul Legplates
	 72923,// Ebonsoul Pauldrons
	 72924,// Ebonsoul Girdle
	 72925,// Ebonsoul Vambraces
	 72929,// Ebonsoul Chestguard
	 72930,// Ebonsoul Greaves
	 72931,// Ebonsoul Handguards
	 72932,// Ebonsoul Faceguard
	 72933,// Ebonsoul Legguards
	 72934,// Ebonsoul Shoulderguards
	 72935,// Ebonsoul Waistband
	 72936,// Ebonsoul Armguards
	 72937,// Valiant Chestguard
	 72938,// Valiant Greaves
	 72939,// Valiant Handguards
	 72940,// Valiant Faceguard
	 72941,// Valiant Legguards
	 72942,// Valiant Shoulderguards
	 72943,// Valiant Waistband
	 72944,// Valiant Armguards
	 72945,// Valiant Breastplate
	 72946,// Valiant Sabatons
	 72947,// Valiant Gauntlets
	 72948,// Valiant Helm
	 72949,// Valiant Legplates
	 72950,// Valiant Pauldrons
	 72951,// Valiant Girdle
	 72952,// Valiant Vambraces
	 72955,// Zealous Battleplate
	 72956,// Zealous Sabatons
	 72957,// Zealous Gauntlets
	 72958,// Zealous Helm
	 72959,// Zealous Legplates
	 72960,// Zealous Pauldrons
	 72961,// Zealous Girdle
	 72962,// Zealous Vambraces
	 72963,// Zealous Chestguard
	 72964,// Zealous Greaves
	 72965,// Zealous Handguards
	 72966,// Zealous Faceguard
	 72967,// Zealous Legguards
	 72968,// Zealous Shoulderguards
	 72969,// Zealous Waistband
	 72970,// Zealous Armguards
	 72971,// Zealous Breastplate
	 72972,// Zealous Boots
	 72973,// Zealous Gloves
	 72974,// Zealous Headpiece
	 72975,// Zealous Leggings
	 72976,// Zealous Spaulders
	 72977,// Zealous Belt
	 72978,// Zealous Armplates
	 73478,// Cataclysmic Gladiator's Plate Shoulders
	 73479,// Cataclysmic Gladiator's Plate Legguards
	 73480,// Cataclysmic Gladiator's Plate Helm
	 73481,// Cataclysmic Gladiator's Plate Gauntlets
	 73482,// Cataclysmic Gladiator's Plate Chestpiece
	 73550,// Cataclysmic Gladiator's Armplates of Alacrity
	 73551,// Cataclysmic Gladiator's Armplates of Proficiency
	 73552,// Cataclysmic Gladiator's Warboots of Alacrity
	 73553,// Cataclysmic Gladiator's Warboots of Cruelty
	 73554,// Cataclysmic Gladiator's Girdle of Prowess
	 73555,// Cataclysmic Gladiator's Girdle of Cruelty
	 73556,// Cataclysmic Gladiator's Ornamented Spaulders
	 73557,// Cataclysmic Gladiator's Ornamented Legplates
	 73558,// Cataclysmic Gladiator's Ornamented Headcover
	 73559,// Cataclysmic Gladiator's Ornamented Gloves
	 73560,// Cataclysmic Gladiator's Ornamented Chestguard
	 73561,// Cataclysmic Gladiator's Bracers of Meditation
	 73562,// Cataclysmic Gladiator's Bracers of Prowess
	 73563,// Cataclysmic Gladiator's Greaves of Meditation
	 73564,// Cataclysmic Gladiator's Greaves of Alacrity
	 73565,// Cataclysmic Gladiator's Clasp of Meditation
	 73566,// Cataclysmic Gladiator's Clasp of Cruelty
	 73567,// Cataclysmic Gladiator's Scaled Shoulders
	 73568,// Cataclysmic Gladiator's Scaled Legguards
	 73569,// Cataclysmic Gladiator's Scaled Helm
	 73570,// Cataclysmic Gladiator's Scaled Gauntlets
	 73571,// Cataclysmic Gladiator's Scaled Chestpiece
	 73616,// Cataclysmic Gladiator's Dreadplate Shoulders
	 73617,// Cataclysmic Gladiator's Dreadplate Legguards
	 73618,// Cataclysmic Gladiator's Dreadplate Helm
	 73619,// Cataclysmic Gladiator's Dreadplate Gauntlets
	 73620,// Cataclysmic Gladiator's Dreadplate Chestpiece
	 73651,// Cataclysmic Gladiator's Plate Shoulders
	 73652,// Cataclysmic Gladiator's Plate Legguards
	 73653,// Cataclysmic Gladiator's Plate Helm
	 73654,// Cataclysmic Gladiator's Plate Gauntlets
	 73655,// Cataclysmic Gladiator's Plate Chestpiece
	 73695,// Cataclysmic Gladiator's Warboots of Alacrity
	 73696,// Cataclysmic Gladiator's Warboots of Cruelty
	 73697,// Cataclysmic Gladiator's Ornamented Spaulders
	 73698,// Cataclysmic Gladiator's Ornamented Legplates
	 73699,// Cataclysmic Gladiator's Ornamented Headcover
	 73700,// Cataclysmic Gladiator's Ornamented Gloves
	 73701,// Cataclysmic Gladiator's Ornamented Chestguard
	 73702,// Cataclysmic Gladiator's Greaves of Meditation
	 73703,// Cataclysmic Gladiator's Greaves of Alacrity
	 73704,// Cataclysmic Gladiator's Scaled Shoulders
	 73705,// Cataclysmic Gladiator's Scaled Legguards
	 73706,// Cataclysmic Gladiator's Scaled Helm
	 73707,// Cataclysmic Gladiator's Scaled Gauntlets
	 73708,// Cataclysmic Gladiator's Scaled Chestpiece
	 73738,// Cataclysmic Gladiator's Dreadplate Shoulders
	 73739,// Cataclysmic Gladiator's Dreadplate Legguards
	 73740,// Cataclysmic Gladiator's Dreadplate Helm
	 73741,// Cataclysmic Gladiator's Dreadplate Gauntlets
	 73742,// Cataclysmic Gladiator's Dreadplate Chestpiece
	 75118,// Vicious Ornate Pyrium Belt
	 75119,// Vicious Pyrium Shoulders
	 75120,// Vicious Pyrium Boots
	 75121,// Vicious Ornate Pyrium Gauntlets
	 75122,// Vicious Pyrium Gauntlets
	 75123,// Vicious Pyrium Belt
	 75124,// Vicious Pyrium Bracers
	 75125,// Vicious Ornate Pyrium Bracers
	 75126,// Vicious Pyrium Helm
	 75128,// Vicious Ornate Pyrium Breastplate
	 75129,// Vicious Ornate Pyrium Helm
	 75132,// Vicious Ornate Pyrium Boots
	 75133,// Vicious Ornate Pyrium Legguards
	 75134,// Vicious Ornate Pyrium Shoulders
	 75135,// Vicious Pyrium Breastplate
	 75136,// Vicious Pyrium Legguards
	 76154,// Breastplate of Despair
	 76156,// Bindings of the End Times
	 76765,// Breastplate of Radiant Glory
	 76766,// Gloves of Radiant Glory
	 76767,// Headguard of Radiant Glory
	 76768,// Greaves of Radiant Glory
	 76769,// Mantle of Radiant Glory
	 76874,// Battleplate of Radiant Glory
	 76875,// Gauntlets of Radiant Glory
	 76876,// Helmet of Radiant Glory
	 76877,// Legplates of Radiant Glory
	 76878,// Pauldrons of Radiant Glory
	 76974,// Necrotic Boneplate Breastplate
	 76975,// Necrotic Boneplate Gauntlets
	 76976,// Necrotic Boneplate Helmet
	 76977,// Necrotic Boneplate Greaves
	 76978,// Necrotic Boneplate Pauldrons
	 76983,// Colossal Dragonplate Helmet
	 76984,// Colossal Dragonplate Battleplate
	 76985,// Colossal Dragonplate Gauntlets
	 76986,// Colossal Dragonplate Legplates
	 76987,// Colossal Dragonplate Pauldrons
	 76988,// Colossal Dragonplate Chestguard
	 76989,// Colossal Dragonplate Handguards
	 76990,// Colossal Dragonplate Faceguard
	 76991,// Colossal Dragonplate Legguards
	 76992,// Colossal Dragonplate Shoulderguards
	 77003,// Chestguard of Radiant Glory
	 77004,// Handguards of Radiant Glory
	 77005,// Faceguard of Radiant Glory
	 77006,// Legguards of Radiant Glory
	 77007,// Shoulderguards of Radiant Glory
	 77008,// Necrotic Boneplate Chestguard
	 77009,// Necrotic Boneplate Handguards
	 77010,// Necrotic Boneplate Faceguard
	 77011,// Necrotic Boneplate Legguards
	 77012,// Necrotic Boneplate Shoulderguards
	 77119,// Bones of the Damned
	 77120,// Chestplate of the Unshakable Titan
	 77123,// Shining Carapace of Glory
	 77153,// Glowing Wings of Hope
	 77155,// Visage of Petrification
	 77156,// Jaw of Repudiation
	 77164,// Gleaming Grips of Mending
	 77165,// Grimfist Crushers
	 77166,// Gauntlets of Feathery Blows
	 77169,// Silver Sabatons of Fury
	 77170,// Kneebreaker Boots
	 77171,// Bladeshatter Treads
	 77184,// Blinding Girdle of Truth
	 77185,// Demonbone Waistguard
	 77186,// Forgesmelter Waistplate
	 77235,// Gauntlets of the Golden Thorn
	 77236,// Backbreaker Spaulders
	 77239,// Goriona's Collar
	 77244,// Dragonfracture Belt
	 77246,// Stillheart Warboots
	 77250,// Runescriven Demon Collar
	 77253,// Heartblood Wristplates
	 77258,// Graveheart Bracers
	 77259,// Treads of Crushed Flesh
	 77265,// Pillarfoot Greaves
	 77268,// Brackenshell Shoulderplates
	 77270,// Rockhide Bracers
	 77316,// Flashing Bracers of Warmth
	 77317,// Heartcrusher Wristplates
	 77318,// Bracers of Unrelenting Excellence
	 77538,// Specialized Retinal Armor
	 77539,// Reinforced Retinal Armor
	 78361,// Pillarfoot Greaves
	 78367,// Brackenshell Shoulderplates
	 78373,// Rockhide Bracers
	 78377,// Rockhide Bracers
	 78378,// Brackenshell Shoulderplates
	 78386,// Pillarfoot Greaves
	 78389,// Treads of Crushed Flesh
	 78390,// Graveheart Bracers
	 78396,// Treads of Crushed Flesh
	 78397,// Graveheart Bracers
	 78406,// Heartblood Wristplates
	 78412,// Heartblood Wristplates
	 78416,// Runescriven Demon Collar
	 78424,// Runescriven Demon Collar
	 78431,// Stillheart Warboots
	 78436,// Dragonfracture Belt
	 78439,// Stillheart Warboots
	 78444,// Dragonfracture Belt
	 78452,// Goriona's Collar
	 78460,// Goriona's Collar
	 78464,// Gauntlets of the Golden Thorn
	 78465,// Backbreaker Spaulders
	 78469,// Gauntlets of the Golden Thorn
	 78470,// Backbreaker Spaulders
	 78499,// Bones of the Damned
	 78500,// Chestplate of the Unshakable Titan
	 78503,// Shining Carapace of Glory
	 78511,// Bladeshatter Treads
	 78514,// Silver Sabatons of Fury
	 78515,// Kneebreaker Boots
	 78525,// Grimfist Crushers
	 78526,// Gauntlets of Feathery Blows
	 78529,// Gleaming Grips of Mending
	 78534,// Visage of Petrification
	 78535,// Jaw of Repudiation
	 78538,// Glowing Wings of Hope
	 78560,// Forgesmelter Waistplate
	 78563,// Blinding Girdle of Truth
	 78564,// Demonbone Waistguard
	 78569,// Heartcrusher Wristplates
	 78570,// Bracers of Unrelenting Excellence
	 78573,// Flashing Bracers of Warmth
	 78578,// Shining Carapace of Glory
	 78583,// Bones of the Damned
	 78584,// Chestplate of the Unshakable Titan
	 78590,// Kneebreaker Boots
	 78591,// Bladeshatter Treads
	 78593,// Silver Sabatons of Fury
	 78605,// Grimfist Crushers
	 78606,// Gauntlets of Feathery Blows
	 78612,// Gleaming Grips of Mending
	 78614,// Visage of Petrification
	 78615,// Jaw of Repudiation
	 78621,// Glowing Wings of Hope
	 78644,// Blinding Girdle of Truth
	 78645,// Demonbone Waistguard
	 78646,// Forgesmelter Waistplate
	 78648,// Flashing Bracers of Warmth
	 78649,// Heartcrusher Wristplates
	 78650,// Bracers of Unrelenting Excellence
	 78657,// Colossal Dragonplate Battleplate
	 78658,// Colossal Dragonplate Chestguard
	 78659,// Necrotic Boneplate Breastplate
	 78663,// Necrotic Boneplate Chestguard
	 78668,// Colossal Dragonplate Gauntlets
	 78669,// Colossal Dragonplate Handguards
	 78670,// Necrotic Boneplate Gauntlets
	 78673,// Gloves of Radiant Glory
	 78675,// Gauntlets of Radiant Glory
	 78677,// Handguards of Radiant Glory
	 78678,// Necrotic Boneplate Handguards
	 78687,// Necrotic Boneplate Helmet
	 78688,// Colossal Dragonplate Helmet
	 78689,// Colossal Dragonplate Faceguard
	 78692,// Headguard of Radiant Glory
	 78693,// Helmet of Radiant Glory
	 78695,// Faceguard of Radiant Glory
	 78697,// Necrotic Boneplate Faceguard
	 78705,// Colossal Dragonplate Legguards
	 78706,// Colossal Dragonplate Legplates
	 78707,// Necrotic Boneplate Greaves
	 78712,// Legplates of Radiant Glory
	 78715,// Legguards of Radiant Glory
	 78716,// Necrotic Boneplate Legguards
	 78717,// Greaves of Radiant Glory
	 78726,// Breastplate of Radiant Glory
	 78727,// Battleplate of Radiant Glory
	 78732,// Chestguard of Radiant Glory
	 78734,// Colossal Dragonplate Shoulderguards
	 78735,// Colossal Dragonplate Pauldrons
	 78736,// Necrotic Boneplate Pauldrons
	 78742,// Pauldrons of Radiant Glory
	 78745,// Shoulderguards of Radiant Glory
	 78746,// Mantle of Radiant Glory
	 78751,// Necrotic Boneplate Shoulderguards
	 78752,// Colossal Dragonplate Battleplate
	 78753,// Colossal Dragonplate Chestguard
	 78754,// Necrotic Boneplate Breastplate
	 78758,// Necrotic Boneplate Chestguard
	 78763,// Colossal Dragonplate Gauntlets
	 78764,// Colossal Dragonplate Handguards
	 78765,// Necrotic Boneplate Gauntlets
	 78768,// Gloves of Radiant Glory
	 78770,// Gauntlets of Radiant Glory
	 78772,// Handguards of Radiant Glory
	 78773,// Necrotic Boneplate Handguards
	 78782,// Necrotic Boneplate Helmet
	 78783,// Colossal Dragonplate Helmet
	 78784,// Colossal Dragonplate Faceguard
	 78787,// Headguard of Radiant Glory
	 78788,// Helmet of Radiant Glory
	 78790,// Faceguard of Radiant Glory
	 78792,// Necrotic Boneplate Faceguard
	 78800,// Colossal Dragonplate Legguards
	 78801,// Colossal Dragonplate Legplates
	 78802,// Necrotic Boneplate Greaves
	 78807,// Legplates of Radiant Glory
	 78810,// Legguards of Radiant Glory
	 78811,// Necrotic Boneplate Legguards
	 78812,// Greaves of Radiant Glory
	 78821,// Breastplate of Radiant Glory
	 78822,// Battleplate of Radiant Glory
	 78827,// Chestguard of Radiant Glory
	 78829,// Colossal Dragonplate Shoulderguards
	 78830,// Colossal Dragonplate Pauldrons
	 78831,// Necrotic Boneplate Pauldrons
	 78837,// Pauldrons of Radiant Glory
	 78840,// Shoulderguards of Radiant Glory
	 78841,// Mantle of Radiant Glory
	 78846,// Necrotic Boneplate Shoulderguards
	 78887,// Girdle of Soulful Mending
	 78888,// Waistguard of Bleeding Bone
	 78889,// Waistplate of the Desecrated Future
	 80689,// Glass Lake Headcover
	 80693,// Thunderwood Helm
	 80694,// Jade Tiger Helm
	 80698,// Glass Lake Spaulders
	 80702,// Thunderwood Shoulders
	 80703,// Jade Tiger Shoulders
	 80707,// Glass Lake Chestguard
	 80711,// Thunderwood Chestpiece
	 80712,// Jade Tiger Chestpiece
	 80716,// Glass Lake Legplates
	 80720,// Thunderwood Legguards
	 80721,// Jade Tiger Legguards
	 80725,// Glass Lake Greaves
	 80729,// Thunderwood Warboots
	 80730,// Jade Tiger Warboots
	 80734,// Glass Lake Clasp
	 80738,// Thunderwood Girdle
	 80739,// Jade Tiger Girdle
	 80743,// Glass Lake Gloves
	 80747,// Thunderwood Gauntlets
	 80748,// Jade Tiger Gauntlets
	 80752,// Glass Lake Bracers
	 80756,// Thunderwood Armplates
	 80757,// Jade Tiger Armplates
	 80811,// Spiritguard Helm
	 80861,// Riverbed Chestguard
	 80863,// Stonestep Boots
	 80867,// Serpentstrike Shoulderpads
	 80899,// Bubble-Breaker Bracers
	 80901,// Sudsy Legplates
	 80908,// Sparkbreath Girdle
	 80911,// Quivering Heart Girdle
	 80912,// Gauntlets of Resolute Fury
	 80915,// Spike-Soled Stompers
	 80918,// Mindbinder Plate Gloves
	 80924,// Acid-Scarred Spaulders
	 80927,// Hive Protector's Gauntlets
	 80930,// Swarmbringer Chestguard
	 80952,// Peacebreaker's Burnished Headcover
	 80953,// Peacebreaker's Armored Helm
	 80954,// Peacebreaker's Heavy Helm
	 80992,// Scavenger's Burnished Spaulders
	 80993,// Scavenger's Armored Shoulders
	 80994,// Scavenger's Heavy Shoulders
	 81001,// Burnished Chestguard of Eminent Domain
	 81002,// Armored Chestpiece of Eminent Domain
	 81003,// Heavy Chestpiece of Eminent Domain
	 81010,// Honorary Combat Engineer's Burnished Legplates
	 81011,// Honorary Combat Engineer's Legguards
	 81012,// Honorary Combat Engineer's Heavy Legplates
	 81019,// Landfall Burnished Greaves
	 81020,// Landfall Warboots
	 81021,// Landfall Plate Boots
	 81028,// Cagebreaker's Burnished Clasp
	 81029,// Cagebreaker's Armored Girdle
	 81030,// Cagebreaker's Heavy Girdle
	 81037,// Scavenger's Burnished Gloves
	 81038,// Scavenger's Armored Gauntlets
	 81039,// Scavenger's Heavy Gauntlets
	 81046,// Scavenger's Burnished Bracers
	 81047,// Scavenger's Armored Bracers
	 81048,// Scavenger's Heavy Armplates
	 81065,// Bubble-Breaker Bracers
	 81070,// Serpentstrike Shoulderpads
	 81073,// Stonestep Boots
	 81078,// Sudsy Legplates
	 81083,// Riverbed Chestguard
	 81086,// Sparkbreath Girdle
	 81087,// Quivering Heart Girdle
	 81098,// Acid-Scarred Spaulders
	 81100,// Hive Protector's Gauntlets
	 81101,// Gauntlets of Resolute Fury
	 81103,// Mindbinder Plate Gloves
	 81109,// Swarmbringer Chestguard
	 81113,// Spike-Soled Stompers
	 81130,// Binding of Broken Dreams
	 81134,// Barreldodger Boots
	 81187,// Hateshatter Chestplate
	 81190,// Grenadier's Belt
	 81230,// Ri'mok's Shattered Scale
	 81241,// Meteoric Greathelm
	 81242,// Glintrok Sollerets
	 81248,// Axebreaker Gauntlets
	 81256,// Mind's Eye Breastplate
	 81270,// Sap-Encrusted Legplates
	 81272,// Girdle of Soothing Detonation
	 81274,// Sightfinder Helm
	 81280,// Siegeworn Bracers
	 81284,// Anchoring Sabatons
	 81287,// Spaulders of Immovable Stone
	 81443,// Narsong Headcover
	 81447,// Korjan Helm
	 81448,// Dojani Helm
	 81452,// Narsong Spaulders
	 81456,// Korjan Shoulders
	 81457,// Dojani Shoulders
	 81461,// Narsong Chestguard
	 81465,// Korjan Chestpiece
	 81466,// Dojani Chestpiece
	 81470,// Narsong Legplates
	 81474,// Korjan Legguards
	 81475,// Dojani Legguards
	 81479,// Narsong Greaves
	 81483,// Korjan Warboots
	 81484,// Dojani Warboots
	 81488,// Narsong Clasp
	 81492,// Korjan Girdle
	 81493,// Dojani Girdle
	 81497,// Narsong Gloves
	 81501,// Korjan Gauntlets
	 81502,// Dojani Gauntlets
	 81506,// Narsong Bracers
	 81510,// Korjan Armplates
	 81511,// Dojani Bracers
	 81572,// Bracers of the Fallen Crusader
	 81574,// Helm of Rising Flame
	 81578,// Crown of Holy Flame
	 81582,// Faded Forest Burnished Headcover
	 81586,// Faded Forest Heavy Helm
	 81587,// Faded Forest Armored Helm
	 81591,// Faded Forest Burnished Spaulders
	 81595,// Faded Forest Heavy Shoulders
	 81596,// Faded Forest Armored Shoulders
	 81600,// Faded Forest Burnished Chestguard
	 81604,// Faded Forest Heavy Chestpiece
	 81605,// Faded Forest Armored Chestpiece
	 81609,// Faded Forest Burnished Legplates
	 81613,// Faded Forest Heavy Legguards
	 81614,// Faded Forest Armored Legguards
	 81618,// Faded Forest Burnished Greaves
	 81622,// Faded Forest Heavy Warboots
	 81623,// Faded Forest Armored Warboots
	 81627,// Faded Forest Burnished Clasp
	 81631,// Faded Forest Heavy Girdle
	 81632,// Faded Forest Armored Girdle
	 81636,// Faded Forest Burnished Gloves
	 81640,// Faded Forest Heavy Gauntlets
	 81641,// Faded Forest Armored Gauntlets
	 81645,// Faded Forest Burnished Bracers
	 81649,// Faded Forest Heavy Armplates
	 81650,// Faded Forest Armored Bracers
	 81687,// Waistplate of Imminent Resurrection
	 81694,// Commanding Bracers
	 81696,// Canine Commander's Breastplate
	 81704,// Ymirjar Lord's Battleplate
	 81705,// Ymirjar Lord's Gauntlets
	 81706,// Ymirjar Lord's Helmet
	 81707,// Ymirjar Lord's Legplates
	 81708,// Ymirjar Lord's Shoulderplates
	 81709,// Belt of Broken Bones
	 81710,// Grinning Skull Greatboots
	 81745,// Paoquan Burnished Headcover
	 81749,// Thunderfoot Heavy Helm
	 81750,// Sunsong Armored Helm
	 81754,// Paoquan Burnished Spaulders
	 81758,// Thunderfoot Heavy Shoulders
	 81759,// Sunsong Armored Shoulders
	 81763,// Paoquan Burnished Chestguard
	 81767,// Thunderfoot Heavy Chestpiece
	 81768,// Sunsong Armored Chestpiece
	 81772,// Paoquan Burnished Legplates
	 81776,// Thunderfoot Heavy Legguards
	 81777,// Sunsong Armored Legguards
	 81781,// Paoquan Burnished Greaves
	 81785,// Thunderfoot Heavy Warboots
	 81786,// Sunsong Armored Warboots
	 81790,// Paoquan Burnished Clasp
	 81794,// Thunderfoot Heavy Girdle
	 81795,// Sunsong Armored Girdle
	 81799,// Paoquan Burnished Gloves
	 81803,// Thunderfoot Heavy Gauntlets
	 81804,// Sunsong Armored Gauntlets
	 81808,// Paoquan Burnished Bracers
	 81812,// Thunderfoot Heavy Armplates
	 81813,// Sunsong Armored Bracers
	 81990,// Wall Girdle
	 81991,// Wall Pauldrons
	 81992,// Wall Legplates
	 81993,// Wall Helm
	 81994,// Wall Gauntlets
	 81995,// Wall Sabatons
	 81996,// Wall Breastplate
	 81997,// Wall Vambraces
	 82067,// Brick Breastplate
	 82068,// Brick Gauntlets
	 82069,// Brick Girdle
	 82070,// Brick Helm
	 82071,// Brick Legplates
	 82072,// Brick Pauldrons
	 82073,// Brick Sabatons
	 82075,// Brick Vambraces
	 82122,// Miner Breastplate
	 82123,// Miner Gauntlets
	 82124,// Miner Girdle
	 82125,// Miner Helm
	 82126,// Miner Legplates
	 82127,// Miner Pauldrons
	 82128,// Miner Sabatons
	 82130,// Miner Vambraces
	 82177,// Snowy Breastplate
	 82178,// Snowy Gauntlets
	 82179,// Snowy Girdle
	 82180,// Snowy Helm
	 82181,// Snowy Legplates
	 82182,// Snowy Pauldrons
	 82183,// Snowy Sabatons
	 82185,// Snowy Vambraces
	 82232,// Highpeak Breastplate
	 82233,// Highpeak Gauntlets
	 82234,// Highpeak Girdle
	 82235,// Highpeak Helm
	 82236,// Highpeak Legplates
	 82237,// Highpeak Pauldrons
	 82238,// Highpeak Sabatons
	 82240,// Highpeak Vambraces
	 82287,// Temple Breastplate
	 82288,// Temple Gauntlets
	 82289,// Temple Girdle
	 82290,// Temple Helm
	 82291,// Temple Legplates
	 82292,// Temple Pauldrons
	 82293,// Temple Sabatons
	 82295,// Temple Vambraces
	 82490,// Serenity Headcover
	 82494,// Summit Guardian Helm
	 82495,// Wallwatcher Helm
	 82499,// Serenity Spaulders
	 82503,// Summit Guardian Shoulders
	 82504,// Wallwatcher Shoulders
	 82508,// Serenity Chestguard
	 82512,// Summit Guardian Chestpiece
	 82513,// Wallwatcher Chestpiece
	 82517,// Serenity Legplates
	 82521,// Summit Guardian Legguards
	 82522,// Wallwatcher Legguards
	 82526,// Serenity Greaves
	 82530,// Summit Guardian Warboots
	 82531,// Wallwatcher Warboots
	 82535,// Serenity Clasp
	 82539,// Summit Guardian Girdle
	 82540,// Wallwatcher Girdle
	 82544,// Serenity Gloves
	 82548,// Summit Guardian Gauntlets
	 82549,// Wallwatcher Gauntlets
	 82553,// Serenity Bracers
	 82557,// Summit Guardian Armplates
	 82558,// Wallwatcher Bracers
	 82617,// Mountainscaler Burnished Headcover
	 82621,// Mountainscaler Heavy Helm
	 82622,// Mountainscaler Armored Helm
	 82626,// Mountainscaler Burnished Spaulders
	 82630,// Mountainscaler Heavy Shoulders
	 82631,// Mountainscaler Armored Shoulders
	 82635,// Mountainscaler Burnished Chestguard
	 82639,// Mountainscaler Heavy Chestpiece
	 82640,// Mountainscaler Armored Chestpiece
	 82644,// Mountainscaler Burnished Legplates
	 82648,// Mountainscaler Heavy Legguards
	 82649,// Mountainscaler Armored Legguards
	 82653,// Mountainscaler Burnished Greaves
	 82657,// Mountainscaler Heavy Warboots
	 82658,// Mountainscaler Armored Warboots
	 82662,// Mountainscaler Burnished Clasp
	 82666,// Mountainscaler Heavy Girdle
	 82667,// Mountainscaler Armored Girdle
	 82671,// Mountainscaler Burnished Gloves
	 82675,// Mountainscaler Heavy Gauntlets
	 82676,// Mountainscaler Armored Gauntlets
	 82680,// Mountainscaler Burnished Bracers
	 82684,// Mountainscaler Heavy Armplates
	 82685,// Mountainscaler Armored Bracers
	 82812,// Pyretic Legguards
	 82821,// Breastplate of Wracking Souls
	 82852,// Wraithplate Treads
	 82856,// Dark Blaze Gauntlets
	 82857,// Vigorsteel Spaulders
	 82862,// Shoulderguards of Painful Lessons
	 82896,// Spiritguard Shoulders
	 82897,// Spiritguard Breastplate
	 82898,// Spiritguard Gauntlets
	 82899,// Spiritguard Legplates
	 82900,// Spiritguard Bracers
	 82901,// Spiritguard Boots
	 82902,// Spiritguard Belt
	 82903,// Ghost-Forged Helm
	 82904,// Ghost-Forged Shoulders
	 82905,// Ghost-Forged Breastplate
	 82906,// Ghost-Forged Gauntlets
	 82907,// Ghost-Forged Legplates
	 82908,// Ghost-Forged Bracers
	 82909,// Ghost-Forged Boots
	 82910,// Ghost-Forged Belt
	 82911,// Lightsteel Helm
	 82912,// Lightsteel Shoulders
	 82913,// Lightsteel Breastplate
	 82914,// Lightsteel Gauntlets
	 82915,// Lightsteel Legplates
	 82916,// Lightsteel Bracers
	 82917,// Lightsteel Boots
	 82918,// Lightsteel Belt
	 82919,// Masterwork Spiritguard Helm
	 82920,// Masterwork Spiritguard Shoulders
	 82921,// Masterwork Spiritguard Breastplate
	 82922,// Masterwork Spiritguard Gauntlets
	 82923,// Masterwork Spiritguard Legplates
	 82924,// Masterwork Spiritguard Bracers
	 82925,// Masterwork Spiritguard Boots
	 82926,// Masterwork Spiritguard Belt
	 82927,// Ghost-Forged Helm
	 82928,// Ghost-Forged Shoulders
	 82929,// Ghost-Forged Breastplate
	 82930,// Ghost-Forged Gauntlets
	 82931,// Ghost-Forged Legplates
	 82932,// Ghost-Forged Bracers
	 82933,// Ghost-Forged Boots
	 82934,// Ghost-Forged Belt
	 82935,// Masterwork Lightsteel Helm
	 82936,// Masterwork Lightsteel Shoulders
	 82937,// Masterwork Lightsteel Breastplate
	 82938,// Masterwork Lightsteel Gauntlets
	 82939,// Masterwork Lightsteel Legplates
	 82940,// Masterwork Lightsteel Bracers
	 82941,// Masterwork Lightsteel Boots
	 82942,// Masterwork Lightsteel Belt
	 82943,// Contender's Revenant Helm
	 82944,// Contender's Revenant Shoulders
	 82945,// Contender's Revenant Breastplate
	 82946,// Contender's Revenant Gauntlets
	 82947,// Contender's Revenant Legplates
	 82948,// Contender's Revenant Bracers
	 82949,// Contender's Revenant Boots
	 82950,// Contender's Revenant Belt
	 82951,// Contender's Spirit Helm
	 82952,// Contender's Spirit Shoulders
	 82953,// Contender's Spirit Breastplate
	 82954,// Contender's Spirit Gauntlets
	 82955,// Contender's Spirit Legplates
	 82956,// Contender's Spirit Bracers
	 82957,// Contender's Spirit Boots
	 82958,// Contender's Spirit Belt
	 82975,// Ghost Reaver's Breastplate
	 82976,// Ghost Reaver's Gauntlets
	 82977,// Living Steel Breastplate
	 82978,// Living Steel Gauntlets
	 82979,// Breastplate of Ancient Steel
	 82980,// Gauntlets of Ancient Steel
	 83161,// Wasteland Burnished Headcover
	 83165,// Wasteland Heavy Helm
	 83166,// Wasteland Armored Helm
	 83170,// Wasteland Burnished Spaulders
	 83174,// Wasteland Heavy Shoulders
	 83175,// Wasteland Armored Shoulders
	 83179,// Wasteland Burnished Chestguard
	 83183,// Wasteland Heavy Chestpiece
	 83184,// Wasteland Armored Chestpiece
	 83188,// Wasteland Burnished Legplates
	 83192,// Wasteland Heavy Legguards
	 83193,// Wasteland Armored Legguards
	 83197,// Wasteland Burnished Greaves
	 83201,// Wasteland Heavy Warboots
	 83202,// Wasteland Armored Warboots
	 83206,// Wasteland Burnished Clasp
	 83210,// Wasteland Heavy Girdle
	 83211,// Wasteland Armored Girdle
	 83215,// Wasteland Burnished Gloves
	 83219,// Wasteland Heavy Gauntlets
	 83220,// Wasteland Armored Gauntlets
	 83224,// Wasteland Burnished Bracers
	 83228,// Wasteland Heavy Armplates
	 83229,// Wasteland Armored Bracers
	 83647,// Goldtalon Headcover
	 83651,// Temple Guardian Helm
	 83652,// Palewind Helm
	 83656,// Goldtalon Spaulders
	 83660,// Temple Guardian Shoulders
	 83661,// Palewind Shoulders
	 83665,// Goldtalon Chestguard
	 83669,// Temple Guardian Chestpiece
	 83670,// Palewind Chestpiece
	 83674,// Goldtalon Legplates
	 83678,// Temple Guardian Legguards
	 83679,// Palewind Legguards
	 83683,// Goldtalon Greaves
	 83687,// Temple Guardian Warboots
	 83688,// Palewind Warboots
	 83692,// Goldtalon Clasp
	 83696,// Temple Guardian Girdle
	 83697,// Palewind Girdle
	 83701,// Goldtalon Gloves
	 83705,// Temple Guardian Gauntlets
	 83706,// Palewind Gauntlets
	 83710,// Goldtalon Bracers
	 83714,// Temple Guardian Armplates
	 83715,// Palewind Bracers
	 83986,// Lucidity Headcover
	 83990,// Bladesworn Helm
	 83991,// Coldbite Helm
	 83995,// Lucidity Spaulders
	 83999,// Bladesworn Shoulders
	 84000,// Coldbite Shoulders
	 84004,// Lucidity Chestguard
	 84008,// Bladesworn Chestpiece
	 84009,// Coldbite Chestpiece
	 84013,// Lucidity Legplates
	 84017,// Bladesworn Legguards
	 84018,// Coldbite Legguards
	 84022,// Lucidity Greaves
	 84026,// Bladesworn Warboots
	 84027,// Coldbite Warboots
	 84031,// Lucidity Clasp
	 84035,// Bladesworn Girdle
	 84036,// Coldbite Girdle
	 84040,// Lucidity Gloves
	 84044,// Bladesworn Gauntlets
	 84045,// Coldbite Gauntlets
	 84049,// Lucidity Bracers
	 84053,// Bladesworn Armplates
	 84054,// Coldbite Bracers
	 84246,// Bamboo Strip Gloves
	 84250,// Bamboo Leaf Gauntlets
	 84275,// Mistwalker Burnished Legplates
	 84279,// Mistwalker Heavy Legguards
	 84280,// Mistwalker Armored Legguards
	 84323,// Hemet's Burnished Legplates
	 84327,// Hemet's Heavy Legguards
	 84328,// Hemet's Armored Legguards
	 84372,// Dreadful Gladiator's Dreadplate Chestpiece
	 84373,// Dreadful Gladiator's Dreadplate Gauntlets
	 84374,// Dreadful Gladiator's Dreadplate Helm
	 84375,// Dreadful Gladiator's Dreadplate Legguards
	 84376,// Dreadful Gladiator's Dreadplate Shoulders
	 84418,// Dreadful Gladiator's Scaled Chestpiece
	 84419,// Dreadful Gladiator's Scaled Gauntlets
	 84420,// Dreadful Gladiator's Scaled Helm
	 84421,// Dreadful Gladiator's Scaled Legguards
	 84422,// Dreadful Gladiator's Scaled Shoulders
	 84423,// Dreadful Gladiator's Clasp of Cruelty
	 84424,// Dreadful Gladiator's Clasp of Meditation
	 84425,// Dreadful Gladiator's Greaves of Alacrity
	 84426,// Dreadful Gladiator's Greaves of Meditation
	 84427,// Dreadful Gladiator's Bracers of Prowess
	 84428,// Dreadful Gladiator's Bracers of Meditation
	 84429,// Dreadful Gladiator's Ornamented Chestguard
	 84430,// Dreadful Gladiator's Ornamented Gloves
	 84431,// Dreadful Gladiator's Ornamented Headcover
	 84432,// Dreadful Gladiator's Ornamented Legplates
	 84433,// Dreadful Gladiator's Ornamented Spaulders
	 84434,// Dreadful Gladiator's Girdle of Accuracy
	 84435,// Dreadful Gladiator's Girdle of Prowess
	 84436,// Dreadful Gladiator's Warboots of Cruelty
	 84437,// Dreadful Gladiator's Warboots of Alacrity
	 84438,// Dreadful Gladiator's Armplates of Proficiency
	 84439,// Dreadful Gladiator's Armplates of Alacrity
	 84504,// Dreadful Gladiator's Plate Chestpiece
	 84505,// Dreadful Gladiator's Plate Gauntlets
	 84506,// Dreadful Gladiator's Plate Helm
	 84507,// Dreadful Gladiator's Plate Legguards
	 84508,// Dreadful Gladiator's Plate Shoulders
	 84512,// Kafa Burnished Spaulders
	 84516,// Kafa Heavy Shoulders
	 84517,// Kafa Armored Shoulders
	 84521,// Kafa Burnished Greaves
	 84525,// Kafa Heavy Warboots
	 84526,// Kafa Armored Warboots
	 84590,// Farwatch Burnished Headcover
	 84594,// Farwatch Heavy Helm
	 84595,// Farwatch Armored Helm
	 84599,// Farwatch Burnished Chestguard
	 84603,// Farwatch Heavy Chestpiece
	 84604,// Farwatch Armored Chestpiece
	 84620,// Sunset Burnished Headcover
	 84624,// Sunset Heavy Helm
	 84625,// Sunset Armored Helm
	 84629,// Sunset Burnished Chestguard
	 84633,// Sunset Heavy Chestpiece
	 84634,// Sunset Armored Chestpiece
	 84793,// Malevolent Gladiator's Ornamented Chestguard
	 84794,// Malevolent Gladiator's Scaled Chestpiece
	 84795,// Malevolent Gladiator's Dreadplate Chestpiece
	 84797,// Malevolent Gladiator's Plate Chestpiece
	 84810,// Malevolent Gladiator's Warboots of Cruelty
	 84811,// Malevolent Gladiator's Greaves of Alacrity
	 84812,// Malevolent Gladiator's Greaves of Meditation
	 84822,// Malevolent Gladiator's Warboots of Alacrity
	 84831,// Malevolent Gladiator's Ornamented Gloves
	 84834,// Malevolent Gladiator's Scaled Gauntlets
	 84835,// Malevolent Gladiator's Dreadplate Gauntlets
	 84840,// Malevolent Gladiator's Plate Gauntlets
	 84849,// Malevolent Gladiator's Ornamented Headcover
	 84851,// Malevolent Gladiator's Scaled Helm
	 84853,// Malevolent Gladiator's Dreadplate Helm
	 84856,// Malevolent Gladiator's Plate Helm
	 84869,// Malevolent Gladiator's Ornamented Legplates
	 84870,// Malevolent Gladiator's Scaled Legguards
	 84872,// Malevolent Gladiator's Dreadplate Legguards
	 84876,// Malevolent Gladiator's Plate Legguards
	 84914,// Malevolent Gladiator's Ornamented Spaulders
	 84915,// Malevolent Gladiator's Scaled Shoulders
	 84918,// Malevolent Gladiator's Dreadplate Shoulders
	 84922,// Malevolent Gladiator's Plate Shoulders
	 84949,// Malevolent Gladiator's Girdle of Accuracy
	 84950,// Malevolent Gladiator's Girdle of Prowess
	 84951,// Malevolent Gladiator's Clasp of Cruelty
	 84952,// Malevolent Gladiator's Clasp of Meditation
	 84974,// Malevolent Gladiator's Bracers of Prowess
	 84975,// Malevolent Gladiator's Bracers of Meditation
	 84985,// Malevolent Gladiator's Armplates of Proficiency
	 84986,// Malevolent Gladiator's Armplates of Alacrity
	 84987,// Malevolent Gladiator's Plate Chestpiece
	 84991,// Malevolent Gladiator's Ornamented Chestguard
	 84992,// Malevolent Gladiator's Scaled Chestpiece
	 84993,// Malevolent Gladiator's Dreadplate Chestpiece
	 84999,// Malevolent Gladiator's Warboots of Alacrity
	 85000,// Malevolent Gladiator's Warboots of Cruelty
	 85001,// Malevolent Gladiator's Greaves of Alacrity
	 85002,// Malevolent Gladiator's Greaves of Meditation
	 85019,// Malevolent Gladiator's Plate Gauntlets
	 85024,// Malevolent Gladiator's Ornamented Gloves
	 85027,// Malevolent Gladiator's Scaled Gauntlets
	 85028,// Malevolent Gladiator's Dreadplate Gauntlets
	 85032,// Malevolent Gladiator's Plate Helm
	 85042,// Malevolent Gladiator's Ornamented Headcover
	 85044,// Malevolent Gladiator's Scaled Helm
	 85046,// Malevolent Gladiator's Dreadplate Helm
	 85056,// Malevolent Gladiator's Ornamented Legplates
	 85057,// Malevolent Gladiator's Scaled Legguards
	 85059,// Malevolent Gladiator's Dreadplate Legguards
	 85063,// Malevolent Gladiator's Plate Legguards
	 85077,// Malevolent Gladiator's Plate Shoulders
	 85086,// Malevolent Gladiator's Dreadplate Shoulders
	 85090,// Malevolent Gladiator's Ornamented Spaulders
	 85091,// Malevolent Gladiator's Scaled Shoulders
	 85102,// Malevolent Gladiator's Girdle of Accuracy
	 85103,// Malevolent Gladiator's Girdle of Prowess
	 85104,// Malevolent Gladiator's Clasp of Cruelty
	 85105,// Malevolent Gladiator's Clasp of Meditation
	 85179,// Meteoric Greathelm
	 85180,// Glintrok Sollerets
	 85186,// Axebreaker Gauntlets
	 85193,// Mind's Eye Breastplate
	 85314,// Shoulderguards of the Lost Catacomb
	 85315,// Legguards of the Lost Catacomb
	 85316,// Faceguard of the Lost Catacomb
	 85317,// Handguards of the Lost Catacomb
	 85318,// Chestguard of the Lost Catacomb
	 85319,// White Tiger Shoulderguards
	 85320,// White Tiger Legguards
	 85321,// White Tiger Faceguard
	 85322,// White Tiger Handguards
	 85323,// White Tiger Chestguard
	 85324,// Shoulderguards of Resounding Rings
	 85325,// Legguards of Resounding Rings
	 85326,// Faceguard of Resounding Rings
	 85327,// Handguards of Resounding Rings
	 85328,// Chestguard of Resounding Rings
	 85329,// Pauldrons of Resounding Rings
	 85330,// Legplates of Resounding Rings
	 85331,// Gauntlets of Resounding Rings
	 85332,// Battleplate of Resounding Rings
	 85333,// Helmet of Resounding Rings
	 85334,// Pauldrons of the Lost Catacomb
	 85335,// Greaves of the Lost Catacomb
	 85336,// Helmet of the Lost Catacomb
	 85337,// Gauntlets of the Lost Catacomb
	 85338,// Breastplate of the Lost Catacomb
	 85339,// White Tiger Pauldrons
	 85340,// White Tiger Legplates
	 85341,// White Tiger Helmet
	 85342,// White Tiger Gauntlets
	 85343,// White Tiger Battleplate
	 85344,// White Tiger Mantle
	 85345,// White Tiger Greaves
	 85346,// White Tiger Headguard
	 85347,// White Tiger Gloves
	 85348,// White Tiger Breastplate
	 85925,// Jasper Clawfeet
	 85975,// Heavenly Jade Greatboots
	 85983,// Bracers of Six Oxen
	 85984,// Nullification Greathelm
	 85988,// Legplates of Sagacious Shadows
	 85992,// Sollerets of Spirit Splitting
	 86027,// Bindings of Ancient Spirits
	 86076,// Breastplate of the Kings' Guard
	 86080,// Shoulderguards of the Unflanked
	 86086,// Girdle of Delirious Visions
	 86121,// Radiant Seafarer's Boots
	 86122,// Plankwalking Greaves
	 86123,// Seafarer's Sturdy Boots
	 86134,// Star-Stealer Waistguard
	 86135,// Starcrusher Gauntlets
	 86145,// Jang-xi's Devastating Legplates
	 86149,// Spaulders of the Emperor's Rage
	 86158,// Chestplate of the Forbidden Tower
	 86164,// Waistplate of Overwhelming Assault
	 86165,// Windblade Talons
	 86174,// Garalon's Hollow Skull
	 86179,// Grasps of Panic
	 86188,// Inlaid Cricket Bracers
	 86190,// Serrated Wasp Bracers
	 86191,// Plated Locust Bracers
	 86201,// Impaling Treads
	 86203,// Articulated Legplates
	 86213,// Shoulderpads of Misshapen Life
	 86230,// Bracers of Defiled Earth
	 86232,// Deepwater Greatboots
	 86318,// Casque of Expelled Corruption
	 86329,// Sollerets of Instability
	 86333,// Cuirass of the Animated Protector
	 86383,// Mender's Girdle of Endless Spring
	 86384,// Protector's Girdle of Endless Spring
	 86385,// Patroller's Girdle of Endless Spring
	 86654,// Shoulderguards of the Lost Catacomb
	 86655,// Legguards of the Lost Catacomb
	 86656,// Faceguard of the Lost Catacomb
	 86657,// Handguards of the Lost Catacomb
	 86658,// Chestguard of the Lost Catacomb
	 86659,// White Tiger Shoulderguards
	 86660,// White Tiger Legguards
	 86661,// White Tiger Faceguard
	 86662,// White Tiger Handguards
	 86663,// White Tiger Chestguard
	 86664,// Shoulderguards of Resounding Rings
	 86665,// Legguards of Resounding Rings
	 86666,// Faceguard of Resounding Rings
	 86667,// Handguards of Resounding Rings
	 86668,// Chestguard of Resounding Rings
	 86669,// Pauldrons of Resounding Rings
	 86670,// Legplates of Resounding Rings
	 86671,// Gauntlets of Resounding Rings
	 86672,// Battleplate of Resounding Rings
	 86673,// Helmet of Resounding Rings
	 86674,// Pauldrons of the Lost Catacomb
	 86675,// Greaves of the Lost Catacomb
	 86676,// Helmet of the Lost Catacomb
	 86677,// Gauntlets of the Lost Catacomb
	 86678,// Breastplate of the Lost Catacomb
	 86679,// White Tiger Pauldrons
	 86680,// White Tiger Legplates
	 86681,// White Tiger Helmet
	 86682,// White Tiger Gauntlets
	 86683,// White Tiger Battleplate
	 86684,// White Tiger Mantle
	 86685,// White Tiger Greaves
	 86686,// White Tiger Headguard
	 86687,// White Tiger Gloves
	 86688,// White Tiger Breastplate
	 86742,// Jasper Clawfeet
	 86744,// Heavenly Jade Greatboots
	 86751,// Bracers of Six Oxen
	 86752,// Nullification Greathelm
	 86756,// Legplates of Sagacious Shadows
	 86760,// Sollerets of Spirit Splitting
	 86766,// Bindings of Ancient Spirits
	 86779,// Breastplate of the Kings' Guard
	 86780,// Shoulderguards of the Unflanked
	 86785,// Girdle of Delirious Visions
	 86793,// Star-Stealer Waistguard
	 86794,// Starcrusher Gauntlets
	 86803,// Jang-xi's Devastating Legplates
	 86807,// Spaulders of the Emperor's Rage
	 86816,// Chestplate of the Forbidden Tower
	 86822,// Waistplate of Overwhelming Assault
	 86823,// Windblade Talons
	 86832,// Garalon's Hollow Skull
	 86837,// Grasps of Panic
	 86846,// Inlaid Cricket Bracers
	 86848,// Serrated Wasp Bracers
	 86849,// Plated Locust Bracers
	 86852,// Impaling Treads
	 86854,// Articulated Legplates
	 86860,// Shoulderpads of Misshapen Life
	 86868,// Bracers of Defiled Earth
	 86870,// Deepwater Greatboots
	 86876,// Casque of Expelled Corruption
	 86887,// Sollerets of Instability
	 86891,// Cuirass of the Animated Protector
	 86902,// Mender's Girdle of Endless Spring
	 86903,// Protector's Girdle of Endless Spring
	 86904,// Patroller's Girdle of Endless Spring
	 86913,// Breastplate of the Lost Catacomb
	 86914,// Gauntlets of the Lost Catacomb
	 86915,// Helmet of the Lost Catacomb
	 86916,// Greaves of the Lost Catacomb
	 86917,// Pauldrons of the Lost Catacomb
	 86918,// Chestguard of the Lost Catacomb
	 86919,// Handguards of the Lost Catacomb
	 86920,// Faceguard of the Lost Catacomb
	 86921,// Legguards of the Lost Catacomb
	 86922,// Shoulderguards of the Lost Catacomb
	 86944,// Articulated Legplates
	 86952,// Chestplate of the Forbidden Tower
	 86955,// Waistplate of Overwhelming Assault
	 86956,// Windblade Talons
	 86966,// Garalon's Hollow Skull
	 86973,// Grasps of Panic
	 86979,// Impaling Treads
	 86986,// Shoulderpads of Misshapen Life
	 86999,// Inlaid Cricket Bracers
	 87000,// Plated Locust Bracers
	 87001,// Serrated Wasp Bracers
	 87015,// Jasper Clawfeet
	 87021,// Heavenly Jade Greatboots
	 87024,// Nullification Greathelm
	 87025,// Bracers of Six Oxen
	 87031,// Legplates of Sagacious Shadows
	 87035,// Sollerets of Spirit Splitting
	 87043,// Bindings of Ancient Spirits
	 87048,// Breastplate of the Kings' Guard
	 87049,// Shoulderguards of the Unflanked
	 87056,// Girdle of Delirious Visions
	 87059,// Starcrusher Gauntlets
	 87060,// Star-Stealer Waistguard
	 87071,// Jang-xi's Devastating Legplates
	 87078,// Spaulders of the Emperor's Rage
	 87099,// White Tiger Battleplate
	 87100,// White Tiger Gauntlets
	 87101,// White Tiger Helmet
	 87102,// White Tiger Legplates
	 87103,// White Tiger Pauldrons
	 87104,// White Tiger Breastplate
	 87105,// White Tiger Gloves
	 87106,// White Tiger Headguard
	 87107,// White Tiger Greaves
	 87108,// White Tiger Mantle
	 87109,// White Tiger Chestguard
	 87110,// White Tiger Handguards
	 87111,// White Tiger Faceguard
	 87112,// White Tiger Legguards
	 87113,// White Tiger Shoulderguards
	 87145,// Bracers of Defiled Earth
	 87146,// Deepwater Greatboots
	 87155,// Casque of Expelled Corruption
	 87165,// Sollerets of Instability
	 87171,// Cuirass of the Animated Protector
	 87184,// Mender's Girdle of Endless Spring
	 87185,// Protector's Girdle of Endless Spring
	 87186,// Patroller's Girdle of Endless Spring
	 87192,// Helmet of Resounding Rings
	 87193,// Battleplate of Resounding Rings
	 87194,// Gauntlets of Resounding Rings
	 87195,// Legplates of Resounding Rings
	 87196,// Pauldrons of Resounding Rings
	 87197,// Chestguard of Resounding Rings
	 87198,// Handguards of Resounding Rings
	 87199,// Faceguard of Resounding Rings
	 87200,// Legguards of Resounding Rings
	 87201,// Shoulderguards of Resounding Rings
	 87286,// Legplates of Absolute Clarity
	 87290,// Legguards of Ironclad Confidence
	 87291,// Legplates of Pure Purpose
	 87298,// Bracers of Ancient Tales
	 87299,// Eversight Armplates
	 87300,// Armplates of the Jade Idol
	 87307,// Vegetable Chopping Handguards
	 87308,// Partycrasher's Gauntlets
	 87309,// Handguards of Sturdy Constitution
	 87318,// Hood of Endless Agitation
	 87322,// Helm of Enmity
	 87323,// Helm of Unstable Temperament
	 87326,// Sha-Trapper Waistguard
	 87330,// Monastery Guardian Waistguard
	 87331,// Girdle of the Broken Seal
	 87336,// Legplates of the Scattered Tribes
	 87340,// Mogu Warlord Legguards
	 87341,// Weaponmaster's Legplates
	 87348,// Bracers of Inner Knowledge
	 87349,// Armplates of Martial Artistry
	 87350,// Poet-King's Vambraces
	 87361,// Martial Purification Gauntlets
	 87362,// Gauntlets of Righteous Conviction
	 87363,// Zealous Fervor Handguards
	 87370,// Waistguard of the Phalanx
	 87371,// Scarlet Champion's Belt
	 87372,// Verdone's Chewed Waistplate
	 87379,// Runed Deathbone Chestplate
	 87380,// Carver's Bloodsplattered Chestpiece
	 87381,// Coldforge Carapace
	 87402,// Ornate Battleplate of the Master
	 87403,// Chestplate of Limitless Faith
	 87404,// Gauntlets of Unbound Devotion
	 87405,// Unyielding Bloodplate
	 87406,// Gauntlets of Battle Command
	 87407,// Bloodforged Warfists
	 87424,// Cryptwarden's Breastplate
	 87426,// Deathspite Breastplate
	 87433,// Blackfooted Greatboots
	 87436,// Sollerets of Immovability
	 87445,// Gauntlets of Blurring Fingers
	 87446,// Gauntlets of the Solemn Charge
	 87449,// Errick's Woundbinder Gauntlets
	 87453,// Endwyn's Toothy Visage
	 87454,// Light-Sealed Casque
	 87455,// Davidian's All-Seeing Eyes
	 87460,// Legplates of the Wandering Warrior
	 87461,// Greatheart Pants
	 87494,// Shoulderguards of Honest Labor
	 87501,// Unbreakable Waistplate
	 87504,// Waistguard of Flaming Words
	 87506,// Cheng's Irrepressible Girdle
	 87518,// Bracers of the Neux Dawn
	 87521,// Zoid's Scorched Bracers
	 87569,// The Horseman's Horrific Hood
	 87589,// Leggings of Fractured Reflection
	 87593,// Gan Shi Warlord Legguards
	 87594,// Leggings of Forgotten War
	 87601,// Plough Driving Grips
	 87602,// Grain Warden's Gauntlets
	 87603,// Thunderfall Gauntlets
	 87607,// Unearthed Dojani Headcover
	 87611,// Shen-zin Shell Headguard
	 87612,// Ancient Krasari Helm
	 87619,// Terracotta Guardian's Bracer
	 87620,// Bracers of the Frozen Summit
	 87621,// Wristguards of Great Fortune
	 87627,// Kunchong Carapace Chestguard
	 87628,// Spinebreaker Chestpiece
	 87629,// Chestplate of Manifest Dread
	 88016,// Paoquan Burnished Cap
	 88017,// Sunsong Armored Cap
	 88018,// Thunderfoot Heavy Cap
	 88019,// Sunsong Armored Pauldrons
	 88020,// Thunderfoot Heavy Pauldrons
	 88024,// Paoquan Burnished Pauldrons
	 88028,// Sunsong Vest
	 88029,// Thunderfoot Vest
	 88032,// Paoquan Vest
	 88035,// Dojani Shoes
	 88036,// Korjan Shoes
	 88040,// Narsong Shoes
	 88044,// Dojani Waistband
	 88045,// Korjan Waistband
	 88049,// Narsong Waistband
	 88053,// Dojani Handwraps
	 88054,// Korjan Handwraps
	 88058,// Narsong Handwraps
	 88062,// Wallwatcher Wristwraps
	 88063,// Summit Guardian Wristwraps
	 88067,// Serenity Wristwraps
	 88071,// Wallwatcher Cap
	 88072,// Summit Guardian Cap
	 88076,// Serenity Cap
	 88080,// Wallwatcher Vest
	 88081,// Summit Guardian Vest
	 88084,// Serenity Vest
	 88087,// Palewind Pauldron
	 88088,// Temple Guardian Pauldron
	 88092,// Goldtalon Pauldron
	 88096,// Palewind Pantaloons
	 88097,// Temple Guardian Pantaloons
	 88101,// Goldtalon Pantaloons
	 88105,// Palewind Waistband
	 88106,// Temple Guardian Waistband
	 88110,// Goldtalon Waistband
	 88114,// Coldbite Shoes
	 88115,// Bladesworn Shoes
	 88119,// Lucidity Shoes
	 88123,// Coldbite Handwraps
	 88124,// Bladesworn Handwraps
	 88128,// Lucidity Handwraps
	 88132,// Coldbite Wristwraps
	 88133,// Bladesworn Wristwraps
	 88137,// Lucidity Wristwraps
	 88170,// Cataclysmic Gladiator's Ornamented Battlerobe
	 88191,// Gladiator's Dreadplate Chestpiece
	 88192,// Gladiator's Dreadplate Gauntlets
	 88193,// Gladiator's Dreadplate Helm
	 88194,// Gladiator's Dreadplate Legguards
	 88195,// Gladiator's Dreadplate Shoulders
	 88226,// Gladiator's Ornamented Chestguard
	 88227,// Gladiator's Ornamented Gloves
	 88228,// Gladiator's Ornamented Headcover
	 88229,// Gladiator's Ornamented Legplates
	 88230,// Gladiator's Ornamented Spaulders
	 88231,// Gladiator's Plate Chestpiece
	 88232,// Gladiator's Plate Gauntlets
	 88233,// Gladiator's Plate Helm
	 88234,// Gladiator's Plate Legguards
	 88235,// Gladiator's Plate Shoulders
	 88246,// Gladiator's Scaled Chestpiece
	 88247,// Gladiator's Scaled Gauntlets
	 88248,// Gladiator's Scaled Helm
	 88249,// Gladiator's Scaled Legguards
	 88250,// Gladiator's Scaled Shoulders
	 88690,// Bamboo Leaf Armplates
	 88691,// Bamboo Plate Armplates
	 88695,// Bamboo Strip Bracers
	 88709,// Bamboo Plate Gauntlets
	 88746,// Gloves of the Overwhelming Swarm
	 88747,// Streetfighter's Iron Knuckles
	 88749,// Gauntlets of Jade Sutras
	 88862,// Tankiss Warstompers
	 88864,// Yu'lon Guardian Boots
	 88865,// Bramblestaff Boots
	 88879,// Braided Black and White Bracer
	 88880,// Battle Shadow Bracers
	 88881,// Fallen Sentinel Bracers
	 89055,// Klaxxi Lash of the Rescinder
	 89056,// Klaxxi Lash of the Consumer
	 89057,// Klaxxi Lash of the Doubter
	 89093,// Kovok's Riven Legguards
	 89094,// Ambersmith Legplates
	 89095,// Legguards of the Unscathed
	 89096,// Six Pool's Open Helm
	 89216,// Yi's Least Favorite Helmet
	 89280,// Voice Amplyifying Greathelm
	 89345,// Stonetoe Spaulders
	 89346,// Shoulders of Autumnlight
	 89347,// Paleblade Shoulderguards
	 89420,// Dawnblade's Chestguard
	 89421,// Cuirass of the Twin Monoliths
	 89423,// Battleguard of Guo-Lai
	 89435,// Greenstone Vambraces
	 89437,// Greenstone Sabatons
	 89438,// Greenstone Pauldrons
	 89439,// Greenstone Legplates
	 89440,// Greenstone Helm
	 89441,// Greenstone Girdle
	 89442,// Greenstone Gauntlets
	 89443,// Greenstone Breastplate
	 89444,// Mogu-Wrought Breastplate
	 89445,// Mogu-Wrought Gauntlets
	 89446,// Mogu-Wrought Girdle
	 89447,// Mogu-Wrought Helm
	 89448,// Mogu-Wrought Legplates
	 89449,// Mogu-Wrought Pauldrons
	 89450,// Mogu-Wrought Sabatons
	 89451,// Mogu-Wrought Vambraces
	 89648,// Bracers of Inner Light
	 89649,// Serrated Forearm Guards
	 89656,// Gauntlets of Restraint
	 89657,// Wall Breaker Gauntlets
	 89664,// Valiant's Shinguards
	 89665,// Leggings of Ponderous Advance
	 89670,// Inner Serenity Chestplate
	 89671,// Chestplate of the Stone Lion
	 89817,// Bonded Soul Bracers
	 89821,// Crown of Keening Stars
	 89823,// Chestguard of Eternal Vigilance
	 89826,// Warbelt of Sealed Pods
	 89828,// Pauldrons of the Broken Blade
	 89832,// Garalon's Graven Carapace
	 89837,// Legplates of Regal Reinforcement
	 89843,// Grasps of Serpentine Might
	 89919,// Warbelt of Sealed Pods
	 89921,// Pauldrons of the Broken Blade
	 89923,// Garalon's Graven Carapace
	 89928,// Legplates of Regal Reinforcement
	 89934,// Bonded Soul Bracers
	 89939,// Crown of Keening Stars
	 89941,// Chestguard of Eternal Vigilance
	 89946,// Grasps of Serpentine Might
	 89954,// Warbelt of Sealed Pods
	 89956,// Pauldrons of the Broken Blade
	 89958,// Garalon's Graven Carapace
	 89963,// Legplates of Regal Reinforcement
	 89969,// Bonded Soul Bracers
	 89974,// Crown of Keening Stars
	 89976,// Chestguard of Eternal Vigilance
	 89981,// Grasps of Serpentine Might
	 90024,// Silver Circlet
	 90025,// Black Circlet
	 90026,// Golden Circlet
	 90049,// Girdle of the Lich Lord
	 90050,// Treads of the Lich Lord
	 90051,// Chestguard of the Lich Lord
	 90052,// Grasps of the Lich Lord
	 90053,// Crown of the Lich Lord
	 90054,// Legplates of the Lich Lord
	 90055,// Shoulderguards of the Lich Lord
	 90056,// Bracers of the Lich Lord
	 90096,// Girdle of the Holy Warrior
	 90097,// Greatboots of the Holy Warrior
	 90098,// Chestplate of the Holy Warrior
	 90099,// Gauntlets of the Holy Warrior
	 90100,// Greathelm of the Holy Warrior
	 90101,// Legplates of the Holy Warrior
	 90102,// Shoulderplate of the Holy Warrior
	 90103,// Wristguards of the Holy Warrior
	 90147,// Girdle of the Golden King
	 90148,// Greatboots of the Golden King
	 90149,// Chestplate of the Golden King
	 90150,// Reach of the Golden King
	 90151,// Crown of the Golden King
	 90152,// Greaves of the Golden King
	 90153,// Mantle of the Golden King
	 90154,// Bracers of the Golden King
	 90292,// Peacebreaker's Burnished Headcover
	 90293,// Peacebreaker's Armored Helm
	 90294,// Peacebreaker's Heavy Helm
	 90301,// Burnished Chestguard of Eminent Domain
	 90302,// Armored Chestpiece of Eminent Domain
	 90303,// Heavy Chestpiece of Eminent Domain
	 90310,// Honorary Combat Engineer's Burnished Legplates
	 90311,// Honorary Combat Engineer's Legguards
	 90312,// Honorary Combat Engineer's Heavy Legplates
	 90319,// Landfall Burnished Greaves
	 90320,// Landfall Warboots
	 90321,// Landfall Plate Boots
	 90344,// Peacebreaker's Burnished Headcover
	 90345,// Peacebreaker's Armored Helm
	 90346,// Peacebreaker's Heavy Helm
	 90353,// Burnished Chestguard of Eminent Domain
	 90354,// Armored Chestpiece of Eminent Domain
	 90355,// Heavy Chestpiece of Eminent Domain
	 90362,// Honorary Combat Engineer's Burnished Legplates
	 90363,// Honorary Combat Engineer's Legplates
	 90364,// Honorary Combat Engineer's Heavy Legguards
	 90371,// Landfall Burnished Greaves
	 90372,// Landfall Warboots
	 90373,// Landfall Plate Boots
	 90414,// Greathelm of the Monstrous Mushan
	 90415,// Giantfoot Headguard
	 90416,// Crown of Ranging Invasion
	 90423,// Chestguard of the Unbowed Back
	 90424,// Ravaging Warrior's Chestplate
	 90425,// Carapace of Crushed Conviction
	 90445,// Firerider Treads
	 90446,// Silverspur Warboots
	 90447,// Stompers of Vigorous Stomping
	 90454,// Girdle of the Galloping Giant
	 90455,// Greatbelt of Livid Fury
	 90456,// Cord of Crazed Strength
	 90506,// Bracers of Defiled Earth
	 90507,// Deepwater Greatboots
	 90516,// Casque of Expelled Corruption
	 90520,// Bracers of Defiled Earth
	 90521,// Deepwater Greatboots
	 90530,// Casque of Expelled Corruption
	 90576,// Spaulders of the Scorned
	 90577,// Boblet's Bouncing Hauberk
	 90579,// Legplates of Durable Dreams
	 90600,// Ferocious Plate of the Golden Lotus
	 90601,// Bonded Plate of the Golden Lotus
	 90603,// Durable Plate of the Golden Lotus
	 90717,// Qu'nas' Apocryphal Legplates
	 90718,// Torik-Ethis' Bloodied Legguards
	 90722,// Torik-Ethis' Gilded Legplates
	 90743,// Dingy Plate Helmet
	 90747,// Dingy Plate Belt
	 90748,// Dingy Plate Boots
	 90749,// Dingy Plate Bracers
	 90750,// Dingy Plate Shoulderpads
	 90751,// Dingy Plate Chestpiece
	 90771,// Dingy Plate Gloves
	 90772,// Dingy Plate Pants
	 90773,// Slipshod Plate Helmet
	 90782,// Slipshod Plate Bracers
	 90787,// Slipshod Plate Belt
	 90797,// Slipshod Plate Boots
	 90799,// Slipshod Plate Chestpiece
	 90800,// Slipshod Plate Gloves
	 90801,// Slipshod Plate Pants
	 90802,// Slipshod Plate Shoulderpads
	 90846,// Replica Shado-Pan Helmet
	 90909,// Intemperate Greatboots
	 90910,// Mindfire Sollerets
	 90912,// Angerforged Stompers
	 91147,// Tyrannical Gladiator's Dreadplate Chestpiece
	 91148,// Tyrannical Gladiator's Dreadplate Chestpiece
	 91149,// Tyrannical Gladiator's Dreadplate Gauntlets
	 91150,// Tyrannical Gladiator's Dreadplate Gauntlets
	 91151,// Tyrannical Gladiator's Dreadplate Helm
	 91152,// Tyrannical Gladiator's Dreadplate Helm
	 91153,// Tyrannical Gladiator's Dreadplate Legguards
	 91154,// Tyrannical Gladiator's Dreadplate Legguards
	 91155,// Tyrannical Gladiator's Dreadplate Shoulders
	 91156,// Tyrannical Gladiator's Dreadplate Shoulders
	 91267,// Tyrannical Gladiator's Scaled Chestpiece
	 91268,// Tyrannical Gladiator's Scaled Chestpiece
	 91269,// Tyrannical Gladiator's Scaled Gauntlets
	 91270,// Tyrannical Gladiator's Scaled Gauntlets
	 91271,// Tyrannical Gladiator's Scaled Helm
	 91272,// Tyrannical Gladiator's Scaled Helm
	 91273,// Tyrannical Gladiator's Scaled Legguards
	 91274,// Tyrannical Gladiator's Scaled Legguards
	 91275,// Tyrannical Gladiator's Scaled Shoulders
	 91276,// Tyrannical Gladiator's Scaled Shoulders
	 91277,// Tyrannical Gladiator's Clasp of Cruelty
	 91278,// Tyrannical Gladiator's Clasp of Cruelty
	 91279,// Tyrannical Gladiator's Clasp of Meditation
	 91280,// Tyrannical Gladiator's Clasp of Meditation
	 91281,// Tyrannical Gladiator's Greaves of Alacrity
	 91282,// Tyrannical Gladiator's Greaves of Alacrity
	 91283,// Tyrannical Gladiator's Greaves of Meditation
	 91284,// Tyrannical Gladiator's Greaves of Meditation
	 91285,// Tyrannical Gladiator's Bracers of Prowess
	 91286,// Tyrannical Gladiator's Bracers of Meditation
	 91287,// Tyrannical Gladiator's Ornamented Chestguard
	 91288,// Tyrannical Gladiator's Ornamented Chestguard
	 91289,// Tyrannical Gladiator's Ornamented Gloves
	 91290,// Tyrannical Gladiator's Ornamented Gloves
	 91291,// Tyrannical Gladiator's Ornamented Headcover
	 91292,// Tyrannical Gladiator's Ornamented Headcover
	 91293,// Tyrannical Gladiator's Ornamented Legplates
	 91294,// Tyrannical Gladiator's Ornamented Legplates
	 91295,// Tyrannical Gladiator's Ornamented Spaulders
	 91296,// Tyrannical Gladiator's Ornamented Spaulders
	 91297,// Tyrannical Gladiator's Girdle of Accuracy
	 91298,// Tyrannical Gladiator's Girdle of Accuracy
	 91299,// Tyrannical Gladiator's Girdle of Prowess
	 91300,// Tyrannical Gladiator's Girdle of Prowess
	 91301,// Tyrannical Gladiator's Warboots of Cruelty
	 91302,// Tyrannical Gladiator's Warboots of Cruelty
	 91303,// Tyrannical Gladiator's Warboots of Alacrity
	 91304,// Tyrannical Gladiator's Warboots of Alacrity
	 91305,// Tyrannical Gladiator's Armplates of Proficiency
	 91306,// Tyrannical Gladiator's Armplates of Alacrity
	 91430,// Tyrannical Gladiator's Plate Chestpiece
	 91431,// Tyrannical Gladiator's Plate Chestpiece
	 91432,// Tyrannical Gladiator's Plate Gauntlets
	 91433,// Tyrannical Gladiator's Plate Gauntlets
	 91434,// Tyrannical Gladiator's Plate Helm
	 91435,// Tyrannical Gladiator's Plate Helm
	 91436,// Tyrannical Gladiator's Plate Legguards
	 91437,// Tyrannical Gladiator's Plate Legguards
	 91438,// Tyrannical Gladiator's Plate Shoulders
	 91439,// Tyrannical Gladiator's Plate Shoulders
	 91500,// Malevolent Gladiator's Dreadplate Chestpiece
	 91502,// Malevolent Gladiator's Dreadplate Gauntlets
	 91504,// Malevolent Gladiator's Dreadplate Helm
	 91506,// Malevolent Gladiator's Dreadplate Legguards
	 91508,// Malevolent Gladiator's Dreadplate Shoulders
	 91620,// Malevolent Gladiator's Scaled Chestpiece
	 91622,// Malevolent Gladiator's Scaled Gauntlets
	 91624,// Malevolent Gladiator's Scaled Helm
	 91626,// Malevolent Gladiator's Scaled Legguards
	 91628,// Malevolent Gladiator's Scaled Shoulders
	 91630,// Malevolent Gladiator's Clasp of Cruelty
	 91632,// Malevolent Gladiator's Clasp of Meditation
	 91634,// Malevolent Gladiator's Greaves of Alacrity
	 91636,// Malevolent Gladiator's Greaves of Meditation
	 91638,// Malevolent Gladiator's Bracers of Prowess
	 91639,// Malevolent Gladiator's Bracers of Meditation
	 91640,// Malevolent Gladiator's Ornamented Chestguard
	 91642,// Malevolent Gladiator's Ornamented Gloves
	 91644,// Malevolent Gladiator's Ornamented Headcover
	 91646,// Malevolent Gladiator's Ornamented Legplates
	 91648,// Malevolent Gladiator's Ornamented Spaulders
	 91650,// Malevolent Gladiator's Girdle of Accuracy
	 91652,// Malevolent Gladiator's Girdle of Prowess
	 91654,// Malevolent Gladiator's Warboots of Cruelty
	 91656,// Malevolent Gladiator's Warboots of Alacrity
	 91658,// Malevolent Gladiator's Armplates of Proficiency
	 91659,// Malevolent Gladiator's Armplates of Alacrity
	 91783,// Malevolent Gladiator's Plate Chestpiece
	 91785,// Malevolent Gladiator's Plate Gauntlets
	 91787,// Malevolent Gladiator's Plate Helm
	 91789,// Malevolent Gladiator's Plate Legguards
	 91791,// Malevolent Gladiator's Plate Shoulders
	 92814,// Bladesnap Vambraces
	 92815,// Bladesnap Sabatons
	 92816,// Bladesnap Pauldrons
	 92817,// Bladesnap Legplates
	 92818,// Bladesnap Helm
	 92819,// Bladesnap Girdle
	 92820,// Bladesnap Gauntlets
	 92821,// Bladesnap Breastplate
	 92822,// Jinyu-Forged Breastplate
	 92823,// Jinyu-Forged Gauntlets
	 92824,// Jinyu-Forged Girdle
	 92825,// Jinyu-Forged Helm
	 92826,// Jinyu-Forged Legplates
	 92827,// Jinyu-Forged Pauldrons
	 92828,// Jinyu-Forged Sabatons
	 92829,// Jinyu-Forged Vambraces
	 93094,// Yaungolian Breastplate
	 93095,// Yaungolian Sabatons
	 93096,// Yaungolian Gauntlets
	 93097,// Yaungolian Helm
	 93098,// Yaungolian Legplates
	 93099,// Yaungolian Pauldrons
	 93100,// Yaungolian Girdle
	 93101,// Yaungolian Vambraces
	 93115,// Lightning Rod Breastplate
	 93116,// Lightning Rod Sabatons
	 93117,// Lightning Rod Gauntlets
	 93118,// Lightning Rod Helm
	 93119,// Lightning Rod Legplates
	 93120,// Lightning Rod Pauldrons
	 93121,// Lightning Rod Girdle
	 93122,// Lightning Rod Vambraces
	 93263,// Groundbreaker Sabatons
	 93264,// Cragchewer Sollerets
	 93265,// Scar Swallower Greatboots
	 93272,// Sabatons of the Sullied Shore
	 93273,// Sea-Soaked Sollerets
	 93274,// Greatboots of Flashing Light
	 93323,// Kwon's Crushing Girdle
	 93324,// Immovable Waistplate
	 93325,// Divide's Greatheart Clasp
	 93332,// Girdle of Crushing Strength
	 93333,// Waistplate of Immobility
	 93334,// Divide's Loyal Clasp
	 93453,// Crafted Dreadful Gladiator's Dreadplate Chestpiece
	 93454,// Crafted Dreadful Gladiator's Dreadplate Gauntlets
	 93455,// Crafted Dreadful Gladiator's Dreadplate Helm
	 93456,// Crafted Dreadful Gladiator's Dreadplate Legguards
	 93457,// Crafted Dreadful Gladiator's Dreadplate Shoulders
	 93527,// Crafted Dreadful Gladiator's Scaled Chestpiece
	 93528,// Crafted Dreadful Gladiator's Scaled Gauntlets
	 93529,// Crafted Dreadful Gladiator's Scaled Helm
	 93530,// Crafted Dreadful Gladiator's Scaled Legguards
	 93531,// Crafted Dreadful Gladiator's Scaled Shoulders
	 93532,// Crafted Dreadful Gladiator's Clasp of Cruelty
	 93533,// Crafted Dreadful Gladiator's Clasp of Meditation
	 93534,// Crafted Dreadful Gladiator's Greaves of Alacrity
	 93535,// Crafted Dreadful Gladiator's Greaves of Meditation
	 93536,// Crafted Dreadful Gladiator's Bracers of Prowess
	 93537,// Crafted Dreadful Gladiator's Bracers of Meditation
	 93538,// Crafted Dreadful Gladiator's Ornamented Chestguard
	 93539,// Crafted Dreadful Gladiator's Ornamented Gloves
	 93540,// Crafted Dreadful Gladiator's Ornamented Headcover
	 93541,// Crafted Dreadful Gladiator's Ornamented Legplates
	 93542,// Crafted Dreadful Gladiator's Ornamented Spaulders
	 93543,// Crafted Dreadful Gladiator's Girdle of Accuracy
	 93544,// Crafted Dreadful Gladiator's Girdle of Prowess
	 93545,// Crafted Dreadful Gladiator's Warboots of Cruelty
	 93546,// Crafted Dreadful Gladiator's Warboots of Alacrity
	 93547,// Crafted Dreadful Gladiator's Armplates of Proficiency
	 93548,// Crafted Dreadful Gladiator's Armplates of Alacrity
	 93620,// Crafted Dreadful Gladiator's Plate Chestpiece
	 93621,// Crafted Dreadful Gladiator's Plate Gauntlets
	 93622,// Crafted Dreadful Gladiator's Plate Helm
	 93623,// Crafted Dreadful Gladiator's Plate Legguards
	 93624,// Crafted Dreadful Gladiator's Plate Shoulders
	 93890,// Gleaming Spaulders of Valor
	 93891,// Gleaming Breastplate of Valor
	 93892,// Brushed Breastplate of Might
	 93893,// Brushed Pauldrons of Might
	 93894,// Immaculate Lightforge Spaulders
	 93895,// Reinforced Stockade Pauldrons
	 94030,// Primordial Bloodsoaked Legplates
	 94031,// Primordial Bloodsoaked Pauldrons
	 94032,// Primordial Bloodsoaked Gauntlets
	 94033,// Primordial Bloodsoaked Greaves
	 94034,// Primordial Bloodsoaked Breastplate
	 94035,// Primordial Bloodsoaked Belt
	 94036,// Forgotten Peacekeeper Leggings
	 94037,// Forgotten Peacekeeper Boots
	 94038,// Forgotten Peacekeeper Gauntlets
	 94039,// Forgotten Peacekeeper Breastplate
	 94040,// Forgotten Peacekeeper Belt
	 94041,// Forgotten Peacekeeper Armguards
	 94042,// Forgotten Peacekeeper Shoulders
	 94043,// Primordial Bloodsoaked Vambraces
	 94085,// Tarnished Fanatic's Battlevest
	 94086,// Tarnished Fanatic's Warboots
	 94087,// Tarnished Fanatic's Girdle
	 94088,// Tarnished Fanatic's Wargreaves
	 94089,// Tarnished Fanatic's Deathgrips
	 94090,// Tarnished Fanatic's Shackles
	 94091,// Tarnished Fanatic's Pauldrons
	 94211,// Tarnished Fanatic's Headcover
	 94263,// Haunted Steel Greaves
	 94264,// Haunted Steel Headcover
	 94265,// Haunted Steel Treads
	 94266,// Haunted Steel Greathelm
	 94267,// Haunted Steel Warboots
	 94268,// Haunted Steel Headguard
	 94331,// Tyrannical Gladiator's Plate Gauntlets
	 94332,// Tyrannical Gladiator's Plate Helm
	 94343,// Tyrannical Gladiator's Scaled Gauntlets
	 94345,// Tyrannical Gladiator's Ornamented Chestguard
	 94348,// Tyrannical Gladiator's Ornamented Headcover
	 94351,// Tyrannical Gladiator's Greaves of Alacrity
	 94352,// Tyrannical Gladiator's Greaves of Meditation
	 94353,// Tyrannical Gladiator's Girdle of Accuracy
	 94364,// Tyrannical Gladiator's Dreadplate Gauntlets
	 94365,// Tyrannical Gladiator's Dreadplate Legguards
	 94366,// Tyrannical Gladiator's Dreadplate Shoulders
	 94392,// Tyrannical Gladiator's Dreadplate Chestpiece
	 94401,// Tyrannical Gladiator's Plate Shoulders
	 94411,// Tyrannical Gladiator's Bracers of Prowess
	 94413,// Tyrannical Gladiator's Ornamented Spaulders
	 94414,// Tyrannical Gladiator's Warboots of Cruelty
	 94418,// Tyrannical Gladiator's Armplates of Proficiency
	 94429,// Tyrannical Gladiator's Dreadplate Helm
	 94438,// Tyrannical Gladiator's Ornamented Gloves
	 94440,// Tyrannical Gladiator's Girdle of Prowess
	 94444,// Tyrannical Gladiator's Plate Chestpiece
	 94448,// Tyrannical Gladiator's Plate Legguards
	 94460,// Tyrannical Gladiator's Scaled Shoulders
	 94461,// Tyrannical Gladiator's Warboots of Alacrity
	 94463,// Tyrannical Gladiator's Scaled Chestpiece
	 94464,// Tyrannical Gladiator's Clasp of Meditation
	 94480,// Tyrannical Gladiator's Clasp of Cruelty
	 94481,// Tyrannical Gladiator's Bracers of Meditation
	 94484,// Tyrannical Gladiator's Ornamented Legplates
	 94487,// Tyrannical Gladiator's Armplates of Alacrity
	 94495,// Tyrannical Gladiator's Scaled Helm
	 94496,// Tyrannical Gladiator's Scaled Legguards
	 94723,// Chestplate of Violent Detonation
	 94726,// Cloudbreaker Greatbelt
	 94727,// Bracers of Constant Implosion
	 94734,// Ionized Yojamban Carapace
	 94742,// Frozen Warlord's Bracers
	 94744,// Puncture-Proof Greathelm
	 94747,// Bloodlord's Bloodsoaked Legplates
	 94751,// Armplates of the Vanquished Abomination
	 94764,// Overloaded Bladebreaker Cuirass
	 94771,// Shell-Coated Wristplates
	 94773,// Shoulderguards of Centripetal Destruction
	 94784,// Refreshing Abalone Girdle
	 94787,// Tortos' Shellseizers
	 94789,// Rot-Proof Greatplate
	 94792,// Plated Toothbreaker Girdle
	 94798,// Ice-Scored Treads
	 94807,// Egg-Shard Grips
	 94809,// Crown of Potentiated Birth
	 94810,// Talonrender Chestplate
	 94815,// Legplates of the Dark Parasite
	 94817,// Treads of the Blind Eye
	 94820,// Caustic Spike Bracers
	 94821,// Artery Rippers
	 94924,// Iceshatter Gauntlets
	 94930,// Legplates of Re-Emergence
	 94938,// Pathogenic Gauntlets
	 94941,// Metabolically Boosted Shoulderplates
	 94944,// Black Blood Legplates
	 94950,// Spaulders of Primordial Growth
	 94952,// Bonemender Bracers
	 94956,// Matter-Swapped Legplates
	 94958,// Crown of the Golden Golem
	 94972,// Rein-Binder's Fists
	 94976,// Tidal Force Treads
	 94984,// Doomed Crown of Lei Shen
	 94985,// Legplates of Whipping Ionization
	 94989,// Lei Shen's Grounded Carapace
	 95001,// Bubbling Anima Belt
	 95002,// Cracklesnap Clasp
	 95003,// Flare-Forged Greatbelt
	 95010,// Hypersensitive Sollerets
	 95011,// Lightning-Walker Clawfeet
	 95012,// Sabatons of the Superior Being
	 95023,// Legplates of Lightning Blood
	 95024,// Time-Lost Greaves
	 95025,// Archaic Protector's Legguards
	 95036,// Nova-Binder Breastplate
	 95037,// Planet-Birthed Cuirass
	 95038,// Carapace of the Core
	 95063,// Reconstructed Furious Shoulderplates
	 95068,// Reconstructed Bloody Shoulderplates
	 95069,// Reconstructed Holy Shoulderplates
	 95074,// Hauberk of Gleaming Fire
	 95075,// Gianttooth Chestplate
	 95076,// Breastplate of Brutal Strikes
	 95083,// Swordhook Slingbelt
	 95084,// Reinforced Spiritplate Girdle
	 95085,// Waistplate of Channeled Mending
	 95098,// Sightblinder Shoulderguards
	 95103,// Sparksmasher Pauldrons
	 95104,// Shoulderguards of Potentiation
	 95110,// Stoneward Handguards
	 95111,// Bloodstained Skullsqueezers
	 95113,// Touch of Soothing Mists
	 95119,// Thunderbreaker Legplates
	 95120,// Legguards of Renewal
	 95121,// Vaultbreaker Greaves
	 95128,// Bonecrusher Bracers
	 95129,// Axebinder Wristguards
	 95130,// Softscar Armplates
	 95151,// Scorched Spiritfire Drape
	 95152,// Breastplate of the Iguanocolossus
	 95153,// Tyrant King Battleplate
	 95190,// Waistband of Furious Stomping
	 95191,// Voolar's Bloodied Belt
	 95192,// Belt of the Tyrannotitan
	 95198,// Vulcanodon Gauntlets
	 95199,// Carnotaur Battlegloves
	 95201,// Skullsmashing Gauntlets
	 95213,// Abandoned Zandalari Greatbelt
	 95214,// Abandoned Zandalari Goreplate
	 95215,// Abandoned Zandalari Bucklebreaker
	 95216,// Vaultwalker Sabatons
	 95217,// Locksmasher Greaves
	 95218,// Columnbreaker Stompers
	 95225,// Breastplate of the All-Consuming Maw
	 95226,// Gauntlets of the All-Consuming Maw
	 95227,// Helmet of the All-Consuming Maw
	 95228,// Greaves of the All-Consuming Maw
	 95229,// Pauldrons of the All-Consuming Maw
	 95230,// Chestguard of the All-Consuming Maw
	 95231,// Handguards of the All-Consuming Maw
	 95232,// Faceguard of the All-Consuming Maw
	 95233,// Legguards of the All-Consuming Maw
	 95234,// Shoulderguards of the All-Consuming Maw
	 95280,// Lightning Emperor's Battleplate
	 95281,// Lightning Emperor's Gauntlets
	 95282,// Lightning Emperor's Helmet
	 95283,// Lightning Emperor's Legplates
	 95284,// Lightning Emperor's Pauldrons
	 95285,// Lightning Emperor's Breastplate
	 95286,// Lightning Emperor's Gloves
	 95287,// Lightning Emperor's Headguard
	 95288,// Lightning Emperor's Greaves
	 95289,// Lightning Emperor's Mantle
	 95290,// Lightning Emperor's Chestguard
	 95291,// Lightning Emperor's Handguards
	 95292,// Lightning Emperor's Faceguard
	 95293,// Lightning Emperor's Legguards
	 95294,// Lightning Emperor's Shoulderguards
	 95330,// Helmet of the Last Mogu
	 95331,// Battleplate of the Last Mogu
	 95332,// Gauntlets of the Last Mogu
	 95333,// Legplates of the Last Mogu
	 95334,// Pauldrons of the Last Mogu
	 95335,// Chestguard of the Last Mogu
	 95336,// Handguards of the Last Mogu
	 95337,// Faceguard of the Last Mogu
	 95338,// Legguards of the Last Mogu
	 95339,// Shoulderguards of the Last Mogu
	 95520,// Girdle of Shan'ze Glory
	 95524,// Thunder Caressed Waistguard
	 95529,// Girdle of Shan'ze Glory
	 95533,// Thunder Caressed Waistguard
	 95535,// Legplates of the Lightning Throne
	 95629,// Cloudbreaker Greatbelt
	 95630,// Chestplate of Violent Detonation
	 95631,// Bracers of Constant Implosion
	 95644,// Ionized Yojamban Carapace
	 95650,// Frozen Warlord's Bracers
	 95651,// Bloodlord's Bloodsoaked Legplates
	 95652,// Puncture-Proof Greathelm
	 95664,// Armplates of the Vanquished Abomination
	 95674,// Overloaded Bladebreaker Cuirass
	 95683,// Shoulderguards of Centripetal Destruction
	 95684,// Shell-Coated Wristplates
	 95696,// Refreshing Abalone Girdle
	 95697,// Tortos' Shellseizers
	 95702,// Plated Toothbreaker Girdle
	 95703,// Rot-Proof Greatplate
	 95716,// Ice-Scored Treads
	 95723,// Crown of Potentiated Birth
	 95724,// Talonrender Chestplate
	 95725,// Egg-Shard Grips
	 95732,// Caustic Spike Bracers
	 95733,// Legplates of the Dark Parasite
	 95734,// Treads of the Blind Eye
	 95735,// Artery Rippers
	 95746,// Iceshatter Gauntlets
	 95747,// Legplates of Re-Emergence
	 95752,// Pathogenic Gauntlets
	 95753,// Black Blood Legplates
	 95754,// Metabolically Boosted Shoulderplates
	 95766,// Bonemender Bracers
	 95767,// Spaulders of Primordial Growth
	 95777,// Matter-Swapped Legplates
	 95778,// Crown of the Golden Golem
	 95789,// Rein-Binder's Fists
	 95798,// Tidal Force Treads
	 95806,// Doomed Crown of Lei Shen
	 95807,// Legplates of the Lightning Throne
	 95808,// Legplates of Whipping Ionization
	 95821,// Lei Shen's Grounded Carapace
	 95825,// Breastplate of the All-Consuming Maw
	 95826,// Gauntlets of the All-Consuming Maw
	 95827,// Helmet of the All-Consuming Maw
	 95828,// Greaves of the All-Consuming Maw
	 95829,// Pauldrons of the All-Consuming Maw
	 95830,// Chestguard of the All-Consuming Maw
	 95831,// Handguards of the All-Consuming Maw
	 95832,// Faceguard of the All-Consuming Maw
	 95833,// Legguards of the All-Consuming Maw
	 95834,// Shoulderguards of the All-Consuming Maw
	 95872,// Reconstructed Holy Shoulderplates
	 95873,// Reconstructed Furious Shoulderplates
	 95874,// Reconstructed Bloody Shoulderplates
	 95910,// Lightning Emperor's Battleplate
	 95911,// Lightning Emperor's Gauntlets
	 95912,// Lightning Emperor's Helmet
	 95913,// Lightning Emperor's Legplates
	 95914,// Lightning Emperor's Pauldrons
	 95915,// Lightning Emperor's Breastplate
	 95916,// Lightning Emperor's Gloves
	 95917,// Lightning Emperor's Headguard
	 95918,// Lightning Emperor's Greaves
	 95919,// Lightning Emperor's Mantle
	 95920,// Lightning Emperor's Chestguard
	 95921,// Lightning Emperor's Handguards
	 95922,// Lightning Emperor's Faceguard
	 95923,// Lightning Emperor's Legguards
	 95924,// Lightning Emperor's Shoulderguards
	 95968,// Vaultwalker Sabatons
	 95974,// Abandoned Zandalari Greatbelt
	 95975,// Abandoned Zandalari Goreplate
	 95976,// Abandoned Zandalari Bucklebreaker
	 95978,// Locksmasher Greaves
	 95979,// Columnbreaker Stompers
	 95986,// Helmet of the Last Mogu
	 95987,// Battleplate of the Last Mogu
	 95988,// Gauntlets of the Last Mogu
	 95989,// Legplates of the Last Mogu
	 95990,// Pauldrons of the Last Mogu
	 95991,// Chestguard of the Last Mogu
	 95992,// Handguards of the Last Mogu
	 95993,// Faceguard of the Last Mogu
	 95994,// Legguards of the Last Mogu
	 95995,// Shoulderguards of the Last Mogu
	 96001,// Cloudbreaker Greatbelt
	 96002,// Chestplate of Violent Detonation
	 96003,// Bracers of Constant Implosion
	 96016,// Ionized Yojamban Carapace
	 96022,// Frozen Warlord's Bracers
	 96023,// Bloodlord's Bloodsoaked Legplates
	 96024,// Puncture-Proof Greathelm
	 96036,// Armplates of the Vanquished Abomination
	 96046,// Overloaded Bladebreaker Cuirass
	 96055,// Shoulderguards of Centripetal Destruction
	 96056,// Shell-Coated Wristplates
	 96068,// Refreshing Abalone Girdle
	 96069,// Tortos' Shellseizers
	 96074,// Plated Toothbreaker Girdle
	 96075,// Rot-Proof Greatplate
	 96088,// Ice-Scored Treads
	 96095,// Crown of Potentiated Birth
	 96096,// Talonrender Chestplate
	 96097,// Egg-Shard Grips
	 96104,// Caustic Spike Bracers
	 96105,// Legplates of the Dark Parasite
	 96106,// Treads of the Blind Eye
	 96107,// Artery Rippers
	 96118,// Iceshatter Gauntlets
	 96119,// Legplates of Re-Emergence
	 96124,// Pathogenic Gauntlets
	 96125,// Black Blood Legplates
	 96126,// Metabolically Boosted Shoulderplates
	 96138,// Bonemender Bracers
	 96139,// Spaulders of Primordial Growth
	 96149,// Matter-Swapped Legplates
	 96150,// Crown of the Golden Golem
	 96161,// Rein-Binder's Fists
	 96170,// Tidal Force Treads
	 96178,// Doomed Crown of Lei Shen
	 96179,// Legplates of the Lightning Throne
	 96180,// Legplates of Whipping Ionization
	 96193,// Lei Shen's Grounded Carapace
	 96244,// Reconstructed Holy Shoulderplates
	 96245,// Reconstructed Furious Shoulderplates
	 96246,// Reconstructed Bloody Shoulderplates
	 96340,// Vaultwalker Sabatons
	 96346,// Abandoned Zandalari Greatbelt
	 96347,// Abandoned Zandalari Goreplate
	 96348,// Abandoned Zandalari Bucklebreaker
	 96350,// Locksmasher Greaves
	 96351,// Columnbreaker Stompers
	 96373,// Cloudbreaker Greatbelt
	 96374,// Chestplate of Violent Detonation
	 96375,// Bracers of Constant Implosion
	 96388,// Ionized Yojamban Carapace
	 96394,// Frozen Warlord's Bracers
	 96395,// Bloodlord's Bloodsoaked Legplates
	 96396,// Puncture-Proof Greathelm
	 96408,// Armplates of the Vanquished Abomination
	 96418,// Overloaded Bladebreaker Cuirass
	 96427,// Shoulderguards of Centripetal Destruction
	 96428,// Shell-Coated Wristplates
	 96440,// Refreshing Abalone Girdle
	 96441,// Tortos' Shellseizers
	 96446,// Plated Toothbreaker Girdle
	 96447,// Rot-Proof Greatplate
	 96460,// Ice-Scored Treads
	 96467,// Crown of Potentiated Birth
	 96468,// Talonrender Chestplate
	 96469,// Egg-Shard Grips
	 96476,// Caustic Spike Bracers
	 96477,// Legplates of the Dark Parasite
	 96478,// Treads of the Blind Eye
	 96479,// Artery Rippers
	 96490,// Iceshatter Gauntlets
	 96491,// Legplates of Re-Emergence
	 96496,// Pathogenic Gauntlets
	 96497,// Black Blood Legplates
	 96498,// Metabolically Boosted Shoulderplates
	 96510,// Bonemender Bracers
	 96511,// Spaulders of Primordial Growth
	 96521,// Matter-Swapped Legplates
	 96522,// Crown of the Golden Golem
	 96533,// Rein-Binder's Fists
	 96542,// Tidal Force Treads
	 96550,// Doomed Crown of Lei Shen
	 96551,// Legplates of the Lightning Throne
	 96552,// Legplates of Whipping Ionization
	 96565,// Lei Shen's Grounded Carapace
	 96569,// Breastplate of the All-Consuming Maw
	 96570,// Gauntlets of the All-Consuming Maw
	 96571,// Helmet of the All-Consuming Maw
	 96572,// Greaves of the All-Consuming Maw
	 96573,// Pauldrons of the All-Consuming Maw
	 96574,// Chestguard of the All-Consuming Maw
	 96575,// Handguards of the All-Consuming Maw
	 96576,// Faceguard of the All-Consuming Maw
	 96577,// Legguards of the All-Consuming Maw
	 96578,// Shoulderguards of the All-Consuming Maw
	 96616,// Reconstructed Holy Shoulderplates
	 96617,// Reconstructed Furious Shoulderplates
	 96618,// Reconstructed Bloody Shoulderplates
	 96654,// Lightning Emperor's Battleplate
	 96655,// Lightning Emperor's Gauntlets
	 96656,// Lightning Emperor's Helmet
	 96657,// Lightning Emperor's Legplates
	 96658,// Lightning Emperor's Pauldrons
	 96659,// Lightning Emperor's Breastplate
	 96660,// Lightning Emperor's Gloves
	 96661,// Lightning Emperor's Headguard
	 96662,// Lightning Emperor's Greaves
	 96663,// Lightning Emperor's Mantle
	 96664,// Lightning Emperor's Chestguard
	 96665,// Lightning Emperor's Handguards
	 96666,// Lightning Emperor's Faceguard
	 96667,// Lightning Emperor's Legguards
	 96668,// Lightning Emperor's Shoulderguards
	 96712,// Vaultwalker Sabatons
	 96718,// Abandoned Zandalari Greatbelt
	 96719,// Abandoned Zandalari Goreplate
	 96720,// Abandoned Zandalari Bucklebreaker
	 96722,// Locksmasher Greaves
	 96723,// Columnbreaker Stompers
	 96730,// Helmet of the Last Mogu
	 96731,// Battleplate of the Last Mogu
	 96732,// Gauntlets of the Last Mogu
	 96733,// Legplates of the Last Mogu
	 96734,// Pauldrons of the Last Mogu
	 96735,// Chestguard of the Last Mogu
	 96736,// Handguards of the Last Mogu
	 96737,// Faceguard of the Last Mogu
	 96738,// Legguards of the Last Mogu
	 96739,// Shoulderguards of the Last Mogu
	 96745,// Cloudbreaker Greatbelt
	 96746,// Chestplate of Violent Detonation
	 96747,// Bracers of Constant Implosion
	 96760,// Ionized Yojamban Carapace
	 96766,// Frozen Warlord's Bracers
	 96767,// Bloodlord's Bloodsoaked Legplates
	 96768,// Puncture-Proof Greathelm
	 96780,// Armplates of the Vanquished Abomination
	 96790,// Overloaded Bladebreaker Cuirass
	 96799,// Shoulderguards of Centripetal Destruction
	 96800,// Shell-Coated Wristplates
	 96812,// Refreshing Abalone Girdle
	 96813,// Tortos' Shellseizers
	 96818,// Plated Toothbreaker Girdle
	 96819,// Rot-Proof Greatplate
	 96832,// Ice-Scored Treads
	 96839,// Crown of Potentiated Birth
	 96840,// Talonrender Chestplate
	 96841,// Egg-Shard Grips
	 96848,// Caustic Spike Bracers
	 96849,// Legplates of the Dark Parasite
	 96850,// Treads of the Blind Eye
	 96851,// Artery Rippers
	 96862,// Iceshatter Gauntlets
	 96863,// Legplates of Re-Emergence
	 96868,// Pathogenic Gauntlets
	 96869,// Black Blood Legplates
	 96870,// Metabolically Boosted Shoulderplates
	 96882,// Bonemender Bracers
	 96883,// Spaulders of Primordial Growth
	 96893,// Matter-Swapped Legplates
	 96894,// Crown of the Golden Golem
	 96905,// Rein-Binder's Fists
	 96914,// Tidal Force Treads
	 96922,// Doomed Crown of Lei Shen
	 96923,// Legplates of the Lightning Throne
	 96924,// Legplates of Whipping Ionization
	 96937,// Lei Shen's Grounded Carapace
	 96988,// Reconstructed Holy Shoulderplates
	 96989,// Reconstructed Furious Shoulderplates
	 96990,// Reconstructed Bloody Shoulderplates
	 97084,// Vaultwalker Sabatons
	 97090,// Abandoned Zandalari Greatbelt
	 97091,// Abandoned Zandalari Goreplate
	 97092,// Abandoned Zandalari Bucklebreaker
	 97094,// Locksmasher Greaves
	 97095,// Columnbreaker Stompers
	 97632,// Insurrection Breastplate
	 97634,// Secessionist's Breastplate
	 97637,// Insurrection Boots
	 97640,// Secessionist's Boots
	 97645,// Insurrection Gauntlets
	 97650,// Secessionist's Gauntlets
	 97654,// Insurrection Helm
	 97656,// Secessionist's Helm
	 97661,// Insurrection Legplates
	 97665,// Secessionist's Legplates
	 97672,// Insurrection Spaulders
	 97676,// Secessionist's Spaulders
	 97680,// Insurrection Belt
	 97684,// Secessionist's Belt
	 97722,// Insubordination Breastplate
	 97723,// Insubordination Boots
	 97724,// Insubordination Gauntlets
	 97725,// Insubordination Helm
	 97726,// Insubordination Legplates
	 97727,// Insubordination Shoulderpads
	 97728,// Insubordination Belt
	 97733,// Insubordination Gauntlets
	 97734,// Insubordination Helm
	 97735,// Insubordination Legplates
	 97736,// Insubordination Shoulderpads
	 97737,// Insubordination Belt
	 97738,// Insubordination Breastplate
	 97739,// Insubordination Boots
	 97761,// Insurrection Spaulders
	 97762,// Insurrection Belt
	 97763,// Insurrection Gauntlets
	 97764,// Insurrection Helm
	 97765,// Insurrection Legplates
	 97766,// Insurrection Breastplate
	 97767,// Insurrection Boots
	 97775,// Secessionist's Gauntlets
	 97776,// Secessionist's Helm
	 97777,// Secessionist's Breastplate
	 97778,// Secessionist's Boots
	 97779,// Secessionist's Belt
	 97780,// Secessionist's Legplates
	 97781,// Secessionist's Spaulders
	 97782,// Secessionist's Breastplate
	 97783,// Secessionist's Boots
	 97784,// Secessionist's Gauntlets
	 97785,// Secessionist's Helm
	 97786,// Secessionist's Legplates
	 97787,// Secessionist's Spaulders
	 97788,// Secessionist's Belt
	 98140,// Boots of Boundless Patience
	 98141,// Sabatons of the Humble
	 98143,// Subservient Greatboots
	 98218,// Lightning Pillar Breastplate
	 98219,// Lightning Pillar Sabatons
	 98220,// Lightning Pillar Gauntlets
	 98221,// Lightning Pillar Helm
	 98222,// Lightning Pillar Legplates
	 98223,// Lightning Pillar Pauldrons
	 98224,// Lightning Pillar Girdle
	 98225,// Lightning Pillar Vambraces
	 98239,// Doubtcrusher Breastplate
	 98240,// Doubtcrusher Sabatons
	 98241,// Doubtcrusher Gauntlets
	 98242,// Doubtcrusher Helm
	 98243,// Doubtcrusher Legplates
	 98244,// Doubtcrusher Pauldrons
	 98245,// Doubtcrusher Girdle
	 98246,// Doubtcrusher Vambraces
	 98250,// Thunder Bastion Breastplate
	 98251,// Thunder Bastion Sabatons
	 98252,// Thunder Bastion Gauntlets
	 98253,// Thunder Bastion Helm
	 98254,// Thunder Bastion Legplates
	 98255,// Thunder Bastion Pauldrons
	 98256,// Thunder Bastion Girdle
	 98257,// Thunder Bastion Vambraces
	 98602,// Blessed Trillium Greaves
	 98606,// Protector's Trillium Legguards
	 98607,// Avenger's Trillium Legplates
	 98611,// Blessed Trillium Belt
	 98615,// Protector's Trillium Waistguard
	 98616,// Avenger's Trillium Waistplate
	 98784,// Crafted Malevolent Gladiator's Dreadplate Chestpiece
	 98785,// Crafted Malevolent Gladiator's Dreadplate Gauntlets
	 98786,// Crafted Malevolent Gladiator's Dreadplate Helm
	 98787,// Crafted Malevolent Gladiator's Dreadplate Legguards
	 98788,// Crafted Malevolent Gladiator's Dreadplate Shoulders
	 98843,// Crafted Malevolent Gladiator's Scaled Chestpiece
	 98844,// Crafted Malevolent Gladiator's Scaled Gauntlets
	 98845,// Crafted Malevolent Gladiator's Scaled Helm
	 98846,// Crafted Malevolent Gladiator's Scaled Legguards
	 98847,// Crafted Malevolent Gladiator's Scaled Shoulders
	 98848,// Crafted Malevolent Gladiator's Clasp of Cruelty
	 98849,// Crafted Malevolent Gladiator's Clasp of Meditation
	 98850,// Crafted Malevolent Gladiator's Greaves of Alacrity
	 98851,// Crafted Malevolent Gladiator's Greaves of Meditation
	 98852,// Crafted Malevolent Gladiator's Bracers of Prowess
	 98853,// Crafted Malevolent Gladiator's Bracers of Meditation
	 98854,// Crafted Malevolent Gladiator's Ornamented Chestguard
	 98855,// Crafted Malevolent Gladiator's Ornamented Gloves
	 98856,// Crafted Malevolent Gladiator's Ornamented Headcover
	 98857,// Crafted Malevolent Gladiator's Ornamented Legplates
	 98858,// Crafted Malevolent Gladiator's Ornamented Spaulders
	 98859,// Crafted Malevolent Gladiator's Girdle of Accuracy
	 98860,// Crafted Malevolent Gladiator's Girdle of Prowess
	 98861,// Crafted Malevolent Gladiator's Warboots of Cruelty
	 98862,// Crafted Malevolent Gladiator's Warboots of Alacrity
	 98863,// Crafted Malevolent Gladiator's Armplates of Proficiency
	 98864,// Crafted Malevolent Gladiator's Armplates of Alacrity
	 98926,// Crafted Malevolent Gladiator's Plate Chestpiece
	 98927,// Crafted Malevolent Gladiator's Plate Gauntlets
	 98928,// Crafted Malevolent Gladiator's Plate Helm
	 98929,// Crafted Malevolent Gladiator's Plate Legguards
	 98930,// Crafted Malevolent Gladiator's Plate Shoulders
	 98979,// Headguard of Winged Triumph
	 98980,// Greaves of Winged Triumph
	 98982,// Gloves of Winged Triumph
	 98985,// Helmet of Winged Triumph
	 98986,// Legplates of Winged Triumph
	 98987,// Pauldrons of Winged Triumph
	 99002,// Gauntlets of Winged Triumph
	 99003,// Breastplate of Winged Triumph
	 99026,// Legguards of Winged Triumph
	 99027,// Shoulderguards of Winged Triumph
	 99028,// Handguards of Winged Triumph
	 99029,// Faceguard of Winged Triumph
	 99030,// Shoulderguards of the Prehistoric Marauder
	 99031,// Chestguard of Winged Triumph
	 99032,// Faceguard of the Prehistoric Marauder
	 99033,// Legguards of the Prehistoric Marauder
	 99034,// Gauntlets of the Prehistoric Marauder
	 99035,// Legplates of the Prehistoric Marauder
	 99036,// Pauldrons of the Prehistoric Marauder
	 99037,// Chestguard of the Prehistoric Marauder
	 99038,// Handguards of the Prehistoric Marauder
	 99039,// Legguards of Cyclopean Dread
	 99040,// Shoulderguards of Cyclopean Dread
	 99046,// Helmet of the Prehistoric Marauder
	 99047,// Battleplate of the Prehistoric Marauder
	 99048,// Handguards of Cyclopean Dread
	 99049,// Faceguard of Cyclopean Dread
	 99052,// Battleplate of Winged Triumph
	 99057,// Helmet of Cyclopean Dread
	 99058,// Greaves of Cyclopean Dread
	 99059,// Pauldrons of Cyclopean Dread
	 99060,// Chestguard of Cyclopean Dread
	 99066,// Breastplate of Cyclopean Dread
	 99067,// Gauntlets of Cyclopean Dread
	 99076,// Mantle of Winged Triumph
	 99124,// Greaves of Winged Triumph
	 99125,// Mantle of Winged Triumph
	 99126,// Chestguard of Winged Triumph
	 99127,// Handguards of Winged Triumph
	 99128,// Faceguard of Winged Triumph
	 99129,// Legguards of Winged Triumph
	 99130,// Shoulderguards of Winged Triumph
	 99132,// Pauldrons of Winged Triumph
	 99133,// Breastplate of Winged Triumph
	 99134,// Gloves of Winged Triumph
	 99135,// Headguard of Winged Triumph
	 99136,// Battleplate of Winged Triumph
	 99137,// Gauntlets of Winged Triumph
	 99138,// Helmet of Winged Triumph
	 99139,// Legplates of Winged Triumph
	 99179,// Shoulderguards of Cyclopean Dread
	 99186,// Greaves of Cyclopean Dread
	 99187,// Pauldrons of Cyclopean Dread
	 99188,// Chestguard of Cyclopean Dread
	 99189,// Handguards of Cyclopean Dread
	 99190,// Faceguard of Cyclopean Dread
	 99191,// Legguards of Cyclopean Dread
	 99192,// Breastplate of Cyclopean Dread
	 99193,// Gauntlets of Cyclopean Dread
	 99194,// Helmet of Cyclopean Dread
	 99195,// Legguards of the Prehistoric Marauder
	 99196,// Shoulderguards of the Prehistoric Marauder
	 99197,// Battleplate of the Prehistoric Marauder
	 99198,// Gauntlets of the Prehistoric Marauder
	 99199,// Legplates of the Prehistoric Marauder
	 99200,// Pauldrons of the Prehistoric Marauder
	 99201,// Chestguard of the Prehistoric Marauder
	 99202,// Handguards of the Prehistoric Marauder
	 99203,// Faceguard of the Prehistoric Marauder
	 99206,// Helmet of the Prehistoric Marauder
	 99323,// Faceguard of Cyclopean Dread
	 99324,// Legguards of Cyclopean Dread
	 99325,// Shoulderguards of Cyclopean Dread
	 99330,// Chestguard of Cyclopean Dread
	 99331,// Handguards of Cyclopean Dread
	 99335,// Breastplate of Cyclopean Dread
	 99336,// Gauntlets of Cyclopean Dread
	 99337,// Helmet of Cyclopean Dread
	 99338,// Greaves of Cyclopean Dread
	 99339,// Pauldrons of Cyclopean Dread
	 99364,// Shoulderguards of Winged Triumph
	 99368,// Chestguard of Winged Triumph
	 99369,// Handguards of Winged Triumph
	 99370,// Faceguard of Winged Triumph
	 99371,// Legguards of Winged Triumph
	 99372,// Legplates of Winged Triumph
	 99373,// Pauldrons of Winged Triumph
	 99374,// Breastplate of Winged Triumph
	 99375,// Gloves of Winged Triumph
	 99376,// Headguard of Winged Triumph
	 99377,// Greaves of Winged Triumph
	 99378,// Mantle of Winged Triumph
	 99379,// Helmet of Winged Triumph
	 99380,// Gauntlets of Winged Triumph
	 99387,// Battleplate of Winged Triumph
	 99407,// Shoulderguards of the Prehistoric Marauder
	 99408,// Handguards of the Prehistoric Marauder
	 99409,// Faceguard of the Prehistoric Marauder
	 99410,// Legguards of the Prehistoric Marauder
	 99411,// Battleplate of the Prehistoric Marauder
	 99412,// Gauntlets of the Prehistoric Marauder
	 99413,// Legplates of the Prehistoric Marauder
	 99414,// Pauldrons of the Prehistoric Marauder
	 99415,// Chestguard of the Prehistoric Marauder
	 99418,// Helmet of the Prehistoric Marauder
	 99557,// Faceguard of the Prehistoric Marauder
	 99558,// Legguards of the Prehistoric Marauder
	 99559,// Gauntlets of the Prehistoric Marauder
	 99560,// Legplates of the Prehistoric Marauder
	 99561,// Pauldrons of the Prehistoric Marauder
	 99562,// Chestguard of the Prehistoric Marauder
	 99563,// Handguards of the Prehistoric Marauder
	 99564,// Legguards of Cyclopean Dread
	 99566,// Battleplate of Winged Triumph
	 99571,// Helmet of Cyclopean Dread
	 99572,// Greaves of Cyclopean Dread
	 99593,// Legguards of Winged Triumph
	 99594,// Shoulderguards of Winged Triumph
	 99595,// Handguards of Winged Triumph
	 99596,// Faceguard of Winged Triumph
	 99597,// Shoulderguards of the Prehistoric Marauder
	 99598,// Chestguard of Winged Triumph
	 99602,// Helmet of the Prehistoric Marauder
	 99603,// Battleplate of the Prehistoric Marauder
	 99604,// Handguards of Cyclopean Dread
	 99605,// Faceguard of Cyclopean Dread
	 99608,// Breastplate of Cyclopean Dread
	 99609,// Gauntlets of Cyclopean Dread
	 99625,// Gauntlets of Winged Triumph
	 99626,// Breastplate of Winged Triumph
	 99639,// Pauldrons of Cyclopean Dread
	 99640,// Chestguard of Cyclopean Dread
	 99648,// Gloves of Winged Triumph
	 99651,// Helmet of Winged Triumph
	 99652,// Shoulderguards of Cyclopean Dread
	 99656,// Mantle of Winged Triumph
	 99661,// Legplates of Winged Triumph
	 99662,// Pauldrons of Winged Triumph
	 99665,// Headguard of Winged Triumph
	 99666,// Greaves of Winged Triumph
	 99806,// Tyrannical Gladiator's Dreadplate Chestpiece
	 99807,// Tyrannical Gladiator's Dreadplate Gauntlets
	 99808,// Tyrannical Gladiator's Dreadplate Helm
	 99809,// Tyrannical Gladiator's Dreadplate Legguards
	 99810,// Tyrannical Gladiator's Dreadplate Shoulders
	 99870,// Tyrannical Gladiator's Scaled Chestpiece
	 99871,// Tyrannical Gladiator's Scaled Gauntlets
	 99872,// Tyrannical Gladiator's Scaled Helm
	 99873,// Tyrannical Gladiator's Scaled Legguards
	 99874,// Tyrannical Gladiator's Scaled Shoulders
	 99875,// Tyrannical Gladiator's Clasp of Cruelty
	 99876,// Tyrannical Gladiator's Clasp of Meditation
	 99877,// Tyrannical Gladiator's Greaves of Alacrity
	 99878,// Tyrannical Gladiator's Greaves of Meditation
	 99879,// Tyrannical Gladiator's Bracers of Prowess
	 99880,// Tyrannical Gladiator's Bracers of Meditation
	 99881,// Tyrannical Gladiator's Ornamented Chestguard
	 99882,// Tyrannical Gladiator's Ornamented Gloves
	 99883,// Tyrannical Gladiator's Ornamented Headcover
	 99884,// Tyrannical Gladiator's Ornamented Legplates
	 99885,// Tyrannical Gladiator's Ornamented Spaulders
	 99886,// Tyrannical Gladiator's Girdle of Accuracy
	 99887,// Tyrannical Gladiator's Girdle of Prowess
	 99888,// Tyrannical Gladiator's Warboots of Cruelty
	 99889,// Tyrannical Gladiator's Warboots of Alacrity
	 99890,// Tyrannical Gladiator's Armplates of Proficiency
	 99891,// Tyrannical Gladiator's Armplates of Alacrity
	 99957,// Tyrannical Gladiator's Plate Chestpiece
	 99958,// Tyrannical Gladiator's Plate Gauntlets
	 99959,// Tyrannical Gladiator's Plate Helm
	 99960,// Tyrannical Gladiator's Plate Legguards
	 99961,// Tyrannical Gladiator's Plate Shoulders
	 99992,// Tyrannical Gladiator's Plate Gauntlets
	 99993,// Tyrannical Gladiator's Plate Helm
	100013,// Tyrannical Gladiator's Scaled Gauntlets
	100015,// Tyrannical Gladiator's Ornamented Chestguard
	100018,// Tyrannical Gladiator's Ornamented Headcover
	100021,// Tyrannical Gladiator's Greaves of Alacrity
	100022,// Tyrannical Gladiator's Greaves of Meditation
	100023,// Tyrannical Gladiator's Girdle of Accuracy
	100034,// Tyrannical Gladiator's Dreadplate Gauntlets
	100035,// Tyrannical Gladiator's Dreadplate Legguards
	100036,// Tyrannical Gladiator's Dreadplate Shoulders
	100062,// Tyrannical Gladiator's Dreadplate Chestpiece
	100071,// Tyrannical Gladiator's Plate Shoulders
	100081,// Tyrannical Gladiator's Bracers of Prowess
	100083,// Tyrannical Gladiator's Ornamented Spaulders
	100084,// Tyrannical Gladiator's Warboots of Cruelty
	100088,// Tyrannical Gladiator's Armplates of Proficiency
	100099,// Tyrannical Gladiator's Dreadplate Helm
	100108,// Tyrannical Gladiator's Ornamented Gloves
	100110,// Tyrannical Gladiator's Girdle of Prowess
	100114,// Tyrannical Gladiator's Plate Chestpiece
	100118,// Tyrannical Gladiator's Plate Legguards
	100130,// Tyrannical Gladiator's Scaled Shoulders
	100131,// Tyrannical Gladiator's Warboots of Alacrity
	100133,// Tyrannical Gladiator's Scaled Chestpiece
	100134,// Tyrannical Gladiator's Clasp of Meditation
	100150,// Tyrannical Gladiator's Clasp of Cruelty
	100151,// Tyrannical Gladiator's Bracers of Meditation
	100154,// Tyrannical Gladiator's Ornamented Legplates
	100157,// Tyrannical Gladiator's Armplates of Alacrity
	100165,// Tyrannical Gladiator's Scaled Helm
	100166,// Tyrannical Gladiator's Scaled Legguards
	100243,// Grievous Gladiator's Dreadplate Chestpiece
	100244,// Grievous Gladiator's Dreadplate Chestpiece
	100245,// Grievous Gladiator's Dreadplate Gauntlets
	100246,// Grievous Gladiator's Dreadplate Gauntlets
	100247,// Grievous Gladiator's Dreadplate Helm
	100248,// Grievous Gladiator's Dreadplate Helm
	100249,// Grievous Gladiator's Dreadplate Legguards
	100250,// Grievous Gladiator's Dreadplate Legguards
	100251,// Grievous Gladiator's Dreadplate Shoulders
	100252,// Grievous Gladiator's Dreadplate Shoulders
	100363,// Grievous Gladiator's Scaled Chestpiece
	100364,// Grievous Gladiator's Scaled Chestpiece
	100365,// Grievous Gladiator's Scaled Gauntlets
	100366,// Grievous Gladiator's Scaled Gauntlets
	100367,// Grievous Gladiator's Scaled Helm
	100368,// Grievous Gladiator's Scaled Helm
	100369,// Grievous Gladiator's Scaled Legguards
	100370,// Grievous Gladiator's Scaled Legguards
	100371,// Grievous Gladiator's Scaled Shoulders
	100372,// Grievous Gladiator's Scaled Shoulders
	100373,// Grievous Gladiator's Clasp of Cruelty
	100374,// Grievous Gladiator's Scaled Clasp
	100375,// Grievous Gladiator's Clasp of Meditation
	100376,// Grievous Gladiator's Ornamented Clasp
	100377,// Grievous Gladiator's Greaves of Alacrity
	100378,// Grievous Gladiator's Ornamented Greaves
	100379,// Grievous Gladiator's Greaves of Meditation
	100380,// Grievous Gladiator's Scaled Greaves
	100381,// Grievous Gladiator's Bracers of Prowess
	100382,// Grievous Gladiator's Bracers of Meditation
	100383,// Grievous Gladiator's Ornamented Chestguard
	100384,// Grievous Gladiator's Ornamented Chestguard
	100385,// Grievous Gladiator's Ornamented Gloves
	100386,// Grievous Gladiator's Ornamented Gloves
	100387,// Grievous Gladiator's Ornamented Headcover
	100388,// Grievous Gladiator's Ornamented Headcover
	100389,// Grievous Gladiator's Ornamented Legplates
	100390,// Grievous Gladiator's Ornamented Legplates
	100391,// Grievous Gladiator's Ornamented Spaulders
	100392,// Grievous Gladiator's Ornamented Spaulders
	100393,// Grievous Gladiator's Girdle of Accuracy
	100394,// Grievous Gladiator's Dreadplate Girdle
	100395,// Grievous Gladiator's Girdle of Prowess
	100396,// Grievous Gladiator's Plate Girdle
	100397,// Grievous Gladiator's Warboots of Cruelty
	100398,// Grievous Gladiator's Plate Warboots
	100399,// Grievous Gladiator's Warboots of Alacrity
	100400,// Grievous Gladiator's Dreadplate Warboots
	100401,// Grievous Gladiator's Armplates of Proficiency
	100402,// Grievous Gladiator's Armplates of Alacrity
	100520,// Grievous Gladiator's Plate Chestpiece
	100521,// Grievous Gladiator's Plate Chestpiece
	100522,// Grievous Gladiator's Plate Gauntlets
	100523,// Grievous Gladiator's Plate Gauntlets
	100524,// Grievous Gladiator's Plate Helm
	100525,// Grievous Gladiator's Plate Helm
	100526,// Grievous Gladiator's Plate Legguards
	100527,// Grievous Gladiator's Plate Legguards
	100528,// Grievous Gladiator's Plate Shoulders
	100529,// Grievous Gladiator's Plate Shoulders
	100561,// Grievous Gladiator's Plate Gauntlets
	100562,// Grievous Gladiator's Plate Helm
	100573,// Grievous Gladiator's Scaled Gauntlets
	100575,// Grievous Gladiator's Ornamented Chestguard
	100578,// Grievous Gladiator's Ornamented Headcover
	100581,// Grievous Gladiator's Greaves of Alacrity
	100582,// Grievous Gladiator's Greaves of Meditation
	100583,// Grievous Gladiator's Girdle of Accuracy
	100594,// Grievous Gladiator's Dreadplate Gauntlets
	100595,// Grievous Gladiator's Dreadplate Legguards
	100596,// Grievous Gladiator's Dreadplate Shoulders
	100622,// Grievous Gladiator's Dreadplate Chestpiece
	100631,// Grievous Gladiator's Plate Shoulders
	100641,// Grievous Gladiator's Bracers of Prowess
	100643,// Grievous Gladiator's Ornamented Spaulders
	100644,// Grievous Gladiator's Warboots of Cruelty
	100648,// Grievous Gladiator's Armplates of Proficiency
	100659,// Grievous Gladiator's Dreadplate Helm
	100668,// Grievous Gladiator's Ornamented Gloves
	100670,// Grievous Gladiator's Girdle of Prowess
	100674,// Grievous Gladiator's Plate Chestpiece
	100678,// Grievous Gladiator's Plate Legguards
	100690,// Grievous Gladiator's Scaled Shoulders
	100691,// Grievous Gladiator's Warboots of Alacrity
	100693,// Grievous Gladiator's Scaled Chestpiece
	100694,// Grievous Gladiator's Clasp of Meditation
	100710,// Grievous Gladiator's Clasp of Cruelty
	100711,// Grievous Gladiator's Bracers of Meditation
	100714,// Grievous Gladiator's Ornamented Legplates
	100717,// Grievous Gladiator's Armplates of Alacrity
	100725,// Grievous Gladiator's Scaled Helm
	100726,// Grievous Gladiator's Scaled Legguards
	100953,// Girdle of Soothing Detonation
	100954,// Sap-Encrusted Legplates
	100959,// Sightfinder Helm
	100964,// Siegeworn Bracers
	100969,// Anchoring Sabatons
	100970,// Spaulders of Immovable Stone
	100977,// Heart-Lesion Breastplate
	100978,// Heart-Lesion Sabatons
	100979,// Heart-Lesion Gauntlets
	100980,// Heart-Lesion Helm
	100981,// Heart-Lesion Legplates
	100982,// Heart-Lesion Pauldrons
	100983,// Heart-Lesion Girdle
	100984,// Heart-Lesion Vambraces
	100992,// Heart-Lesion Chestguard
	100994,// Heart-Lesion Greaves
	100995,// Heart-Lesion Handguards
	100996,// Heart-Lesion Faceguard
	100997,// Heart-Lesion Legguards
	101003,// Heart-Lesion Shoulderguards
	101004,// Heart-Lesion Waistband
	101005,// Heart-Lesion Armguards
	101120,// Sunsoul Battleplate
	101121,// Sunsoul Sabatons
	101122,// Sunsoul Gauntlets
	101123,// Sunsoul Helm
	101124,// Sunsoul Legplates
	101125,// Sunsoul Pauldrons
	101126,// Sunsoul Girdle
	101127,// Sunsoul Vambraces
	101128,// Sunsoul Breastplate
	101130,// Sunsoul Boots
	101131,// Sunsoul Gloves
	101132,// Sunsoul Headpiece
	101133,// Sunsoul Leggings
	101139,// Sunsoul Spaulders
	101140,// Sunsoul Belt
	101141,// Sunsoul Armplates
	101153,// Sunsoul Chestguard
	101155,// Sunsoul Greaves
	101156,// Sunsoul Handguards
	101157,// Sunsoul Faceguard
	101158,// Sunsoul Legguards
	101164,// Sunsoul Shoulderguards
	101165,// Sunsoul Waistband
	101166,// Sunsoul Armguards
	101279,// Oathsworn Breastplate
	101280,// Oathsworn Sabatons
	101281,// Oathsworn Gauntlets
	101282,// Oathsworn Helm
	101283,// Oathsworn Legplates
	101284,// Oathsworn Pauldrons
	101285,// Oathsworn Girdle
	101286,// Oathsworn Vambraces
	101296,// Oathsworn Chestguard
	101298,// Oathsworn Greaves
	101299,// Oathsworn Handguards
	101300,// Oathsworn Faceguard
	101301,// Oathsworn Legguards
	101307,// Oathsworn Shoulderguards
	101308,// Oathsworn Waistband
	101309,// Oathsworn Armguards
	101789,// Cliffbreaker Breastplate
	101791,// Cliffbreaker Gauntlets
	101792,// Cliffbreaker Girdle
	101793,// Cliffbreaker Helm
	101794,// Cliffbreaker Legplates
	101796,// Cliffbreaker Pauldrons
	101797,// Cliffbreaker Sabatons
	101799,// Cliffbreaker Vambraces
	101819,// Everbright Breastplate
	101820,// Everbright Gauntlets
	101821,// Everbright Girdle
	101822,// Everbright Helm
	101823,// Everbright Legplates
	101824,// Everbright Pauldrons
	101825,// Everbright Sabatons
	101826,// Everbright Vambraces
	101851,// Elder Tortoiseshell Breastplate
	101853,// Elder Tortoiseshell Gauntlets
	101854,// Elder Tortoiseshell Girdle
	101855,// Elder Tortoiseshell Helm
	101856,// Elder Tortoiseshell Legplates
	101858,// Elder Tortoiseshell Pauldrons
	101859,// Elder Tortoiseshell Sabatons
	101861,// Elder Tortoiseshell Vambraces
	101878,// Cliffbreaker Breastplate
	101880,// Cliffbreaker Gauntlets
	101881,// Cliffbreaker Girdle
	101882,// Cliffbreaker Helm
	101883,// Cliffbreaker Legplates
	101885,// Cliffbreaker Pauldrons
	101886,// Cliffbreaker Sabatons
	101888,// Cliffbreaker Vambraces
	101908,// Everbright Breastplate
	101909,// Everbright Gauntlets
	101910,// Everbright Girdle
	101911,// Everbright Helm
	101912,// Everbright Legplates
	101913,// Everbright Pauldrons
	101914,// Everbright Sabatons
	101915,// Everbright Vambraces
	101938,// Elder Tortoiseshell Breastplate
	101940,// Elder Tortoiseshell Gauntlets
	101941,// Elder Tortoiseshell Girdle
	101942,// Elder Tortoiseshell Helm
	101943,// Elder Tortoiseshell Legplates
	101945,// Elder Tortoiseshell Pauldrons
	101946,// Elder Tortoiseshell Sabatons
	101948,// Elder Tortoiseshell Vambraces
	102618,// Prideful Gladiator's Plate Gauntlets
	102619,// Prideful Gladiator's Plate Helm
	102630,// Prideful Gladiator's Scaled Gauntlets
	102632,// Prideful Gladiator's Ornamented Chestguard
	102635,// Prideful Gladiator's Ornamented Headcover
	102638,// Prideful Gladiator's Greaves of Alacrity
	102639,// Prideful Gladiator's Greaves of Meditation
	102640,// Prideful Gladiator's Girdle of Accuracy
	102650,// Prideful Gladiator's Dreadplate Gauntlets
	102651,// Prideful Gladiator's Dreadplate Legguards
	102652,// Prideful Gladiator's Dreadplate Shoulders
	102676,// Prideful Gladiator's Dreadplate Chestpiece
	102685,// Prideful Gladiator's Plate Shoulders
	102695,// Prideful Gladiator's Bracers of Prowess
	102697,// Prideful Gladiator's Ornamented Spaulders
	102698,// Prideful Gladiator's Warboots of Cruelty
	102702,// Prideful Gladiator's Armplates of Proficiency
	102713,// Prideful Gladiator's Dreadplate Helm
	102722,// Prideful Gladiator's Ornamented Gloves
	102724,// Prideful Gladiator's Girdle of Prowess
	102728,// Prideful Gladiator's Plate Chestpiece
	102732,// Prideful Gladiator's Plate Legguards
	102744,// Prideful Gladiator's Scaled Shoulders
	102745,// Prideful Gladiator's Warboots of Alacrity
	102747,// Prideful Gladiator's Scaled Chestpiece
	102748,// Prideful Gladiator's Clasp of Meditation
	102764,// Prideful Gladiator's Clasp of Cruelty
	102765,// Prideful Gladiator's Bracers of Meditation
	102768,// Prideful Gladiator's Ornamented Legplates
	102771,// Prideful Gladiator's Armplates of Alacrity
	102779,// Prideful Gladiator's Scaled Helm
	102780,// Prideful Gladiator's Scaled Legguards
	102815,// Grievous Gladiator's Plate Gauntlets
	102816,// Grievous Gladiator's Plate Helm
	102827,// Grievous Gladiator's Scaled Gauntlets
	102829,// Grievous Gladiator's Ornamented Chestguard
	102832,// Grievous Gladiator's Ornamented Headcover
	102835,// Grievous Gladiator's Greaves of Alacrity
	102836,// Grievous Gladiator's Greaves of Meditation
	102837,// Grievous Gladiator's Girdle of Accuracy
	102847,// Grievous Gladiator's Dreadplate Gauntlets
	102848,// Grievous Gladiator's Dreadplate Legguards
	102849,// Grievous Gladiator's Dreadplate Shoulders
	102873,// Grievous Gladiator's Dreadplate Chestpiece
	102882,// Grievous Gladiator's Plate Shoulders
	102892,// Grievous Gladiator's Bracers of Prowess
	102894,// Grievous Gladiator's Ornamented Spaulders
	102895,// Grievous Gladiator's Warboots of Cruelty
	102899,// Grievous Gladiator's Armplates of Proficiency
	102910,// Grievous Gladiator's Dreadplate Helm
	102919,// Grievous Gladiator's Ornamented Gloves
	102921,// Grievous Gladiator's Girdle of Prowess
	102925,// Grievous Gladiator's Plate Chestpiece
	102929,// Grievous Gladiator's Plate Legguards
	102941,// Grievous Gladiator's Scaled Shoulders
	102942,// Grievous Gladiator's Warboots of Alacrity
	102944,// Grievous Gladiator's Scaled Chestpiece
	102945,// Grievous Gladiator's Clasp of Meditation
	102961,// Grievous Gladiator's Clasp of Cruelty
	102962,// Grievous Gladiator's Bracers of Meditation
	102965,// Grievous Gladiator's Ornamented Legplates
	102968,// Grievous Gladiator's Armplates of Alacrity
	102976,// Grievous Gladiator's Scaled Helm
	102977,// Grievous Gladiator's Scaled Legguards
	103004,// Prideful Gladiator's Dreadplate Chestpiece
	103005,// Prideful Gladiator's Dreadplate Gauntlets
	103006,// Prideful Gladiator's Dreadplate Helm
	103007,// Prideful Gladiator's Dreadplate Legguards
	103008,// Prideful Gladiator's Dreadplate Shoulders
	103059,// Prideful Gladiator's Scaled Chestpiece
	103060,// Prideful Gladiator's Scaled Gauntlets
	103061,// Prideful Gladiator's Scaled Helm
	103062,// Prideful Gladiator's Scaled Legguards
	103063,// Prideful Gladiator's Scaled Shoulders
	103064,// Prideful Gladiator's Scaled Clasp
	103065,// Prideful Gladiator's Ornamented Clasp
	103066,// Prideful Gladiator's Ornamented Greaves
	103067,// Prideful Gladiator's Scaled Greaves
	103068,// Prideful Gladiator's Ornamented Chestguard
	103069,// Prideful Gladiator's Ornamented Gloves
	103070,// Prideful Gladiator's Ornamented Headcover
	103071,// Prideful Gladiator's Ornamented Legplates
	103072,// Prideful Gladiator's Ornamented Spaulders
	103073,// Prideful Gladiator's Dreadplate Girdle
	103074,// Prideful Gladiator's Plate Girdle
	103075,// Prideful Gladiator's Plate Warboots
	103076,// Prideful Gladiator's Dreadplate Warboots
	103128,// Prideful Gladiator's Plate Chestpiece
	103129,// Prideful Gladiator's Plate Gauntlets
	103130,// Prideful Gladiator's Plate Helm
	103131,// Prideful Gladiator's Plate Legguards
	103132,// Prideful Gladiator's Plate Shoulders
	103179,// Grievous Gladiator's Dreadplate Chestpiece
	103180,// Grievous Gladiator's Dreadplate Gauntlets
	103181,// Grievous Gladiator's Dreadplate Helm
	103182,// Grievous Gladiator's Dreadplate Legguards
	103183,// Grievous Gladiator's Dreadplate Shoulders
	103242,// Grievous Gladiator's Scaled Chestpiece
	103243,// Grievous Gladiator's Scaled Gauntlets
	103244,// Grievous Gladiator's Scaled Helm
	103245,// Grievous Gladiator's Scaled Legguards
	103246,// Grievous Gladiator's Scaled Shoulders
	103247,// Grievous Gladiator's Clasp of Cruelty
	103248,// Grievous Gladiator's Clasp of Meditation
	103249,// Grievous Gladiator's Greaves of Alacrity
	103250,// Grievous Gladiator's Greaves of Meditation
	103251,// Grievous Gladiator's Bracers of Prowess
	103252,// Grievous Gladiator's Bracers of Meditation
	103253,// Grievous Gladiator's Ornamented Chestguard
	103254,// Grievous Gladiator's Ornamented Gloves
	103255,// Grievous Gladiator's Ornamented Headcover
	103256,// Grievous Gladiator's Ornamented Legplates
	103257,// Grievous Gladiator's Ornamented Spaulders
	103258,// Grievous Gladiator's Girdle of Accuracy
	103259,// Grievous Gladiator's Girdle of Prowess
	103260,// Grievous Gladiator's Warboots of Cruelty
	103261,// Grievous Gladiator's Warboots of Alacrity
	103262,// Grievous Gladiator's Armplates of Proficiency
	103263,// Grievous Gladiator's Armplates of Alacrity
	103328,// Grievous Gladiator's Plate Chestpiece
	103329,// Grievous Gladiator's Plate Gauntlets
	103330,// Grievous Gladiator's Plate Helm
	103331,// Grievous Gladiator's Plate Legguards
	103332,// Grievous Gladiator's Plate Shoulders
	103376,// Prideful Gladiator's Dreadplate Chestpiece
	103377,// Prideful Gladiator's Dreadplate Gauntlets
	103378,// Prideful Gladiator's Dreadplate Helm
	103379,// Prideful Gladiator's Dreadplate Legguards
	103380,// Prideful Gladiator's Dreadplate Shoulders
	103439,// Prideful Gladiator's Scaled Chestpiece
	103440,// Prideful Gladiator's Scaled Gauntlets
	103441,// Prideful Gladiator's Scaled Helm
	103442,// Prideful Gladiator's Scaled Legguards
	103443,// Prideful Gladiator's Scaled Shoulders
	103444,// Prideful Gladiator's Clasp of Cruelty
	103445,// Prideful Gladiator's Clasp of Meditation
	103446,// Prideful Gladiator's Greaves of Alacrity
	103447,// Prideful Gladiator's Greaves of Meditation
	103448,// Prideful Gladiator's Bracers of Prowess
	103449,// Prideful Gladiator's Bracers of Meditation
	103450,// Prideful Gladiator's Ornamented Chestguard
	103451,// Prideful Gladiator's Ornamented Gloves
	103452,// Prideful Gladiator's Ornamented Headcover
	103453,// Prideful Gladiator's Ornamented Legplates
	103454,// Prideful Gladiator's Ornamented Spaulders
	103455,// Prideful Gladiator's Girdle of Accuracy
	103456,// Prideful Gladiator's Girdle of Prowess
	103457,// Prideful Gladiator's Warboots of Cruelty
	103458,// Prideful Gladiator's Warboots of Alacrity
	103459,// Prideful Gladiator's Armplates of Proficiency
	103460,// Prideful Gladiator's Armplates of Alacrity
	103525,// Prideful Gladiator's Plate Chestpiece
	103526,// Prideful Gladiator's Plate Gauntlets
	103527,// Prideful Gladiator's Plate Helm
	103528,// Prideful Gladiator's Plate Legguards
	103529,// Prideful Gladiator's Plate Shoulders
	103733,// Corruption-Rotted Gauntlets
	103734,// Zoid's Molten Gauntlets
	103735,// Tar-Coated Gauntlets
	103736,// Chestplate of Congealed Corrosion
	103737,// Breastplate of Shamanic Mirrors
	103738,// Bubble-Burst Bracers
	103739,// Wall-Borer Bracers
	103740,// Bracers of Blind Hatred
	103741,// Bracers of Sordid Sleep
	103742,// Blood Rage Bracers
	103743,// Arcsmasher Bracers
	103744,// Treads of Unchained Hate
	103745,// Ominous Mogu Greatboots
	103746,// 5.4 Raid - Normal - Siege of Orgrimmar - Undetermined - Plate Str Tank Boot
	103747,// Pauldrons of Violent Eruption
	103748,// Krugruk's Rigid Shoulderplates
	103766,// Waterwalker Greatboots
	103767,// Borer Drill Boots
	103768,// Mogu Mindbender's Greaves
	103783,// Darkfallen Shoulderplates
	103784,// Spaulders of the Fallen Warchief
	103785,// Tusks of Mannoroth
	103787,// Poisonbinder Girth
	103788,// Demolisher's Reinforced Belt
	103790,// Shockstriker Gauntlets
	103791,// Gauntlets of Discarded Time
	103792,// Calixian Bladebreakers
	103817,// Grips of the Fallen Council
	103818,// Romy's Reliable Grips
	103819,// Gauntlets of Insane Calculations
	103820,// Gaze of Echoing Despair
	103821,// Crown of Boastful Words
	103839,// Rage-Blind Greathelm
	103840,// Greathelm of the Warchief
	103864,// Wristplates of Broken Doubt
	103865,// Smoldering Drakescale Bracers
	103866,// Shackles of Stinking Slime
	103878,// Greaves of Sublime Superiority
	103879,// Malkorok's Giant Stompers
	103880,// Wolf-Rider Spurs
	103892,// Thranok's Shattering Helm
	103893,// Helm of the Night Watchman
	103907,// Windfire Legplates
	103914,// Earthbreaker's Steaming Chestplate
	103915,// Icy Blood Chestplate
	103932,// Ashen Wall Girdle
	103933,// Untarnishable Greatbelt
	103943,// Shoulderplates of Gushing Geysers
	103944,// Mantle of Looming Darkness
	103954,// Legplates of Willful Doom
	103957,// Terrorguard Chestplate
	103958,// Chestplate of Fallen Passion
	103965,// Plate Belt of the War-Healer
	103966,// Greatbelt of Living Waters
	104311,// Legplates of Unthinking Strife
	104415,// Bubble-Burst Bracers
	104416,// Chestplate of Congealed Corrosion
	104417,// Corruption-Rotted Gauntlets
	104418,// Treads of Unchained Hate
	104419,// Bracers of Sordid Sleep
	104420,// Pauldrons of Violent Eruption
	104431,// Greatbelt of Living Waters
	104432,// Waterwalker Greatboots
	104437,// Poisonbinder Girth
	104438,// Darkfallen Shoulderplates
	104439,// Shockstriker Gauntlets
	104452,// Grips of the Fallen Council
	104453,// Gaze of Echoing Despair
	104460,// Bracers of Blind Hatred
	104461,// Rage-Blind Greathelm
	104475,// Wristplates of Broken Doubt
	104481,// Crown of Boastful Words
	104482,// Greaves of Sublime Superiority
	104492,// Thranok's Shattering Helm
	104493,// Arcsmasher Bracers
	104494,// Krugruk's Rigid Shoulderplates
	104506,// Smoldering Drakescale Bracers
	104507,// Windfire Legplates
	104513,// Demolisher's Reinforced Belt
	104514,// Wall-Borer Bracers
	104515,// Tar-Coated Gauntlets
	104516,// Earthbreaker's Steaming Chestplate
	104529,// Borer Drill Boots
	104535,// Wolf-Rider Spurs
	104536,// Breastplate of Shamanic Mirrors
	104537,// Ashen Wall Girdle
	104549,// Shackles of Stinking Slime
	104550,// Shoulderplates of Gushing Geysers
	104567,// Malkorok's Giant Stompers
	104568,// Blood Rage Bracers
	104569,// Legplates of Willful Doom
	104583,// Terrorguard Chestplate
	104590,// Helm of the Night Watchman
	104591,// Untarnishable Greatbelt
	104592,// Ominous Mogu Greatboots
	104603,// Plate Belt of the War-Healer
	104604,// Mogu Mindbender's Greaves
	104612,// Icy Blood Chestplate
	104623,// Calixian Bladebreakers
	104635,// Gauntlets of Insane Calculations
	104644,// Legplates of Unthinking Strife
	104645,// Spaulders of the Fallen Warchief
	104646,// Tusks of Mannoroth
	104647,// Greathelm of the Warchief
	104658,// Chestplate of Fallen Passion
	104659,// Mantle of Looming Darkness
	104664,// Bubble-Burst Bracers
	104665,// Chestplate of Congealed Corrosion
	104666,// Corruption-Rotted Gauntlets
	104667,// Treads of Unchained Hate
	104668,// Bracers of Sordid Sleep
	104669,// Pauldrons of Violent Eruption
	104680,// Greatbelt of Living Waters
	104681,// Waterwalker Greatboots
	104686,// Poisonbinder Girth
	104687,// Darkfallen Shoulderplates
	104688,// Shockstriker Gauntlets
	104701,// Grips of the Fallen Council
	104702,// Gaze of Echoing Despair
	104709,// Bracers of Blind Hatred
	104710,// Rage-Blind Greathelm
	104724,// Wristplates of Broken Doubt
	104730,// Crown of Boastful Words
	104731,// Greaves of Sublime Superiority
	104741,// Thranok's Shattering Helm
	104742,// Arcsmasher Bracers
	104743,// Krugruk's Rigid Shoulderplates
	104755,// Smoldering Drakescale Bracers
	104756,// Windfire Legplates
	104762,// Demolisher's Reinforced Belt
	104763,// Wall-Borer Bracers
	104764,// Tar-Coated Gauntlets
	104765,// Earthbreaker's Steaming Chestplate
	104778,// Borer Drill Boots
	104784,// Wolf-Rider Spurs
	104785,// Breastplate of Shamanic Mirrors
	104786,// Ashen Wall Girdle
	104798,// Shackles of Stinking Slime
	104799,// Shoulderplates of Gushing Geysers
	104816,// Malkorok's Giant Stompers
	104817,// Blood Rage Bracers
	104818,// Legplates of Willful Doom
	104832,// Terrorguard Chestplate
	104839,// Helm of the Night Watchman
	104840,// Untarnishable Greatbelt
	104841,// Ominous Mogu Greatboots
	104852,// Plate Belt of the War-Healer
	104853,// Mogu Mindbender's Greaves
	104861,// Icy Blood Chestplate
	104872,// Calixian Bladebreakers
	104884,// Gauntlets of Insane Calculations
	104893,// Legplates of Unthinking Strife
	104894,// Spaulders of the Fallen Warchief
	104896,// Greathelm of the Warchief
	104907,// Chestplate of Fallen Passion
	104908,// Mantle of Looming Darkness
	104913,// Bubble-Burst Bracers
	104914,// Chestplate of Congealed Corrosion
	104915,// Corruption-Rotted Gauntlets
	104916,// Treads of Unchained Hate
	104917,// Bracers of Sordid Sleep
	104918,// Pauldrons of Violent Eruption
	104929,// Greatbelt of Living Waters
	104930,// Waterwalker Greatboots
	104935,// Poisonbinder Girth
	104936,// Darkfallen Shoulderplates
	104937,// Shockstriker Gauntlets
	104950,// Grips of the Fallen Council
	104951,// Gaze of Echoing Despair
	104958,// Bracers of Blind Hatred
	104959,// Rage-Blind Greathelm
	104973,// Wristplates of Broken Doubt
	104979,// Crown of Boastful Words
	104980,// Greaves of Sublime Superiority
	104990,// Thranok's Shattering Helm
	104991,// Arcsmasher Bracers
	104992,// Krugruk's Rigid Shoulderplates
	105004,// Smoldering Drakescale Bracers
	105005,// Windfire Legplates
	105011,// Demolisher's Reinforced Belt
	105012,// Wall-Borer Bracers
	105013,// Tar-Coated Gauntlets
	105014,// Earthbreaker's Steaming Chestplate
	105027,// Borer Drill Boots
	105033,// Wolf-Rider Spurs
	105034,// Breastplate of Shamanic Mirrors
	105035,// Ashen Wall Girdle
	105047,// Shackles of Stinking Slime
	105048,// Shoulderplates of Gushing Geysers
	105065,// Malkorok's Giant Stompers
	105066,// Blood Rage Bracers
	105067,// Legplates of Willful Doom
	105081,// Terrorguard Chestplate
	105088,// Helm of the Night Watchman
	105089,// Untarnishable Greatbelt
	105090,// Ominous Mogu Greatboots
	105101,// Plate Belt of the War-Healer
	105102,// Mogu Mindbender's Greaves
	105110,// Icy Blood Chestplate
	105121,// Calixian Bladebreakers
	105133,// Gauntlets of Insane Calculations
	105142,// Legplates of Unthinking Strife
	105143,// Spaulders of the Fallen Warchief
	105145,// Greathelm of the Warchief
	105156,// Chestplate of Fallen Passion
	105157,// Mantle of Looming Darkness
	105162,// Bubble-Burst Bracers
	105163,// Chestplate of Congealed Corrosion
	105164,// Corruption-Rotted Gauntlets
	105165,// Treads of Unchained Hate
	105166,// Bracers of Sordid Sleep
	105167,// Pauldrons of Violent Eruption
	105178,// Greatbelt of Living Waters
	105179,// Waterwalker Greatboots
	105184,// Poisonbinder Girth
	105185,// Darkfallen Shoulderplates
	105186,// Shockstriker Gauntlets
	105199,// Grips of the Fallen Council
	105200,// Gaze of Echoing Despair
	105207,// Bracers of Blind Hatred
	105208,// Rage-Blind Greathelm
	105222,// Wristplates of Broken Doubt
	105228,// Crown of Boastful Words
	105229,// Greaves of Sublime Superiority
	105239,// Thranok's Shattering Helm
	105240,// Arcsmasher Bracers
	105241,// Krugruk's Rigid Shoulderplates
	105253,// Smoldering Drakescale Bracers
	105254,// Windfire Legplates
	105260,// Demolisher's Reinforced Belt
	105261,// Wall-Borer Bracers
	105262,// Tar-Coated Gauntlets
	105263,// Earthbreaker's Steaming Chestplate
	105276,// Borer Drill Boots
	105282,// Wolf-Rider Spurs
	105283,// Breastplate of Shamanic Mirrors
	105284,// Ashen Wall Girdle
	105296,// Shackles of Stinking Slime
	105297,// Shoulderplates of Gushing Geysers
	105314,// Malkorok's Giant Stompers
	105315,// Blood Rage Bracers
	105316,// Legplates of Willful Doom
	105330,// Terrorguard Chestplate
	105337,// Helm of the Night Watchman
	105338,// Untarnishable Greatbelt
	105339,// Ominous Mogu Greatboots
	105350,// Plate Belt of the War-Healer
	105351,// Mogu Mindbender's Greaves
	105359,// Icy Blood Chestplate
	105370,// Calixian Bladebreakers
	105382,// Gauntlets of Insane Calculations
	105391,// Legplates of Unthinking Strife
	105392,// Spaulders of the Fallen Warchief
	105393,// Tusks of Mannoroth
	105394,// Greathelm of the Warchief
	105405,// Chestplate of Fallen Passion
	105406,// Mantle of Looming Darkness
	105411,// Bubble-Burst Bracers
	105412,// Chestplate of Congealed Corrosion
	105413,// Corruption-Rotted Gauntlets
	105414,// Treads of Unchained Hate
	105415,// Bracers of Sordid Sleep
	105416,// Pauldrons of Violent Eruption
	105427,// Greatbelt of Living Waters
	105428,// Waterwalker Greatboots
	105433,// Poisonbinder Girth
	105434,// Darkfallen Shoulderplates
	105435,// Shockstriker Gauntlets
	105448,// Grips of the Fallen Council
	105449,// Gaze of Echoing Despair
	105456,// Bracers of Blind Hatred
	105457,// Rage-Blind Greathelm
	105471,// Wristplates of Broken Doubt
	105477,// Crown of Boastful Words
	105478,// Greaves of Sublime Superiority
	105488,// Thranok's Shattering Helm
	105489,// Arcsmasher Bracers
	105490,// Krugruk's Rigid Shoulderplates
	105502,// Smoldering Drakescale Bracers
	105503,// Windfire Legplates
	105509,// Demolisher's Reinforced Belt
	105510,// Wall-Borer Bracers
	105511,// Tar-Coated Gauntlets
	105512,// Earthbreaker's Steaming Chestplate
	105525,// Borer Drill Boots
	105531,// Wolf-Rider Spurs
	105532,// Breastplate of Shamanic Mirrors
	105533,// Ashen Wall Girdle
	105545,// Shackles of Stinking Slime
	105546,// Shoulderplates of Gushing Geysers
	105563,// Malkorok's Giant Stompers
	105564,// Blood Rage Bracers
	105565,// Legplates of Willful Doom
	105579,// Terrorguard Chestplate
	105586,// Helm of the Night Watchman
	105587,// Untarnishable Greatbelt
	105588,// Ominous Mogu Greatboots
	105599,// Plate Belt of the War-Healer
	105600,// Mogu Mindbender's Greaves
	105608,// Icy Blood Chestplate
	105619,// Calixian Bladebreakers
	105631,// Gauntlets of Insane Calculations
	105640,// Legplates of Unthinking Strife
	105641,// Spaulders of the Fallen Warchief
	105642,// Tusks of Mannoroth
	105643,// Greathelm of the Warchief
	105654,// Chestplate of Fallen Passion
	105655,// Mantle of Looming Darkness
	105756,// Poxleitner's Leggings of Lights
	105759,// Magmaplates of Jian Wu Xi Feng
	105761,// Partik's Purified Legplates
	105767,// Hoodrych's Bloodied Chestplate
	105769,// Omegal's Crushing Carapace
	105775,// Gleaming Eye Spellplate
	105776,// Belt of the Burning Soul
	105777,// Remnar's Ruinous Girdle
	105783,// Greatbelt of the Crendor
	105785,// Vanguard's Burly Bracers
	105786,// Ordosian Cultist's Bracers
	105791,// Bracers of Unquestioning Belief
	105794,// Starry Spaulders of Durability
	105796,// Rossi's Rosin-Soaked Shoulderplates
	105802,// Yaungol Deathcult Shoulderguards
	105804,// Aladya's Spiritfire Greathelm
	105805,// Dominik's Casque of Raging Flame
	105807,// Magdalena's Murderous Crown
	105821,// Romy's Reliable Grips
	105822,// Zoid's Molten Gauntlets
	105823,// Gauntlets of Discarded Time
	105835,// Romy's Reliable Grips
	105836,// Zoid's Molten Gauntlets
	105837,// Gauntlets of Discarded Time
	105849,// Romy's Reliable Grips
	105850,// Zoid's Molten Gauntlets
	105851,// Gauntlets of Discarded Time
	106145,// Frostwolf Stalwart Bracers
	106146,// Frostwolf Stalwart Cap
	106147,// Frostwolf Stalwart Chestpiece
	106148,// Frostwolf Stalwart Gauntlets
	106149,// Frostwolf Stalwart Girdle
	106150,// Karabor Honor Guard Helm
	106151,// Karabor Honor Guard Legguards
	106152,// Frostwolf Stalwart Shoulders
	106153,// Karabor Honor Guard Chestplate
	106154,// Frostwolf Stalwart Warboots
	106155,// Karabor Honor Guard Wristwraps
	106285,// Acid Scarred Plate Belt
	106292,// Acid Scarred Plate Bracers
	106294,// Acid Scarred Plate Pants
	106298,// Acid Scarred Plate Shoulderpads
	106300,// Acid Scarred Plate Boots
	106302,// Acid Scarred Plate Gloves
	106305,// Acid Scarred Plate Helmet
	106310,// Acid Scarred Plate Chestpiece
	106326,// Punctured Plate Belt
	106329,// Punctured Plate Bracers
	106336,// Punctured Plate Pauldrons
	106343,// Punctured Plate Gloves
	106346,// Punctured Plate Helmet
	106348,// Punctured Plate Pants
	106350,// Punctured Plate Chestpiece
	106353,// Punctured Plate Boots
	106390,// Bladespire Breastplate
	106391,// Bladespire Gauntlets
	106392,// Bladespire Girdle
	106393,// Bladespire Helm
	106394,// Bladespire Legplates
	106395,// Bladespire Pauldrons
	106396,// Bladespire Sabatons
	106398,// Bladespire Vambraces
	106423,// Rimeplate Breastplate
	106424,// Rimeplate Gauntlets
	106425,// Rimeplate Girdle
	106426,// Rimeplate Helm
	106427,// Rimeplate Legplates
	106428,// Rimeplate Pauldrons
	106429,// Rimeplate Sabatons
	106431,// Rimeplate Vambraces
	106456,// Rockspine Breastplate
	106457,// Rockspine Gauntlets
	106458,// Rockspine Girdle
	106459,// Rockspine Helm
	106460,// Rockspine Legplates
	106461,// Rockspine Pauldrons
	106462,// Rockspine Sabatons
	106464,// Rockspine Vambraces
	106489,// Shardback Breastplate
	106490,// Shardback Gauntlets
	106491,// Shardback Girdle
	106492,// Shardback Helm
	106493,// Shardback Legplates
	106494,// Shardback Pauldrons
	106495,// Shardback Sabatons
	106497,// Shardback Vambraces
	106522,// Gul'rok Breastplate
	106523,// Gul'rok Gauntlets
	106524,// Gul'rok Girdle
	106525,// Gul'rok Helm
	106526,// Gul'rok Legplates
	106527,// Gul'rok Pauldrons
	106528,// Gul'rok Sabatons
	106530,// Gul'rok Vambraces
	106555,// Stonebreaker Breastplate
	106556,// Stonebreaker Gauntlets
	106557,// Stonebreaker Girdle
	106558,// Stonebreaker Helm
	106559,// Stonebreaker Legplates
	106560,// Stonebreaker Pauldrons
	106561,// Stonebreaker Sabatons
	106563,// Stonebreaker Vambraces
	106588,// Sharptusk Breastplate
	106589,// Sharptusk Gauntlets
	106590,// Sharptusk Girdle
	106591,// Sharptusk Helm
	106592,// Sharptusk Legplates
	106593,// Sharptusk Pauldrons
	106594,// Sharptusk Sabatons
	106596,// Sharptusk Vambraces
	106621,// Ravenskar Breastplate
	106622,// Ravenskar Gauntlets
	106623,// Ravenskar Girdle
	106624,// Ravenskar Helm
	106625,// Ravenskar Legplates
	106626,// Ravenskar Pauldrons
	106627,// Ravenskar Sabatons
	106629,// Ravenskar Vambraces
	106654,// Talon Guard Breastplate
	106655,// Talon Guard Gauntlets
	106656,// Talon Guard Girdle
	106657,// Talon Guard Helm
	106658,// Talon Guard Legplates
	106659,// Talon Guard Pauldrons
	106660,// Talon Guard Sabatons
	106662,// Talon Guard Vambraces
	106687,// Ironfist Breastplate
	106688,// Ironfist Gauntlets
	106689,// Ironfist Girdle
	106690,// Ironfist Helm
	106691,// Ironfist Legplates
	106692,// Ironfist Pauldrons
	106693,// Ironfist Sabatons
	106695,// Ironfist Vambraces
	106720,// Stonecrag Breastplate
	106721,// Stonecrag Gauntlets
	106722,// Stonecrag Girdle
	106723,// Stonecrag Helm
	106724,// Stonecrag Legplates
	106725,// Stonecrag Pauldrons
	106726,// Stonecrag Sabatons
	106728,// Stonecrag Vambraces
	107309,// Karabor Honor Guard Warboots
	107310,// Karabor Honor Guard Gauntlets
	107311,// Frostwolf Stalwart Legguards
	107312,// Karabor Honor Guard Shoulders
	107313,// Karabor Honor Guard Girdle
	107550,// Unbreakable Greatbelt
	107968,// Draenic Steel Chestplate
	107969,// Draenic Steel Warboots
	107970,// Draenic Steel Gauntlets
	107971,// Draenic Steel Helm
	107972,// Draenic Steel Legguards
	107973,// Draenic Steel Shoulders
	107974,// Draenic Steel Girdle
	107975,// Draenic Steel Wristwraps
	107976,// Draenic Steel Chestplate
	107977,// Draenic Steel Warboots
	107978,// Draenic Steel Gauntlets
	107979,// Draenic Steel Helm
	107980,// Draenic Steel Legguards
	107981,// Draenic Steel Shoulders
	107982,// Draenic Steel Girdle
	107983,// Draenic Steel Wristwraps
	107984,// UNUSED
	107985,// Draenic Steel Warboots
	107986,// Draenic Steel Gauntlets
	107987,// Draenic Steel Helm
	107988,// Draenic Steel Legguards
	107989,// Draenic Steel Shoulders
	107990,// Draenic Steel Girdle
	107991,// Draenic Steel Wristwraps
	107992,// Draenic Steel Chestplate
	107993,// Draenic Steel Warboots
	107994,// Draenic Steel Gauntlets
	107995,// Draenic Steel Helm
	107996,// Draenic Steel Legguards
	107997,// Draenic Steel Shoulders
	107998,// Draenic Steel Girdle
	107999,// Draenic Steel Wristwraps
	108000,// Draenic Steel Chestplate
	108001,// Draenic Steel Warboots
	108002,// Draenic Steel Gauntlets
	108003,// Draenic Steel Helm
	108004,// Draenic Steel Legguards
	108005,// Draenic Steel Shoulders
	108006,// Draenic Steel Girdle
	108007,// Draenic Steel Wristwraps
	108008,// Draenic Steel Chestplate
	108009,// Draenic Steel Warboots
	108010,// Draenic Steel Gauntlets
	108011,// Draenic Steel Helm
	108012,// Draenic Steel Legguards
	108013,// Draenic Steel Shoulders
	108014,// Draenic Steel Girdle
	108015,// Draenic Steel Wristwraps
	108016,// Draenic Steel Chestplate
	108017,// Draenic Steel Warboots
	108018,// Draenic Steel Gauntlets
	108019,// Draenic Steel Helm
	108020,// Draenic Steel Legguards
	108021,// Draenic Steel Shoulders
	108022,// Draenic Steel Girdle
	108023,// Draenic Steel Wristwraps
	108024,// Draenic Steel Chestplate
	108025,// Draenic Steel Warboots
	108026,// Draenic Steel Gauntlets
	108027,// Draenic Steel Helm
	108028,// Draenic Steel Legguards
	108029,// Draenic Steel Shoulders
	108030,// Draenic Steel Girdle
	108031,// Draenic Steel Wristwraps
	108032,// Draenic Steel Chestplate
	108033,// Draenic Steel Warboots
	108034,// Draenic Steel Gauntlets
	108035,// Draenic Steel Helm
	108036,// Draenic Steel Legguards
	108037,// Draenic Steel Shoulders
	108038,// Draenic Steel Girdle
	108039,// Draenic Steel Wristwraps
	108078,// Hardened Draenic Steel Chestplate
	108079,// Hardened Draenic Steel Warboots
	108080,// Hardened Draenic Steel Gauntlets
	108081,// Hardened Draenic Steel Helm
	108082,// Hardened Draenic Steel Legguards
	108083,// Hardened Draenic Steel Shoulders
	108084,// Hardened Draenic Steel Girdle
	108085,// Hardened Draenic Steel Wristwraps
	108086,// UNUSED
	108087,// Hardened Draenic Steel Warboots
	108088,// Hardened Draenic Steel Gauntlets
	108089,// Hardened Draenic Steel Helm
	108090,// Hardened Draenic Steel Legguards
	108091,// Hardened Draenic Steel Shoulders
	108092,// Hardened Draenic Steel Girdle
	108093,// Hardened Draenic Steel Wristwraps
	108094,// Hardened Draenic Steel Chestplate
	108095,// Hardened Draenic Steel Warboots
	108096,// Hardened Draenic Steel Gauntlets
	108097,// Hardened Draenic Steel Helm
	108098,// Hardened Draenic Steel Legguards
	108099,// Hardened Draenic Steel Shoulders
	108100,// Hardened Draenic Steel Girdle
	108101,// Hardened Draenic Steel Wristwraps
	108102,// Hardened Draenic Steel Chestplate
	108103,// Hardened Draenic Steel Warboots
	108104,// Hardened Draenic Steel Gauntlets
	108105,// Hardened Draenic Steel Helm
	108106,// Hardened Draenic Steel Legguards
	108107,// Hardened Draenic Steel Shoulders
	108108,// Hardened Draenic Steel Girdle
	108109,// Hardened Draenic Steel Wristwraps
	108110,// Hardened Draenic Steel Chestplate
	108111,// Hardened Draenic Steel Warboots
	108112,// Hardened Draenic Steel Gauntlets
	108113,// Hardened Draenic Steel Helm
	108114,// Hardened Draenic Steel Legguards
	108115,// Hardened Draenic Steel Shoulders
	108116,// Hardened Draenic Steel Girdle
	108117,// Hardened Draenic Steel Wristwraps
	108118,// Hardened Draenic Steel Chestplate
	108119,// Hardened Draenic Steel Warboots
	108120,// Hardened Draenic Steel Gauntlets
	108121,// Hardened Draenic Steel Helm
	108122,// Hardened Draenic Steel Legguards
	108123,// Hardened Draenic Steel Shoulders
	108124,// Hardened Draenic Steel Girdle
	108125,// Hardened Draenic Steel Wristwraps
	108126,// Hardened Draenic Steel Chestplate
	108127,// Hardened Draenic Steel Warboots
	108128,// Hardened Draenic Steel Gauntlets
	108129,// Hardened Draenic Steel Helm
	108130,// Hardened Draenic Steel Legguards
	108131,// Hardened Draenic Steel Shoulders
	108132,// Hardened Draenic Steel Girdle
	108133,// Hardened Draenic Steel Wristwraps
	108134,// Hardened Draenic Steel Chestplate
	108135,// Hardened Draenic Steel Warboots
	108136,// Hardened Draenic Steel Gauntlets
	108137,// Hardened Draenic Steel Helm
	108138,// Hardened Draenic Steel Legguards
	108139,// Hardened Draenic Steel Shoulders
	108140,// Hardened Draenic Steel Girdle
	108141,// Hardened Draenic Steel Wristwraps
	108162,// Peerless Draenic Steel Chestplate
	108163,// Peerless Draenic Steel Warboots
	108164,// Peerless Draenic Steel Gauntlets
	108165,// Peerless Draenic Steel Helm
	108166,// Peerless Draenic Steel Legguards
	108167,// Peerless Draenic Steel Shoulders
	108168,// Peerless Draenic Steel Girdle
	108169,// Peerless Draenic Steel Wristwraps
	108170,// UNUSED
	108171,// UNUSED
	108172,// UNUSED
	108173,// UNUSED
	108174,// UNUSED
	108175,// UNUSED
	108176,// UNUSED
	108177,// UNUSED
	108178,// Peerless Draenic Steel Chestplate
	108179,// Peerless Draenic Steel Warboots
	108180,// Peerless Draenic Steel Gauntlets
	108181,// Peerless Draenic Steel Helm
	108182,// Peerless Draenic Steel Legguards
	108183,// Peerless Draenic Steel Shoulders
	108184,// Peerless Draenic Steel Girdle
	108185,// Peerless Draenic Steel Wristwraps
	108186,// Peerless Draenic Steel Chestplate
	108187,// Peerless Draenic Steel Warboots
	108188,// Peerless Draenic Steel Gauntlets
	108189,// Peerless Draenic Steel Helm
	108190,// Peerless Draenic Steel Legguards
	108191,// Peerless Draenic Steel Shoulders
	108192,// Peerless Draenic Steel Girdle
	108193,// Peerless Draenic Steel Wristwraps
	108194,// Peerless Draenic Steel Chestplate
	108195,// Peerless Draenic Steel Warboots
	108196,// Peerless Draenic Steel Gauntlets
	108197,// Peerless Draenic Steel Helm
	108198,// Peerless Draenic Steel Legguards
	108199,// Peerless Draenic Steel Shoulders
	108200,// Peerless Draenic Steel Girdle
	108201,// Peerless Draenic Steel Wristwraps
	108202,// Peerless Draenic Steel Chestplate
	108203,// Peerless Draenic Steel Warboots
	108204,// Peerless Draenic Steel Gauntlets
	108205,// Peerless Draenic Steel Helm
	108206,// Peerless Draenic Steel Legguards
	108207,// Peerless Draenic Steel Shoulders
	108208,// Peerless Draenic Steel Girdle
	108209,// Peerless Draenic Steel Wristwraps
	108210,// Peerless Draenic Steel Chestplate
	108211,// Peerless Draenic Steel Warboots
	108212,// Peerless Draenic Steel Gauntlets
	108213,// Peerless Draenic Steel Helm
	108214,// Peerless Draenic Steel Legguards
	108215,// Peerless Draenic Steel Shoulders
	108216,// Peerless Draenic Steel Girdle
	108217,// Peerless Draenic Steel Wristwraps
	108218,// Peerless Draenic Steel Chestplate
	108219,// Peerless Draenic Steel Warboots
	108220,// Peerless Draenic Steel Gauntlets
	108221,// Peerless Draenic Steel Helm
	108222,// Peerless Draenic Steel Legguards
	108223,// Peerless Draenic Steel Shoulders
	108224,// Peerless Draenic Steel Girdle
	108225,// Peerless Draenic Steel Wristwraps
	109174,// Razorguard Mechshades
	109793,// Incarnadine Greaves
	109794,// Verdant Plate Treads
	109795,// Goldsteel Sabatons
	109802,// Gutcrusher Stompers
	109803,// Rivet-Sealed Treads
	109818,// Incarnadine Legplates
	109819,// Verdant Plate Legguards
	109820,// Goldsteel Legplates
	109821,// Gutcrusher Legplates
	109822,// Rivet-Sealed Legplates
	109837,// Incarnadine Girdle
	109838,// Verdant Plate Belt
	109839,// Goldsteel Belt
	109840,// Gutcrusher Greatbelt
	109841,// Rivet-Sealed Waistplate
	109856,// Incarnadine Gauntlets
	109857,// Verdant Plate Grips
	109858,// Goldsteel Gloves
	109859,// Gutcrusher Gauntlets
	109860,// Rivet-Sealed Crushers
	109876,// Incarnadine Bracers
	109877,// Verdant Plate Wristguards
	109878,// Goldsteel Bindings
	109879,// Gutcrusher Bracers
	109880,// Rivet-Sealed Bracers
	109892,// Incarnadine Breastplate
	109893,// Verdant Plate Chest
	109894,// Goldsteel Chestguard
	109895,// Gutcrusher Chestplate
	109896,// Rivet-Sealed Breastplate
	109943,// Incarnadine Shoulderguard
	109944,// Verdant Plate Spaulders
	109945,// Goldsteel Shouldercaps
	109946,// Gutcrusher Shoulderplates
	109947,// Rivet-Sealed Shoulderplates
	109985,// Incarnadine Greathelm
	109986,// Verdant Plate Crown
	109987,// Goldsteel Greathelm
	109988,// Gutcrusher Coronet
	109989,// Rivet-Sealed Casque
	111102,// Primal Gladiator's Dreadplate Chestpiece
	111103,// Primal Gladiator's Dreadplate Gauntlets
	111104,// Primal Gladiator's Dreadplate Helm
	111105,// Primal Gladiator's Dreadplate Legguards
	111106,// Primal Gladiator's Dreadplate Shoulders
	111169,// Primal Gladiator's Scaled Chestpiece
	111170,// Primal Gladiator's Scaled Gauntlets
	111171,// Primal Gladiator's Scaled Helm
	111172,// Primal Gladiator's Scaled Legguards
	111173,// Primal Gladiator's Scaled Shoulders
	111174,// Primal Gladiator's Girdle of Cruelty
	111175,// Primal Gladiator's Girdle of Prowess
	111176,// Primal Gladiator's Girdle of Victory
	111177,// Primal Gladiator's Warboots of Cruelty
	111178,// Primal Gladiator's Warboots of Prowess
	111179,// Primal Gladiator's Warboots of Victory
	111180,// Primal Gladiator's Armplates of Cruelty
	111181,// Primal Gladiator's Armplates of Prowess
	111182,// Primal Gladiator's Armplates of Victory
	111209,// Primal Gladiator's Plate Breastplate
	111210,// Primal Gladiator's Plate Gloves
	111211,// Primal Gladiator's Plate Helmet
	111212,// Primal Gladiator's Legplates
	111213,// Primal Gladiator's Shoulderplates
	111214,// Primal Gladiator's Plate Chestguard
	111215,// Primal Gladiator's Plate Grips
	111216,// Primal Gladiator's Plate Visor
	111217,// Primal Gladiator's Plate Leggings
	111218,// Primal Gladiator's Plate Pauldrons
	111239,// Primal Gladiator's Plate Chestpiece
	111240,// Primal Gladiator's Plate Gauntlets
	111241,// Primal Gladiator's Plate Helm
	111242,// Primal Gladiator's Plate Legguards
	111243,// Primal Gladiator's Plate Shoulders
	111534,// The Bone Crawler's Carapace
	112346,// Ice-Encrusted Plate Headguard
	112347,// Ice-Encrusted Plate Helm
	112354,// Ice-Encrusted Plate Legguards
	112356,// Ice-Encrusted Plate Leggings
	112361,// Ice-Encrusted Plate Belt
	112362,// Ice-Encrusted Plate Girdle
	112416,// Bubble-Burst Bracers
	112417,// Chestplate of Congealed Corrosion
	112418,// Corruption-Rotted Gauntlets
	112419,// Treads of Unchained Hate
	112420,// Bracers of Sordid Sleep
	112421,// Pauldrons of Violent Eruption
	112431,// Hollowheart Legguards
	112437,// Mismatched Plate Gauntlets
	112443,// Slavebreaker Chestguard
	112447,// Greatbelt of Living Waters
	112448,// Waterwalker Greatboots
	112469,// Jungle-Chopper Wristplates
	112481,// Darkfallen Shoulderplates
	112482,// Poisonbinder Girth
	112483,// Shockstriker Gauntlets
	112495,// Grips of the Fallen Council
	112496,// Gaze of Echoing Despair
	112509,// Sha'tari Keeper Chestplate
	112512,// Sha'tari Keeper Warboots
	112517,// Sha'tari Keeper Handguards
	112520,// Sha'tari Keeper Helm
	112524,// Sha'tari Keeper Legguards
	112530,// Sha'tari Keeper Shoulders
	112533,// Sha'tari Keeper Girdle
	112538,// Sha'tari Keeper Wristwraps
	112545,// Bracers of Blind Hatred
	112552,// Rage-Blind Greathelm
	112565,// Wristplates of Broken Doubt
	112588,// Foundry-Fired Plate Chestplate
	112591,// Foundry-Fired Plate Warboots
	112596,// Foundry-Fired Plate Gauntlets
	112599,// Foundry-Fired Plate Helm
	112603,// Foundry-Fired Plate Legguards
	112609,// Foundry-Fired Plate Shoulders
	112612,// Foundry-Fired Plate Girdle
	112617,// Foundry-Fired Plate Wristwraps
	112659,// Blackrock Infantry Warboots
	112663,// Voidgazer Headguard
	112669,// Quarrier's Shoulderplates
	112702,// Crown of Boastful Words
	112704,// Arcsmasher Bracers
	112705,// Krugruk's Rigid Shoulderplates
	112713,// Thranok's Shattering Helm
	112727,// Smoldering Drakescale Bracers
	112728,// Windfire Legplates
	112732,// Tar-Coated Gauntlets
	112733,// Wall-Borer Bracers
	112735,// Demolisher's Reinforced Belt
	112741,// Earthbreaker's Steaming Chestplate
	112752,// Borer Drill Boots
	112755,// Breastplate of Shamanic Mirrors
	112757,// Wolf-Rider Spurs
	112763,// Ashen Wall Girdle
	112773,// Shackles of Stinking Slime
	112774,// Shoulderplates of Gushing Geysers
	112793,// Blood Rage Bracers
	112796,// Malkorok's Giant Stompers
	112807,// Legplates of Willful Doom
	112811,// Wallbuilder Gauntlets
	112823,// Terrorguard Chestplate
	112826,// Ominous Mogu Greatboots
	112832,// Helm of the Night Watchman
	112834,// Untarnishable Greatbelt
	112846,// Plate Belt of the War-Healer
	112847,// Mogu Mindbender's Greaves
	112856,// Icy Blood Chestplate
	112882,// Calixian Bladebreakers
	112915,// Gauntlets of Insane Calculations
	112928,// Greathelm of the Warchief
	112933,// Legplates of Unthinking Strife
	112934,// Spaulders of the Fallen Warchief
	112935,// Tusks of Mannoroth
	112944,// Chestplate of Fallen Passion
	112945,// Mantle of Looming Darkness
	112953,// Greaves of Sublime Superiority
	113034,// Sha'tari Keeper Gauntlets
	113151,// Lightly Perforated Chestplate
	113219,// Romy's Reliable Grips
	113228,// Gauntlets of Discarded Time
	113229,// Zoid's Molten Gauntlets
	113234,// Karabor Honor Guard Wristwraps
	113240,// Blademoon Plate Legguards
	113251,// Grom'gar Plate Stompers
	113600,// Casque of the Iron Bomber
	113632,// Gauntlets of the Heavy Hand
	113633,// Entrail Squishers
	113648,// Legplates of Fractured Crystal
	113659,// Fleshchewer Greatbelt
	113660,// Mosscrusher Sabatons
	113691,// Ice-Encrusted Gloves
	113692,// Ice-Encrusted Gauntlets
	113695,// Emberspark Plate Helm
	113696,// Emberspark Plate Headguard
	113701,// Emberspark Plate Bracers
	113702,// Emberspark Plate Wristguards
	113707,// Emberspark Plate Leggings
	113708,// Emberspark Plate Legguards
	113713,// Emberspark Chestplate
	113714,// Emberspark Plate Chestguard
	113719,// Emberspark Plate Gloves
	113720,// Emberspark Plate Gauntlets
	113728,// Kyparite Helm
	113729,// Kyparite Headguard
	113737,// Kyparite Chestplate
	113738,// Kyparite Chestguard
	113743,// Kyparite Gloves
	113744,// Kyparite Gauntlets
	113749,// Kyparite Pauldrons
	113750,// Kyparite Shoulderguards
	113780,// Emberspark Plate Boots
	113781,// Emberspark Plate Sabatons
	113782,// Kyparite Boots
	113783,// Kyparite Stompers
	113784,// Kyparite Belt
	113785,// Kyparite Girdle
	113805,// Blackrock Girth
	113806,// Blackrock Greaves
	113807,// Blackrock Chestplate
	113808,// Blackrock Gauntlets
	113809,// Blackrock Greathelm
	113810,// Blackrock Legplates
	113811,// Blackrock Pauldrons
	113812,// Blackrock Wristguards
	113831,// Chestplate of Arcane Volatility
	113844,// Bracers of Mirrored Flame
	113855,// Uncrushable Shoulderplates
	113871,// Bracers of Martial Perfection
	113881,// Chestplate of Rolling Fury
	113884,// Unstable Slag Shoulderplates
	113894,// Lava-Dipped Greathelm
	113896,// Fleshmelter Bracers
	113906,// Gauntlets of Dramatic Blows
	113910,// Hardened Greathelm
	113921,// Firestorm Legplates
	113925,// Flamefury Gauntlets
	113936,// Sabatons of Fractal Earth
	113950,// Ironcrusher's Collar
	113961,// Iron Bellow Sabatons
	113976,// Uktar's Belt of Chiming Rings
	113977,// Bloodsoaked Heart Protector
	113990,// Overdriven Spaulders
	114230,// Truesteel Helm
	114231,// Truesteel Pauldrons
	114232,// Truesteel Breastplate
	114233,// Truesteel Waistguard
	114234,// Truesteel Greaves
	114235,// Truesteel Boots
	114236,// Truesteel Armguards
	114237,// Truesteel Gauntlets
	114250,// Ruby Plate Bracers
	114253,// Ruby Plate Breastplate
	114258,// Ruby Plate Greaves
	114262,// Ruby Plate Gauntlets
	114266,// Ruby Plate Greathelm
	114270,// Ruby Plate Legplates
	114274,// Ruby Plate Shoulderguard
	114278,// Ruby Plate Girdle
	114313,// Salt-Scorched Bracers
	114316,// Salt-Scorched Breastplate
	114321,// Salt-Scorched Greaves
	114325,// Salt-Scorched Gauntlets
	114329,// Salt-Scorched Greathelm
	114333,// Salt-Scorched Legplates
	114337,// Salt-Scorched Shoulderguard
	114341,// Salt-Scorched Girdle
	114374,// Bracers of Grievous Storms
	114377,// Breastplate of Grievous Storms
	114382,// Greaves of Grievous Storms
	114386,// Gauntlets of Grievous Storms
	114390,// Greathelm of Grievous Storms
	114394,// Legplates of Grievous Storms
	114398,// Shoulderguard of Grievous Storms
	114402,// Girdle of Grievous Storms
	114435,// Bracers of Vaulted Skies
	114438,// Breastplate of Vaulted Skies
	114443,// Greaves of Vaulted Skies
	114447,// Gauntlets of Vaulted Skies
	114451,// Greathelm of Vaulted Skies
	114455,// Legplates of Vaulted Skies
	114459,// Shoulderguard of Vaulted Skies
	114463,// Girdle of Vaulted Skies
	114496,// Crazed Bomber's Bracers
	114499,// Crazed Bomber's Breastplate
	114504,// Crazed Bomber's Greaves
	114508,// Crazed Bomber's Gauntlets
	114512,// Crazed Bomber's Greathelm
	114516,// Crazed Bomber's Legplates
	114520,// Crazed Bomber's Shoulderguard
	114524,// Crazed Bomber's Girdle
	114557,// Crimson Carapace Bracers
	114560,// Crimson Carapace Breastplate
	114565,// Crimson Carapace Greaves
	114569,// Crimson Carapace Gauntlets
	114573,// Crimson Carapace Greathelm
	114577,// Crimson Carapace Legplates
	114581,// Crimson Carapace Shoulderguard
	114585,// Crimson Carapace Girdle
	114680,// Plainsthunder Chestplate
	114683,// Plainsthunder Warboots
	114688,// Plainsthunder Gauntlets
	114691,// Plainsthunder Helm
	114695,// Plainsthunder Legguards
	114701,// Plainsthunder Shoulders
	114704,// Plainsthunder Girdle
	114709,// Plainsthunder Wristwraps
	114712,// Cragplate Chestplate
	114715,// Cragplate Warboots
	114720,// Cragplate Gauntlets
	114723,// Cragplate Helm
	114727,// Cragplate Legguards
	114733,// Cragplate Shoulders
	114736,// Cragplate Girdle
	114741,// Cragplate Wristwraps
	115049,// Primal Combatant's Dreadplate Chestpiece
	115050,// Primal Combatant's Dreadplate Gauntlets
	115051,// Primal Combatant's Dreadplate Helm
	115052,// Primal Combatant's Dreadplate Legguards
	115053,// Primal Combatant's Dreadplate Shoulders
	115106,// Primal Combatant's Scaled Chestpiece
	115107,// Primal Combatant's Scaled Gauntlets
	115108,// Primal Combatant's Scaled Helm
	115109,// Primal Combatant's Scaled Legguards
	115110,// Primal Combatant's Scaled Shoulders
	115111,// Primal Combatant's Girdle of Cruelty
	115112,// Primal Combatant's Girdle of Prowess
	115113,// Primal Combatant's Warboots of Cruelty
	115114,// Primal Combatant's Warboots of Prowess
	115115,// Primal Combatant's Armplates of Cruelty
	115116,// Primal Combatant's Armplates of Prowess
	115141,// Primal Combatant's Plate Breastplate
	115142,// Primal Combatant's Plate Gloves
	115143,// Primal Combatant's Plate Helmet
	115144,// Primal Combatant's Legplates
	115145,// Primal Combatant's Shoulderplates
	115166,// Primal Combatant's Plate Chestpiece
	115167,// Primal Combatant's Plate Gauntlets
	115168,// Primal Combatant's Plate Helm
	115169,// Primal Combatant's Plate Legguards
	115170,// Primal Combatant's Plate Shoulders
	115197,// Primal Aspirant's Dreadplate Chestpiece
	115198,// Primal Aspirant's Dreadplate Gauntlets
	115199,// Primal Aspirant's Dreadplate Helm
	115200,// Primal Aspirant's Dreadplate Legguards
	115201,// Primal Aspirant's Dreadplate Shoulders
	115233,// Primal Aspirant's Scaled Chestpiece
	115234,// Primal Aspirant's Scaled Gauntlets
	115235,// Primal Aspirant's Scaled Helm
	115236,// Primal Aspirant's Scaled Legguards
	115237,// Primal Aspirant's Scaled Shoulders
	115238,// Primal Aspirant's Girdle of Cruelty
	115239,// Primal Aspirant's Warboots of Cruelty
	115240,// Primal Aspirant's Armplates of Cruelty
	115263,// Primal Aspirant's Plate Chestpiece
	115264,// Primal Aspirant's Plate Gauntlets
	115265,// Primal Aspirant's Plate Helm
	115266,// Primal Aspirant's Plate Legguards
	115267,// Primal Aspirant's Plate Shoulders
	115377,// Crystal-Plated Legplates
	115381,// Crystal-Plated Greatbelt
	115390,// Exceptional Crystal-Plated Gauntlets
	115399,// Flawless Crystal-Plated Greathelm
	115403,// Flawless Crystal-Plated Bracers
	115407,// Tehax's Penetrating Visage
	115411,// Ozymandias' Burdensome Treads
	115415,// Spaulders of Primal Ferocity
	115428,// Gauntlets of Impenetrability
	115432,// Waistplate of Bladed Force
	115436,// Phoenixfire Legplates
	115535,// Ogreskull Boneplate Greaves
	115536,// Ogreskull Boneplate Pauldrons
	115537,// Ogreskull Boneplate Breastplate
	115538,// Ogreskull Boneplate Gauntlets
	115539,// Ogreskull Boneplate Greathelm
	115565,// Pauldrons of Guiding Light
	115566,// Battleplate of Guiding Light
	115567,// Gauntlets of Guiding Light
	115568,// Helmet of Guiding Light
	115569,// Legplates of Guiding Light
	115580,// Blackhand's Legguards
	115581,// Blackhand's Shoulderguards
	115582,// Blackhand's Chestguard
	115583,// Blackhand's Handguards
	115584,// Blackhand's Faceguard
	115629,// Primal Gladiator's Dreadplate Chestpiece
	115630,// Primal Gladiator's Dreadplate Gauntlets
	115631,// Primal Gladiator's Dreadplate Helm
	115632,// Primal Gladiator's Dreadplate Legguards
	115633,// Primal Gladiator's Dreadplate Shoulders
	115696,// Primal Gladiator's Scaled Chestpiece
	115697,// Primal Gladiator's Scaled Gauntlets
	115698,// Primal Gladiator's Scaled Helm
	115699,// Primal Gladiator's Scaled Legguards
	115700,// Primal Gladiator's Scaled Shoulders
	115701,// Primal Gladiator's Girdle of Cruelty
	115702,// Primal Gladiator's Girdle of Prowess
	115703,// Primal Gladiator's Girdle of Victory
	115704,// Primal Gladiator's Warboots of Cruelty
	115705,// Primal Gladiator's Warboots of Prowess
	115706,// Primal Gladiator's Warboots of Victory
	115707,// Primal Gladiator's Armplates of Cruelty
	115708,// Primal Gladiator's Armplates of Prowess
	115709,// Primal Gladiator's Armplates of Victory
	115736,// Primal Gladiator's Plate Breastplate
	115737,// Primal Gladiator's Plate Gloves
	115738,// Primal Gladiator's Plate Helmet
	115739,// Primal Gladiator's Legplates
	115740,// Primal Gladiator's Shoulderplates
	115741,// Primal Gladiator's Plate Chestguard
	115742,// Primal Gladiator's Plate Grips
	115743,// Primal Gladiator's Plate Visor
	115744,// Primal Gladiator's Plate Leggings
	115745,// Primal Gladiator's Plate Pauldrons
	115766,// Primal Gladiator's Plate Chestpiece
	115767,// Primal Gladiator's Plate Gauntlets
	115768,// Primal Gladiator's Plate Helm
	115769,// Primal Gladiator's Plate Legguards
	115770,// Primal Gladiator's Plate Shoulders
	115837,// Primal Gladiator's Dreadplate Chestpiece
	115838,// Primal Gladiator's Dreadplate Gauntlets
	115839,// Primal Gladiator's Dreadplate Helm
	115840,// Primal Gladiator's Dreadplate Legguards
	115841,// Primal Gladiator's Dreadplate Shoulders
	115892,// Primal Gladiator's Scaled Chestpiece
	115893,// Primal Gladiator's Scaled Gauntlets
	115894,// Primal Gladiator's Scaled Helm
	115895,// Primal Gladiator's Scaled Legguards
	115896,// Primal Gladiator's Scaled Shoulders
	115897,// Primal Gladiator's Scaled Clasp
	115898,// Primal Gladiator's Ornamented Clasp
	115899,// Primal Gladiator's Ornamented Greaves
	115900,// Primal Gladiator's Scaled Greaves
	115901,// Primal Gladiator's Ornamented Chestguard
	115902,// Primal Gladiator's Ornamented Gloves
	115903,// Primal Gladiator's Ornamented Headcover
	115904,// Primal Gladiator's Ornamented Legplates
	115905,// Primal Gladiator's Ornamented Spaulders
	115906,// Primal Gladiator's Dreadplate Girdle
	115907,// Primal Gladiator's Plate Girdle
	115908,// Primal Gladiator's Plate Warboots
	115909,// Primal Gladiator's Dreadplate Warboots
	115961,// Primal Gladiator's Plate Chestpiece
	115962,// Primal Gladiator's Plate Gauntlets
	115963,// Primal Gladiator's Plate Helm
	115964,// Primal Gladiator's Plate Legguards
	115965,// Primal Gladiator's Plate Shoulders
	116230,// Ogre-Eater Treads
	116231,// Legplates of Arcanic Absorbtion
	116232,// 6.0 LFR - Highmaul Raid - UNUSED - Plate Versatile Belt 1
	116233,// Grips of Burning Infusion
	116234,// Bracers of Cursed Cries
	116235,// Chestplate of Destructive Resonance
	116236,// Iron Bomb Spaulders
	116237,// Crown of the Crags
	116238,// Heel Protectors
	116239,// Gunnery Sergeant's Legplates
	116240,// Waistplate of Caustic Spittle
	116241,// Gauntlets of Electrocution
	116242,// Gruul's Smallest Shackles
	116243,// Chestplate of Runed Earth
	116244,// Spaulders of the Iron Crucible
	116245,// Maw of Charring Breath
	116250,// Impaler's Greatboots
	116251,// Ironshatter Legplates
	116252,// Waistplate of Obliteration
	116253,// Lava-Crushing Grips
	116254,// Reverberating Bracers
	116255,// Heartsmasher Chestplate
	116256,// Elbow Drop Spaulders
	116257,// Acid-Munched Greathelm
	116262,// Waistplate of Soothed Beasts
	116263,// Vortex Plate Helm
	116425,// Smoldering Greaves
	116426,// Smoldering Helm
	116427,// Smoldering Breastplate
	116805,// Blug'thol's Bloody Bracers
	116930,// Exceptional Crystal-Plated Legplates
	116934,// Flawless Crystal-Plated Legplates
	116938,// Exceptional Crystal-Plated Greatbelt
	116942,// Flawless Crystal-Plated Greatbelt
	116946,// Crystal-Plated Gauntlets
	116950,// Flawless Crystal-Plated Gauntlets
	116956,// Crystal-Plated Greathelm
	116960,// Exceptional Crystal-Plated Greathelm
	116964,// Exceptional Crystal-Plated Bracers
	116968,// Crystal-Plated Bracers
	117020,// Heart-Lesion Breastplate
	117021,// Heart-Lesion Sabatons
	117022,// Heart-Lesion Gauntlets
	117023,// Heart-Lesion Helm
	117024,// Heart-Lesion Legplates
	117025,// Heart-Lesion Pauldrons
	117026,// Heart-Lesion Girdle
	117027,// Heart-Lesion Vambraces
	117035,// Heart-Lesion Chestguard
	117037,// Heart-Lesion Greaves
	117038,// Heart-Lesion Handguards
	117039,// Heart-Lesion Faceguard
	117040,// Heart-Lesion Legguards
	117046,// Heart-Lesion Shoulderguards
	117047,// Heart-Lesion Waistband
	117048,// Heart-Lesion Armguards
	117163,// Sunsoul Battleplate
	117164,// Sunsoul Sabatons
	117165,// Sunsoul Gauntlets
	117166,// Sunsoul Helm
	117167,// Sunsoul Legplates
	117168,// Sunsoul Pauldrons
	117169,// Sunsoul Girdle
	117170,// Sunsoul Vambraces
	117171,// Sunsoul Breastplate
	117173,// Sunsoul Boots
	117174,// Sunsoul Gloves
	117175,// Sunsoul Headpiece
	117176,// Sunsoul Leggings
	117182,// Sunsoul Spaulders
	117183,// Sunsoul Belt
	117184,// Sunsoul Armplates
	117196,// Sunsoul Chestguard
	117198,// Sunsoul Greaves
	117199,// Sunsoul Handguards
	117200,// Sunsoul Faceguard
	117201,// Sunsoul Legguards
	117207,// Sunsoul Shoulderguards
	117208,// Sunsoul Waistband
	117209,// Sunsoul Armguards
	117322,// Oathsworn Breastplate
	117323,// Oathsworn Sabatons
	117324,// Oathsworn Gauntlets
	117325,// Oathsworn Helm
	117326,// Oathsworn Legplates
	117327,// Oathsworn Pauldrons
	117328,// Oathsworn Girdle
	117329,// Oathsworn Vambraces
	117339,// Oathsworn Chestguard
	117341,// Oathsworn Greaves
	117342,// Oathsworn Handguards
	117343,// Oathsworn Faceguard
	117344,// Oathsworn Legguards
	117350,// Oathsworn Shoulderguards
	117351,// Oathsworn Waistband
	117352,// Oathsworn Armguards
	117355,// The Horseman's Horrific Hood
	117499,// Lunarlight Plate Stompers
	117501,// Grimfrost Plate Chestguard
	117511,// Agurak Wristplates
	117516,// Frostwolf Stalwart Legplates
	117609,// Tournament Gladiator's Dreadplate Chestpiece
	117610,// Tournament Gladiator's Dreadplate Gauntlets
	117611,// Tournament Gladiator's Dreadplate Helm
	117612,// Tournament Gladiator's Dreadplate Legguards
	117613,// Tournament Gladiator's Dreadplate Shoulders
	117676,// Tournament Gladiator's Scaled Chestpiece
	117677,// Tournament Gladiator's Scaled Gauntlets
	117678,// Tournament Gladiator's Scaled Helm
	117679,// Tournament Gladiator's Scaled Legguards
	117680,// Tournament Gladiator's Scaled Shoulders
	117681,// Tournament Gladiator's Girdle of Cruelty
	117682,// Tournament Gladiator's Girdle of Prowess
	117683,// Tournament Gladiator's Girdle of Victory
	117684,// Tournament Gladiator's Warboots of Cruelty
	117685,// Tournament Gladiator's Warboots of Prowess
	117686,// Tournament Gladiator's Warboots of Victory
	117687,// Tournament Gladiator's Armplates of Cruelty
	117688,// Tournament Gladiator's Armplates of Prowess
	117689,// Tournament Gladiator's Armplates of Victory
	117716,// Tournament Gladiator's Plate Breastplate
	117717,// Tournament Gladiator's Plate Gloves
	117718,// Tournament Gladiator's Plate Helmet
	117719,// Tournament Gladiator's Legplates
	117720,// Tournament Gladiator's Shoulderplates
	117721,// Tournament Gladiator's Plate Chestguard
	117722,// Tournament Gladiator's Plate Grips
	117723,// Tournament Gladiator's Plate Visor
	117724,// Tournament Gladiator's Plate Leggings
	117725,// Tournament Gladiator's Plate Pauldrons
	117746,// Tournament Gladiator's Plate Chestpiece
	117747,// Tournament Gladiator's Plate Gauntlets
	117748,// Tournament Gladiator's Plate Helm
	117749,// Tournament Gladiator's Plate Legguards
	117750,// Tournament Gladiator's Plate Shoulders
	117810,// Tournament Gladiator's Dreadplate Chestpiece
	117811,// Tournament Gladiator's Dreadplate Gauntlets
	117812,// Tournament Gladiator's Dreadplate Helm
	117813,// Tournament Gladiator's Dreadplate Legguards
	117814,// Tournament Gladiator's Dreadplate Shoulders
	117877,// Tournament Gladiator's Scaled Chestpiece
	117878,// Tournament Gladiator's Scaled Gauntlets
	117879,// Tournament Gladiator's Scaled Helm
	117880,// Tournament Gladiator's Scaled Legguards
	117881,// Tournament Gladiator's Scaled Shoulders
	117882,// Tournament Gladiator's Girdle of Cruelty
	117883,// Tournament Gladiator's Girdle of Prowess
	117884,// Tournament Gladiator's Girdle of Victory
	117885,// Tournament Gladiator's Warboots of Cruelty
	117886,// Tournament Gladiator's Warboots of Prowess
	117887,// Tournament Gladiator's Warboots of Victory
	117888,// Tournament Gladiator's Armplates of Cruelty
	117889,// Tournament Gladiator's Armplates of Prowess
	117890,// Tournament Gladiator's Armplates of Victory
	117917,// Tournament Gladiator's Plate Breastplate
	117918,// Tournament Gladiator's Plate Gloves
	117919,// Tournament Gladiator's Plate Helmet
	117920,// Tournament Gladiator's Legplates
	117921,// Tournament Gladiator's Shoulderplates
	117922,// Tournament Gladiator's Plate Chestguard
	117923,// Tournament Gladiator's Plate Grips
	117924,// Tournament Gladiator's Plate Visor
	117925,// Tournament Gladiator's Plate Leggings
	117926,// Tournament Gladiator's Plate Pauldrons
	117947,// Tournament Gladiator's Plate Chestpiece
	117948,// Tournament Gladiator's Plate Gauntlets
	117949,// Tournament Gladiator's Plate Helm
	117950,// Tournament Gladiator's Plate Legguards
	117951,// Tournament Gladiator's Plate Shoulders
	117985,// RENAME Lightly Perforated Chestplate
	117998,// RENAME Karabor Honor Guard Wristwraps
	118003,// RENAME Blademoon Plate Legguards
	118031,// Foundry-Fired Plate Handguards
	118034,// Foundry-Fired Plate Waistguard
	118071,// "Fireproof" Venture Co. Blastplate
	118075,// Fungal Resistant Plate Boots
	118087,// "Super Sterilized" Blastguard Legplates
	118139,// Plainsthunder Waistguard
	118144,// Plainsthunder Handguards
	118148,// Plainsthunder Bracers
	118154,// Grounded Headguard
	118688,// Carapace Shell Shoulders
	118750,// Reiver Gauntlets
	118753,// Plate of Shamanic Fury
	118853,// Iron Beltguard of Fuufuu
	118854,// Zor's Taboo Treads
	118855,// Chyler's Charming Chestguard
	118856,// Cydil's Coiled Grasp
	118857,// Casque of Defiance
	118858,// Fobbly's Fabulous Legplates
	118859,// Mantle of Moriccalas
	118860,// Bolt-Bound Bracers
	118888,// Ashelia's Adorned Waistguard
	118892,// Botani-Barbed Pauldrons
	118896,// Helmet of Vile Indignation
	118940,// Crown of Desolation
	118946,// Bouldercrush Breastplate
	118947,// Bouldercrush Gauntlets
	118948,// Bouldercrush Girdle
	118949,// Bouldercrush Helm
	118950,// Bouldercrush Legplates
	118951,// Bouldercrush Pauldrons
	118952,// Bouldercrush Sabatons
	118954,// Bouldercrush Vambraces
	119227,// Morgo's Unstoppable Ramming Helm
	119331,// Bracers of Visceral Force
	119337,// Ripswallow Plate Belt
	119341,// Doomslag Greatboots
	119380,// Brutag's Iron Toe Boots
	119381,// Grash's Fireproof Handguards
	119382,// Hershak's Heavy Legguards
	119383,// Shoulderplates of the Vigilant
	119384,// Krud's Girthy Girdle
	119385,// Vanguard's Linebreaking Bracer
	119422,// Breastplate of the Sha'tari Defense
	119423,// Boots of the Sha'tari Defense
	119424,// Legplates of the Sha'tari Defense
	119425,// Belt of the Sha'tari Defense
	119426,// Gauntlets of the Sha'tari Defense
	119427,// Shoulderguards of the Sha'tari Defense
	119428,// Greathelm of the Sha'tari Defense
	119429,// Bracers of the Sha'tari Defense
	119470,// Heart-Lesion Breastplate
	119471,// Heart-Lesion Sabatons
	119472,// Heart-Lesion Gauntlets
	119473,// Heart-Lesion Helm
	119474,// Heart-Lesion Legplates
	119475,// Heart-Lesion Pauldrons
	119476,// Heart-Lesion Girdle
	119477,// Heart-Lesion Vambraces
	119485,// Heart-Lesion Chestguard
	119487,// Heart-Lesion Greaves
	119488,// Heart-Lesion Handguards
	119489,// Heart-Lesion Faceguard
	119490,// Heart-Lesion Legguards
	119496,// Heart-Lesion Shoulderguards
	119497,// Heart-Lesion Waistband
	119498,// Heart-Lesion Armguards
	119613,// Sunsoul Battleplate
	119614,// Sunsoul Sabatons
	119615,// Sunsoul Gauntlets
	119616,// Sunsoul Helm
	119617,// Sunsoul Legplates
	119618,// Sunsoul Pauldrons
	119619,// Sunsoul Girdle
	119620,// Sunsoul Vambraces
	119621,// Sunsoul Breastplate
	119623,// Sunsoul Boots
	119624,// Sunsoul Gloves
	119625,// Sunsoul Headpiece
	119626,// Sunsoul Leggings
	119632,// Sunsoul Spaulders
	119633,// Sunsoul Belt
	119634,// Sunsoul Armplates
	119646,// Sunsoul Chestguard
	119648,// Sunsoul Greaves
	119649,// Sunsoul Handguards
	119650,// Sunsoul Faceguard
	119651,// Sunsoul Legguards
	119657,// Sunsoul Shoulderguards
	119658,// Sunsoul Waistband
	119659,// Sunsoul Armguards
	119772,// Oathsworn Breastplate
	119773,// Oathsworn Sabatons
	119774,// Oathsworn Gauntlets
	119775,// Oathsworn Helm
	119776,// Oathsworn Legplates
	119777,// Oathsworn Pauldrons
	119778,// Oathsworn Girdle
	119779,// Oathsworn Vambraces
	119789,// Oathsworn Chestguard
	119791,// Oathsworn Greaves
	119792,// Oathsworn Handguards
	119793,// Oathsworn Faceguard
	119794,// Oathsworn Legguards
	119800,// Oathsworn Shoulderguards
	119801,// Oathsworn Waistband
	119802,// Oathsworn Armguards
	119839,// Primal Combatant's Dreadplate Chestpiece
	119840,// Primal Combatant's Dreadplate Gauntlets
	119841,// Primal Combatant's Dreadplate Helm
	119842,// Primal Combatant's Dreadplate Legguards
	119843,// Primal Combatant's Dreadplate Shoulders
	119889,// Primal Combatant's Scaled Chestpiece
	119890,// Primal Combatant's Scaled Gauntlets
	119891,// Primal Combatant's Scaled Helm
	119892,// Primal Combatant's Scaled Legguards
	119893,// Primal Combatant's Scaled Shoulders
	119894,// Primal Combatant's Girdle of Cruelty
	119895,// Primal Combatant's Girdle of Prowess
	119896,// Primal Combatant's Warboots of Cruelty
	119897,// Primal Combatant's Warboots of Prowess
	119898,// Primal Combatant's Armplates of Cruelty
	119899,// Primal Combatant's Armplates of Prowess
	119918,// Primal Combatant's Plate Breastplate
	119919,// Primal Combatant's Plate Gloves
	119920,// Primal Combatant's Plate Helmet
	119921,// Primal Combatant's Legplates
	119922,// Primal Combatant's Shoulderplates
	119943,// Primal Combatant's Plate Chestpiece
	119944,// Primal Combatant's Plate Gauntlets
	119945,// Primal Combatant's Plate Helm
	119946,// Primal Combatant's Plate Legguards
	119947,// Primal Combatant's Plate Shoulders
	119974,// Primal Aspirant's Dreadplate Chestpiece
	119975,// Primal Aspirant's Dreadplate Gauntlets
	119976,// Primal Aspirant's Dreadplate Helm
	119977,// Primal Aspirant's Dreadplate Legguards
	119978,// Primal Aspirant's Dreadplate Shoulders
	120010,// Primal Aspirant's Scaled Chestpiece
	120011,// Primal Aspirant's Scaled Gauntlets
	120012,// Primal Aspirant's Scaled Helm
	120013,// Primal Aspirant's Scaled Legguards
	120014,// Primal Aspirant's Scaled Shoulders
	120015,// Primal Aspirant's Girdle of Cruelty
	120016,// Primal Aspirant's Warboots of Cruelty
	120017,// Primal Aspirant's Armplates of Cruelty
	120040,// Primal Aspirant's Plate Chestpiece
	120041,// Primal Aspirant's Plate Gauntlets
	120042,// Primal Aspirant's Plate Helm
	120043,// Primal Aspirant's Plate Legguards
	120044,// Primal Aspirant's Plate Shoulders
	120090,// Falling Leaf Breastplate
	120114,// Wing-Forged Greatboots
	120391,// Blacksteel Legplates
	120392,// Blacksteel Gauntlets
	120393,// Blacksteel Chestplate
	120394,// Blacksteel Greatboots
	120395,// Blacksteel Shoulderplates
	120396,// Blacksteel Casque
	122166,// Blackrock Iron Stranglers
	122169,// Sooty Blackrock Iron Legplates
	122173,// Charred Blackrock Iron Waistplate
	122245,// Polished Helm of Valor
	122251,// Polished Legplates of Valor
	122263,// Burnished Helm of Might
	122264,// Burnished Legplates of Might
	122311,// Ethereal Crystal-Plated Greathelm
	122315,// Ethereal Crystal-Plated Bracers
	122319,// Ethereal Crystal-Plated Legplates
	122323,// Ethereal Crystal-Plated Greatbelt
	122327,// Ethereal Crystal-Plated Gauntlets
	122355,// Polished Spaulders of Valor
	122372,// Strengthened Stockade Pauldrons
	122373,// Pristine Lightforge Spaulders
	122381,// Polished Breastplate of Valor
	122387,// Burnished Breastplate of Might
	122388,// Burnished Pauldrons of Might
	123984,// Greathelm of the Unbreakable
	123990,// Greaves of the Shatterer
	123996,// Gauntlets of the Righteous
	124000,// Justice Bearer's Pauldrons
	124011,// Spaulders of Slaughter
	124027,// Boots of the Righteous Path
	124315,// Stamped Felsteel Chestplate
	124316,// Chestguard of Ill Fate
	124317,// Demongaze Chestplate
	124318,// Cuirass of the Ceaseless Vigil
	124319,// Breastplate of Iron Wrath
	124320,// Shell-Resistant Stompers
	124321,// Stompers of Brazen Terror
	124322,// Treads of the Defiler
	124323,// Cruel Hope Crushers
	124324,// Flamebelcher's Insulated Mitts
	124325,// Crimson Throatgrabbers
	124326,// Gauntlets of Derision
	124327,// Demongaze Gauntlets
	124328,// Gauntlets of the Ceaseless Vigil
	124329,// Gauntlets of Iron Wrath
	124330,// Helm of Precognition
	124331,// Casque of Foul Concentration
	124332,// Demongaze Helm
	124333,// Helm of the Ceaseless Vigil
	124334,// Faceguard of Iron Wrath
	124335,// Blastproof Legguards
	124336,// Acid-Etched Legplates
	124337,// Legguards of Grievous Consonances
	124338,// Demongaze Legplates
	124339,// Greaves of the Ceaseless Vigil
	124340,// Legplates of Iron Wrath
	124341,// Fel-Inscribed Shoulderplates
	124342,// Soulgorged Pauldrons
	124343,// Doomcrier's Shoulderplates
	124344,// Demongaze Pauldrons
	124345,// Shoulderplates of the Ceaseless Vigil
	124346,// Pauldrons of Iron Wrath
	124347,// Girdle of Savage Resolve
	124348,// Ravenous Girdle
	124349,// Annihilan's Waistplate
	124350,// Girdle of Demonic Wrath
	124351,// Hot-Rolled Iron Bracers
	124352,// Wristplate of the Wretched
	124353,// Breach-Scarred Wristplates
	124566,// Felbane Bracers
	124569,// Felbane Breastplate
	124574,// Felbane Greaves
	124578,// Felbane Gauntlets
	124582,// Felbane Greathelm
	124586,// Felbane Legplates
	124590,// Felbane Shoulderguard
	124594,// Felbane Girdle
	124711,// Wild Gladiator's Dreadplate Chestpiece
	124712,// Wild Gladiator's Dreadplate Gauntlets
	124713,// Wild Gladiator's Dreadplate Helm
	124714,// Wild Gladiator's Dreadplate Legguards
	124715,// Wild Gladiator's Dreadplate Shoulders
	124798,// Wild Gladiator's Scaled Chestpiece
	124799,// Wild Gladiator's Scaled Gauntlets
	124800,// Wild Gladiator's Scaled Helm
	124801,// Wild Gladiator's Scaled Legguards
	124802,// Wild Gladiator's Scaled Shoulders
	124803,// Wild Gladiator's Girdle of Cruelty
	124804,// Wild Gladiator's Girdle of Prowess
	124805,// Wild Gladiator's Girdle of Victory
	124806,// Wild Gladiator's Warboots of Cruelty
	124807,// Wild Gladiator's Warboots of Prowess
	124808,// Wild Gladiator's Warboots of Victory
	124809,// Wild Gladiator's Armplates of Cruelty
	124810,// Wild Gladiator's Armplates of Prowess
	124811,// Wild Gladiator's Armplates of Victory
	124812,// Wild Gladiator's Plate Breastplate
	124813,// Wild Gladiator's Plate Gloves
	124814,// Wild Gladiator's Plate Helmet
	124815,// Wild Gladiator's Legplates
	124816,// Wild Gladiator's Shoulderplates
	124817,// Wild Gladiator's Plate Chestguard
	124818,// Wild Gladiator's Plate Grips
	124819,// Wild Gladiator's Plate Visor
	124820,// Wild Gladiator's Plate Leggings
	124821,// Wild Gladiator's Plate Pauldrons
	124880,// Wild Gladiator's Plate Chestpiece
	124881,// Wild Gladiator's Plate Gauntlets
	124882,// Wild Gladiator's Plate Helm
	124883,// Wild Gladiator's Plate Legguards
	124884,// Wild Gladiator's Plate Shoulders
	124913,// Wild Combatant's Dreadplate Chestpiece
	124914,// Wild Combatant's Dreadplate Gauntlets
	124915,// Wild Combatant's Dreadplate Helm
	124916,// Wild Combatant's Dreadplate Legguards
	124917,// Wild Combatant's Dreadplate Shoulders
	124984,// Wild Combatant's Scaled Chestpiece
	124985,// Wild Combatant's Scaled Gauntlets
	124986,// Wild Combatant's Scaled Helm
	124987,// Wild Combatant's Scaled Legguards
	124988,// Wild Combatant's Scaled Shoulders
	124989,// Wild Combatant's Girdle of Cruelty
	124990,// Wild Combatant's Girdle of Prowess
	124991,// Wild Combatant's Warboots of Cruelty
	124992,// Wild Combatant's Warboots of Prowess
	124993,// Wild Combatant's Armplates of Cruelty
	124994,// Wild Combatant's Armplates of Prowess
	124995,// Wild Combatant's Plate Breastplate
	124996,// Wild Combatant's Plate Gloves
	124997,// Wild Combatant's Plate Helmet
	124998,// Wild Combatant's Legplates
	124999,// Wild Combatant's Shoulderplates
	125058,// Wild Combatant's Plate Chestpiece
	125059,// Wild Combatant's Plate Gauntlets
	125060,// Wild Combatant's Plate Helm
	125061,// Wild Combatant's Plate Legguards
	125062,// Wild Combatant's Plate Shoulders
	125070,// Wild Aspirant's Dreadplate Chestpiece
	125071,// Wild Aspirant's Dreadplate Gauntlets
	125072,// Wild Aspirant's Dreadplate Helm
	125073,// Wild Aspirant's Dreadplate Legguards
	125074,// Wild Aspirant's Dreadplate Shoulders
	125109,// Wild Aspirant's Scaled Chestpiece
	125110,// Wild Aspirant's Scaled Gauntlets
	125111,// Wild Aspirant's Scaled Helm
	125112,// Wild Aspirant's Scaled Legguards
	125113,// Wild Aspirant's Scaled Shoulders
	125114,// Wild Aspirant's Girdle of Cruelty
	125115,// Wild Aspirant's Warboots of Cruelty
	125116,// Wild Aspirant's Armplates of Cruelty
	125149,// Wild Aspirant's Plate Chestpiece
	125150,// Wild Aspirant's Plate Gauntlets
	125151,// Wild Aspirant's Plate Helm
	125152,// Wild Aspirant's Plate Legguards
	125153,// Wild Aspirant's Plate Shoulders
	125190,// Wild Gladiator's Dreadplate Chestpiece
	125191,// Wild Gladiator's Dreadplate Gauntlets
	125192,// Wild Gladiator's Dreadplate Helm
	125193,// Wild Gladiator's Dreadplate Legguards
	125194,// Wild Gladiator's Dreadplate Shoulders
	125277,// Wild Gladiator's Scaled Chestpiece
	125278,// Wild Gladiator's Scaled Gauntlets
	125279,// Wild Gladiator's Scaled Helm
	125280,// Wild Gladiator's Scaled Legguards
	125281,// Wild Gladiator's Scaled Shoulders
	125282,// Wild Gladiator's Girdle of Cruelty
	125283,// Wild Gladiator's Girdle of Prowess
	125284,// Wild Gladiator's Girdle of Victory
	125285,// Wild Gladiator's Warboots of Cruelty
	125286,// Wild Gladiator's Warboots of Prowess
	125287,// Wild Gladiator's Warboots of Victory
	125288,// Wild Gladiator's Armplates of Cruelty
	125289,// Wild Gladiator's Armplates of Prowess
	125290,// Wild Gladiator's Armplates of Victory
	125291,// Wild Gladiator's Plate Breastplate
	125292,// Wild Gladiator's Plate Gloves
	125293,// Wild Gladiator's Plate Helmet
	125294,// Wild Gladiator's Legplates
	125295,// Wild Gladiator's Shoulderplates
	125296,// Wild Gladiator's Plate Chestguard
	125297,// Wild Gladiator's Plate Grips
	125298,// Wild Gladiator's Plate Visor
	125299,// Wild Gladiator's Plate Leggings
	125300,// Wild Gladiator's Plate Pauldrons
	125357,// Wild Gladiator's Plate Chestpiece
	125358,// Wild Gladiator's Plate Gauntlets
	125359,// Wild Gladiator's Plate Helm
	125360,// Wild Gladiator's Plate Legguards
	125361,// Wild Gladiator's Plate Shoulders
	125390,// Wild Combatant's Dreadplate Chestpiece
	125391,// Wild Combatant's Dreadplate Gauntlets
	125392,// Wild Combatant's Dreadplate Helm
	125393,// Wild Combatant's Dreadplate Legguards
	125394,// Wild Combatant's Dreadplate Shoulders
	125461,// Wild Combatant's Scaled Chestpiece
	125462,// Wild Combatant's Scaled Gauntlets
	125463,// Wild Combatant's Scaled Helm
	125464,// Wild Combatant's Scaled Legguards
	125465,// Wild Combatant's Scaled Shoulders
	125466,// Wild Combatant's Girdle of Cruelty
	125467,// Wild Combatant's Girdle of Prowess
	125468,// Wild Combatant's Warboots of Cruelty
	125469,// Wild Combatant's Warboots of Prowess
	125470,// Wild Combatant's Armplates of Cruelty
	125471,// Wild Combatant's Armplates of Prowess
	125472,// Wild Combatant's Plate Breastplate
	125473,// Wild Combatant's Plate Gloves
	125474,// Wild Combatant's Plate Helmet
	125475,// Wild Combatant's Legplates
	125476,// Wild Combatant's Shoulderplates
	125535,// Wild Combatant's Plate Chestpiece
	125536,// Wild Combatant's Plate Gauntlets
	125537,// Wild Combatant's Plate Helm
	125538,// Wild Combatant's Plate Legguards
	125539,// Wild Combatant's Plate Shoulders
	125547,// Wild Aspirant's Dreadplate Chestpiece
	125548,// Wild Aspirant's Dreadplate Gauntlets
	125549,// Wild Aspirant's Dreadplate Helm
	125550,// Wild Aspirant's Dreadplate Legguards
	125551,// Wild Aspirant's Dreadplate Shoulders
	125586,// Wild Aspirant's Scaled Chestpiece
	125587,// Wild Aspirant's Scaled Gauntlets
	125588,// Wild Aspirant's Scaled Helm
	125589,// Wild Aspirant's Scaled Legguards
	125590,// Wild Aspirant's Scaled Shoulders
	125591,// Wild Aspirant's Girdle of Cruelty
	125592,// Wild Aspirant's Warboots of Cruelty
	125593,// Wild Aspirant's Armplates of Cruelty
	125626,// Wild Aspirant's Plate Chestpiece
	125627,// Wild Aspirant's Plate Gauntlets
	125628,// Wild Aspirant's Plate Helm
	125629,// Wild Aspirant's Plate Legguards
	125630,// Wild Aspirant's Plate Shoulders
	125651,// Wild Gladiator's Dreadplate Chestpiece
	125652,// Wild Gladiator's Dreadplate Gauntlets
	125653,// Wild Gladiator's Dreadplate Helm
	125654,// Wild Gladiator's Dreadplate Legguards
	125655,// Wild Gladiator's Dreadplate Shoulders
	125706,// Wild Gladiator's Scaled Chestpiece
	125707,// Wild Gladiator's Scaled Gauntlets
	125708,// Wild Gladiator's Scaled Helm
	125709,// Wild Gladiator's Scaled Legguards
	125710,// Wild Gladiator's Scaled Shoulders
	125711,// Wild Gladiator's Scaled Clasp
	125712,// Wild Gladiator's Ornamented Clasp
	125713,// Wild Gladiator's Ornamented Greaves
	125714,// Wild Gladiator's Scaled Greaves
	125715,// Wild Gladiator's Ornamented Chestguard
	125716,// Wild Gladiator's Ornamented Gloves
	125717,// Wild Gladiator's Ornamented Headcover
	125718,// Wild Gladiator's Ornamented Legplates
	125719,// Wild Gladiator's Ornamented Spaulders
	125720,// Wild Gladiator's Dreadplate Girdle
	125721,// Wild Gladiator's Plate Girdle
	125722,// Wild Gladiator's Plate Warboots
	125723,// Wild Gladiator's Dreadplate Warboots
	125775,// Wild Gladiator's Plate Chestpiece
	125776,// Wild Gladiator's Plate Gauntlets
	125777,// Wild Gladiator's Plate Helm
	125778,// Wild Gladiator's Plate Legguards
	125779,// Wild Gladiator's Plate Shoulders
	125825,// Warmongering Gladiator's Dreadplate Chestpiece
	125826,// Warmongering Gladiator's Dreadplate Gauntlets
	125827,// Warmongering Gladiator's Dreadplate Helm
	125828,// Warmongering Gladiator's Dreadplate Legguards
	125829,// Warmongering Gladiator's Dreadplate Shoulders
	125912,// Warmongering Gladiator's Scaled Chestpiece
	125913,// Warmongering Gladiator's Scaled Gauntlets
	125914,// Warmongering Gladiator's Scaled Helm
	125915,// Warmongering Gladiator's Scaled Legguards
	125916,// Warmongering Gladiator's Scaled Shoulders
	125917,// Warmongering Gladiator's Girdle of Cruelty
	125918,// Warmongering Gladiator's Girdle of Prowess
	125919,// Warmongering Gladiator's Girdle of Victory
	125920,// Warmongering Gladiator's Warboots of Cruelty
	125921,// Warmongering Gladiator's Warboots of Prowess
	125922,// Warmongering Gladiator's Warboots of Victory
	125923,// Warmongering Gladiator's Armplates of Cruelty
	125924,// Warmongering Gladiator's Armplates of Prowess
	125925,// Warmongering Gladiator's Armplates of Victory
	125926,// Warmongering Gladiator's Plate Breastplate
	125927,// Warmongering Gladiator's Plate Gloves
	125928,// Warmongering Gladiator's Plate Helmet
	125929,// Warmongering Gladiator's Legplates
	125930,// Warmongering Gladiator's Shoulderplates
	125931,// Warmongering Gladiator's Plate Chestguard
	125932,// Warmongering Gladiator's Plate Grips
	125933,// Warmongering Gladiator's Plate Visor
	125934,// Warmongering Gladiator's Plate Leggings
	125935,// Warmongering Gladiator's Plate Pauldrons
	125994,// Warmongering Gladiator's Plate Chestpiece
	125995,// Warmongering Gladiator's Plate Gauntlets
	125996,// Warmongering Gladiator's Plate Helm
	125997,// Warmongering Gladiator's Plate Legguards
	125998,// Warmongering Gladiator's Plate Shoulders
	126027,// Warmongering Combatant's Dreadplate Chestpiece
	126028,// Warmongering Combatant's Dreadplate Gauntlets
	126029,// Warmongering Combatant's Dreadplate Helm
	126030,// Warmongering Combatant's Dreadplate Legguards
	126031,// Warmongering Combatant's Dreadplate Shoulders
	126098,// Warmongering Combatant's Scaled Chestpiece
	126099,// Warmongering Combatant's Scaled Gauntlets
	126100,// Warmongering Combatant's Scaled Helm
	126101,// Warmongering Combatant's Scaled Legguards
	126102,// Warmongering Combatant's Scaled Shoulders
	126103,// Warmongering Combatant's Girdle of Cruelty
	126104,// Warmongering Combatant's Girdle of Prowess
	126105,// Warmongering Combatant's Warboots of Cruelty
	126106,// Warmongering Combatant's Warboots of Prowess
	126107,// Warmongering Combatant's Armplates of Cruelty
	126108,// Warmongering Combatant's Armplates of Prowess
	126109,// Warmongering Combatant's Plate Breastplate
	126110,// Warmongering Combatant's Plate Gloves
	126111,// Warmongering Combatant's Plate Helmet
	126112,// Warmongering Combatant's Legplates
	126113,// Warmongering Combatant's Shoulderplates
	126172,// Warmongering Combatant's Plate Chestpiece
	126173,// Warmongering Combatant's Plate Gauntlets
	126174,// Warmongering Combatant's Plate Helm
	126175,// Warmongering Combatant's Plate Legguards
	126176,// Warmongering Combatant's Plate Shoulders
	126184,// Warmongering Aspirant's Dreadplate Chestpiece
	126185,// Warmongering Aspirant's Dreadplate Gauntlets
	126186,// Warmongering Aspirant's Dreadplate Helm
	126187,// Warmongering Aspirant's Dreadplate Legguards
	126188,// Warmongering Aspirant's Dreadplate Shoulders
	126223,// Warmongering Aspirant's Scaled Chestpiece
	126224,// Warmongering Aspirant's Scaled Gauntlets
	126225,// Warmongering Aspirant's Scaled Helm
	126226,// Warmongering Aspirant's Scaled Legguards
	126227,// Warmongering Aspirant's Scaled Shoulders
	126228,// Warmongering Aspirant's Girdle of Cruelty
	126229,// Warmongering Aspirant's Warboots of Cruelty
	126230,// Warmongering Aspirant's Armplates of Cruelty
	126263,// Warmongering Aspirant's Plate Chestpiece
	126264,// Warmongering Aspirant's Plate Gauntlets
	126265,// Warmongering Aspirant's Plate Helm
	126266,// Warmongering Aspirant's Plate Legguards
	126267,// Warmongering Aspirant's Plate Shoulders
	126304,// Warmongering Gladiator's Dreadplate Chestpiece
	126305,// Warmongering Gladiator's Dreadplate Gauntlets
	126306,// Warmongering Gladiator's Dreadplate Helm
	126307,// Warmongering Gladiator's Dreadplate Legguards
	126308,// Warmongering Gladiator's Dreadplate Shoulders
	126391,// Warmongering Gladiator's Scaled Chestpiece
	126392,// Warmongering Gladiator's Scaled Gauntlets
	126393,// Warmongering Gladiator's Scaled Helm
	126394,// Warmongering Gladiator's Scaled Legguards
	126395,// Warmongering Gladiator's Scaled Shoulders
	126396,// Warmongering Gladiator's Girdle of Cruelty
	126397,// Warmongering Gladiator's Girdle of Prowess
	126398,// Warmongering Gladiator's Girdle of Victory
	126399,// Warmongering Gladiator's Warboots of Cruelty
	126400,// Warmongering Gladiator's Warboots of Prowess
	126401,// Warmongering Gladiator's Warboots of Victory
	126402,// Warmongering Gladiator's Armplates of Cruelty
	126403,// Warmongering Gladiator's Armplates of Prowess
	126404,// Warmongering Gladiator's Armplates of Victory
	126405,// Warmongering Gladiator's Plate Breastplate
	126406,// Warmongering Gladiator's Plate Gloves
	126407,// Warmongering Gladiator's Plate Helmet
	126408,// Warmongering Gladiator's Legplates
	126409,// Warmongering Gladiator's Shoulderplates
	126410,// Warmongering Gladiator's Plate Chestguard
	126411,// Warmongering Gladiator's Plate Grips
	126412,// Warmongering Gladiator's Plate Visor
	126413,// Warmongering Gladiator's Plate Leggings
	126414,// Warmongering Gladiator's Plate Pauldrons
	126471,// Warmongering Gladiator's Plate Chestpiece
	126472,// Warmongering Gladiator's Plate Gauntlets
	126473,// Warmongering Gladiator's Plate Helm
	126474,// Warmongering Gladiator's Plate Legguards
	126475,// Warmongering Gladiator's Plate Shoulders
	126504,// Warmongering Combatant's Dreadplate Chestpiece
	126505,// Warmongering Combatant's Dreadplate Gauntlets
	126506,// Warmongering Combatant's Dreadplate Helm
	126507,// Warmongering Combatant's Dreadplate Legguards
	126508,// Warmongering Combatant's Dreadplate Shoulders
	126575,// Warmongering Combatant's Scaled Chestpiece
	126576,// Warmongering Combatant's Scaled Gauntlets
	126577,// Warmongering Combatant's Scaled Helm
	126578,// Warmongering Combatant's Scaled Legguards
	126579,// Warmongering Combatant's Scaled Shoulders
	126580,// Warmongering Combatant's Girdle of Cruelty
	126581,// Warmongering Combatant's Girdle of Prowess
	126582,// Warmongering Combatant's Warboots of Cruelty
	126583,// Warmongering Combatant's Warboots of Prowess
	126584,// Warmongering Combatant's Armplates of Cruelty
	126585,// Warmongering Combatant's Armplates of Prowess
	126586,// Warmongering Combatant's Plate Breastplate
	126587,// Warmongering Combatant's Plate Gloves
	126588,// Warmongering Combatant's Plate Helmet
	126589,// Warmongering Combatant's Legplates
	126590,// Warmongering Combatant's Shoulderplates
	126649,// Warmongering Combatant's Plate Chestpiece
	126650,// Warmongering Combatant's Plate Gauntlets
	126651,// Warmongering Combatant's Plate Helm
	126652,// Warmongering Combatant's Plate Legguards
	126653,// Warmongering Combatant's Plate Shoulders
	126661,// Warmongering Aspirant's Dreadplate Chestpiece
	126662,// Warmongering Aspirant's Dreadplate Gauntlets
	126663,// Warmongering Aspirant's Dreadplate Helm
	126664,// Warmongering Aspirant's Dreadplate Legguards
	126665,// Warmongering Aspirant's Dreadplate Shoulders
	126700,// Warmongering Aspirant's Scaled Chestpiece
	126701,// Warmongering Aspirant's Scaled Gauntlets
	126702,// Warmongering Aspirant's Scaled Helm
	126703,// Warmongering Aspirant's Scaled Legguards
	126704,// Warmongering Aspirant's Scaled Shoulders
	126705,// Warmongering Aspirant's Girdle of Cruelty
	126706,// Warmongering Aspirant's Warboots of Cruelty
	126707,// Warmongering Aspirant's Armplates of Cruelty
	126740,// Warmongering Aspirant's Plate Chestpiece
	126741,// Warmongering Aspirant's Plate Gauntlets
	126742,// Warmongering Aspirant's Plate Helm
	126743,// Warmongering Aspirant's Plate Legguards
	126744,// Warmongering Aspirant's Plate Shoulders
	126765,// Warmongering Gladiator's Dreadplate Chestpiece
	126766,// Warmongering Gladiator's Dreadplate Gauntlets
	126767,// Warmongering Gladiator's Dreadplate Helm
	126768,// Warmongering Gladiator's Dreadplate Legguards
	126769,// Warmongering Gladiator's Dreadplate Shoulders
	126820,// Warmongering Gladiator's Scaled Chestpiece
	126821,// Warmongering Gladiator's Scaled Gauntlets
	126822,// Warmongering Gladiator's Scaled Helm
	126823,// Warmongering Gladiator's Scaled Legguards
	126824,// Warmongering Gladiator's Scaled Shoulders
	126825,// Warmongering Gladiator's Scaled Clasp
	126826,// Warmongering Gladiator's Ornamented Clasp
	126827,// Warmongering Gladiator's Ornamented Greaves
	126828,// Warmongering Gladiator's Scaled Greaves
	126829,// Warmongering Gladiator's Ornamented Chestguard
	126830,// Warmongering Gladiator's Ornamented Gloves
	126831,// Warmongering Gladiator's Ornamented Headcover
	126832,// Warmongering Gladiator's Ornamented Legplates
	126833,// Warmongering Gladiator's Ornamented Spaulders
	126834,// Warmongering Gladiator's Dreadplate Girdle
	126835,// Warmongering Gladiator's Plate Girdle
	126836,// Warmongering Gladiator's Plate Warboots
	126837,// Warmongering Gladiator's Dreadplate Warboots
	126889,// Warmongering Gladiator's Plate Chestpiece
	126890,// Warmongering Gladiator's Plate Gauntlets
	126891,// Warmongering Gladiator's Plate Helm
	126892,// Warmongering Gladiator's Plate Legguards
	126893,// Warmongering Gladiator's Plate Shoulders
	127010,// Pristine Lightforge Breastplate
	127011,// Pristine Lightforge Legplates
	127012,// Pristine Lightforge Helm
	127049,// Gladiator's Dreadplate Chestpiece
	127052,// Gladiator's Scaled Chestpiece
	127055,// Gladiator's Plate Chestpiece
	127071,// Gladiator's Dreadplate Helm
	127076,// Gladiator's Scaled Helm
	127081,// Gladiator's Plate Helm
	127082,// Gladiator's Dreadplate Gauntlets
	127087,// Gladiator's Scaled Gauntlets
	127092,// Gladiator's Plate Gauntlets
	127093,// Gladiator's Dreadplate Shoulders
	127098,// Gladiator's Scaled Shoulders
	127103,// Gladiator's Plate Shoulders
	127104,// Gladiator's Dreadplate Legguards
	127109,// Gladiator's Scaled Legguards
	127114,// Gladiator's Plate Legguards
	127149,// Breastplate of the Bold
	127153,// Rubium War-Girdle
	127157,// Thatia's Self-Correcting Gauntlets
	127165,// Doomplate Chestguard
	127177,// Bracers of Dignity
	127195,// Girdle of Many Blessings
	127199,// Girdle of the Immovable
	127211,// Breastplate of Righteous Fury
	127218,// Faith Bearer's Gauntlets
	127229,// Nexus-Bracers of Vigor
	127232,// Gauntlets of Vindication
	127233,// Boots of the Colossus
	127253,// Pauldrons of Swift Retribution
	127317,// Murktide's Coveted Chestplate
	127318,// Iron Cleated Warboots
	127319,// Krag'goth's Iron Gauntlets
	127320,// Mo'gruth's Discarded Parade Helm
	127321,// Iron Houndmaster's Pauldrons
	127322,// Fel Burnished Waistguard
	127323,// Bracers of Endless Suffering
	127423,// Slatesteel Breastplate
	127431,// Legplates of the Righteous
	127433,// Legplates of the Bold
	127453,// Pauldrons of the Crimson Flight
	127455,// Girdle of Valorous Deeds
	127460,// Svala's Bloodied Shackles
	127465,// Reanimated Armor
	127468,// Harpooner's Striders
	127473,// Crown of Forgotten Kings
	127476,// Ancient Royal Legguards
	127478,// Berserker's Sabatons
	127481,// Echoing Stompers
	127488,// Ferocious Pauldrons of the Rhino
	127490,// Skadi's Iron Belt
	127494,// Ornamented Plate Regalia
	127503,// Bands of Fading Light
	127504,// Iron Dwarf Smith Pauldrons
	127507,// The General's Steel Girdle
	127515,// Skywall Striders
	127517,// Planetary Helm
	127531,// Forlorn Breastplate of War
	127536,// Steel Bear Trap Bracers
	127539,// Snake Den Spaulders
	127544,// Mojo Frenzy Greaves
	127545,// Ground Tremor Helm
	127547,// Pauldrons of the Colossus
	127557,// Horn-Tipped Gauntlets
	127564,// Engraved Chestplate of Eck
	127575,// Chiseled Stalagmite Pauldrons
	127576,// Greaves of the Blue Flight
	127577,// Insulating Bindings
	127581,// Arcane-Shielded Helm
	127587,// Rift Striders
	127589,// Girdle of Ice
	127598,// Flame-Bathed Steel Girdle
	127601,// Glassy Silver Bracers
	127604,// Grips of Sculptured Icicles
	127609,// Crawler-Emblem Belt
	127615,// Volazj's Sabatons
	127623,// Bonegrinder Breastplate
	127629,// Greaves of Ancient Evil
	127631,// Bracers of the Herald
	127635,// Web Winder Gloves
	127638,// Battlechest of the Twilight Cult
	127639,// Faceguard of the Hammer Clan
	127664,// Grokmar's Greaves of Fortification
	127984,// Wristclasps of Righteous Reckoning
	128032,// Demonbreaker Crushers
	128033,// Assembly Worker's Legguards
	128042,// Ribwrencher Gauntlets
	128043,// Gaze of Superiority
	128050,// Engine-Kicking Boots
	128051,// Automated Shoulderplates
	128057,// Chestplate of Potential Energy
	128058,// Roughly Soldered Wristclamps
	128061,// Wailing Woe Pauldrons
	128068,// Blade-Chipped Waistguard
	128073,// Ironspike Knuckled Gauntlets
	128074,// Hollowheart Helm
	128082,// Corrupted Talonguard Chestplate
	128083,// Feather-Embellished Wristclamps
	128088,// Girdle of Bound Agony
	128091,// Stoic Netherfel Legplates
	128123,// Demonbreaker Pauldrons
	128127,// Demonbreaker Chestplate
	128134,// Demonbreaker Helm
	128135,// Demonbreaker Legplates
	128139,// Demonbreaker Gauntlets
	128171,// Stompers of Echoing Doom
	128177,// Demonforged Iron Bracers
	128300,// Befouled Demonhide Belt
	128352,// Felbane Shoulderguard
	129427,// Heart-Lesion Breastplate
	129428,// Heart-Lesion Sabatons
	129429,// Heart-Lesion Gauntlets
	129430,// Heart-Lesion Helm
	129431,// Heart-Lesion Legplates
	129432,// Heart-Lesion Pauldrons
	129433,// Heart-Lesion Girdle
	129434,// Heart-Lesion Vambraces
	129442,// Heart-Lesion Chestguard
	129444,// Heart-Lesion Greaves
	129445,// Heart-Lesion Handguards
	129446,// Heart-Lesion Faceguard
	129447,// Heart-Lesion Legguards
	129453,// Heart-Lesion Shoulderguards
	129454,// Heart-Lesion Waistband
	129455,// Heart-Lesion Armguards
	129527,// Oathsworn Breastplate
	129528,// Oathsworn Sabatons
	129529,// Oathsworn Gauntlets
	129530,// Oathsworn Helm
	129531,// Oathsworn Legplates
	129532,// Oathsworn Pauldrons
	129533,// Oathsworn Girdle
	129534,// Oathsworn Vambraces
	129544,// Oathsworn Chestguard
	129546,// Oathsworn Greaves
	129547,// Oathsworn Handguards
	129548,// Oathsworn Faceguard
	129549,// Oathsworn Legguards
	129555,// Oathsworn Shoulderguards
	129556,// Oathsworn Waistband
	129557,// Oathsworn Armguards
	129656,// Sunsoul Battleplate
	129657,// Sunsoul Sabatons
	129658,// Sunsoul Gauntlets
	129659,// Sunsoul Helm
	129660,// Sunsoul Legplates
	129661,// Sunsoul Pauldrons
	129662,// Sunsoul Girdle
	129663,// Sunsoul Vambraces
	129664,// Sunsoul Breastplate
	129666,// Sunsoul Boots
	129667,// Sunsoul Gloves
	129668,// Sunsoul Headpiece
	129669,// Sunsoul Leggings
	129675,// Sunsoul Spaulders
	129676,// Sunsoul Belt
	129677,// Sunsoul Armplates
	129689,// Sunsoul Chestguard
	129691,// Sunsoul Greaves
	129692,// Sunsoul Handguards
	129693,// Sunsoul Faceguard
	129694,// Sunsoul Legguards
	129700,// Sunsoul Shoulderguards
	129701,// Sunsoul Waistband
	129702,// Sunsoul Armguards
	129835,// Faceguard of Determination
	129842,// Legplates of Unending Fury
	129854,// Girdle of Seething Rage
	129868,// Kyzoc's Ground Stompers
	129880,// Gauntlets of the Kraken
	129889,// Castle Breaker's Battleplate
	133185,// Harp Shell Pauldrons
	133191,// Anomuran Helm
	133195,// Triton Legplates
	133202,// Abalone Plate Armor
	133205,// Alpheus Legguards
	133208,// Cinnabar Shoulders
	133214,// Hematite Plate Gloves
	133218,// Belt of the Ringworm
	133234,// Headcover of Fog
	133243,// Legguards of Winnowing Wind
	133249,// Lunar Halo
	133253,// Darksky Treads
	133256,// Greaves of Wu the Elder
	133262,// Greaves of Wu the Younger
	133267,// Sand Dune Belt
	133289,// Belt of the Forgemaster
	133294,// Earthshape Pauldrons
	133306,// Bracers of Umbral Mending
	133387,// Gauntlets of Temporal Interference
	133388,// Breastplate of Sorrow
	133390,// Girdle of Lost Heroes
	133394,// Waistguard of Lost Time
	133402,// Bloodhoof Legguards
	133404,// Time Altered Legguards
	133405,// Breastplate of Tarnished Bronze
	133406,// Chrono Boots
	133407,// Crown of Epochs
	133408,// Temporal Pauldrons
	133416,// Time Strand Gauntlets
	133422,// Breastplate of Despair
	133424,// Bindings of the End Times
	133434,// Gauntlets of Divine Blessings
	133445,// Bracers of Slaughter
	133451,// Helm of Sanctification
	133456,// Sunstrider Warboots
	133465,// Shoulderplates of Everlasting Pain
	133468,// Breastplate of Fierce Survival
	133475,// Greaves of the Penitent Knight
	133478,// Netherforce Chestplate
	133492,// Bent Gold Belt
	133498,// Scourgelord's Frigid Chestplate
	133501,// Skeleton Lord's Cranium
	133525,// Bones of the Damned
	133531,// Blinding Girdle of Truth
	133533,// Flashing Bracers of Warmth
	     0,
};

item_subclass_t weapon_type_list[] = {
	{  1933,    10},// Staff of Conjuring
	{  5613,    10},// Staff of the Purifier
	{  9449,     5},// Manual Crowd Pummeler
	{ 12532,    10},// Spire of the Stoneshaper
	{ 13937,    10},// Headmaster's Charge
	{ 17074,     6},// Shadowstrike
	{ 17223,     6},// Thunderstrike
	{ 18582,     7},// The Twin Blades of Azzinoth
	{ 18583,     7},// Warglaive of Azzinoth (Right)
	{ 18584,     7},// Warglaive of Azzinoth (Left)
	{ 18608,    10},// Benediction
	{ 18609,    10},// Anathema
	{ 22589,    10},// Atiesh, Greatstaff of the Guardian
	{ 22630,    10},// Atiesh, Greatstaff of the Guardian
	{ 22631,    10},// Atiesh, Greatstaff of the Guardian
	{ 22632,    10},// Atiesh, Greatstaff of the Guardian
	{ 22783,     7},// Sunwell Blade
	{ 23362,     4},// Hammer of the Sun
	{ 23497,     0},// Fel Iron Hatchet
	{ 23498,     4},// Fel Iron Hammer
	{ 23499,     8},// Fel Iron Greatsword
	{ 23502,     5},// Adamantite Maul
	{ 23503,     1},// Adamantite Cleaver
	{ 23505,     7},// Adamantite Rapier
	{ 23540,     7},// Felsteel Longblade
	{ 23541,     8},// Khorium Champion
	{ 23542,     0},// Fel Edged Battleaxe
	{ 23543,     1},// Felsteel Reaper
	{ 23544,     4},// Runic Hammer
	{ 23546,     5},// Fel Hardened Maul
	{ 23556,     4},// Hand of Eternity
	{ 24361,     7},// Spellfire Longsword
	{ 24378,     4},// Coilfang Hammer of Renewal
	{ 24461,     5},// Hatebringer
	{ 24550,     8},// Gladiator's Greatsword
	{ 24557,    10},// Gladiator's War Staff
	{ 25117,     4},// Flanged Battle Mace
	{ 25118,     4},// Battle Star
	{ 25119,     4},// Silvermoon War-Mace
	{ 25120,     4},// Rockshard Club
	{ 25121,     4},// Dreaded Mace
	{ 25122,     4},// Khorium Plated Bludgeon
	{ 25123,     4},// Boneshredder Mace
	{ 25124,     4},// Footman Mace
	{ 25125,     4},// Retro-Spike Club
	{ 25126,     4},// Anvilmar Hammer
	{ 25127,     4},// Knight's War Hammer
	{ 25131,     5},// Hateful Bludgeon
	{ 25132,     5},// Thrallmar War Hammer
	{ 25133,     5},// Stormwind Maul
	{ 25134,     5},// Highmountain Hammer
	{ 25135,     5},// Clefthoof Mace
	{ 25136,     5},// Blood Stained Hammer
	{ 25137,     5},// Draenethyst Mallet
	{ 25138,     5},// Blood Knight Maul
	{ 25139,     5},// Algaz Battle Hammer
	{ 25140,     5},// Commanding Mallet
	{ 25141,     5},// Halaani Hammer
	{ 25145,     7},// Wisdom Blade
	{ 25146,     7},// Light-Etched Longsword
	{ 25147,     7},// Skystrider Katana
	{ 25148,     7},// Bone Collector Sword
	{ 25149,     7},// Baron's Broadsword
	{ 25150,     7},// Honor Hold Saber
	{ 25151,     7},// Assassins' Short Blade
	{ 25152,     7},// Howling Sword
	{ 25153,     7},// Gladiator Greatblade
	{ 25154,     7},// Blood Groove Blade
	{ 25155,     7},// Iron Skull Sword
	{ 25159,     8},// Thunderstrike Falchion
	{ 25160,     8},// Vengeance Blade
	{ 25161,     8},// Dragon Wing Blade
	{ 25162,     8},// Darkened Broadsword
	{ 25163,     8},// Elexorien Blade
	{ 25164,     8},// Crude Umbrafen Blade
	{ 25165,     8},// Boulderfist Claymore
	{ 25166,     8},// Mok'Nathal Warblade
	{ 25167,     8},// Nethersteel Claymore
	{ 25168,     8},// Sha'tari Longsword
	{ 25169,     8},// Fel Orc Brute Sword
	{ 25173,    10},// Master's Bo Staff
	{ 25174,    10},// Hanbo Staff
	{ 25175,    10},// Demoniac Longstaff
	{ 25176,    10},// Taiji Quarterstaff
	{ 25177,    10},// Tanjo Staff
	{ 25178,    10},// Bata Staff
	{ 25179,    10},// Nguni Stick
	{ 25180,    10},// Calenda Fighting Stick
	{ 25181,    10},// Tapered Staff
	{ 25182,    10},// Crystal-Etched Warstaff
	{ 25183,    10},// Voodoo Hex-Staff
	{ 25201,     0},// Reaver's Sickle
	{ 25202,     0},// Kingly Axe
	{ 25203,     0},// Chipped Woodchopper
	{ 25204,     0},// Colossal War Axe
	{ 25205,     0},// Silvermoon Crescent Axe
	{ 25206,     0},// Berserker Axe
	{ 25207,     0},// Shadowmoon Cleaver
	{ 25208,     0},// Bladespire Broadaxe
	{ 25209,     0},// Amani Tomahawk
	{ 25210,     0},// Double-Bladed Axe
	{ 25211,     0},// Rockbiter Cutter
	{ 25215,     1},// Spiked Battle Axe
	{ 25216,     1},// Ogre Splitting Axe
	{ 25217,     1},// Sundering Axe
	{ 25218,     1},// Silver-Edged Axe
	{ 25219,     1},// Rending Claw
	{ 25220,     1},// Glorious War-Axe
	{ 25221,     1},// Ghostly Battle Axe
	{ 25222,     1},// Ceremonial Slayer's Axe
	{ 25223,     1},// Windcaller Hatchet
	{ 25224,     1},// Slavemaster Axe
	{ 25225,     1},// Deepforge Broadaxe
	{ 25229,     6},// Partisan Polearm
	{ 25230,     6},// Voulge Blade
	{ 25231,     6},// Fel-Wrought Halberd
	{ 25232,     6},// War Glaive
	{ 25233,     6},// Battle Scythe
	{ 25234,     6},// Telaari Polearm
	{ 25235,     6},// Ethereal-Etched Glaive
	{ 25236,     6},// Grim Scythe
	{ 25237,     6},// Nether Trident
	{ 25238,     6},// Hellfire War Spear
	{ 25239,     6},// Legend's Glaive
	{ 25313,     4},// Cold-Iron Scepter
	{ 25314,     4},// Ceremonial Hammer
	{ 25315,     4},// Restorative Mace
	{ 25316,     4},// Spirit-Clad Mace
	{ 25317,     4},// Lesser Sledgemace
	{ 25318,     4},// Ancestral Hammer
	{ 25319,     4},// Tranquility Mace
	{ 25320,     4},// Queen's Insignia
	{ 25321,     4},// Divine Hammer
	{ 25322,     4},// Lordly Scepter
	{ 25323,     4},// Ascendant's Scepter
	{ 25327,    10},// Frenzied Staff
	{ 25328,    10},// Faerie-Kind Staff
	{ 25329,    10},// Tranquility Staff
	{ 25330,    10},// Starshine Staff
	{ 25331,    10},// Vengeance Staff
	{ 25332,    10},// Reflective Staff
	{ 25333,    10},// Purification Staff
	{ 25334,    10},// Intimidating Greatstaff
	{ 25335,    10},// Feral Warp-Staff
	{ 25336,    10},// Splintering Greatstaff
	{ 25337,    10},// Swarming Sting-Staff
	{ 25492,     4},// Earthcaller's Mace
	{ 25494,    10},// Totemic Staff
	{ 25519,     4},// Warden's Hammer
	{ 25536,     4},// Sporeggar Smasher
	{ 25537,     1},// Hewing Axe of the Marsh
	{ 25603,     6},// Lantresor's Warblade
	{ 25608,     6},// Lantresor's Warblade
	{ 25622,    10},// Staff of the Four Golden Coins
	{ 25759,     4},// Mogor's Anointing Club
	{ 25760,    10},// Battle Mage's Baton
	{ 25761,    10},// Staff of Beasts
	{ 25762,     1},// Honed Voidaxe
	{ 25772,     7},// Crystalline Kopesh
	{ 25773,     4},// Hungering Bone Cudgel
	{ 25835,    10},// Explorer's Walking Stick
	{ 25836,     4},// Preserver's Cudgel
	{ 25915,     7},// Fallen Vindicator's Blade
	{ 25916,     0},// Terokkar Axe
	{ 25917,    10},// Healer's Staff of the Forest
	{ 25920,     7},// Sedai's Blade
	{ 25933,     7},// Extra Sharp Blade
	{ 25934,     5},// Spiked Destroyer
	{ 25935,    10},// Invincible Stave
	{ 25944,     8},// Shaarde the Greater
	{ 25950,    10},// Staff of Polarities
	{ 25952,     7},// Scimitar of the Nexus-Stalkers
	{ 25964,     7},// Shaarde the Lesser
	{ 25985,    10},// Cenarion Naturalist's Staff
	{ 25986,     5},// Dreadtusk's Fury
	{ 25987,     8},// Helboar Carving Blade
	{ 26655,    10},// 70 TEST Green Staff
	{ 26792,     4},// 67 TEST Green Healer Mace
	{ 27412,    10},// Ironstaff of Regeneration
	{ 27424,     0},// Amani Venom-Axe
	{ 27426,     4},// Northshire Battlemace
	{ 27476,     4},// Truncheon of Five Hells
	{ 27490,     0},// Firebrand Battleaxe
	{ 27512,     7},// The Willbreaker
	{ 27524,     5},// Firemaul of Destruction
	{ 27538,     4},// Lightsworn Hammer
	{ 27673,     7},// Phosphorescent Blade
	{ 27741,     4},// Bleeding Hollow Warhammer
	{ 27749,    10},// Staff of the Wild
	{ 27750,     5},// Hammer of the Sporelings
	{ 27751,     6},// Survivalist's Pike
	{ 27752,     8},// Zangarmarsh Claymore
	{ 27754,     7},// Keen Marshfang Slicer
	{ 27756,     0},// Marshfang Blade Axe
	{ 27757,    10},// Greatstaff of the Leviathan
	{ 27767,     0},// Bogreaver
	{ 27769,     8},// Endbringer
	{ 27791,    10},// Serpentcrest Life-Staff
	{ 27829,     1},// Axe of the Nexus-Kings
	{ 27840,     5},// Scepter of Sha'tar
	{ 27842,    10},// Grand Scepter of the Nexus-Kings
	{ 27872,     0},// The Harvester of Souls
	{ 27876,     4},// Will of the Fallen Exarch
	{ 27877,    10},// Draenic Wildstaff
	{ 27899,     7},// Mana Wrath
	{ 27901,     4},// Blackout Truncheon
	{ 27903,     6},// Sonic Spear
	{ 27905,     7},// Greatsword of Horrid Dreams
	{ 27937,     4},// Sky Breaker
	{ 27980,     4},// Terokk's Nightmace
	{ 27986,     1},// Crow Wing Reaper
	{ 28033,    10},// Epoch-Mender
	{ 28184,     7},// Millennium Blade
	{ 28188,    10},// Bloodfire Greatstaff
	{ 28189,     7},// Latro's Shifting Sword
	{ 28210,     4},// Bloodskull Destroyer
	{ 28216,     4},// Dathrohan's Ceremonial Hammer
	{ 28222,     1},// Reaver of the Infinites
	{ 28253,     6},// Plasma Rat's Hyper-Scythe
	{ 28257,     4},// Hammer of the Penitent
	{ 28263,     0},// Stellaris
	{ 28267,     7},// Edge of the Cosmos
	{ 28293,     8},// High Warlord's Claymore
	{ 28295,     7},// Gladiator's Slicer
	{ 28298,     1},// Gladiator's Decapitator
	{ 28299,     5},// Gladiator's Bonegrinder
	{ 28300,     6},// Gladiator's Painsaw
	{ 28302,     4},// Gladiator's Bonecracker
	{ 28305,     4},// Gladiator's Pummeler
	{ 28307,     7},// Gladiator's Quickblade
	{ 28308,     0},// Gladiator's Cleaver
	{ 28309,     0},// Gladiator's Hacker
	{ 28311,     7},// Revenger
	{ 28325,    10},// Dreamer's Dragonstaff
	{ 28341,    10},// Warpstaff of Arcanum
	{ 28367,     8},// Greatsword of Forlorn Visions
	{ 28393,     5},// Warmaul of Infused Light
	{ 28400,     7},// Warp-Storm Warblade
	{ 28425,     7},// Fireguard
	{ 28426,     7},// Blazeguard
	{ 28427,     7},// Blazefury
	{ 28428,     8},// Lionheart Blade
	{ 28429,     8},// Lionheart Champion
	{ 28430,     8},// Lionheart Executioner
	{ 28431,     0},// The Planar Edge
	{ 28432,     0},// Black Planar Edge
	{ 28433,     0},// Wicked Edge of the Planes
	{ 28434,     1},// Lunar Crescent
	{ 28435,     1},// Mooncleaver
	{ 28436,     1},// Bloodmoon
	{ 28437,     4},// Drakefist Hammer
	{ 28438,     4},// Dragonmaw
	{ 28439,     4},// Dragonstrike
	{ 28440,     5},// Thunder
	{ 28441,     5},// Deep Thunder
	{ 28442,     5},// Stormherald
	{ 28476,     5},// Gladiator's Maul
	{ 28522,     4},// Shard of the Virtuous
	{ 28573,     8},// Despair
	{ 28587,     1},// Legacy
	{ 28604,    10},// Nightstaff of the Everliving
	{ 28633,    10},// Staff of Infinite Mysteries
	{ 28657,     4},// Fool's Bane
	{ 28658,    10},// Terestian's Stranglestaff
	{ 28729,     7},// Spiteblade
	{ 28749,     7},// King's Defender
	{ 28767,     0},// The Decapitator
	{ 28771,     4},// Light's Justice
	{ 28773,     1},// Gorehowl
	{ 28774,     6},// Glaive of the Pit
	{ 28782,    10},// Crystalheart Pulse-Staff
	{ 28794,     1},// Axe of the Gronn Lords
	{ 28800,     5},// Hammer of the Naaru
	{ 28802,     7},// Bloodmaw Magus-Blade
	{ 28917,     5},// High Warlord's Bonegrinder
	{ 28918,     1},// High Warlord's Decapitator
	{ 28919,     5},// High Warlord's Maul
	{ 28920,     0},// High Warlord's Cleaver
	{ 28921,     0},// High Warlord's Hacker
	{ 28923,     6},// High Warlord's Painsaw
	{ 28924,     4},// High Warlord's Bonecracker
	{ 28925,     4},// High Warlord's Pummeler
	{ 28926,     7},// High Warlord's Quickblade
	{ 28935,    10},// High Warlord's War Staff
	{ 28937,     7},// High Warlord's Slicer
	{ 28942,     5},// Grand Marshal's Bonegrinder
	{ 28943,     8},// Grand Marshal's Warblade
	{ 28944,     0},// Grand Marshal's Cleaver
	{ 28945,     1},// Grand Marshal's Decapitator
	{ 28946,     0},// Grand Marshal's Hacker
	{ 28948,     5},// Grand Marshal's Maul
	{ 28949,     6},// Grand Marshal's Painsaw
	{ 28950,     4},// Grand Marshal's Bonecracker
	{ 28951,     4},// Grand Marshal's Pummeler
	{ 28952,     7},// Grand Marshal's Quickblade
	{ 28956,     7},// Grand Marshal's Slicer
	{ 28959,    10},// Grand Marshal's War Staff
	{ 29124,     7},// Vindicator's Brand
	{ 29130,    10},// Auchenai Staff
	{ 29133,    10},// Seer's Cane
	{ 29137,     1},// Hellscream's Will
	{ 29138,     5},// Arechron's Gift
	{ 29153,     7},// Blade of the Archmage
	{ 29155,     7},// Stormcaller
	{ 29156,     7},// Honor's Call
	{ 29165,     0},// Warbringer
	{ 29166,     6},// Hellforged Halberd
	{ 29167,     6},// Blackened Spear
	{ 29171,     5},// Earthwarden
	{ 29175,     4},// Gavel of Pure Light
	{ 29185,     7},// Continuum Blade
	{ 29329,     6},// Terokk's Quill
	{ 29353,     4},// Shockwave Truncheon
	{ 29355,    10},// Terokk's Shadowstaff
	{ 29356,     8},// Quantum Blade
	{ 29359,    10},// Feral Staff of Lashing
	{ 29362,     7},// The Sun Eater
	{ 29377,     6},// Ethereum Phase-Spear
	{ 29380,     7},// Ethereum Phase Blade
	{ 29399,    10},// Rod of the Void Caller
	{ 29456,     7},// Gift of the Ethereal
	{ 29787,     4},// Master Smith's Hammer
	{ 29924,     0},// Netherbane
	{ 29981,    10},// Ethereum Life-Staff
	{ 29988,    10},// The Nexus Key
	{ 29993,     8},// Twinblade of the Phoenix
	{ 29996,     4},// Rod of the Sun King
	{ 30009,     1},// The Burning Crusader
	{ 30010,    10},// Fleshling Simulation Staff
	{ 30011,    10},// Ameer's Impulse Taser
	{ 30012,    10},// Ameer's Judgement
	{ 30021,    10},// Wildfury Greatstaff
	{ 30058,     4},// Mallet of the Tides
	{ 30077,     7},// Windforged Rapier
	{ 30082,     7},// Talon of Azshara
	{ 30086,     8},// Stoneforged Claymore
	{ 30087,     0},// Stormforged Axe
	{ 30088,     1},// Skyforged Great Axe
	{ 30089,     4},// Lavaforged Warhammer
	{ 30090,     5},// World Breaker
	{ 30093,     5},// Great Earthforged Hammer
	{ 30095,     7},// Fang of the Leviathan
	{ 30108,     4},// Lightfathom Scepter
	{ 30278,     7},// Pilfered Ethereal Blade
	{ 30311,     7},// Warp Slicer
	{ 30313,    10},// Staff of Disintegration
	{ 30316,     1},// Devastation
	{ 30317,     4},// Cosmic Infuser
	{ 30364,     0},// Resonating Axe
	{ 30394,     8},// Sunfury Blade
	{ 30395,     5},// Warp-Master's Maul
	{ 30396,     6},// Jeweled Halberd
	{ 30522,    10},// Conjurer's Staff
	{ 30570,     8},// Arkadian Claymore
	{ 30597,     8},// Halaani Claymore
	{ 30722,     1},// Ethereum Nexus-Reaver
	{ 30732,    10},// Exodar Life-Staff
	{ 30733,     7},// Hope Ender
	{ 30788,     7},// Illidari-Bane Broadsword
	{ 30789,     8},// Illidari-Bane Claymore
	{ 30830,     6},// Trident of the Outcast Tribe
	{ 30832,     4},// Gavel of Unearthed Secrets
	{ 30874,     7},// The Unbreakable Will
	{ 30881,     7},// Blade of Infamy
	{ 30883,    10},// Pillar of Ferocity
	{ 30902,     8},// Cataclysm's Edge
	{ 30908,    10},// Apostle of Argus
	{ 30910,     7},// Tempest of Chaos
	{ 30918,     4},// Hammer of Atonement
	{ 31002,     7},// Summoner's Blade
	{ 31009,    10},// Wildcaller
	{ 31010,     1},// Slayer's Axe
	{ 31036,    10},// Oronok's Ancient Scepter
	{ 31038,    10},// Staff of the Redeemer
	{ 31062,     1},// Torn-Heart Axe of Battle
	{ 31071,     0},// Grom'tor's Charge
	{ 31153,     0},// Axe of the Legion
	{ 31186,    10},// Braxxis' Staff of Slumber
	{ 31234,     7},// Crystalblade of the Draenei
	{ 31289,    10},// Staff of Divine Infusion
	{ 31291,     1},// Crystalforged War Axe
	{ 31299,     5},// The Oathkeeper
	{ 31304,     4},// The Essence Focuser
	{ 31308,    10},// The Bringer of Death
	{ 31318,     1},// Singing Crystal Axe
	{ 31322,     5},// The Hammer of Destiny
	{ 31332,     7},// Blinkstrike
	{ 31334,    10},// Staff of Natural Fury
	{ 31336,     7},// Blade of Wizardry
	{ 31342,     4},// The Ancient Scepter of Sue-Min
	{ 31414,    10},// Wild Wood Staff
	{ 31417,    10},// Staff of the Ashtongue Deathsworn
	{ 31423,     0},// Wolf Hewer's Axe
	{ 31448,     7},// Vibro Sword
	{ 31541,     7},// Whistling Sword
	{ 31542,     1},// Fanged Axe
	{ 31543,    10},// Adjudicator's Staff
	{ 31700,    10},// Runed Silver Staff
	{ 31701,     1},// Saboteur's Axe
	{ 31785,     1},// Edge of Inevitability
	{ 31816,     8},// Dragonbone Greatsword
	{ 31821,     7},// Blade of Retribution
	{ 31958,     4},// Merciless Gladiator's Bonecracker
	{ 31959,     5},// Merciless Gladiator's Bonegrinder
	{ 31965,     0},// Merciless Gladiator's Cleaver
	{ 31966,     1},// Merciless Gladiator's Decapitator
	{ 31984,     8},// Merciless Gladiator's Greatsword
	{ 31985,     0},// Merciless Gladiator's Hacker
	{ 32014,     5},// Merciless Gladiator's Maul
	{ 32025,     6},// Merciless Gladiator's Painsaw
	{ 32026,     4},// Merciless Gladiator's Pummeler
	{ 32027,     7},// Merciless Gladiator's Quickblade
	{ 32052,     7},// Merciless Gladiator's Slicer
	{ 32055,    10},// Merciless Gladiator's War Staff
	{ 32173,     4},// Chancellor's Bonecracker
	{ 32174,     0},// Chancellor's Cleaver
	{ 32175,     0},// Chancellor's Hacker
	{ 32176,     4},// Chancellor's Pummeler
	{ 32177,     7},// Chancellor's Quickblade
	{ 32180,     7},// Chancellor's Slicer
	{ 32181,     5},// Chancellor's Bonegrinder
	{ 32182,     1},// Chancellor's Decapitator
	{ 32183,     5},// Chancellor's Maul
	{ 32184,     6},// Chancellor's Painsaw
	{ 32185,    10},// Chancellor's War Staff
	{ 32186,     8},// Chancellor's Warblade
	{ 32236,     0},// Rising Tide
	{ 32248,     6},// Halberd of Desolation
	{ 32254,     0},// The Brutalizer
	{ 32262,     4},// Syphon of the Nathrezim
	{ 32332,     5},// Torch of the Damned
	{ 32344,    10},// Staff of Immaculate Recovery
	{ 32348,     1},// Soul Cleaver
	{ 32369,     7},// Blade of Savagery
	{ 32374,    10},// Zhar'doom, Greatstaff of the Devourer
	{ 32421,     1},// Tom's Axe A
	{ 32422,     1},// Tom's Axe B
	{ 32450,     4},// Gladiator's Gavel
	{ 32451,     4},// Gladiator's Salvation
	{ 32466,     7},// Bland Blade
	{ 32500,     4},// Crystal Spire of Karabor
	{ 32536,     4},// Terokk's Gavel
	{ 32537,     4},// Terokk's Gavel
	{ 32660,     7},// Crystalforged Sword
	{ 32661,     4},// Apexis Crystal Mace
	{ 32662,    10},// Flaming Quartz Staff
	{ 32663,     1},// Apexis Cleaver
	{ 32829,     6},// Windcharger's Lance
	{ 32830,    10},// Severin's Cane
	{ 32837,     7},// Warglaive of Azzinoth
	{ 32838,     7},// Warglaive of Azzinoth
	{ 32854,     5},// Hammer of Righteous Might
	{ 32943,     4},// Swiftsteel Bludgeon
	{ 32949,     7},// Unusually Slow Sword
	{ 32950,     4},// Unusually Slow Mace
	{ 32963,     4},// Merciless Gladiator's Gavel
	{ 32964,     4},// Merciless Gladiator's Salvation
	{ 33214,     7},// Akil'zon's Talonblade
	{ 33283,     4},// Amani Punisher
	{ 33350,     8},// Frostmourne Art Demo
	{ 33388,     7},// Heartless
	{ 33423,     4},// Rime-Covered Mace
	{ 33424,    10},// Cracked Iron Staff
	{ 33425,     7},// Ice-Pitted Blade
	{ 33426,     0},// Chipped Timber Axe
	{ 33429,     1},// Ice Cleaver
	{ 33430,     8},// Abandoned Greatsword
	{ 33431,     5},// Icesmashing Mace
	{ 33465,    10},// Staff of Primal Fury
	{ 33467,     7},// Blade of Twisted Visions
	{ 33468,     4},// Dark Blessing
	{ 33475,     8},// Frostmourne
	{ 33476,     0},// Cleaver of the Unforgiving
	{ 33478,     8},// Jin'rohk, The Great Apocalypse
	{ 33490,    10},// Staff of Dark Mending
	{ 33492,     1},// Trollbane
	{ 33494,    10},// Amani Divining Staff
	{ 33662,     4},// Vengeful Gladiator's Bonecracker
	{ 33663,     5},// Vengeful Gladiator's Bonegrinder
	{ 33669,     0},// Vengeful Gladiator's Cleaver
	{ 33670,     1},// Vengeful Gladiator's Decapitator
	{ 33687,     4},// Vengeful Gladiator's Gavel
	{ 33688,     8},// Vengeful Gladiator's Greatsword
	{ 33689,     0},// Vengeful Gladiator's Hacker
	{ 33716,    10},// Vengeful Gladiator's Staff
	{ 33727,     6},// Vengeful Gladiator's Painsaw
	{ 33733,     4},// Vengeful Gladiator's Pummeler
	{ 33734,     7},// Vengeful Gladiator's Quickblade
	{ 33743,     4},// Vengeful Gladiator's Salvation
	{ 33762,     7},// Vengeful Gladiator's Slicer
	{ 33766,    10},// Vengeful Gladiator's War Staff
	{ 34009,     4},// Hammer of Judgement
	{ 34014,     1},// Vengeful Gladiator's Waraxe
	{ 34015,     0},// Vengeful Gladiator's Chopper
	{ 34164,     7},// Dragonscale-Encrusted Longblade
	{ 34176,     4},// Reign of Misery
	{ 34182,    10},// Grand Magister's Staff of Torrents
	{ 34183,     6},// Shivering Felspine
	{ 34198,    10},// Stanchion of Primal Instinct
	{ 34199,     4},// Archon's Gavel
	{ 34214,     7},// Muramasa
	{ 34247,     8},// Apolyon, the Soul-Render
	{ 34335,     4},// Hammer of Sanctification
	{ 34337,    10},// Golden Staff of the Sin'dorei
	{ 34540,    10},// Vengeful Gladiator's Battle Staff
	{ 34608,    10},// Rod of the Blazing Light
	{ 34609,     7},// Quickening Blade of the Prince
	{ 34611,     4},// Cudgel of Consecration
	{ 34616,     0},// Breeching Comet
	{ 34666,     7},// The Sunbreaker
	{ 34667,     7},// Archmage's Guile
	{ 34670,     4},// Seeker's Gavel
	{ 34671,     4},// K'iru's Presage
	{ 34672,     7},// Inuuro's Blade
	{ 34673,     1},// Legionfoe
	{ 34699,     0},// Sun-Forged Cleaver
	{ 34703,     7},// Latro's Dancing Blade
	{ 34790,     4},// Battle-Mace of the High Priestess
	{ 34794,     1},// Axe of Shattered Dreams
	{ 34797,    10},// Sun-Infused Focus Staff
	{ 34891,     1},// The Blade of Harbingers
	{ 34896,     4},// Gavel of Naaru Blessings
	{ 34898,    10},// Staff of the Forest Lord
	{ 34987,    10},// Brutal Gladiator's Battle Staff
	{ 34988,     4},// Brutal Gladiator's Bonecracker
	{ 34989,     5},// Brutal Gladiator's Bonegrinder
	{ 34995,     0},// Brutal Gladiator's Chopper
	{ 34996,     0},// Brutal Gladiator's Cleaver
	{ 34997,     1},// Brutal Gladiator's Decapitator
	{ 35014,     4},// Brutal Gladiator's Gavel
	{ 35015,     8},// Brutal Gladiator's Greatsword
	{ 35017,     0},// Brutal Gladiator's Hacker
	{ 35064,     6},// Brutal Gladiator's Painsaw
	{ 35071,     4},// Brutal Gladiator's Pummeler
	{ 35072,     7},// Brutal Gladiator's Quickblade
	{ 35082,     4},// Brutal Gladiator's Salvation
	{ 35101,     7},// Brutal Gladiator's Slicer
	{ 35103,    10},// Brutal Gladiator's Staff
	{ 35109,    10},// Brutal Gladiator's War Staff
	{ 35110,     0},// Brutal Gladiator's Waraxe
	{ 35514,    10},// Frostscythe of Lord Ahune
	{ 35576,     1},// Ingvar's Monolithic Cleaver
	{ 35583,    10},// Witch Doctor's Wildstaff
	{ 35587,     4},// Frozen Scepter of Necromancy
	{ 35618,     8},// Troll Butcherer
	{ 35630,     4},// Summoner's Stone Gavel
	{ 35633,    10},// Staff of the Great Reptile
	{ 35649,    10},// Jailer's Baton
	{ 35658,    10},// Life-Staff of the Web Lair
	{ 35664,     4},// Unknown Archaeologist's Hammer
	{ 35807,    10},// Bramblethorn Greatstaff
	{ 35808,     7},// Coldstone Cutlass
	{ 35810,     4},// Pacifying Pummeler
	{ 35812,     5},// Cragthumper
	{ 35824,     7},// Stoneblade Slicer
	{ 35849,     8},// Featherweight Claymore
	{ 35870,     1},// Stoneground Cleaver
	{ 36487,     4},// Stone-Headed Gavel
	{ 36488,     4},// Conifer Club
	{ 36489,     4},// Iron Flanged Scepter
	{ 36490,     4},// Tuskarr Cudgel
	{ 36491,     4},// Serrated Maul
	{ 36492,     4},// Peaked Club
	{ 36493,     4},// Furbolg Truncheon
	{ 36494,     4},// Barbed Star
	{ 36495,     4},// Ferrous Hammer
	{ 36496,     4},// Brass-Bound Cudgel
	{ 36497,     4},// Adamant Mallet
	{ 36498,     4},// Nerubian Mace
	{ 36499,     4},// Frigid War-Mace
	{ 36500,     4},// Gargoyle's Mace
	{ 36501,     5},// Granite Maul
	{ 36502,     5},// Ungainly Mace
	{ 36503,     5},// Toothless Bludgeon
	{ 36504,     5},// Cleft-Edged Hammer
	{ 36505,     5},// Frosted Steel Mallet
	{ 36506,     5},// Vaulted Mace
	{ 36507,     5},// Iron-Molded Fist
	{ 36508,     5},// Cumbersome Sledgehammer
	{ 36509,     5},// Femur-Shafted Mace
	{ 36510,     5},// Lumbering Bludgeon
	{ 36511,     5},// Arctic War Hammer
	{ 36512,     5},// Onerous Mallet
	{ 36513,     5},// Lode-Headed Hammer
	{ 36514,     5},// Kingly Battlehammer
	{ 36515,     7},// Raider's Cutlass
	{ 36516,     7},// Tribal Blade
	{ 36517,     7},// Iron-Grip Shortsword
	{ 36518,     7},// Tundra's Edge
	{ 36519,     7},// Moonlit Katana
	{ 36520,     7},// Chopping Wideblade
	{ 36521,     7},// Shimmering Sabre
	{ 36522,     7},// Scored Blade
	{ 36523,     7},// Trollish Slicer
	{ 36524,     7},// Primitive Scimitar
	{ 36525,     7},// Craggy Machete
	{ 36526,     7},// Sleeted Longsword
	{ 36527,     7},// Blackened Blade
	{ 36528,     7},// Skeleton's Sword
	{ 36529,     8},// Unearthed Broadsword
	{ 36530,     8},// Whetted Ironblade
	{ 36531,     8},// Sawtooth Greatsword
	{ 36532,     8},// Shark Fin Blade
	{ 36533,     8},// Adorned Broadsword
	{ 36534,     8},// Tempered-Steel Blade
	{ 36535,     8},// Dragon's Rib Sword
	{ 36536,     8},// Inlaid Greatsword
	{ 36537,     8},// Fur-Grip Broadsword
	{ 36538,     8},// Trollish Destroyer
	{ 36539,     8},// Chilled Warblade
	{ 36540,     8},// Petrified Sword
	{ 36541,     8},// Wintry Claymore
	{ 36542,     8},// Invasion Blade
	{ 36543,    10},// Survival Stick
	{ 36544,    10},// Journeyed Staff
	{ 36545,    10},// Branched Stick
	{ 36546,    10},// Unusual Staff
	{ 36547,    10},// Jester's Stick
	{ 36548,    10},// Promised Staff
	{ 36549,    10},// Pulsing Quarterstaff
	{ 36550,    10},// Refulgent Staff
	{ 36551,    10},// Ritual Greatstaff
	{ 36552,    10},// Spiked Greatstaff
	{ 36553,    10},// Desecrated Staff
	{ 36554,    10},// Cursed Staff
	{ 36555,    10},// Minion Staff
	{ 36556,    10},// Apocalyptic Staff
	{ 36571,     0},// Splicing Axe
	{ 36572,     0},// Dinged Cleaver
	{ 36573,     0},// Primeval Adze
	{ 36574,     0},// Bone Cleaver
	{ 36575,     0},// Dragonflayer Hatchet
	{ 36576,     0},// Beaked Axe
	{ 36577,     0},// Disk Axe
	{ 36578,     0},// Troll Chopper
	{ 36579,     0},// Boreal Woodchopper
	{ 36580,     0},// Dire Axe
	{ 36581,     0},// Wolvar Handaxe
	{ 36582,     0},// Ice Pick
	{ 36583,     0},// Skeletal Hacker
	{ 36584,     0},// Snowy Edge
	{ 36585,     1},// Finned Battleaxe
	{ 36586,     1},// Wreaking Battleaxe
	{ 36587,     1},// Taunka Axe
	{ 36588,     1},// Burning Battleaxe
	{ 36589,     1},// Segmenting Broadaxe
	{ 36590,     1},// Bone Plate Axe
	{ 36591,     1},// Winged Axe
	{ 36592,     1},// Deforester Axe
	{ 36593,     1},// Troll Decollator
	{ 36594,     1},// Fracturing Battleaxe
	{ 36595,     1},// Planate Broadaxe
	{ 36596,     1},// Rupturing Axe
	{ 36597,     1},// Ice-Splintering Axe
	{ 36598,     1},// Scarlet Battle Axe
	{ 36599,     6},// Ocean Trident
	{ 36600,     6},// Village Scythe
	{ 36601,     6},// Patient Harpoon
	{ 36602,     6},// Rust-Covered Polearm
	{ 36603,     6},// Archaic Longspear
	{ 36604,     6},// Grizzly Glaive
	{ 36605,     6},// Wind Scythe
	{ 36606,     6},// Rugged Polearm
	{ 36607,     6},// Dwarven Halberd
	{ 36608,     6},// Piercing Glaive
	{ 36609,     6},// Abandoned Spear
	{ 36610,     6},// Plagued Pike
	{ 36611,     6},// Bleak Scythe
	{ 36612,     6},// Scourge War Spear
	{ 36683,     4},// Enshrined Mace
	{ 36684,     4},// Ambrosial Hammer
	{ 36685,     4},// Placid Lightmace
	{ 36686,     4},// Harmonious Scepter
	{ 36687,     4},// Illuminated Scepter
	{ 36688,     4},// Sacrosanct Mace
	{ 36689,     4},// Refreshing Hammer
	{ 36690,     4},// Unearthly Scepter
	{ 36691,     4},// Dignified Hammer
	{ 36692,     4},// Remedial Mace
	{ 36693,     4},// Serene Hammer
	{ 36694,     4},// Beatific Mace
	{ 36695,     4},// Dogmatic Scepter
	{ 36696,     4},// Graced Scepter
	{ 36697,    10},// Aquatic Greatstaff
	{ 36698,    10},// Conifer Cone Staff
	{ 36699,    10},// Iceberg Staff
	{ 36700,    10},// Peat Greatstaff
	{ 36701,    10},// Pine Needle Staff
	{ 36702,    10},// Melting Icestaff
	{ 36703,    10},// Tusked Greatstaff
	{ 36704,    10},// Hive Comb Staff
	{ 36705,    10},// Geyser Staff
	{ 36706,    10},// Tenacious Vine Staff
	{ 36707,    10},// Cascading Water Staff
	{ 36708,    10},// Snow Blossom Staff
	{ 36709,    10},// Crystal Woodstaff
	{ 36710,    10},// Avalanche Staff
	{ 36737,     0},// Brutal Gladiator's Hatchet
	{ 36878,    10},// Writhing Longstaff
	{ 36879,     4},// Soldier's Spiked Mace
	{ 36881,     4},// Medic's Morning Star
	{ 36883,     8},// Combatant Greatsword
	{ 36942,     8},// Frostmourne
	{ 36962,     1},// Wyrmclaw Battleaxe
	{ 36975,    10},// Malygos' Favor
	{ 36980,    10},// Hewn Sparring Quarterstaff
	{ 36984,     7},// Eternally Folded Blade
	{ 37014,     4},// Rod of Poacher Punishment
	{ 37025,     1},// Blubber Carver
	{ 37026,    10},// Spirit Channeller's Rod
	{ 37030,     5},// Blubber Grinder
	{ 37031,    10},// Zook's Walking Stick
	{ 37032,     0},// Edge of the Tuskarr
	{ 37034,     7},// Lobstrock Slicer
	{ 37039,     7},// Mrgl Blade
	{ 37041,     4},// Scepter of the Winterfin
	{ 37046,     5},// Shell Smasher
	{ 37054,     1},// Frostbiter
	{ 37060,     7},// Jeweled Coronation Sword
	{ 37065,     7},// Ymiron's Blade
	{ 37073,    10},// Hungering Greatstaff
	{ 37076,     7},// Fiery Prod
	{ 37080,     8},// Crimson Will
	{ 37081,     7},// Meathook's Slicer
	{ 37099,    10},// Sempiternal Staff
	{ 37108,     8},// Dreadlord's Blade
	{ 37112,     4},// Beguiling Scepter
	{ 37169,     4},// War Mace of Unrequited Love
	{ 37179,     7},// Infantry Assault Blade
	{ 37190,    10},// Enraged Feral Staff
	{ 37235,     7},// Crypt Lord's Deft Blade
	{ 37255,     7},// The Interrogator
	{ 37260,     0},// Cloudstrider's Waraxe
	{ 37360,    10},// Staff of Draconic Combat
	{ 37384,    10},// Staff of Wayward Principles
	{ 37401,     7},// Red Sword of Courage
	{ 37461,     6},// Tidebreaker Trident
	{ 37535,    10},// Stave of the Windborn
	{ 37536,     4},// BT57 Fast Mace2
	{ 37537,    10},// Stave of the Spiritcaller
	{ 37547,     4},// Fireborn Warhammer
	{ 37617,    10},// Staff of Sinister Claws
	{ 37653,     8},// Sword of Justice
	{ 37659,     8},// Enti's Quenched Sword
	{ 37681,     4},// Gavel of the Fleshcrafter
	{ 37721,     7},// Cursed Lich Blade
	{ 37733,     5},// Mojo Masked Crusher
	{ 37740,     4},// Brutal Gladiator's Swift Judgment
	{ 37803,    10},// Lola's Lifegiving Branch
	{ 37804,    10},// Bloodwood Greatstaff
	{ 37805,     4},// Melia's Magnificent Scepter
	{ 37806,    10},// Zabra's Misplaced Staff
	{ 37807,     7},// Lydia's Sharpened Swordbreaker
	{ 37808,     4},// Dragonjaw Mauler
	{ 37811,     1},// Captain Carver's Persuader
	{ 37812,     5},// Petrified Ironwood Smasher
	{ 37813,     6},// Banner Slicer
	{ 37848,    10},// Lightning Giant Staff
	{ 37852,     1},// Colossal Skull-Clad Cleaver
	{ 37871,     0},// The Key
	{ 37883,    10},// Staff of Trickery
	{ 38126,    10},// Frostbite Warstaff
	{ 38127,     4},// Carved Dragonbone Mace
	{ 38128,    10},// Staff of the Spiked Beast
	{ 38129,    10},// Staff of the Ley Mender
	{ 38131,    10},// Staff of Ruby Wood
	{ 38132,    10},// Moonrest Garden Stave
	{ 38133,    10},// Timeshattered Spire
	{ 38135,     4},// Mace of the Fallen Raven Priest
	{ 38137,    10},// Endurance of the Spell Warder
	{ 38141,    10},// Coldwind Scratching Pole
	{ 38143,    10},// Composite Harpyspine Staff
	{ 38146,     7},// Gleaming Iceblade
	{ 38148,     5},// Chilled Headsmasher
	{ 38152,     4},// Mace of the Violet Guardian
	{ 38154,     7},// Taigasha
	{ 38156,     1},// Battered Magnataur Dualblade
	{ 38170,     4},// Spiked Coldwind Club
	{ 38171,     5},// Battleworn Magnataur Crusher
	{ 38174,     4},// Time-Bending Smasher
	{ 38175,     7},// The Horseman's Blade
	{ 38176,     4},// Stronghold Battlemace
	{ 38178,     1},// Battlement Enforcer's Axe
	{ 38181,     8},// Warblade of the Forgotten Footman
	{ 38187,     0},// Reactive Waraxe
	{ 38195,     8},// Magister's Bane
	{ 38196,     0},// Bloodsmeared Brutalizer
	{ 38197,     1},// Mounted Boneshredder
	{ 38198,     7},// Joint-Severing Quickblade
	{ 38237,     1},// Axe of Frozen Death
	{ 38239,    10},// Tower of the Infinite Mind
	{ 38240,    10},// Staff of the Purposeful Mendicant
	{ 38244,     1},// Valorous Exterminator
	{ 38245,    10},// Crystalline Providence
	{ 38248,    10},// Torch of the Fallen Souls
	{ 38282,     8},// Bland Two-Handed Blade
	{ 38454,     4},// Warsong Punisher
	{ 38455,     4},// Hammer of the Alliance Vanguard
	{ 38468,     4},// Kalu'ak Peacebringer
	{ 38618,     5},// Hammer of Grief
	{ 39109,    10},// Branch of the Roaming Spirit
	{ 39110,    10},// Staff of Righteous Vengeance
	{ 39114,     1},// Axe of the Warlord's Demise
	{ 39115,     1},// Axe of Bloodstained Ice
	{ 39116,     5},// Grinder of Reverse Emancipation
	{ 39117,     8},// Liberator's Blade
	{ 39120,    10},// Spire of Soaring Rumination
	{ 39121,    10},// Cultist's Cauldron Stirrer
	{ 39127,     7},// Serrated Cold-Iron Slicer
	{ 39128,     7},// Yoke Slasher
	{ 39132,     7},// Sword of the Caged Mind
	{ 39136,     0},// Reanimator's Hacker
	{ 39142,     4},// Mace of Helotry
	{ 39143,     4},// Writhing Mace
	{ 39144,     4},// Twisted Hooligan Whacker
	{ 39200,     7},// Grieving Spellblade
	{ 39221,     6},// Wraith Spear
	{ 39226,     4},// Maexxna's Femur
	{ 39245,     5},// Demise
	{ 39255,    10},// Staff of the Plague Beast
	{ 39256,    10},// Sulfur Stave
	{ 39270,     7},// Hatestrike
	{ 39281,     4},// Infection Repulser
	{ 39291,     7},// Torment of the Banished
	{ 39344,     7},// Slayer of the Lifeless
	{ 39393,     8},// Claymore of Ancient Power
	{ 39394,    10},// Charmed Cierge
	{ 39417,     1},// Death's Bite
	{ 39422,    10},// Staff of the Plaguehound
	{ 39423,     4},// Hammer of the Astral Plane
	{ 39730,     7},// Widow's Fury
	{ 39758,     5},// The Jawbone
	{ 39769,     1},// Arcanite Ripper
	{ 39784,    10},// Staff of the Dutybound
	{ 39802,     8},// Crusader's Greatblade
	{ 39806,     7},// Blade of Diligence
	{ 39808,    10},// Staff of Diligence
	{ 39823,     4},// Dutybound Mace of Purity
	{ 39824,     1},// Cleaver of Diligence
	{ 39826,     7},// Bloodletter's Blade
	{ 39853,    10},// Thorny Bough of the Light
	{ 40189,     4},// Angry Dread
	{ 40208,     6},// Cryptfiend's Bite
	{ 40233,    10},// The Undeath Carrier
	{ 40244,     4},// The Impossible Dream
	{ 40264,     4},// Split Greathammer
	{ 40280,    10},// Origin of Nightmares
	{ 40300,    10},// Spire of Sunset
	{ 40336,     7},// Life and Death
	{ 40343,     8},// Armageddon
	{ 40345,     7},// Broken Promise
	{ 40348,    10},// Damnation
	{ 40384,     1},// Betrayer of Humanity
	{ 40388,    10},// Journey's End
	{ 40395,     4},// Torch of Holy Fire
	{ 40396,     7},// The Turning Tide
	{ 40402,     0},// Last Laugh
	{ 40406,     5},// Inevitable Defeat
	{ 40407,     7},// Silent Crusader
	{ 40455,    10},// Staff of Restraint
	{ 40488,     4},// Ice Spire Scepter
	{ 40489,    10},// Greatstaff of the Nexus
	{ 40491,     7},// Hailstorm
	{ 40497,     6},// Black Ice
	{ 40553,     7},// Electrified Blade
	{ 40703,     7},// Grasscutter
	{ 41181,     1},// Honed Cobalt Cleaver
	{ 41182,     7},// Savage Cobalt Slicer
	{ 41185,     4},// Furious Saronite Beatstick
	{ 41186,     7},// Corroded Saronite Edge
	{ 41187,     7},// Corroded Saronite Woundbringer
	{ 41188,     5},// Saronite Mindcrusher
	{ 41239,     7},// Sturdy Cobalt Quickblade
	{ 41240,     4},// Cobalt Tenderizer
	{ 41242,     8},// Forged Cobalt Claymore
	{ 41243,     0},// Notched Cobalt War Axe
	{ 41257,     5},// Titansteel Destroyer
	{ 41383,     4},// Titansteel Bonecrusher
	{ 41384,     4},// Titansteel Guardian
	{ 41815,     6},// Icier Barbed Spear
	{ 41816,     1},// De-Raged Waraxe
	{ 41821,    10},// Chilly Slobberknocker
	{ 41822,     4},// Screw-Sprung Fixer-Upper
	{ 41824,     4},// Crimson Cranium Crusher
	{ 41987,    10},// Staff of the Sorrowful Chieftain
	{ 42206,     0},// Savage Gladiator's Cleaver
	{ 42207,     0},// Hateful Gladiator's Cleaver
	{ 42208,     0},// Deadly Gladiator's Cleaver
	{ 42209,     0},// Furious Gladiator's Cleaver
	{ 42210,     0},// Relentless Gladiator's Cleaver
	{ 42212,     0},// Savage Gladiator's Chopper
	{ 42213,     0},// Savage Gladiator's Hacker
	{ 42214,     0},// Savage Gladiator's Waraxe
	{ 42221,     4},// Savage Gladiator's Bonecracker
	{ 42222,     4},// Savage Gladiator's Pummeler
	{ 42223,     7},// Savage Gladiator's Quickblade
	{ 42224,     7},// Savage Gladiator's Slicer
	{ 42226,     0},// Hateful Gladiator's Hacker
	{ 42227,     0},// Deadly Gladiator's Hacker
	{ 42228,     0},// Furious Gladiator's Hacker
	{ 42229,     0},// Relentless Gladiator's Hacker
	{ 42231,     0},// Hateful Gladiator's Chopper
	{ 42232,     0},// Deadly Gladiator's Chopper
	{ 42233,     0},// Furious Gladiator's Chopper
	{ 42234,     0},// Relentless Gladiator's Chopper
	{ 42236,     0},// Hateful Gladiator's Waraxe
	{ 42237,     0},// Deadly Gladiator's Waraxe
	{ 42238,     0},// Furious Gladiator's Waraxe
	{ 42274,     4},// Hateful Gladiator's Pummeler
	{ 42275,     4},// Deadly Gladiator's Pummeler
	{ 42276,     4},// Furious Gladiator's Pummeler
	{ 42277,     4},// Relentless Gladiator's Pummeler
	{ 42279,     4},// Hateful Gladiator's Bonecracker
	{ 42280,     4},// Deadly Gladiator's Bonecracker
	{ 42281,     4},// Furious Gladiator's Bonecracker
	{ 42282,     4},// Relentless Gladiator's Bonecracker
	{ 42284,     7},// Hateful Gladiator's Slicer
	{ 42285,     7},// Deadly Gladiator's Slicer
	{ 42286,     7},// Furious Gladiator's Slicer
	{ 42287,     7},// Relentless Gladiator's Slicer
	{ 42289,     7},// Hateful Gladiator's Quickblade
	{ 42290,     7},// Deadly Gladiator's Quickblade
	{ 42291,     7},// Furious Gladiator's Quickblade
	{ 42292,     7},// Relentless Gladiator's Quickblade
	{ 42294,     1},// Savage Gladiator's Decapitator
	{ 42295,     5},// Savage Gladiator's Bonegrinder
	{ 42296,     6},// Savage Gladiator's Pike
	{ 42297,     8},// Savage Gladiator's Greatsword
	{ 42316,     1},// Hateful Gladiator's Decapitator
	{ 42317,     1},// Deadly Gladiator's Decapitator
	{ 42318,     1},// Furious Gladiator's Decapitator
	{ 42319,     1},// Relentless Gladiator's Decapitator
	{ 42321,     5},// Hateful Gladiator's Bonegrinder
	{ 42322,     5},// Deadly Gladiator's Bonegrinder
	{ 42323,     5},// Furious Gladiator's Bonegrinder
	{ 42324,     5},// Relentless Gladiator's Bonegrinder
	{ 42326,     6},// Hateful Gladiator's Pike
	{ 42327,     6},// Deadly Gladiator's Pike
	{ 42328,     6},// Furious Gladiator's Pike
	{ 42329,     6},// Relentless Gladiator's Pike
	{ 42331,     8},// Hateful Gladiator's Greatsword
	{ 42332,     8},// Deadly Gladiator's Greatsword
	{ 42333,     8},// Furious Gladiator's Greatsword
	{ 42334,     8},// Relentless Gladiator's Greatsword
	{ 42344,     4},// Savage Gladiator's Gavel
	{ 42351,     4},// Hateful Gladiator's Gavel
	{ 42352,     4},// Deadly Gladiator's Gavel
	{ 42353,     4},// Furious Gladiator's Gavel
	{ 42354,     4},// Relentless Gladiator's Gavel
	{ 42356,    10},// Savage Gladiator's Battle Staff
	{ 42359,    10},// Hateful Gladiator's Battle Staff
	{ 42362,    10},// Deadly Gladiator's Battle Staff
	{ 42364,    10},// Furious Gladiator's Battle Staff
	{ 42366,    10},// Relentless Gladiator's Battle Staff
	{ 42382,    10},// Savage Gladiator's Energy Staff
	{ 42383,    10},// Hateful Gladiator's Energy Staff
	{ 42384,    10},// Deadly Gladiator's Energy Staff
	{ 42385,    10},// Furious Gladiator's Energy Staff
	{ 42386,    10},// Relentless Gladiator's Energy Staff
	{ 42388,    10},// Savage Gladiator's Staff
	{ 42389,    10},// Hateful Gladiator's Staff
	{ 42390,    10},// Deadly Gladiator's Staff
	{ 42391,    10},// Furious Gladiator's Staff
	{ 42392,    10},// Relentless Gladiator's Staff
	{ 42443,     4},// Cudgel of Saronite Justice
	{ 42786,     7},// Daschal's Serrated Blade
	{ 42794,    10},// Hardened Vine of the Mauler
	{ 42799,     8},// Snowblind Butcher
	{ 42807,     7},// Blade of the Inception
	{ 42819,     4},// Maker's Touch
	{ 42823,     4},// Ricket's Beatstick
	{ 42824,     1},// Maker's Edge
	{ 42828,    10},// Garm's Ward
	{ 42857,    10},// Thorim's Riding Crop
	{ 42859,     5},// Thorim's Crusher
	{ 42868,     4},// Hyldnir Headcracker
	{ 42943,     1},// Bloodied Arcanite Reaper
	{ 42945,     7},// Venerable Dal'Rend's Sacred Charge
	{ 42947,    10},// Dignified Headmaster's Charge
	{ 42948,     4},// Devout Aurastone Hammer
	{ 43281,     1},// Edge of Oblivion
	{ 43407,     4},// Stormstrike Mace
	{ 43409,     6},// Saliva Corroded Pike
	{ 43611,     7},// Krol Cleaver
	{ 43832,     8},// The Argent Resolve
	{ 43833,     7},// Blade of Echoes
	{ 43834,    10},// Staff of Redeemed Souls
	{ 43835,     4},// Hand of Gustav
	{ 43858,    10},// Vrykul Crusher
	{ 43871,     7},// Saronite Spellblade
	{ 43875,     0},// Axe of the Cunning
	{ 43883,     8},// Arete's Command
	{ 43885,     5},// Scourgehammer
	{ 43888,     4},// Blunt Brainwasher
	{ 43897,     0},// Frost Climber's Hatchet
	{ 43898,     0},// Icy Quick Edge
	{ 43899,     1},// Sapph's Cleaver
	{ 43916,     4},// Mace of the Final Command
	{ 43920,    10},// Growler's Intimidation
	{ 43921,    10},// Staff of Interrogation
	{ 43922,     7},// Honed Lightblade
	{ 43923,     7},// Bloodblade
	{ 43927,    10},// Wrought-Iron Staff
	{ 43929,     5},// Vile's Uglystick
	{ 44029,     7},// Quickblade of Cold Return
	{ 44052,     4},// Totemic Purification Rod
	{ 44053,     6},// Whale-Stick Harpoon
	{ 44092,     8},// Reforged Truesilver Champion
	{ 44094,     4},// The Blessed Hammer of Grace
	{ 44095,    10},// Grand Staff of Jordan
	{ 44096,     7},// Battleworn Thrash Blade
	{ 44174,    10},// Stave of Shrouded Mysteries
	{ 44187,     7},// Fang of Truth
	{ 44191,     1},// Ice-Rimed Chopper
	{ 44192,     0},// Stalactite Chopper
	{ 44199,     4},// Gavel of the Brewing Storm
	{ 44244,     5},// Argent Skeleton Crusher
	{ 44249,     8},// Runeblade of Demonstrable Power
	{ 44250,     7},// Reaper of Dark Souls
	{ 44311,     7},// Avool's Sword of Jin
	{ 44415,    10},// Savage Gladiator's War Staff
	{ 44416,    10},// Savage Gladiator's Focus Staff
	{ 44417,    10},// Hateful Gladiator's War Staff
	{ 44418,    10},// Hateful Gladiator's Focus Staff
	{ 44419,    10},// Deadly Gladiator's War Staff
	{ 44420,    10},// Deadly Gladiator's Focus Staff
	{ 44421,    10},// Furious Gladiator's War Staff
	{ 44422,    10},// Furious Gladiator's Focus Staff
	{ 44423,    10},// Relentless Gladiator's War Staff
	{ 44424,    10},// Relentless Gladiator's Focus Staff
	{ 44604,    10},// Borrowed Broom
	{ 44708,     5},// Dirkee's Superstructure
	{ 44734,     4},// Hammer of Quiet Mourning
	{ 44735,     0},// Crescent of Brooding Fury
	{ 44736,     7},// Sword of Heartwrenching Slaughter
	{ 44745,     7},// Blade of the Empty Void
	{ 44747,     4},// Hammer of Wrenching Change
	{ 44748,    10},// Stave of Youthful Sorrow
	{ 44924,     1},// Sun-Lute of the Phoenix King
	{ 45074,     8},// Claymore of the Prophet
	{ 45075,     4},// Ironforge Smasher
	{ 45076,     0},// Teldrassil Protector
	{ 45110,     7},// Titanguard
	{ 45128,    10},// Silvery Sylvan Stave
	{ 45129,     7},// Gnomeregan Bonechopper
	{ 45142,     7},// Remorse
	{ 45147,     4},// Guiding Star
	{ 45165,     1},// Worldcarver
	{ 45171,    10},// Intensity
	{ 45203,     4},// Grimhorn Crusher
	{ 45204,     0},// Axe of the Sen'jin Protector
	{ 45205,     8},// Greatsword of the Sin'dorei
	{ 45208,     7},// Blade of the Keening Banshee
	{ 45212,    10},// Staff of Feral Furies
	{ 45233,     8},// Stormrune Edge
	{ 45234,    10},// Rapture
	{ 45256,    10},// Twisted Visage
	{ 45266,     7},// Malice
	{ 45282,     5},// Ironsoul
	{ 45287,     7},// Firesoul
	{ 45298,     7},// Razorscale Talon
	{ 45311,     6},// Relentless Edge
	{ 45315,     4},// Stonerender
	{ 45331,     7},// Rune-Etched Nightblade
	{ 45437,     7},// Runescribed Blade
	{ 45442,     4},// Sorthalis, Hammer of the Watchers
	{ 45457,    10},// Staff of Endless Winter
	{ 45458,     1},// Stormedge
	{ 45463,     4},// Vulmir, the Northern Tempest
	{ 45479,    10},// The Lifebinder
	{ 45498,     6},// Lotrafen, Spear of the Damned
	{ 45516,     8},// Voldrethar, Dark Blade of Oblivion
	{ 45521,     5},// Earthshaper
	{ 45533,     6},// Dark Edge of Depravity
	{ 45575,     0},// Test Melee Rifle [PH]
	{ 45612,     4},// Constellus
	{ 45613,    10},// Dreambinder
	{ 45695,    10},// Spire of Withering Dreams
	{ 45700,     7},// Stoneguard
	{ 45868,     8},// Aesir's Edge
	{ 45876,     4},// Shiver
	{ 45886,    10},// Icecore Staff
	{ 45892,     4},// Legacy of Thunder
	{ 45934,    10},// Unraveling Reach
	{ 45947,     7},// Serilas, Blood Blade of Invar One-Arm
	{ 45948,     1},// Furious Gladiator's Sunderer
	{ 45949,     5},// Furious Gladiator's Crusher
	{ 45950,     8},// Furious Gladiator's Claymore
	{ 45951,     6},// Furious Gladiator's Halberd
	{ 45952,    10},// Furious Gladiator's Greatstaff
	{ 45953,    10},// Furious Gladiator's Combat Staff
	{ 45954,    10},// Furious Gladiator's Acute Staff
	{ 45955,    10},// Furious Gladiator's Skirmish Staff
	{ 45956,    10},// Furious Gladiator's Light Staff
	{ 45957,     0},// Furious Gladiator's Handaxe
	{ 45959,     4},// Furious Gladiator's Truncheon
	{ 45960,     7},// Furious Gladiator's Longblade
	{ 45961,     0},// Furious Gladiator's Dicer
	{ 45964,     4},// Furious Gladiator's Punisher
	{ 45965,     7},// Furious Gladiator's Swiftblade
	{ 45966,     0},// Furious Gladiator's Splitter
	{ 45971,     4},// Furious Gladiator's Salvation
	{ 45972,     4},// Pulse Baton
	{ 45990,     7},// Fusion Blade
	{ 45996,     6},// Hoperender
	{ 46016,     8},// Abaddon
	{ 46017,     4},// Val'anyr, Hammer of Ancient Kings
	{ 46025,    10},// Devotion
	{ 46031,     0},// Touch of Madness
	{ 46033,    10},// Tortured Earth
	{ 46035,     4},// Aesuga, Hand of the Ardent Champion
	{ 46036,     7},// Void Sabre
	{ 46067,     5},// Hammer of Crushing Whispers
	{ 46097,     4},// Caress of Insanity
	{ 46350,    10},// Pillar of Fortitude
	{ 46351,     4},// Bloodcrush Cudgel
	{ 46996,     0},// Lionhead Slasher
	{ 47001,     0},// Lionhead Slasher
	{ 47069,     1},// Justicebringer
	{ 47078,     1},// Justicebringer
	{ 47114,    10},// Lupine Longstaff
	{ 47130,    10},// Lupine Longstaff
	{ 47148,     0},// Stormpike Cleaver
	{ 47156,     0},// Stormpike Cleaver
	{ 47193,     4},// Misery's End
	{ 47206,     4},// Misery's End
	{ 47233,     6},// Archon Glaive
	{ 47239,     6},// Archon Glaive
	{ 47266,     0},// Blood Fury
	{ 47285,     1},// Dual-Blade Butcher
	{ 47302,    10},// Twin's Pact
	{ 47314,     0},// Hellscream Slicer
	{ 47322,     4},// Suffering's End
	{ 47329,     6},// Hellion Glaive
	{ 47427,     0},// Blood Fury
	{ 47446,     1},// Dual-Blade Butcher
	{ 47463,    10},// Twin's Pact
	{ 47475,     0},// Hellscream Slicer
	{ 47483,     4},// Suffering's End
	{ 47491,     6},// Hellion Glaive
	{ 47493,     1},// Edge of Ruin
	{ 47500,     7},// Peacekeeper Blade
	{ 47506,     7},// Silverwing Defender
	{ 47508,     4},// Aledar's Battlestar
	{ 47509,     4},// Mariel's Sorrow
	{ 47513,     7},// Orgrim's Deflector
	{ 47515,     8},// Decimation
	{ 47516,     8},// Fleshrender
	{ 47517,     7},// Blade of the Unbroken Covenant
	{ 47518,     7},// Mortalis
	{ 47519,     5},// Catastrophe
	{ 47520,     5},// Grievance
	{ 47522,     6},// Marrowstrike
	{ 47524,    10},// Clemency
	{ 47525,    10},// Sufferance
	{ 47526,     4},// Remorseless
	{ 47528,     4},// Cudgel of the Damned
	{ 47737,     8},// Reckoning
	{ 47743,    10},// Enlightenment
	{ 47808,     0},// The Lion's Maw
	{ 47809,     4},// Argent Resolve
	{ 47810,     7},// Crusader's Glory
	{ 47814,     7},// Westfall Saber
	{ 47815,    10},// Cold Convergence
	{ 47816,     4},// The Grinder
	{ 47834,     6},// Fordragon Blades
	{ 47884,     8},// Edge of Agony
	{ 47892,    10},// Illumination
	{ 47894,     4},// Mace of the Earthborn Chieftain
	{ 47898,     0},// Frostblade Hatchet
	{ 47899,     7},// Ardent Guard
	{ 47900,    10},// Perdition
	{ 47903,     7},// Forsaken Bonecarver
	{ 47905,     4},// Blackhorn Bludgeon
	{ 47911,     6},// Anguish
	{ 47951,     8},// Reckoning
	{ 47960,    10},// Enlightenment
	{ 47962,     4},// Argent Resolve
	{ 47966,     0},// The Lion's Maw
	{ 47967,     7},// Crusader's Glory
	{ 47968,    10},// Cold Convergence
	{ 47971,     7},// Westfall Saber
	{ 47973,     4},// The Grinder
	{ 47979,     6},// Fordragon Blades
	{ 48023,     8},// Edge of Agony
	{ 48036,    10},// Illumination
	{ 48039,     4},// Mace of the Earthborn Chieftain
	{ 48043,     0},// Frostblade Hatchet
	{ 48044,     7},// Ardent Guard
	{ 48045,    10},// Perdition
	{ 48048,     7},// Forsaken Bonecarver
	{ 48050,     4},// Blackhorn Bludgeon
	{ 48056,     6},// Anguish
	{ 48402,     1},// Relentless Gladiator's Sunderer
	{ 48404,     5},// Relentless Gladiator's Crusher
	{ 48406,     8},// Relentless Gladiator's Claymore
	{ 48410,    10},// Relentless Gladiator's Skirmish Staff
	{ 48412,    10},// Relentless Gladiator's Acute Staff
	{ 48414,    10},// Relentless Gladiator's Combat Staff
	{ 48426,     0},// Relentless Gladiator's Dicer
	{ 48435,     4},// Relentless Gladiator's Punisher
	{ 48438,     7},// Relentless Gladiator's Swiftblade
	{ 48440,     0},// Relentless Gladiator's Splitter
	{ 48507,     0},// Relentless Gladiator's Handaxe
	{ 48511,     4},// Relentless Gladiator's Truncheon
	{ 48513,     7},// Relentless Gladiator's Longblade
	{ 48517,     6},// Relentless Gladiator's Halberd
	{ 48519,     4},// Relentless Gladiator's Salvation
	{ 48521,    10},// Relentless Gladiator's Light Staff
	{ 48523,    10},// Relentless Gladiator's Greatstaff
	{ 48663,     4},// Tankard O' Terror
	{ 48693,     4},// Heartsmasher
	{ 48695,     1},// Mor'kosh, the Bloodreaver
	{ 48699,     4},// Blood and Glory
	{ 48701,     7},// Spellharvest
	{ 48705,    10},// Attrition
	{ 48708,     7},// Spellstorm Blade
	{ 48709,     4},// Heartcrusher
	{ 48710,    10},// Paragon's Breadth
	{ 48713,     1},// Lothar's Edge
	{ 48714,     4},// Honor of the Fallen
	{ 48716,     4},// Venerable Mass of McGowan
	{ 48718,     5},// Repurposed Lava Dredger
	{ 49128,     7},// The Horseman's Baleful Blade
	{ 49296,     7},// Singed Vis'kag the Bloodletter
	{ 49297,     0},// Empowered Deathbringer
	{ 49298,     7},// Glinting Azuresong Mageblade
	{ 49299,     8},// Keen Obsidian Edged Blade
	{ 49301,     6},// Reclaimed Thunderstrike
	{ 49302,     6},// Reclaimed Shadowstrike
	{ 49303,     7},// Gleaming Quel'Serrar
	{ 49495,     7},// Burnished Quel'Serrar
	{ 49496,     6},// Reinforced Shadowstrike
	{ 49497,     6},// Reinforced Thunderstrike
	{ 49498,     8},// Sharpened Obsidian Edged Blade
	{ 49499,     7},// Polished Azuresong Mageblade
	{ 49500,     0},// Raging Deathbringer
	{ 49501,     7},// Tempered Vis'kag the Bloodletter
	{ 49623,     1},// Shadowmourne
	{ 49783,     4},// Lucky Old Sun
	{ 49790,    10},// Blood Boil Lancet
	{ 49793,    10},// Tower of the Mouldering Corpse
	{ 49801,    10},// Unspeakable Secret
	{ 49802,     5},// Garfrost's Two-Ton Hammer
	{ 49827,     7},// Ghoulslicer
	{ 49833,     7},// Splintered Icecrown Parapet
	{ 49839,     8},// Mourning Malice
	{ 49840,     0},// Hate-Forged Cleaver
	{ 49845,     4},// Bone Golem Scapula
	{ 49888,     1},// Shadow's Edge
	{ 49919,     5},// Cryptmaker
	{ 49992,    10},// Nibelung
	{ 49997,     4},// Mithrios, Bronzebeard's Legacy
	{ 50012,     0},// Havoc's Call, Blade of Lordaeron Kings
	{ 50028,     4},// Trauma
	{ 50040,    10},// Distant Land
	{ 50046,     7},// Quel'Delar, Cunning of the Shadows
	{ 50047,     7},// Quel'Delar, Lens of the Mind
	{ 50048,     8},// Quel'Delar, Might of the Faithful
	{ 50049,     8},// Quel'Delar, Ferocity of the Scorned
	{ 50050,     4},// Cudgel of Furious Justice
	{ 50051,     4},// Hammer of Purified Flame
	{ 50052,     5},// Lightborn Spire
	{ 50068,     7},// Rigormortis
	{ 50070,     8},// Glorenzelg, High-Blade of the Silver Hand
	{ 50178,     6},// Bloodfall
	{ 50179,     4},// Last Word
	{ 50181,    10},// Dying Light
	{ 50191,     0},// Nighttime
	{ 50210,     7},// Seethe
	{ 50267,     1},// Tyrannical Beheader
	{ 50268,     7},// Rimefang's Claw
	{ 50273,    10},// Engraved Gargoyle Femur
	{ 50290,     0},// Falric's Wrist-Chopper
	{ 50296,     6},// Orca-Hunter's Harpoon
	{ 50302,     7},// Liar's Tongue
	{ 50303,     4},// Black Icicle
	{ 50411,     0},// Scourgeborne Waraxe
	{ 50412,     7},// Bloodvenom Blade
	{ 50415,     1},// Bryntroll, the Bone Arbiter
	{ 50425,     6},// Oathbinder, Charge of the Ranger-General
	{ 50427,     7},// Bloodsurge, Kel'Thuzad's Blade of Agony
	{ 50428,     4},// Royal Scepter of Terenas II
	{ 50429,    10},// Archus, Greatstaff of Antonidas
	{ 50603,     5},// Cryptmaker
	{ 50648,    10},// Nibelung
	{ 50654,     0},// Scourgeborne Waraxe
	{ 50672,     7},// Bloodvenom Blade
	{ 50685,     4},// Trauma
	{ 50695,    10},// Distant Land
	{ 50704,     7},// Rigormortis
	{ 50708,     4},// Last Word
	{ 50709,     1},// Bryntroll, the Bone Arbiter
	{ 50725,    10},// Dying Light
	{ 50727,     6},// Bloodfall
	{ 50730,     8},// Glorenzelg, High-Blade of the Silver Hand
	{ 50731,    10},// Archus, Greatstaff of Antonidas
	{ 50732,     7},// Bloodsurge, Kel'Thuzad's Blade of Agony
	{ 50734,     4},// Royal Scepter of Terenas II
	{ 50735,     6},// Oathbinder, Charge of the Ranger-General
	{ 50737,     0},// Havoc's Call, Blade of Lordaeron Kings
	{ 50738,     4},// Mithrios, Bronzebeard's Legacy
	{ 50759,     0},// Bone Warden's Splitter
	{ 50760,     4},// Bonebreaker Scepter
	{ 50761,     8},// Citadel Enforcer's Claymore
	{ 50771,     7},// Frost Needle
	{ 50787,     0},// Frost Giant's Cleaver
	{ 50798,     1},// Ramaladni's Blade of Culling
	{ 50805,    10},// Mag'hari Chieftain's Staff
	{ 50810,     4},// Gutbuster
	{ 50815,     7},// Shadowmourne Monster Offhand
	{ 50966,    10},// Abracadaver
	{ 50998,    10},// Shaft of Glacial Ice
	{ 51004,     4},// Lockjaw
	{ 51010,     7},// The Facelifter
	{ 51021,     7},// Soulbreaker
	{ 51022,     6},// Hersir's Greatspear
	{ 51388,     1},// Wrathful Gladiator's Decapitator
	{ 51389,     1},// Wrathful Gladiator's Sunderer
	{ 51390,     5},// Wrathful Gladiator's Bonegrinder
	{ 51391,     5},// Wrathful Gladiator's Crusher
	{ 51392,     8},// Wrathful Gladiator's Greatsword
	{ 51393,     8},// Wrathful Gladiator's Claymore
	{ 51400,    10},// Wrathful Gladiator's War Staff
	{ 51401,    10},// Wrathful Gladiator's Combat Staff
	{ 51402,    10},// Wrathful Gladiator's Focus Staff
	{ 51403,    10},// Wrathful Gladiator's Acute Staff
	{ 51404,    10},// Wrathful Gladiator's Battle Staff
	{ 51405,    10},// Wrathful Gladiator's Skirmish Staff
	{ 51431,    10},// Wrathful Gladiator's Staff
	{ 51432,    10},// Wrathful Gladiator's Greatstaff
	{ 51439,     0},// Wrathful Gladiator's Hacker
	{ 51440,     0},// Wrathful Gladiator's Dicer
	{ 51445,     4},// Wrathful Gladiator's Bonecracker
	{ 51446,     4},// Wrathful Gladiator's Punisher
	{ 51447,     7},// Wrathful Gladiator's Quickblade
	{ 51448,     7},// Wrathful Gladiator's Swiftblade
	{ 51453,     4},// Wrathful Gladiator's Gavel
	{ 51454,     4},// Wrathful Gladiator's Salvation
	{ 51456,    10},// Wrathful Gladiator's Energy Staff
	{ 51457,    10},// Wrathful Gladiator's Light Staff
	{ 51480,     6},// Wrathful Gladiator's Pike
	{ 51481,     6},// Wrathful Gladiator's Halberd
	{ 51515,     0},// Wrathful Gladiator's Cleaver
	{ 51516,     0},// Wrathful Gladiator's Handaxe
	{ 51519,     4},// Wrathful Gladiator's Pummeler
	{ 51520,     4},// Wrathful Gladiator's Truncheon
	{ 51521,     7},// Wrathful Gladiator's Slicer
	{ 51522,     7},// Wrathful Gladiator's Longblade
	{ 51525,     0},// Wrathful Gladiator's Chopper
	{ 51526,     0},// Wrathful Gladiator's Splitter
	{ 51562,     5},// Oxheart
	{ 51582,    10},// Sister Svalna's Aether Staff
	{ 51795,     0},// Troggbane, Axe of the Frostborne King
	{ 51796,     5},// Warmace of Menethil
	{ 51797,    10},// Tainted Twig of Nordrassil
	{ 51798,     4},// Valius, Gavel of the Lightbringer
	{ 51799,    10},// Halion, Staff of Forgotten Love
	{ 51828,    10},// Sister Svalna's Aether Staff
	{ 51833,     5},// Oxheart
	{ 51857,     6},// Hersir's Greatspear
	{ 51858,     7},// Soulbreaker
	{ 51869,     7},// The Facelifter
	{ 51875,     4},// Lockjaw
	{ 51881,    10},// Shaft of Glacial Ice
	{ 51887,    10},// Abracadaver
	{ 51893,     4},// Gutbuster
	{ 51898,    10},// Mag'hari Chieftain's Staff
	{ 51905,     1},// Ramaladni's Blade of Culling
	{ 51916,     0},// Frost Giant's Cleaver
	{ 51932,     7},// Frost Needle
	{ 51936,     8},// Citadel Enforcer's Claymore
	{ 51937,     4},// Bonebreaker Scepter
	{ 51938,     0},// Bone Warden's Splitter
	{ 51943,    10},// Halion, Staff of Forgotten Love
	{ 51944,     4},// Valius, Gavel of the Lightbringer
	{ 51945,    10},// Tainted Twig of Nordrassil
	{ 51946,     5},// Warmace of Menethil
	{ 51947,     0},// Troggbane, Axe of the Frostborne King
	{ 54553,     8},// Kliklak's Fearsome Greatsword
	{ 54806,    10},// Frostscythe of Lord Ahune
	{ 55043,     0},// Decapitator's Razor
	{ 55046,     4},// Lifeforce Hammer
	{ 55052,     8},// Obsidium Executioner
	{ 55065,     4},// Elementium Hammer
	{ 55066,     6},// Elementium Poleaxe
	{ 55067,     0},// Elementium Bonesplitter
	{ 55203,     0},// Lightning Whelk Axe
	{ 55228,    10},// Cerith Spire Staff
	{ 55246,     6},// Obsidium Bladespear
	{ 55252,     1},// Whitefin Axe
	{ 55281,     0},// Razorwind Axe
	{ 55282,     0},// Steelspark Axe
	{ 55283,     0},// Angerfang Axe
	{ 55284,     0},// Nethergarde Axe
	{ 55285,     0},// Splinterspear Axe
	{ 55286,     0},// Mardenholde Axe
	{ 55287,     0},// Bladefist Axe
	{ 55288,     0},// Irontree Axe
	{ 55289,     0},// Rustmaul Axe
	{ 55290,     1},// Razorwind Broadaxe
	{ 55291,     1},// Steelspark Broadaxe
	{ 55292,     1},// Angerfang Broadaxe
	{ 55293,     1},// Nethergarde Broadaxe
	{ 55294,     1},// Splinterspear Broadaxe
	{ 55295,     1},// Mardenholde Broadaxe
	{ 55296,     1},// Bladefist Broadaxe
	{ 55297,     1},// Irontree Broadaxe
	{ 55298,     1},// Rustmaul Broadaxe
	{ 55335,    10},// Razorwind Staff
	{ 55336,    10},// Steelspark Staff
	{ 55337,    10},// Angerfang Staff
	{ 55338,    10},// Nethergarde Staff
	{ 55339,    10},// Splinterspear Staff
	{ 55340,    10},// Mardenholde Staff
	{ 55341,    10},// Bladefist Staff
	{ 55342,    10},// Irontree Staff
	{ 55343,    10},// Rustmaul Staff
	{ 55362,     4},// Moonbrook Scepter
	{ 55363,     4},// Swamplight Scepter
	{ 55364,     4},// Sishir Scepter
	{ 55365,     4},// Mirkfallon Scepter
	{ 55366,     4},// Nethander Scepter
	{ 55367,     4},// Mereldar Scepter
	{ 55368,     4},// Thondroril Scepter
	{ 55369,     4},// Blackwolf Scepter
	{ 55370,     4},// Sorrowmurk Scepter
	{ 55380,     4},// Razorwind Mace
	{ 55381,     4},// Steelspark Mace
	{ 55382,     4},// Angerfang Mace
	{ 55383,     4},// Nethergarde Mace
	{ 55384,     4},// Splinterspear Mace
	{ 55385,     4},// Mardenholde Mace
	{ 55386,     4},// Bladefist Mace
	{ 55387,     4},// Irontree Mace
	{ 55388,     4},// Rustmaul Mace
	{ 55389,     5},// Razorwind Hammer
	{ 55390,     5},// Steelspark Hammer
	{ 55391,     5},// Angerfang Hammer
	{ 55392,     5},// Nethergarde Hammer
	{ 55393,     5},// Splinterspear Hammer
	{ 55394,     5},// Mardenholde Hammer
	{ 55395,     5},// Bladefist Hammer
	{ 55396,     5},// Irontree Hammer
	{ 55397,     5},// Rustmaul Hammer
	{ 55407,     6},// Razorwind Spear
	{ 55408,     6},// Steelspark Spear
	{ 55409,     6},// Angerfang Spear
	{ 55410,     6},// Nethergarde Spear
	{ 55411,     6},// Splinterspear Spear
	{ 55412,     6},// Mardenholde Spear
	{ 55413,     6},// Bladefist Spear
	{ 55414,     6},// Irontree Spear
	{ 55415,     6},// Rustmaul Spear
	{ 55443,    10},// Razorwind Staff
	{ 55444,    10},// Steelspark Staff
	{ 55445,    10},// Angerfang Staff
	{ 55446,    10},// Nethergarde Staff
	{ 55447,    10},// Splinterspear Staff
	{ 55448,    10},// Mardenholde Staff
	{ 55449,    10},// Bladefist Staff
	{ 55450,    10},// Irontree Staff
	{ 55451,    10},// Rustmaul Staff
	{ 55452,     7},// Razorwind Sword
	{ 55453,     7},// Steelspark Sword
	{ 55454,     7},// Angerfang Sword
	{ 55455,     7},// Nethergarde Sword
	{ 55456,     7},// Splinterspear Sword
	{ 55457,     7},// Mardenholde Sword
	{ 55458,     7},// Bladefist Sword
	{ 55459,     7},// Irontree Sword
	{ 55460,     7},// Rustmaul Sword
	{ 55461,     8},// Razorwind Greatsword
	{ 55462,     8},// Steelspark Greatsword
	{ 55463,     8},// Angerfang Greatsword
	{ 55464,     8},// Nethergarde Greatsword
	{ 55465,     8},// Splinterspear Greatsword
	{ 55466,     8},// Mardenholde Greatsword
	{ 55467,     8},// Bladefist Greatsword
	{ 55468,     8},// Irontree Greatsword
	{ 55469,     8},// Rustmaul Greatsword
	{ 55777,     4},// Torturer's Mercy
	{ 55789,    10},// Berto's Staff
	{ 55811,     8},// Sword of the Bottomless Pit
	{ 55813,     7},// Elementium Fang
	{ 55815,    10},// Darkling Staff
	{ 55822,     4},// Heavy Geode Mace
	{ 55841,     0},// Axe of the Eclipse
	{ 55860,     6},// Seliza's Spear
	{ 55865,     7},// Resonant Kris
	{ 55875,     4},// Hammer of Sparks
	{ 56004,     6},// Talons of the Storm Crow
	{ 56097,    10},// Soul Releaser
	{ 56101,     7},// Sun Strike
	{ 56108,     7},// Blade of the Burning Sun
	{ 56130,     4},// Mace of Transformed Bone
	{ 56131,     5},// Wild Hammer
	{ 56137,    10},// Staff of Siphoned Essences
	{ 56266,     0},// Lightning Whelk Axe
	{ 56271,    10},// Cerith Spire Staff
	{ 56284,     1},// Whitefin Axe
	{ 56312,     4},// Torturer's Mercy
	{ 56325,    10},// Berto's Staff
	{ 56342,     8},// Sword of the Bottomless Pit
	{ 56343,    10},// Darkling Staff
	{ 56346,     7},// Elementium Fang
	{ 56353,     4},// Heavy Geode Mace
	{ 56364,     0},// Axe of the Eclipse
	{ 56382,     6},// Seliza's Spear
	{ 56384,     7},// Resonant Kris
	{ 56396,     4},// Hammer of Sparks
	{ 56424,    10},// Soul Releaser
	{ 56430,     7},// Sun Strike
	{ 56433,     7},// Blade of the Burning Sun
	{ 56456,     5},// Wild Hammer
	{ 56459,     4},// Mace of Transformed Bone
	{ 56461,    10},// Staff of Siphoned Essences
	{ 57292,    10},// Repurposed Twilight Stave
	{ 57294,     8},// Poisonfire Greatsword
	{ 57304,     4},// Druidic Channeler's Mace
	{ 57305,     0},// Axe of Grounded Flame
	{ 57329,     7},// Firestorm Hackblade
	{ 57337,    10},// Heraldcall Censer
	{ 57339,     5},// Heartcrush Greathammer
	{ 57350,    10},// Kindleprotector Staff
	{ 57365,     4},// Crusher of Bonds
	{ 57865,     4},// Scepter of Power
	{ 57872,     4},// Scepter of Power
	{ 57928,     0},// Windslicer
	{ 57929,     7},// Dawnblaze Blade
	{ 59330,     1},// Shalug'doom, the Axe of Unmaking
	{ 59333,     7},// Lava Spine
	{ 59347,     4},// Mace of Acrid Death
	{ 59443,     0},// Crul'korak, the Lightning's Arc
	{ 59459,     4},// Andoros, Fist of the Dragon King
	{ 59462,     0},// Maimgor's Bite
	{ 59463,     7},// Maldo's Sword Cane
	{ 59474,    10},// Malevolence
	{ 59492,     5},// Akirus the Worm-Breaker
	{ 59521,     7},// Soul Blade
	{ 59525,    10},// Chelley's Staff of Dark Mending
	{ 59611,     5},// Grimhorn Pummeler
	{ 59612,     7},// Darkspear Ritual Blade
	{ 59614,     5},// Draenic Shacklebreaker
	{ 59615,     7},// Gnomeregan Mindslicer
	{ 59622,    10},// Remora-Crusher Staff
	{ 59625,    10},// Remora-Crusher Staff
	{ 59647,     8},// Captain Verne's Splitter
	{ 59650,     8},// Glovaal's Choppink Svord
	{ 59655,     7},// Eel Cutter
	{ 59658,     7},// Eel Cutter
	{ 59681,    10},// Staff of Post-Facto Preparation
	{ 59684,    10},// Staff of Post-Facto Preparation
	{ 59729,     4},// Pocket-Sized Mace
	{ 59732,     4},// Prototype Chemical Applicator
	{ 59743,     6},// Beakless Polearm
	{ 59746,     6},// Beakless Polearm
	{ 59757,     4},// Sambino's Old Hammer
	{ 59778,    10},// Medusoid Staff
	{ 59798,     1},// Barnacle-Coated Greataxe
	{ 59807,     0},// Legionnaire Nazgrim's Hacker
	{ 59810,     0},// Captain Taylor's Chopper
	{ 61324,     0},// Vicious Gladiator's Cleaver
	{ 61325,     0},// Vicious Gladiator's Hacker
	{ 61326,     1},// Vicious Gladiator's Decapitator
	{ 61335,     4},// Vicious Gladiator's Pummeler
	{ 61336,     4},// Vicious Gladiator's Bonecracker
	{ 61338,     4},// Vicious Gladiator's Gavel
	{ 61339,     5},// Vicious Gladiator's Bonegrinder
	{ 61340,     6},// Vicious Gladiator's Pike
	{ 61341,    10},// Vicious Gladiator's Battle Staff
	{ 61342,    10},// Vicious Gladiator's Energy Staff
	{ 61343,    10},// Vicious Gladiator's Staff
	{ 61344,     7},// Vicious Gladiator's Slicer
	{ 61345,     7},// Vicious Gladiator's Quickblade
	{ 61346,     8},// Vicious Gladiator's Greatsword
	{ 61398,     1},// Axe of Earthly Sundering
	{ 61402,     0},// Riftrent Waraxe
	{ 61403,    10},// Spire of Defiance
	{ 61404,     6},// Blacksoul Polearm
	{ 61420,     7},// Dragonsaw Boneblade
	{ 61465,     4},// Geomancer's Mace
	{ 61478,     5},// Energon Greatmace
	{ 61486,    10},// Breathpipe
	{ 61493,     0},// Questioning Axe
	{ 62063,     5},// Shattered War Mace
	{ 62064,     8},// Warped Greatsword
	{ 62065,     1},// Melted Cleaver
	{ 62067,     4},// Flamewashed Mace
	{ 62070,     0},// Rusted Timber Axe
	{ 62071,     7},// Corroded Blade
	{ 62072,    10},// Robble's Wobbly Staff
	{ 62454,     8},// Blade of the Fearless
	{ 62455,     6},// Spear of Trailing Shadows
	{ 62457,     0},// Ravening Slicer
	{ 62458,    10},// Insidious Staff
	{ 62459,     4},// Shimmering Morningstar
	{ 62473,     8},// Blade of the Fearless
	{ 62474,     6},// Spear of Trailing Shadows
	{ 62476,     0},// Ravening Slicer
	{ 62477,    10},// Insidious Staff
	{ 62478,     4},// Shimmering Morningstar
	{ 63445,     1},// Arced War Axe
	{ 63461,    10},// Staff of Isolation
	{ 63533,     7},// Fang of Twilight
	{ 63679,     8},// Reclaimed Ashkandi, Greatsword of the Brotherhood
	{ 63680,     4},// Twilight's Hammer
	{ 63787,     8},// Oversized Oblique Ogre Obliterator
	{ 63788,     0},// Calder's Coated Carrion Carver
	{ 63789,    10},// Very Manly Staff
	{ 63790,     4},// Gurgthock's Garish Gorebat
	{ 63799,     4},// Mace of the Gullet
	{ 63803,    10},// Torth-Slayer's Staff
	{ 63804,     4},// Dragonscorn Mace
	{ 63808,    10},// Staff of Draconic Pacification
	{ 63817,     4},// Keg Smasher
	{ 63820,     4},// Barrel Opener
	{ 64377,     8},// Zin'rokh, Destroyer of Worlds
	{ 64460,     0},// Nifflevar Bearded Axe
	{ 64489,    10},// Staff of Sorcerer-Thane Thaurissan
	{ 64695,    10},// Bloodthirsty Gladiator's Battle Staff
	{ 64700,     4},// Bloodthirsty Gladiator's Bonecracker
	{ 64701,     5},// Bloodthirsty Gladiator's Bonegrinder
	{ 64717,     0},// Bloodthirsty Gladiator's Cleaver
	{ 64726,     1},// Bloodthirsty Gladiator's Decapitator
	{ 64744,    10},// Bloodthirsty Gladiator's Energy Staff
	{ 64752,     4},// Bloodthirsty Gladiator's Gavel
	{ 64755,     8},// Bloodthirsty Gladiator's Greatsword
	{ 64758,     0},// Bloodthirsty Gladiator's Hacker
	{ 64810,     6},// Bloodthirsty Gladiator's Pike
	{ 64816,     4},// Bloodthirsty Gladiator's Pummeler
	{ 64817,     7},// Bloodthirsty Gladiator's Quickblade
	{ 64858,     7},// Bloodthirsty Gladiator's Slicer
	{ 64860,    10},// Bloodthirsty Gladiator's Staff
	{ 64880,    10},// Staff of Ammunae
	{ 64885,     7},// Scimitar of the Sirocco
	{ 65003,     8},// Reclaimed Ashkandi, Greatsword of the Brotherhood
	{ 65007,     5},// Akirus the Worm-Breaker
	{ 65013,     7},// Maldo's Sword Cane
	{ 65014,     0},// Maimgor's Bite
	{ 65017,     4},// Andoros, Fist of the Dragon King
	{ 65024,     0},// Crul'korak, the Lightning's Arc
	{ 65036,     4},// Mace of Acrid Death
	{ 65047,     7},// Lava Spine
	{ 65090,     4},// Twilight's Hammer
	{ 65094,     7},// Fang of Twilight
	{ 65102,    10},// Chelley's Staff of Dark Mending
	{ 65103,     7},// Soul Blade
	{ 65139,    10},// Malevolence
	{ 65145,     1},// Shalug'doom, the Axe of Unmaking
	{ 65164,     7},// Cruel Barb
	{ 65165,     5},// Foe Reaper
	{ 65166,     7},// Buzz Saw
	{ 65167,    10},// Emberstone Staff
	{ 65168,     1},// Rockslicer
	{ 65170,     0},// Smite's Reaver
	{ 65171,     4},// Cookie's Tenderizer
	{ 65173,     7},// Thief's Blade
	{ 65667,     4},// Shovel of Mercy
	{ 65795,     0},// Vir'naal Guardsman's Axe
	{ 65799,    10},// Ihsenn's Staff of Terror
	{ 65808,     6},// Orsis Polearm
	{ 65816,     5},// Ramkahen Ceremonial Hammer
	{ 65844,     4},// Tombbreaker Mace
	{ 65851,    10},// Officer's Formal Baton
	{ 66916,     7},// Delicate Blade of Meaning
	{ 66940,    10},// Staff of Solemn Secrecy
	{ 66952,     0},// Belmont's Vampire Hacker
	{ 66960,     7},// Dirk's Command
	{ 66964,     6},// Sand Tracker's Spear
	{ 66978,     8},// Rage-Possessed Greatsword
	{ 66981,     0},// Axe of the Deadly Price
	{ 66985,     1},// Termination Axe
	{ 66990,     4},// Downfall Hammer
	{ 66993,     5},// Sorrow's End
	{ 67029,     4},// Death Pyre Mace
	{ 67052,     7},// Loyal Blade
	{ 67071,    10},// Staff of Old Woes
	{ 67098,    10},// Sealing Heartstaff
	{ 67120,     4},// Mace of Apotheosis
	{ 67153,     6},// Mobus's Vile Halberd
	{ 67243,     5},// Armagedillo's Tail
	{ 67447,     8},// Vicious Gladiator's Greatsword
	{ 67448,    10},// Vicious Gladiator's Staff
	{ 67449,    10},// Vicious Gladiator's Energy Staff
	{ 67450,    10},// Vicious Gladiator's Battle Staff
	{ 67451,     6},// Vicious Gladiator's Pike
	{ 67452,     5},// Vicious Gladiator's Bonegrinder
	{ 67453,     1},// Vicious Gladiator's Decapitator
	{ 67454,     4},// Vicious Gladiator's Gavel
	{ 67468,     7},// Vicious Gladiator's Quickblade
	{ 67469,     7},// Vicious Gladiator's Slicer
	{ 67470,     4},// Vicious Gladiator's Bonecracker
	{ 67471,     4},// Vicious Gladiator's Pummeler
	{ 67473,     0},// Vicious Gladiator's Hacker
	{ 67474,     0},// Vicious Gladiator's Cleaver
	{ 67602,     0},// Elementium Gutslicer
	{ 67605,     5},// Forged Elementium Mindcrusher
	{ 68050,     4},// Shatterscale Mightfish
	{ 68127,     7},// Stormwake, the Tempest's Reach
	{ 68128,     7},// Stormwake, the Tempest's Reach
	{ 68129,     7},// Stormwake, the Tempest's Reach
	{ 68130,     7},// Stormwake, the Tempest's Reach
	{ 68131,     7},// Stormwake, the Tempest's Reach
	{ 68132,     7},// Stormwake, the Tempest's Reach
	{ 68161,     7},// Krol Decapitator
	{ 68739,     0},// Darkheart Hacker
	{ 68740,     0},// Darkheart Hacker
	{ 69575,     4},// Mace of the Sacrificed
	{ 69581,     4},// Amani Scepter of Rites
	{ 69592,     1},// Reforged Trollbane
	{ 69609,     7},// Bloodlord's Protector
	{ 69618,     7},// Zulian Slasher
	{ 69624,    10},// Legacy of Arlokk
	{ 69626,    10},// Jin'do's Verdict
	{ 69628,     5},// Jeklik's Smasher
	{ 69639,     7},// Renataki's Soul Slicer
	{ 69771,    10},// Frostscythe of Lord Ahune
	{ 69803,     4},// Gurubashi Punisher
	{ 69814,     4},// Bug Test Heirloom Weapon
	{ 69843,     6},// Mobus's Dripping Halberd
	{ 69893,     7},// Bloodsoaked Skullforge Reaver
	{ 69897,    10},// Fandral's Flamescythe
	{ 69916,     1},// Trollbane (Daakara)
	{ 70080,     7},// Reforged Heartless
	{ 70157,     4},// Lightforged Elementium Hammer
	{ 70158,     0},// Elementium-Edged Scalper
	{ 70162,     7},// Pyrium Spellward
	{ 70163,     7},// Unbreakable Guardian
	{ 70164,     8},// Masterwork Elementium Deathblade
	{ 70165,     6},// Witch-Hunter's Harvester
	{ 70178,     8},// Ruthless Gladiator's Greatsword
	{ 70179,    10},// Ruthless Gladiator's Staff
	{ 70180,    10},// Ruthless Gladiator's Energy Staff
	{ 70181,    10},// Ruthless Gladiator's Battle Staff
	{ 70182,     6},// Ruthless Gladiator's Pike
	{ 70183,     5},// Ruthless Gladiator's Bonegrinder
	{ 70184,     1},// Ruthless Gladiator's Decapitator
	{ 70185,     4},// Ruthless Gladiator's Gavel
	{ 70199,     7},// Ruthless Gladiator's Quickblade
	{ 70200,     7},// Ruthless Gladiator's Slicer
	{ 70201,     4},// Ruthless Gladiator's Bonecracker
	{ 70202,     4},// Ruthless Gladiator's Pummeler
	{ 70204,     0},// Ruthless Gladiator's Hacker
	{ 70205,     0},// Ruthless Gladiator's Cleaver
	{ 70211,     0},// Ruthless Gladiator's Cleaver
	{ 70212,     0},// Ruthless Gladiator's Hacker
	{ 70213,     1},// Ruthless Gladiator's Decapitator
	{ 70221,     4},// Ruthless Gladiator's Pummeler
	{ 70222,     4},// Ruthless Gladiator's Bonecracker
	{ 70223,     4},// Ruthless Gladiator's Gavel
	{ 70224,     5},// Ruthless Gladiator's Bonegrinder
	{ 70225,     6},// Ruthless Gladiator's Pike
	{ 70226,    10},// Ruthless Gladiator's Battle Staff
	{ 70227,    10},// Ruthless Gladiator's Energy Staff
	{ 70228,    10},// Ruthless Gladiator's Staff
	{ 70229,     7},// Ruthless Gladiator's Slicer
	{ 70230,     7},// Ruthless Gladiator's Quickblade
	{ 70231,     8},// Ruthless Gladiator's Greatsword
	{ 70723,     5},// Sulfuras, the Extinguished Hand
	{ 70922,     7},// Mandible of Beth'tilac
	{ 71006,     7},// Volcanospike
	{ 71014,     1},// Skullstealer Greataxe
	{ 71039,    10},// Funeral Pyre
	{ 71084,    10},// Branch of Nordrassil
	{ 71085,    10},// Runestaff of Nordrassil
	{ 71086,    10},// Dragonwrath, Tarecgosa's Rest
	{ 71312,     0},// Gatecrasher
	{ 71325,     7},// The Horseman's Sinister Saber
	{ 71332,     4},// Tremendous Tankard O' Terror
	{ 71352,     5},// Sulfuras, the Extinguished Hand
	{ 71355,     4},// Ko'gun, Hammer of the Firelord
	{ 71360,    10},// Spire of Scarlet Pain
	{ 71361,     6},// Ranseur of Hatred
	{ 71362,     0},// Obsidium Cleaver
	{ 71406,     7},// Mandible of Beth'tilac
	{ 71409,    10},// Funeral Pyre
	{ 71422,     7},// Volcanospike
	{ 71445,     1},// Skullstealer Greataxe
	{ 71454,     0},// Gatecrasher
	{ 71466,    10},// Fandral's Flamescythe
	{ 71557,     6},// Ranseur of Hatred
	{ 71559,    10},// Spire of Scarlet Pain
	{ 71562,     0},// Obsidium Cleaver
	{ 71615,     4},// Ko'gun, Hammer of the Firelord
	{ 71774,    10},// Smoldering Censer of Purity
	{ 71775,    10},// Smoldering Censer of Purity
	{ 71776,     0},// Eye of Purification
	{ 71777,     0},// Eye of Purification
	{ 71780,     8},// Zoid's Firelit Greatsword
	{ 71781,     8},// Zoid's Firelit Greatsword
	{ 71782,     4},// Shatterskull Bonecrusher
	{ 71783,     4},// Shatterskull Bonecrusher
	{ 71784,     7},// Firethorn Mindslicer
	{ 71785,     7},// Firethorn Mindslicer
	{ 71797,    10},// Sho'ravon, Greatstaff of Annihilation
	{ 71798,    10},// Sho'ravon, Greatstaff of Annihilation
	{ 72804,     4},// Dragonshrine Scepter
	{ 72808,    10},// Jaina's Staff
	{ 72812,     0},// Crescent Moon
	{ 72814,     1},// Axe of the Tauren Chieftains
	{ 72827,     4},// Gavel of Peroth'arn
	{ 72828,     0},// Trickster's Edge
	{ 72833,     4},// Scepter of Azshara
	{ 72844,     5},// Pit Lord's Destroyer
	{ 72846,    10},// Thornwood Staff
	{ 72863,    10},// Stalk of Corruption
	{ 72866,     7},// Treachery's Bite
	{ 72980,     7},// Valiant Sword
	{ 72981,     7},// Zealous Sword
	{ 72989,     4},// Zealous Scepter
	{ 72990,     5},// Ebonsoul Hammer
	{ 72991,     5},// Ebonsoul Maul
	{ 72992,     8},// Valiant Greatsword
	{ 72993,     8},// Zealous Greatsword
	{ 72994,     7},// Ebonsoul Blade
	{ 72997,     7},// Shadowstalking Sword
	{ 72998,     4},// Stormbinder Mace
	{ 72999,     5},// Valiant Maul
	{ 73001,     6},// Beastsoul Spear
	{ 73002,     4},// Stormbinder Scepter
	{ 73003,     4},// Stormbinder Gavel
	{ 73006,    10},// Magesoul Staff
	{ 73007,    10},// Dreadsoul Staff
	{ 73008,    10},// Seraphic Staff
	{ 73009,    10},// Seraphic Stave
	{ 73010,    10},// Wildsoul Stave
	{ 73011,    10},// Wildsoul Staff
	{ 73012,     6},// Wildsoul Spear
	{ 73414,     7},// Cataclysmic Gladiator's Slicer
	{ 73415,     4},// Cataclysmic Gladiator's Bonecracker
	{ 73416,     0},// Cataclysmic Gladiator's Hacker
	{ 73423,     6},// Cataclysmic Gladiator's Pike
	{ 73424,    10},// Cataclysmic Gladiator's Energy Staff
	{ 73426,     4},// Cataclysmic Gladiator's Gavel
	{ 73429,    10},// Cataclysmic Gladiator's Staff
	{ 73433,    10},// Cataclysmic Gladiator's Battle Staff
	{ 73439,     7},// Cataclysmic Gladiator's Quickblade
	{ 73440,     4},// Cataclysmic Gladiator's Pummeler
	{ 73441,     0},// Cataclysmic Gladiator's Cleaver
	{ 73442,     8},// Cataclysmic Gladiator's Greatsword
	{ 73443,     5},// Cataclysmic Gladiator's Bonegrinder
	{ 73444,     1},// Cataclysmic Gladiator's Decapitator
	{ 73447,     7},// Cataclysmic Gladiator's Slicer
	{ 73448,     4},// Cataclysmic Gladiator's Bonecracker
	{ 73449,     0},// Cataclysmic Gladiator's Hacker
	{ 73456,     6},// Cataclysmic Gladiator's Pike
	{ 73457,    10},// Cataclysmic Gladiator's Energy Staff
	{ 73459,     4},// Cataclysmic Gladiator's Gavel
	{ 73462,    10},// Cataclysmic Gladiator's Staff
	{ 73466,    10},// Cataclysmic Gladiator's Battle Staff
	{ 73472,     7},// Cataclysmic Gladiator's Quickblade
	{ 73473,     4},// Cataclysmic Gladiator's Pummeler
	{ 73474,     0},// Cataclysmic Gladiator's Cleaver
	{ 73475,     8},// Cataclysmic Gladiator's Greatsword
	{ 73476,     5},// Cataclysmic Gladiator's Bonegrinder
	{ 73477,     1},// Cataclysmic Gladiator's Decapitator
	{ 76175,     7},// Monster - Shivan 1 Sword
	{ 76176,     7},// Monster - Alizabal Sword
	{ 77188,     0},// No'Kaled, the Elements of Death
	{ 77190,    10},// Ti'tahk, the Steps of Time
	{ 77191,     8},// Gurthalak, Voice of the Deeps
	{ 77193,     7},// Souldrinker
	{ 77194,     6},// Kiril, Fury of Beasts
	{ 77196,     4},// Maw of the Dragonlord
	{ 77212,     0},// Hand of Morchok
	{ 77214,     4},// Vagaries of Time
	{ 77217,     1},// Experimental Specimen Slicer
	{ 77218,    10},// Spire of Coagulated Globules
	{ 77221,    10},// Lightning Rod
	{ 77223,     4},// Morningstar of Heroic Will
	{ 77224,     5},// Ataraxis, Cudgel of the Warmaster
	{ 77225,    10},// Visage of the Destroyer
	{ 78363,     4},// Vagaries of Time
	{ 78371,     0},// Hand of Morchok
	{ 78379,     0},// Hand of Morchok
	{ 78383,     4},// Vagaries of Time
	{ 78401,    10},// Spire of Coagulated Globules
	{ 78403,     1},// Experimental Specimen Slicer
	{ 78407,    10},// Spire of Coagulated Globules
	{ 78409,     1},// Experimental Specimen Slicer
	{ 78418,    10},// Lightning Rod
	{ 78426,    10},// Lightning Rod
	{ 78429,     4},// Morningstar of Heroic Will
	{ 78437,     4},// Morningstar of Heroic Will
	{ 78445,     5},// Ataraxis, Cudgel of the Warmaster
	{ 78451,    10},// Visage of the Destroyer
	{ 78453,     5},// Ataraxis, Cudgel of the Warmaster
	{ 78459,    10},// Visage of the Destroyer
	{ 78472,     0},// No'Kaled, the Elements of Death
	{ 78473,     6},// Kiril, Fury of Beasts
	{ 78476,     4},// Maw of the Dragonlord
	{ 78477,    10},// Ti'tahk, the Steps of Time
	{ 78478,     8},// Gurthalak, Voice of the Deeps
	{ 78479,     7},// Souldrinker
	{ 78481,     0},// No'Kaled, the Elements of Death
	{ 78482,     6},// Kiril, Fury of Beasts
	{ 78485,     4},// Maw of the Dragonlord
	{ 78486,    10},// Ti'tahk, the Steps of Time
	{ 78487,     8},// Gurthalak, Voice of the Deeps
	{ 78488,     7},// Souldrinker
	{ 78878,     7},// Spine of the Thousand Cuts
	{ 79131,    10},// Burnished Warden Staff
	{ 79339,    10},// Rain Poppy Staff
	{ 79340,    10},// Inscribed Crane Staff
	{ 79341,    10},// Inscribed Serpent Staff
	{ 79342,    10},// Ghost Iron Staff
	{ 79343,    10},// Inscribed Tiger Staff
	{ 80211,     7},// Enchanting Test Sword
	{ 80788,    10},// Jinyu Meditation Staff
	{ 80789,    10},// Jinyu Divining Rod
	{ 80790,    10},// Jinyu Combat Staff
	{ 80791,     8},// Jinyu Greatsword
	{ 80792,     0},// Jinyu Handaxe
	{ 80794,     0},// Jinyu Battleaxe
	{ 80795,     4},// Jinyu Ritual Scepter
	{ 80797,     4},// Jinyu Combat Mace
	{ 80798,     1},// Greataxe of Honor
	{ 80799,     7},// Sword of Honor
	{ 80803,     4},// Mace of Honor
	{ 80873,     0},// Dubious Handaxe
	{ 80874,    10},// Staff of Trembling Will
	{ 80883,     0},// Crescent of Ichor
	{ 80892,     7},// Ook's Hozen Slicer
	{ 80894,     4},// Gao's Keg Tapper
	{ 80932,     4},// Carapace Breaker
	{ 80936,     5},// Warmace of Taran Zhu
	{ 80937,    10},// Snowdrift's Bladed Staff
	{ 80972,     4},// Land Claimer's Cudgel
	{ 80973,    10},// Staff of the Mist Navigator
	{ 80974,    10},// Staff of Rolling Thunder
	{ 80975,     0},// Stormcaller's Spellaxe
	{ 80976,    10},// Trench Medic's Staff
	{ 80977,     0},// Shock Trooper's Battleaxe
	{ 80978,     5},// Standard Bearer's War Cudgel
	{ 80979,     4},// Foe Flattening Warhammer
	{ 80980,     0},// Axe of Aborted Deforestation
	{ 80983,     0},// Extravagant Tree Chopper
	{ 80984,     1},// Expropriator's Greataxe
	{ 81061,     7},// Ook's Hozen Slicer
	{ 81062,     4},// Gao's Keg Tapper
	{ 81063,     0},// Dubious Handaxe
	{ 81079,    10},// Staff of Trembling Will
	{ 81089,     0},// Crescent of Ichor
	{ 81094,     4},// Carapace Breaker
	{ 81107,     5},// Warmace of Taran Zhu
	{ 81108,    10},// Snowdrift's Bladed Staff
	{ 81140,    10},// Wort Stirring Rod
	{ 81247,     6},// Ghostheart
	{ 81273,     7},// Siege-Captain's Scimitar
	{ 81288,    10},// Gustwalker Staff
	{ 81544,     6},// Marista Halberd
	{ 81545,     8},// Marista Blade
	{ 81546,     7},// Cloudfall Sword
	{ 81548,     4},// Marista Mace
	{ 81549,     0},// Marista Axe
	{ 81551,     4},// Cloudfall Mace
	{ 81552,     8},// Red Crane Sword
	{ 81553,     7},// Crane Temple Blade
	{ 81576,    10},// Firestorm Greatstaff
	{ 81577,     8},// Lightbreaker Greatsword
	{ 81671,    10},// Faded Forest Meditation Staff
	{ 81672,    10},// Faded Forest Diviner's Rod
	{ 81673,    10},// Faded Forest Combat Staff
	{ 81674,     5},// Faded Forest Battlemace
	{ 81675,     0},// Faded Forest Handaxe
	{ 81677,     7},// Faded Forest Saber
	{ 81678,     4},// Faded Forest Scepter
	{ 81680,     4},// Faded Forest Smasher
	{ 81681,     8},// Faded Forest Greatsword
	{ 81682,     4},// Faded Forest Mace
	{ 81686,     0},// Faded Forest Axe
	{ 81691,    10},// Greatstaff of Righteousness
	{ 81697,     1},// The Gleaming Ravager
	{ 81703,     8},// Glorenzelg, High-Blade of the Silver Hand
	{ 81846,     6},// Fran's Spear
	{ 81847,     1},// Gardener's Axe
	{ 81848,     0},// Fran's Handaxe
	{ 81850,     4},// Gardener's Mace
	{ 81851,     4},// Fran's Golden Mace
	{ 81853,     4},// Fran's Bronze Mace
	{ 81854,     1},// Mushan Chopper
	{ 81855,     7},// Darkhide Blade
	{ 82000,     8},// Polished Greatsword
	{ 82001,     7},// Polished Sword
	{ 82002,    10},// Polished Staff
	{ 82006,     6},// Polished Spear
	{ 82008,     5},// Polished Hammer
	{ 82009,     4},// Polished Mace
	{ 82011,     4},// Intricate Scepter
	{ 82014,    10},// Polished Staff
	{ 82019,     1},// Polished Broadaxe
	{ 82020,     0},// Polished Axe
	{ 82045,     0},// Bronzed Axe
	{ 82047,     1},// Bronzed Broadaxe
	{ 82050,     8},// Bronzed Greatsword
	{ 82052,     5},// Bronzed Hammer
	{ 82055,     4},// Bronzed Mace
	{ 82056,     6},// Bronzed Spear
	{ 82057,    10},// Bronzed Staff
	{ 82058,    10},// Bronzed Staff
	{ 82059,     7},// Bronzed Sword
	{ 82064,     4},// Gemmed Scepter
	{ 82100,     0},// Barbarian Axe
	{ 82102,     1},// Barbarian Broadaxe
	{ 82105,     8},// Barbarian Greatsword
	{ 82107,     5},// Barbarian Hammer
	{ 82110,     4},// Barbarian Mace
	{ 82111,     6},// Barbarian Spear
	{ 82112,    10},// Barbarian Staff
	{ 82113,    10},// Barbarian Staff
	{ 82114,     7},// Barbarian Sword
	{ 82119,     4},// Shamanic Scepter
	{ 82155,     0},// Rigid Axe
	{ 82157,     1},// Rigid Broadaxe
	{ 82160,     8},// Rigid Greatsword
	{ 82162,     5},// Rigid Hammer
	{ 82165,     4},// Rigid Mace
	{ 82166,     6},// Rigid Spear
	{ 82167,    10},// Rigid Staff
	{ 82168,    10},// Rigid Staff
	{ 82169,     7},// Rigid Sword
	{ 82174,     4},// Grummle Scepter
	{ 82210,     0},// Inlaid Axe
	{ 82212,     1},// Inlaid Broadaxe
	{ 82215,     8},// Inlaid Greatsword
	{ 82217,     5},// Inlaid Hammer
	{ 82220,     4},// Inlaid Mace
	{ 82221,     6},// Inlaid Spear
	{ 82222,    10},// Inlaid Staff
	{ 82223,    10},// Inlaid Staff
	{ 82224,     7},// Inlaid Sword
	{ 82229,     4},// Bejeweled Scepter
	{ 82265,     0},// Engraved Axe
	{ 82267,     1},// Engraved Broadaxe
	{ 82270,     8},// Engraved Greatsword
	{ 82272,     5},// Engraved Hammer
	{ 82275,     4},// Engraved Mace
	{ 82276,     6},// Engraved Spear
	{ 82277,    10},// Engraved Staff
	{ 82278,    10},// Engraved Staff
	{ 82279,     7},// Engraved Sword
	{ 82284,     4},// Immaculate Scepter
	{ 82589,     4},// Ordo Mace
	{ 82591,     6},// Wind's Rest Spear
	{ 82592,     1},// Warbringer's Axe
	{ 82593,     7},// Wind Blade
	{ 82595,     7},// Wind's Edge
	{ 82596,     0},// Ordo Handaxe
	{ 82598,     4},// Fireblaze Clobberer
	{ 82599,     8},// Shomi's Greatsword
	{ 82600,     4},// Shomi's Mace
	{ 82604,     0},// Shomi's Axe
	{ 82706,    10},// Mountainscaler Meditation Staff
	{ 82707,    10},// Mountainscaler Diviner's Rod
	{ 82708,    10},// Mountainscaler Combat Staff
	{ 82709,     5},// Mountainscaler Battlemace
	{ 82710,     0},// Mountainscaler Handaxe
	{ 82712,     7},// Mountainscaler Saber
	{ 82713,     4},// Mountainscaler Scepter
	{ 82715,     4},// Mountainscaler Smasher
	{ 82716,     8},// Mountainscaler Greatsword
	{ 82717,     4},// Mountainscaler Mace
	{ 82721,     0},// Mountainscaler Axe
	{ 82814,     5},// Mograine's Immaculate Might
	{ 82822,     8},// Gravetouch Greatsword
	{ 82824,     1},// Goresoaked Headreaper
	{ 82859,    10},// Headmaster's Will
	{ 82963,     0},// Forgewire Axe
	{ 82964,     7},// Ghost-Forged Blade
	{ 82965,     4},// Phantasmal Hammer
	{ 82966,     1},// Spiritblade Decimator
	{ 82970,     0},// Masterwork Forgewire Axe
	{ 82971,     7},// Masterwork Ghost-Forged Blade
	{ 82972,     4},// Masterwork Phantasmal Hammer
	{ 82973,     1},// Masterwork Spiritblade Decimator
	{ 83260,    10},// Wasteland Meditation Staff
	{ 83261,    10},// Wasteland Diviner's Rod
	{ 83262,    10},// Wasteland Combat Staff
	{ 83263,     5},// Wasteland Battlemace
	{ 83264,     0},// Wasteland Handaxe
	{ 83266,     7},// Wasteland Saber
	{ 83267,     4},// Wasteland Scepter
	{ 83269,     4},// Wasteland Smasher
	{ 83270,     8},// Wasteland Greatsword
	{ 83271,     4},// Wasteland Mace
	{ 83275,     0},// Wasteland Axe
	{ 83746,    10},// Torch of Noon
	{ 83747,    10},// Torch of Dawn
	{ 83748,    10},// Torch of Dusk
	{ 83749,     5},// Hatred's Vise
	{ 83750,     7},// Sha-Blighted Blade
	{ 83752,     7},// Hatred's Bite
	{ 83753,     0},// Dividing Edge
	{ 83755,     4},// Bearheart's Club
	{ 83756,     5},// Sumprush Mace
	{ 83757,     7},// Halcyon Death
	{ 84085,    10},// Dreadwaste Meditation Staff
	{ 84086,    10},// Dreadwaste Diviner's Rod
	{ 84087,    10},// Kyparitic Staff
	{ 84088,     5},// Kyparitic Clawmace
	{ 84089,     0},// Axe of the Rikkitun
	{ 84091,     4},// Obelisk of the Rikkitun
	{ 84092,     0},// Boggeo's Ritual Axe
	{ 84095,     1},// Bloodseeker's Axe
	{ 84096,     4},// Bloodseeker's Mace
	{ 84251,    10},// Staff of Inner Focus
	{ 84252,    10},// Instructor's Staff
	{ 84253,    10},// Tian Monastic Staff
	{ 84254,     8},// Sword of the Lone Victor
	{ 84255,     0},// Axe of the Lone Champion
	{ 84257,     4},// Trophy of the Last Man Standing
	{ 84258,     4},// Mace of Inner Peace
	{ 84260,     4},// Mace of Serenity
	{ 84261,     1},// Axe of Sacrifice
	{ 84262,     4},// Spirit Crusher
	{ 84266,     0},// Spiritbound Axe
	{ 84527,    10},// Hidden Pass Meditation Staff
	{ 84528,     7},// Inkgill Blade
	{ 84529,     6},// Bodyguard's Halberd
	{ 84530,     8},// Swordmistress' Greatsword
	{ 84531,     7},// Swordmistress' Blade
	{ 84533,     7},// Mei's Blade
	{ 84534,     4},// Ornate Mace
	{ 84537,     8},// Binan Greatsword
	{ 84538,     7},// Binan Blade
	{ 84542,     0},// Bataari Hatchet
	{ 84700,     4},// Dreadful Gladiator's Pummeler
	{ 84701,     0},// Dreadful Gladiator's Cleaver
	{ 84702,     0},// Dreadful Gladiator's Hacker
	{ 84707,     1},// Dreadful Gladiator's Decapitator
	{ 84710,     7},// Dreadful Gladiator's Slicer
	{ 84716,     7},// Dreadful Gladiator's Quickblade
	{ 84717,     8},// Dreadful Gladiator's Greatsword
	{ 84719,     4},// Dreadful Gladiator's Bonecracker
	{ 84720,     4},// Dreadful Gladiator's Gavel
	{ 84721,     5},// Dreadful Gladiator's Bonegrinder
	{ 84722,     6},// Dreadful Gladiator's Pike
	{ 84723,    10},// Dreadful Gladiator's Battle Staff
	{ 84724,    10},// Dreadful Gladiator's Energy Staff
	{ 84725,    10},// Dreadful Gladiator's Staff
	{ 84785,     5},// Malevolent Gladiator's Bonegrinder
	{ 84786,     6},// Malevolent Gladiator's Pike
	{ 84787,    10},// Malevolent Gladiator's Battle Staff
	{ 84788,    10},// Malevolent Gladiator's Energy Staff
	{ 84789,    10},// Malevolent Gladiator's Staff
	{ 84790,     8},// Malevolent Gladiator's Greatsword
	{ 84791,     1},// Malevolent Gladiator's Decapitator
	{ 84964,     4},// Malevolent Gladiator's Pummeler
	{ 84965,     0},// Malevolent Gladiator's Cleaver
	{ 84966,     0},// Malevolent Gladiator's Hacker
	{ 84968,     7},// Malevolent Gladiator's Slicer
	{ 84969,     7},// Malevolent Gladiator's Quickblade
	{ 84970,     4},// Malevolent Gladiator's Bonecracker
	{ 84971,     4},// Malevolent Gladiator's Gavel
	{ 85107,     5},// Malevolent Gladiator's Bonegrinder
	{ 85108,     6},// Malevolent Gladiator's Pike
	{ 85109,    10},// Malevolent Gladiator's Battle Staff
	{ 85110,    10},// Malevolent Gladiator's Energy Staff
	{ 85111,    10},// Malevolent Gladiator's Staff
	{ 85112,     8},// Malevolent Gladiator's Greatsword
	{ 85113,     1},// Malevolent Gladiator's Decapitator
	{ 85130,     4},// Malevolent Gladiator's Pummeler
	{ 85131,     0},// Malevolent Gladiator's Cleaver
	{ 85132,     0},// Malevolent Gladiator's Hacker
	{ 85134,     7},// Malevolent Gladiator's Slicer
	{ 85135,     7},// Malevolent Gladiator's Quickblade
	{ 85136,     4},// Malevolent Gladiator's Bonecracker
	{ 85137,     4},// Malevolent Gladiator's Gavel
	{ 85185,     6},// Ghostheart
	{ 85428,     8},// Gold Ulduar Sword
	{ 85777,     0},// Ancient Pandaren Mining Pick
	{ 86071,     6},// Screaming Tiger, Qiang's Unbreakable Polearm
	{ 86124,     6},// Pandaren Fishing Spear
	{ 86130,     0},// Elegion, the Fanged Crescent
	{ 86140,     8},// Starshatter
	{ 86148,     4},// Tihan, Scepter of the Sleeping Emperor
	{ 86196,    10},// Ancient Jinyu Staff
	{ 86198,     5},// Hammer of Ten Thunders
	{ 86199,     7},// Jade Infused Blade
	{ 86218,    10},// Staff of the Hidden Master
	{ 86219,     7},// Scimitar of Seven Stars
	{ 86227,     4},// Kri'tak, Imperial Scepter of the Swarm
	{ 86321,    10},// Gao-Rei, Staff of the Legendary Protector
	{ 86328,     7},// Loshan, Terror Incarnate
	{ 86335,    10},// Jin'ya, Orb of the Waterspeaker
	{ 86386,     1},// Shin'ka, Execution of Dominion
	{ 86387,     7},// Kilrak, Jaws of Terror
	{ 86394,     6},// Hozen Warrior Spear
	{ 86518,     4},// Yaungol Fire Carrier
	{ 86520,     6},// Malik's Stalwart Spear
	{ 86522,     7},// Blade of the Prime
	{ 86523,     8},// Swarming Cleaver of Ka'roz
	{ 86524,    10},// Dissector's Staff of Mutation
	{ 86527,     7},// Blade of the Poisoned Mind
	{ 86777,     6},// Screaming Tiger, Qiang's Unbreakable Polearm
	{ 86789,     0},// Elegion, the Fanged Crescent
	{ 86799,     8},// Starshatter
	{ 86806,     4},// Tihan, Scepter of the Sleeping Emperor
	{ 86863,     7},// Scimitar of Seven Stars
	{ 86865,     4},// Kri'tak, Imperial Scepter of the Swarm
	{ 86879,    10},// Gao-Rei, Staff of the Legendary Protector
	{ 86886,     7},// Loshan, Terror Incarnate
	{ 86893,    10},// Jin'ya, Orb of the Waterspeaker
	{ 86905,     1},// Shin'ka, Execution of Dominion
	{ 86906,     7},// Kilrak, Jaws of Terror
	{ 86987,     7},// Scimitar of Seven Stars
	{ 86990,     4},// Kri'tak, Imperial Scepter of the Swarm
	{ 87046,     6},// Screaming Tiger, Qiang's Unbreakable Polearm
	{ 87061,     8},// Starshatter
	{ 87062,     0},// Elegion, the Fanged Crescent
	{ 87074,     4},// Tihan, Scepter of the Sleeping Emperor
	{ 87156,    10},// Gao-Rei, Staff of the Legendary Protector
	{ 87164,     7},// Loshan, Terror Incarnate
	{ 87170,    10},// Jin'ya, Orb of the Waterspeaker
	{ 87173,     7},// Kilrak, Jaws of Terror
	{ 87176,     1},// Shin'ka, Execution of Dominion
	{ 87417,    10},// Staff of Broken Hopes
	{ 87418,     5},// Lerah's Ribsmasher
	{ 87419,    10},// Kaleiki's Lost Training Staff
	{ 87420,     6},// Ritter's Rat Render
	{ 87421,     1},// Fellworth's Repetitive Greataxe
	{ 87422,    10},// Matsuba's Breadmaker
	{ 87423,     8},// Bjam's Door-Breaker
	{ 87465,     4},// Solianti's Insect Smasher
	{ 87466,     7},// Ritualistic Sickle
	{ 87510,     7},// Buc-Zakai Bugslicer
	{ 87511,     7},// Horrifying Meatsaw
	{ 87512,     4},// Porter's Tooth-Marked Mace
	{ 87513,     0},// Axe of the Iron Price
	{ 87515,     4},// Ced's Crusher
	{ 87516,     0},// Scalebreaker Axe
	{ 87523,     5},// [PH] Troll Guitar
	{ 87525,     4},// [PH] Orc Microphone
	{ 87542,     8},// Mogu'Dar, Blade of the Thousand Slaves
	{ 87544,     4},// Je'lyu, Spirit of the Serpent
	{ 87545,     0},// Inelava, Spirit of Inebriation
	{ 87561,    10},// Silver Inlaid Staff
	{ 87562,    10},// Rosethorn Staff
	{ 87565,    10},// Key to the Planes
	{ 87566,    10},// Runed Staff
	{ 87570,     7},// The Horseman's Sinister Slicer
	{ 87642,    10},// Darkstaff of Annihilation
	{ 87643,     5},// Fangcracker Battlemace
	{ 87646,     0},// Needlefang Throatripper
	{ 87649,     4},// Pool-Stirrer
	{ 87651,    10},// Pathwalker Greatstaff
	{ 87652,     4},// Ook-Breaker Mace
	{ 88150,     7},// Krol Scimitar
	{ 88622,    10},// Monastic Staff
	{ 88648,    10},// Monastic Spire
	{ 88649,     7},// Monastic Sword
	{ 88723,     6},// Sturdy Yaungol Spear
	{ 89394,     6},// Amber Spear of Klaxxi'vess
	{ 89395,    10},// Amber Scythe of Klaxxi'vess
	{ 89396,     7},// Amber Espada of Klaxxi'vess
	{ 89397,     7},// Amber Saber of Klaxxi'vess
	{ 89398,     8},// Amber Flammard of Klaxxi'vess
	{ 89400,     4},// Amber Sledge of Klaxxi'vess
	{ 89576,     6},// Bladed Staff of the Frozen Mountain
	{ 89577,     6},// Bladed Staff of the Summit's Breeze
	{ 89584,    10},// Staff of Meditation
	{ 89585,    10},// Staff of Fallen Blossoms
	{ 89586,    10},// Staff of Serenity
	{ 89606,     6},// Bladed Staff of the Echoing Gong
	{ 89685,     6},// Spear of Xuen
	{ 90010,    10},// Cranedancer's Staff
	{ 90011,    10},// Staff of the White Tigerlord
	{ 90012,    10},// Staff of Ox-Hoof Thunder
	{ 90027,     6},// Skirmisher's Spear
	{ 90028,     0},// Overseer's Handaxe
	{ 90030,     7},// Captain's Cutlass
	{ 90031,    10},// Staff of the Faithful
	{ 90032,     1},// Grunt's Greataxe
	{ 90034,    10},// Archmage's Staff
	{ 90035,     7},// Sailor's Scimitar
	{ 90118,     7},// Bland Blade
	{ 90324,     4},// Land Claimer's Cudgel
	{ 90325,    10},// Staff of the Mist Navigator
	{ 90326,    10},// Staff of Rolling Thunder
	{ 90327,     4},// Stormcaller's Warclub
	{ 90328,    10},// Trench Medic's Staff
	{ 90329,     0},// Garrosh's Vanguard Battleaxe
	{ 90330,     5},// Smoldering Gunship Strut
	{ 90331,     4},// Face Smasher Warhammer
	{ 90332,     0},// Zin'jun's Dwarf-Cleaver
	{ 90335,     4},// Hozen-Thunking Mace
	{ 90336,     1},// Gunship Armory Greataxe
	{ 90376,     4},// Barricade-Breaker Cudgel
	{ 90377,    10},// Fogcutter Staff
	{ 90378,    10},// Staff of the Skymagi
	{ 90379,     4},// Mystic Perpetual Motion Mace
	{ 90380,    10},// Skyfire Medic's Staff
	{ 90381,     0},// Shock Trooper Battleaxe
	{ 90382,     5},// Captain Rogers' Polite Knocking Stick
	{ 90383,     4},// Skyfire Trooper's Mace
	{ 90384,     0},// Peon-Chopping Axe
	{ 90387,     7},// Crashed Gyrocopter Rotor
	{ 90388,     8},// Greatsword of Kofinna Kottr
	{ 90461,     4},// Jol'Grum's Frozen Mace
	{ 90462,    10},// Liuyang's Lovely Longstaff
	{ 90463,     0},// Chagan's Cheery Chopper
	{ 90464,     8},// Satay's Stabbing Sword
	{ 90465,    10},// Scar-Shell's Scintillating Staff
	{ 90466,     4},// Maki's Mashing Mace
	{ 90805,    10},// Robble's Stabilized Staff
	{ 90806,     7},// Rusted Blade
	{ 90807,     0},// Corroded Timber Axe
	{ 90810,     4},// Fireblackened Mace
	{ 90812,     1},// Salt-Scored Cleaver
	{ 90813,     8},// Salt-Scored Greatsword
	{ 90814,     5},// Fractured War Mace
	{ 91087,     1},// Tyrannical Gladiator's Decapitator
	{ 91088,     1},// Tyrannical Gladiator's Decapitator
	{ 91089,     5},// Tyrannical Gladiator's Bonegrinder
	{ 91090,     5},// Tyrannical Gladiator's Bonegrinder
	{ 91091,     8},// Tyrannical Gladiator's Greatsword
	{ 91092,     8},// Tyrannical Gladiator's Greatsword
	{ 91093,     0},// Tyrannical Gladiator's Cleaver
	{ 91094,     0},// Tyrannical Gladiator's Cleaver
	{ 91095,     4},// Tyrannical Gladiator's Pummeler
	{ 91096,     4},// Tyrannical Gladiator's Pummeler
	{ 91097,     7},// Tyrannical Gladiator's Quickblade
	{ 91098,     7},// Tyrannical Gladiator's Quickblade
	{ 91133,    10},// Tyrannical Gladiator's Battle Staff
	{ 91134,    10},// Tyrannical Gladiator's Battle Staff
	{ 91182,    10},// Tyrannical Gladiator's Staff
	{ 91183,    10},// Tyrannical Gladiator's Staff
	{ 91203,     4},// Tyrannical Gladiator's Gavel
	{ 91204,     4},// Tyrannical Gladiator's Gavel
	{ 91207,    10},// Tyrannical Gladiator's Energy Staff
	{ 91208,    10},// Tyrannical Gladiator's Energy Staff
	{ 91307,     6},// Tyrannical Gladiator's Pike
	{ 91308,     6},// Tyrannical Gladiator's Pike
	{ 91398,     7},// Tyrannical Gladiator's Mageblade
	{ 91399,     7},// Tyrannical Gladiator's Mageblade
	{ 91404,     0},// Tyrannical Gladiator's Hacker
	{ 91405,     0},// Tyrannical Gladiator's Hacker
	{ 91406,     4},// Tyrannical Gladiator's Bonecracker
	{ 91407,     4},// Tyrannical Gladiator's Bonecracker
	{ 91408,     7},// Tyrannical Gladiator's Slicer
	{ 91409,     7},// Tyrannical Gladiator's Slicer
	{ 91440,     1},// Malevolent Gladiator's Decapitator
	{ 91442,     5},// Malevolent Gladiator's Bonegrinder
	{ 91444,     8},// Malevolent Gladiator's Greatsword
	{ 91446,     0},// Malevolent Gladiator's Cleaver
	{ 91448,     4},// Malevolent Gladiator's Pummeler
	{ 91450,     7},// Malevolent Gladiator's Quickblade
	{ 91486,    10},// Malevolent Gladiator's Battle Staff
	{ 91535,    10},// Malevolent Gladiator's Staff
	{ 91556,     4},// Malevolent Gladiator's Gavel
	{ 91560,    10},// Malevolent Gladiator's Energy Staff
	{ 91660,     6},// Malevolent Gladiator's Pike
	{ 91757,     0},// Malevolent Gladiator's Hacker
	{ 91759,     4},// Malevolent Gladiator's Bonecracker
	{ 91761,     7},// Malevolent Gladiator's Slicer
	{ 93125,     6},// Scavenged Pandaren Spear
	{ 93126,    10},// Scavenged Pandaren Staff
	{ 93127,     8},// Scavenged Pandaren Greatsword
	{ 93128,     5},// Scavenged Pandaren Hammer
	{ 93129,    10},// Scavenged Pandaren Staff
	{ 93130,     1},// Scavenged Pandaren Broadaxe
	{ 93132,     4},// Scavenged Pandaren Scepter
	{ 93136,     7},// Scavenged Pandaren Sword
	{ 93137,     4},// Scavenged Pandaren Mace
	{ 93140,     0},// Scavenged Pandaren Axe
	{ 93141,     6},// Scavenged Pandaren Spear
	{ 93142,     0},// Scavenged Pandaren Axe
	{ 93144,     4},// Scavenged Pandaren Mace
	{ 93145,     7},// Scavenged Pandaren Sword
	{ 93413,     1},// Crafted Dreadful Gladiator's Decapitator
	{ 93414,     5},// Crafted Dreadful Gladiator's Bonegrinder
	{ 93415,     8},// Crafted Dreadful Gladiator's Greatsword
	{ 93416,     0},// Crafted Dreadful Gladiator's Cleaver
	{ 93417,     4},// Crafted Dreadful Gladiator's Pummeler
	{ 93418,     7},// Crafted Dreadful Gladiator's Quickblade
	{ 93443,    10},// Crafted Dreadful Gladiator's Battle Staff
	{ 93471,    10},// Crafted Dreadful Gladiator's Staff
	{ 93482,     4},// Crafted Dreadful Gladiator's Gavel
	{ 93484,    10},// Crafted Dreadful Gladiator's Energy Staff
	{ 93549,     6},// Crafted Dreadful Gladiator's Pike
	{ 93603,     0},// Crafted Dreadful Gladiator's Hacker
	{ 93604,     4},// Crafted Dreadful Gladiator's Bonecracker
	{ 93605,     7},// Crafted Dreadful Gladiator's Slicer
	{ 93843,     1},// Hardened Arcanite Reaper
	{ 93844,    10},// Refinished Warden Staff
	{ 93845,     7},// Gore-Steeped Skullforge Reaver
	{ 93846,     5},// Re-Engineered Lava Dredger
	{ 93847,     4},// Crushing Mass of McGowan
	{ 93848,     7},// Battle-Hardened Thrash Blade
	{ 93849,    10},// Elder Staff of Jordan
	{ 93850,     4},// The Sanctified Hammer of Grace
	{ 93851,     8},// Battle-Forged Truesilver Champion
	{ 93853,     4},// Pious Aurastone Hammer
	{ 93854,    10},// Scholarly Headmaster's Charge
	{ 93856,     7},// Noble Dal'Rend's Sacred Charge
	{ 94028,     0},// Zandalari Head-Cleaver
	{ 94093,     7},// Saur-Singer Spellblade
	{ 94095,    10},// Thunder Eagle Staff
	{ 94097,    10},// Defective Soulgem Staff
	{ 94099,     0},// Corroded Hacker
	{ 94100,     1},// Weighty Stone Axe
	{ 94103,     6},// Ritual Headcleaver Halberd
	{ 94104,    10},// Sky-Shaper Staff
	{ 94212,     4},// Hex-Caster Gavel
	{ 94217,     7},// Stubby Talonblade
	{ 94302,     4},// Tyrannical Gladiator's Gavel
	{ 94304,     4},// Tyrannical Gladiator's Pummeler
	{ 94307,    10},// Tyrannical Gladiator's Staff
	{ 94310,     7},// Tyrannical Gladiator's Mageblade
	{ 94311,     8},// Tyrannical Gladiator's Greatsword
	{ 94312,     0},// Tyrannical Gladiator's Cleaver
	{ 94313,    10},// Tyrannical Gladiator's Battle Staff
	{ 94317,     0},// Tyrannical Gladiator's Hacker
	{ 94318,     7},// Tyrannical Gladiator's Slicer
	{ 94319,     6},// Tyrannical Gladiator's Pike
	{ 94320,    10},// Tyrannical Gladiator's Energy Staff
	{ 94322,     4},// Tyrannical Gladiator's Bonecracker
	{ 94323,     1},// Tyrannical Gladiator's Decapitator
	{ 94324,     5},// Tyrannical Gladiator's Bonegrinder
	{ 94325,     7},// Tyrannical Gladiator's Quickblade
	{ 94575,     0},// The Planar Edge, Reborn
	{ 94576,     1},// Lunar Crescent, Reborn
	{ 94577,     0},// Black Planar Edge, Reborn
	{ 94578,     1},// Mooncleaver, Reborn
	{ 94579,     0},// Wicked Edge of the Planes, Reborn
	{ 94580,     1},// Bloodmoon, Reborn
	{ 94581,     4},// Drakefist Hammer, Reborn
	{ 94582,     5},// Thunder, Reborn
	{ 94583,     5},// Deep Thunder, Reborn
	{ 94584,     4},// Dragonmaw, Reborn
	{ 94585,     4},// Dragonstrike, Reborn
	{ 94586,     5},// Stormherald, Reborn
	{ 94587,     7},// Fireguard, Reborn
	{ 94588,     8},// Lionheart Blade, Reborn
	{ 94589,     7},// Blazeguard, Reborn
	{ 94590,     8},// Lionheart Champion, Reborn
	{ 94591,     7},// Blazefury, Reborn
	{ 94592,     8},// Lionheart Executioner, Reborn
	{ 94707,     6},// Teng's Reach
	{ 94709,     7},// Talonblade of Akil'amon
	{ 94720,     7},// Vengeance of Kor'dok
	{ 94722,     0},// Worldbreaker's Stormscythe
	{ 94730,     7},// Soulblade of the Breaking Storm
	{ 94740,    10},// Jalak's Maelstrom Staff
	{ 94749,    10},// Dinomancer's Spiritbinding Spire
	{ 94758,     8},// Zerat, Malakk's Soulburning Greatsword
	{ 94759,     0},// Kura-Kura, Kazra'jin's Skullcleaver
	{ 94768,     0},// Shellsplitter Greataxe
	{ 94805,    10},// Giorgio's Caduceus of Pure Moods
	{ 94823,     1},// Drakkari Decapitator
	{ 94824,    10},// Gaze of Qi'nor
	{ 94825,     4},// Lightning Snare
	{ 94937,     4},// Acid-Spine Bonemace
	{ 94954,     4},// Hand of the Dark Animus
	{ 94964,     7},// Qon's Flaming Scimitar
	{ 94974,    10},// Suen-Wo, Spire of the Falling Sun
	{ 94982,     1},// Uroe, Harbinger of Terror
	{ 94983,     6},// Shan-Dun, Breaker of Hope
	{ 94988,     4},// Torall, Rod of the Shattered Throne
	{ 95391,     7},// Mantid Sky Reaver
	{ 95426,    10},// Frostscythe of Lord Ahune
	{ 95498,     6},// Bo-Ris, Horror in the Night
	{ 95499,     5},// Invocation of the Dawn
	{ 95500,     4},// Jerthud, Graceful Hand of the Savior
	{ 95502,     7},// Do-tharak, the Swordbreaker
	{ 95504,     4},// Zeeg's Ancient Kegsmasher
	{ 95505,     8},// Greatsword of Frozen Hells
	{ 95507,    10},// Darkwood Spiritstaff
	{ 95632,     0},// Worldbreaker's Stormscythe
	{ 95640,     7},// Soulblade of the Breaking Storm
	{ 95647,    10},// Jalak's Maelstrom Staff
	{ 95657,    10},// Dinomancer's Spiritbinding Spire
	{ 95666,     0},// Kura-Kura, Kazra'jin's Skullcleaver
	{ 95675,     8},// Zerat, Malakk's Soulburning Greatsword
	{ 95686,     0},// Shellsplitter Greataxe
	{ 95720,    10},// Giorgio's Caduceus of Pure Moods
	{ 95758,     4},// Acid-Spine Bonemace
	{ 95770,     4},// Hand of the Dark Animus
	{ 95790,     7},// Qon's Flaming Scimitar
	{ 95795,    10},// Suen-Wo, Spire of the Falling Sun
	{ 95803,     6},// Shan-Dun, Breaker of Hope
	{ 95809,     1},// Uroe, Harbinger of Terror
	{ 95815,     4},// Torall, Rod of the Shattered Throne
	{ 95858,     5},// Invocation of the Dawn
	{ 95861,     4},// Zeeg's Ancient Kegsmasher
	{ 95862,    10},// Darkwood Spiritstaff
	{ 95867,     4},// Jerthud, Graceful Hand of the Savior
	{ 95875,     8},// Greatsword of Frozen Hells
	{ 95876,     7},// Do-tharak, the Swordbreaker
	{ 95877,     6},// Bo-Ris, Horror in the Night
	{ 96004,     0},// Worldbreaker's Stormscythe
	{ 96012,     7},// Soulblade of the Breaking Storm
	{ 96019,    10},// Jalak's Maelstrom Staff
	{ 96029,    10},// Dinomancer's Spiritbinding Spire
	{ 96038,     0},// Kura-Kura, Kazra'jin's Skullcleaver
	{ 96047,     8},// Zerat, Malakk's Soulburning Greatsword
	{ 96058,     0},// Shellsplitter Greataxe
	{ 96092,    10},// Giorgio's Caduceus of Pure Moods
	{ 96130,     4},// Acid-Spine Bonemace
	{ 96142,     4},// Hand of the Dark Animus
	{ 96162,     7},// Qon's Flaming Scimitar
	{ 96167,    10},// Suen-Wo, Spire of the Falling Sun
	{ 96175,     6},// Shan-Dun, Breaker of Hope
	{ 96181,     1},// Uroe, Harbinger of Terror
	{ 96187,     4},// Torall, Rod of the Shattered Throne
	{ 96230,     5},// Invocation of the Dawn
	{ 96233,     4},// Zeeg's Ancient Kegsmasher
	{ 96234,    10},// Darkwood Spiritstaff
	{ 96239,     4},// Jerthud, Graceful Hand of the Savior
	{ 96247,     8},// Greatsword of Frozen Hells
	{ 96248,     7},// Do-tharak, the Swordbreaker
	{ 96249,     6},// Bo-Ris, Horror in the Night
	{ 96376,     0},// Worldbreaker's Stormscythe
	{ 96384,     7},// Soulblade of the Breaking Storm
	{ 96391,    10},// Jalak's Maelstrom Staff
	{ 96401,    10},// Dinomancer's Spiritbinding Spire
	{ 96410,     0},// Kura-Kura, Kazra'jin's Skullcleaver
	{ 96419,     8},// Zerat, Malakk's Soulburning Greatsword
	{ 96430,     0},// Shellsplitter Greataxe
	{ 96464,    10},// Giorgio's Caduceus of Pure Moods
	{ 96502,     4},// Acid-Spine Bonemace
	{ 96514,     4},// Hand of the Dark Animus
	{ 96534,     7},// Qon's Flaming Scimitar
	{ 96539,    10},// Suen-Wo, Spire of the Falling Sun
	{ 96547,     6},// Shan-Dun, Breaker of Hope
	{ 96553,     1},// Uroe, Harbinger of Terror
	{ 96559,     4},// Torall, Rod of the Shattered Throne
	{ 96602,     5},// Invocation of the Dawn
	{ 96605,     4},// Zeeg's Ancient Kegsmasher
	{ 96606,    10},// Darkwood Spiritstaff
	{ 96611,     4},// Jerthud, Graceful Hand of the Savior
	{ 96619,     8},// Greatsword of Frozen Hells
	{ 96620,     7},// Do-tharak, the Swordbreaker
	{ 96621,     6},// Bo-Ris, Horror in the Night
	{ 96748,     0},// Worldbreaker's Stormscythe
	{ 96756,     7},// Soulblade of the Breaking Storm
	{ 96763,    10},// Jalak's Maelstrom Staff
	{ 96773,    10},// Dinomancer's Spiritbinding Spire
	{ 96782,     0},// Kura-Kura, Kazra'jin's Skullcleaver
	{ 96791,     8},// Zerat, Malakk's Soulburning Greatsword
	{ 96802,     0},// Shellsplitter Greataxe
	{ 96836,    10},// Giorgio's Caduceus of Pure Moods
	{ 96874,     4},// Acid-Spine Bonemace
	{ 96886,     4},// Hand of the Dark Animus
	{ 96906,     7},// Qon's Flaming Scimitar
	{ 96911,    10},// Suen-Wo, Spire of the Falling Sun
	{ 96919,     6},// Shan-Dun, Breaker of Hope
	{ 96925,     1},// Uroe, Harbinger of Terror
	{ 96931,     4},// Torall, Rod of the Shattered Throne
	{ 96974,     5},// Invocation of the Dawn
	{ 96977,     4},// Zeeg's Ancient Kegsmasher
	{ 96978,    10},// Darkwood Spiritstaff
	{ 96983,     4},// Jerthud, Graceful Hand of the Savior
	{ 96991,     8},// Greatsword of Frozen Hells
	{ 96992,     7},// Do-tharak, the Swordbreaker
	{ 96993,     6},// Bo-Ris, Horror in the Night
	{ 97296,     4},// Kri'tak, Imperial Scepter of the Swarm
	{ 98012,    10},// Dinomancer's Spiritbinding Spire
	{ 98043,    10},// Jin'ya, Orb of the Waterspeaker
	{ 98070,    10},// Jin'ya, Orb of the Waterspeaker
	{ 98260,     6},// Immaculate Pandaren Spear
	{ 98261,    10},// Immaculate Pandaren Staff
	{ 98262,     8},// Immaculate Pandaren Greatsword
	{ 98263,     5},// Immaculate Pandaren Hammer
	{ 98264,    10},// Immaculate Pandaren Staff
	{ 98265,     1},// Immaculate Pandaren Broadaxe
	{ 98266,     6},// Immaculate Pandaren Spear
	{ 98271,     4},// Immaculate Pandaren Mace
	{ 98272,     7},// Immaculate Pandaren Sword
	{ 98273,     7},// Immaculate Pandaren Sword
	{ 98274,     4},// Immaculate Pandaren Mace
	{ 98276,     4},// Immaculate Pandaren Scepter
	{ 98278,     0},// Immaculate Pandaren Axe
	{ 98279,     0},// Immaculate Pandaren Axe
	{ 98312,     8},// Immaculate Pandaren Greatsword
	{ 98313,     5},// Immaculate Pandaren Hammer
	{ 98314,     1},// Immaculate Pandaren Broadaxe
	{ 98315,     6},// Immaculate Pandaren Spear
	{ 98316,     7},// Immaculate Pandaren Sword
	{ 98318,     0},// Immaculate Pandaren Axe
	{ 98319,    10},// Immaculate Pandaren Staff
	{ 99766,     1},// Tyrannical Gladiator's Decapitator
	{ 99767,     5},// Tyrannical Gladiator's Bonegrinder
	{ 99768,     8},// Tyrannical Gladiator's Greatsword
	{ 99769,     0},// Tyrannical Gladiator's Cleaver
	{ 99770,     4},// Tyrannical Gladiator's Pummeler
	{ 99771,     7},// Tyrannical Gladiator's Quickblade
	{ 99796,    10},// Tyrannical Gladiator's Battle Staff
	{ 99824,    10},// Tyrannical Gladiator's Staff
	{ 99835,     4},// Tyrannical Gladiator's Gavel
	{ 99837,    10},// Tyrannical Gladiator's Energy Staff
	{ 99892,     6},// Tyrannical Gladiator's Pike
	{ 99936,     7},// Tyrannical Gladiator's Mageblade
	{ 99940,     0},// Tyrannical Gladiator's Hacker
	{ 99941,     4},// Tyrannical Gladiator's Bonecracker
	{ 99942,     7},// Tyrannical Gladiator's Slicer
	{ 99963,     4},// Tyrannical Gladiator's Gavel
	{ 99965,     4},// Tyrannical Gladiator's Pummeler
	{ 99968,    10},// Tyrannical Gladiator's Staff
	{ 99971,     7},// Tyrannical Gladiator's Mageblade
	{ 99972,     8},// Tyrannical Gladiator's Greatsword
	{ 99973,     0},// Tyrannical Gladiator's Cleaver
	{ 99974,    10},// Tyrannical Gladiator's Battle Staff
	{ 99978,     0},// Tyrannical Gladiator's Hacker
	{ 99979,     7},// Tyrannical Gladiator's Slicer
	{ 99980,     6},// Tyrannical Gladiator's Pike
	{ 99981,    10},// Tyrannical Gladiator's Energy Staff
	{ 99983,     4},// Tyrannical Gladiator's Bonecracker
	{ 99984,     1},// Tyrannical Gladiator's Decapitator
	{ 99985,     5},// Tyrannical Gladiator's Bonegrinder
	{ 99986,     7},// Tyrannical Gladiator's Quickblade
	{100183,     1},// Grievous Gladiator's Decapitator
	{100184,     1},// Grievous Gladiator's Decapitator
	{100185,     5},// Grievous Gladiator's Bonegrinder
	{100186,     5},// Grievous Gladiator's Bonegrinder
	{100187,     8},// Grievous Gladiator's Greatsword
	{100188,     8},// Grievous Gladiator's Greatsword
	{100189,     0},// Grievous Gladiator's Cleaver
	{100190,     0},// Grievous Gladiator's Cleaver
	{100191,     4},// Grievous Gladiator's Pummeler
	{100192,     4},// Grievous Gladiator's Pummeler
	{100193,     7},// Grievous Gladiator's Quickblade
	{100194,     7},// Grievous Gladiator's Quickblade
	{100229,    10},// Grievous Gladiator's Battle Staff
	{100230,    10},// Grievous Gladiator's Battle Staff
	{100278,    10},// Grievous Gladiator's Staff
	{100279,    10},// Grievous Gladiator's Staff
	{100299,     4},// Grievous Gladiator's Gavel
	{100300,     4},// Grievous Gladiator's Gavel
	{100303,    10},// Grievous Gladiator's Energy Staff
	{100304,    10},// Grievous Gladiator's Energy Staff
	{100403,     6},// Grievous Gladiator's Pike
	{100404,     6},// Grievous Gladiator's Pike
	{100488,     7},// Grievous Gladiator's Mageblade
	{100489,     7},// Grievous Gladiator's Mageblade
	{100494,     0},// Grievous Gladiator's Hacker
	{100495,     0},// Grievous Gladiator's Hacker
	{100496,     4},// Grievous Gladiator's Bonecracker
	{100497,     4},// Grievous Gladiator's Bonecracker
	{100498,     7},// Grievous Gladiator's Slicer
	{100499,     7},// Grievous Gladiator's Slicer
	{100532,     4},// Grievous Gladiator's Gavel
	{100534,     4},// Grievous Gladiator's Pummeler
	{100537,    10},// Grievous Gladiator's Staff
	{100540,     7},// Grievous Gladiator's Mageblade
	{100541,     8},// Grievous Gladiator's Greatsword
	{100542,     0},// Grievous Gladiator's Cleaver
	{100543,    10},// Grievous Gladiator's Battle Staff
	{100547,     0},// Grievous Gladiator's Hacker
	{100548,     7},// Grievous Gladiator's Slicer
	{100549,     6},// Grievous Gladiator's Pike
	{100550,    10},// Grievous Gladiator's Energy Staff
	{100552,     4},// Grievous Gladiator's Bonecracker
	{100553,     1},// Grievous Gladiator's Decapitator
	{100554,     5},// Grievous Gladiator's Bonegrinder
	{100555,     7},// Grievous Gladiator's Quickblade
	{100955,     7},// Siege-Captain's Scimitar
	{100973,    10},// Gustwalker Staff
	{100976,     5},// Heart-Lesion Maul
	{100985,     7},// Heart-Lesion Blade
	{101006,     5},// Heart-Lesion Hammer
	{101019,    10},// Springrain Stave
	{101032,     6},// Springrain Spear
	{101051,    10},// Springrain Staff
	{101083,    10},// Mountainsage Staff
	{101088,    10},// Mistdancer Spire
	{101109,    10},// Mistdancer Staff
	{101112,     7},// Mistdancer Sword
	{101142,     4},// Sunsoul Scepter
	{101144,     7},// Sunsoul Sword
	{101146,     8},// Sunsoul Greatsword
	{101187,    10},// Communal Staff
	{101197,    10},// Communal Stave
	{101214,     7},// Lightdrinker Sword
	{101226,     4},// Streamtalker Gavel
	{101236,     4},// Streamtalker Mace
	{101252,     4},// Streamtalker Scepter
	{101277,    10},// Felsoul Staff
	{101278,     8},// Oathsworn Greatsword
	{101287,     5},// Oathsworn Maul
	{101288,     7},// Oathsworn Sword
	{102574,     1},// Axe of Ordos
	{102590,     4},// Prideful Gladiator's Gavel
	{102592,     4},// Prideful Gladiator's Pummeler
	{102595,    10},// Prideful Gladiator's Staff
	{102598,     7},// Prideful Gladiator's Mageblade
	{102599,     8},// Prideful Gladiator's Greatsword
	{102600,     0},// Prideful Gladiator's Cleaver
	{102601,    10},// Prideful Gladiator's Battle Staff
	{102604,     0},// Prideful Gladiator's Hacker
	{102605,     7},// Prideful Gladiator's Slicer
	{102606,     6},// Prideful Gladiator's Pike
	{102607,    10},// Prideful Gladiator's Energy Staff
	{102609,     4},// Prideful Gladiator's Bonecracker
	{102610,     1},// Prideful Gladiator's Decapitator
	{102611,     5},// Prideful Gladiator's Bonegrinder
	{102612,     7},// Prideful Gladiator's Quickblade
	{102787,     4},// Grievous Gladiator's Gavel
	{102789,     4},// Grievous Gladiator's Pummeler
	{102792,    10},// Grievous Gladiator's Staff
	{102795,     7},// Grievous Gladiator's Mageblade
	{102796,     8},// Grievous Gladiator's Greatsword
	{102797,     0},// Grievous Gladiator's Cleaver
	{102798,    10},// Grievous Gladiator's Battle Staff
	{102801,     0},// Grievous Gladiator's Hacker
	{102802,     7},// Grievous Gladiator's Slicer
	{102803,     6},// Grievous Gladiator's Pike
	{102804,    10},// Grievous Gladiator's Energy Staff
	{102806,     4},// Grievous Gladiator's Bonecracker
	{102807,     1},// Grievous Gladiator's Decapitator
	{102808,     5},// Grievous Gladiator's Bonegrinder
	{102809,     7},// Grievous Gladiator's Quickblade
	{102984,     1},// Prideful Gladiator's Decapitator
	{102985,     5},// Prideful Gladiator's Bonegrinder
	{102986,     8},// Prideful Gladiator's Greatsword
	{102987,     0},// Prideful Gladiator's Cleaver
	{102988,     4},// Prideful Gladiator's Pummeler
	{102989,     7},// Prideful Gladiator's Quickblade
	{103000,    10},// Prideful Gladiator's Battle Staff
	{103021,    10},// Prideful Gladiator's Staff
	{103030,     4},// Prideful Gladiator's Gavel
	{103032,    10},// Prideful Gladiator's Energy Staff
	{103077,     6},// Prideful Gladiator's Pike
	{103117,     7},// Prideful Gladiator's Mageblade
	{103119,     0},// Prideful Gladiator's Hacker
	{103120,     4},// Prideful Gladiator's Bonecracker
	{103121,     7},// Prideful Gladiator's Slicer
	{103139,     1},// Grievous Gladiator's Decapitator
	{103140,     5},// Grievous Gladiator's Bonegrinder
	{103141,     8},// Grievous Gladiator's Greatsword
	{103142,     0},// Grievous Gladiator's Cleaver
	{103143,     4},// Grievous Gladiator's Pummeler
	{103144,     7},// Grievous Gladiator's Quickblade
	{103169,    10},// Grievous Gladiator's Battle Staff
	{103197,    10},// Grievous Gladiator's Staff
	{103207,     4},// Grievous Gladiator's Gavel
	{103209,    10},// Grievous Gladiator's Energy Staff
	{103264,     6},// Grievous Gladiator's Pike
	{103307,     7},// Grievous Gladiator's Mageblade
	{103311,     0},// Grievous Gladiator's Hacker
	{103312,     4},// Grievous Gladiator's Bonecracker
	{103313,     7},// Grievous Gladiator's Slicer
	{103336,     1},// Prideful Gladiator's Decapitator
	{103337,     5},// Prideful Gladiator's Bonegrinder
	{103338,     8},// Prideful Gladiator's Greatsword
	{103339,     0},// Prideful Gladiator's Cleaver
	{103340,     4},// Prideful Gladiator's Pummeler
	{103341,     7},// Prideful Gladiator's Quickblade
	{103366,    10},// Prideful Gladiator's Battle Staff
	{103394,    10},// Prideful Gladiator's Staff
	{103404,     4},// Prideful Gladiator's Gavel
	{103406,    10},// Prideful Gladiator's Energy Staff
	{103461,     6},// Prideful Gladiator's Pike
	{103504,     7},// Prideful Gladiator's Mageblade
	{103508,     0},// Prideful Gladiator's Hacker
	{103509,     4},// Prideful Gladiator's Bonecracker
	{103510,     7},// Prideful Gladiator's Slicer
	{103649,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{103726,    10},// Trident of Corrupted Waters
	{103727,     4},// Encapsulated Essence of Immerseus
	{103826,     7},// Xifeng, Longblade of the Titanic Guardian
	{103869,     8},// Greatsword of Pride's Fall
	{103873,    10},// Gaze of Arrogance
	{103874,    10},// Lever of the Megantholithic Apparatus
	{103875,    10},// Drakebinder Greatstaff
	{103908,     4},// Seismic Bore
	{103926,     0},// Haromm's Frozen Crescent
	{103936,     4},// Kardris' Scepter
	{103937,     4},// Horned Mace of the Old Ones
	{103945,     5},// Gar'tok, Strength of the Faithful
	{103946,     7},// Arcweaver Spell Sword
	{103951,     0},// Malkorok's Skullcleaver
	{103952,     6},// Halberd of Inner Shadows
	{103961,     7},// Enchanted Shao-Tien Saber
	{103968,     6},// Britomart's Jagged Pike
	{103969,     4},// Siegecrafter's Forge Hammer
	{103971,     0},// Korven's Crimson Crescent
	{103972,     7},// Kil'ruk's Furious Blade
	{103974,    10},// Kor'kron Spire of Supremacy
	{104401,     7},// Hellscream's Doomblade
	{104402,     4},// Hellscream's Warmace
	{104403,     6},// Hellscream's Pig Sticker
	{104404,     0},// Hellscream's Cleaver
	{104405,     1},// Hellscream's Decapitator
	{104406,    10},// Hellscream's War Staff
	{104412,    10},// Trident of Corrupted Waters
	{104421,     4},// Encapsulated Essence of Immerseus
	{104464,     7},// Xifeng, Longblade of the Titanic Guardian
	{104479,    10},// Gaze of Arrogance
	{104483,     8},// Greatsword of Pride's Fall
	{104503,    10},// Drakebinder Greatstaff
	{104508,     4},// Seismic Bore
	{104539,     0},// Haromm's Frozen Crescent
	{104545,     4},// Kardris' Scepter
	{104554,     7},// Arcweaver Spell Sword
	{104559,     5},// Gar'tok, Strength of the Faithful
	{104564,     6},// Halberd of Inner Shadows
	{104571,     0},// Malkorok's Skullcleaver
	{104585,     7},// Enchanted Shao-Tien Saber
	{104614,     6},// Britomart's Jagged Pike
	{104618,    10},// Lever of the Megantholithic Apparatus
	{104625,     4},// Siegecrafter's Forge Hammer
	{104629,     0},// Korven's Crimson Crescent
	{104637,     7},// Kil'ruk's Furious Blade
	{104638,    10},// Kor'kron Spire of Supremacy
	{104648,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{104653,     4},// Horned Mace of the Old Ones
	{104661,    10},// Trident of Corrupted Waters
	{104670,     4},// Encapsulated Essence of Immerseus
	{104713,     7},// Xifeng, Longblade of the Titanic Guardian
	{104728,    10},// Gaze of Arrogance
	{104732,     8},// Greatsword of Pride's Fall
	{104752,    10},// Drakebinder Greatstaff
	{104757,     4},// Seismic Bore
	{104788,     0},// Haromm's Frozen Crescent
	{104794,     4},// Kardris' Scepter
	{104803,     7},// Arcweaver Spell Sword
	{104808,     5},// Gar'tok, Strength of the Faithful
	{104813,     6},// Halberd of Inner Shadows
	{104820,     0},// Malkorok's Skullcleaver
	{104834,     7},// Enchanted Shao-Tien Saber
	{104863,     6},// Britomart's Jagged Pike
	{104867,    10},// Lever of the Megantholithic Apparatus
	{104874,     4},// Siegecrafter's Forge Hammer
	{104878,     0},// Korven's Crimson Crescent
	{104886,     7},// Kil'ruk's Furious Blade
	{104887,    10},// Kor'kron Spire of Supremacy
	{104897,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{104902,     4},// Horned Mace of the Old Ones
	{104910,    10},// Trident of Corrupted Waters
	{104919,     4},// Encapsulated Essence of Immerseus
	{104962,     7},// Xifeng, Longblade of the Titanic Guardian
	{104977,    10},// Gaze of Arrogance
	{104981,     8},// Greatsword of Pride's Fall
	{105001,    10},// Drakebinder Greatstaff
	{105006,     4},// Seismic Bore
	{105037,     0},// Haromm's Frozen Crescent
	{105043,     4},// Kardris' Scepter
	{105052,     7},// Arcweaver Spell Sword
	{105057,     5},// Gar'tok, Strength of the Faithful
	{105062,     6},// Halberd of Inner Shadows
	{105069,     0},// Malkorok's Skullcleaver
	{105083,     7},// Enchanted Shao-Tien Saber
	{105112,     6},// Britomart's Jagged Pike
	{105116,    10},// Lever of the Megantholithic Apparatus
	{105123,     4},// Siegecrafter's Forge Hammer
	{105127,     0},// Korven's Crimson Crescent
	{105135,     7},// Kil'ruk's Furious Blade
	{105136,    10},// Kor'kron Spire of Supremacy
	{105146,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{105151,     4},// Horned Mace of the Old Ones
	{105159,    10},// Trident of Corrupted Waters
	{105168,     4},// Encapsulated Essence of Immerseus
	{105211,     7},// Xifeng, Longblade of the Titanic Guardian
	{105226,    10},// Gaze of Arrogance
	{105230,     8},// Greatsword of Pride's Fall
	{105250,    10},// Drakebinder Greatstaff
	{105255,     4},// Seismic Bore
	{105286,     0},// Haromm's Frozen Crescent
	{105292,     4},// Kardris' Scepter
	{105301,     7},// Arcweaver Spell Sword
	{105306,     5},// Gar'tok, Strength of the Faithful
	{105311,     6},// Halberd of Inner Shadows
	{105318,     0},// Malkorok's Skullcleaver
	{105332,     7},// Enchanted Shao-Tien Saber
	{105361,     6},// Britomart's Jagged Pike
	{105365,    10},// Lever of the Megantholithic Apparatus
	{105372,     4},// Siegecrafter's Forge Hammer
	{105376,     0},// Korven's Crimson Crescent
	{105384,     7},// Kil'ruk's Furious Blade
	{105385,    10},// Kor'kron Spire of Supremacy
	{105395,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{105400,     4},// Horned Mace of the Old Ones
	{105408,    10},// Trident of Corrupted Waters
	{105417,     4},// Encapsulated Essence of Immerseus
	{105460,     7},// Xifeng, Longblade of the Titanic Guardian
	{105475,    10},// Gaze of Arrogance
	{105479,     8},// Greatsword of Pride's Fall
	{105499,    10},// Drakebinder Greatstaff
	{105504,     4},// Seismic Bore
	{105535,     0},// Haromm's Frozen Crescent
	{105541,     4},// Kardris' Scepter
	{105550,     7},// Arcweaver Spell Sword
	{105555,     5},// Gar'tok, Strength of the Faithful
	{105560,     6},// Halberd of Inner Shadows
	{105567,     0},// Malkorok's Skullcleaver
	{105581,     7},// Enchanted Shao-Tien Saber
	{105610,     6},// Britomart's Jagged Pike
	{105614,    10},// Lever of the Megantholithic Apparatus
	{105621,     4},// Siegecrafter's Forge Hammer
	{105625,     0},// Korven's Crimson Crescent
	{105633,     7},// Kil'ruk's Furious Blade
	{105634,    10},// Kor'kron Spire of Supremacy
	{105644,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{105649,     4},// Horned Mace of the Old Ones
	{105672,     0},// Hellscream's Cleaver
	{105673,     6},// Hellscream's Pig Sticker
	{105675,     4},// Hellscream's Warmace
	{105677,    10},// Hellscream's War Staff
	{105678,     7},// Hellscream's Doomblade
	{105679,     1},// Hellscream's Decapitator
	{105685,     0},// Hellscream's Cleaver
	{105686,     6},// Hellscream's Pig Sticker
	{105688,     4},// Hellscream's Warmace
	{105690,    10},// Hellscream's War Staff
	{105691,     7},// Hellscream's Doomblade
	{105692,     1},// Hellscream's Decapitator
	{105920,     4},// Pandaren Peace Offering
	{105921,    10},// Cloudscorcher Greatstaff
	{105923,    10},// Contemplation of Shaohao
	{105925,     6},// Yak-Herder's Longstaff
	{106316,     4},// Half-Handle Mace
	{106317,     7},// Brittle Blade
	{106318,     0},// Blunt Logging Axe
	{106321,     1},// Cracked-Haft Cleaver
	{106322,     8},// Brittle Greatsword
	{106323,     5},// Poorly Balanced Warhammer
	{106324,    10},// Robble's Staff of Herding
	{107218,     4},// Tremendous Tankard O' Terror
	{107390,     4},// Obliterator Firing Lever
	{107506,     0},// Charbelching Crescent
	{107556,     4},// Rockshock Smasher
	{107646,     5},// Iron Horde Grunt's Warmace
	{107658,     6},// Thunderlord Longspear
	{108046,     1},// Draenic Steel War Axe
	{108047,     1},// Draenic Steel War Axe
	{108048,     1},// Draenic Steel War Axe
	{108049,     1},// Draenic Steel War Axe
	{108050,     7},// Draenic Steel Sword
	{108051,     7},// Draenic Steel Sword
	{108052,     7},// Draenic Steel Sword
	{108053,     7},// Draenic Steel Sword
	{108058,     4},// Draenic Steel Mace
	{108059,     4},// Draenic Steel Mace
	{108060,     4},// Draenic Steel Mace
	{108061,     4},// Draenic Steel Mace
	{108142,     1},// Hardened Draenic Steel War Axe
	{108143,     1},// Hardened Draenic Steel War Axe
	{108144,     1},// Hardened Draenic Steel War Axe
	{108145,     1},// Hardened Draenic Steel War Axe
	{108146,     7},// Hardened Draenic Steel Sword
	{108147,     7},// Hardened Draenic Steel Sword
	{108148,     7},// Hardened Draenic Steel Sword
	{108149,     7},// Hardened Draenic Steel Sword
	{108154,     4},// Hardened Draenic Steel Mace
	{108155,     4},// Hardened Draenic Steel Mace
	{108156,     4},// Hardened Draenic Steel Mace
	{108157,     4},// Hardened Draenic Steel Mace
	{108226,     1},// Peerless Draenic Steel War Axe
	{108227,     1},// Peerless Draenic Steel War Axe
	{108228,     1},// Peerless Draenic Steel War Axe
	{108229,     1},// Peerless Draenic Steel War Axe
	{108230,     7},// Peerless Draenic Steel Sword
	{108231,     7},// Peerless Draenic Steel Sword
	{108232,     7},// Peerless Draenic Steel Sword
	{108233,     7},// Peerless Draenic Steel Sword
	{108238,     4},// Peerless Draenic Steel Mace
	{108239,     4},// Peerless Draenic Steel Mace
	{108240,     4},// Peerless Draenic Steel Mace
	{108241,     4},// Peerless Draenic Steel Mace
	{108905,     8},// Jagged Turtleshell Blade
	{108909,     6},// Karabor Footman's Pike
	{108912,     8},// Karabor Greatsword
	{108914,     7},// Karabor Footman Sword
	{108918,    10},// Karabor Arcanist Rod
	{108919,     4},// Karabor Augury Mace
	{109059,     1},// Iron Executioner's Axe
	{110030,     8},// Chakram-Breaker Greatsword
	{110031,    10},// Spire of the Furious Construct
	{110032,     7},// Beakbreaker Scimitar
	{110036,     6},// Nhallish's Bloody Polearm
	{110039,    10},// Portal-Ripper's Staff
	{110040,     6},// Crushto's Neck Separator
	{110041,     0},// Roltall's Brutal Crescent
	{110042,     4},// Gug'rokk's Smasher
	{110045,    10},// Kamui's Crystalline Staff of Wizardry
	{110046,     5},// Hammer of the Soulbinder
	{110047,     7},// Soulcutter Mageblade
	{110049,     7},// Bloodblade of Teron'Gor
	{110051,     1},// Overseer's Final Word
	{110052,     4},// Scepter of Brutality
	{110054,    10},// Thunderlord Flamestaff
	{110055,     0},// Gutwrench Goreaxe
	{110057,     4},// Mindbreaker Scepter
	{110059,    10},// Chasmwrench Docking Hook
	{110689,     0},// Icebound Frost-Singer Axe
	{110784,    10},// Trident of Corrupted Waters
	{110785,     4},// Encapsulated Essence of Immerseus
	{111067,     0},// Primal Gladiator's Cleaver
	{111070,     4},// Primal Gladiator's Pummeler
	{111071,     7},// Primal Gladiator's Quickblade
	{111075,     6},// Primal Gladiator's Pike
	{111076,    10},// Primal Gladiator's Staff
	{111118,     4},// Primal Gladiator's Gavel
	{111119,     7},// Primal Gladiator's Mageblade
	{111122,    10},// Primal Gladiator's Battle Staff
	{111123,    10},// Primal Gladiator's Energy Staff
	{111198,     0},// Primal Gladiator's Hacker
	{111200,     4},// Primal Gladiator's Bonecracker
	{111201,     7},// Primal Gladiator's Slicer
	{111202,     1},// Primal Gladiator's Decapitator
	{111203,     5},// Primal Gladiator's Bonegrinder
	{111204,     8},// Primal Gladiator's Greatsword
	{111475,     5},// Beater's Beat Stick
	{111484,     7},// Cold Tusk
	{111523,     5},// Yrel's Mace
	{111526,    10},// Etched-Blade Warstaff
	{111535,     0},// Frostwolf Hand Axe
	{111536,     0},// Frostwolf Cleaver
	{111537,     1},// Frostwolf Greataxe
	{111540,    10},// Frostwolf Augury Staff
	{111541,     6},// Frostwolf Mountaineering Stick
	{111542,     4},// Frostwolf Wind-Talker Cudgel
	{111911,     6},// Thunderlord Hunting Spear
	{111912,     4},// Thunderlord Riding Crop
	{111913,     6},// Thunderlord War Spear
	{111916,     4},// Thunderlord Herding Cudgel
	{112261,     7},// Forgotten Vindicator's Blade
	{112388,     0},// Iron Horde Tomahawk
	{112389,     4},// Iron Horde Warcudgel
	{112391,     0},// Iron Horde Hatchet
	{112392,    10},// Iron Horde Ritual Staff
	{112393,     1},// Iron Horde Waraxe
	{112395,    10},// Iron Horde Bramblestaff
	{112546,     7},// Xifeng, Longblade of the Titanic Guardian
	{112579,     4},// Riverbeast Jawbone
	{112580,     5},// Ra'tok's Painhammer
	{112586,     4},// Riverbeast Femur
	{112723,    10},// Drakebinder Greatstaff
	{112736,     4},// Seismic Bore
	{112759,     0},// Haromm's Frozen Crescent
	{112769,     4},// Kardris' Scepter
	{112785,     5},// Gar'tok, Strength of the Faithful
	{112787,     7},// Arcweaver Spell Sword
	{112804,     0},// Malkorok's Skullcleaver
	{112805,     6},// Halberd of Inner Shadows
	{112835,     7},// Enchanted Shao-Tien Saber
	{112862,     6},// Britomart's Jagged Pike
	{112867,     0},// Abandoned Dark Iron Handaxe
	{112868,     1},// Abandoned Dark Iron Greataxe
	{112871,     4},// Abandoned Dark Iron Skullthumper
	{112872,     6},// Abandoned Dark Iron Glaive
	{112873,    10},// Abandoned Dark Iron Staff
	{112874,     4},// Abandoned Dark Iron Cudgel
	{112892,    10},// Lever of the Megantholithic Apparatus
	{112897,     4},// Siegecrafter's Forge Hammer
	{112920,     0},// Korven's Crimson Crescent
	{112921,     7},// Kil'ruk's Furious Blade
	{112925,     1},// Xal'atoh, Desecrated Image of Gorehowl
	{112932,    10},// Kor'kron Spire of Supremacy
	{112939,     4},// Horned Mace of the Old Ones
	{112949,     8},// Greatsword of Pride's Fall
	{112951,    10},// Gaze of Arrogance
	{113043,    10},// Telmor Crystal Staff
	{113044,    10},// Telmor Soupriest Staff
	{113045,     8},// Restalaan's Greatsword
	{113046,     5},// Vorpil's Ribsmasher
	{113047,     7},// Restalaan's Longsword
	{113048,     4},// Vorpil's Ribcrusher
	{113051,     6},// Iron Shredder Axle
	{113052,     1},// Camshaft-Haft Greatcleaver
	{113055,     0},// Serrated Sawblade Axe
	{113056,     0},// Multi-Purpose Shredder Hydraulic Lever
	{113057,     0},// Maintenance Downtime Hatchet
	{113093,     7},// Starshatter
	{113125,     0},// Singing Crystal Axe
	{113134,    10},// Crystalfire Spellstaff
	{113170,    10},// Karabor Starsinger Staff
	{113171,     5},// Karabor Warmace
	{113173,     4},// Karabor Honor Guard Mace
	{113174,     4},// Rangari Initiate Blackjack
	{113176,     4},// Karabor Anchorite Cudgel
	{113181,     0},// Karabor Honor Guard Axe
	{113182,     0},// Rangari Initiate Hatchet
	{113287,     7},// Shard of Scorn
	{113548,    10},// Darktide Summoner Staff
	{113553,     7},// Windfang Sabre
	{113559,     4},// Void Prophecy Cudgel
	{113560,     1},// Ancestral Shadowmoon Greataxe
	{113561,    10},// Staff of the Mad Bramble King
	{113606,     0},// Butcher's Bloody Cleaver
	{113607,     4},// Butcher's Terrible Tenderizer
	{113639,    10},// Spire of Tectus
	{113640,    10},// Earthwarped Bladestaff
	{113667,     0},// Phemos' Double Slasher
	{113838,     5},// Gar'tash, Hammer of the Breakers
	{113848,     8},// Gor'gah, High Blade of the Gorians
	{113857,    10},// Staff of the Grand Imperator
	{113862,     7},// Taner's Terrible Spine
	{113869,    10},// Inferno-Flame Staff
	{113886,     1},// Crescent of Living Magma
	{113897,     4},// Hans'gar's Forgehammer
	{113904,     4},// Franzok's Headsmasher
	{113913,     8},// Ka'graz's Burning Blade
	{113927,     4},// Kromog's Brutal Fist
	{113934,     7},// Fang of the Earth
	{113939,     6},// Tal'rak, Bloody Skull of the Thunderlords
	{113953,     6},// Thogar's Control Rod
	{113973,     0},// Koloch Na, the Blood Feast
	{113979,     5},// The Black Hand
	{113980,     7},// Iron Soldier's Saber
	{113988,    10},// Blackhand Doomstaff
	{114903,     7},// Talon Guard Shortblade
	{114904,     5},// Talon Guard Wingsmasher
	{114907,     0},// Talon Guard Wingclipper
	{114908,     6},// Talon Guard Glaive
	{114909,    10},// Talon Guard Staff
	{114910,     4},// Talon Guard Cudgel
	{114911,     0},// Mighty Gorian Cleaver
	{114912,     8},// Mighty Gorian Greatsword
	{114915,     7},// Mighty Gorian Shortsword
	{114916,     6},// Mighty Gorian Halberd
	{114917,    10},// Gorian Arcanist Spellstaff
	{114918,     4},// Gorian Arcanist Spiritshaker
	{115024,     0},// Primal Combatant's Cleaver
	{115027,     4},// Primal Combatant's Pummeler
	{115028,     7},// Primal Combatant's Quickblade
	{115032,     6},// Primal Combatant's Pike
	{115033,    10},// Primal Combatant's Staff
	{115065,     4},// Primal Combatant's Gavel
	{115066,     7},// Primal Combatant's Mageblade
	{115069,    10},// Primal Combatant's Battle Staff
	{115070,    10},// Primal Combatant's Energy Staff
	{115132,     0},// Primal Combatant's Hacker
	{115134,     4},// Primal Combatant's Bonecracker
	{115135,     7},// Primal Combatant's Slicer
	{115136,     1},// Primal Combatant's Decapitator
	{115137,     5},// Primal Combatant's Bonegrinder
	{115138,     8},// Primal Combatant's Greatsword
	{115292,     0},// Spectral Axe
	{115293,     1},// Spectral Greataxe
	{115296,     4},// Spectral Warmace
	{115297,     6},// Spectral Polearm
	{115298,    10},// Spectral Spire
	{115299,     4},// Spectral Scepter
	{115303,     0},// Tormented Axe
	{115304,     1},// Tormented Greataxe
	{115307,     4},// Tormented Warmace
	{115308,     6},// Tormented Polearm
	{115309,    10},// Tormented Spire
	{115310,     4},// Tormented Scepter
	{115311,     0},// Munificent Axe
	{115312,     1},// Munificent Greataxe
	{115315,     4},// Munificent Warmace
	{115316,     6},// Munificent Polearm
	{115317,    10},// Munificent Spire
	{115318,     4},// Munificent Scepter
	{115319,     0},// Turbulent Axe
	{115320,     1},// Turbulent Greataxe
	{115323,     4},// Turbulent Warmace
	{115324,     6},// Turbulent Polearm
	{115325,    10},// Turbulent Spire
	{115326,     4},// Turbulent Scepter
	{115327,     0},// Grandiose Axe
	{115328,     1},// Grandiose Greataxe
	{115331,     4},// Grandiose Warmace
	{115332,     6},// Grandiose Polearm
	{115333,    10},// Grandiose Spire
	{115334,     4},// Grandiose Scepter
	{115335,     0},// Formidable Axe
	{115336,     1},// Formidable Greataxe
	{115339,     4},// Formidable Warmace
	{115340,     6},// Formidable Polearm
	{115341,    10},// Formidable Spire
	{115342,     4},// Formidable Scepter
	{115417,     0},// Chadrik's Lost Axe
	{115418,     8},// Blood Gutter Greatsword
	{115421,     4},// Zolvolt's Shocking Mace
	{115422,     6},// Grimthorn's Fearsome Halberd
	{115423,    10},// Megana's Staff of Knowledge
	{115424,     4},// Mace of Amaranthine Power
	{115594,     0},// Primal Gladiator's Cleaver
	{115597,     4},// Primal Gladiator's Pummeler
	{115598,     7},// Primal Gladiator's Quickblade
	{115602,     6},// Primal Gladiator's Pike
	{115603,    10},// Primal Gladiator's Staff
	{115645,     4},// Primal Gladiator's Gavel
	{115646,     7},// Primal Gladiator's Mageblade
	{115649,    10},// Primal Gladiator's Battle Staff
	{115650,    10},// Primal Gladiator's Energy Staff
	{115725,     0},// Primal Gladiator's Hacker
	{115727,     4},// Primal Gladiator's Bonecracker
	{115728,     7},// Primal Gladiator's Slicer
	{115729,     1},// Primal Gladiator's Decapitator
	{115730,     5},// Primal Gladiator's Bonegrinder
	{115731,     8},// Primal Gladiator's Greatsword
	{115817,     1},// Primal Gladiator's Decapitator
	{115818,     5},// Primal Gladiator's Bonegrinder
	{115819,     8},// Primal Gladiator's Greatsword
	{115820,     0},// Primal Gladiator's Cleaver
	{115821,     4},// Primal Gladiator's Pummeler
	{115822,     7},// Primal Gladiator's Quickblade
	{115833,    10},// Primal Gladiator's Battle Staff
	{115854,    10},// Primal Gladiator's Staff
	{115863,     4},// Primal Gladiator's Gavel
	{115865,    10},// Primal Gladiator's Energy Staff
	{115910,     6},// Primal Gladiator's Pike
	{115950,     7},// Primal Gladiator's Mageblade
	{115952,     0},// Primal Gladiator's Hacker
	{115953,     4},// Primal Gladiator's Bonecracker
	{115954,     7},// Primal Gladiator's Slicer
	{116116,     8},// Blazegrease Greatsword
	{116123,     4},// Fleshrender's Painbringer
	{116126,     7},// Taladorantula Terrorfang
	{116361,     0},// Butcher's Cruel Chopper
	{116362,     4},// Shard of Crystalline Fury
	{116366,     8},// Magic-Breaker Greatsword
	{116368,     6},// Polearm of Expulsion
	{116372,    10},// Imperator's Warstaff
	{116380,     7},// Oregorger's Venomous Canine
	{116382,    10},// Spire of Pyroclastic Flame
	{116385,     4},// Magma Monsoon Mace
	{116387,     1},// Axe of the Stone Geyser
	{116389,    10},// Thogar's Imperialistic Spire
	{116391,     5},// Blackhand Forgehammer
	{116453,     1},// Steelforged Greataxe
	{116454,     7},// Steelforged Saber
	{116457,     0},// Frostbitten Axe
	{116458,     1},// Frostbitten Broadaxe
	{116465,     4},// Frostbitten Mace
	{116466,     4},// Coldsinger Scepter
	{116467,     5},// Frostbitten Hammer
	{116468,     6},// Frostbitten Spear
	{116469,    10},// Frostbitten Staff
	{116470,    10},// Frostbitten Staff
	{116471,     7},// Frostbitten Sword
	{116472,     8},// Frostbitten Greatsword
	{116474,     0},// Lunarglow Axe
	{116475,     1},// Lunarglow Broadaxe
	{116482,     4},// Lunarglow Mace
	{116483,     4},// Moonwhisper Scepter
	{116484,     5},// Lunarglow Hammer
	{116485,     6},// Lunarglow Spear
	{116486,    10},// Lunarglow Staff
	{116487,    10},// Lunarglow Staff
	{116488,     7},// Lunarglow Sword
	{116489,     8},// Lunarglow Greatsword
	{116491,     0},// Vinewrapped Axe
	{116492,     1},// Vinewrapped Broadaxe
	{116499,     4},// Vinewrapped Mace
	{116500,     4},// Growthshaper Scepter
	{116501,     5},// Vinewrapped Hammer
	{116502,     6},// Vinewrapped Spear
	{116503,    10},// Vinewrapped Staff
	{116504,    10},// Vinewrapped Staff
	{116505,     7},// Vinewrapped Sword
	{116506,     8},// Vinewrapped Greatsword
	{116508,     0},// Creeperclaw Axe
	{116509,     1},// Creeperclaw Broadaxe
	{116516,     4},// Creeperclaw Mace
	{116517,     4},// Evermorn Scepter
	{116518,     5},// Creeperclaw Hammer
	{116519,     6},// Creeperclaw Spear
	{116520,    10},// Creeperclaw Staff
	{116521,    10},// Creeperclaw Staff
	{116522,     7},// Creeperclaw Sword
	{116523,     8},// Creeperclaw Greatsword
	{116525,     0},// Incised Axe
	{116526,     1},// Incised Broadaxe
	{116533,     4},// Incised Mace
	{116534,     4},// Zangarra Scepter
	{116535,     5},// Incised Hammer
	{116536,     6},// Incised Spear
	{116537,    10},// Incised Staff
	{116538,    10},// Incised Staff
	{116539,     7},// Incised Sword
	{116540,     8},// Incised Greatsword
	{116542,     0},// Auchenai Axe
	{116543,     1},// Auchenai Broadaxe
	{116550,     4},// Auchenai Mace
	{116551,     4},// Soulkeeper Scepter
	{116552,     5},// Auchenai Hammer
	{116553,     6},// Auchenai Spear
	{116554,    10},// Auchenai Staff
	{116555,    10},// Auchenai Staff
	{116556,     7},// Auchenai Sword
	{116557,     8},// Auchenai Greatsword
	{116559,     0},// Skettis Axe
	{116560,     1},// Skettis Broadaxe
	{116567,     4},// Skettis Mace
	{116568,     4},// Sunsworn Scepter
	{116569,     5},// Skettis Hammer
	{116570,     6},// Skettis Spear
	{116571,    10},// Skettis Staff
	{116572,    10},// Skettis Staff
	{116573,     7},// Skettis Sword
	{116574,     8},// Skettis Greatsword
	{116576,     0},// Longclaw Axe
	{116577,     1},// Longclaw Broadaxe
	{116584,     4},// Longclaw Mace
	{116585,     4},// Shadowsage Scepter
	{116586,     5},// Longclaw Hammer
	{116587,     6},// Longclaw Spear
	{116588,    10},// Longclaw Staff
	{116589,    10},// Longclaw Staff
	{116590,     7},// Longclaw Sword
	{116591,     8},// Longclaw Greatsword
	{116593,     0},// Bloodmane Axe
	{116594,     1},// Bloodmane Broadaxe
	{116601,     4},// Bloodmane Mace
	{116602,     4},// Ruhkmari Scepter
	{116603,     5},// Bloodmane Hammer
	{116604,     6},// Bloodmane Spear
	{116605,    10},// Bloodmane Staff
	{116606,    10},// Bloodmane Staff
	{116607,     7},// Bloodmane Sword
	{116608,     8},// Bloodmane Greatsword
	{116610,     0},// Gorian Axe
	{116611,     1},// Gorian Broadaxe
	{116618,     4},// Gorian Mace
	{116619,     4},// Ancestral Scepter
	{116620,     5},// Gorian Hammer
	{116621,     6},// Gorian Spear
	{116622,    10},// Gorian Staff
	{116623,    10},// Gorian Staff
	{116624,     7},// Gorian Sword
	{116625,     8},// Gorian Greatsword
	{116627,     0},// Howling Axe
	{116628,     1},// Howling Broadaxe
	{116635,     4},// Howling Mace
	{116636,     4},// Oshu'gun Scepter
	{116637,     5},// Howling Hammer
	{116638,     6},// Howling Spear
	{116639,    10},// Howling Staff
	{116640,    10},// Howling Staff
	{116641,     7},// Howling Sword
	{116642,     8},// Howling Greatsword
	{116646,     4},// Steelforged Hammer
	{116688,     0},// Pokhar's Thirteenth Axe
	{116796,    10},// Malroc's Staff of Command
	{116797,     0},// Pokhar's Eighth Axe
	{116806,     7},// Soul Fang
	{116808,    10},// Whirlwind's Harvest
	{116835,     6},// Assassin's Spear
	{116837,     6},// Spooky Scythe
	{116855,     7},// Stingtail's Toxic Stinger
	{116857,    10},// Stave of Buzzing Bark
	{116913,     0},// Peon's Mining Pick
	{116918,     4},// Garrison Workman's Hammer
	{117010,     0},// Forester's Axe
	{117019,     8},// Heart-Lesion Greatsword
	{117028,     7},// Heart-Lesion Blade
	{117049,     8},// Heart-Lesion Runeblade
	{117062,    10},// Springrain Stave
	{117075,     6},// Springrain Spear
	{117094,    10},// Springrain Staff
	{117126,    10},// Mountainsage Staff
	{117131,    10},// Mistdancer Spire
	{117152,    10},// Mistdancer Staff
	{117155,     7},// Mistdancer Sword
	{117185,     4},// Sunsoul Scepter
	{117187,     7},// Sunsoul Sword
	{117189,     5},// Sunsoul Warmaul
	{117230,    10},// Communal Staff
	{117240,    10},// Communal Stave
	{117257,     7},// Lightdrinker Sword
	{117320,    10},// Felsoul Staff
	{117321,     1},// Oathsworn Greataxe
	{117330,     1},// Oathsworn Headchopper
	{117331,     0},// Oathsworn Axe
	{117356,     7},// The Horseman's Sinister Slicer
	{117373,    10},// Frostscythe of Lord Ahune
	{117379,     4},// Tremendous Tankard O' Terror
	{117382,     4},// Beakbreaker of Terokk
	{117384,     5},// Warmaul of the Warmaul Chieftain
	{117507,     0},// Frostwolf Hatchet
	{117508,     0},// Frostwolf Logsplitter
	{117551,    10},// Staff of the One True Bramble King
	{117562,     6},// Steeltusk's Steel Tusk
	{117571,     4},// Gordunni Skullthumper
	{117574,     0},// Tournament Gladiator's Cleaver
	{117577,     4},// Tournament Gladiator's Pummeler
	{117578,     7},// Tournament Gladiator's Quickblade
	{117582,     6},// Tournament Gladiator's Pike
	{117583,    10},// Tournament Gladiator's Staff
	{117625,     4},// Tournament Gladiator's Gavel
	{117626,     7},// Tournament Gladiator's Mageblade
	{117629,    10},// Tournament Gladiator's Battle Staff
	{117630,    10},// Tournament Gladiator's Energy Staff
	{117705,     0},// Tournament Gladiator's Hacker
	{117707,     4},// Tournament Gladiator's Bonecracker
	{117708,     7},// Tournament Gladiator's Slicer
	{117709,     1},// Tournament Gladiator's Decapitator
	{117710,     5},// Tournament Gladiator's Bonegrinder
	{117711,     8},// Tournament Gladiator's Greatsword
	{117775,     0},// Tournament Gladiator's Cleaver
	{117778,     4},// Tournament Gladiator's Pummeler
	{117779,     7},// Tournament Gladiator's Quickblade
	{117783,     6},// Tournament Gladiator's Pike
	{117784,    10},// Tournament Gladiator's Staff
	{117826,     4},// Tournament Gladiator's Gavel
	{117827,     7},// Tournament Gladiator's Mageblade
	{117830,    10},// Tournament Gladiator's Battle Staff
	{117831,    10},// Tournament Gladiator's Energy Staff
	{117906,     0},// Tournament Gladiator's Hacker
	{117908,     4},// Tournament Gladiator's Bonecracker
	{117909,     7},// Tournament Gladiator's Slicer
	{117910,     1},// Tournament Gladiator's Decapitator
	{117911,     5},// Tournament Gladiator's Bonegrinder
	{117912,     8},// Tournament Gladiator's Greatsword
	{117994,     0},// RENAME Karabor Honor Guard Axe
	{117995,     0},// RENAME Rangari Initiate Hatchet
	{118013,     7},// Steamscar Sabre
	{118014,     4},// Steamscar Cudgel
	{118022,     0},// Ogron Slayer's Axe
	{118023,     1},// Ogron Slayer's Greataxe
	{118026,     4},// Ogron Slayer's Eyebruiser
	{118027,     6},// Ogron Slayer's Eyegouger
	{118028,    10},// Ogron Slayer's Greatstaff
	{118029,     4},// Ogron Slayer's Club
	{118059,     0},// [MONSTER] Tournament Gladiator's Decapitator
	{118079,     7},// Admiral Taylor's Ceremonial Sword
	{118080,     8},// Admiral Taylor's Greatsword
	{118083,     7},// Admiral Taylor's Cutlass
	{118084,     6},// Admiral Taylor's Glaive
	{118085,    10},// Admiral Taylor's Staff of Wisdom
	{118086,     4},// Admiral Taylor's Keg Tapper
	{118124,     7},// Void-Warped Oshu'gun Shortsword
	{118125,     5},// Void-Warped Oshu'gun Greatmaul
	{118128,     4},// Void-Warped Oshu'gun Mace
	{118129,    10},// Void-Warped Oshu'gun Staff
	{118130,    10},// Void-Warped Oshu'gun Spellstaff
	{118131,     4},// Void-Warped Oshu'gun Mallet
	{118137,     4},// Plainshunter Blackjack
	{118206,     5},// Mutafen's Mighty Maul
	{118209,     0},// Skrikka's Mandible
	{118210,     4},// Greldrok's Facesmasher
	{118212,     5},// Char's Smoldering Fist
	{118228,     5},// Smashalupagus
	{118238,     6},// Anzu's Reach
	{118239,    10},// Anzu's Stoicism
	{118240,     7},// Anzu's Scything Talon
	{118241,     7},// Anzu's Piercing Talon
	{118245,     5},// Hunter Blacktooth's Ribcruncher
	{118264,     8},// Serrated Void Crystal
	{118396,     4},// Bloodmaw Gargoyle
	{118397,     4},// Equus
	{118400,     1},// Orgrimmar Axe
	{118401,    10},// Arcana Shard Spire
	{118402,    10},// Greatstaff of Infinite Knowledge
	{118403,    10},// Dimension-Ripper's Staff
	{118405,     7},// Shifting Felblade
	{118408,     0},// Elemental Crescent
	{118409,     6},// Cloudsong Glaive
	{118412,     8},// Greatsword of the Inferno
	{118413,     5},// Flamegrinder
	{118702,    10},// Brokor's Walking Stick
	{118712,     5},// Huurand's Huge Hammer
	{118719,     5},// Petrified Willow
	{118725,     7},// Tharbek's Unholy Charge
	{118726,     7},// Tharbek's Brutal Possessor
	{118737,     6},// Blackhand Doomcutter
	{118740,     8},// Bleakblade of Shahram
	{118755,     5},// Dripping Willow
	{118757,     7},// Tharbek's Terrible Charge
	{118758,     7},// Tharbek's Horrific Posessor
	{118781,     0},// Gorestained Hatchet
	{118782,     0},// Ivory-Hilted Cleaver
	{118787,     4},// Gibberskull Mace
	{118788,     4},// Matti's Magnificent Mace
	{118789,     4},// Firecrystal Mace
	{118790,     7},// Sabre of the Faceless Moon
	{118791,     7},// Razorcrystal Blade
	{118792,     7},// Reinforced Tuskblade
	{118795,     6},// Draenic Treecleaver
	{118799,     5},// Draenic Ribsmasher
	{118800,     6},// Pillar of Malice
	{118801,     6},// Spire of Autumn
	{118802,     1},// Tayger's Sword-On-A-Stick
	{118803,    10},// Kihrawr's Scratching Post
	{118804,    10},// Starrgo's Walking Stick
	{118805,    10},// Caniki's Cane of Command
	{118806,     8},// Windworn Greatsword
	{118979,     0},// Expeditious Axe
	{118980,     1},// Expeditious Broadaxe
	{118987,     4},// Expeditious Mace
	{118988,     4},// Blackfire Scepter
	{118989,     5},// Expeditious Hammer
	{118990,     6},// Expeditious Spear
	{118991,    10},// Expeditious Staff
	{118992,    10},// Expeditious Staff
	{118993,     7},// Expeditious Sword
	{118994,     8},// Expeditious Greatsword
	{119017,     0},// Expeditious Axe
	{119019,     4},// Expeditious Mace
	{119020,     7},// Expeditious Sword
	{119174,    10},// Sol's Magestaff
	{119181,     4},// Hoof of Yalnu
	{119224,     6},// Foereaver Polearm
	{119392,     0},// Voidreaver's Axe
	{119393,     0},// Searing Shadowflame Axe
	{119398,     4},// Plunderer's Drill
	{119399,     4},// Cudgel of the Son of Goramal
	{119400,     4},// Rugged Crystal Cudgel
	{119401,     7},// Sentinel's Wingblade
	{119402,     7},// Gug'tol's Imp Imperator
	{119403,     7},// Sargerei Soulbiter
	{119405,     5},// Durg's Heavy Maul
	{119406,     6},// Depthroot's Forearm
	{119407,     6},// Cloudsplitter Greatstaff
	{119408,     6},// Foereaver Polearm
	{119409,    10},// Icebound Bloodmaul Spire
	{119410,    10},// Soultwisting Staff
	{119411,     8},// Massive Rockworm Fang
	{119430,    10},// Gas-Powered Stick
	{119448,    10},// Head-Lopper Skullscythe
	{119457,     0},// Handaxe of Trials
	{119458,     1},// Greataxe of Trials
	{119461,     4},// Skullthumper of Trials
	{119462,     6},// Skullcutter of Trials
	{119463,    10},// Staff of Trials
	{119464,     4},// Cudgel of Trials
	{119469,     8},// Heart-Lesion Greatsword
	{119478,     7},// Heart-Lesion Blade
	{119499,     8},// Heart-Lesion Runeblade
	{119512,    10},// Springrain Stave
	{119525,     6},// Springrain Spear
	{119544,    10},// Springrain Staff
	{119576,    10},// Mountainsage Staff
	{119581,    10},// Mistdancer Spire
	{119602,    10},// Mistdancer Staff
	{119605,     7},// Mistdancer Sword
	{119635,     4},// Sunsoul Scepter
	{119637,     7},// Sunsoul Sword
	{119639,     5},// Sunsoul Warmaul
	{119680,    10},// Communal Staff
	{119690,    10},// Communal Stave
	{119707,     7},// Lightdrinker Sword
	{119770,    10},// Felsoul Staff
	{119771,     1},// Oathsworn Greataxe
	{119780,     1},// Oathsworn Headchopper
	{119781,     0},// Oathsworn Axe
	{120053,     0},// Primal Combatant's Cleaver
	{120056,     4},// Primal Combatant's Pummeler
	{120057,     7},// Primal Combatant's Quickblade
	{120061,     6},// Primal Combatant's Pike
	{120062,    10},// Primal Combatant's Staff
	{120064,     4},// Primal Combatant's Gavel
	{120065,     7},// Primal Combatant's Mageblade
	{120068,    10},// Primal Combatant's Battle Staff
	{120069,    10},// Primal Combatant's Energy Staff
	{120070,     0},// Primal Combatant's Hacker
	{120072,     4},// Primal Combatant's Bonecracker
	{120073,     7},// Primal Combatant's Slicer
	{120074,     1},// Primal Combatant's Decapitator
	{120075,     5},// Primal Combatant's Bonegrinder
	{120076,     8},// Primal Combatant's Greatsword
	{120259,     0},// Steelforged Axe
	{120427,     8},// Owen Test 2H Sword
	{120430,     4},// Mighty Gorian Headcracker
	{122349,     1},// Bloodied Arcanite Reaper
	{122351,     7},// Venerable Dal'Rend's Sacred Charge
	{122353,    10},// Dignified Headmaster's Charge
	{122354,     4},// Devout Aurastone Hammer
	{122363,    10},// Burnished Warden Staff
	{122365,     8},// Reforged Truesilver Champion
	{122367,     4},// The Blessed Hammer of Grace
	{122368,    10},// Grand Staff of Jordan
	{122369,     7},// Battleworn Thrash Blade
	{122385,     4},// Venerable Mass of McGowan
	{122386,     5},// Repurposed Lava Dredger
	{122389,     7},// Bloodsoaked Skullforge Reaver
	{123987,     5},// Firemaul of Destruction
	{123999,     4},// Lightsworn Hammer
	{124358,     0},// Runeaxe of the Breaker
	{124359,     0},// Voracious Souleater
	{124360,     1},// Hellrender
	{124371,     4},// Hammer of Wicked Infusion
	{124372,     4},// Gavel of the Eredar
	{124373,     4},// Iron Skullcrusher
	{124374,     4},// Fiendsbreath Warmace
	{124375,     5},// Maul of Tyranny
	{124376,     5},// Warhammer of Arrogance
	{124377,     6},// Rune Infused Spear
	{124378,     6},// Xu'tenash, Glaive of Ruin
	{124379,    10},// Bite of the Bleeding Hollow
	{124380,    10},// Spur of the Great Devourer
	{124381,    10},// Voidcore Greatstaff
	{124382,    10},// Edict of Argus
	{124383,     7},// Mindbender's Flameblade
	{124384,     7},// Saber of Twisted Virtue
	{124385,     7},// Blazing Demonhilt Sword
	{124386,     7},// Felstricken Sha'tari Crystalsword
	{124387,     7},// Shadowrend Talonblade
	{124388,     8},// Fel-Burning Blade
	{124389,     8},// Calamity's Edge
	{124624,     7},// Baleful Sword
	{124625,     8},// Baleful Greatsword
	{124628,     0},// Baleful Greataxe
	{124629,     6},// Baleful Polearm
	{124630,    10},// Baleful Spire
	{124631,     4},// Baleful Scepter
	{124675,     0},// Wild Gladiator's Cleaver
	{124678,     4},// Wild Gladiator's Pummeler
	{124679,     7},// Wild Gladiator's Quickblade
	{124683,     6},// Wild Gladiator's Pike
	{124684,    10},// Wild Gladiator's Staff
	{124727,     4},// Wild Gladiator's Gavel
	{124728,     7},// Wild Gladiator's Mageblade
	{124731,    10},// Wild Gladiator's Battle Staff
	{124732,    10},// Wild Gladiator's Energy Staff
	{124837,     0},// Wild Gladiator's Hacker
	{124839,     4},// Wild Gladiator's Bonecracker
	{124840,     7},// Wild Gladiator's Slicer
	{124841,     1},// Wild Gladiator's Decapitator
	{124842,     5},// Wild Gladiator's Bonegrinder
	{124843,     8},// Wild Gladiator's Greatsword
	{124885,     0},// Wild Combatant's Cleaver
	{124888,     4},// Wild Combatant's Pummeler
	{124889,     7},// Wild Combatant's Quickblade
	{124893,     6},// Wild Combatant's Pike
	{124894,    10},// Wild Combatant's Staff
	{124929,     4},// Wild Combatant's Gavel
	{124930,     7},// Wild Combatant's Mageblade
	{124933,    10},// Wild Combatant's Battle Staff
	{124934,    10},// Wild Combatant's Energy Staff
	{125015,     0},// Wild Combatant's Hacker
	{125017,     4},// Wild Combatant's Bonecracker
	{125018,     7},// Wild Combatant's Slicer
	{125019,     1},// Wild Combatant's Decapitator
	{125020,     5},// Wild Combatant's Bonegrinder
	{125021,     8},// Wild Combatant's Greatsword
	{125154,     0},// Wild Gladiator's Cleaver
	{125157,     4},// Wild Gladiator's Pummeler
	{125158,     7},// Wild Gladiator's Quickblade
	{125162,     6},// Wild Gladiator's Pike
	{125163,    10},// Wild Gladiator's Staff
	{125206,     4},// Wild Gladiator's Gavel
	{125207,     7},// Wild Gladiator's Mageblade
	{125210,    10},// Wild Gladiator's Battle Staff
	{125211,    10},// Wild Gladiator's Energy Staff
	{125316,     0},// Wild Gladiator's Hacker
	{125318,     4},// Wild Gladiator's Bonecracker
	{125319,     7},// Wild Gladiator's Slicer
	{125320,     1},// Wild Gladiator's Decapitator
	{125321,     5},// Wild Gladiator's Bonegrinder
	{125322,     8},// Wild Gladiator's Greatsword
	{125362,     0},// Wild Combatant's Cleaver
	{125365,     4},// Wild Combatant's Pummeler
	{125366,     7},// Wild Combatant's Quickblade
	{125370,     6},// Wild Combatant's Pike
	{125371,    10},// Wild Combatant's Staff
	{125406,     4},// Wild Combatant's Gavel
	{125407,     7},// Wild Combatant's Mageblade
	{125410,    10},// Wild Combatant's Battle Staff
	{125411,    10},// Wild Combatant's Energy Staff
	{125492,     0},// Wild Combatant's Hacker
	{125494,     4},// Wild Combatant's Bonecracker
	{125495,     7},// Wild Combatant's Slicer
	{125496,     1},// Wild Combatant's Decapitator
	{125497,     5},// Wild Combatant's Bonegrinder
	{125498,     8},// Wild Combatant's Greatsword
	{125631,     1},// Wild Gladiator's Decapitator
	{125632,     5},// Wild Gladiator's Bonegrinder
	{125633,     8},// Wild Gladiator's Greatsword
	{125634,     0},// Wild Gladiator's Cleaver
	{125635,     4},// Wild Gladiator's Pummeler
	{125636,     7},// Wild Gladiator's Quickblade
	{125647,    10},// Wild Gladiator's Battle Staff
	{125668,    10},// Wild Gladiator's Staff
	{125677,     4},// Wild Gladiator's Gavel
	{125679,    10},// Wild Gladiator's Energy Staff
	{125724,     6},// Wild Gladiator's Pike
	{125764,     7},// Wild Gladiator's Mageblade
	{125766,     0},// Wild Gladiator's Hacker
	{125767,     4},// Wild Gladiator's Bonecracker
	{125768,     7},// Wild Gladiator's Slicer
	{125789,     0},// Warmongering Gladiator's Cleaver
	{125792,     4},// Warmongering Gladiator's Pummeler
	{125793,     7},// Warmongering Gladiator's Quickblade
	{125797,     6},// Warmongering Gladiator's Pike
	{125798,    10},// Warmongering Gladiator's Staff
	{125841,     4},// Warmongering Gladiator's Gavel
	{125842,     7},// Warmongering Gladiator's Mageblade
	{125845,    10},// Warmongering Gladiator's Battle Staff
	{125846,    10},// Warmongering Gladiator's Energy Staff
	{125951,     0},// Warmongering Gladiator's Hacker
	{125953,     4},// Warmongering Gladiator's Bonecracker
	{125954,     7},// Warmongering Gladiator's Slicer
	{125955,     1},// Warmongering Gladiator's Decapitator
	{125956,     5},// Warmongering Gladiator's Bonegrinder
	{125957,     8},// Warmongering Gladiator's Greatsword
	{125999,     0},// Warmongering Combatant's Cleaver
	{126002,     4},// Warmongering Combatant's Pummeler
	{126003,     7},// Warmongering Combatant's Quickblade
	{126007,     6},// Warmongering Combatant's Pike
	{126008,    10},// Warmongering Combatant's Staff
	{126043,     4},// Warmongering Combatant's Gavel
	{126044,     7},// Warmongering Combatant's Mageblade
	{126047,    10},// Warmongering Combatant's Battle Staff
	{126048,    10},// Warmongering Combatant's Energy Staff
	{126129,     0},// Warmongering Combatant's Hacker
	{126131,     4},// Warmongering Combatant's Bonecracker
	{126132,     7},// Warmongering Combatant's Slicer
	{126133,     1},// Warmongering Combatant's Decapitator
	{126134,     5},// Warmongering Combatant's Bonegrinder
	{126135,     8},// Warmongering Combatant's Greatsword
	{126268,     0},// Warmongering Gladiator's Cleaver
	{126271,     4},// Warmongering Gladiator's Pummeler
	{126272,     7},// Warmongering Gladiator's Quickblade
	{126276,     6},// Warmongering Gladiator's Pike
	{126277,    10},// Warmongering Gladiator's Staff
	{126320,     4},// Warmongering Gladiator's Gavel
	{126321,     7},// Warmongering Gladiator's Mageblade
	{126324,    10},// Warmongering Gladiator's Battle Staff
	{126325,    10},// Warmongering Gladiator's Energy Staff
	{126430,     0},// Warmongering Gladiator's Hacker
	{126432,     4},// Warmongering Gladiator's Bonecracker
	{126433,     7},// Warmongering Gladiator's Slicer
	{126434,     1},// Warmongering Gladiator's Decapitator
	{126435,     5},// Warmongering Gladiator's Bonegrinder
	{126436,     8},// Warmongering Gladiator's Greatsword
	{126476,     0},// Warmongering Combatant's Cleaver
	{126479,     4},// Warmongering Combatant's Pummeler
	{126480,     7},// Warmongering Combatant's Quickblade
	{126484,     6},// Warmongering Combatant's Pike
	{126485,    10},// Warmongering Combatant's Staff
	{126520,     4},// Warmongering Combatant's Gavel
	{126521,     7},// Warmongering Combatant's Mageblade
	{126524,    10},// Warmongering Combatant's Battle Staff
	{126525,    10},// Warmongering Combatant's Energy Staff
	{126606,     0},// Warmongering Combatant's Hacker
	{126608,     4},// Warmongering Combatant's Bonecracker
	{126609,     7},// Warmongering Combatant's Slicer
	{126610,     1},// Warmongering Combatant's Decapitator
	{126611,     5},// Warmongering Combatant's Bonegrinder
	{126612,     8},// Warmongering Combatant's Greatsword
	{126745,     1},// Warmongering Gladiator's Decapitator
	{126746,     5},// Warmongering Gladiator's Bonegrinder
	{126747,     8},// Warmongering Gladiator's Greatsword
	{126748,     0},// Warmongering Gladiator's Cleaver
	{126749,     4},// Warmongering Gladiator's Pummeler
	{126750,     7},// Warmongering Gladiator's Quickblade
	{126761,    10},// Warmongering Gladiator's Battle Staff
	{126782,    10},// Warmongering Gladiator's Staff
	{126791,     4},// Warmongering Gladiator's Gavel
	{126793,    10},// Warmongering Gladiator's Energy Staff
	{126838,     6},// Warmongering Gladiator's Pike
	{126878,     7},// Warmongering Gladiator's Mageblade
	{126880,     0},// Warmongering Gladiator's Hacker
	{126881,     4},// Warmongering Gladiator's Bonecracker
	{126882,     7},// Warmongering Gladiator's Slicer
	{127160,     5},// Warmaul of Infused Light
	{127183,     7},// Spellfire Longsword
	{127185,     4},// Coilfang Hammer of Renewal
	{127200,     7},// Phosphorescent Blade
	{127206,     4},// Bleeding Hollow Warhammer
	{127220,     8},// Shaarde the Greater
	{127224,    10},// Staff of Polarities
	{127225,     7},// Scimitar of the Nexus-Stalkers
	{127246,     1},// Axe of the Nexus-Kings
	{127250,     5},// Scepter of Sha'tar
	{127251,    10},// Grand Scepter of the Nexus-Kings
	{127255,     7},// Warp-Storm Warblade
	{127324,     0},// Weathered Memento Axe
	{127325,     1},// Axe of the Weeping Wolf
	{127332,     4},// Riverbeast Molar Club
	{127333,     5},// Ogra'mal Snake Charming Flute
	{127334,     6},// Ravager Hunting Spear
	{127335,     6},// Relgor's Master Glaive
	{127336,    10},// Rod of the One True Podlord
	{127337,    10},// Emanating Staff of Shadow
	{127338,     7},// Guardian Swiftblade of Kra'nak
	{127339,     8},// Forgotten Champion's Blade
	{127340,     8},// Felfire Lit Greatsword
	{127378,     0},// Warmongering Combatant's Chopper
	{127379,     0},// Warmongering Combatant's Chopper
	{127380,     0},// Wild Combatant's Chopper
	{127381,     0},// Wild Combatant's Chopper
	{127440,    10},// Epoch-Mender
	{127442,     7},// Millennium Blade
	{127446,    10},// Bloodfire Greatstaff
	{127447,     7},// Latro's Shifting Sword
	{127456,     8},// Quantum Blade
	{127471,     7},// Jeweled Coronation Sword
	{127475,     7},// Ymiron's Blade
	{127491,    10},// Staff of Wayward Principles
	{127497,     7},// Red Sword of Courage
	{127516,    10},// Lightning Giant Staff
	{127520,     1},// Colossal Skull-Clad Cleaver
	{127527,    10},// Witch Doctor's Wildstaff
	{127530,     4},// Frozen Scepter of Necromancy
	{127596,     4},// War Mace of Unrequited Love
	{127628,    10},// Staff of Sinister Claws
	{127640,     1},// Edge of Oblivion
	{127647,     1},// Ice-Rimed Chopper
	{127653,     7},// Wingblade of Reckoning
	{128094,     4},// Spiked Torque Wrench
	{128095,     7},// Viscera-Stained Longsword
	{128097,     1},// Rivetspike Cleaver
	{128099,     5},// Spiked Gnarlroot Greatclub
	{128100,    10},// Spring-Loaded Jawstaff
	{128101,    10},// Soulcult Ritual Staff
	{128191,     7},// Hellfire Mindblade
	{128196,     0},// Limbcarver Hatchet
	{128197,     7},// Felgore Double Blade
	{128198,    10},// Irontalon Staff
	{128199,    10},// Fractured Soulgem Staff
	{128201,     8},// Greatsword of Chaos
	{128629,     5},// Durg's Heavy Maul
	{129394,    10},// Communal Staff
	{129404,    10},// Communal Stave
	{129425,    10},// Felsoul Staff
	{129426,     8},// Heart-Lesion Greatsword
	{129435,     7},// Heart-Lesion Blade
	{129456,     8},// Heart-Lesion Runeblade
	{129473,     7},// Lightdrinker Sword
	{129478,    10},// Mistdancer Spire
	{129499,    10},// Mistdancer Staff
	{129502,     7},// Mistdancer Sword
	{129525,    10},// Mountainsage Staff
	{129526,     1},// Oathsworn Greataxe
	{129535,     1},// Oathsworn Headchopper
	{129536,     0},// Oathsworn Axe
	{129570,    10},// Springrain Stave
	{129583,     6},// Springrain Spear
	{129602,    10},// Springrain Staff
	{129678,     4},// Sunsoul Scepter
	{129680,     7},// Sunsoul Sword
	{129682,     5},// Sunsoul Warmaul
	{129827,     1},// The Blade of Harbingers
	{129828,    10},// Staff of the Soul-Eater
	{129829,    10},// Staff of the Forest Lord
	{129858,     4},// Gavel of Naaru Blessings
	{129861,     7},// Sword of Unyielding Force
	{129934,     0},// Wild Gladiator's Runeaxe
	{129935,     0},// Wild Gladiator's Runeaxe
	{129936,     0},// Wild Gladiator's Runeaxe
	{133179,     0},// Lightning Whelk Axe
	{133184,    10},// Cerith Spire Staff
	{133196,     1},// Whitefin Axe
	{133219,     8},// Sword of the Bottomless Pit
	{133220,    10},// Darkling Staff
	{133223,     7},// Elementium Fang
	{133229,     4},// Heavy Geode Mace
	{133240,     0},// Axe of the Eclipse
	{133257,     6},// Seliza's Spear
	{133259,     7},// Resonant Kris
	{133271,     4},// Hammer of Sparks
	{133298,     5},// Wild Hammer
	{133301,     4},// Mace of Transformed Bone
	{133303,    10},// Staff of Siphoned Essences
	{133371,     1},// Thundercleaver Axe
	{133375,     4},// Craclking Geode Mace
	{133376,     4},// Sceptre of Swirling Winds
	{133391,     4},// Dragonshrine Scepter
	{133395,    10},// Jaina's Staff
	{133399,     0},// Crescent Moon
	{133401,     1},// Axe of the Tauren Chieftains
	{133433,     0},// Sun-Forged Cleaver
	{133437,     7},// Latro's Dancing Blade
	{133446,     4},// Battle-Mace of the High Priestess
	{133450,     1},// Axe of Shattered Dreams
	{133453,    10},// Sun-Infused Focus Staff
	{133471,    10},// Rod of the Blazing Light
	{133472,     7},// Quickening Blade of the Prince
	{133474,     4},// Cudgel of Consecration
	{133479,     0},// Breeching Comet
	{133485,    10},// Unspeakable Secret
	{133486,     5},// Garfrost's Two-Ton Hammer
	{133582,     0},// Warmongering Gladiator's Runeaxe
	{133583,     0},// Warmongering Gladiator's Runeaxe
	{133584,     0},// Warmongering Gladiator's Runeaxe
	{     0,     0},
};

