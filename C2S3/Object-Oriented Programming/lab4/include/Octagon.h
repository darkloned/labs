/**
 * Created by h3ll_ow0rld.
 */

#ifndef OCTAGON_H
#define OCTAGON_H

#include "Polygon.h"
#include "Point.h"

class Octagon : public Polygon
{
	public:
		Octagon(const Octagon& origin);
		Octagon(std::istream& is);

		void print(std::ostream& os) override;

		//Octagon& operator=(const Octagon& roctagon);

		virtual ~Octagon();

	private:
		Point coords[8];
};

#endif

