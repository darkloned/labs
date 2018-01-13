#include "queue.h"

void BFS(int order, int** matrix, int* dist, int startVertex)
{
	Queue* q = newQueue(order);

	dist[startVertex] = 0;

	push(q, startVertex);

	while (!isEmpty(q))
	{
		int v = pop(q);

		for (int i = 0; i < order; ++i)
		{
			if (matrix[v][i] == 1 && dist[i] == -1)
			{
				dist[i] = dist[v] + 1;

				push(q, i);
			}
		}
	}

	deleteQueue(q);
}
