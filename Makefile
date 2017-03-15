CC = g++
FLAG = -g

all: poetry.cpp parsers.cpp poetry.h
	$(CC) $(FLAG) -o poetry poetry.cpp parsers.cpp
clean:
	rm -rf poetry
	rm -rf *.dSYM/
