"""
################################################################################
#                                   LICENSE                                    #
################################################################################
#   This file is part of libtmpl.                                              #
#                                                                              #
#   libtmpl is free software: you can redistribute it and/or modify it         #
#   under the terms of the GNU General Public License as published by          #
#   the Free Software Foundation, either version 3 of the License, or          #
#   (at your option) any later version.                                        #
#                                                                              #
#   libtmpl is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
#   GNU General Public License for more details.                               #
#                                                                              #
#   You should have received a copy of the GNU General Public License          #
#   along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.          #
################################################################################
#   Purpose:                                                                   #
#       Routines for computing Remez polynomials.                              #
################################################################################
#   Author: Ryan Maguire                                                       #
#   Date:   January 8, 2023.                                                   #
################################################################################
"""

# Basic array manipulations.
import numpy

# mpmath is imported here.
import tmpld

# mpmath constants.
import tmpld.constants

# Rational evaluations via Horner's method.
from tmpld.rat.rat_eval import rat_eval

# Initial setup function.
from tmpld.remez.start_exchange import start_exchange

# Function for updating samples in the Remez exchange.
from tmpld.remez.reset_samples import reset_samples

# Function for performing the exchange step.
from tmpld.remez.perform_rational_remez_exchange import \
    perform_rational_remez_exchange

# Computes the rational Minimax function using the Remez exchange.
def rat_remez(func, num_deg, den_deg, start, end):
    """
        Function:
            rat_remez
        Purpose:
            Computes the Minimax rational approximation of a function f on a
            given interval of a specified degree using the Remez algorithm.
        Arguments:
            f (function):
                The function to be approximated.
            deg (int):
                The degree of the output Minimax polynomial.
            start (float):
                The left-most point of the interval f is approximated on.
            end (float):
                The right-most point of the interval f is approximated on.
        Output:
            coeffs (list):
                The coefficients of the Minimax polynomial in ascending order
                in terms of the degrees.
    """

    # Convert the inputs to mpmath objects if necessary.
    xarr, farr, x_vals, y_vals = start_exchange(
        func, num_deg + den_deg, start, end
    )

    # The iteration stops when E_{n} and E_{n+1} are close. Keep track of both.
    previous_error = tmpld.constants.zero

    # Iteratively apply the Remez exchange algorithm until the error is decent.
    while True:

        # Compute the coefficient of the approximate Minimax polynomial.
        data = perform_rational_remez_exchange(x_vals, y_vals, num_deg, den_deg)

        # Compute the error. If the bumps are the same magnitude, stop.
        num = data[0:num_deg + 1]
        den = [tmpld.mpmath.mpf(1)] + data[num_deg + 1: num_deg + den_deg + 1]

        # Check if we can stop.
        if previous_error != tmpld.constants.zero:
            rel_diff = tmpld.mpmath.fabs((data[-1] - previous_error)/data[-1])
            if rel_diff < tmpld.mpmath.mpf(1.0E-6):
                return num, den, data[-1]

        yarr = numpy.abs(
            numpy.array(
                [
                    float(farr[k] - rat_eval(num, den, xarr[k]))
                    for k in range(len(xarr))
                ]
            )
        )

        # Reset the samples to the peaks and compute the function there.
        x_vals, y_vals = reset_samples(func, xarr, yarr)

        # If there were not enough samples in x_vals, shrink the increment.
        if len(x_vals) != num_deg + den_deg + 2:
            tmpld.constants.remez_increment *= tmpld.constants.one_tenth

            print(
                "rat_remez: shrinking increment size. new increment = %E" %
                float(tmpld.constants.remez_increment)
            )

            xarr, farr, x_vals, y_vals = start_exchange(
                func, num_deg + den_deg, start, end
            )

        previous_error = data[-1]
