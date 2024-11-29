
//
// Created by amucz0 on 11/26/24.
//
#include <malloc.h>
#include "SinglyLinkedList.h"
LinkedList *createLinkedList(){
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL){perror("Failure: Linked List Allocation");abort();}
    list->head = NULL;
    list->size = 0;
    return list;
}
void destroyLinkedList(LinkedList* list){
    free(list);
}

void insertAtFront(LinkedList* list, void* data){
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head=newNode;
    list->size++;
}

void insertAtEnd(LinkedList* list, void* data){
    Node *newNode = createNode(data);
    Node *curr = list->head;
    if (curr == NULL){insertAtFront(list, data);return;}
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    list->size++;
        curr = curr->next;
}


void insertAtIndex(LinkedList* list, void* data, int index){
    if (index > list->size){perror("Failure: Index is Out of Bounds");abort();}
    if (index == 0){ insertAtFront(list, data);}
    Node *newNode = createNode(data);
    Node *curr = list->head->next;
    Node *prev = list->head;
    int currI = 1;
    while (curr != NULL){
        if(currI == index){
            newNode->next = curr;
            prev->next = newNode;
        }
        curr = curr->next; currI++;
        prev = prev->next;
    }
    list->size++;
}


void printList(LinkedList* list){
    Node *curr = list->head;
    while (curr != NULL){
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

unsigned int getSize(LinkedList* list){
    return list->size;
}