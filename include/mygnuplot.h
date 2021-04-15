#ifndef _GNUPLOT_PIPES_H_
#define _GNUPLOT_PIPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gnuplot_i.h>

/*---------------------------------------------------------------------------
                            Functions by Elena and Vincenzo
 ---------------------------------------------------------------------------*/

/**
 * @brief Set terminal png and set output file
 * 
 * @param h handler of a gnuplot instance
 * @param file_name string with the name of the output file, including the .png estension
 * 
 * @return
 */
void gnuplot_set_term_png(gnuplot_ctrl * c, char file_name []);

/**
 * @brief Set tab as datafile separator for csv
 * 
 * @param h handler of a gnuplot instance
 * 
 * @return
 */
void gnuplot_tab_separator(gnuplot_ctrl * h);

#endif