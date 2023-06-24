#include <stdlib.h>
#include <time.h>
#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_complex.h>
#include <libtmpl/include/tmpl_fft.h>
#include <fftw3.h>

int main(void)
{
    clock_t t1, t2;
    size_t n;
    const size_t N = (size_t)1000000UL;
    tmpl_ComplexDouble *z0 = malloc(sizeof(*z0) * N);
    tmpl_ComplexDouble *w0 = malloc(sizeof(*w0) * N);
    fftw_complex *z1 = (fftw_complex*)fftw_malloc(sizeof(*z1) * N);
    fftw_complex *w1 = (fftw_complex*)fftw_malloc(sizeof(*w1) * N);
    const double start = -20.0;
    const double end = 20.0;
    const double dt = (end - start)/(double)N;
    double t = start;
    double x, tmp, dx, dy;
    double rms = 0.0;
    double max = 0.0;
    fftw_plan p;

    for (n = (size_t)0; n < N; ++n)
    {
        x = tmpl_Double_Exp(-t*t);
        z0[n] = tmpl_CDouble_Rect(x, 0.0);
        z1[n][0] = x;
        z1[n][1] = 0.0;

        t += dt;
    }

    t1 = clock();
    tmpl_CDouble_FFT_Bluestein_Chirp_Z(z0, w0, N);
    t2 = clock();

    printf("libtmpl: %f\n", (double)(t2 - t1)/CLOCKS_PER_SEC);

    t1 = clock();
    p = fftw_plan_dft_1d(N, z1, w1, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    t2 = clock();

    printf("FFTW:    %f\n", (double)(t2 - t1)/CLOCKS_PER_SEC);

    for (n = (size_t)0; n < N; ++n)
    {
        dx = w0[n].dat[0] - w1[n][0];
        dy = w0[n].dat[1] - w1[n][1];

        tmp = tmpl_Double_Hypot(dx, dy);

        if (tmp > max)
            max = tmp;

        rms += tmp*tmp;
    }

    rms = tmpl_Double_Sqrt(rms / (double)N);

    printf("Max Abs Error: %e\n", max);
    printf("RMS Abs Error: %e\n", rms);

    fftw_destroy_plan(p);
    fftw_free(z0);
    fftw_free(z1);
    free(w0);
    free(w1);
}
