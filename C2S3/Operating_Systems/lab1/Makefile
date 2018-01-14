CC=gcc
CSTD=-std=c99
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab1

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

clean:
	rm -f bin/lab1
	rm -f out/*

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE)
	@echo "=========="

