/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#include "Point.h"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x(x), y(y) {}

bool operator==(const Point& left, const Point& right)
{
	return (left.x == right.x && 
			left.y == right.y );
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::print()
{
	printf("(%d, %d)\n", x, y);
}	
