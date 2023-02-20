// cmdapp: cmdapp.c
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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "termcolor.h"
#include "cmdapp.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define eprintf(fmt, ...) \
    tcol_fprintf(stderr, "{R+}error:{0}" fmt, ##__VA_ARGS__);

typedef struct _cmdopt_internal_t {
    // The option that this internal representation refers to
    cmdopt_t* result;

    // Used for help and version generation
    const char* description;

    // NULL-terminated array
    cmdopt_t* conflicts[];
} cmdarg_internal_t;

static inline size_t _argvlen(void** argv) {
    size_t length = 0;
    while (*argv) argv++, length++;
    return length;
}

void cmdapp_init(cmdapp_t* app, int argc, char** argv, cmdapp_mode_t mode,
                 const cmdapp_info_t* info) {
    app->_argc = argc;
    app->_argv = argv;
    app->_mode = mode;
    app->_custom_help = 0;
    app->_custom_ver = 0;
    app->_length = 0;
    app->_capacity = 4;
    app->_start = malloc(sizeof(cmdarg_internal_t*) * app->_capacity);
    app->_args.length = 0;
    app->_args.contents = NULL;
    app->_info = *info;
    app->_proc = NULL;
}

void cmdapp_destroy(cmdapp_t* app) {
    for (size_t i = 0; i < app->_length; i++) {
        free(app->_start[i]);
    }
    free(app->_start);
    free(app->_args.contents);
    app->_args.contents = NULL;
}

static void cmdapp_append(cmdapp_t* app, cmdarg_internal_t* arg_int) {
    if (app->_length + 1 > app->_capacity) {
        app->_capacity += (app->_capacity / 2);
        app->_start = realloc(app->_start,
                              sizeof(cmdarg_internal_t*) * app->_capacity);
    }
    app->_start[app->_length++] = arg_int;
}

void cmdapp_set(cmdapp_t* app, char shorto, const char* longo, uint8_t flags,
                cmdopt_t** conflicts, const char* description,
                const char *argtype,
                 cmdopt_t* option)
{

     if (strncmp(longo, "help", 5) == 0) {
        app->_custom_help = 1;
    } else if (strncmp(longo, "version", 8) == 0) {
        app->_custom_ver = 1;
    }

    option->shorto = shorto;
    option->longo = longo;
    option->argtype = argtype;
    option->flags = flags;
    option->value = NULL;
    const size_t conflict_count = (conflicts == NULL)
                                      ? 1
                                      : _argvlen((void**)conflicts) + 1;
    const size_t size = sizeof(cmdarg_internal_t)
                        + conflict_count * sizeof(cmdopt_t*);
    cmdarg_internal_t* arg_int = malloc(size);
    arg_int->result = option;
    arg_int->description = description;
    if (conflicts == NULL) {
        arg_int->conflicts[0] = NULL;
    } else {
        memcpy(arg_int->conflicts, conflicts, conflict_count
                                              * sizeof(cmdopt_t*));
    }
    cmdapp_append(app, arg_int);
}

void cmdapp_enable_procedure(cmdapp_t* app, cmdapp_procedure_t proc, void *user_data) {
    app->_proc = proc;
    app->_user_data = user_data;
}

void cmdapp_print_help(cmdapp_t* app) {
    if (app->_info.synopses && *app->_info.synopses) {
        tcol_printf("{Y}Usage:{0} {+}%s{0} %s\n", app->_argv[0], *app->_info.synopses);
        for (size_t i = 1; app->_info.synopses[i]; i++) {
            printf("   or: {+}%s{0} %s\n", app->_argv[0], app->_info.synopses[i]);
        }
    } else {
        tcol_printf("{Y}Usage:{0} {+}%s{0} {G}[OPTION]{-}...{0} {M}ARG {-}...{0}\n", app->_argv[0]);
    }
    printf("\n");
    tcol_printf("{-}%s{0}\n", app->_info.description);
    if (!app->_length)
        return;
    printf("\n");
    tcol_printf("{Y}Options:{0}\n");
    for (size_t i = 0; i < app->_length; i++) {
        cmdarg_internal_t* arg_int = app->_start[i];
        tcol_printf("%*s", app->_info.help_des_offset, "");
        tcol_printf(arg_int->description);
        tcol_printf("\r");
        if(arg_int->result->shorto) {
          tcol_printf("  {G}-%c{0}", arg_int->result->shorto);
        } else {
          tcol_printf("   {G}-{0}");
        }
        if (arg_int->result->longo) {
            tcol_printf(", {G}--%s{0}", arg_int->result->longo);
        }
        if (arg_int->result->flags & CMDOPT_TAKESARG) {
          tcol_printf("{M}=");
          if (!arg_int->result->argtype)
            tcol_printf("ARG");
          else
            tcol_printf(arg_int->result->argtype);
          tcol_printf("{0}");
        }
        else if (arg_int->result->flags & CMDOPT_MAYTAKEARG) {
          tcol_printf("{M}(=");
          if (!arg_int->result->argtype)
            tcol_printf("ARG");
          else
            tcol_printf(arg_int->result->argtype);
          tcol_printf("){0}");
        }
        fputc('\n', stdout);
    }
    if (!app->_custom_help) {
        tcol_printf("%*s%s\r  {+G}--help{0}\n", app->_info.help_des_offset, "",
               "Display this information");
    }
    if (!app->_custom_ver) {
        tcol_printf("%*s%s\r  {+G}--version{0}\n", app->_info.help_des_offset, "",
               "Display program version information");
    }
}

void cmdapp_print_version(cmdapp_t* app) {
    printf("%s %s\n", app->_info.program, app->_info.version);
    printf("Copyright (C) %d %s\n", app->_info.year, app->_info.author);
    printf("%s", app->_info.ver_extra);
}

static cmdarg_internal_t* cmdapp_search(cmdapp_t* app, char shorto, const char* longo) {
    if (longo == NULL) {
        for (size_t i = 0; i < app->_length; i++) {
            if (app->_start[i]->result->shorto == shorto) {
                return app->_start[i];
            }
        }
    } else {
        for (size_t i = 0; i < app->_length; i++) {
            if (strcmp(app->_start[i]->result->longo, longo) == 0) {
                return app->_start[i];
            }
        }
    }
    return NULL;
}

#define IS_END_OF_FLAGS(str) \
    ((str)[0] == '-' && (str)[1] == '-' && (str)[2] == 0)
#define IS_LONG_FLAG(str) ((str)[0] == '-' && (str)[1] == '-')
#define IS_SHORT_FLAG(str) ((str)[0] == '-')

static int cmdapp_resolve_options(cmdapp_t* app) {
    for (size_t i = 0; i < app->_length; i++) {
        cmdarg_internal_t* arg_int = app->_start[i];
        if (!cmdopt_exists(*arg_int->result)) continue;
        if (!cmdopt_is_optional(*arg_int->result)) {
            eprintf("Required option -%c not passed\n",
                    arg_int->result->shorto);
            return EXIT_FAILURE;
        }
        cmdopt_t** conflicts = arg_int->conflicts;
        if (!conflicts) continue;
        for (size_t i = 0; conflicts[i]; i++) {
            if (cmdopt_exists(*conflicts[i])) {
                eprintf("Cannot pass both -%c and -%c\n",
                        arg_int->result->shorto, conflicts[i]->shorto);
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

int cmdapp_run(cmdapp_t* app) {
    if (app->_args.contents != NULL) {
        app->_args.contents = realloc(app->_args.contents, sizeof(char*) * 4);
        app->_args.length = 0;
    } else {
        app->_args.contents = malloc(sizeof(char*) * 4);
    }
    size_t args_cap = 4;
    #define APPEND_ARG(arg) if (app->_args.length + 1 > args_cap) { \
        args_cap += (args_cap / 2); \
        app->_args.contents = realloc(app->_args.contents, \
                                      sizeof(char*) * args_cap); \
    } \
    if (app->_proc) { \
        app->_proc(app->_user_data, NULL, arg); \
    } \
    app->_args.contents[app->_args.length++] = arg;

    bool only_args = false;
    for (int i = 0; i < app->_argc; i++) {
        char* current = app->_argv[i];
        if (only_args) {
            APPEND_ARG(current);
            continue;
        }
        const char* next = app->_argv[i + 1];
        if (IS_END_OF_FLAGS(current)) {
            only_args = true;
            continue;
        }
        cmdarg_internal_t* arg_int;
        if (IS_LONG_FLAG(current)) {
            // Find the `=` for longopt args.
            char* arg = strchr(current, '=');
            // Move the pointer to the start of the longopt's args
            if (arg) {
                *arg = 0;
                arg++;
            }
            if ((arg_int = cmdapp_search(app, 0, current + 2))) {
                if (arg_int->result->flags & CMDOPT_TAKESARG) {
                    if (arg == NULL || *arg == 0) {
                        eprintf("%s expects an argument\n", current);
                        return EXIT_FAILURE;
                    }
                    arg_int->result->value = arg;
                } else if (arg_int->result->flags & CMDOPT_MAYTAKEARG) {
                    arg_int->result->value = arg;
                } else {
                    if (arg != NULL) {
                        eprintf("%s does not take arguments\n", current);
                        return EXIT_FAILURE;
                    }
                }
            } else {
                if (strncmp(current, "--help", 7) == 0) {
                    cmdapp_print_help(app);
                    app->_mode |= _CMDAPP_MODE_EXIT;
                    return EXIT_SUCCESS;
                } else if (strncmp(current, "--version", 10) == 0) {
                    cmdapp_print_version(app);
                    app->_mode |= _CMDAPP_MODE_EXIT;
                    return EXIT_SUCCESS;
                }
                eprintf("Unrecognized command line option %s, try --help\n", current);
                return EXIT_FAILURE;
            }
            arg_int->result->flags |= CMDOPT_EXISTS;
            if (app->_proc) {
                app->_proc(app->_user_data, arg_int->result, NULL);
            }
        } else if (IS_SHORT_FLAG(current)) {
            if (app->_mode & CMDAPP_MODE_SHORTARG) {
                if ((arg_int = cmdapp_search(app, current[1], NULL))) {
                    arg_int->result->value = NULL;
                    if (arg_int->result->flags | CMDOPT_TAKESARG) {
                        arg_int->result->value = current + 2;
                        if (!current[2] && next && next[0] != '-') {
                            arg_int->result->value = next;
                            i++;
                        } else if (current[2] == 0) {
                            eprintf("-%c expects an argument\n", current[1]);
                            return EXIT_FAILURE;
                        }
                    } else if ((current[2] != 0) || (next && next[0] != '-')) {
                        eprintf("-%c does not take arguments\n", current[1]);
                        return EXIT_FAILURE;
                    }
                } else {
                    eprintf("Unrecognized command line option -%c, try --help\n",
                            current[1]);
                    return EXIT_FAILURE;
                }
                arg_int->result->flags |= CMDOPT_EXISTS;
                if (app->_proc) {
                    app->_proc(app->_user_data, arg_int->result, NULL);
                }
            } else /* app->_mode | CMDAPP_MODE_MULTIFLAG */ {
                for (size_t j = 1; current[j]; j++) {
                    if ((arg_int = cmdapp_search(app, current[1], NULL))) {
                        arg_int->result->value = current + 2;
                        if (arg_int->result->value[2] == 0) {
                            if (next && next[0] != '-') {
                                arg_int->result->value = next;
                                i++;
                            } else {
                                eprintf("-%c expects an argument\n", current[1]);
                                return EXIT_FAILURE;
                            }
                        }
                    } else {
                        eprintf("Unrecognized command line option -%c\n",
                                current[1]);
                        return EXIT_FAILURE;
                    }
                }
            }
        } else {
            APPEND_ARG(current);
        }
    }
    #undef APPEND_ARG

    if (cmdapp_resolve_options(app) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

cmdargs_t* cmdapp_getargs(cmdapp_t* app) {
    if (app->_args.contents == NULL) {
        return NULL;
    }
    return &app->_args;
}

// https://stackoverflow.com/questions/11350878/how-can-i-determine-if-the-operating-system-is-posix-in-c
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#endif

void cmdapp_error(cmdapp_t* app, const char* fmt, ...) {
    #ifdef _POSIX_VERSION
    if (isatty(STDERR_FILENO) || (getenv("CMDAPP_COLOR_ALWAYS") != NULL)) {
        fprintf(stderr, "%s: {R+}error:{0} ", app->_info.program);
    } else {
        fprintf(stderr, "%s: error: ", app->_info.program);
    }
    #else
    fprintf(stderr, "%s: error: ", app->_info.program);
    #endif /* _POSIX_VERSION */
    va_list valist;
    va_start(valist, fmt);
    vfprintf(stderr, fmt, valist);
    va_end(valist);
}
