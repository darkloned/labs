#include <stdlib.h>

#include "headers/Node.h"
#include "headers/Iterator.h"


Node* createNode(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));

	node->value = value;
	node->next = NULL;

	return node;
}

Node* getLastNode(List* list)
{
	Iterator* it = createIterator(list);

	while (!lastNode(it))
	{
		iterate(it);
	}

	return it->pointer;
}

void addNode(List* list, int value)
{
	if (list->size == 0)
	{
		list->root = createNode(value);
	}
	else
	{
		Node* lastNode = getLastNode(list);

		lastNode->next = createNode(value);
	}

	list->size++;
}
