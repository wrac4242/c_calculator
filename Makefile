CXX = g++
CC = g++

CFLAGS = -Wall -Wextra -Wpedantic 

# debugging flags
CFLAGS += -g -O0
LDFLAGS += $(CFLAGS)

vpath % src

# .PHONY all

all: main


calculator: main.o

clean:
	$(RM) *.o
	$(RM) main