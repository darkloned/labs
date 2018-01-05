#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Iterator.c"
#include "List.c"
#include "Node.c"

int main()
{
	int size, value;

	printf("Enter list size: ");
	scanf("%d", &size);
	printf("Enter list: ");

	List* list = createList();

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
