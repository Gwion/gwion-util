/** @file: gwion_util.h
\brief meta header (use this to include the whole library)
*/
#ifndef __GWION_UTIL
#define __GWION_UTIL

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__WIN32))
#define BUILD_ON_WINDOWS
#endif

#include "defs.h"
#include "gwion_thread.h"
#include "err_msg.h"
#include "xalloc.h"
#include "mpool.h"
#include "container.h"
#include "hash.h"
#include "symbol.h"
#include "gwion_text.h"
#include "mp_string.h"
#include "carg.h"
#include "mp_vector.h"

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__WIN32))
#include "windows_missing.h"
#endif


#endif
