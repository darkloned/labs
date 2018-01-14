#include "stack.h"

Stack* newStack(int poolsize)
{
	Stack* s = (Stack*) malloc(sizeof(Stack));

	s->pool = malloc(poolsize * sizeof(double));
	s->size = 0;
	s->poolsize = poolsize;

	return s;
}

bool isEmpty(Stack* s)
{
	return s->size == 0;
}

void printStack(Stack* s)
{
	printf("Stack: ");
	for (int i = --s->size; i >= 0; --i)
	{
		printf("%.5f ", s->pool[i]);
	}
	printf("\n");

	s->size = 0; // reading stack is destructive by definition
}

void push(Stack* s, double newItem)
{
	if (s->size == s->poolsize)
	{
		printf("Push (%.5f) declined, stack is full.\n", newItem);
	}
	else
	{
		s->pool[s->size++] = newItem;
	}
}

double pop(Stack* s)
{
	if (s->size == 0)
	{
		printf("Pop declined, stack is empty. Returning zero-value.\n");

		return 0;
	}
	else
	{
		return s->pool[--s->size];
	}
}

void deleteStack(Stack* s)
{
	free(s->pool);
	free(s);
}
