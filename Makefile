CC=g++
FLAGS=-std=c++17 -g -Wall
SOURCES=./main/main.cpp ./main/records.cpp ./main/address.cpp

all: CS314_TermProject

CS314_TermProject: $(SOURCES)
	$(CC) -o $@ $^ $(FLAGS)
