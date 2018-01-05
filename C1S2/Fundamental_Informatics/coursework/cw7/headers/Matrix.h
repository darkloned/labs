#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix
{
	int M, N;
	Vector* V;

} Matrix;

Matrix* new_Matrix(int M, int N);

void readMatrix(Matrix* m);

int get2dID(Matrix* m, int i, int j);

int Matrix_getValue(Matrix* m, int i, int j);

void Matrix_multiplyValue(Matrix* m, int i, int j, int koef);	

void printMatrix(Matrix* m);

#endif
