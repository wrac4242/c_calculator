CXX = g++
CC = g++

#purely for convinience, this way main source file can stay consistent with c/c++ ideology while letting the app have it's name
APP_NAME = ccalc
CFLAGS = -Wall -Wextra -Wpedantic 

# debugging flags
CFLAGS += -g -O0 -o $(APP_NAME)
CXXFLAGS += -g -O -o $(APP_NAME)
LDFLAGS += $(CFLAGS)

vpath % src

.PHONY clean

all: main

main: main.o

clean:
	$(RM) *.o
	$(RM) ccalc