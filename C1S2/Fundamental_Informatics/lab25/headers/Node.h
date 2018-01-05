#ifndef NODE_H
#define NODE_H

#include "Structs.h"

Node* createNode(int value);

Node* getLastNode(List* list);

void addNode(List* list, int value);

#endif
