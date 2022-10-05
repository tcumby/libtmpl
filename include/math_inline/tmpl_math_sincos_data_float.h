#ifndef TMPL_MATH_SINCOS_DATA_FLOAT_H
#define TMPL_MATH_SINCOS_DATA_FLOAT_H

#include <libtmpl/include/tmpl_config.h>

#if TMPL_HAS_IEEE754_FLOAT == 1

static const float tmpl_Float_SinCos_Table[440] = {
    0.0000000000000000000000000000E+00F, 0.0000000000000000000000000000E+00F,
    1.0000000000000000000000000000E+00F, 0.0000000000000000000000000000E+00F,
    7.8124205273828314574635633960E-03F, -4.1027557093826169084400491361E-19F,
    9.9996948257709505902823821088E-01F, 5.4277914283717882106897365652E-17F,
    1.5624364224883372301300177298E-02F, -1.2650937552759818835837845946E-19F,
    9.9987793217100662257479370964E-01F, 3.2161222299723411104472873844E-17F,
    2.3435354291722571701273025723E-02F, 1.0500785515068912742289956906E-19F,
    9.9972535436949949705365270347E-01F, 4.6667145441133907000012785004E-17F,
    3.1244913985326080302362683482E-02F, -1.5627815622254329979920780920E-18F,
    9.9951175848513640342929420512E-01F, -3.4188064879729469107393539522E-17F,
    3.9052566650422150529298193077E-02F, 1.1342467037138512016263821367E-18F,
    9.9923715755470898791656964021E-01F, 1.1089280858439993728180614665E-17F,
    4.6857835748134242515039460386E-02F, -2.3419368365610253549054406236E-18F,
    9.9890156833844290229507123513E-01F, -2.1425557800399754364674101258E-17F,
    5.4660244885066461284495176187E-02F, 3.3738319353517742315024153391E-19F,
    9.9850501131897406725812516015E-01F, 1.7799308706206641533895380582E-17F,
    6.2459317842380200624941011255E-02F, -2.0402595045857108132964186126E-18F,
    9.9804751070009911639857591580E-01F, 3.3232291674141345531920899752E-17F,
    7.0254578604860049018121515018E-02F, -6.7738909003013733298889721839E-18F,
    9.9752909440529780038531271202E-01F, 5.1120860578872347550233917415E-18F,
    7.8045551389967313116180491761E-02F, -5.4494437820057935726870534833E-18F,
    9.9694979407602868359816739030E-01F, -1.2467075728553626440860857688E-17F,
    8.5831760676879351179557886553E-02F, -3.4900371672318246520345836492E-18F,
    9.9630964506979802219888142644E-01F, -1.1743657041590172453535564735E-18F,
    9.3612731235512891547756453292E-02F, 1.4628632005878733106066671571E-18F,
    9.9560868645800171261583955129E-01F, 3.3129224309329911492434590164E-17F,
    1.0138798815552964305286565149E-01F, 3.9924285683580703498959397671E-18F,
    9.9484696102354064350947737693E-01F, -8.1982783332587056487189578146E-18F,
    1.0915705687532235856895823644E-01F, 6.6284699502736665630972438487E-18F,
    9.9402451525820911815145564105E-01F, 1.3287985046260087017112537385E-17F,
    1.1691946321097965166835308536E-01F, -2.2834125369700959204854999688E-18F,
    9.9314139935985767948523061932E-01F, 2.8553964189785564654098648887E-17F,
    1.2467473338522769288339020477E-01F, -2.9259474960578581848639425288E-18F,
    9.9219766722932900560039115589E-01F, 4.7548705751893640758977643520E-17F,
    1.3242239405634717575033221237E-01F, 1.2801053067990684431116073883E-17F,
    9.9119337646716820788839186207E-01F, 3.1426138811726996350687825152E-17F,
    1.4016197234706370688961385440E-01F, -9.9468471138834780672562014896E-18F,
    9.9012858837010708779047263305E-01F, -4.5899063535538112466203212775E-18F,
    1.4789299587340962172099523286E-01F, -1.3140968557128452024650623689E-17F,
    9.8900336792732290724927679548E-01F, 1.7676104005868335352578377527E-18F,
    1.5561499277355603232386727086E-01F, 8.8860533723422878199146977019E-18F,
    9.8781778381647189490877281059E-01F, 4.9191730223768100198463299310E-17F,
    1.6332749173661284536329674210E-01F, 5.4835694303471590078498366700E-18F,
    9.8657190839949759908478199577E-01F, -1.0327444588275445884005836097E-17F,
    1.7103002203139502923612269569E-01F, -9.9547747264529225883671274304E-18F,
    9.8526581771821386546150733920E-01F, -4.9257212629445548889564515659E-17F,
    1.7872211353515365939159664776E-01F, -1.6240405901073998690379947246E-20F,
    9.8389959148966399382629788306E-01F, -2.1647988531644274802587820589E-17F,
    1.8640329676226988220300029297E-01F, 2.3493796901281573126516806922E-18F,
    9.8247331310125529668653143744E-01F, -3.9199203754200877937525854712E-17F,
    1.9407310289290979898879641041E-01F, -7.8327412101986148792836191369E-18F,
    9.8098706960566917079091808773E-01F, 1.9678411808703028835780183372E-17F,
    2.0173106380163879913780533570E-01F, 5.5872328154601128014433144805E-18F,
    9.7944095171554834688976143297E-01F, 1.3108769521526759339970117373E-17F,
    2.0937671208599364924829444589E-01F, -5.5364036931721638366681479873E-18F,
    9.7783505379795976342194308017E-01F, 2.9910028492769483788234613590E-17F,
    2.1700958109501014559050702246E-01F, 1.1170071073364376073837231874E-17F,
    9.7616947386863528457467964472E-01F, -7.8506906092850274700355839000E-18F,
    2.2462920495770530293633271412E-01F, -1.0585904164329030738161388648E-17F,
    9.7444431358598893044842270683E-01F, 4.9901288349213957113769748439E-17F,
    2.3223511861151147073201173043E-01F, -8.3180808526872059948064650569E-18F,
    9.7265967824491272875064851177E-01F, 2.3920264546490164803820343682E-17F,
    2.3982685783066157170217991279E-01F, -7.2608106609797120064777457815E-18F,
    9.7081567677034941166169801363E-01F, 5.1285792532153653145908250239E-17F,
    2.4740395925452293712787366075E-01F, -7.5310249559070599238122839736E-18F,
    9.6891242171064473343022882545E-01F, 5.0714366624039358337866220065E-17F,
    2.5496596041587848979759201029E-01F, -2.2310035435425956659668282110E-17F,
    9.6695002923067785438604460068E-01F, -3.2377702977076922341774388330E-17F,
    2.6251239976915330398554715429E-01F, -2.2534597527902128018941346859E-17F,
    9.6492861910477101261562893341E-01F, -3.0345542681018625490045093431E-18F,
    2.7004281671858504365602016150E-01F, -1.2103265097887777091773660423E-17F,
    9.6284831470937970454571086520E-01F, -4.6460097717242409662816724113E-18F,
    2.7755675164633630824795318403E-01F, 1.7674070262791824934380452985E-17F,
    9.6070924301556193114492998574E-01F, -2.8078270635167290949787987814E-17F,
    2.8505374594054744274984614094E-01F, -1.8162083107618118425073070922E-17F,
    9.5851153458122861916734791520E-01F, 8.1346214929462547455013692133E-18F,
    2.9253334202332753610775739616E-01F, 7.5169449303273518975518262689E-18F,
    9.5625532354317532846010863067E-01F, -3.1484508688416289098608874018E-17F,
    2.9999508337868302509932050270E-01F, 2.6063927779307340080362356240E-17F,
    9.5394074760889469022373532425E-01F, 4.3757589471734984570217915796E-17F,
    3.0743851458038085056045929377E-01F, 1.1004366442765291674302660853E-19F,
    9.5156794804817224076032289303E-01F, -3.8614834675674123319609325633E-17F,
    3.1486318131974527778638162089E-01F, -2.6921345305772251886385348299E-17F,
    9.4913706968446298617436696076E-01F, 4.1491480460994451465707570474E-17F,
    3.2226863043338660475001233862E-01F, 2.0937733581266059730733549909E-17F,
    9.4664826088605336096293285663E-01F, -3.9116833349341519637772036490E-17F,
    3.2965440993086014831447982942E-01F, 2.3599837895703100160560383000E-17F,
    9.4410167355700436164767097579E-01F, -1.6017653284545848375913992971E-17F,
    3.3702006902225306594900189338E-01F, 1.0312279860787216149056394410E-17F,
    9.4149746312788107349689425973E-01F, -4.8523830236797103203539024839E-18F,
    3.4436515814569840232550745895E-01F, 5.8816645875179888023355297471E-18F,
    9.3883578854626548171324884606E-01F, 6.9193294599217877449658003193E-18F,
    3.5168922899481408483879363302E-01F, -2.5616208736069942137685366159E-17F,
    9.3611681226705534264453945070E-01F, -5.2350302039683216453580709426E-17F,
    3.5899183454606503618222745899E-01F, 1.7495482840158847559212850189E-17F,
    9.3334070024254844888389470725E-01F, -1.3228595477780879540733917750E-17F,
    3.6627252908604757131172391382E-01F, -9.9388145621065241831256259704E-18F,
    9.3050762191231428666071678890E-01F, 4.4887600033280737995079986775E-18F,
    3.7353086823869297017353119372E-01F, -2.3756691441061890274311070566E-17F,
    9.2761775019285186427708822520E-01F, 4.5350942573591973722189495177E-17F,
    3.8076640899239017068467205717E-01F, 2.1372528646211373684991774372E-17F,
    9.2467126146703604305798762652E-01F, 5.5444125388034563316327625488E-17F,
    3.8797870972702502845308458745E-01F, 1.7597995103359528680472632684E-17F,
    9.2166833557335192672610446607E-01F, -8.5506930978672431460149729344E-18F,
    3.9516733024093425585832051183E-01F, -1.9613487871414228141290891507E-17F,
    9.1860915579491830840197508223E-01F, -4.0564150104514996472154165808E-17F,
    4.0233183177777309680323014617E-01F, 1.4413875452702006733702330147E-17F,
    9.1549390884830117443016206379E-01F, 5.4133755668380422141193142380E-17F,
    4.0947177705329507180209702710E-01F, -5.6794030000912660379311852430E-18F,
    9.1232278487211782014298933063E-01F, 2.6349040211413332351821999739E-17F,
    4.1658673028204112886996313136E-01F, -9.6108506825337149321557128899E-18F,
    9.0909597741543102245032059727E-01F, 2.9200061138412112058096341065E-17F,
    4.2367625720393803367969098871E-01F, -2.3318007000688709392309584713E-17F,
    9.0581368342593637787985016984E-01F, 4.2864666490805214294812574293E-17F,
    4.3073992511080322342920112532E-01F, -2.6212879607476533030419024312E-17F,
    9.0247610323794147380027652616E-01F, 3.1124906746513261845655718115E-17F,
    4.3777730287275512521816267508E-01F, 7.6434562996202303026137242126E-18F,
    8.9908344056013844713959315413E-01F, 9.0769517750756159496631440874E-18F,
    4.4478796096452721808844898987E-01F, -6.6553929773449251342840102322E-18F,
    8.9563590246317070775461388620E-01F, -8.8540438857627159008774428404E-18F,
    4.5177147149168378481576269223E-01F, -8.2340739420989025740335450970E-18F,
    8.9213369936699438156324504234E-01F, 2.3160655211380165987051325224E-17F,
    4.5872740821673657629631293275E-01F, 1.6080982096218355795911653367E-17F,
    8.8857704502803558366252900668E-01F, -4.0344919983571670840306513992E-17F,
    4.6565534658516016808249560199E-01F, 1.4598703910514260085843646342E-17F,
    8.8496615652614329938785431295E-01F, -7.6905577759873569275402769867E-18F,
    4.7255486375130445475534202159E-01F, -3.6087907037905456803195749836E-18F,
    8.8130125425134064887089380135E-01F, -4.9730731893060662633736579285E-17F,
    4.7942553860420300537725779577E-01F, -5.1039698605560128980182626501E-18F,
    8.7758256189037275873943144688E-01F, -4.2623149864279996803986121942E-17F,
    4.8626695179327555917936365403E-01F, 1.5131647652857082612140470098E-17F,
    8.7381030641305446060584927181E-01F, 4.7676707565256570997992783595E-17F,
    4.9307868575392305166005257888E-01F, 5.6050839738717547398249853616E-18F,
    8.6998471805841737225506449249E-01F, 1.6573851107409228664831239861E-17F,
    4.9986032473301345024907504921E-01F, 1.3570481487732127577806381364E-17F,
    8.6610603032065669459882428782E-01F, 2.0097792543831332933985493054E-17F,
    5.0661145481425740033643023707E-01F, -3.2694134236181677445917180930E-17F,
    8.6217447993488049995391975244E-01F, 4.4132427578105804523148818199E-18F,
    5.1333166394347118366425775093E-01F, 3.4624543519281947322864618579E-17F,
    8.5819030686266040142129440937E-01F, -5.4374664844403744788570213910E-17F,
    5.2002054195372704459288115685E-01F, -3.9832667456984547651596748992E-17F,
    8.5415375427738537972288668242E-01F, 5.4205651026752869877689512329E-18F,
    5.2667768059038677641581216448E-01F, -4.5705022753862018701362086470E-17F,
    8.5006506854942021078613834106E-01F, 5.3170934558114159959598671712E-17F,
    5.3330267353602012203594995298E-01F, 5.1293181150320439857560425216E-17F,
    8.4592449923106793896465660509E-01F, 1.5495066473503288733583775257E-17F,
    5.3989511643520438077814560529E-01F, 2.4263515104613218121356079636E-17F,
    8.4173229904133839429647423457E-01F, -2.7333362440269661982856149817E-17F,
    5.4645460691920355600359471281E-01F, 8.3997548409295073933902789069E-18F,
    8.3748872385052364197832730496E-01F, 4.3337026043948395743545278341E-17F,
    5.5298074463052737659296553829E-01F, -6.7432704556117327938967039386E-18F,
    8.3319403266458136325667283017E-01F, -1.8644878796734314856252784088E-19F,
    5.5947313124736686162918886111E-01F, 1.5755655144887280310989418842E-17F,
    8.2884848760932572364623638350E-01F, 1.1163935406617444002353524558E-17F,
    5.6593137050790598419069965530E-01F, 6.5824594403885716404080843601E-18F,
    8.2445235391442917016746605440E-01F, 3.7318177543803779102640707012E-17F,
    5.7235506823450721380908134960E-01F, 2.6575872357215315675439249182E-17F,
    8.2000589989723404737986811596E-01F, -3.9124317482091280317774712499E-17F,
    5.7874383235777038247960035732E-01F, -2.7958488978746924265746741768E-17F,
    8.1550939694637547550115641570E-01F, 1.3751889684983783616319405902E-18F,
    5.8509727294046220968937177531E-01F, -5.4883972461161805006385434940E-17F,
    8.1096311950521793310286966516E-01F, -3.0913334861221786950880771816E-17F,
    5.9141500220131626441855132725E-01F, 5.0668448898504804563755941644E-17F,
    8.0636734505510387904791969049E-01F, 3.4650875715584733679055923478E-17F,
    5.9769663453870147673541168842E-01F, 5.4503235930543850191400033634E-17F,
    8.0172235409841841047295929456E-01F, 4.0134533311087013878714775839E-17F,
    6.0394178655415664547234655401E-01F, 1.1794923733511837067407480715E-17F,
    7.9702843014146829148103279294E-01F, 5.0523609948487484092622858097E-17F,
    6.1015007707579138607201230115E-01F, -1.4798269907589880023568078010E-17F,
    7.9228585967717857219128063661E-01F, -2.9049779312834575881019939275E-17F,
    6.1632112718155096509065060672E-01F, -2.2084950172964100288115582839E-17F,
    7.8749493216760613201188334642E-01F, -4.8080555050456574407967783422E-17F,
    6.2245456022234368909096247080E-01F, -6.0490357657097071445080543047E-18F,
    7.8265594002627281167150385954E-01F, -1.4740716412114870185349490579E-17F,
    6.2855000184502962667920655803E-01F, 3.5348797769901484765476691404E-17F,
    7.7776917860031791196462336301E-01F, -8.8424198493337866009797820886E-18F,
    6.3460708001526933141889230682E-01F, -3.4568582392624964791119675869E-17F,
    7.7283494615247150250070262700E-01F, 4.2310149218910232661138576347E-17F,
    6.4062542504023045619732101840E-01F, -4.7008911238993859445901565243E-17F,
    7.6785354384285031681400823799E-01F, 4.9065912521116423880062852258E-17F,
    6.4660466959115237006727738844E-01F, 4.5676477143932870652035235528E-19F,
    7.6282527571057623383410373207E-01F, 1.6672995021546627758725394034E-17F,
    6.5254444872576600200630991821E-01F, -4.5598735935930496868250896596E-17F,
    7.5775044865521934411844995338E-01F, -1.8782151211542039803924820655E-18F,
    6.5844439991056757932597065519E-01F, -3.7736386700306716899152532450E-17F,
    7.5262937241806648902553433799E-01F, -1.2970993013150525564016406903E-17F,
    6.6430416304294626073101426300E-01F, 1.5784492324431575364785593093E-17F,
    7.4746235956321616100694882334E-01F, 5.6627515613726675739836312072E-18F,
    6.7012338047316288847099485792E-01F, 6.1835367255749601282002650866E-18F,
    7.4224972545850131933065085831E-01F, -1.2339303604869521024464088827E-17F,
    6.7590169702617886038353844924E-01F, -5.1193896246098892421120243097E-17F,
    7.3699178825624078736922228927E-01F, -4.6312132903684967194711385285E-17F,
    6.8163876002333412262856882080E-01F, 4.4104673131979028742526292188E-17F,
    7.3168886887382089678766305951E-01F, -1.0475824306512767519665888343E-17F,
    6.8733421930387350595736961622E-01F, 2.8994333996809586326557675725E-17F,
    7.2634129097410859987604681009E-01F, -9.4658991798578323099661004399E-18F,
    6.9298772724631796382510628973E-01F, -5.3543290798909454949022198607E-17F,
    7.2094938094569638309394576936E-01F, 3.4949867014788160539919697907E-17F,
    6.9859893878968171154753008522E-01F, 2.9754399191881138249406404494E-17F,
    7.1551346788298153533958156913E-01F, 3.8181038992157035382855269160E-17F,
    7.0416751145453371218962956845E-01F, -3.9409570058482498479715265888E-17F,
    7.1003388356607965992139952504E-01F, 1.5052722118912909876273730696E-17F,
    7.0969310536389973442794598668E-01F, -9.4682769585421172943253505516E-18F,
    7.0451096244057465067811563130E-01F, -4.4513986149762259673767537819E-17F,
    7.1517538326400764692181155623E-01F, -1.4660995783282281352437174339E-17F,
    6.9894504159710568735874858248E-01F, -5.5261332036460915470542856483E-18F,
    7.2061401054487106421220232732E-01F, 1.1056944561373619474483324730E-17F,
    6.9333646075079335968638361009E-01F, 1.2822831674529968745570787945E-17F,
    7.2600865526071256539353271364E-01F, -1.5736218153395868831308015586E-17F,
    6.8768556222050480908336567154E-01F, 3.5430696752823923473464857147E-17F,
    7.3135898815022359897852766152E-01F, 2.6553630314845697304665853355E-17F,
    6.8199269090796055259318109165E-01F, 2.8089333561212785408205657880E-17F,
    7.3666468265666140702307984611E-01F, -4.6397233748754288482898339274E-17F,
    6.7625819427668332206593504452E-01F, 3.4970023993942477508027178561E-17F,
    7.4192541494777963784201801900E-01F, 2.9074827569875119594109808933E-18F,
    6.7048242233079080598656673828E-01F, 5.4258089975716480579102755824E-17F,
    7.4714086393559420162802098275E-01F, 2.9374987880282120204976277656E-17F,
    6.6466572759363329314652446555E-01F, -5.2874573286772265931847777683E-17F,
    7.5231071129598037217078854155E-01F, -4.0786618257566396963801471381E-17F,
    6.5880846508627688429271529457E-01F, 1.7760805237087261826634296830E-17F
};

