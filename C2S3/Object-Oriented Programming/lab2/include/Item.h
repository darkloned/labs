/**
 * Created by h3ll_ow0rld on 9/23/17.
 */

#ifndef ITEM_H
#define ITEM_H

#include "Square.h"

class Item
{
	public:
		Item(const Square& square);
		Item(const Item& origin);

		friend std::ostream& operator<<(std::ostream& os, const Item& item);

		Item* setNext(Item* next);
		Item* getNext();
		Square getSquare() const;

		virtual ~Item();

	private:
		Square square;
		Item* next;
};

#endif

