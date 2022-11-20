CC = gcc
CFLAGS = -std=c11 -fPIC -c -Wall -Iinclude -ggdb
LD = ld
LDFLAGS = -shared
SRC = $(wildcard src/*.c)

all: libtree.so

libtree.so: $(SRC:.c=.o)
	$(LD) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

tests: test/mock
	LD_LIBRARY_PATH="$$LD_LIBRARY_PATH:$$PWD" ./test/mock

test/mock: $(wildcard test/*.c) libtree.so
	$(MAKE) -C test
