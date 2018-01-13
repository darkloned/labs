CC=gcc
CSTD=-std=c99
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab2

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

# remove if exists
clean:
	rm bin/lab2 2> /dev/null

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE) $s
	@echo "=========="

