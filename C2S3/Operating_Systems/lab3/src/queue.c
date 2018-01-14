#include "queue.h"

Queue* newQueue(int poolsize)
{
	Queue* q = (Queue*) malloc(sizeof(Queue));

	q->pool  = malloc(poolsize * sizeof(int));
	
	q->size  = 0;
	q->front = 0;
	q->back  = 0;

	return q;
}

bool isEmpty(Queue* q)
{
	return q->size == 0;
}

// not failsafe functions below

void push(Queue* q, int v)
{
	q->back = isEmpty(q) ? q->front : (q->back + 1) % ARRAYSIZE(q->pool);
	q->pool[q->back] = v;

	q->size++;
}

int pop(Queue* q)
{
	int v = q->pool[q->front];

	q->front = (q->front + 1) % ARRAYSIZE(q->pool);

	q->size--;

	return v;
}

void deleteQueue(Queue* q)
{
	free(q->pool);
	free(q);
} 
