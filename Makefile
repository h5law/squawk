MAKEFLAGS += --no-builtin-rules --no-builtin-variables

DIAG = -Wall -Wextra -Wpedantic
#OFLAGS = -O3 -Ofast
OFLAGS = -O2

CFLAGS ?= $(OFLAGS) $(DIAG)
CPPFLAGS ?=
LDFLAGS ?=
LIBS ?=
INCS ?=

INCS := -I$(SQUAWK_PATH)/include
LIBS := -L$(SQUAWK_PATH)/lib -lm -lc
CFLAGS := $(CFLAGS) $(INCS)
LDFLAGS := $(LDFLAGS) $(LIBS)

OBJS = \
	src/main.o

TEST = test

.PHONY: all clean test

all: clean test

clean:
	rm -frd $(TEST)
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

%.o: %.c
	$(CC) -MD $(CFLAGS) -o $@ -c $<

$(TEST): $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJS) $(LDFLAGS)
