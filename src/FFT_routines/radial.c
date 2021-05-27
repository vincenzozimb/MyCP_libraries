#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <assert.h>
#include <gsl/gsl_fft_complex.h>

#include <FFT_routines/radial.h>

void radial_FFT(double f[], double L, int N, double k[], double F[]){

    /* check if N is a power of two */
    // write the assertion

    /* initialize vector r */
    double dr = L / N;
    double r[N];
    for(int i=0;i<N;i++){
        r[i] = i * dr;
    }

    /* initialize function A = r * f(r) */
    double A[N];
    for(int i=0;i<N;i++){
        A[i] = r[i] * f[i];
    }

    /* odd extensions */
    double A2[2*N];
    for(int i=0;i<2*N;i++){
        if(i < N){
            A2[i] = A[i];
        }else if(N < i && i < 2*N){
            A2[i] = -A[2*N-i];
        }else{
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
    double dk = M_PI / L; 
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
    double sum = 0.0;
    for(int i=0;i<N;i++){
        sum += i * i * f[i]; 
    }
    sum *= 2 * L * L / (N * N);
    
    for(int i=0;i<N;i++){
        if( k[i] == 0.0){
            F[i] = sum;
        }else{
            F[i] = - 4 * M_PI * M_PI / k[i] * A2z_imag[i];
        }
    }

}

void radial_IFFT(double F[], double L, int N, double r[], double f[]){

    /* check if N is a power of two */
    // write the assertion
    
    /* initialize frequency vector */
    double dk = M_PI / L;
    double k[N];
    for(int i=0;i<N;i++){
        k[i] = dk * i;
    }

    /* initialize function B = k * F(k) */
    double B[N];
    for(int i=0;i<N;i++){
        B[i] = k[i] * F[i];
    }

    /* odd extensions */
    double B2[2*N];
    for(int i=0;i<2*N;i++){
        if(i < N){
            B2[i] = B[i];
        }else if(N < i && i < 2*N){
            B2[i] = -B[2*N-i];
        }else{
            B2[i] = 0.0;
        }
    }

    /* complexification of B2 for gsl_fft_radix2_inverse */
    int M = 2*N;
    double B2z[2*M];
    for(int i=0;i<M;i++){
        B2z[2*i] = B2[i];
        B2z[2*i+1] = 0.0;
    }
    
    /* initialize radial coordinate vector */
    double dr = L / N; 
    double r2[M];
    for(int i=0;i<M;i++){
        r2[i] = dr * i;
    }

    /* inverse fourier transform of B2z */
    gsl_fft_complex_radix2_inverse(B2z,1,M);

    /* take the immaginary part */
    double B2z_imag[M];
    for(int i=0;i<M;i++){
        B2z_imag[i] = B2z[2*i+1];
    }

    /* inizialize only the positive coordinates */
    for(int i=0;i<N;i++){
        r[i] = r2[i];
    }

    /* initialize the inverse radial transform f */
    double sum = 0.0;
    for(int i=0;i<N;i++){
        sum += i * i * F[i]; 
    }
    sum *= M_PI * M_PI / (L * L * N);
    
    for(int i=0;i<N;i++){
        if( r[i] == 0.0){
            f[i] = sum;
        }else{
            f[i] = 1 / (4.0 * M_PI * M_PI * r[i]) * B2z_imag[i];
        }
    }

}