CC=gcc
CSTD=-std=c99
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab2

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

clean:
	rm -f bin/lab2
	rm -f out/*

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE) $s
	@echo "=========="

