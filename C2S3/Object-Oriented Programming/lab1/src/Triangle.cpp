/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#include "Triangle.h"

Triangle::Triangle() : Triangle(0 ,0 ,0) {}

Triangle::Triangle(int a, int b, int c) : a(a), b(b), c(c)
{
	printf("new Triangle(%d, %d, %d) created\n", a, b, c);
}

Triangle::Triangle(std::istream& is)
{
	printf("Enter triangle sides: ");

	is >> a >> b >> c;
}

Triangle::Triangle(const Triangle& orig)
{
	a = orig.a;
	b = orig.b;
	c = orig.c;

	printf("Triangle(%d, %d, %d) copied\n", a, b, c);
}

bool Triangle::isDegenerate()
{
	return !(a > 0     && 
			 b > 0     && 
			 c > 0     &&
		     a + b > c &&
			 b + c > a &&
			 c + a > b );
}

double Triangle::calcArea()
{
	double p = (a + b + c) / 2.;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::printParams()
{
	printf("Triangle(%d, %d, %d)\n", a, b, c);
}

Triangle::~Triangle()
{
	printf("Triangle deleted\n");
}

