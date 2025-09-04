# $squawk: Makefile

CC ?= clang

DIAG = -Wall -Wextra -pedantic
#OFLAGS = -O3 -Ofast -pipe
OFLAGS = -O2 -pipe

CFLAGS ?= $(OFLAGS) $(DIAG)
CPPFLAGS ?=
LDFLAGS ?=
LIBS ?=
INCS ?=

INCS := -Iinclude
CFLAGS := $(CFLAGS) $(INCS)
LDFLAGS := $(LDFLAGS) $(LIBS)

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

TEST = test

.PHONY: all clean test

all: test

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(TEST): $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJS) $(LDFLAGS)

clean:
	rm -frd $(TEST)
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

# vim: ft=make ts=4 sts=4 sw=4 et ai
