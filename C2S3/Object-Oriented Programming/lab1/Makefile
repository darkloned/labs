CC=g++
CSTD=-std=c++14
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab1

all: execute vcs

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE)
	@echo "=========="

vcs:
	mv $(EXECUTABLE) $(EXECUTABLE).prev

