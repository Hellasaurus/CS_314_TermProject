CC=g++
FLAGS=-std=c++17 -g -Wall
SOURCES=./main/*.cpp
TESTS=./tests/*.cpp
BINARIES=CS314_TermProject

all: clean $(BINARIES)

CS314_TermProject: $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)

test: $(SOURCES)
	$(CC) -0 $@ $^ $(FLAGS)

clean:
	rm -f $(BINARIES) *.o ./output/*
