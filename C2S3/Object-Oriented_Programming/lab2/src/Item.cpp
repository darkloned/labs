/**
 * Created by h3ll_ow0rld on 9/23/17.
 */

#include "Item.h"

Item::Item(const Square& square)
{
	this->square = square;
	this->next = nullptr;

	printf("Item created\n");
}

Item::Item(const Item& origin)
{
	//ios::sync_with_stdio(false);
	this->square = origin.square;
	this->next = origin.next;

	printf("Item copied\n");
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << "{ " << std::endl << "  " << item.square << "}" << std::endl;
	
	return os;
}

Item* Item::setNext(Item* next)
{
	Item* oldNext = this->next;
	
	this->next = next;

	return oldNext;
}

Item* Item::getNext()
{
	return this->next;
}

Square Item::getSquare() const
{
	return this->square;
}

Item::~Item()
{
	delete next;

	printf("Item deleted\n");
}

