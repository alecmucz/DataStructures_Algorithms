//
// Created by amucz0 on 11/26/24.
//

#include "Node.h"
Node* createNode(void* data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void destroyNode(Node* node){
    free(node);
}