#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <assert.h>
#include <gsl/gsl_fft_complex.h>

#include <FFT_routines/radial.h>

void radial_FFT(double r[], double f[], double L, double dr, int N, double k[], double F[]){

    /* check if N is a power of two */
    // write the assertion, using the logarithm
    
    /* initialize function A = r * f(r) */
    double A[N];
    for(int i=0;i<N;i++){
        A[i] = r[i] * f[i];
    }

    /* odd extensions */
    double r2[2*N], A2[2*N];
    for(int i=0;i<2*N;i++){
        if(i < N){
            r2[i] = r[i];
            A2[i] = A[i];
        }else if(N < i && i < 2*N){
            r2[i] = -r[2*N-i];
            A2[i] = -A[2*N-i];
        }else{
            r2[i] = 0.0;
            A2[i] = 0.0;
        }
    }

    /* complexification of A2 for gsl_fft_radix2_forward */
    int M = 2*N;
    double A2z[2*M];
    for(int i=0;i<M;i++){
        A2z[2*i] = A2[i];
        A2z[2*i+1] = 0.0;
    }
    
    /* initialize frequency vector */
    double dk = 2 * M_PI / L; 
    double k2[M];
    for(int i=0;i<M;i++){
        k2[i] = dk * (i <= M/2 ? i : i - M);
    }

    /* fourier transform of A2z */
    gsl_fft_complex_radix2_forward(A2z,1,M);

    /* take the immaginary part */
    double A2z_imag[M];
    for(int i=0;i<M;i++){
        A2z_imag[i] = A2z[2*i+1];
    }

    /* inizialize only the positive frequency */
    for(int i=0;i<N;i++){
        k[i] = k2[i];
    }

    /* initialize the radial transform F */
    for(int i=0;i<N;i++){
        F[i] = - 2 * M_PI / k[i] * A2z_imag[i];
    }

}