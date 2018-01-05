#include <stdio.h>
#include <stdlib.h>

#include "headers/Iterator.h"
#include "headers/List.h"

List* createList()
{
	List* list = (List*) malloc(sizeof(List));

	list->size = 0;
	list->root = NULL;

	return list;
}

void printList(List* list)
{
	if (list->size == 0)
	{
		printf("Empty list");
	}
	else
	{
		Iterator* it = createIterator(list);

		while (!lastNode(it))
		{
			printf("%d ", getNodeValue(it));
		
			iterate(it);
		}

		printf("%d ", getNodeValue(it));

		destroyIterator(it);
	}

	printf("\n");
}

void bubbleSortList(List* list)
{
	if (list->size > 1)
	{
		bool sorted = false;

		while (!sorted)
		{
			Iterator* it1 = createIterator(list);
			Iterator* it2 = createIterator(list);
	
			it2->pointer = it2->pointer->next;

			sorted = true;

			while (!lastNode(it1))
			{
				if (getNodeValue(it1) > getNodeValue(it2))
				{
					int tmp = it1->pointer->value;
					it1->pointer->value = it2->pointer->value;
					it2->pointer->value = tmp;

					sorted = false;
				}

				iterate(it1);
				iterate(it2);
			}

			destroyIterator(it1);
			destroyIterator(it2);
		}
	}
}
