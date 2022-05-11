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
 *                             tmpl_rational_add                              *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Code for adding rational numbers.                                     *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      tmpl_RationalNumber_Add                                               *
 *  Purpose:                                                                  *
 *      Adds two rational numbers.                                            *
 *  Arguments:                                                                *
 *      p (tmpl_RationalNumber):                                              *
 *          A rational number.                                                *
 *      q (tmpl_RationalNumber):                                              *
 *          Another rational number.                                          *
 *  Output:                                                                   *
 *      sum (tmpl_RationalNumber):                                            *
 *          The sum of p and q.                                               *
 *  Called Functions:                                                         *
 *      None.                                                                 *
 *  Method:                                                                   *
 *      Use the "cross-multiply" rule to add the two numbers.                 *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) tmpl_rational.h:                                                      *
 *          Function prototype found here.                                    *
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
 *  Author:     Ryan Maguire                                                  *
 *  Date:       June 24, 2021                                                 *
 ******************************************************************************/

/*  Rational numbers and function prototype found here.                       */
#include <libtmpl/include/tmpl_rational.h>

/*  Function for adding two rational numbers.                                 */
tmpl_RationalNumber
tmpl_RationalNumber_Add(const tmpl_RationalNumber *p,
                        const tmpl_RationalNumber *q)
{
    /*  Declare a variable for the sum.                                       */
    tmpl_RationalNumber sum;

    /*  We add a/b + c/d via the following:                                   *
     *      a     c     ad     cb     ad + cb                                 *
     *      -  +  -  =  --  +  --  =  -------                                 *
     *      b     d     bd     bd       bd                                    *
     *  This is the so-called "cross-multiply" rule.                          */
    sum.numerator = p->denominator*q->numerator + p->numerator*q->denominator;
    sum.denominator = p->denominator*q->denominator;
    return sum;
}
/*  End of tmpl_RationalNumber_Add.                                           */
