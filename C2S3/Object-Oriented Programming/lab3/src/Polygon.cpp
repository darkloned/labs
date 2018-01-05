/**
 * Created by h3ll_ow0rld.
 */

#include "Polygon.h"

std::ostream& operator<<(std::ostream& os, Polygon& polygon)
{
	polygon.print(os);

	return os;
}