#else

static const float tmpl_Float_Cos_Lookup_Table[128] = {
    1.000000000000000000000000000000000000000F,
    0.9996988186962042201157656496661721968501F,
    0.9987954562051723927147716047591006944432F,
    0.9972904566786902161355971401825678211717F,
    0.9951847266721968862448369531094799215755F,
    0.9924795345987099981567672516611178200108F,
    0.9891765099647809734516737380162430639837F,
    0.9852776423889412447740184331785477871601F,
    0.9807852804032304491261822361342390369739F,
    0.9757021300385285444603957664195279716440F,
    0.9700312531945439926039842072861002514569F,
    0.9637760657954398666864643555078351536631F,
    0.9569403357322088649357978869802699694828F,
    0.9495281805930366671959360741893450282522F,
    0.9415440651830207784125094025995023571856F,
    0.9329927988347388877116602555433024982950F,
    0.9238795325112867561281831893967882868224F,
    0.9142097557035306546350148293935774010447F,
    0.9039892931234433315862002972305370487101F,
    0.8932243011955153203424164474933979780006F,
    0.8819212643483550297127568636603883495084F,
    0.8700869911087114186522924044838488439108F,
    0.8577286100002720699022699842847701370425F,
    0.8448535652497070732595712051049570977198F,
    0.8314696123025452370787883776179057567386F,
    0.8175848131515836965049208841306338094710F,
    0.8032075314806449098066765129631419238796F,
    0.7883464276266062620091647053596892826565F,
    0.7730104533627369608109066097584698009710F,
    0.7572088465064845475754640536057844730404F,
    0.7409511253549590911756168974951627297290F,
    0.7242470829514669209410692432905531674831F,
    0.7071067811865475244008443621048490392848F,
    0.6895405447370669246167306299574847028455F,
    0.6715589548470184006253768504274218032288F,
    0.6531728429537767640842030136563054150769F,
    0.6343932841636454982151716132254933706757F,
    0.6152315905806268454849135634139842776594F,
    0.5956993044924333434670365288299698895119F,
    0.5758081914178453007459724538157308417760F,
    0.5555702330196022247428308139485328743749F,
    0.5349976198870972106630769046370179155603F,
    0.5141027441932217265936938389688157726080F,
    0.4928981922297840368730266887588092682397F,
    0.4713967368259976485563876259052543776575F,
    0.4496113296546066000462945794242270758832F,
    0.4275550934302820943209668568887985343046F,
    0.4052413140049898709084813055050524665119F,
    0.3826834323650897717284599840303988667613F,
    0.3598950365349881487751045723267564202023F,
    0.3368898533922200506892532126191475704778F,
    0.3136817403988914766564788459941003099934F,
    0.2902846772544623676361923758173952746915F,
    0.2667127574748983863252865151164363940421F,
    0.2429801799032638899482741620774711183210F,
    0.2191012401568697972277375474973577988484F,
    0.1950903220161282678482848684770222409277F,
    0.1709618887603012263636423572082635319663F,
    0.1467304744553617516588501296467178197062F,
    0.1224106751992161984987044741509457875752F,
    0.09801714032956060199419556388864184586114F,
    0.07356456359966742352946562157523432181330F,
    0.04906767432741801425495497694268265831475F,
    0.02454122852291228803173452945928292506547F,
    0.00000000000000000000000000000000000000000F,
    -0.02454122852291228803173452945928292506547F,
    -0.04906767432741801425495497694268265831475F,
    -0.07356456359966742352946562157523432181330F,
    -0.09801714032956060199419556388864184586114F,
    -0.1224106751992161984987044741509457875752F,
    -0.1467304744553617516588501296467178197062F,
    -0.1709618887603012263636423572082635319663F,
    -0.1950903220161282678482848684770222409277F,
    -0.2191012401568697972277375474973577988484F,
    -0.2429801799032638899482741620774711183210F,
    -0.2667127574748983863252865151164363940421F,
    -0.2902846772544623676361923758173952746915F,
    -0.3136817403988914766564788459941003099934F,
    -0.3368898533922200506892532126191475704778F,
    -0.3598950365349881487751045723267564202023F,
    -0.3826834323650897717284599840303988667613F,
    -0.4052413140049898709084813055050524665119F,
    -0.4275550934302820943209668568887985343046F,
    -0.4496113296546066000462945794242270758832F,
    -0.4713967368259976485563876259052543776575F,
    -0.4928981922297840368730266887588092682397F,
    -0.5141027441932217265936938389688157726080F,
    -0.5349976198870972106630769046370179155603F,
    -0.5555702330196022247428308139485328743749F,
    -0.5758081914178453007459724538157308417760F,
    -0.5956993044924333434670365288299698895119F,
    -0.6152315905806268454849135634139842776594F,
    -0.6343932841636454982151716132254933706757F,
    -0.6531728429537767640842030136563054150769F,
    -0.6715589548470184006253768504274218032288F,
    -0.6895405447370669246167306299574847028455F,
    -0.7071067811865475244008443621048490392848F,
    -0.7242470829514669209410692432905531674831F,
    -0.7409511253549590911756168974951627297290F,
    -0.7572088465064845475754640536057844730404F,
    -0.7730104533627369608109066097584698009710F,
    -0.7883464276266062620091647053596892826565F,
    -0.8032075314806449098066765129631419238796F,
    -0.8175848131515836965049208841306338094710F,
    -0.8314696123025452370787883776179057567386F,
    -0.8448535652497070732595712051049570977198F,
    -0.8577286100002720699022699842847701370425F,
    -0.8700869911087114186522924044838488439108F,
    -0.8819212643483550297127568636603883495084F,
    -0.8932243011955153203424164474933979780006F,
    -0.9039892931234433315862002972305370487101F,
    -0.9142097557035306546350148293935774010447F,
    -0.9238795325112867561281831893967882868224F,
    -0.9329927988347388877116602555433024982950F,
    -0.9415440651830207784125094025995023571856F,
    -0.9495281805930366671959360741893450282522F,
    -0.9569403357322088649357978869802699694828F,
    -0.9637760657954398666864643555078351536631F,
    -0.9700312531945439926039842072861002514569F,
    -0.9757021300385285444603957664195279716440F,
    -0.9807852804032304491261822361342390369739F,
    -0.9852776423889412447740184331785477871601F,
    -0.9891765099647809734516737380162430639837F,
    -0.9924795345987099981567672516611178200108F,
    -0.9951847266721968862448369531094799215755F,
    -0.9972904566786902161355971401825678211717F,
    -0.9987954562051723927147716047591006944432F,
    -0.9996988186962042201157656496661721968501F
};

