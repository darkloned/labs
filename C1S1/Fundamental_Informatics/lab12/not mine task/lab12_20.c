#include <stdio.h>
#include <math.h>

int sgn(int x) { return (x > 0) ? (1) : (-1); }

int main()
{
	int n;
	scanf("%d", &n);

	int sign = sgn(n);
	n *= sign;

	int len = floor(log10(n)) + 1;
	int res = 0;

	if (len < 3)
	       	printf("Incorrect input\n");
	else
	{
		if (sign == -1) printf("-");

		if (len == 3)
			printf("%d\n", (n / 100) * 10 + (n % 10));
		else
		{	
			char num[len - 1];
			num[len - 2] = '\0';
			int not_rmvd = 2;
			
			for (int i = len - 1; i >= 0; --i)
			{
				num[i - not_rmvd] = 48 + (n % 10);
				n /= 10;
				if ((i == len - 2) || (i == 1)) not_rmvd--;
			}
			
			printf("%s\n", num);
		}
	}
		
	return 0;
}
