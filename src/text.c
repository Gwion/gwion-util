#include "gwion_util.h"

ANN static inline m_str text_grow(GwText *text, const size_t sz) {
  if (text->cap <= sz) {
    const m_uint cap = text->cap;
    while (text->cap <= sz) text->cap <<= 1;
    text->str = (m_str)mp_realloc(text->mp, text->str, cap, text->cap);
  }
  return text->str + text->len;
}

ANN void text_add(GwText *text, const char *str) {
  const size_t sz = strlen(str);
  const size_t len = sz + text->len + 1;
  strcpy(text_grow(text, len), str);
  text->len += sz;
}
