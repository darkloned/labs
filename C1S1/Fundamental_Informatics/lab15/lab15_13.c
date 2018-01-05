#include <stdio.h>
#include <limits.h>

#define max(a, b) ((a > b) ? (a) : (b))

int main()
{
	int N, maxBottom = INT_MIN;

	scanf("%d", &N);

	int a[N][N];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &a[i][j]);
			
			if (j <= i)
			{
				maxBottom = max(a[i][j], maxBottom);
			}
		}
	}

	printf("\n");

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j >= i)
			{
				a[i][j] *= maxBottom;
			}

			printf("%d ", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}
