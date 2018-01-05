#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> // compile with -lm key

const double eps = 1E-8;

double f27(double x)
{
	double ln_x = log(x);

	return sin(ln_x) - cos(ln_x) + 2*ln_x;
}

double f28(double x)
{
	return x - 2 + sin(1 / x);
}

double phi27(double x)
{
	double ln_x = log(x);

	return pow(exp(1), (cos(ln_x) - sin(ln_x)) / 2);
}

double phi28(double x)
{
	return 2 - sin(1 / x);
}

double sqr(double x)
{
	return x * x;
}

double diff(double f(double), double x, int order)
{
	double x1 = x - eps, x2 = x + eps;
	double y1, y2;

	if (order == 1)
	{
		y1 = f(x1);
		y2 = f(x2);
	}
	else
	{
		y1 = diff(f, x1, order - 1);
		y2 = diff(f, x2, order - 1);
	}

	return (y2 - y1) / (2 * eps);
}

double dichotomie(double f(double), double lx, double rx) // (left, right)
{
	double dx, mx;

	do
	{
		dx = fabs(lx - rx);  // delta
		mx = (lx + rx) / 2;  // middle

		if (f(lx) * f(mx) > 0)
			lx = mx;
		else
			rx = mx;
	}
	while (dx > eps);

	return mx;
}

double iterations(double f(double), double phi(double),
		  const double lx, const double rx,
		  double x, bool *isConvergent)
{
	// sufficient condition for convergence
	if (fabs(diff(phi, x, 1)) >= 1)
	{
		*isConvergent = false;

		return 0;
	}

	// new value
	double phi_x = phi(x);

	// termination condition
	if (fabs(phi_x - x) < eps)
	{
		*isConvergent = true;
		
		return phi_x;
	}

	// new iteration
	return iterations(f, phi, lx, rx, phi_x, &(*isConvergent));
}

double newton(double f(double), double x, bool *isConvergent)
{
	// sufficient condtion for convergence
	if (fabs(f(x) * diff(f, x, 2)) >= sqr(diff(f, x, 1)))
	{
		*isConvergent = false;

		return 0;
	}

	// convergence delta
	double k = f(x) / diff(f, x, 1); // TODO: diff != 0?

	// new value
	x -= k;

	// termination condition
	if (fabs(k) < eps)
	{
		*isConvergent = true;

	     	return x;
	}

	// new iteration
	return newton(f, x, &(*isConvergent));
}

int main()
{
	double x, lx, rx;
	
	scanf("%lf %lf", &lx, &rx);

	double mx = (lx + rx) / 2;
	bool isConvergent = true;

	printf("Dichotomie: %f\n", dichotomie(f27, lx, rx));

	printf("Iterations: ");
        x = iterations(f27, phi27, lx, rx, mx, &isConvergent);	
	if (isConvergent)
		printf("%f\n", x);
	else
		printf("FALSE\n");

	printf("Newton: ");
	x = newton(f27, mx, &isConvergent);
	if (isConvergent)
		printf("    %f\n", x);
	else
		printf("FALSE\n");

	return 0;
}
