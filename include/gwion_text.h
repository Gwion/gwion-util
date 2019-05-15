#ifndef __TEXT
#define __TEXT
typedef struct Text_ {
  m_str str;
  size_t cap;
  size_t len;
} Text;

ANN void text_add(Text*, const m_str);
ANN static inline void text_release(Text *text) {
  if(text->str) {
    xfree(text->str);
    text->str = NULL;
    text->cap = text->len = 0;
  }
}
#endif
