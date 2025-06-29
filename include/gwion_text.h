/** @file: gwion_text.h
\brief text structure and functions
**/
#pragma once

/** mp_allocted text */
typedef struct GwText_ {
  m_str   str;
  size_t  cap;
  size_t  len;
  MemPool mp;
} GwText;

/** append to text **/
ANN void text_add(GwText *, const char *);

ANN static inline void text_init(GwText *text, MemPool mp) {
  text->mp = mp;
  text->str = (m_str)mp_malloc2(mp, 64);
  text->len = 0;
  text->cap = 64;
}

/** release text memory **/
ANN static inline void text_release(GwText *text) {
  if (text->str) {
    mp_free2(text->mp, text->cap, text->str);
    text->str = NULL;
    text->cap = text->len = 0;
  }
}

ANN static inline GwText *new_text(MemPool mp) {
  GwText *text = (GwText *)mp_calloc(mp, GwText);
  text_init(text, mp);
  return text;
}

ANN static inline void free_text(GwText *text) {
  text_release(text);
  mp_free(text->mp, GwText, text);
}

/** reset text **/
ANN static inline void text_reset(GwText *text) {
  if (text->str) {
    *text->str = '\0';
    text->len  = 0;
  }
}
