CFLAGS=-std=c++14 -pedantic -W -Wall -Wconversion -Wextra -Wfatal-errors -Wwrite-strings -Wno-unused-variable -Wno-unused-parameter
OFLAGS=-O3

.PHONY: test

hexxer: hexxer.cpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@

test: hexxer
	cd test && ./hexxer.sh

clean:
	rm hexxer
