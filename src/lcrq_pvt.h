/* SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only */
/* Copyright (c) 2022 Brett Sheffield <bacs@librecast.net> */

#ifndef LCRQ_PVT_H
#define LCRQ_PVT_H 1

#include <config.h>
#include <lcrq.h>
#include <matrix.h>
#include <stdint.h>

typedef struct t2_s {
	uint16_t k;
	uint16_t j;
	uint16_t s;
	uint16_t h;
	uint16_t w;
} t2_t;

/* 5.5.1.  The Table V0 */
static const size_t V0[] = {
	251291136, 3952231631, 3370958628, 4070167936, 123631495,
	3351110283, 3218676425, 2011642291, 774603218, 2402805061,
	1004366930, 1843948209, 428891132, 3746331984, 1591258008,
	3067016507, 1433388735, 504005498, 2032657933, 3419319784,
	2805686246, 3102436986, 3808671154, 2501582075, 3978944421,
	246043949, 4016898363, 649743608, 1974987508, 2651273766,
	2357956801, 689605112, 715807172, 2722736134, 191939188,
	3535520147, 3277019569, 1470435941, 3763101702, 3232409631,
	122701163, 3920852693, 782246947, 372121310, 2995604341,
	2045698575, 2332962102, 4005368743, 218596347, 3415381967,
	4207612806, 861117671, 3676575285, 2581671944, 3312220480,
	681232419, 307306866, 4112503940, 1158111502, 709227802,
	2724140433, 4201101115, 4215970289, 4048876515, 3031661061,
	1909085522, 510985033, 1361682810, 129243379, 3142379587,
	2569842483, 3033268270, 1658118006, 932109358, 1982290045,
	2983082771, 3007670818, 3448104768, 683749698, 778296777,
	1399125101, 1939403708, 1692176003, 3868299200, 1422476658,
	593093658, 1878973865, 2526292949, 1591602827, 3986158854,
	3964389521, 2695031039, 1942050155, 424618399, 1347204291,
	2669179716, 2434425874, 2540801947, 1384069776, 4123580443,
	1523670218, 2708475297, 1046771089, 2229796016, 1255426612,
	4213663089, 1521339547, 3041843489, 420130494, 10677091,
	515623176, 3457502702, 2115821274, 2720124766, 3242576090,
	854310108, 425973987, 325832382, 1796851292, 2462744411,
	1976681690, 1408671665, 1228817808, 3917210003, 263976645,
	2593736473, 2471651269, 4291353919, 650792940, 1191583883,
	3046561335, 2466530435, 2545983082, 969168436, 2019348792,
	2268075521, 1169345068, 3250240009, 3963499681, 2560755113,
	911182396, 760842409, 3569308693, 2687243553, 381854665,
	2613828404, 2761078866, 1456668111, 883760091, 3294951678,
	1604598575, 1985308198, 1014570543, 2724959607, 3062518035,
	3115293053, 138853680, 4160398285, 3322241130, 2068983570,
	2247491078, 3669524410, 1575146607, 828029864, 3732001371,
	3422026452, 3370954177, 4006626915, 543812220, 1243116171,
	3928372514, 2791443445, 4081325272, 2280435605, 885616073,
	616452097, 3188863436, 2780382310, 2340014831, 1208439576,
	258356309, 3837963200, 2075009450, 3214181212, 3303882142,
	880813252, 1355575717, 207231484, 2420803184, 358923368,
	1617557768, 3272161958, 1771154147, 2842106362, 1751209208,
	1421030790, 658316681, 194065839, 3241510581, 38625260,
	301875395, 4176141739, 297312930, 2137802113, 1502984205,
	3669376622, 3728477036, 234652930, 2213589897, 2734638932,
	1129721478, 3187422815, 2859178611, 3284308411, 3819792700,
	3557526733, 451874476, 1740576081, 3592838701, 1709429513,
	3702918379, 3533351328, 1641660745, 179350258, 2380520112,
	3936163904, 3685256204, 3156252216, 1854258901, 2861641019,
	3176611298, 834787554, 331353807, 517858103, 3010168884,
	4012642001, 2217188075, 3756943137, 3077882590, 2054995199,
	3081443129, 3895398812, 1141097543, 2376261053, 2626898255,
	2554703076, 401233789, 1460049922, 678083952, 1064990737,
	940909784, 1673396780, 528881783, 1712547446, 3629685652,
	1358307511
};

