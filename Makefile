CXX = g++
CC = g++

CFLAGS = -Wall -Wextra -Wpedantic 
CXXFLAGS = -Wall -Wextra -Wpedantic 

# debugging flags
CFLAGS += -g -O0
CXXFLAGS += -g -O0
LDFLAGS += $(CFLAGS)

.PHONY: clean

all: main

main: main.o

clean:
	$(RM) *.o
	$(RM) ccalc