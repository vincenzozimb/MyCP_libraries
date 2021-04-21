/*-------------------------------------------------------------------------*/
/**
  @file     print_routines_h
  @author   V. Zimbardo
  @date     Apr 2021
  @brief    C routines for print.               
*/
/*--------------------------------------------------------------------------*/


#ifndef __PRINT_ROUTINES_H__
#define __PRINT_ROUTINES_H__

#include <stdio.h>

/**
 * @brief Print a double to a specified file, followed by a tab.
 * 
 * @param file the file handler of type FILE for the ouput file. If you want to print to terminal, use stdout
 * @param d the double to be printed to file
 * 
 * @return void
 */
void fprint_double (FILE *file, double d);

/**
 * @brief Print a double vector to a specified file.
 * 
 * @param file the file handler of type FILE for the ouput file. If you want to print to terminal, use stdout
 * @param vec the vector of double to be printed to file
 * 
 * @return void
 */
void fprint_vec(FILE *file, double vec[], int dim);

/**
 * @brief Print a matrix to a specified file, using tab as the separator.
 * 
 * @param file the file handler of type FILE for the ouput file. If you want to print to terminal, use stdout
 * @param m matrix to be printed on file
 * @param n_rows number of rows (first dimension)
 * @param n_cols number of columns (second dimension)
 * 
 * @return void
 */
void fprint_mat (FILE *file, double *m, int n_rows, int n_cols);

#endif