/* 5.5.2.  The Table V1 */
static const size_t V1[] = {
	807385413, 2043073223, 3336749796, 1302105833, 2278607931,
	541015020, 1684564270, 372709334, 3508252125, 1768346005,
	1270451292, 2603029534, 2049387273, 3891424859, 2152948345,
	4114760273, 915180310, 3754787998, 700503826, 2131559305,
	1308908630, 224437350, 4065424007, 3638665944, 1679385496,
	3431345226, 1779595665, 3068494238, 1424062773, 1033448464,
	4050396853, 3302235057, 420600373, 2868446243, 311689386,
	259047959, 4057180909, 1575367248, 4151214153, 110249784,
	3006865921, 4293710613, 3501256572, 998007483, 499288295,
	1205710710, 2997199489, 640417429, 3044194711, 486690751,
	2686640734, 2394526209, 2521660077, 49993987, 3843885867,
	4201106668, 415906198, 19296841, 2402488407, 2137119134,
	1744097284, 579965637, 2037662632, 852173610, 2681403713,
	1047144830, 2982173936, 910285038, 4187576520, 2589870048,
	989448887, 3292758024, 506322719, 176010738, 1865471968,
	2619324712, 564829442, 1996870325, 339697593, 4071072948,
	3618966336, 2111320126, 1093955153, 957978696, 892010560,
	1854601078, 1873407527, 2498544695, 2694156259, 1927339682,
	1650555729, 183933047, 3061444337, 2067387204, 228962564,
	3904109414, 1595995433, 1780701372, 2463145963, 307281463,
	3237929991, 3852995239, 2398693510, 3754138664, 522074127,
	146352474, 4104915256, 3029415884, 3545667983, 332038910,
	976628269, 3123492423, 3041418372, 2258059298, 2139377204,
	3243642973, 3226247917, 3674004636, 2698992189, 3453843574,
	1963216666, 3509855005, 2358481858, 747331248, 1957348676,
	1097574450, 2435697214, 3870972145, 1888833893, 2914085525,
	4161315584, 1273113343, 3269644828, 3681293816, 412536684,
	1156034077, 3823026442, 1066971017, 3598330293, 1979273937,
	2079029895, 1195045909, 1071986421, 2712821515, 3377754595,
	2184151095, 750918864, 2585729879, 4249895712, 1832579367,
	1192240192, 946734366, 31230688, 3174399083, 3549375728,
	1642430184, 1904857554, 861877404, 3277825584, 4267074718,
	3122860549, 666423581, 644189126, 226475395, 307789415,
	1196105631, 3191691839, 782852669, 1608507813, 1847685900,
	4069766876, 3931548641, 2526471011, 766865139, 2115084288,
	4259411376, 3323683436, 568512177, 3736601419, 1800276898,
	4012458395, 1823982, 27980198, 2023839966, 869505096,
	431161506, 1024804023, 1853869307, 3393537983, 1500703614,
	3019471560, 1351086955, 3096933631, 3034634988, 2544598006,
	1230942551, 3362230798, 159984793, 491590373, 3993872886,
	3681855622, 903593547, 3535062472, 1799803217, 772984149,
	895863112, 1899036275, 4187322100, 101856048, 234650315,
	3183125617, 3190039692, 525584357, 1286834489, 455810374,
	1869181575, 922673938, 3877430102, 3422391938, 1414347295,
	1971054608, 3061798054, 830555096, 2822905141, 167033190,
	1079139428, 4210126723, 3593797804, 429192890, 372093950,
	1779187770, 3312189287, 204349348, 452421568, 2800540462,
	3733109044, 1235082423, 1765319556, 3174729780, 3762994475,
	3171962488, 442160826, 198349622, 45942637, 1324086311,
	2901868599, 678860040, 3812229107, 19936821, 1119590141,
	3640121682, 3545931032, 2102949142, 2828208598, 3603378023,
	4135048896
};

/* 5.5.3.  The Table V2 */
static const size_t V2[] = {
	1629829892, 282540176, 2794583710, 496504798, 2990494426,
	3070701851, 2575963183, 4094823972, 2775723650, 4079480416,
	176028725, 2246241423, 3732217647, 2196843075, 1306949278,
	4170992780, 4039345809, 3209664269, 3387499533, 293063229,
	3660290503, 2648440860, 2531406539, 3537879412, 773374739,
	4184691853, 1804207821, 3347126643, 3479377103, 3970515774,
	1891731298, 2368003842, 3537588307, 2969158410, 4230745262,
	831906319, 2935838131, 264029468, 120852739, 3200326460,
	355445271, 2296305141, 1566296040, 1760127056, 20073893,
	3427103620, 2866979760, 2359075957, 2025314291, 1725696734,
	3346087406, 2690756527, 99815156, 4248519977, 2253762642,
	3274144518, 598024568, 3299672435, 556579346, 4121041856,
	2896948975, 3620123492, 918453629, 3249461198, 2231414958,
	3803272287, 3657597946, 2588911389, 242262274, 1725007475,
	2026427718, 46776484, 2873281403, 2919275846, 3177933051,
	1918859160, 2517854537, 1857818511, 3234262050, 479353687,
	200201308, 2801945841, 1621715769, 483977159, 423502325,
	3689396064, 1850168397, 3359959416, 3459831930, 841488699,
	3570506095, 930267420, 1564520841, 2505122797, 593824107,
	1116572080, 819179184, 3139123629, 1414339336, 1076360795,
	512403845, 177759256, 1701060666, 2239736419, 515179302,
	2935012727, 3821357612, 1376520851, 2700745271, 966853647,
	1041862223, 715860553, 171592961, 1607044257, 1227236688,
	3647136358, 1417559141, 4087067551, 2241705880, 4194136288,
	1439041934, 20464430, 119668151, 2021257232, 2551262694,
	1381539058, 4082839035, 498179069, 311508499, 3580908637,
	2889149671, 142719814, 1232184754, 3356662582, 2973775623,
	1469897084, 1728205304, 1415793613, 50111003, 3133413359,
	4074115275, 2710540611, 2700083070, 2457757663, 2612845330,
	3775943755, 2469309260, 2560142753, 3020996369, 1691667711,
	4219602776, 1687672168, 1017921622, 2307642321, 368711460,
	3282925988, 213208029, 4150757489, 3443211944, 2846101972,
	4106826684, 4272438675, 2199416468, 3710621281, 497564971,
	285138276, 765042313, 916220877, 3402623607, 2768784621,
	1722849097, 3386397442, 487920061, 3569027007, 3424544196,
	217781973, 2356938519, 3252429414, 145109750, 2692588106,
	2454747135, 1299493354, 4120241887, 2088917094, 932304329,
	1442609203, 952586974, 3509186750, 753369054, 854421006,
	1954046388, 2708927882, 4047539230, 3048925996, 1667505809,
	805166441, 1182069088, 4265546268, 4215029527, 3374748959,
	373532666, 2454243090, 2371530493, 3651087521, 2619878153,
	1651809518, 1553646893, 1227452842, 703887512, 3696674163,
	2552507603, 2635912901, 895130484, 3287782244, 3098973502,
	990078774, 3780326506, 2290845203, 41729428, 1949580860,
	2283959805, 1036946170, 1694887523, 4880696, 466000198,
	2765355283, 3318686998, 1266458025, 3919578154, 3545413527,
	2627009988, 3744680394, 1696890173, 3250684705, 4142417708,
	915739411, 3308488877, 1289361460, 2942552331, 1169105979,
	3342228712, 698560958, 1356041230, 2401944293, 107705232,
	3701895363, 903928723, 3646581385, 844950914, 1944371367,
	3863894844, 2946773319, 1972431613, 1706989237, 29917467,
	3497665928
};

