/**
 * Created by h3ll_ow0rld.
 */

#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"
#include "Stack.h"

int main(int argc, char** argv)
{
	Stack<Polygon> stack;
	
	Polygon* triangle = new Triangle(std::cin);
	Polygon* square   = new Square(std::cin);
	Polygon* octagon  = new Octagon(std::cin);

	stack.push(std::shared_ptr<Polygon>(triangle));
	stack.push(std::shared_ptr<Polygon>(square));
	stack.push(std::shared_ptr<Polygon>(octagon));
        
    for (auto i : stack)
    {
    	std::cout << *i << std::endl;
    }
	
	stack.clear();

	return 0;
}
