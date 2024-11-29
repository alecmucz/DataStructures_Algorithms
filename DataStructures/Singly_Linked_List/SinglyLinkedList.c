
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



void removeFront(LinkedList* list){
    list->head = list->head->next;
    list->size--;
}

void removeEnd(LinkedList* list){
    Node *curr = list->head->next;
    Node *prev = list->head;
    while(curr->next != NULL){
        curr = curr->next;
        prev = prev->next;
    }
    free(curr);
    prev->next = NULL;
    list->size--;
}

void removeAtIndex(LinkedList* list, int index){
    Node *curr = list->head->next;
    Node *prev = list->head;
    int currI = 1;

    while (curr != NULL){
        if (currI == index){
            prev->next = curr->next;
        }
        curr = curr->next;
        prev = prev->next;
        currI++;
    }
    list->size--;
}



Node* getFront(LinkedList* list){
    return list->head;
}

Node* getEnd(LinkedList* list){
    Node* curr = list->head;
    while (curr->next != NULL){
        curr = curr->next;
    } return curr;
}

Node* getAtIndex(LinkedList* list, int index){
    Node* curr = list->head;
    int currI = 0;

    while (curr != NULL){
        if (currI == index){
            return curr;
        }
        curr = curr->next;
        currI++;
    } return NULL;
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