/* 5.5.4.  The Table V3 */
static const size_t V3[] = {
	1191369816, 744902811, 2539772235, 3213192037, 3286061266,
	1200571165, 2463281260, 754888894, 714651270, 1968220972,
	3628497775, 1277626456, 1493398934, 364289757, 2055487592,
	3913468088, 2930259465, 902504567, 3967050355, 2056499403,
	692132390, 186386657, 832834706, 859795816, 1283120926,
	2253183716, 3003475205, 1755803552, 2239315142, 4271056352,
	2184848469, 769228092, 1249230754, 1193269205, 2660094102,
	642979613, 1687087994, 2726106182, 446402913, 4122186606,
	3771347282, 37667136, 192775425, 3578702187, 1952659096,
	3989584400, 3069013882, 2900516158, 4045316336, 3057163251,
	1702104819, 4116613420, 3575472384, 2674023117, 1409126723,
	3215095429, 1430726429, 2544497368, 1029565676, 1855801827,
	4262184627, 1854326881, 2906728593, 3277836557, 2787697002,
	2787333385, 3105430738, 2477073192, 748038573, 1088396515,
	1611204853, 201964005, 3745818380, 3654683549, 3816120877,
	3915783622, 2563198722, 1181149055, 33158084, 3723047845,
	3790270906, 3832415204, 2959617497, 372900708, 1286738499,
	1932439099, 3677748309, 2454711182, 2757856469, 2134027055,
	2780052465, 3190347618, 3758510138, 3626329451, 1120743107,
	1623585693, 1389834102, 2719230375, 3038609003, 462617590,
	260254189, 3706349764, 2556762744, 2874272296, 2502399286,
	4216263978, 2683431180, 2168560535, 3561507175, 668095726,
	680412330, 3726693946, 4180630637, 3335170953, 942140968,
	2711851085, 2059233412, 4265696278, 3204373534, 232855056,
	881788313, 2258252172, 2043595984, 3758795150, 3615341325,
	2138837681, 1351208537, 2923692473, 3402482785, 2105383425,
	2346772751, 499245323, 3417846006, 2366116814, 2543090583,
	1828551634, 3148696244, 3853884867, 1364737681, 2200687771,
	2689775688, 232720625, 4071657318, 2671968983, 3531415031,
	1212852141, 867923311, 3740109711, 1923146533, 3237071777,
	3100729255, 3247856816, 906742566, 4047640575, 4007211572,
	3495700105, 1171285262, 2835682655, 1634301229, 3115169925,
	2289874706, 2252450179, 944880097, 371933491, 1649074501,
	2208617414, 2524305981, 2496569844, 2667037160, 1257550794,
	3399219045, 3194894295, 1643249887, 342911473, 891025733,
	3146861835, 3789181526, 938847812, 1854580183, 2112653794,
	2960702988, 1238603378, 2205280635, 1666784014, 2520274614,
	3355493726, 2310872278, 3153920489, 2745882591, 1200203158,
	3033612415, 2311650167, 1048129133, 4206710184, 4209176741,
	2640950279, 2096382177, 4116899089, 3631017851, 4104488173,
	1857650503, 3801102932, 445806934, 3055654640, 897898279,
	3234007399, 1325494930, 2982247189, 1619020475, 2720040856,
	885096170, 3485255499, 2983202469, 3891011124, 546522756,
	1524439205, 2644317889, 2170076800, 2969618716, 961183518,
	1081831074, 1037015347, 3289016286, 2331748669, 620887395,
	303042654, 3990027945, 1562756376, 3413341792, 2059647769,
	2823844432, 674595301, 2457639984, 4076754716, 2447737904,
	1583323324, 625627134, 3076006391, 345777990, 1684954145,
	879227329, 3436182180, 1522273219, 3802543817, 1456017040,
	1897819847, 2970081129, 1382576028, 3820044861, 1044428167,
	612252599, 3340478395, 2150613904, 3397625662, 3573635640,
	3432275192
};

