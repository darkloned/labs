/**
 * Created by h3ll_ow0rld.
 */

#include "Triangle.h"

Triangle::Triangle() : Triangle(0, 0, 0)
{
	std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(int a, int b, int c) : a(a), b(b), c(c)
{
	std::cout << "Triangle(" << a << ", " << b << ", " << c << ") created" << std::endl;
}

Triangle::Triangle(const Triangle& origin)
{
	a = origin.a;
	b = origin.b;
	c = origin.c;

	std::cout << "Triangle(" << a << ", " << b << ", " << c << ") copied" << std::endl;
}

Triangle::Triangle(std::istream& is)
{
	std::cout << "Enter triangle sides: ";

	is >> a >> b >> c;
}

void Triangle::print(std::ostream& os)
{
	os << "Triangle(" << a << ", " << b << ", " << c << ")";
}

Triangle& Triangle::operator=(const Triangle& rtriangle)
{
	a = rtriangle.a;
	b = rtriangle.b;
	c = rtriangle.c;

	std::cout << "Triangle(" << a << ", " << b << ", " << c << ") assigned" << std::endl;

	return *this;
}

Triangle::~Triangle()
{
	std::cout << "Triangle(" << a << ", " << b << ", " << c << ") deleted" << std::endl;
}

