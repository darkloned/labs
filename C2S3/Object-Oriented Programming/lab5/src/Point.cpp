/**
 * Created by h3ll_ow0rld.
 */

#include "Point.h"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

bool operator==(const Point& left, const Point& right)
{
	return (left.x == right.x && 
			left.y == right.y );
}
