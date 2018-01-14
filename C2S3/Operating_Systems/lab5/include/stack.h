#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
	 double* pool;
	 int size, poolsize;

} Stack;

extern Stack* newStack(int poolsize);

extern bool isEmpty(Stack* s);
extern void printStack(Stack* s);

extern void push(Stack* s, double item);
extern double pop(Stack* s);

extern void deleteStack(Stack* s);

#endif
