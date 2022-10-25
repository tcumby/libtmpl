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

/*  Include guard to prevent including this file twice.                       */
#ifndef TMPL_MATH_COSPI_LOOKUP_TABLE_FLOAT_H
#define TMPL_MATH_COSPI_LOOKUP_TABLE_FLOAT_H

/*  The values cos(pi*k/128) for k = 0, 1, ..., 127.                          */
static const float tmpl_Float_CosPi_Lookup_Table[128] = {
    1.0000000000000000000000000000000000000000F,
    0.99969881869620422011576564966617219685006F,
    0.99879545620517239271477160475910069444320F,
    0.99729045667869021613559714018256782117169F,
    0.99518472667219688624483695310947992157547F,
    0.99247953459870999815676725166111782001082F,
    0.98917650996478097345167373801624306398369F,
    0.98527764238894124477401843317854778716013F,
    0.98078528040323044912618223613423903697393F,
    0.97570213003852854446039576641952797164401F,
    0.97003125319454399260398420728610025145687F,
    0.96377606579543986668646435550783515366308F,
    0.95694033573220886493579788698026996948285F,
    0.94952818059303666719593607418934502825222F,
    0.94154406518302077841250940259950235718559F,
    0.93299279883473888771166025554330249829502F,
    0.92387953251128675612818318939678828682242F,
    0.91420975570353065463501482939357740104469F,
    0.90398929312344333158620029723053704871013F,
    0.89322430119551532034241644749339797800063F,
    0.88192126434835502971275686366038834950844F,
    0.87008699110871141865229240448384884391083F,
    0.85772861000027206990226998428477013704249F,
    0.84485356524970707325957120510495709771979F,
    0.83146961230254523707878837761790575673856F,
    0.81758481315158369650492088413063380947104F,
    0.80320753148064490980667651296314192387957F,
    0.78834642762660626200916470535968928265649F,
    0.77301045336273696081090660975846980097104F,
    0.75720884650648454757546405360578447304043F,
    0.74095112535495909117561689749516272972896F,
    0.72424708295146692094106924329055316748309F,
    0.70710678118654752440084436210484903928484F,
    0.68954054473706692461673062995748470284554F,
    0.67155895484701840062537685042742180322875F,
    0.65317284295377676408420301365630541507686F,
    0.63439328416364549821517161322549337067569F,
    0.61523159058062684548491356341398427765943F,
    0.59569930449243334346703652882996988951193F,
    0.57580819141784530074597245381573084177601F,
    0.55557023301960222474283081394853287437494F,
    0.53499761988709721066307690463701791556027F,
    0.51410274419322172659369383896881577260805F,
    0.49289819222978403687302668875880926823969F,
    0.47139673682599764855638762590525437765746F,
    0.44961132965460660004629457942422707588319F,
    0.42755509343028209432096685688879853430458F,
    0.40524131400498987090848130550505246651195F,
    0.38268343236508977172845998403039886676134F,
    0.35989503653498814877510457232675642020232F,
    0.33688985339222005068925321261914757047777F,
    0.31368174039889147665647884599410030999338F,
    0.29028467725446236763619237581739527469148F,
    0.26671275747489838632528651511643639404212F,
    0.24298017990326388994827416207747111832099F,
    0.21910124015686979722773754749735779884836F,
    0.19509032201612826784828486847702224092769F,
    0.17096188876030122636364235720826353196633F,
    0.14673047445536175165885012964671781970622F,
    0.12241067519921619849870447415094578757522F,
    0.098017140329560601994195563888641845861137F,
    0.073564563599667423529465621575234321813299F,
    0.049067674327418014254954976942682658314745F,
    0.024541228522912288031734529459282925065466F,
    0.000000000000000000000000000000000000000000F,
    -0.024541228522912288031734529459282925065466F,
    -0.049067674327418014254954976942682658314745F,
    -0.073564563599667423529465621575234321813299F,
    -0.098017140329560601994195563888641845861137F,
    -0.12241067519921619849870447415094578757522F,
    -0.14673047445536175165885012964671781970622F,
    -0.17096188876030122636364235720826353196633F,
    -0.19509032201612826784828486847702224092769F,
    -0.21910124015686979722773754749735779884836F,
    -0.24298017990326388994827416207747111832099F,
    -0.26671275747489838632528651511643639404212F,
    -0.29028467725446236763619237581739527469148F,
    -0.31368174039889147665647884599410030999338F,
    -0.33688985339222005068925321261914757047777F,
    -0.35989503653498814877510457232675642020232F,
    -0.38268343236508977172845998403039886676134F,
    -0.40524131400498987090848130550505246651195F,
    -0.42755509343028209432096685688879853430458F,
    -0.44961132965460660004629457942422707588319F,
    -0.47139673682599764855638762590525437765746F,
    -0.49289819222978403687302668875880926823969F,
    -0.51410274419322172659369383896881577260805F,
    -0.53499761988709721066307690463701791556027F,
    -0.55557023301960222474283081394853287437494F,
    -0.57580819141784530074597245381573084177601F,
    -0.59569930449243334346703652882996988951193F,
    -0.61523159058062684548491356341398427765943F,
    -0.63439328416364549821517161322549337067569F,
    -0.65317284295377676408420301365630541507686F,
    -0.67155895484701840062537685042742180322875F,
    -0.68954054473706692461673062995748470284554F,
    -0.70710678118654752440084436210484903928484F,
    -0.72424708295146692094106924329055316748309F,
    -0.74095112535495909117561689749516272972896F,
    -0.75720884650648454757546405360578447304043F,
    -0.77301045336273696081090660975846980097104F,
    -0.78834642762660626200916470535968928265649F,
    -0.80320753148064490980667651296314192387957F,
    -0.81758481315158369650492088413063380947104F,
    -0.83146961230254523707878837761790575673856F,
    -0.84485356524970707325957120510495709771979F,
    -0.85772861000027206990226998428477013704249F,
    -0.87008699110871141865229240448384884391083F,
    -0.88192126434835502971275686366038834950844F,
    -0.89322430119551532034241644749339797800063F,
    -0.90398929312344333158620029723053704871013F,
    -0.91420975570353065463501482939357740104469F,
    -0.92387953251128675612818318939678828682242F,
    -0.93299279883473888771166025554330249829502F,
    -0.94154406518302077841250940259950235718559F,
    -0.94952818059303666719593607418934502825222F,
    -0.95694033573220886493579788698026996948285F,
    -0.96377606579543986668646435550783515366308F,
    -0.97003125319454399260398420728610025145687F,
    -0.97570213003852854446039576641952797164401F,
    -0.98078528040323044912618223613423903697393F,
    -0.98527764238894124477401843317854778716013F,
    -0.98917650996478097345167373801624306398369F,
    -0.99247953459870999815676725166111782001082F,
    -0.99518472667219688624483695310947992157547F,
    -0.99729045667869021613559714018256782117169F,
    -0.99879545620517239271477160475910069444320F,
    -0.99969881869620422011576564966617219685006F
};

#endif
/*  End of include guard.                                                     */
