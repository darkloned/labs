/**
 * Created by h3ll_ow0rld.
 */

#include "Square.h"

Square::Square() : Square(0)
{
	std::cout << "Default square created" << std::endl;
}

Square::Square(int edge) : edge(edge)
{
	std::cout << "Square(" << edge << ") created" << std::endl;
}

Square::Square(const Square& origin)
{
	edge = origin.edge;

	std::cout << "Square(" << edge << ") copied" << std::endl;
}

Square::Square(std::istream& is)
{
	std::cout << "Enter square side: ";

	is >> edge;
}

void Square::print(std::ostream& os)
{
	os << "Square(" << edge << ")";
}

Square& Square::operator=(const Square& rsquare)
{
	edge = rsquare.edge;

	std::cout << "Square(" << edge << ") assigned" << std::endl;

	return *this;
}

Square::~Square()
{
	std::cout << "Square(" << edge << ") deleted" << std::endl;
}

