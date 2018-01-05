/**
 * Created by h3ll_ow0rld.
 */

#include "Octagon.h"

Octagon::Octagon(const Octagon& origin)
{
	for (int i = 0; i < 8; ++i)
	{
		coords[i] = origin.coords[i];
	}

	std::cout << "Octagon copied" << std::endl;
}

Octagon::Octagon(std::istream& is)
{
	std::cout << "Enter octagon coordinates:" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		int x, y;

		is >> x >> y;

		coords[i] = Point(x, y);
	}
}

void Octagon::print(std::ostream& os)
{
	os << "Octagon(" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		os << "    " << coords[i].getX() << " " << coords[i].getY() << std::endl;
	}

	os << ")";
}

Octagon::~Octagon()
{
	std::cout << "Octagon deleted" << std::endl;
}

