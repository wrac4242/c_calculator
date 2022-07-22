CXX = g++
CC = g++

CFLAGS = -Wall -Wextra -Wpedantic 

# debugging flags
CFLAGS += -g -O0
CXXFLAGS += -g -O0 -std=c++20
LDFLAGS += $(CFLAGS)

vpath % src

# .PHONY all

all: main


main: main.o

clean:
	$(RM) *.o
	$(RM) main