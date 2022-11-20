CC = gcc
CFLAGS = -std=c11 -Wall -I../include -ggdb
LDFLAGS = -L.. -ltree -lcmocka

all: mock

mock: mock.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
