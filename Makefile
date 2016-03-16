W=-pedantic -std=c++14 -W -Wall -Wconversion -Wextra -Wfatal-errors -Wwrite-strings -Wno-unused-variable -Wno-unused-parameter

all: hexxer

hexxer: hexxer.cpp
	g++ $W -O3 $< -std=c++14 -o $@

clean:
	rm -f hexxer
