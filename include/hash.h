#ifndef __HASH
#define __HASH
typedef struct Hash_* Hash;
struct Hash_ {
  void*       *table;
  uint size;  /* should be prime */
};

void  hini(const Hash, const uint, const uint);
void  hdel(const Hash, void (*)(void*));
void  hend(const Hash);
//Macro hadd(const Hash, const char*);
//int   hrem(const Hash, const char*);
//Macro hhas(const Hash, const char*);

ANN unsigned int hash(const char *s0);
#endif
