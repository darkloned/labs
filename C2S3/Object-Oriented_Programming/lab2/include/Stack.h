/**
 * Created by h3ll_ow0rld on 9/22/17.
 */

#ifndef STACK_H
#define STACK_H

#include "Item.h"

class Stack
{
	public:
		Stack();
		Stack(const Stack& origin);
                
		friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

		bool isEmpty();
		void push(Square&& square);
		Square pop();
		
		virtual ~Stack();
	
	private:
		Item* top;
};

#endif

