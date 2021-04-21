/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify it        *
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
 *                          tmpl_matrix_complex                               *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Define matrices and vectors and provide the prototypes for basic      *
 *      linear algebra functions and routines.                                *
 ******************************************************************************
 *  Author:     Ryan Maguire, Wellesley College                               *
 *  Date:       January 26, 2021                                              *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef __TMPL_MATRIX_COMPLEX_H__
#define __TMPL_MATRIX_COMPLEX_H__

#include <libtmpl/include/tmpl_bool.h>
#include <libtmpl/include/tmpl_complex.h>

typedef struct tmpl_ComplexDoubleMatrix {
    tmpl_ComplexDouble **data;
    unsigned long row_length;
    unsigned long column_length;
    tmpl_Bool error_occurred;
    char *error_message;
} tmpl_ComplexDoubleMatrix;

#endif
/*  End of include guard.                                                     */

