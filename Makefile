CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic 

# debugging flags
CFLAGS += -g -O0
LDFLAGS += $(CFLAGS)

vpath % src

# .PHONY all

all: calculator


calculator: calculator.o stack.o
