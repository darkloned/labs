/**
 * Created by h3ll_ow0rld on 9/23/17.
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square
{
	public:
		Square();
		Square(int edge);
		Square(const Square& origin);

		friend std::istream& operator>>(std::istream& is,       Square& square); 
		friend std::ostream& operator<<(std::ostream& os, const Square& square);

		double calcArea();

		friend	Square  operator+(const Square& lsquare, const Square& rsquare);
				Square& operator=(const Square& rsquare);
				Square& operator++();   

		virtual ~Square();

	private:
		int edge;
};

#endif

