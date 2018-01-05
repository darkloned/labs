/**
 * Created by h3ll_ow0rld on 9/23/17.
 */

#include "Square.h"
#include "Stack.h"

int main(int argc, char** argv)
{
	Stack stack;

	stack.push(Square(13));
	stack.push(Square(42));
	stack.push(Square(77));

	std::cout << stack;

	while (!stack.isEmpty())
	{
		std::cout << stack.pop();
	}

	return 0;
}
