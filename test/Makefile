CC = gcc
CFLAGS = -std=c11 -Wall -I../include -ggdb
LDFLAGS = -L.. -l:libtree.a -lcmocka

all: mock

mock: mock.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