/* Table 1: Degree Distribution for Encoding Symbols (5.3.5.2) */
static const int DEG[] = {
	0,
	5243,
	529531,
	704294,
	791675,
	844104,
	879057,
	904023,
	922747,
	937311,
	948962,
	958494,
	966438,
	973160,
	978921,
	983914,
	988283,
	992138,
	995565,
	998631,
	1001391,
	1003887,
	1006157,
	1008229,
	1010129,
	1011876,
	1013490,
	1014983,
	1016370,
	1017662,
	1048576
};
static const int DEGMAX = sizeof DEG / sizeof DEG[0];

/* Table 2 (5.6) */
static const t2_t T2[] = {
	{10, 254, 7, 10, 17},
	{12, 630, 7, 10, 19},
	{18, 682, 11, 10, 29},
	{20, 293, 11, 10, 31},
	{26, 80, 11, 10, 37},
	{30, 566, 11, 10, 41},
	{32, 860, 11, 10, 43},
	{36, 267, 11, 10, 47},
	{42, 822, 11, 10, 53},
	{46, 506, 13, 10, 59},
	{48, 589, 13, 10, 61},
	{49, 87, 13, 10, 61},
	{55, 520, 13, 10, 67},
	{60, 159, 13, 10, 71},
	{62, 235, 13, 10, 73},
	{69, 157, 13, 10, 79},
	{75, 502, 17, 10, 89},
	{84, 334, 17, 10, 97},
	{88, 583, 17, 10, 101},
	{91, 66, 17, 10, 103},
	{95, 352, 17, 10, 107},
	{97, 365, 17, 10, 109},
	{101, 562, 17, 10, 113},
	{114, 5, 19, 10, 127},
	{119, 603, 19, 10, 131},
	{125, 721, 19, 10, 137},
	{127, 28, 19, 10, 139},
	{138, 660, 19, 10, 149},
	{140, 829, 19, 10, 151},
	{149, 900, 23, 10, 163},
	{153, 930, 23, 10, 167},
	{160, 814, 23, 10, 173},
	{166, 661, 23, 10, 179},
	{168, 693, 23, 10, 181},
	{179, 780, 23, 10, 191},
	{181, 605, 23, 10, 193},
	{185, 551, 23, 10, 197},
	{187, 777, 23, 10, 199},
	{200, 491, 23, 10, 211},
	{213, 396, 23, 10, 223},
	{217, 764, 29, 10, 233},
	{225, 843, 29, 10, 241},
	{236, 646, 29, 10, 251},
	{242, 557, 29, 10, 257},
	{248, 608, 29, 10, 263},
	{257, 265, 29, 10, 271},
	{263, 505, 29, 10, 277},
	{269, 722, 29, 10, 283},
	{280, 263, 29, 10, 293},
	{295, 999, 29, 10, 307},
	{301, 874, 29, 10, 313},
	{305, 160, 29, 10, 317},
	{324, 575, 31, 10, 337},
	{337, 210, 31, 10, 349},
	{341, 513, 31, 10, 353},
	{347, 503, 31, 10, 359},
	{355, 558, 31, 10, 367},
	{362, 932, 31, 10, 373},
	{368, 404, 31, 10, 379},
	{372, 520, 37, 10, 389},
	{380, 846, 37, 10, 397},
	{385, 485, 37, 10, 401},
	{393, 728, 37, 10, 409},
	{405, 554, 37, 10, 421},
	{418, 471, 37, 10, 433},
	{428, 641, 37, 10, 443},
	{434, 732, 37, 10, 449},
	{447, 193, 37, 10, 461},
	{453, 934, 37, 10, 467},
	{466, 864, 37, 10, 479},
	{478, 790, 37, 10, 491},
	{486, 912, 37, 10, 499},
	{491, 617, 37, 10, 503},
	{497, 587, 37, 10, 509},
	{511, 800, 37, 10, 523},
	{526, 923, 41, 10, 541},
	{532, 998, 41, 10, 547},
	{542, 92, 41, 10, 557},
	{549, 497, 41, 10, 563},
	{557, 559, 41, 10, 571},
	{563, 667, 41, 10, 577},
	{573, 912, 41, 10, 587},
	{580, 262, 41, 10, 593},
	{588, 152, 41, 10, 601},
	{594, 526, 41, 10, 607},
	{600, 268, 41, 10, 613},
	{606, 212, 41, 10, 619},
	{619, 45, 41, 10, 631},
	{633, 898, 43, 10, 647},
	{640, 527, 43, 10, 653},
	{648, 558, 43, 10, 661},
	{666, 460, 47, 10, 683},
	{675, 5, 47, 10, 691},
	{685, 895, 47, 10, 701},
	{693, 996, 47, 10, 709},
	{703, 282, 47, 10, 719},
	{718, 513, 47, 10, 733},
	{728, 865, 47, 10, 743},
	{736, 870, 47, 10, 751},
	{747, 239, 47, 10, 761},
	{759, 452, 47, 10, 773},
	{778, 862, 53, 10, 797},
	{792, 852, 53, 10, 811},
	{802, 643, 53, 10, 821},
	{811, 543, 53, 10, 829},
	{821, 447, 53, 10, 839},
	{835, 321, 53, 10, 853},
	{845, 287, 53, 10, 863},
	{860, 12, 53, 10, 877},
	{870, 251, 53, 10, 887},
	{891, 30, 53, 10, 907},
	{903, 621, 53, 10, 919},
	{913, 555, 53, 10, 929},
	{926, 127, 53, 10, 941},
	{938, 400, 53, 10, 953},
	{950, 91, 59, 10, 971},
	{963, 916, 59, 10, 983},
	{977, 935, 59, 10, 997},
	{989, 691, 59, 10, 1009},
	{1002, 299, 59, 10, 1021},
	{1020, 282, 59, 10, 1039},
	{1032, 824, 59, 10, 1051},
	{1050, 536, 59, 11, 1069},
	{1074, 596, 59, 11, 1093},
	{1085, 28, 59, 11, 1103},
	{1099, 947, 59, 11, 1117},
	{1111, 162, 59, 11, 1129},
	{1136, 536, 59, 11, 1153},
	{1152, 1000, 61, 11, 1171},
	{1169, 251, 61, 11, 1187},
	{1183, 673, 61, 11, 1201},
	{1205, 559, 61, 11, 1223},
	{1220, 923, 61, 11, 1237},
	{1236, 81, 67, 11, 1259},
	{1255, 478, 67, 11, 1277},
	{1269, 198, 67, 11, 1291},
	{1285, 137, 67, 11, 1307},
	{1306, 75, 67, 11, 1327},
	{1347, 29, 67, 11, 1367},
	{1361, 231, 67, 11, 1381},
	{1389, 532, 67, 11, 1409},
	{1404, 58, 67, 11, 1423},
	{1420, 60, 67, 11, 1439},
	{1436, 964, 71, 11, 1459},
	{1461, 624, 71, 11, 1483},
	{1477, 502, 71, 11, 1499},
	{1502, 636, 71, 11, 1523},
	{1522, 986, 71, 11, 1543},
	{1539, 950, 71, 11, 1559},
	{1561, 735, 73, 11, 1583},
	{1579, 866, 73, 11, 1601},
	{1600, 203, 73, 11, 1621},
	{1616, 83, 73, 11, 1637},
	{1649, 14, 73, 11, 1669},
	{1673, 522, 79, 11, 1699},
	{1698, 226, 79, 11, 1723},
	{1716, 282, 79, 11, 1741},
	{1734, 88, 79, 11, 1759},
	{1759, 636, 79, 11, 1783},
	{1777, 860, 79, 11, 1801},
	{1800, 324, 79, 11, 1823},
	{1824, 424, 79, 11, 1847},
	{1844, 999, 79, 11, 1867},
	{1863, 682, 83, 11, 1889},
	{1887, 814, 83, 11, 1913},
	{1906, 979, 83, 11, 1931},
	{1926, 538, 83, 11, 1951},
	{1954, 278, 83, 11, 1979},
	{1979, 580, 83, 11, 2003},
	{2005, 773, 83, 11, 2029},
	{2040, 911, 89, 11, 2069},
	{2070, 506, 89, 11, 2099},
	{2103, 628, 89, 11, 2131},
	{2125, 282, 89, 11, 2153},
	{2152, 309, 89, 11, 2179},
	{2195, 858, 89, 11, 2221},
	{2217, 442, 89, 11, 2243},
	{2247, 654, 89, 11, 2273},
	{2278, 82, 97, 11, 2311},
	{2315, 428, 97, 11, 2347},
	{2339, 442, 97, 11, 2371},
	{2367, 283, 97, 11, 2399},
	{2392, 538, 97, 11, 2423},
	{2416, 189, 97, 11, 2447},
	{2447, 438, 97, 11, 2477},
	{2473, 912, 97, 11, 2503},
	{2502, 1, 97, 11, 2531},
	{2528, 167, 97, 11, 2557},
	{2565, 272, 97, 11, 2593},
	{2601, 209, 101, 11, 2633},
	{2640, 927, 101, 11, 2671},
	{2668, 386, 101, 11, 2699},
	{2701, 653, 101, 11, 2731},
	{2737, 669, 101, 11, 2767},
	{2772, 431, 101, 11, 2801},
	{2802, 793, 103, 11, 2833},
	{2831, 588, 103, 11, 2861},
	{2875, 777, 107, 11, 2909},
	{2906, 939, 107, 11, 2939},
	{2938, 864, 107, 11, 2971},
	{2979, 627, 107, 11, 3011},
	{3015, 265, 109, 11, 3049},
	{3056, 976, 109, 11, 3089},
	{3101, 988, 113, 11, 3137},
	{3151, 507, 113, 11, 3187},
	{3186, 640, 113, 11, 3221},
	{3224, 15, 113, 11, 3259},
	{3265, 667, 113, 11, 3299},
	{3299, 24, 127, 11, 3347},
	{3344, 877, 127, 11, 3391},
	{3387, 240, 127, 11, 3433},
	{3423, 720, 127, 11, 3469},
	{3466, 93, 127, 11, 3511},
	{3502, 919, 127, 11, 3547},
	{3539, 635, 127, 11, 3583},
	{3579, 174, 127, 11, 3623},
	{3616, 647, 127, 11, 3659},
	{3658, 820, 127, 11, 3701},
	{3697, 56, 127, 11, 3739},
	{3751, 485, 127, 11, 3793},
	{3792, 210, 127, 11, 3833},
	{3840, 124, 127, 11, 3881},
	{3883, 546, 127, 11, 3923},
	{3924, 954, 131, 11, 3967},
	{3970, 262, 131, 11, 4013},
	{4015, 927, 131, 11, 4057},
	{4069, 957, 131, 11, 4111},
	{4112, 726, 137, 11, 4159},
	{4165, 583, 137, 11, 4211},
	{4207, 782, 137, 11, 4253},
	{4252, 37, 137, 11, 4297},
	{4318, 758, 137, 11, 4363},
	{4365, 777, 137, 11, 4409},
	{4418, 104, 139, 11, 4463},
	{4468, 476, 139, 11, 4513},
	{4513, 113, 149, 11, 4567},
	{4567, 313, 149, 11, 4621},
	{4626, 102, 149, 11, 4679},
	{4681, 501, 149, 11, 4733},
	{4731, 332, 149, 11, 4783},
	{4780, 786, 149, 11, 4831},
	{4838, 99, 149, 11, 4889},
	{4901, 658, 149, 11, 4951},
	{4954, 794, 149, 11, 5003},
	{5008, 37, 151, 11, 5059},
	{5063, 471, 151, 11, 5113},
	{5116, 94, 157, 11, 5171},
	{5172, 873, 157, 11, 5227},
	{5225, 918, 157, 11, 5279},
	{5279, 945, 157, 11, 5333},
	{5334, 211, 157, 11, 5387},
	{5391, 341, 157, 11, 5443},
	{5449, 11, 163, 11, 5507},
	{5506, 578, 163, 11, 5563},
	{5566, 494, 163, 11, 5623},
	{5637, 694, 163, 11, 5693},
	{5694, 252, 163, 11, 5749},
	{5763, 451, 167, 11, 5821},
	{5823, 83, 167, 11, 5881},
	{5896, 689, 167, 11, 5953},
	{5975, 488, 173, 11, 6037},
	{6039, 214, 173, 11, 6101},
	{6102, 17, 173, 11, 6163},
	{6169, 469, 173, 11, 6229},
	{6233, 263, 179, 11, 6299},
	{6296, 309, 179, 11, 6361},
	{6363, 984, 179, 11, 6427},
	{6427, 123, 179, 11, 6491},
	{6518, 360, 179, 11, 6581},
	{6589, 863, 181, 11, 6653},
	{6655, 122, 181, 11, 6719},
	{6730, 522, 191, 11, 6803},
	{6799, 539, 191, 11, 6871},
	{6878, 181, 191, 11, 6949},
	{6956, 64, 191, 11, 7027},
	{7033, 387, 191, 11, 7103},
	{7108, 967, 191, 11, 7177},
	{7185, 843, 191, 11, 7253},
	{7281, 999, 193, 11, 7351},
	{7360, 76, 197, 11, 7433},
	{7445, 142, 197, 11, 7517},
	{7520, 599, 197, 11, 7591},
	{7596, 576, 199, 11, 7669},
	{7675, 176, 211, 11, 7759},
	{7770, 392, 211, 11, 7853},
	{7855, 332, 211, 11, 7937},
	{7935, 291, 211, 11, 8017},
	{8030, 913, 211, 11, 8111},
	{8111, 608, 211, 11, 8191},
	{8194, 212, 211, 11, 8273},
	{8290, 696, 211, 11, 8369},
	{8377, 931, 223, 11, 8467},
	{8474, 326, 223, 11, 8563},
	{8559, 228, 223, 11, 8647},
	{8654, 706, 223, 11, 8741},
	{8744, 144, 223, 11, 8831},
	{8837, 83, 223, 11, 8923},
	{8928, 743, 223, 11, 9013},
	{9019, 187, 223, 11, 9103},
	{9111, 654, 227, 11, 9199},
	{9206, 359, 227, 11, 9293},
	{9303, 493, 229, 11, 9391},
	{9400, 369, 233, 11, 9491},
	{9497, 981, 233, 11, 9587},
	{9601, 276, 239, 11, 9697},
	{9708, 647, 239, 11, 9803},
	{9813, 389, 239, 11, 9907},
	{9916, 80, 239, 11, 10009},
	{10017, 396, 241, 11, 10111},
	{10120, 580, 251, 11, 10223},
	{10241, 873, 251, 11, 10343},
	{10351, 15, 251, 11, 10453},
	{10458, 976, 251, 11, 10559},
	{10567, 584, 251, 11, 10667},
	{10676, 267, 257, 11, 10781},
	{10787, 876, 257, 11, 10891},
	{10899, 642, 257, 12, 11003},
	{11015, 794, 257, 12, 11119},
	{11130, 78, 263, 12, 11239},
	{11245, 736, 263, 12, 11353},
	{11358, 882, 269, 12, 11471},
	{11475, 251, 269, 12, 11587},
	{11590, 434, 269, 12, 11701},
	{11711, 204, 269, 12, 11821},
	{11829, 256, 271, 12, 11941},
	{11956, 106, 277, 12, 12073},
	{12087, 375, 277, 12, 12203},
	{12208, 148, 277, 12, 12323},
	{12333, 496, 281, 12, 12451},
	{12460, 88, 281, 12, 12577},
	{12593, 826, 293, 12, 12721},
	{12726, 71, 293, 12, 12853},
	{12857, 925, 293, 12, 12983},
	{13002, 760, 293, 12, 13127},
	{13143, 130, 293, 12, 13267},
	{13284, 641, 307, 12, 13421},
	{13417, 400, 307, 12, 13553},
	{13558, 480, 307, 12, 13693},
	{13695, 76, 307, 12, 13829},
	{13833, 665, 307, 12, 13967},
	{13974, 910, 307, 12, 14107},
	{14115, 467, 311, 12, 14251},
	{14272, 964, 311, 12, 14407},
	{14415, 625, 313, 12, 14551},
	{14560, 362, 317, 12, 14699},
	{14713, 759, 317, 12, 14851},
	{14862, 728, 331, 12, 15013},
	{15011, 343, 331, 12, 15161},
	{15170, 113, 331, 12, 15319},
	{15325, 137, 331, 12, 15473},
	{15496, 308, 331, 12, 15643},
	{15651, 800, 337, 12, 15803},
	{15808, 177, 337, 12, 15959},
	{15977, 961, 337, 12, 16127},
	{16161, 958, 347, 12, 16319},
	{16336, 72, 347, 12, 16493},
	{16505, 732, 347, 12, 16661},
	{16674, 145, 349, 12, 16831},
	{16851, 577, 353, 12, 17011},
	{17024, 305, 353, 12, 17183},
	{17195, 50, 359, 12, 17359},
	{17376, 351, 359, 12, 17539},
	{17559, 175, 367, 12, 17729},
	{17742, 727, 367, 12, 17911},
	{17929, 902, 367, 12, 18097},
	{18116, 409, 373, 12, 18289},
	{18309, 776, 373, 12, 18481},
	{18503, 586, 379, 12, 18679},
	{18694, 451, 379, 12, 18869},
	{18909, 287, 383, 12, 19087},
	{19126, 246, 389, 12, 19309},
	{19325, 222, 389, 12, 19507},
	{19539, 563, 397, 12, 19727},
	{19740, 839, 397, 12, 19927},
	{19939, 897, 401, 12, 20129},
	{20152, 409, 401, 12, 20341},
	{20355, 618, 409, 12, 20551},
	{20564, 439, 409, 12, 20759},
	{20778, 95, 419, 13, 20983},
	{20988, 448, 419, 13, 21191},
	{21199, 133, 419, 13, 21401},
	{21412, 938, 419, 13, 21613},
	{21629, 423, 431, 13, 21841},
	{21852, 90, 431, 13, 22063},
	{22073, 640, 431, 13, 22283},
	{22301, 922, 433, 13, 22511},
	{22536, 250, 439, 13, 22751},
	{22779, 367, 439, 13, 22993},
	{23010, 447, 443, 13, 23227},
	{23252, 559, 449, 13, 23473},
	{23491, 121, 457, 13, 23719},
	{23730, 623, 457, 13, 23957},
	{23971, 450, 457, 13, 24197},
	{24215, 253, 461, 13, 24443},
	{24476, 106, 467, 13, 24709},
	{24721, 863, 467, 13, 24953},
	{24976, 148, 479, 13, 25219},
	{25230, 427, 479, 13, 25471},
	{25493, 138, 479, 13, 25733},
	{25756, 794, 487, 13, 26003},
	{26022, 247, 487, 13, 26267},
	{26291, 562, 491, 13, 26539},
	{26566, 53, 499, 13, 26821},
	{26838, 135, 499, 13, 27091},
	{27111, 21, 503, 13, 27367},
	{27392, 201, 509, 13, 27653},
	{27682, 169, 521, 13, 27953},
	{27959, 70, 521, 13, 28229},
	{28248, 386, 521, 13, 28517},
	{28548, 226, 523, 13, 28817},
	{28845, 3, 541, 13, 29131},
	{29138, 769, 541, 13, 29423},
	{29434, 590, 541, 13, 29717},
	{29731, 672, 541, 13, 30013},
	{30037, 713, 547, 13, 30323},
	{30346, 967, 547, 13, 30631},
	{30654, 368, 557, 14, 30949},
	{30974, 348, 557, 14, 31267},
	{31285, 119, 563, 14, 31583},
	{31605, 503, 569, 14, 31907},
	{31948, 181, 571, 14, 32251},
	{32272, 394, 577, 14, 32579},
	{32601, 189, 587, 14, 32917},
	{32932, 210, 587, 14, 33247},
	{33282, 62, 593, 14, 33601},
	{33623, 273, 593, 14, 33941},
	{33961, 554, 599, 14, 34283},
	{34302, 936, 607, 14, 34631},
	{34654, 483, 607, 14, 34981},
	{35031, 397, 613, 14, 35363},
	{35395, 241, 619, 14, 35731},
	{35750, 500, 631, 14, 36097},
	{36112, 12, 631, 14, 36457},
	{36479, 958, 641, 14, 36833},
	{36849, 524, 641, 14, 37201},
	{37227, 8, 643, 14, 37579},
	{37606, 100, 653, 14, 37967},
	{37992, 339, 653, 14, 38351},
	{38385, 804, 659, 14, 38749},
	{38787, 510, 673, 14, 39163},
	{39176, 18, 673, 14, 39551},
	{39576, 412, 677, 14, 39953},
	{39980, 394, 683, 14, 40361},
	{40398, 830, 691, 15, 40787},
	{40816, 535, 701, 15, 41213},
	{41226, 199, 701, 15, 41621},
	{41641, 27, 709, 15, 42043},
	{42067, 298, 709, 15, 42467},
	{42490, 368, 719, 15, 42899},
	{42916, 755, 727, 15, 43331},
	{43388, 379, 727, 15, 43801},
	{43840, 73, 733, 15, 44257},
	{44279, 387, 739, 15, 44701},
	{44729, 457, 751, 15, 45161},
	{45183, 761, 751, 15, 45613},
	{45638, 855, 757, 15, 46073},
	{46104, 370, 769, 15, 46549},
	{46574, 261, 769, 15, 47017},
	{47047, 299, 787, 15, 47507},
	{47523, 920, 787, 15, 47981},
	{48007, 269, 787, 15, 48463},
	{48489, 862, 797, 15, 48953},
	{48976, 349, 809, 15, 49451},
	{49470, 103, 809, 15, 49943},
	{49978, 115, 821, 15, 50461},
	{50511, 93, 821, 16, 50993},
	{51017, 982, 827, 16, 51503},
	{51530, 432, 839, 16, 52027},
	{52062, 340, 853, 16, 52571},
	{52586, 173, 853, 16, 53093},
	{53114, 421, 857, 16, 53623},
	{53650, 330, 863, 16, 54163},
	{54188, 624, 877, 16, 54713},
	{54735, 233, 877, 16, 55259},
	{55289, 362, 883, 16, 55817},
	{55843, 963, 907, 16, 56393},
	{56403, 471, 907, 16, 56951}
};

