/******************************************************************************
 *                                 LICENSE                                    *
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
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Provides an example of using complex addition.                        *
 *      We can compile this with:                                             *
 *                                                                            *
 *          gcc tmpl_complex_add_imagl_example.c -o test -ltmpl               *
 *                                                                            *
 *      If libtmpl is not in /usr/local/lib/ (this is the default location it *
 *      is placed in when built via make.sh), change the -L option to the     *
 *      correct location. If /usr/local/include/ is not in your path, add the *
 *      -I option as follows:                                                 *
 *                                                                            *
 *          gcc -I/usr/local/include/ -L/usr/local/lib/                       *
 *              tmpl_complex_add_imagl_example.c -o test -ltmpl               *
 *                                                                            *
 *      Note, this should all be one line. This outputs an executable "test". *
 *      Running the executable with ./test, this outputs:                     *
 *          (0.000000 + i0.000000) + iinf = 0.000000 + iinf                   *
 *          (1.000000 + i0.000000) + inan = 1.000000 + inan                   *
 *          (1.000000 + i1.000000) + i-4.000000 = 1.000000 + i-3.000000       *
 *          (nan + i0.000000) + i1.000000 = nan + i1.000000                   *
 *          (inf + i0.000000) + i2.000000 = inf + i2.000000                   *
 *          (nan + inan) + i1.000000 = nan + inan                             *
 *          (inf + iinf) + i-inf = inf + inan                                 *
 ******************************************************************************
 *  Author:     Ryan Maguire, Dartmouth College                               *
 *  Date:       June 03, 2021                                                 *
 ******************************************************************************/

/*  Complex functions defined here.                                           */
#include <libtmpl/include/tmpl_complex.h>

/*  Real nan and inf found here.                                              */
#include <libtmpl/include/tmpl_math.h>

/*  We'll use stdio to print the results.                                     */
#include <stdio.h>

/*  Routine for adding an imaginary number to a complex one.                  */
int main(void)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    tmpl_ComplexLongDouble z[7], w[7];
    long double y[7];
    long double re_z, im_z, re_w, im_w;

    /*  And declare a variable for indexing.                                  */
    unsigned int n;

    /*  Set the test values in the array z.                                   */
    z[0] = tmpl_CLDouble_Zero;
    z[1] = tmpl_CLDouble_One;
    z[2] = tmpl_CLDouble_Rect(1.0L, 1.0L);
    z[3] = tmpl_CLDouble_Rect(TMPL_NANL, 0.0L);
    z[4] = tmpl_CLDouble_Rect(TMPL_INFINITYL, 0.0L);
    z[5] = tmpl_CLDouble_NaN;
    z[6] = tmpl_CLDouble_Infinity;

    /*  Set the test values for the array y.                                  */
    y[0] =  TMPL_INFINITYL;
    y[1] =  TMPL_NANL;
    y[2] = -4.0L;
    y[3] =  1.0L;
    y[4] =  2.0L;
    y[5] =  1.0L;
    y[6] =  -TMPL_INFINITYL;

    /*  Loop over the results and print them.                                 */
    for (n = 0U; n < 7U; ++n)
    {
        /*  Compute z + iy of the nth value.                                  */
        w[n] = tmpl_CLDouble_Add_Imag(y[n], z[n]);

        /*  Extract the real and imaginary parts from z[n].                   */
        re_z = tmpl_CLDouble_Real_Part(z[n]);
        im_z = tmpl_CLDouble_Imag_Part(z[n]);

        /*  Extract the real and imaginary parts from w[n].                   */
        re_w = tmpl_CLDouble_Real_Part(w[n]);
        im_w = tmpl_CLDouble_Imag_Part(w[n]);

        /*  And finally, print the result to the screen.                      */
        printf("(%Lf + i%Lf) + i%Lf = %Lf + i%Lf\n",
               re_z, im_z, y[n], re_w, im_w);
    }
    /*  End of for loop z + iy.                                               */

    return 0;
}
/*  End of main.                                                              */

