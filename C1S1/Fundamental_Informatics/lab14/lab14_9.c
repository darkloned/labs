#include <stdio.h>
#include <stdbool.h>

typedef enum {TOP, BOTTOM} Side;
typedef enum {UP, DOWN} Direction;

int main()
{
	int N;
	Side side = BOTTOM;
	Direction direction = UP;

	scanf("%d", &N);
	
	int a[N][N];
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", (*(a + i) + j));
		}
	}

	int i = N;
	int j = 1;

	printf("\n%d ", a[i - 1][j - 1]);

	while ((i != 1) || (j != N))
	{
		if (side == BOTTOM)
		{
			if (direction == DOWN)
			{
				if (i < N)
				{
					i++;
				}
				else
				{
					direction = UP;
				}

				j++;

				if (j == N)
				{
					side = TOP;
				}
			}
			else if (direction == UP)
			{
				if (j > 1)
				{
					j--;
				}
				else
				{	
					direction = DOWN;
				}

				i--;

				if (i == 1)
				{
					side = TOP;
				}
			}
		}
		else if (side == TOP)
		{
			if (direction == DOWN)
			{
				if (j < N)
				{
					i++;
					j++;
				}
				else
				{
					if (i > 1)
					{
						i--;
						direction = UP;
					}
				}
			}
			else if (direction == UP)
			{
				if (i > 1)
				{
					i--;
					j--;
				}
				else
				{
					j++;
					direction = DOWN;
				}
			}
		}

		printf("%d ", a[i - 1][j - 1]);
	}

	printf("\n");
		
	return 0;
}
