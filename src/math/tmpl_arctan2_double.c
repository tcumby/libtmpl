/*  Function prototype found here.                                            */
#include <libtmpl/include/tmpl_math.h>

/*  Only implement this if the user requested libtmpl algorithms.             */
#if defined(TMPL_USE_MATH_ALGORITHMS) && TMPL_USE_MATH_ALGORITHMS == 1

/*  Check for IEEE-754 support.                                               */
#if defined(TMPL_HAS_IEEE754_DOUBLE) && TMPL_HAS_IEEE754_DOUBLE == 1

#include <libtmpl/include/tmpl_math_arctan_tables.h>

/*  Coefficients for the computation of the polynomial approximation. The     *
 *  coefficients for the Taylor series are 1 / (1 + 2n).                      */
#define A00 3.33333333333329318027E-01
#define A01 -1.99999999998764832476E-01
#define A02 1.42857142725034663711E-01
#define A03 -1.11111104054623557880E-01
#define A04 9.09088713343650656196E-02
#define A05 -7.69187620504482999495E-02
#define A06 6.66107313738753120669E-02
#define A07 -5.83357013379057348645E-02

static double tmpl_double_arctan_small_vals(double x)
{
    const double x_sq = x*x;
    return  x * (
        1.0 - x_sq * (
            A00 + x_sq * (
                A01 + x_sq * (
                    A02 + x_sq * (
                        A03 + x_sq * (
                            A04 + x_sq * (
                                A05 + x_sq * A06
                            )
                        )
                    )
                )
            )
        )
    );
}

/*  Double precision inverse tangent (atan equivalent).                       */
double tmpl_Double_Arctan2(double y, double x)
{
    /*  Declare necessary variables. C89 requires this at the top.            */
    tmpl_IEEE754_Double wx, wy, w;
    double arg, out, v, atan_v;
    unsigned int ind;

    wx.r = x;
    wy.r = y;

    /*  Special cases, NaN and INF.                                           */
    if (wx.bits.expo == TMPL_DOUBLE_NANINF_EXP)
    {
        /*  Check if x is NaN. If it is, return NaN.                          */
        if (wx.bits.expo == 0x7FFU &&
            (wx.bits.man0 != 0x00U || wx.bits.man1 != 0x00U ||
             wx.bits.man2 != 0x00U || wx.bits.man3 != 0x00U))
        return x;

        /*  x is infinity. Check if y is NaN or Inf.                          */
        if (wy.bits.expo == TMPL_DOUBLE_NANINF_EXP)
        {
            /*  Check if y is NaN. If it is, return NaN.                      */
            if (wy.bits.expo == 0x7FFU &&
                (wy.bits.man0 != 0x00U || wy.bits.man1 != 0x00U ||
                 wy.bits.man2 != 0x00U || wy.bits.man3 != 0x00U))
            return y;

            /*  Both x and y are infinity. 4 special cases corresponding to   *
             *  North-East, North-West, South-West, and South-East.           */
            if (!wx.bits.sign && !wy.bits.sign)
                return tmpl_Pi_By_Four;
            else if (wx.bits.sign && !wy.bits.sign)
                return tmpl_Three_Pi_By_Four;
            else if (wx.bits.sign && wy.bits.sign)
                return -tmpl_Three_Pi_By_Four;
            else
                return -tmpl_Pi_By_Four;
        }

        /*  y is finite and x is infinite. The angle is 0 or pi.              */
        if (wx.bits.sign)
            return tmpl_One_Pi;
        else
            return 0.0;
    }

    /*  Check if y is infinite or NaN.                                        */
    else if (wy.bits.expo == TMPL_DOUBLE_NANINF_EXP)
    {
        /*  We've already checked that x is finite. Check if y is NaN.        */
        if (wy.bits.expo == 0x7FFU &&
            (wy.bits.man0 != 0x00U || wy.bits.man1 != 0x00U ||
             wy.bits.man2 != 0x00U || wy.bits.man3 != 0x00U))
            return y;

        /*  y is infinite and x is finite. The angle is +/- pi/2.             */
        if (wy.bits.sign)
            return -tmpl_Pi_By_Two;
        else
            return tmpl_Pi_By_Two;
    }
    else if (x == 0.0)
        return (y > 0.0 ? tmpl_Pi_By_Two : -tmpl_Pi_By_Two);

    else if (y == 0.0)


    /*  The arctan function is odd. Compute |x| by setting sign to positive.  */
    wx.bits.sign = 0x00U;
    wy.bits.sign = 0x00U;
    w.r = wy.r / wx.r;

    /*  Small values, |x| < 1/8. Use the MacLaurin series to 8 terms.         */
    if (w.bits.expo < TMPL_DOUBLE_BIAS - 3U)
        out = tmpl_double_arctan_small_vals(w.r);

    /*  For |x| > 8, use the asymptotic expansion.                            */
    else if (w.bits.expo > TMPL_DOUBLE_BIAS + 3U)
        out = tmpl_Double_Arctan_Asymptotic(w.r);

    else
    {
        ind = (w.bits.expo + 3U) - TMPL_DOUBLE_BIAS;
        v = tmpl_atan_double_v[ind];
        atan_v = tmpl_atan_double_atan_of_v[ind];
        arg = (w.r - v) / (1.0 + w.r*v);
        out = atan_v + tmpl_Double_Arctan_Maclaurin(arg);
    }

    /*  Use the fact that atan is an odd function to complete the computation.*/
    out = (x < 0.0 ? tmpl_One_Pi - out : out);
    return (y < 0.0 ? -out : out);
}
/*  End of tmpl_Double_Arctan.                                                */

/*  Undefine all of the macros.                                               */
#undef A00
#undef A01
#undef A02
#undef A03
#undef A04
#undef A05
#undef A06
#undef A07

#else

#endif

#endif
