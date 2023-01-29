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

/*  Declaration given here.                                                   */
#include <libtmpl/include/tmpl_math.h>

/*  The values exp(k/128) for k = -89, -88, ..., 0, 1, ..., 88, 89.           */
const double tmpl_double_exp_table[179] = {
    4.9891851158647191879092823249854371651191242010804E-01,
    5.0283157797094095968863661143762517988284294280110E-01,
    5.0677533491543867520925655179678850779143277893705E-01,
    5.1075002312901069057468918679066710593192624979176E-01,
    5.1475588520860707431677234859441289193716537103975E-01,
    5.1879316565388935634264545733732511343670700875892E-01,
    5.2286211088215367888213869819651544380338917577938E-01,
    5.2696296924337099115866906803717151252133851896855E-01,
    5.3109599103534520576894416059745889266841469139386E-01,
    5.3526142851899024195662250802204640543354412503602E-01,
    5.3945953593372688822139635268831454728479238286516E-01,
    5.4369056951300042401819177944149482622841245520983E-01,
    5.4795478749991994767176856090775404251508666262414E-01,
    5.5225245016302036506039772473070799917295715659073E-01,
    5.5658381981214800110895213697266754535205162967905E-01,
    5.6094916081447080367712126215845961656731258272024E-01,
    5.6534873961061411703301624305428549184224875619833E-01,
    5.6978282473092300976662968982912281588463847432800E-01,
    5.7425168681185214972192386665844161970294626916206E-01,
    5.7875559861248422631121277092238562215850349991105E-01,
    5.8329483503117792842145307042765714670039659920440E-01,
    5.8786967312234649402954487873169325112996145179631E-01,
    5.9248039211336785561324854476859269546665514571265E-01,
    5.9712727342162741347633443303759365420268441327068E-01,
    6.0181060067169447720158931214436344470960110720425E-01,
    6.0653065971263342360379953499118045344191813548719E-01,
    6.1128773863545062777731564103964146020694269192423E-01,
    6.1608212779067823211977720299440863481723688797714E-01,
    6.2091411980609582656554647631598407658727882266926E-01,
    6.2578400960459112167987445653519947423097081782701E-01,
    6.3069209442216070474831707092986532803872457688278E-01,
    6.3563867382605197754595022175772381681032362330999E-01,
    6.4062404973304738308802211305123183759998773780185E-01,
    6.4564852642789203734835568006103194636093977727958E-01,
    6.5071241058186589068460307294052801923769361340890E-01,
    6.5581601127150155253089225476332411449333915415538E-01,
    6.6095963999744892180903127905025159422320685690096E-01,
    6.6614361070348777446979135713018318624717332077968E-01,
    6.7136823979568946860642231035123308444010074605806E-01,
    6.7663384616172893668401461526449192902486125291503E-01,
    6.8194075119034814360116650331723968712436811355002E-01,
    6.8728927879097219854520233914651359043465202377252E-01,
    6.9267975541347931791948403319253363439577902522604E-01,
    6.9811251006812584601172923053588018740636310615796E-01,
    7.0358787434562754953627160433906045582185490275649E-01,
    7.0910618243739841172144741001650184234311878988997E-01,
    7.1466777115594816122635069673569149593475373620164E-01,
    7.2027297995543978085965396356218266870021124385763E-01,
    7.2592215095240825083763292783776606756731659760495E-01,
    7.3161562894664179115955942049140282528128115321985E-01,
    7.3735376144222687759683588850131867352425604746990E-01,
    7.4313689866875831578824393119743827272487226058391E-01,
    7.4896539360271566800807783497683992266858160044639E-01,
    7.5483960198900733732734709591752982734760020943583E-01,
    7.6075988236268362412127915002005870944044190333384E-01,
    7.6672659607082008018965954519570587764438505071107E-01,
    7.7274010729457249615074106509985723737491644991636E-01,
    7.7880078307140486824517026697832064729677229042614E-01,
    7.8490899331749170124425891412575195039024010875380E-01,
    7.9106511085029601479761327342227019934293834879347E-01,
    7.9726951141132443127927566892151244230243601155312E-01,
    8.0352257368906073399978458658728312801829650426039E-01,
    8.0982467934207929554458169971567811492905132030834E-01,
    8.1617621302233978697765129002110255575898567797414E-01,
    8.2257756239866458971383975106093870426905176009230E-01,
    8.2902911818040034301464550934308186242538840928345E-01,
    8.3553127414126507130107341150594850900249955272707E-01,
    8.4208442714338234680409836901154989805389498782696E-01,
    8.4868897716150395448907217057361072204842510667652E-01,
    8.5534532730742253769573163507101225277861436271498E-01,
    8.6205388385457571453102791680785303888183657142438E-01,
    8.6881505626284316673850353119134082911265133119176E-01,
    8.7562925720353821454610883360141542647451741383524E-01,
    8.8249690258459540286489214322905073622200482499065E-01,
    8.8941841157595563617464198106246174656833042851368E-01,
    8.9639420663515041149003619361375079393410439400547E-01,
    9.0342471353308671095289699509610658983690752941579E-01,
    9.1051036138003412784350488627625207581873329126241E-01,
    9.1765158265181581214733552110100285828657821017742E-01,
    9.2484881321620483425380527828838595297676435750877E-01,
    9.3210249235952757790140284911913503113492686093588E-01,
    9.3941306281347578611971082462230508452468089054944E-01,
    9.4678097078212889665405430710783214792632024265196E-01,
    9.5420666596918831619363028345123108267737679357916E-01,
    9.6169060160542529565975527801986070356505697303999E-01,
    9.6923323447634408184810919324635278360472575389656E-01,
    9.7683502495006203385834597965447957773307479320787E-01,
    9.8449643700540840598698882969702036970786100318035E-01,
    9.9221793826024351210593722611361783007089027101260E-01,
    1.0000000000000000000000000000000000000000000000000E+00,
    1.0078430972064479776934535597601235791933921498840E+00,
    1.0157477085866857474585350720823517489067162884822E+00,
    1.0237143166023579169688505321657689580745565901201E+00,
    1.0317434074991026709387478152815071441944983266418E+00,
    1.0398354713362300005766220098751917925969305800518E+00,
    1.0479910020166327022767382918196849669390532192406E+00,
    1.0562104973169319711813367037681297731537514884252E+00,
    1.0644944589178594295633905946428896731007254436494E+00,
    1.0728433924348774444113000950108137669286240070507E+00,
    1.0812578074490396031408946517428286548338916608472E+00,
    1.0897382175380932310182820254185122044095244819876E+00,
    1.0982851403078258486502099342567867188098263100638E+00,
    1.1068990974236574827876023937417789636307650142476E+00,
    1.1155806146424807586937045083794438798390782261205E+00,
    1.1243302218447507174517329054449565537714045938180E+00,
    1.1331484530668263168290072278117938725655031317452E+00,
    1.1420358465335655896761614313488004988947112115520E+00,
    1.1509929446911764493221396657803508410236922580336E+00,
    1.1600202942403251470292152138940958101001021943760E+00,
    1.1691184461695044022981846915118914445916046703834E+00,
    1.1782879557886632426631433081958559090232306216516E+00,
    1.1875293827631006055888078228331305661056264446587E+00,
    1.1968432911476247711821968527700683464587538762102E+00,
    1.2062302494209807106555860104464335480403936462000E+00,
    1.2156908305205474518300182545403968328635750251820E+00,
    1.2252256118773075794492659275775547905529260698723E+00,
    1.2348351754510910046840161108760027424078237285532E+00,
    1.2445201077660951549461989520766544581233530734001E+00,
    1.2542809999466837520048212530906856313930507114143E+00,
    1.2641184477534663633984346034590176916127065444219E+00,
    1.2740330516196609292764965387163400150598442500420E+00,
    1.2840254166877414840734205680624364583362808652815E+00,
    1.2940961528463733098261106268100709645926577196080E+00,
    1.3042458747676377754893000110524664638914930533372E+00,
    1.3144752019445491342841349219798729587973919652224E+00,
    1.3247847587288655689352375606889644453814644324632E+00,
    1.3351751743691967926110409106636134960513339824463E+00,
    1.3456470830494105314826030943160177231413009986119E+00,
    1.3562011239273402330584882593857570013204578364337E+00,
    1.3668379411737963628387567727212086721727332944308E+00,
    1.3775581840118836703607622378892548520433120652828E+00,
    1.3883625067566268243844374753000036641797537449137E+00,
    1.3992515688549068357862059454951895801349576287119E+00,
    1.4102260349257107056997279341815912975975335874046E+00,
    1.4212865748006967555595399377075767858324403710630E+00,
    1.4324338635650781149714379568249381105086461736848E+00,
    1.4436685815988268627523668434427752933667451961445E+00,
    1.4549914146182013360537936919875185083468420209644E+00,
    1.4664030537175991422072580622261772341235882048769E+00,
    1.4779041954117384278102094711614577636044573968831E+00,
    1.4894955416781699796055764474013653746366884178910E+00,
    1.5011778000001227519009843681945126839847194733559E+00,
    1.5129516834096854356243837541143330540396893952551E+00,
    1.5248179105313267046233088024596115443256307035313E+00,
    1.5367772056257567954863095631977568976482127559147E+00,
    1.5488302986341330979985519845954923375583036629258E+00,
    1.5609779252226124543404296589529359617213440719532E+00,
    1.5732208268272528862995610345959599306077297999814E+00,
    1.5855597506992674910940477323437952296789346099923E+00,
    1.5979954499506332678996451470842104572159357373404E+00,
    1.6105286836000576588368576715138990015137372593744E+00,
    1.6231602166193056100072398828952478310491124132776E+00,
    1.6358908199798899801726944886054803066336858485647E+00,
    1.6487212707001281468486507878141635716537761007101E+00,
    1.6616523518925676819330374640390175534089439553987E+00,
    1.6746848528117839915192948821484471915616397261784E+00,
    1.6878195689025528372446796287495748265689688026875E+00,
    1.7010573018484006794061834954848285349306956270529E+00,
    1.7143988596205358051369170173112717453784531664493E+00,
    1.7278450565271632281772015524381343960105588347356E+00,
    1.7413967132631863701982922765711232180120641174773E+00,
    1.7550546569602985572440470365989676887382375302457E+00,
    1.7688197212374673886484036560813297321717220170403E+00,
    1.7826927462518150597656831961070971624870767081346E+00,
    1.7966745787498977440179624291990663920674300962033E+00,
    1.8107660721193871641205304388476395701804873528693E+00,
    1.8249680864411575068942484398874703584971161910630E+00,
    1.8392814885417808608139669119715291919683603467489E+00,
    1.8537071520464343803765299877394712853248166534392E+00,
    1.8682459574322224065018356201881044531149722837226E+00,
    1.8828987920819167975074551877605054582064687859329E+00,
    1.8976665503381187507229937281862390730851715106946E+00,
    1.9125501335578454205362498947690069141803876587963E+00,
    1.9275504501675446645908831925937307660930032991508E+00,
    1.9426684157185412759862975831367569870468296891064E+00,
    1.9579049529429180856664000618841160115832720792658E+00,
    1.9732609918098353457263977417630639167722963005157E+00,
    1.9887374695822918311174773496469253668482551764106E+00,
    2.0043353308743311241896996041635187235500791639992E+00
};