static const float tmpl_Float_Sin_Lookup_Table[128] = {
    0.00000000000000000000000000000000000000000F,
    0.02454122852291228803173452945928292506547F,
    0.04906767432741801425495497694268265831475F,
    0.07356456359966742352946562157523432181330F,
    0.09801714032956060199419556388864184586114F,
    0.1224106751992161984987044741509457875752F,
    0.1467304744553617516588501296467178197062F,
    0.1709618887603012263636423572082635319663F,
    0.1950903220161282678482848684770222409277F,
    0.2191012401568697972277375474973577988484F,
    0.2429801799032638899482741620774711183210F,
    0.2667127574748983863252865151164363940421F,
    0.2902846772544623676361923758173952746915F,
    0.3136817403988914766564788459941003099934F,
    0.3368898533922200506892532126191475704778F,
    0.3598950365349881487751045723267564202023F,
    0.3826834323650897717284599840303988667613F,
    0.4052413140049898709084813055050524665119F,
    0.4275550934302820943209668568887985343046F,
    0.4496113296546066000462945794242270758832F,
    0.4713967368259976485563876259052543776575F,
    0.4928981922297840368730266887588092682397F,
    0.5141027441932217265936938389688157726080F,
    0.5349976198870972106630769046370179155603F,
    0.5555702330196022247428308139485328743749F,
    0.5758081914178453007459724538157308417760F,
    0.5956993044924333434670365288299698895119F,
    0.6152315905806268454849135634139842776594F,
    0.6343932841636454982151716132254933706757F,
    0.6531728429537767640842030136563054150769F,
    0.6715589548470184006253768504274218032288F,
    0.6895405447370669246167306299574847028455F,
    0.7071067811865475244008443621048490392848F,
    0.7242470829514669209410692432905531674831F,
    0.7409511253549590911756168974951627297290F,
    0.7572088465064845475754640536057844730404F,
    0.7730104533627369608109066097584698009710F,
    0.7883464276266062620091647053596892826565F,
    0.8032075314806449098066765129631419238796F,
    0.8175848131515836965049208841306338094710F,
    0.8314696123025452370787883776179057567386F,
    0.8448535652497070732595712051049570977198F,
    0.8577286100002720699022699842847701370425F,
    0.8700869911087114186522924044838488439108F,
    0.8819212643483550297127568636603883495084F,
    0.8932243011955153203424164474933979780006F,
    0.9039892931234433315862002972305370487101F,
    0.9142097557035306546350148293935774010447F,
    0.9238795325112867561281831893967882868224F,
    0.9329927988347388877116602555433024982950F,
    0.9415440651830207784125094025995023571856F,
    0.9495281805930366671959360741893450282522F,
    0.9569403357322088649357978869802699694828F,
    0.9637760657954398666864643555078351536631F,
    0.9700312531945439926039842072861002514569F,
    0.9757021300385285444603957664195279716440F,
    0.9807852804032304491261822361342390369739F,
    0.9852776423889412447740184331785477871601F,
    0.9891765099647809734516737380162430639837F,
    0.9924795345987099981567672516611178200108F,
    0.9951847266721968862448369531094799215755F,
    0.9972904566786902161355971401825678211717F,
    0.9987954562051723927147716047591006944432F,
    0.9996988186962042201157656496661721968501F,
    1.0000000000000000000000000000000000000000F,
    0.9996988186962042201157656496661721968501F,
    0.9987954562051723927147716047591006944432F,
    0.9972904566786902161355971401825678211717F,
    0.9951847266721968862448369531094799215755F,
    0.9924795345987099981567672516611178200108F,
    0.9891765099647809734516737380162430639837F,
    0.9852776423889412447740184331785477871601F,
    0.9807852804032304491261822361342390369739F,
    0.9757021300385285444603957664195279716440F,
    0.9700312531945439926039842072861002514569F,
    0.9637760657954398666864643555078351536631F,
    0.9569403357322088649357978869802699694828F,
    0.9495281805930366671959360741893450282522F,
    0.9415440651830207784125094025995023571856F,
    0.9329927988347388877116602555433024982950F,
    0.9238795325112867561281831893967882868224F,
    0.9142097557035306546350148293935774010447F,
    0.9039892931234433315862002972305370487101F,
    0.8932243011955153203424164474933979780006F,
    0.8819212643483550297127568636603883495084F,
    0.8700869911087114186522924044838488439108F,
    0.8577286100002720699022699842847701370425F,
    0.8448535652497070732595712051049570977198F,
    0.8314696123025452370787883776179057567386F,
    0.8175848131515836965049208841306338094710F,
    0.8032075314806449098066765129631419238796F,
    0.7883464276266062620091647053596892826565F,
    0.7730104533627369608109066097584698009710F,
    0.7572088465064845475754640536057844730404F,
    0.7409511253549590911756168974951627297290F,
    0.7242470829514669209410692432905531674831F,
    0.7071067811865475244008443621048490392848F,
    0.6895405447370669246167306299574847028455F,
    0.6715589548470184006253768504274218032288F,
    0.6531728429537767640842030136563054150769F,
    0.6343932841636454982151716132254933706757F,
    0.6152315905806268454849135634139842776594F,
    0.5956993044924333434670365288299698895119F,
    0.5758081914178453007459724538157308417760F,
    0.5555702330196022247428308139485328743749F,
    0.5349976198870972106630769046370179155603F,
    0.5141027441932217265936938389688157726080F,
    0.4928981922297840368730266887588092682397F,
    0.4713967368259976485563876259052543776575F,
    0.4496113296546066000462945794242270758832F,
    0.4275550934302820943209668568887985343046F,
    0.4052413140049898709084813055050524665119F,
    0.3826834323650897717284599840303988667613F,
    0.3598950365349881487751045723267564202023F,
    0.3368898533922200506892532126191475704778F,
    0.3136817403988914766564788459941003099934F,
    0.2902846772544623676361923758173952746915F,
    0.2667127574748983863252865151164363940421F,
    0.2429801799032638899482741620774711183210F,
    0.2191012401568697972277375474973577988484F,
    0.1950903220161282678482848684770222409277F,
    0.1709618887603012263636423572082635319663F,
    0.1467304744553617516588501296467178197062F,
    0.1224106751992161984987044741509457875752F,
    0.09801714032956060199419556388864184586114F,
    0.07356456359966742352946562157523432181330F,
    0.04906767432741801425495497694268265831475F,
    0.02454122852291228803173452945928292506547F
};

#endif

#endif
