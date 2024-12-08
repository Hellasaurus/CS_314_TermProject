CC=g++
FLAGS=-std=c++17 -g -Wall
SOURCES=./main/*.cpp
BINARIES=CS314_TermProject

all: clean $(BINARIES) ./output/*

CS314_TermProject: $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	rm -f $(BINARIES) *.o
