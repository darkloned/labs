/**
 * Created by h3ll_ow0rld.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon
{
	public:
		Triangle();
		Triangle(int a, int b, int c);
		Triangle(const Triangle& origin);
        Triangle(std::istream& is);
 
		void print(std::ostream& os) override;

		Triangle& operator=(const Triangle& rtriangle);   

		virtual ~Triangle();

	private:
		int a, b, c;
};

#endif
