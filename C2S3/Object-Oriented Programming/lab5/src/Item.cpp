/**
 * Created by h3ll_ow0rld.
 */

#include "Item.h"

template <class T> Item<T>::Item(const std::shared_ptr<T>& value)
{
	this->value = value;
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

template <class T> std::shared_ptr<T> Item<T>::getValue() const
{
	return this->value;
}

template <class T> void * Item<T>::operator new(size_t size)
{
	std::cout << "Allocated: " << size << " bytes" << std::endl;

	return malloc(size);
}

template <class T> void Item<T>::operator delete(void* p)
{
	free(p);
	
	std::cout << "Deleted" << std::endl;
}

template <class A> std::ostream& operator<<(std::ostream& os, const Item<A>& item)
{
	os << *item.value << std::endl;

	return os;
}

template <class T> Item<T>::~Item() {}


template class Item<Polygon>;

template std::ostream& operator<<(std::ostream& os, const Item<Polygon>& item);