struct rq_s {
	matrix_sched_t *sched;
	part_t src_part;
	part_t sub_part;
	uint8_t *obj; /* pointer to source object data */
	uint8_t *sym; /* pointer to current symbol */
	uint8_t *rep; /* pointer to last repair symbol */
	uint8_t *C; /* storage for intermediate symbols for all blocks (LxTxZ) */
	uint8_t  SBN; /* next SBI to return by rq_symbol_next() */
	uint32_t ESI; /* next symbol to return by rq_symbol_next() */
	/* F: the transfer length of the source object, in octets (40 bits) */
	uint64_t F;
	/* WS: the maximum size block that is decodable in working memory */
	size_t WS;
	/* Kt is the total number of symbols required to represent the source data of the object */
	uint64_t Kt;
	size_t kl;
	/* Al: the symbol alignment parameter, in octets (recommended: 4) */
	uint8_t Al;
	/* P' (PP): the maximum payload size in octets, which is assumed to be a multiple of Al */
	//uint16_t PP; Not required => P' == T
	/* T: symbol size, MUST be a multiple of Al */
	uint16_t T;
	/* sub-symbol size */
	uint16_t SSS;
	/* SS: a parameter where the desired lower bound on the sub-symbol size is SS*Al */
	uint16_t SS;
	uint16_t Nmax;
	/* Z: the number of source blocks */
	uint16_t Z;
	/* N: the number of sub-blocks in each source block */
	uint16_t N;
	/* K: the number of symbols in a source block */
	uint16_t K;
	/* K': K' smallest K' >= K in Table 2 */
	uint16_t KP;
	uint16_t J;
	uint16_t H;
	uint16_t S;
	uint16_t W;
	uint16_t L;
	uint16_t P;
	/* P1 denote the smallest prime number greater than or equal to P */
	uint16_t P1;
	uint16_t U;
	uint16_t B;
	uint32_t Nesi;
	int nsrc; /* number of source symbols received (ESI < K) */
	int nrep; /* number of repair symbols received (ESI >= K) */
};

