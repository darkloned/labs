#include "headers/Matrix.h"

Matrix* new_Matrix(int M, int N)
{
	Matrix* m = (Matrix*) malloc(sizeof(Matrix));

	m->M = M;
	m->N = N;

	m->V = new_Vector();

	return m;
}

void readMatrix(Matrix* m)
{
	printf("Enter matrix %dx%d:\n", m->M, m->N);

	for (int i = 0; i < m->M; ++i)
	{
		bool zero_row = true;
		
		for (int j = 0; j < m->N; ++j)
		{
			int Aij;

			scanf("%d", &Aij);

			if (Aij != 0)
			{
				if (zero_row)
				{
					Vector_putValue(m->V, -1);
					Vector_putValue(m->V, i);
					
					zero_row = false;
				}
				
				Vector_putValue(m->V, j);
				Vector_putValue(m->V, Aij);
			}
        }
	}
        
	Vector_putValue(m->V, -1);
	Vector_putValue(m->V, -1);
}

int get2dID(Matrix* m, int i, int j)
{
	Vector* v = m->V;

	int it = 0;

	while (it < v->size)
	{
		if (Vector_getValue(v, it) == -1)
		{
			int row = Vector_getValue(v, ++it);

			if (row == -1 || row > i)
			{
				return -1;
			}
			else if (i == row)
			{
				break;
			}
		}

		it++;
	}
	
	while (it < v->size)
	{
		int column = Vector_getValue(v, ++it);

		if (column == -1 || column > j)
		{
			return -1;
		}
		else if (j == column)
		{
			return ++it;
		}

		it++;
	}

	return 0; // shouldn't be
}

int Matrix_getValue(Matrix* m, int i, int j)
{
	int index = get2dID(m, i, j);

	return (index == -1) ? 0 : Vector_getValue(m->V, index);
}

void Matrix_multiplyValue(Matrix* m, int i, int j, int koef)
{
	Vector_multiplyValue(m->V, get2dID(m, i, j), koef);
}	

void printMatrix(Matrix* m)
{
	for (int i = 0; i < m->M; ++i)
	{
		for (int j = 0; j < m->N; ++j)
		{
			printf("%d ", Matrix_getValue(m, i, j));
		}

		printf("\n");
	}
} 
