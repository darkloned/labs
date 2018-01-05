/**
 * Created by h3ll_ow0rld.
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon.h"

class Square : public Polygon
{
	public:
		Square();
		Square(int edge);
		Square(const Square& origin);
        Square(std::istream& is);
 
		void print(std::ostream& os) override;

		Square& operator=(const Square& rsquare);   

		virtual ~Square();

	private:
		int edge;
};

#endif

