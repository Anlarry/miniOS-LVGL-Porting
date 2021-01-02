CFLAGS		= -I ../../include/ -m32 -c -fno-builtin -fno-stack-protector -Wall -Wextra -g
LIB := libgui.a

SRC := $(wildcard *.c)
BIN := $(patsubst %.c, %.o,$(SRC))

all : $(BIN)
	ar rcs $(LIB) $(BIN)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<