/**
 * Created by h3ll_ow0rld on 9/23/17.
 */

#include "Square.h"

Square::Square() : Square(0)
{
	printf("Default square created\n");
}

Square::Square(int edge) : edge(edge)
{
	printf("Square(%d) created\n", edge);
}

Square::Square(const Square& origin)
{
	edge = origin.edge;

	printf("Square(%d) copied\n", edge);
}

std::istream& operator>>(std::istream& is, Square& square)
{
	is >> square.edge;

	return is;
}	

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	os << "Square(" << square.edge << ")" << std::endl;

	return os;
}

double Square::calcArea()
{
	return edge * edge;
}

Square operator+(const Square& lsquare, const Square& rsquare)
{
	return Square(lsquare.edge + rsquare.edge);
}

Square& Square::operator=(const Square& rsquare)
{
	edge = rsquare.edge;

	printf("Square(%d) assigned\n", edge);

	return *this;
}

Square& Square::operator++()
{
	printf("%d - ", edge);
	edge++;
	printf("%d\n", edge);

	return *this;
}

Square::~Square()
{
	//std::cout << "Square(" << edge << ")deleted" << std::endl; 
	printf("Square(%d) deleted\n", edge);
}

