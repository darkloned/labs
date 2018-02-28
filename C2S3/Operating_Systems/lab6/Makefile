CC=g++
CSTD=-std=c++14
CFLAGS=-Wall -pedantic
INCLUDE=-Iinclude
SERVERSRC=src/Server.cpp
CLIENTSRC=src/Client.cpp
SERVEREXEC=bin/Server
CLIENTEXEC=bin/Client

all: clean build_server_exec build_client_exec

build_server_exec:
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(SERVERSRC) -o $(SERVEREXEC) -lzmq
	
build_client_exec:
	$(CC) $(CSTD) $(CFLAGS) $(INCLUDE) $(CLIENTSRC) -o $(CLIENTEXEC) -lzmq

clean:
	rm -f bin/lab6
