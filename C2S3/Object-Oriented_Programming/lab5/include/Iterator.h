/**
 * Created by h3ll_ow0rld.
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

template <class Node, class T>
class Iterator
{
public:
	Iterator(std::shared_ptr<Node> n_ptr)
	{
		node_ptr = n_ptr;
	}

	std::shared_ptr<T> operator * ()
	{
		return node_ptr->getValue();
	}

	std::shared_ptr<T> operator -> ()
	{
		return node_ptr->getValue();
	}

	void operator ++ ()
	{
		node_ptr = node_ptr->getNext();
	}

	Iterator operator ++ (int)
	{
		Iterator it(*this);

		++(*this);

		return it;
	}

	bool operator == (Iterator const& it)
	{
		return node_ptr == it.node_ptr;
	}

	bool operator != (Iterator const& it)
	{
		return !(*this == it);
	}
	
private:
	std::shared_ptr<Node> node_ptr;
};

#endif
