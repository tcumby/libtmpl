/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify it        *
 *  under the terms of the GNU General Public License as published by         *
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
 *                          tmpl_rational_are_equal                           *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Code for checking if two rationals are equal.                         *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      tmpl_RationalNumber_Are_Equal                                         *
 *  Purpose:                                                                  *
 *      Checks if two rational numbers are equal.                             *
 *  Arguments:                                                                *
 *      p (tmpl_RationalNumber):                                              *
 *          A rational number.                                                *
 *      q (tmpl_RationalNumber):                                              *
 *          Another rational number.                                          *
 *  Output:                                                                   *
 *      are_equal (tmpl_Bool):                                                *
 *          A Boolean checking if p == q.                                     *
 *  Called Functions:                                                         *
 *      None.                                                                 *
 *  Method:                                                                   *
 *      Given a/b and c/d, check if ad = bc.                                  *
 *  Notes:                                                                    *
 *      No error check is performed to see if either of the denominators are  *
 *      zero.                                                                 *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) tmpl_rational.h:                                                      *
 *          Function prototype found here.                                    *
 *  2.) stdio.h:                                                              *
 *          FILE data type found here.                                        *
 ******************************************************************************
 *                            A NOTE ON COMMENTS                              *
 ******************************************************************************
 *  It is anticipated that many users of this code will have experience in    *
 *  either Python or IDL, but not C. Many comments are left to explain as     *
 *  much as possible. Vagueness or unclear code should be reported to:        *
 *  https://github.com/ryanmaguire/libtmpl/issues                             *
 ******************************************************************************
 *                            A FRIENDLY WARNING                              *
 ******************************************************************************
 *  This code is compatible with the C89/C90 standard. The setup script that  *
 *  is used to compile this in make.sh uses gcc and has the                   *
 *  -pedantic and -std=c89 flags to check for compliance. If you edit this to *
 *  use C99 features (built-in complex, built-in booleans, C++ style comments *
 *  and etc.), or GCC extensions, you will need to edit the config script.    *
 ******************************************************************************
 *  Author:     Ryan Maguire, Dartmouth College                               *
 *  Date:       June 24, 2021                                                 *
 ******************************************************************************/

/*  Rational numbers and function prototype found here.                       */
#include <libtmpl/include/tmpl_rational.h>

/*  FILE data type found here.                                                */
#include <stdio.h>

/*  Function for printing a rational number to a file.                        */
void
tmpl_RationalNumber_Print_String(FILE *fp, tmpl_RationalNumber p)
{
    if (p.denominator >= 0L)
        fprintf(fp, "%ld/%ld", p.numerator, p.denominator);
    else if (p.numerator >= 0L)
        fprintf(fp, "-%ld/%ld", p.numerator, -p.denominator);
    else
        fprintf(fp, "%ld/%ld", -p.numerator, -p.denominator);
}
/*  End of tmpl_RationalNumber_Print_String.                                  */
