/**
 * Created by h3ll_ow0rld.
 */

#ifndef ITEM_H
#define ITEM_H

#include <memory>

#include "Polygon.h"

template<class T>
class Item
{
public:
	Item(const std::shared_ptr<T>& polygon);

	std::shared_ptr<Item<T>> setNext(std::shared_ptr<Item>& next);
	std::shared_ptr<Item<T>> getNext();
	std::shared_ptr<T> getPolygon() const;

	template <class A> friend std::ostream& operator<<(std::ostream& os, const Item<A>& item);

	virtual ~Item();
	
private:
	std::shared_ptr<T> polygon;
	std::shared_ptr<Item<T>> next;
};

#endif
