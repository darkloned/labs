CC=gcc
CSTD=-std=c99
CFLAGS=-Wall -pedantic -pthread
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab3

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

clean:
	rm -f bin/lab3

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE)
	@echo "=========="
