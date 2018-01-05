/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#include "Octagon.h"

Octagon::Octagon(std::istream& is)
{
	printf("Enter octagon coordinates:\n");

	for (int i = 0; i < 8; ++i)
	{
		int x, y;

		is >> x >> y;

		coords[i] = Point(x, y);
	}
}

Octagon::Octagon(const Octagon& orig)
{
	for (int i = 0; i < 8; ++i)
	{
		coords[i] = orig.coords[i];
	}

	printf("Octagon copied\n");
}

bool Octagon::isDegenerate()
{
	for (int i = 0; i < 8; ++i)
	{
		if (coords[i] == coords[(i + 1) % 8])
		{
			return true;
		}
	}

	return false;
}

// shoelace formula
double Octagon::calcArea()
{
	int left = 0, right = 0;

	for (int i = 0; i < 8; ++i)
	{
		left  += coords[i].getX() * coords[(i + 1) % 8].getY();
		right += coords[i].getY() * coords[(i + 1) % 8].getX();
	}

	return abs(right - left) / 2;
}

void Octagon::printParams()
{
	printf("Octagon:\n");

	for (int i = 0; i < 8; ++i)
	{
		coords[i].print();
	}
}

Octagon::~Octagon()
{
	printf("Octagon deleted\n");
}

