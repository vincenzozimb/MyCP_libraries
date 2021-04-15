#include <gnuplot_i.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
#include <io.h>
#endif // #ifdef _WIN32

/*---------------------------------------------------------------------------
                            Functions by Elena and Vincenzo
 ---------------------------------------------------------------------------*/

 void gnuplot_set_term_png(gnuplot_ctrl * c, char file_name []) {
    char cmd [128];
    sprintf(cmd, "set output \'%s\'", file_name);
    
    gnuplot_cmd(c, "set term pngcairo");
    gnuplot_cmd(c, cmd);
}

void gnuplot_tab_separator(gnuplot_ctrl * h) {
    gnuplot_cmd(h, "set datafile separator \'\\t\'");
    return;
}