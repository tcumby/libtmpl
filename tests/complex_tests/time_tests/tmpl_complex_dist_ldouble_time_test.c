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
#include "tmpl_complex_time_tests.h"
#ifdef _MSC_VER
static long double func(_Lcomplex z0, _Lcomplex double z1){
    return cabsl(_LCbuild(creall(z0)-creall(z1), cimagl(z0)-cimagl(z1));
}
#else
static long double func(complex long double z0, complex long double z1){
    return cabsl(z0-z1);
}
#endif
TEST8(long double,
      tmpl_ComplexLongDouble,
      complex long double,
      tmpl_CLDouble_Dist, func, COMPLEX_LDOUBLE_CTOR)