#define T2LEN sizeof T2 / sizeof T2[0]
#define KP_MAX 56403

matrix_t rq_matrix_C_by_SBN(const rq_t *rq, const uint8_t SBN);
void rq_block(rq_t *rq); /* calculate params based on K */

/* generate n symbols, starting at ISI from.  pass in preallocated buffer blk.
 * ISIs >= K are repair symbols */
uint8_t *rq_encode_block(const rq_t *rq, const matrix_t *C, uint8_t *blk,
		const uint32_t from, const uint32_t n);

void rq_generate_matrix_A(const rq_t *rq, matrix_t *A, uint32_t lt);
matrix_t rq_matrix_D(const rq_t *rq, const unsigned char *blk, uint32_t N);
matrix_t rq_intermediate_symbols(matrix_t *A, const matrix_t *D, uint8_t *base);
uint8_t *rq_encode_symbol(const rq_t *rq, const matrix_t *C, const uint32_t isi, uint8_t *sym);

void rq_decoding_matrix_A(rq_t *rq, matrix_t *A, rq_blkmap_t *sym, rq_blkmap_t *rep);

uint8_t *rq_decode_C(rq_t *rq, matrix_t *D);

void rq_encoder_rfc6330_phase0(rq_t *rq, matrix_t *A);
void rq_decoder_rfc6330_phase0(rq_t *rq, matrix_t *A, uint8_t *dec, uint8_t *enc, uint32_t ESI[],
		uint32_t nesi);
int rq_decoder_rfc6330_phase1(const rq_t *rq, matrix_t *A, int *i, int *u);
int rq_decoder_rfc6330_phase2(rq_t *rq, matrix_t *A, int *i, int *u);
int rq_decoder_rfc6330_phase3(rq_t *rq, matrix_t *A, int *i, int *u);

part_t rq_partition(const size_t I, const uint16_t J);
size_t rq_rand(size_t y, uint8_t i, size_t m);
int rq_deg(const rq_t *rq, const int v);
rq_tuple_t rq_tuple(const rq_t *rq, const uint32_t X);


/* debug functions - disabled when NDEBUG defined */
#ifndef NDEBUG
void rq_dump(const rq_t *rq, FILE *stream);
void rq_dump_symbol(const rq_t *rq, const uint8_t *sym, FILE *stream);
#else
# define rq_dump(a, b)
# define rq_dump_symbol(a, b, c)
#endif

#endif /* LCRQ_PVT_H */
