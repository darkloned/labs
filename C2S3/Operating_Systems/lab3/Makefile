CC=gcc
CSTD=-std=c99
CFLAGS=-Wall -pedantic -pthread
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab3

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

# remove if exists
clean:
	rm bin/lab3 2> /dev/null

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE)
	@echo "=========="
