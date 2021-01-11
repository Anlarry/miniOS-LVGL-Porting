CFLAGS		= -I ../../include -m32 -c -fno-builtin -fno-stack-protector -Wall -Wextra -g
LIB := libipc.a

SRC := $(wildcard *.c)
BIN := $(patsubst %.c, %.o,$(SRC))

all : $(BIN) kipc.h
	ar rcs $(LIB) $(BIN)
	#rm -f ./*.o ./*.a ./*.bin

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<

