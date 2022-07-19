CC = clang
CXX = clang

CFLAGS = -Wall -Wextra -Wpedantic 

vpath % src

# .PHONY all

all: calculator


calculator: calculator.o

calculator.o: calculator.c
