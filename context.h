/*
 * context.h
 * Authors : Honoré NINTUNZE
 */
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include <assert.h>

struct ctx_s * ctx_current = NULL;

int init_ctx(struct ctx_s* ctx, int stack_size, func_t* f,void* args)
{
  if ((ctx->stk = malloc(stack_size)) == NULL)
    {
      return 0;
    }
  ctx->ebp = &ctx->stk[stack_size-4];
  ctx->esp = &ctx->stk[stack_size-4];
  ctx->state = CTX_READY;
  ctx->entrypoint = f;
  ctx->args = args;

  ctx->ctx_magic = MAGIC_NUMBER;

  return 1;
}

void exec_f(struct ctx_s * ctx)
{
  assert(ctx != NULL);
  ctx->state = CTX_ACTIVATED;
  ctx->entrypoint(ctx->args);
  ctx->state = CTX_TERMINATED;
  printf("exec_f terminated");
  exit(1);
}

void switch_to_ctx(struct ctx_s* ctx)
{
  assert(ctx != NULL);
  assert(ctx->ctx_magic == MAGIC_NUMBER);
  assert(ctx->state == CTX_READY || ctx->state == CTX_ACTIVATED);

  if(ctx_current != NULL)
    {
      asm("movl %%ebp, %0":"=r" (ctx_current->ebp)::);
      asm("movl %%esp, %0":"=r" (ctx_current->esp)::);
    }
  ctx_current = ctx;
  asm("movl %0, %%ebp"::"r" (ctx_current->ebp):);
  asm("movl %0, %%esp"::"r" (ctx_current->esp):); 
  if (ctx_current->state == CTX_READY)
    {
      exec_f(ctx_current); /* Normalement, cette fonction ne revient jamais */
    }
}
