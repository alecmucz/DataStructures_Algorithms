//
// Created by amucz0 on 11/26/24.
//

#ifndef DATASTRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
#define DATASTRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
#include "../Node/Node.h"
#include <errno.h>

typedef struct LinkedList {
    struct Node *head;
    unsigned int size;
} LinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList* list);

void insertAtFront(LinkedList* list, void* data);
void insertAtEnd(LinkedList* list, void* data);
void insertAtIndex(LinkedList* list, void* data, int index);

void removeFront(LinkedList* list);
void removeEnd(LinkedList* list);
void removeAtIndex(LinkedList* list, int index);

Node* getFront(LinkedList* list);
Node* getEnd(LinkedList* list);
Node* getAtIndex(LinkedList* list, int index);

void printList(LinkedList* list);
unsigned int getSize(LinkedList* list);

#endif //DATASTRUCTURES_ALGORITHMS_SINGLYLINKEDLIST_H
