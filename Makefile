CC = g++
FLAG = -g

all: poetry.cpp
	$(CC) $(FLAG) -o poetry poetry.cpp
clean:
	rm -rf poetry
	rm -rf *.dSYM/
