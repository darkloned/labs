/**
 * Created by h3ll_ow0rld.
 */

#include "Stack.h"

Stack::Stack() : top(nullptr)
{
	std::cout << "Stack created" << std::endl;
}

bool Stack::isEmpty()
{
	return top == nullptr;
}

void Stack::push(std::shared_ptr<Polygon>&& polygon)
{
	std::shared_ptr<Item> newTop(new Item(polygon));

	newTop->setNext(top);

	top = newTop;
}

std::shared_ptr<Polygon> Stack::pop()
{
	std::shared_ptr<Polygon> topPolygon;

	if (top != nullptr)
	{
		topPolygon = top->getPolygon();
		top = top->getNext();
	}

	return topPolygon;
}

void Stack::clear()
{
	while (top != nullptr)
	{
		pop();
	}
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
	std::shared_ptr<Item> top = stack.top;

	os << "Stack of polygons:" << std::endl << "{" << std::endl;

	while (top != nullptr)
	{
		os << " -->" << *top;
		top = top->getNext();
	}

	os << "}" << std::endl;

	return os;
}

Stack::~Stack()
{
	std::cout << "Stack deleted" << std::endl;
}
