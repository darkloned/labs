/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
	public:
		Point();
		Point(int x, int y);
                
        friend bool operator==(const Point& left, const Point& right);
		
		// getters
		int getX() const;
		int getY() const;

		void print();
                
    private:
		int x, y;
};

#endif

