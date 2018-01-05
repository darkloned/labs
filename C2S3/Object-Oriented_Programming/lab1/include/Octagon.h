/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#ifndef OCTAGON_H
#define OCTAGON_H

#include "Polygon.h"
#include "Point.h"

class Octagon : public Polygon
{
	public:
		Octagon();
		Octagon(std::istream& is);
		Octagon(const Octagon& origin);

		bool   isDegenerate() override;
		double calcArea()     override;
		void   printParams()  override;

		virtual ~Octagon();

	private:
		Point coords[8];
};

#endif

