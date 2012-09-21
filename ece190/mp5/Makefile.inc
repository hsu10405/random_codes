UNAME := $(shell uname -s)

CC=gcc
CFLAGS=-g -Wall -Werror -std=c99 -D_GNU_SOURCE
LD=gcc
LDFLAGS=-lc

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
