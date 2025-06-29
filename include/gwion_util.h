/** @file: gwion_util.h
\brief meta header (use this to include the whole library)
*/
#pragma once

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__WIN32))
#ifndef BUILD_ON_WINDOWS
#define BUILD_ON_WINDOWS
#endif
#endif

#include "defs.h"
#include "gwion_thread.h"
#include "err_msg.h"
#include "xalloc.h"
#include "mpool.h"
#include "gwion_print.h"
#include "container.h"
#include "mp_vector.h"
#include "threadpool.h"
#include "hash.h"
#include "symbol.h"
#include "gwion_text.h"
#include "mp_string.h"
#include "carg.h"
#include "prettyerr.h"

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__WIN32))
#include "windows_missing.h"
#endif
