// nice lab26 with Makefile and headers inside lab25

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int value;
	struct Node* next;

} Node;

typedef struct List
{
	int size;
	Node* root;

} List;

typedef struct Iterator
{
	Node* pointer;

} Iterator;

Node* createNode(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));

	node->value = value;
	node->next = NULL;

	return node;
}

List* createList(int size)
{
	List* list = (List*) malloc(sizeof(List));

	list->size = size;
	list->root = NULL;

	return list;
}

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

void destroyIterator(Iterator* it)
{
	free(it);
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

int getNodeValue(Iterator* it)
{
	return it->pointer->value;
}

void setNodeValue(Iterator* it, int value)
{
	it->pointer->value = value;
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
	
			iterate(it2);

			sorted = true;

			while (!lastNode(it1))
			{
				if (getNodeValue(it1) > getNodeValue(it2))
				{
					int tmp = getNodeValue(it1);
					setNodeValue(it1, getNodeValue(it2));
					setNodeValue(it2, tmp);

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


int main()
{
	int size, value;

	printf("Enter list size: ");
	scanf("%d", &size);
	printf("Enter list: ");

	List* list = createList(0);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &value);
		addNode(list, value);
	}

	bubbleSortList(list);

	printf("Bubble-sorted list: ");
	printList(list);
	
	return 0;	
}
