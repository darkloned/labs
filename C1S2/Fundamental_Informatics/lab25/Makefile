# nice lab26
CC=gcc

CFLAGS=-std=c99 -Wall -pedantic

all: lab

lab: main.o Node.o List.o Iterator.o
	$(CC) main.o Node.o List.o Iterator.o -o lab25

main.o: main.c
	$(CC) -c main.c

Node.o: Node.c #headers/Node.h
	$(CC) -c Node.c	
	
List.o: List.c #headers/List.h
	$(CC) -c List.c

Iterator.o: Iterator.c #headers/Iterator.h
	$(CC) -c Iterator.c

clean:
	rm *.o lab25

