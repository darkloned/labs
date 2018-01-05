/**
 * Created by h3ll_ow0rld.
 */

#ifndef STACK_H
#define STACK_H

#include "Item.h"
#include "Iterator.h"

template <class T> class Stack
{
public:
	Stack();
	
	bool isEmpty();
	void push(std::shared_ptr<T>&& value);
	std::shared_ptr<T> pop();
	void clear();

	Iterator<Item<T>, T> begin();
	Iterator<Item<T>, T> end();

	template <class A> friend std::ostream& operator<<(std::ostream& os, const Stack<A>& stack);

	virtual ~Stack();

private:
	std::shared_ptr<Item<T>> top;
};

#endif
