/**
 * Created by h3ll_ow0rld.
 */

#include "Stack.h"

template <class T> Stack<T>::Stack() : top(nullptr)
{
	std::cout << "Stack created" << std::endl;
}

template <class T> bool Stack<T>::isEmpty()
{
	return top == nullptr;
}

template <class T> void Stack<T>::push(std::shared_ptr<T>&& value)
{
	std::shared_ptr<Item<T>> newTop(new Item<T>(value));

	newTop->setNext(top);

	top = newTop;
}

template <class T> std::shared_ptr<T> Stack<T>::pop()
{
	std::shared_ptr<T> topValue;

	if (top != nullptr)
	{
		topValue = top->getValue();
		top = top->getNext();
	}

	return topValue;
}

template <class T> void Stack<T>::clear()
{
	while (top != nullptr)
	{
		pop();
	}
}

template <class T> std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
	std::shared_ptr<Item<T>> top = stack.top;

	os << "Stack of polygons:" << std::endl << "{" << std::endl;

	while (top != nullptr)
	{
		os << " -->" << *top;
		top = top->getNext();
	}

	os << "}" << std::endl;

	return os;
}

template <class T> Iterator<Item<T>, T> Stack<T>::begin()
{
	return Iterator<Item<T>, T>(top);
}

template <class T> Iterator<Item<T>, T> Stack<T>::end()
{
	return Iterator<Item<T>, T>(nullptr);
}

template <class T> Stack<T>::~Stack()
{
	std::cout << "Stack deleted" << std::endl;
}


template class Stack<Polygon>;

template std::ostream& operator<<(std::ostream& os, const Stack<Polygon>& stack);
