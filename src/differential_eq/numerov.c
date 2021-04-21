#include <numerov.h>
#include <complex.h>

double complex numerov_step(double x, double dx, 
                            complex double psi_curr, complex double psi_prec,
                            double F (double, void*), void *p ){

double ris;
ris = ( 2 + 5*dx*dx*F(x,p)/6 ) * psi_curr;
ris -= ( 1 - dx*dx*F(x-dx,p)/12 ) * psi_prec;
ris /= 1 - dx*dx*F(x+dx,p)/12;
return ris;
}
