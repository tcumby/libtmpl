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
 ******************************************************************************
 *                       tmpl_complex_quick_dist_float                        *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains the source code for the function f(z,w) = |z - w|.           *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      tmpl_CFloat_Quick_Dist                                                *
 *  Purpose:                                                                  *
 *      Computes the distance between two complex numbers:                    *
 *                                                                            *
 *          dist(z, w) = dist(a + ib, c + id)                                 *
 *                     = sqrt((c-a)^2 + (d-b)^2)                              *
 *  Arguments:                                                                *
 *      z (tmpl_ComplexFloat):                                                *
 *          A complex number.                                                 *
 *      w (tmpl_ComplexFloat):                                                *
 *          Another complex number.                                           *
 *  Output:                                                                   *
 *      dist (float):                                                         *
 *          The distance between z and w.                                     *
 *  Called Functions:                                                         *
 *      tmpl_Float_Sqrt (tmpl_math.h):                                        *
 *          Computes the square root of a real number.                        *
 *  Method:                                                                   *
 *      Compute sqrt((c-a)^2 + (d-b)^2). The method is a bit faster than      *
 *      calling the hypot function, which is what tmpl_CFloat_Dist does,      *
 *      but may cause overflow or underflow because of the intermediate step  *
 *      of computing (c-a)^2 + (d-b)^2.                                       *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) tmpl_config.h:                                                        *
 *          Header file where TMPL_USE_INLINE is found.                       *
 *  2.) tmpl_complex.h:                                                       *
 *          Header where complex types and function prototypes are defined.   *
 *  3.) tmpl_math.h:                                                          *
 *          Header containing various math functions.                         *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       February 07, 2023                                             *
 ******************************************************************************/

/*  TMPL_USE_INLINE found here.                                               */
#include <libtmpl/include/tmpl_config.h>

/*  This file is only used if inline support is not requested.                */
#if TMPL_USE_INLINE != 1

/*  Header file containing the hypot function.                                */
#include <libtmpl/include/tmpl_math.h>

/*  Complex routines and data types defined here.                             */
#include <libtmpl/include/tmpl_complex.h>

/*  Single precision distance function for complex variables.                 */
float tmpl_CFloat_Quick_Dist(tmpl_ComplexFloat z0, tmpl_ComplexFloat z1)
{
    /*  Compute the difference in both components and use Pythagoras.         */
    const float dx = z0.dat[0] - z1.dat[0];
    const float dy = z0.dat[1] - z1.dat[1];
    return tmpl_Float_Sqrt(dx*dx + dy*dy);
}
/*  End of tmpl_CFloat_Quick_Dist.                                            */

#endif
/*  End of #if TMPL_USE_INLINE != 1.                                          */
