#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector
{
	int *arr;
	int size;
	int maxSize;

} Vector;

Vector* new_Vector();

int Vector_getValue(Vector* v, int index);

void Vector_multiplyValue(Vector* v, int index, int koef);

void Vector_putValue(Vector* v, int value);

void printVector(Vector* v);

#endif
