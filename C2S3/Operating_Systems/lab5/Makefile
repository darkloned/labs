CC=gcc
CSTD=-std=c99
CFLAGS=-Wall
INCLUDE=-Iinclude

STCSRC=src/static/*
STCEXE=bin/lab5stc

DYNSRC=src/dynamic/*
DYNEXE=bin/lab5dyn

DYNLIB=lib/stack.so
LIBSRC=src/static/stack.c

all: clean stcexec clib dynexec

$(STCEXE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(STCSRC) -o $@

$(DYNEXE):
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(DYNSRC) -o $@ -ldl

clean:
	rm -f $(STCEXE)
	rm -f $(DYNEXE)
	rm -f $(DYNLIB)

stcexec: $(STCEXE)
	@echo "====STATIC==="
	$(STCEXE)
	@echo "============="

clib:
	$(CC) $(CSTD) $(CFLAGS) -shared -o $(DYNLIB) -fPIC $(INCLUDE) $(LIBSRC)

dynexec: $(DYNEXE)
	@echo "===DYNAMIC==="
	$(DYNEXE)
	@echo "============="
