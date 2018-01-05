/**
 * Created by h3ll_ow0rld.
 */

#include "Item.h"

template <class T> Item<T>::Item(const std::shared_ptr<T>& polygon)
{
	this->polygon = polygon;
	this->next = nullptr;
}

template <class T> std::shared_ptr<Item<T>> Item<T>::setNext(std::shared_ptr<Item<T>>& next)
{
	std::shared_ptr<Item<T>> oldNext = this->next;

	this->next = next;

	return oldNext;
}

template <class T> std::shared_ptr<Item<T>> Item<T>::getNext()
{
	return this->next;
}

template <class T> std::shared_ptr<T> Item<T>::getPolygon() const
{
	return this->polygon;
}

template <class A> std::ostream& operator<<(std::ostream& os, const Item<A>& item)
{
	os << *item.polygon << std::endl;

	return os;
}

template <class T> Item<T>::~Item() {}


template class Item<Polygon>;

template std::ostream& operator<<(std::ostream& os, const Item<Polygon>& item);
