/*
 * pingpong.c
 * Authors : Honoré NINTUNZE
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "context.h"


struct ctx_s ctx_ping;
struct ctx_s ctx_pong;

func_t f_ping;
func_t f_pong;

int main(int argc, char *argv[])
{
  init_ctx(&ctx_ping,16384,f_ping, NULL);
  init_ctx(&ctx_pong,16384,f_pong, NULL);
  switch_to_ctx(&ctx_ping);

  exit(EXIT_SUCCESS);
}

void f_ping(void * arg)
{
  while(1)
    {
      printf("A");
      switch_to_ctx(&ctx_pong);
      printf("B");
      switch_to_ctx(&ctx_pong);
      printf("C");
      switch_to_ctx(&ctx_pong);
    }
}

void f_pong(void * arg)
{
    while(1)
    {
      printf("1");
      switch_to_ctx(&ctx_ping);
      printf("2");
      switch_to_ctx(&ctx_ping);
    }
}
