CXX=g++
CFLAGS=-std=c++14 -pedantic -W -Wall -Wconversion -Wextra -Wfatal-errors -Wwrite-strings -Wno-unused-variable -Wno-unused-parameter
OFLAGS=-O3

all: hexxer

hexxer: hexxer.cpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@

clean:
	rm hexxer
