CC=g++
FLAGS=-std:c++17 -g -Wall
SOURCES=main.cpp records.cpp

all: CS314_TermProject

CS314_TermProject: $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)
