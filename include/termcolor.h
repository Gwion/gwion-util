// libtermcolor: termcolor.h
// Copyright (C) 2021 Jérémie Astor
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
/*
   This is the header file for libtermcolor. It contains the documentation for
   using the various functions in the exposed API. The doc folder contains
   other information. Both places are vital for proper API usage, so reading
   both places will facilitate adeptitude with libtermcolor.
*/

#ifndef _LIBTERMCOLOR_TERMCOLOR_H
#define _LIBTERMCOLOR_TERMCOLOR_H

#include <stdbool.h>
#include <stdio.h>
//#include "termcolor_export.h"

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__WIN32) && !defined(__CYGWIN__)) && defined (ENABLE_VIRTUAL_TERMINAL_PROCESSING)
    #define TERMCOLOR_OS_WIN
    #include <windows.h>
#endif

/* A type describing an termcolor error. These are the only values returned by
   the `tcol_fprintf` and `tcol_printf` functions. You may assume any nonzero
   value is an error and use `tcol_errorstr` to display a diagnostic. */
enum term_color_error_t {
    TermColorErrorNone = 0,
    TermColorErrorAllocationFailed = 1,
    TermColorErrorPrintingFailed = 2,
    TermColorErrorInvalidColor = 3,
    TermColorErrorUnterminatedColor = 4,
    TERM_COLOR_ERROR_COUNT
};

/* Decodes the given termcolor representation of a color
  
   Parameters:
   - `dst`: The buffer to write the resulting ANSI escape code to
   - `dstn`: The length of the destination buffer
   - `len`: A pointer to a value which is initialized to the number of bytes
           written to `dst`
   - `rep`: The attributes applied to the text
   - `foreground`: A foreground color, if any
   - `background`: A background color, if any
  
   Return Value:
   - int: One of the values `enum term_color_error_t`
  
   NOTE: This is private API exposed for developers. Those interested can read
   the source (found in src/termcolor.c). The relevant parts are the enum
   `_termcolor_internal_color` and the function `_termcolor_internal_lookup`.
*/
int _tcol_color_generate(char *dst, size_t dstn, size_t *len, int rep,
                         int foreground, int background);

/* Returns a human-readable string describing the given libtermcolor error. */
const char *tcol_errorstr(const enum term_color_error_t err);

/* Parses a termcolor color string without the brackets.
  
   Parameters:
   - `dst`: The buffer to write the resulting ANSI escape code to
   - `dstn`: The length of the destination buffer
   - `color`: The buffer that the color is given in
   - `k`: The length of the given color in the buffer
   - `len`: A pointer to a value which is initialized to the number of bytes
            written to `dst`
  
   Return Value:
   - `int`: One of the values `enum term_color_error_t`
  
   NOTE: color is not null-terminated as its length is given by k which shall be
   between 1 and 16.*/
int tcol_color_parse(char *dst, size_t dstn, char color[16],
                                      size_t k, size_t *len);

/* By default libtermcolor will use color. However this behavior can be manually
   overridden using this function.
  
   Parameters
   - `enable_color`: Whether to enable "colorization" of the format string */
void tcol_override_color_checks(bool enable_color);

/* Printfs the colorized format string to the specified stream.
  
   Parameters:
   - `fmt`: The termcolor format string
   - `...`: The variable argumentsto replace the format specifiers with
  
   Return Value:
   - `int`: One of the values `enum term_color_error_t` */
int tcol_fprintf(FILE *stream, const char *fmt, ...);

/* Printfs the colorized format string to the standard output.
  
   Parameters:
   - `stream`: The `FILE*` stream to printf to
   - `fmt`: The termcolor format string
   - `...`: The variable argumentsto replace the format specifiers with
  
   Return Value:
   - `int`: One of the values `enum term_color_error_t` */
int tcol_printf(const char *fmt, ...);

/* Snprintfs the colorized format string to the specified string stream.
  
   Parameters:
   - `buffer`: The `char*` stream to printf to
   - `N`: The total size of `buffer`, including the null terminatr
   - `fmt`: The termcolor format string
   - `...`: The variable argumentsto replace the format specifiers with
  
   Return Value:
   - `int`: One of the values `enum term_color_error_t`*/
int tcol_snprintf(char *buffer, size_t N, const char *fmt, ...);

#endif /* _LIBTERMCOLOR_TERMCOLOR_H */
