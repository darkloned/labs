#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>

#include "Structs.h"

Iterator* createIterator(List* list);

void iterate(Iterator* it);

bool lastNode(Iterator* it);

int getNodeValue(Iterator* it);

void destroyIterator(Iterator* it); 

#endif

