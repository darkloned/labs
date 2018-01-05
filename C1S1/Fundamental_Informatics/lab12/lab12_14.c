#include <stdio.h>
#include <stdbool.h>

int abs(int x) 
{
	return (x > 0) ? (x) : (-x);
}

int main()
{
	int a;
	while (scanf("%d", &a) == 1)
	{
		a = abs(a);
		bool res = false;

		int prev_digit = a % 10;
		a /= 10;

		while (a > 0)
		{
			if (a % 10 == prev_digit)
			{
				res = true;
				break;
			}
			
			prev_digit = a % 10;
			a /= 10;
		}

		printf("%d\n", res);
	}	

	return 0;
}
