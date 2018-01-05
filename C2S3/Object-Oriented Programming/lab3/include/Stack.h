/**
 * Created by h3ll_ow0rld.
 */

#ifndef STACK_H
#define STACK_H

#include "Item.h"

class Stack
{
	public:
		Stack();

		bool isEmpty();
		void push(std::shared_ptr<Polygon>&& polygon);
		std::shared_ptr<Polygon> pop();
		void clear();

		friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
		
		virtual ~Stack();
	
	private:
		std::shared_ptr<Item> top;
};

#endif

