#include <string.h>
#include "gwion_util.h"

ANN static inline m_str text_init(Text *text, const size_t sz) {
  return (text->str = (m_str)xmalloc(text-> cap = round2szint(sz)));
}

ANN static inline m_str text_grow(Text *text, const size_t sz) {
  if(text->cap <= sz) {
    while(text->cap <= sz)
      text->cap <<= 1;
    text->str = (m_str)xrealloc(text->str, text->cap);
  }
  return text->str + text->len;
}

ANN void text_add(Text *text, const m_str str) {
  const size_t sz = strlen(str);
  if(!text->str) {
    text->str = (m_str)xmalloc(text-> cap = round2szint(sz + 1));
    strcpy(text->str, str);
  } else {
    const size_t len = sz + text->len + 1;
    strcpy(text_grow(text, len), str);
  }
  text->len += sz;
}
