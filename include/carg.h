/** @file: carg.h
\brief argument utilities
**/
#ifndef __CARG
#define __CARG

/** structure use to parse arguments **/
struct CArg {
  char **argv; /**< array of char* arguments */
  int    argc; /**< number of arguments */
  int    idx;  /**< curr index [internal] */
};

/** returns the option to the argument, errors and returns if none **/
ANN m_str option_argument(struct CArg *ca);


/** returns separated arguments from a string in a vector.
each value is a mp_allocated string.
freeing it is caller responsability.
**/
ANN Vector split_args(MemPool, const m_str str);
#endif
