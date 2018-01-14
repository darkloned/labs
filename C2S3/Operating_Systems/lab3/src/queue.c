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

void push(Queue* q, int v)
{
	if (q->size == sizeof(q->pool) / sizeof(int))
	{
		printf("Push (%d) declined, queue is full.\n", v);
	}
	else
	{
		q->back = isEmpty(q) ? q->front : (q->back + 1) % ARRAYSIZE(q->pool);
		q->pool[q->back] = v;

		q->size++;
	}
}

int pop(Queue* q)
{
	if (q->size == 0)
	{
		printf("Pop declined, queue is empty. Returning zero-value.\n");

		return 0;
	}
	else
	{
		int v = q->pool[q->front];

		q->front = (q->front + 1) % ARRAYSIZE(q->pool);

		q->size--;

		return v;
	}
}

void deleteQueue(Queue* q)
{
	free(q->pool);
	free(q);
} 
