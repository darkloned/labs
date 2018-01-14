/*
 * Created by darkloned.
 * Task 21:
 *  Using BFS find the shortest path in the oriented graph.
 *  Explore multithreading (one thread for each pair [given vertex; random vertex]).
 * 
 *  See log file for usage example.
 */ 

#include "bfs.h"
#include "printer.h"

int main(int argc, char* argv[])
{
	int order; // number of vertices

	printf("Enter graph order: ");
	scanf("%d", &order);

	int** matrix = malloc(order * sizeof(int*)); // adjacency matrix

	for (int i = 0; i < order; ++i)
	{
		matrix[i] = malloc(order * sizeof(int));
	}

	printf("Enter adjacency matrix:\n");

	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	int startVertex;

	printf("Enter start vertex: ");  // for BFS-traversal of the graph
	scanf("%d", &startVertex);

	startVertex--; // to counting-from-zero style

	/***reading finished***/

	int dist[order];

	for (int i = 0; i < order; ++i)
	{
		dist[i] = -1;
	}

	BFS(order, 
		matrix, 
		dist, 
		startVertex);

	printf("\n");

	pthread_t* thread = malloc(order * sizeof(pthread_t));

	for (int finishVertex = 0; finishVertex < order; ++finishVertex)
	{
		PrinterArgs* args = newPrinterArgs(order,
			matrix,
			dist,
			startVertex,
			finishVertex);

		int threadStatus = pthread_create(&thread[finishVertex],
			NULL,
			&printShortestPath,
			(void*) args);

		if (threadStatus)
		{
			printf("Thread[%d] creation error.\n", finishVertex + 1);

			return 1;
		}
	}

	for (int finishVertex = 0; finishVertex < order; ++finishVertex)
	{
		pthread_join(thread[finishVertex], NULL);
	}

	/***freeing memory***/

	for (int i = 0; i < order; ++i)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(thread);

	/***done***/

	return 0;
}
