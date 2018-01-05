/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#ifndef POLYGON_H
#define POLYGON_H

#include <cmath>
#include <iostream>

class Polygon
{
	public:
		virtual bool   isDegenerate() = 0;
		virtual double calcArea()     = 0;
		virtual void   printParams()  = 0;
		
		virtual ~Polygon() {};
};

#endif

