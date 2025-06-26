/** @file: mp_string.h
\brief string allocated with memory pool
**/
#pragma once

/** free mp_allocated string **/
ANN static inline void free_mstr(MemPool mp, char *const str) {
  _mp_free(mp, strlen(str) + 1, str);
}

/** mp_alloc version of strdup **/
ANN static inline m_str mstrdup(MemPool mp, const char *name) {
  const m_str dup = (m_str)_mp_malloc(mp, strlen(name) + 1);
  strcpy(dup, name);
  return dup;
}
