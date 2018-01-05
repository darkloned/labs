// Description of interactive functions are located in main()

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int value;
	struct Node* next;

} Node;

Node* createNode(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));

	node->value = value;
	node->next = NULL;

	return node;
}

bool addNode(Node** root, int* size, int pos, int value)
{
	//   vvvvvvvv - avoid colliding with root addition  
	if ((pos != 1 && pos > *size) || pos < 1)
		return false;
	else
	{
		if (*size == 0) // empty list
			(*root)->value = value;
		else
		{
			Node* node = createNode(value);

			if (pos == 1) // new root
			{
				node->next = *root;
				*root = node;
			}
			else
			{
				Node* prevNode = *root;

				for (int i = 2; i < pos; i++)
					prevNode = prevNode->next;

				node->next = prevNode->next;
				prevNode->next = node;
			}
		}

		(*size)++;

		return true;
	}
}

bool deleteNode(Node** root, int* size, int value)
{
	if ((*root)->value == value)
	{	
		if (*size > 1)
			*root = (*root)->next;
		
		// if *size == 1, no need to change *root, only decrement *size
	}
	else
	{
		Node* prevNode = *root;

		while (prevNode->next->value != value)
		{
			if (prevNode->next == NULL)
				return false;
			else
				prevNode = prevNode->next;
		}
		
		prevNode->next = prevNode->next->next;
	}

	(*size)--;

	return true;
}

void rshList(Node** root, int* size)
{
	Node* prevNode = *root;

	while (prevNode->next->next != NULL) // find 'parent' of last node
	{
		prevNode = prevNode->next;
	}

	int lastNodeValue = prevNode->next->value;

	prevNode->next = NULL;
	(*size)--;

	addNode(root, size, 1, lastNodeValue);
}
		

void printList(Node* root)
{
	Node* node = root;

	do
	{
		printf("%d ", node->value);

		node = node->next; 
	}
	while (node != NULL);

	printf("\n");
}


int main()
{
	int size = 0;
	Node* root = createNode(0);

	char cmd;
	bool quit = false;

	while (!quit)
	{
		scanf("%c", &cmd);
		getchar();

		switch(cmd)
		{
			int pos, value;

			case 'i': // i 1 5 - insert 5 before 1st element 
					  // (or creates root if list is empty)

				scanf("%d %d", &pos, &value);
				getchar();

				bool added = addNode(&root, &size, pos, value);

				printf(added ? "OK\n" : "Error\n");

				break;

			case 'l': // l - print size of list

				printf("%d\n", size);

				break;

			case 'p': // p - print list in order of LinkedList's dependency

				if (size == 0)
					printf("Empty list\n");
				else
					printList(root);

				break;

			case 'd': // d 5 - delete first node with value 5

				scanf("%d", &value);
				getchar();

				if (size == 0)
					printf("Empty list\n");
				else
				{
					bool deleted = deleteNode(&root, &size, value);

					printf(deleted ? "OK\n" : "Value not found\n");
				}

				break;

			case 't': // t - cyclic shift on one step right
		 		if (size == 0)
					printf("Empty list\n");
				else
				{
					if (size > 1)
						rshList(&root, &size);

					printf("OK\n");
				}

				break;		

			case 'q': // quit

				printf("Bye\n");
				
				quit = true;

				break;

			default: ;
				
				char garbage[1024];

				fgets(garbage, sizeof garbage, stdin);
				printf("Unknown request\n");

				break;
		}
	}

	return 0;
}
