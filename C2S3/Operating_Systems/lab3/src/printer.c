#include "printer.h"

PrinterArgs* newPrinterArgs(int order, int** matrix, int* dist, int startVertex, int finishVertex)
{
	PrinterArgs* args = (PrinterArgs*) malloc(sizeof(PrinterArgs));

	args->order 	   = order;
	args->matrix 	   = matrix;
	args->dist 		   = dist;
	args->startVertex  = startVertex;
	args->finishVertex = finishVertex;

	return args;
}

void* printShortestPath(void* Args)
{
	PrinterArgs* args = (PrinterArgs*) Args;

	printf("Thread created [TID: %lu]\n", pthread_self());
	printf("Path from %d to %d: ", args->startVertex + 1, args->finishVertex + 1);

	switch(args->dist[args->finishVertex])
	{
		case -1:
			printf("no path\n\n");

			break;

		case 0:
			printf("already here\n\n");

			break;

		default: ; // semicolon to avoid `labels can only be followed by statements` exception
			int path[args->dist[args->finishVertex] + 1];

			path[0] = args->finishVertex;

			int v  = args->finishVertex;

			for (int i = args->dist[args->finishVertex]; i >= 0; --i)
			{
				path[i] = v;

				for (int j = 0; j < args->order; ++j)
				{
					if (args->matrix[j][v] == 1 && args->dist[j] == args->dist[v] - 1)
					{
						v = j;

						break;
					}
				}
			}

			for (int i = 0; i <= args->dist[args->finishVertex]; ++i)
			{
				printf("%d ", path[i] + 1);
			}
			printf("\n\n");
	}

	free(args);

	pthread_exit(NULL);

	return NULL;
} 
