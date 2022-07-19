CC = clang
CXX = clang

CFLAGS = -Wall -Wextra -Wpedantic 

vpath %.c src
vpath %.h include

# .PHONY all

all: calculator


calculator: calculator.o

calculator.o: calculator.c
