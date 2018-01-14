#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct PrinterArgs
{
	int order;
	int** matrix;
	int* dist;
	int startVertex, finishVertex;

} PrinterArgs;

extern PrinterArgs* newPrinterArgs(int order, int** matrix, int* dist, int startVertex, int finishVertex);
extern void* printShortestPath(void* Args);

#endif
