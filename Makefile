CC = gcc
CFLAGS = -std=c11 -fPIC -c -Wall -Iinclude -O3
LD = ld
LDFLAGS = -shared
SRC = $(wildcard src/*.c)
PREFIX = /usr/local

all: libtree.so

libtree.so: $(SRC:.c=.o)
	$(LD) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

tests: test/mock
	LD_LIBRARY_PATH="$$LD_LIBRARY_PATH:$$PWD" ./test/mock

test/mock: $(wildcard test/*.c) libtree.so
	$(MAKE) -C test

install: libtree.so
	mv libtree.so $(PREFIX)/lib/
