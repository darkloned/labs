#include <stdlib.h>

#include"headers/Iterator.h"

Iterator* createIterator(List* list)
{
	Iterator* it = (Iterator*) malloc(sizeof(Iterator));

	it->pointer = list->root;

	return it;
}

void iterate(Iterator* it)
{
	it->pointer = it->pointer->next;
}

bool lastNode(Iterator* it)
{
	return (it->pointer->next == NULL);
}

int getNodeValue(Iterator* it)
{
	return it->pointer->value;
}

void destroyIterator(Iterator* it)
{
	free(it);
}

