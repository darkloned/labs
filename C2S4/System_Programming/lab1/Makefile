CC=g++
CSTD=-std=c++14
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SOURCES=src/*
EXECUTABLE=bin/lab1

all: clean execute

$(EXECUTABLE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $@

clean:
	rm bin/lab1
	
execute: $(EXECUTABLE)
	@echo "=========="
	$(EXECUTABLE)
	@echo "=========="
	

