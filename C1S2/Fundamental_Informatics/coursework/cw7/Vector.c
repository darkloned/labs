#include "headers/Vector.h"

Vector* new_Vector()
{
	Vector* v = (Vector*) malloc(sizeof(int));

	v->arr = (int*) malloc(sizeof(int));
	v->size = 0;
	v->maxSize = 1;

	return v;
}

int Vector_getValue(Vector* v, int index)
{
	return v->arr[index];
}

void Vector_multiplyValue(Vector* v, int index, int koef)
{
	v->arr[index] *= koef;
}

void Vector_putValue(Vector* v, int value)
{
	if (v->size == v->maxSize)
	{
		v->maxSize *= 2;
		v->arr = (int*) realloc(v->arr, v->maxSize * sizeof(int));
	}

	v->arr[v->size++] = value;
}

void printVector(Vector* v)
{
	printf("Rarefied matrix: ");

	for (int i = 0; i < v->size; ++i)
	{
		printf("%d ", Vector_getValue(v, i));
	}

	printf("\n");
}

