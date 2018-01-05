/**
 * Created by h3ll_ow0rld.
 */

#ifndef ITEM_H
#define ITEM_H

#include <memory>

#include "Polygon.h"

class Item
{
	public:
		Item(const std::shared_ptr<Polygon>& polygon);

		std::shared_ptr<Item> setNext(std::shared_ptr<Item>& next);
		std::shared_ptr<Item> getNext();
		std::shared_ptr<Polygon> getPolygon() const;

		friend std::ostream& operator<<(std::ostream& os, const Item& item);

		virtual ~Item();

	private:
		std::shared_ptr<Polygon> polygon;
		std::shared_ptr<Item> next;
};

#endif

