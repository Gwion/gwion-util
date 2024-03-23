// libprettyerr: error.h
// Copyright (C) 2021 Ethan Uppal
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

#ifndef _LIBPRETTYERR_ERROR_H
#define _LIBPRETTYERR_ERROR_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

struct libprettyerr_str {
    size_t line;
    const char* start;
};

#define PERR_Str(line_, start_) \
    (struct libprettyerr_str){ .line = line_, .start = start_ }
#define PERR_Str_None() \
    PERR_Str(0, NULL)

struct libprettyerr_pos {
    size_t index;
    size_t length;
};

#define PERR_Pos(index_, length_) \
    (struct libprettyerr_pos){ .index = index_, .length = length_ }

enum libprettyerr_errtype {
    PERR_SUCCESS,  // bold green
    PERR_ERROR,   // bold red
    PERR_WARNING, // red
    PERR_INFO,    // bold white
    PERR_HINT    // bold yellow
};

enum libprettyerr_boxtype {
    PERR_BOX_THICK_VERT,
    PERR_BOX_THIN_HIGH,
    PERR_BOX_THIN_UL,
    PERR_BOX_THIN_UL_ROUNDED,
    PERR_BOX_THIN_HORIZ,
    PERR_BOX_THIN_BL,
    PERR_BOX_THIN_BL_ROUNDED,
    PERR_BOX_THIN_VERT,
    PERR_BOX_MAX,
};

struct libprettyerr_error {
    enum libprettyerr_errtype type;

    struct libprettyerr_str primary;
    struct libprettyerr_pos error_position;

    const char* main;
    const char* explain;
    short error_code;

    const char* filename;
};

#define PERR_Error(type_, primary_, error_position_, main_, explain_, error_code_, filename_) \
    (struct libprettyerr_error){ \
        .type = type_, .primary = primary_, .error_position = error_position_, \
        .main = main_, .explain = explain_, .error_code = error_code_, \
        .filename = filename_ \
    }

#define PERR_Secondary(type_, primary_, error_position_, main_, filename_) \
    (struct libprettyerr_error){ \
        .type = type_, .primary = primary_, .error_position = error_position_, \
        .main = main_, .filename = filename_ \
    }

// TODO: tertiary for warnings
struct libprettyerr_printer;
typedef void (*libprettyerr_runner_t)(const struct libprettyerr_printer*, const  struct libprettyerr_error*);
struct libprettyerr_printer {
    const char* source;
    FILE* stream;
    const char** box_lookup;
    libprettyerr_runner_t runner;
    bool color;
    bool utf8;
    bool rounded;
};

#define PRETTYERR_EXPORT

// Initializes a printer
PRETTYERR_EXPORT
void perr_printer_init(struct libprettyerr_printer* printer, FILE* stream,
                       const char* source, bool utf8, libprettyerr_runner_t style);

// Uses the printer to display the provided error in
PRETTYERR_EXPORT
void perr_print_error(const struct libprettyerr_printer* printer,
                      const struct libprettyerr_error* err);

// prints source filename and position
PRETTYERR_EXPORT
void perr_print_line_number(const struct libprettyerr_printer* printer,
                             const struct libprettyerr_error* err,
                             const char *color);

typedef struct libprettyerr_error   perr_t;
typedef struct libprettyerr_printer perr_printer_t;
typedef libprettyerr_runner_t       perr_runner_t;
extern PRETTYERR_EXPORT perr_runner_t perr_runner_basic_style;
extern PRETTYERR_EXPORT perr_runner_t perr_runner_secondary_style;

#endif /* _LIBPRETTYERR_PRETTYERR_H */
