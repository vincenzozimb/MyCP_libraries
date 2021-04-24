#include <differential_eq/numerov.h>
#include <complex.h>

double complex numerov_step(double x, double dx,
                            complex double psi_curr, complex double psi_prec,
                            double F(double, void *), void *p){

    double ris;
    ris = (2 + 5 * dx * dx * F(x, p) / 6) * psi_curr;
    ris -= (1 - dx * dx * F(x - dx, p) / 12) * psi_prec;
    ris /= 1 - dx * dx * F(x + dx, p) / 12;
    return ris;
}

void execute_numerov_complex(double x[], complex double psi[], int dim, double dx,
                             double F(double, void *), void *p){
    int i = 2;
    while (i < dim){
        complex double psi_curr = numerov_step(x[i - 1], psi[i - 1], psi[i - 2], dx, F, p);
        psi[i] = psi_curr;
        x[i] = x[i - 1] + dx;
        i++;
    }
}