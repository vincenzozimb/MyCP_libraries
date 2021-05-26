/*-------------------------------------------------------------------------*/
/**
  @file     radial_h
  @author   V. Zimbardo
  @date     May 2021
  @brief    C routines for the radial fourier transform of a three dimensional
            radial function and its inverse. The radial fourier transform is related
            to the Hankel transform, so this code can excetute also the Hankel transform
            of order nu = 1/2. The H_{1/2} transform and its inverse are nothing more 
            than the sine and the inverse sine transforms.            
*/
/*--------------------------------------------------------------------------*/

#ifndef __RADIAL_H__
#define __RADIAL_H__

/**
 * @brief  Take a radial function and inizialize the radial fourier transform and the vector
 *         contening the magnitude of frequencies.
 * 
 * @param r the radial coordinate vector
 * @param f the radial function, calculated in the position of the vector r[]
 * @param L the direct space length
 * @param dr the radial discretization
 * @param N the number of points. It must be a power of 2
 * @param k the N-vector you want to inizialize with the magnitude of frequencies
 * @param F the N-vector you want to inizialize with the radial transform 
 * 
 * @return void
 */
void radial_FFT(double r[], double f[], double L, double dr, int N, double k[], double F[]);

/**
 * @brief  Take a radial fourier transform and inizialize the radial fourier inverse 
 *         transform and the vector contening the radial coordinate.
 * 
 * @param k the magnitude frequency vector
 * @param F the radial fourier transform, calculated in the frequencies of the vector k[]
 * @param L the direct space length
 * @param dk the (radial) frequency discretization
 * @param N the number of points. It must be a power of 2
 * @param r the N-vector you want to inizialize with the radial coordinates
 * @param f the N-vector you want to inizialize with the radial inverse transform 
 * 
 * @return void
 */
void radial_IFFT(double k[], double F[], double L, double dk, int N, double r[], double f[]);

#endif