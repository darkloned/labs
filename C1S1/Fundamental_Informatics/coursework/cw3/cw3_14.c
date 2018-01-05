#include <stdio.h>
#include <math.h> // compile with -lm key

double epsilon()
{
	double eps = 1;

	while (1 + eps/2 > 1)
		eps /= 2;

	return eps;
}

double f(double x)
{
	return (2*x - 3) / ((x - 1) * (x - 1));
}

// tsr - taylor series result
double taylor(double x, int *iterations, double eps)
{
	int i = 1; // number of iterations
	double pow_x = 1; // x^0
	double summand = -3, tsr = summand;

	while (fabs(summand) > eps && i < 100)
	{
		pow_x *= x;
		summand = -(i + 3) * pow_x;
		tsr += summand;
		i++;
	}

	*iterations = i;
	return tsr;
}

int main()
{
	int n;
	double lx = 0.1, rx = 0.6;
	const double eps = epsilon();

	printf("Machine epsilon = %e\n", eps);
	printf("Amount of splits: ");
	scanf("%d", &n);
	printf("+---------------------------------------------------------------------------+\n");
    	printf("|    Argument    |    Function     |     Taylor      |     Delta      |  i  |\n");
    	printf("+---------------------------------------------------------------------------+\n");	

	double dx = (rx - lx) / n; // step length

	for (int i = 0; i <= n; ++i)
	{
		int iterations;
		double x = lx + dx * i;
		double f_x = f(x), ts = taylor(x, &iterations, eps);

		printf("|  %e  |  %e  |  %e  |  %e  | %3d |\n", x, f_x, ts, fabs(f_x - ts), iterations);
	}

	printf("+---------------------------------------------------------------------------+\n");	

	return 0;
}
