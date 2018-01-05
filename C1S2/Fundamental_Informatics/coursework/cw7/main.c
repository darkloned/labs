#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vector.c"
#include "Matrix.c"

int main()
{
	int M, N;
	int x;

	printf("Enter matrix size: ");
	scanf("%d %d", &M, &N);

	Matrix* m = new_Matrix(M, N);

	readMatrix(m);
    
	printVector(m->V);
	
	printf("Enter value: ");
	scanf("%d", &x);

	int prox = Matrix_getValue(m, 0, 0);
	int xProx = 0, yProx = 0;

	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < M; ++i)
		{
			int Aij = Matrix_getValue(m, i, j);

			if (Aij != 0 && abs(x - Aij) < abs(x - prox))
			{
				prox = Aij;

				xProx = i;
				yProx = j;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		Matrix_multiplyValue(m, i, yProx, prox);
	}

	for (int j = 0; j < N; ++j)
	{
		Matrix_multiplyValue(m, xProx, j, prox);
	}
	
	printf("Proximate coefficient: %d\n", prox);
	printf("Processed matrix:\n");
	printMatrix(m);
	printVector(m->V);

	return 0;
}
