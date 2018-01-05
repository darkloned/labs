/**
 * Created by h3ll_ow0rld on 9/12/17.
 */

#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"

int main(int argc, char** argv)
{
	Polygon* triangle = new Triangle(std::cin);

	if (!triangle->isDegenerate())
	{		
       	triangle->printParams();
		printf("Triangle area = %g\n", triangle->calcArea());
	}
	else
	{
		printf("Degenerate triangle entered\n");
    }

	delete triangle;

    /***/ printf("\n");
        
	Polygon* square = new Square(std::cin);

	if (!square->isDegenerate())
	{	
    	square->printParams();
    	printf("Square area = %g\n", square->calcArea());
    }
	else
	{
		printf("Degenerate square entered\n");
	}

    delete square;
        
    /***/ printf("\n");
        
	Polygon* octagon = new Octagon (std::cin);

    octagon->printParams();
    printf("Octagon area = %g\n", octagon->calcArea());
        
	delete octagon;

	return 0;
}
