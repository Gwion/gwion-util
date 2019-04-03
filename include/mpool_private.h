struct Recycle {
  struct Recycle *next;
};

struct pool {
  uint8_t **data;
  struct Recycle  *next;
  uint32_t  obj_sz;
  uint32_t  obj_id;
  int32_t   blk_id;
  uint32_t  nblk;
};

#define BLK 64
