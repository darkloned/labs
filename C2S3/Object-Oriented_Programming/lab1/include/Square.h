/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon.h"

class Square : public Polygon
{
	public:
		Square();
		Square(std::istream& is);
		Square(int a);
		Square(const Square& origin);
		
		bool   isDegenerate() override;
		double calcArea()     override;
		void   printParams()  override;

		virtual ~Square();

	private:
		int a;
};

#endif

