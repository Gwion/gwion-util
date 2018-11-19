#ifndef __GWION_TEST
#define __GWION_TEST

#define OP(op, a,b,c)                                    \
if((a) op (b))                                           \
  gw_out("\033[1;32mOK     \033[0m% 4i %s %s(%s:%i)\n",  \
    ++count, #c, #a, __FILE__, __LINE__);                \
else                                                     \
  gw_out("\033[1;31mNOT OK \033[0m% 4i %s %s (%s:%i)\n", \
  (++fail, ++count), #c, #a, __FILE__, __LINE__);        \

#define EQ(a,b,c) OP(==, a, (b), c)
#define NE(a,b,c) OP(!=, a, (b), c)
#define NO(a,b) a; gw_out("#         %s\n", #b);
#endif
