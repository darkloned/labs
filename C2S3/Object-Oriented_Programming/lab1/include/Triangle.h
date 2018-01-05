/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon
{
	public:
		Triangle();
		Triangle(std::istream& is);
		Triangle(int a, int b, int c);
		Triangle(const Triangle& origin);

		bool   isDegenerate() override;
		double calcArea()     override;
		void   printParams()  override;

		virtual ~Triangle();

	private:
		int a, b, c;
};

#endif

