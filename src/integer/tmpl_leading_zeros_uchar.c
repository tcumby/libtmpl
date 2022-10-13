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

/*  Function prototype here.                                                  */
#include <libtmpl/include/tmpl_integer.h>

/*  Size of unsigned char here.                                               */
#include <limits.h>

/*  The C standard requires char to be at least 8 bits wide.                  */
#if UCHAR_MAX == 0xFFU

/*  8-bit leading-zeros function.                                             */
int tmpl_UChar_Leading_Zeros(unsigned char n)
{
    /*  Variable for the number of leading zeros.                             */
    int bits = 0;

    /*  If n is zero, return 0. That is, 0 has no leading zeros.              */
    if (n != 0U)
    {
        /*  Set the lower 4 bits to zero and see if the number ends up being  *
         *  zero. If yes, there are at least 4 leading zeros.                 */
        if (!(n & 0xF0U))
        {
            bits += 4;
            n <<= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0xC0U))
        {
            bits += 2;
            n <<= 2;
        }

        /*  The last bit of n.                                                */
        if (!(n & 0x80U))
            bits += 1;
    }
    return bits;
}
/*  End of tmpl_UChar_Leading_Zeros.                                          */

#elif UCHAR_MAX == 0xFFFFU

/*  16-bit leading-zeros function.                                            */
int tmpl_UChar_Leading_Zeros(unsigned char n)
{
    /*  Variable for the number of leading zeros.                             */
    int bits = 0;

    /*  If n is zero, return 0. That is, 0 has no leading zeros.              */
    if (n != 0U)
    {
        /*  Set the lower 8 bits to zero and see if the number ends up being  *
         *  zero. If yes, there are at least 8 leading zeros.                 */
        if (!(n & 0xFF00U))
        {
            bits += 8;
            n <<= 8;
        }

        /*  The next four bits in the number.                                 */
        if (!(n & 0xF000U))
        {
            bits += 4;
            n <<= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0xC000U))
        {
            bits += 2;
            n <<= 2;
        }

        /*  The last bit of n.                                                */
        if (!(n & 0x8000U))
            bits += 1;
    }
    return bits;
}
/*  End of tmpl_UChar_Leading_Zeros.                                          */

/*   32-bit char.                                                             */
#elif UCHAR_MAX == 0xFFFFFFFFU

/*  32-bit leading-zeros function.                                            */
int tmpl_UChar_Leading_Zeros(unsigned char n)
{
    /*  Variable for the number of leading zeros.                             */
    int bits = 0;

    /*  If n is zero, return 0. That is, 0 has no leading zeros.              */
    if (n != 0U)
    {
        /*  Set the lower 16 bits to zero and see if the number ends up being *
         *  zero. If yes, there are at least 16 leading zeros.                */
        if (!(n & 0xFFFF0000U))
        {
            bits += 16;
            n <<= 16;
        }

        /*  The next 8 bits.                                                  */
        if (!(n & 0xFF000000U))
        {
            bits += 8;
            n <<= 8;
        }

        /*  The next four bits in the number.                                 */
        if (!(n & 0xF0000000U))
        {
            bits += 4;
            n <<= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0xC0000000U))
        {
            bits += 2;
            n <<= 2;
        }

        /*  The last bit of n.                                                */
        if (!(n & 0x80000000U))
            bits += 1;
    }
    return bits;
}
/*  End of tmpl_UChar_Leading_Zeros.                                          */

/*  I once read there's a calculator with char = short = int = long = 64-bit. */
#elif UCHAR_MAX == 0xFFFFFFFFFFFFFFFFU

/*  64-bit leading-zeros function.                                            */
int tmpl_UChar_Leading_Zeros(unsigned char n)
{
    /*  Variable for the number of leading zeros.                             */
    int bits = 0;

    /*  If n is zero, return 0. That is, 0 has no leading zeros.              */
    if (n != 0U)
    {
        /*  Set the lower 32 bits to zero and see if the number ends up being *
         *  zero. If yes, there are at least 32 leading zeros.                */
        if (!(n & 0xFFFFFFFF00000000U))
        {
            bits += 32;
            n <<= 32;
        }

        /*  Next 16 bits.                                                     */
        if (!(n & 0xFFFF000000000000U))
        {
            bits += 16;
            n <<= 16;
        }

        /*  The next 8 bits.                                                  */
        if (!(n & 0xFF00000000000000U))
        {
            bits += 8;
            n <<= 8;
        }

        /*  The next four bits in the number.                                 */
        if (!(n & 0xF000000000000000U))
        {
            bits += 4;
            n <<= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & 0xC000000000000000U))
        {
            bits += 2;
            n <<= 2;
        }

        /*  The last bit of n.                                                */
        if (!(n & 0x8000000000000000U))
            bits += 1;
    }
    return bits;
}
/*  End of tmpl_UChar_Leading_Zeros.                                          */

/*  This is for exotic systems. The C standard requires char to be at least   *
 *  8 bits wide, so we can loop through the bits of the input 8 at a time.    */
#else

/*  Portable leading zeros function.                                          */
int tmpl_UChat_Leading_Zeros(unsigned char n)
{
    /*  Variable for the number of leading zeros.                             */
    int bits = 0;
    const unsigned char zero = 0x00U;
    const unsigned char top8 = ~((~zero) >> 8U);
    const unsigned char top4 = ~((~zero) >> 4U);
    const unsigned char top2 = ~((~zero) >> 2U);
    const unsigned char top1 = ~((~zero) >> 1U);

    /*  If n is zero, return 0. That is, 0 has no leading zeros.              */
    if (n != 0U)
    {
        /*  Keep zeroing out the lower 8 bits and shifting the number.        */
        while (!(n & top8))
        {
            bits += 8;
            n <<= 8;
        }

        /*  The next four bits in the number.                                 */
        if (!(n & top4))
        {
            bits += 4;
            n <<= 4;
        }

        /*  Next two bits.                                                    */
        if (!(n & top2))
        {
            bits += 2;
            n <<= 2;
        }

        /*  The last bit of n.                                                */
        if (!(n & top1))
            bits += 1;
    }
    return bits;
}
/*  End of tmpl_UCHAR_Leading_Zeros.                                          */

#endif
/*  End of #if UCHAR_MAX == 0xFFFFU.                                          */
