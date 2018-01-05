/**
 * Created by h3ll_ow0rld.
 */

#include "Item.h"

Item::Item(const std::shared_ptr<Polygon>& polygon)
{
	this->polygon = polygon;
	this->next = nullptr;
}

std::shared_ptr<Item> Item::setNext(std::shared_ptr<Item>& next)
{
	std::shared_ptr<Item> oldNext = this->next;
	
	this->next = next;

	return oldNext;
}

std::shared_ptr<Item> Item::getNext()
{
	return this->next;
}

std::shared_ptr<Polygon> Item::getPolygon() const
{
	return this->polygon;
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os  << *item.polygon << std::endl;
	
	return os;
}

Item::~Item() {}
