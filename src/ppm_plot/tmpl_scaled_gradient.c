#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_ppm_plot.h>

void tmpl_RGB_Scaled_Gradient(double val, FILE *fp)
{
    /*  Declare variables for the color. We'll compute the color in RGB       *
     *  format, hence the need for these three variables.                     */
    double scaled;
    unsigned char red, green, blue;

    scaled = tmpl_Double_Arctan(val);
    scaled += tmpl_Pi_By_Two;
    scaled = 255.0 * scaled / tmpl_One_Pi;

    /*  Use an RGB rainbow gradient to color the current pixel. We'll set     *
     *  blue to correspond to the least value and red for the greatest, with  *
     *  a continuous gradient in between.                                     */
    if (scaled < 64)
    {
        red   = (unsigned char)0;
        green = (unsigned char)(4.0*scaled);
        blue  = (unsigned char)255;
    }
    else if (scaled < 128)
    {
        red   = (unsigned char)0;
        green = (unsigned char)255;
        blue  = (unsigned char)(255 - 4*(scaled - 64));
    }
    else if (scaled < 192)
    {
        red   = (unsigned char)(4.0*(scaled-128));
        green = (unsigned char)255;
        blue  = (unsigned char)0;
    }
    else if (scaled < 255)
    {
        red   = (unsigned char)255;
        green = (unsigned char)(255 - 4*(scaled-192));
        blue  = (unsigned char)0;
    }
    else
    {
        red   = (unsigned char)255;
        green = (unsigned char)0;
        blue  = (unsigned char)0;
    }

    /*  Color the current pixel.                                              */
    tmpl_Color(red, green, blue, fp);
}
