//
// Created by amucz0 on 11/26/24.
//

#ifndef DATASTRUCTURES_ALGORITHMS_NODE_H
#define DATASTRUCTURES_ALGORITHMS_NODE_H
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

struct Node* createNode(void* data);
void destroyNode(Node* node);
#endif //DATASTRUCTURES_ALGORITHMS_NODE_H
