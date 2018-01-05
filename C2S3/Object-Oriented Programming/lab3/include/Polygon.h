/**
 * Created by h3ll_ow0rld.
 */

#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>

class Polygon
{
	public:
		friend std::ostream& operator<<(std::ostream& os, Polygon& polygon);
		
		virtual void print(std::ostream& os) = 0;

		virtual ~Polygon() {};
};

#endif

