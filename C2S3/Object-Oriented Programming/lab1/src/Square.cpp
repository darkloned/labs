/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#include "Square.h"

Square::Square() : Square(0) {}

Square::Square(int a) : a(a)
{
	printf("new Square(%d) created\n", a);
}

Square::Square(std::istream& is)
{
	printf("Enter square side: ");

	is >> a;
}

Square::Square(const Square& orig)
{
	a = orig.a;

	printf("Square(%d) copied\n", a);
}

bool Square::isDegenerate()
{
	return !(a > 0);
}

double Square::calcArea()
{
	return a * a;
}

void Square::printParams()
{
	printf("Square(%d)\n", a);
}

Square::~Square()
{
	printf("Square deleted\n");
}

