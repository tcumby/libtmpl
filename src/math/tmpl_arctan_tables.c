/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify           *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl is distributed in the hope that it will be useful,                *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.         *
 ******************************************************************************/
#include <libtmpl/include/tmpl_config.h>

/*  These tables are only needed if libtmpl math algorithms are used.         */
#if TMPL_USE_MATH_ALGORITHMS == 1

/*  Declarations given here.                                                  */
#include <libtmpl/include/tmpl_math.h>

/*  Formula 4.4.34 from Abramowitz and Stegun states:                         *
 *                                                                            *
 *                                     u - v                                  *
 *          atan(u) = atan(v) + atan( -------- )                              *
 *                                     1 + uv                                 *
 *                                                                            *
 *  The values v and atan(v) are pre-computed below for the calculation.      */
const float tmpl_atan_float_v[8] = {
    0.05F, 0.18F, 0.35F, 0.72F, 1.35F, 2.5F, 4.0F, 8.0F
};

const float tmpl_atan_float_atan_of_v[8] = {
    4.99583957219427614100063E-02F,
    1.78092938231197549667920E-01F,
    3.36674819386727181396699E-01F,
    6.24023052976756847589791E-01F,
    9.33247528656203869893663E-01F,
    1.19028994968253173292773E+00F,
    1.32581766366803246505924E+00F,
    1.44644133224813518419997E+00F
};

const double tmpl_atan_double_v[8] = {
    0.05, 0.18, 0.35, 0.72, 1.35, 2.5, 4.0, 8.0
};

const double tmpl_atan_double_atan_of_v[8] = {
    4.99583957219427614100063E-02,
    1.78092938231197549667920E-01,
    3.36674819386727181396699E-01,
    6.24023052976756847589791E-01,
    9.33247528656203869893663E-01,
    1.19028994968253173292773E+00,
    1.32581766366803246505924E+00,
    1.44644133224813518419997E+00
};

/*  The long double version of these tables depends on how long double is     *
 *  implemented. 80-bit extended and 64-bit double implementations, as well   *
 *  as the "portable" version, use the same idea as double and float. 128-bit *
 *  quadruple uses a much larger table to speed up computations while still   *
 *  achieving 10^-34 peak relative error. 128-bit double-double uses the same *
 *  table as double and does not need any new tables.                         */
#if TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_96_BIT_EXTENDED_LITTLE_ENDIAN  || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_96_BIT_EXTENDED_BIG_ENDIAN     || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_128_BIT_EXTENDED_LITTLE_ENDIAN || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_128_BIT_EXTENDED_BIG_ENDIAN    || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_64_BIT_LITTLE_ENDIAN           || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_64_BIT_BIG_ENDIAN              || \
    TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_UNKNOWN
const long double tmpl_atan_ldouble_v[8] = {
    0.05L, 0.18L, 0.35L, 0.72L, 1.35L, 2.5L, 4.0L, 8.0L
};

const long double tmpl_atan_ldouble_atan_of_v[8] = {
    4.99583957219427614100063E-02L,
    1.78092938231197549667920E-01L,
    3.36674819386727181396699E-01L,
    6.24023052976756847589791E-01L,
    9.33247528656203869893663E-01L,
    1.19028994968253173292773E+00L,
    1.32581766366803246505924E+00L,
    1.44644133224813518419997E+00L
};

#elif TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_128_BIT_QUADRUPLE_BIG_ENDIAN || \
      TMPL_LDOUBLE_ENDIANNESS == TMPL_LDOUBLE_128_BIT_QUADRUPLE_LITTLE_ENDIAN

