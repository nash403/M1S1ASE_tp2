CC=gcc
CFLAGS=-m32 -Wall -g

all: pingpong pingpongpang

pingpong: pingpong.c
	$(CC) -o pingpong pingpong.c define.h context.h $(CFLAGS)

pingpongpang: pingpongpang.c
	$(CC) -o pingpongpang pingpongpang.c define.h context.h $(CFLAGS)

clean:
	rm -f *~ *.o pingpong pingpongpang
