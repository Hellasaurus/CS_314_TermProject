CC=g++
FLAGS=-g -Wall
SOURCES=main.cpp records.cpp

CS314_TermProject: $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)
