#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

#define ARRAYSIZE(a) (sizeof(a) / sizeof(*a))

typedef struct Queue
{
	int* pool;
	int size, front, back;

} Queue;

extern Queue* newQueue(int poolsize);

extern bool isEmpty(Queue *q);

extern void push(Queue* q, int v);
extern int pop(Queue* q);

extern void deleteQueue(Queue* q);

#endif
