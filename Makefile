CC = gcc
CFLAGS = -std=c11 -fPIC -c -Wall -Iinclude -O3
LD = ld
LDFLAGS = -shared
AR = ar
SRC = $(wildcard src/*.c)
PREFIX = /usr/local

all: libtree.so libtree.a

libtree.so: $(SRC:.c=.o)
	$(LD) $^ $(LDFLAGS) -o $@

libtree.a: $(SRC:.c=.o)
	$(AR) -crs $@ $^

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

tests: test/mock
	./test/mock

test/mock: $(wildcard test/*.c)
	$(MAKE) -C test

install: libtree.so
	mv libtree.so $(PREFIX)/lib/

clean:
	rm -rf libtree.so libtree.a $(SRC:.c=.o)
