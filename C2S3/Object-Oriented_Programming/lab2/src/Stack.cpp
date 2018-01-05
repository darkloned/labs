/**
 * Created by h3ll_ow0rld on 9/22/17.
 */

#include "Stack.h"

Stack::Stack() : top(nullptr)
{
	printf("Stack created\n");
}

Stack::Stack(const Stack& origin)
{
	top = origin.top;

	printf("Stack copied\n");
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
	Item* item = stack.top;

	while (item != nullptr)
	{
		os << *item;
		item = item->getNext();
	}

	return os;
}

bool Stack::isEmpty()
{
	return top == nullptr;
}

void Stack::push(Square&& square)
{
	Item* newTop = new Item(square);

	newTop->setNext(top);

	top = newTop;
}

Square Stack::pop()
{
	Square topSquare;

	if (top != nullptr)
	{
		topSquare = top->getSquare();

		Item* oldTop = top;
		top = oldTop->getNext();
		
		oldTop->setNext(nullptr);
		
		delete oldTop;
	}

	return topSquare;
}

Stack::~Stack()
{
	delete top;
	
	printf("Stack deleted\n");
}

