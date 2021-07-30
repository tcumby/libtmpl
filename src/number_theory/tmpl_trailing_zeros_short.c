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
 *                        tmpl_trailing_zeros_short                            *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the number of trailing zeros, in binary, of an integer.      *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      tmpl_Short_Trailing_Zeros:                                            *
 *  Purpose:                                                                  *
 *      Given a short n, returns the number of trailing zeros for the         *
 *      binary representation of n. Ex. If n = 8, then in binary n = 1000_2,  *
 *      so the number of trailing zeros is 3.                                 *
 *  Arguments:                                                                *
 *      n (short int):                                                        *
 *          An integer.                                                       *
 *  Output:                                                                   *
 *      zeros (unsigned int):                                                 *
 *          The number of trailing zeros for n.                               *
 *  Called Functions:                                                         *
 *      None.                                                                 *
 *  Method:                                                                   *
 *      If short is 16 or 32 bit, use a simple O(1) algorithm to              *
 *      compute the number of trailing zeros. If not, a portable algorithm is *
 *      implemented, though it is slightly slower.                            *
 *  Notes:                                                                    *
 *      If n = 0, the number of trailing zeros is zero.                       *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) tmpl_number_theory.h:                                                 *
 *          Header where the function prototype is defined.                   *
 *  2.) limits.h:                                                             *
 *          Standard C library header file containing information on the size *
 *          of an int.                                                        *
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
 *  Author: Ryan Maguire, Dartmouth College                                   *
 *  Date:   2021/07/30                                                        *
 ******************************************************************************/

/*  Function prototype here.                                                  */
#include <libtmpl/include/tmpl_number_theory.h>

/*  Size of int here.                                                         */
#include <limits.h>

/*  The C standard requires short to be at LEAST 16 bits. It usually is.      */
#if SHRT_MAX == 0x7FFF

/*  16-bit trailing-zeros function.                                           */
unsigned int tmpl_Short_Trailing_Zeros(short int n)
{
    /*  Variable for the number of trailing zeros.                            */
    unsigned int bits = 0U;

    /*  If n is zero, return 0. That is, 0 has no trailing zeros.             */
    if (n)
    {
        /*  Set the upper 8 bits to zero and see if the number ends up being  *
         *  zero. If yes, there are at least 8 trailing zeros.                */
        if (!(n & 0x00FF))
        {
            bits += 8U;
            n >>= 8;
        }

        /*  Same thing with the next 4 bits.                                  */
        if (!(n & 0x000F))
        {
            bits += 4U;
            n >>= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0x0003))
        {
            bits += 2U;
            n >>= 2;
        }

        /*  Last bit.                                                         */
        if (n)
            ++bits;
    }
    return bits;
}
/*  End of tmpl_Short_Trailing_Zeros.                                         */

/*  32-bit short is rarer.                                                    */
#elif SHRT_MAX == 0x7FFFFFFF

/*  32-bit trailing-zeros function.                                           */
unsigned int tmpl_Short_Trailing_Zeros(short int n)
{
    /*  Variable for the number of trailing zeros.                            */
    unsigned int bits = 0;

    /*  If n is zero, return 0. That is, 0 has no trailing zeros.             */
    if (n)
    {
        /*  Set the upper 16 bits to zero and see if the number ends up being *
         *  zero. If yes, there are at least 16 trailing zeros.               */
        if (!(n & 0x0000FFFF))
        {
            bits += 16U;
            n >>= 16;
        }

        /*  Same thing with the next 8 bits.                                  */
        if (!(n & 0x000000FF))
        {
            bits += 8U;
            n >>= 8;
        }

        /*  Same thing with the next 4 bits.                                  */
        if (!(n & 0x0000000F))
        {
            bits += 4U;
            n >>= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0x00000003))
        {
            bits += 2U;
            n >>= 2;
        }

        /*  Last bit.                                                         */
        if (n)
            ++bits;
    }
    return bits;
}
/*  End of tmpl_Short_Trailing_Zeros.                                         */

/*  This is for exotic systems with short not 16 or 32 bit.                   */
#else

/*  Portable trailing-zeros function.                                         */
unsigned int tmpl_Short_Trailing_Zeros(short int n)
{
    /*  Variable for the number of trailing zeros.                            */
    unsigned int bits = 0U;

    /*  If n is zero, return 0. That is, 0 has no trailing zeros.             */
    if (n)
    {
        /*  Keep zeroing out all but the lower 16 bits, since we don't know   *
         *  the size of the integer. Once this loop finishes, we're down to   *
         *  the last 16 bits of the integer and can proceed as normal.        */
        while (!(n & 0x0000FFFF))
        {
            bits += 16U;
            n >>= 16;
        }

        /*  Same thing with the next 8 bits.                                  */
        if (!(n & 0x000000FF))
        {
            bits += 8U;
            n >>= 8;
        }

        /*  Same thing with the next 4 bits.                                  */
        if (!(n & 0x0000000F))
        {
            bits += 4U;
            n >>= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0x00000003))
        {
            bits += 2U;
            n >>= 2;
        }

        /*  Last bit.                                                         */
        if (n)
            ++bits;
    }
    return bits;
}
/*  End of tmpl_Short_Trailing_Zeros.                                         */

#endif
/*  End of #if SHRT_MAX == 0xFFFF.                                            */

