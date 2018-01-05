/**
 * Created by h3ll_ow0rld.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
	public:
		Point();
		Point(int x, int y);
		
		// getters
		int getX() const;
		int getY() const;

		friend bool operator==(const Point& left, const Point& right);
                
    private:
		int x, y;
};

#endif