/*  The values atan(n/8) for n = 0, 1, ... , 127, 128.                        */
const long double tmpl_ldouble_atan_n_by_8[129] = {
    0.0000000000000000000000000000000000000000E+00L,
    1.2435499454676143503135484916387102557317E-01L,
    2.4497866312686415417208248121127581091414E-01L,
    3.5877067027057222039592006392646049977698E-01L,
    4.6364760900080611621425623146121440202854E-01L,
    5.5859931534356243597150821640166127034645E-01L,
    6.4350110879328438680280922871732263804151E-01L,
    7.1882999962162450541701415152590465395142E-01L,
    7.8539816339744830961566084581987572104929E-01L,
    8.4415398611317100251784414827164750652594E-01L,
    8.9605538457134395617480071802993782702458E-01L,
    9.4200004037946366473793717053459358607166E-01L,
    9.8279372324732906798571061101466601449688E-01L,
    1.0191413442663497346383429170230636487744E+00L,
    1.0516502125483736674598673120862998296302E+00L,
    1.0808390005411683108871567292171998202703E+00L,
    1.1071487177940905030170654601785370400700E+00L,
    1.1309537439791604464709335155363278047493E+00L,
    1.1525719972156675180401498626127513797495E+00L,
    1.1722738811284763866005949441337046149712E+00L,
    1.1902899496825317329277337748293183376012E+00L,
    1.2068173702852525303955115800565576303133E+00L,
    1.2220253232109896370417417439225704908830E+00L,
    1.2360594894780819419094519711090786987027E+00L,
    1.2490457723982544258299170772810901230778E+00L,
    1.2610933822524404193139408812473357720101E+00L,
    1.2722973952087173412961937498224804940684E+00L,
    1.2827408797442707473628852511364955306249E+00L,
    1.2924966677897852679030914214070816845853E+00L,
    1.3016288340091961438047858503666855921414E+00L,
    1.3101939350475556342564376891719053122733E+00L,
    1.3182420510168370498593302023271362531155E+00L,
    1.3258176636680324650592392104284756311844E+00L,
    1.3329603993374458675538498697331558093700E+00L,
    1.3397056595989995393283037525895557411039E+00L,
    1.3460851583802539310489409282517796256512E+00L,
    1.3521273809209546571891479413898128509842E+00L,
    1.3578579772154994751124898859640585287459E+00L,
    1.3633001003596939542892985278250991189943E+00L,
    1.3684746984165928776366381936948529556191E+00L,
    1.3734007669450158608612719264449611486510E+00L,
    1.3780955681325110444536609641291551522494E+00L,
    1.3825748214901258580599674177685685125566E+00L,
    1.3868528702577214543289381097042486034883E+00L,
    1.3909428270024183486427686943836432060856E+00L,
    1.3948567013423687823948122092044222644895E+00L,
    1.3986055122719575950126700816114282335732E+00L,
    1.4021993871854670105330304794336492676944E+00L,
    1.4056476493802697809521934019958079881002E+00L,
    1.4089588955564736949699075250792569287156E+00L,
    1.4121410646084952153676136718584891599630E+00L,
    1.4152014988178669079462550975833894394929E+00L,
    1.4181469983996314594038603039700989523716E+00L,
    1.4209838702219992566633046424614466661176E+00L,
    1.4237179714064941189018190466107297503086E+00L,
    1.4263547484202526397918060597281265695725E+00L,
    1.4288992721907326964184700745371983590908E+00L,
    1.4313562697035588982240194668401779312122E+00L,
    1.4337301524847089866404719096698873648610E+00L,
    1.4360250423171655234964275337155008780675E+00L,
    1.4382447944982225979614042479354815855386E+00L,
    1.4403930189057632173997301031392126865694E+00L,
    1.4424730991091018200252920599377292525125E+00L,
    1.4444882097316563655148453598508037025938E+00L,
    1.4464413322481351841999668424758804165254E+00L,
    1.4483352693775551917970437843145232637695E+00L,
    1.4501726582147939000905940595923466567576E+00L,
    1.4519559822271314199339700039142990228105E+00L,
    1.4536875822280323362423034480994649820285E+00L,
    1.4553696664279718992423082296859928222270E+00L,
    1.4570043196511885530074841089245667532358E+00L,
    1.4585935117976422128825857356750737658039E+00L,
    1.4601391056210009726721818194296893361233E+00L,
    1.4616428638860188872060496086383008594310E+00L,
    1.4631064559620759326975975316301202111560E+00L,
    1.4645314639038178118428450961503371619177E+00L,
    1.4659193880646627234129855241049975398470E+00L,
    1.4672716522843522691530527207287398276197E+00L,
    1.4685896086876430842559640450619880951144E+00L,
    1.4698745421276027686510391411132998919794E+00L,
    1.4711276743037345918528755717617308518553E+00L,
    1.4723501675822635384916444186631899205983E+00L,
    1.4735431285433308455179928682541563973416E+00L,
    1.4747076112775297156457696020843429121750E+00L,
    1.4758446204521402994740697066993045737807E+00L,
    1.4769551141655601073845643918489010491235E+00L,
    1.4780400066067528742912956492679274173081E+00L,
    1.4791001705350335920067055415092607945848E+00L,
    1.4801364395941515057329350163312858240725E+00L,
    1.4811496104734101005230254685700755826154E+00L,
    1.4821404449274591535866502155505515382824E+00L,
    1.4831096716653961446653884363217722221355E+00L,
    1.4840579881189115074204117986550232546263E+00L,
    1.4849860620983944584330588319254642223696E+00L,
    1.4858945333451746684000206793240900744035E+00L,
    1.4867840149874020396578063976185774328938E+00L,
    1.4876550949064553893206533769889701445675E+00L,
    1.4885083370202147351605477895533266305580E+00L,
    1.4893442824890256416375381678846838656578E+00L,
    1.4901634508497227996178425022670335106973E+00L,
    1.4909663410826593033383675000724190851828E+00L,
    1.4917534326163040343047464110667474168911E+00L,
    1.4925251862736186574372737258621480949375E+00L,
    1.4932820451641048379521906024777377613925E+00L,
    1.4940244355251185800019995584923659339920E+00L,
    1.4947527675157795396087307557692440871168E+00L,
    1.4954674359665565006171167688311694261887E+00L,
    1.4961688210873838771202975793537579544411E+00L,
    1.4968572891369562763722351552743516865583E+00L,
    1.4975331930556571615295846136533458351021E+00L,
    1.4981968730644019949034322665438486358775E+00L,
    1.4988486572315145661857645980708538360309E+00L,
    1.4994888620096062927989507017866583810753E+00L,
    1.5001177927442910140857596690590647397203E+00L,
    1.5007357441564411850523945880885632115724E+00L,
    1.5013430007995745002297298103299323309651E+00L,
    1.5019398374938520197571649905681176269652E+00L,
    1.5025265197380690797791405520832913365105E+00L,
    1.5031033041009279678124130530803583941493E+00L,
    1.5036704385927959126560829413161988499911E+00L,
    1.5042281630190728150326749973457803750007E+00L,
    1.5047767093162198170166093290594653407112E+00L,
    1.5053163018714318083306395218738285783435E+00L,
    1.5058471578268738696935788811632539967881E+00L,
    1.5063694873693430686317821563374018259572E+00L,
    1.5068834940061625962000055895618863582185E+00L,
    1.5073893748280646390591656283411759619585E+00L,
    1.5078873207597713231536332351575422706711E+00L,
    1.5083775167989392707573425786542463284923E+00L
};
#endif
/*  End of 64-bit / 80-bit extended / portables vs. 128-bit quadruple.        */

#endif
/*  End of #if TMPL_USE_MATH_ALGORITHMS == 1.                                 */
