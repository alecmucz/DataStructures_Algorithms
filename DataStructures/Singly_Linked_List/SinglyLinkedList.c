
//
// Created by amucz0 on 11/26/24.
//
#include <malloc.h>
#include "SinglyLinkedList.h"

LinkedList *createLinkedList(){
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL){fprintf(stderr, "Error: Memory Allocation Failed\n");return NULL;}
    list->head = NULL;
    list->size = 0;
    return list;
}
void destroyLinkedList(LinkedList* list){
    if(list->size == 0){return;}
    Node *curr = list->head;
    while(curr != NULL){
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
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
    if (index > list->size || index < 0){fprintf(stderr, "Error: Index %d is out of bounds\n", index);return;}
    if (index == 0){insertAtFront(list, data);return;}
    Node *newNode = createNode(data);
    Node *curr = list->head->next;
    Node *prev = list->head;

    int currI = 1;
    while (curr != NULL){
        if(currI == index){
            newNode->next = curr;
            prev->next = newNode;
            list->size++;
            break;
        }
        curr = curr->next; currI++;
        prev = prev->next;
    }

}



void removeFront(LinkedList* list){
    if (list->head == NULL){fprintf(stderr, "Error: Linked List is Empty\n");return;}
    Node *temp = list->head;
    list->head = list->head->next;
    list->size--;
    free(temp);
}

void removeEnd(LinkedList* list){
    if(list->head == NULL){fprintf(stderr, "Error: Linked List is Empty\n");return;}
    if(list->size == 1){removeFront(list);return;}
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

void removeFromIndex(LinkedList* list, int index){
    if (index >= list->size || index < 0){fprintf(stderr, "Error: Index %d is out of bounds\n", index);return;}
    if (index == 0){removeFront(list);return;}
    Node *curr = list->head->next;
    Node *prev = list->head;
    int currI = 1;

    while (curr != NULL){
        if (currI == index){
            Node *temp = curr;
            prev->next = curr->next;
            list->size--;
            free(temp);
            break;
        }
        curr = curr->next;
        prev = prev->next;
        currI++;
    }
}



Node* getFront(LinkedList* list){
    if(list->head == NULL){fprintf(stderr, "Error: Linked List is Empty\n");return NULL;}
    return list->head;
}

Node* getEnd(LinkedList* list){
    if(list->head == NULL){fprintf(stderr, "Error: Linked List is Empty\n");return NULL;}
    Node* curr = list->head;
    while (curr->next != NULL){
        curr = curr->next;
    } return curr;
}

Node* getAtIndex(LinkedList* list, int index){
    if (index >= list->size || index < 0){fprintf(stderr, "Error: Index %d is out of bounds\n", index);return NULL;}
    Node* curr = list->head;
    int currI = 0;

    while (currI < index){
        curr = curr->next;
        currI++;
    } return curr;
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