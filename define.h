/*
 * define.h
 * Authors : Honoré NINTUNZE
 */

typedef void (func_t) (void *);

enum ctx_state_e
{
  CTX_READY,
  CTX_ACTIVATED,
  CTX_TERMINATED
};

#define MAGIC_NUMBER 0xdeadbeef

struct ctx_s
{
  void* ebp;
  void* esp;
  func_t * entrypoint;
  unsigned char* stk;
  enum ctx_state_e state;
  void* args;
  unsigned int ctx_magic; /* détrompeur */
};

int init_ctx(struct ctx_s*, int, func_t*,void*);

void switch_to_ctx(struct ctx_s*);
