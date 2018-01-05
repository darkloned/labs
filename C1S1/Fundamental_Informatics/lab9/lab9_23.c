#include <stdio.h>
#include <math.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define abs(x) (((x) > 0) ? (x) : (-x))

int mod(int x, int y)
{
	int r = x % y;

	if (r > 0)
		return r;
	else
		return r + abs(y);
}

int main()
{
	int icur = 29;
	int jcur = -6;
	int lcur = 1;

	int iprev, jprev, lprev;

	// A(-10, 0) B(0, 10) C(-10, 20)
	int x[3] = {-10, 0, -10};
	int y[3] = {0, 10, 20};

	for (int k = 0; k < 50; k++)
	{
		int a = (x[1] - icur) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - jcur);
		int b = (x[2] - icur) * (y[3] - y[2]) - (x[3] - x[2]) * (y[2] - jcur);
		int c = (x[3] - icur) * (y[1] - y[3]) - (x[1] - x[3]) * (y[3] - jcur);
		
		if (((a >= 0) && (b >= 0) && (c >= 0)) || ((a <= 0) && (b <= 0) && (c <= 0)))
		{
			printf("Specified area reached at point (%d, %d) in %d steps.\n", icur, jcur, k);

			return 0;
		}

		iprev = icur;
		jprev = jcur;
		lprev = lcur;

		icur = mod(min(max(min(iprev - jprev, iprev - lprev), jprev - lprev), iprev - k), 30);
	       	jcur = mod(max(min(max(iprev - jprev, iprev - lprev), jprev - lprev), iprev - k), 30);
		lcur = mod(iprev, 30) - mod(jprev, 30) + mod(lcur, 30) - mod(k, 30);		
	}

	printf("Exceeded steps limit, stopping at point (%d, %d). Current l = %d.\n", icur, jcur, lcur);

	return 0;
}	
