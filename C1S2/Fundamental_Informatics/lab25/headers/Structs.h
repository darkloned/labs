#ifndef STRUCTS_H
#define STRUCTS_H

// HOTFIX for structs' use in multiple files

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

#endif
