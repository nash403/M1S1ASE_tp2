CC=gcc
CFLAGS=-m32 -Wall -g

all: pingpong

pingpong: pingpong.c
	$(CC) -o pingpong pingpong.c define.h context.h $(CFLAGS)
	./pingpong

clean:
	rm -f *~ *.o pingpong
