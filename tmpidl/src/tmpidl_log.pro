;******************************************************************************;
;                                 LICENSE                                      ;
;******************************************************************************;
;  This file is part of libtmpl.                                               ;
;                                                                              ;
;  libtmpl is free software: you can redistribute it and/or modify             ;
;  it under the terms of the GNU General Public License as published by        ;
;  the Free Software Foundation, either version 3 of the License, or           ;
;  (at your option) any later version.                                         ;
;                                                                              ;
;  libtmpl is distributed in the hope that it will be useful,                  ;
;  but WITHOUT ANY WARRANTY; without even the implied warranty of              ;
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               ;
;  GNU General Public License for more details.                                ;
;                                                                              ;
;  You should have received a copy of the GNU General Public License           ;
;  along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.           ;
;******************************************************************************;
;                                  tmpidl_log                                  ;
;******************************************************************************;
;   Purpose:                                                                   ;
;       Provide IDL wrappers for libtmpl's Log function.                       ;
;   Input:                                                                     ;
;       A real array or scalar.                                                ;
;   Output:                                                                    ;
;       A real array or scalar, the natural log of the input, y = log(x).      ;
;******************************************************************************;
;  Author:     Ryan Maguire                                                    ;
;  Date:       March 9, 2022                                                   ;
;******************************************************************************;

FUNCTION TMPIDL_LOG, x

    ; Set error handling.
    ON_ERROR, 2

    ; libtmpl wants a double, so convert if necessary.
    IF TYPENAME(x) NE "DOUBLE" THEN in = DOUBLE(x) ELSE in = x

    ; Get the number of elements in the input array.
    n = ULONG(N_ELEMENTS(in))

    ; Create an empty array to store the values.
    out = DBLARR(n)

    ; Use 'CALL_EXTERNAL' to pass the IDL parameters to the C code.
    s = CALL_EXTERNAL('/usr/local/lib/libtmpidl.so', 'tmpidl_Log', in, n, out)

    ; The output has been stored in out, so return this.
    RETURN, out
END
