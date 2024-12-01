#include "SinglyLinkedList.h"
#include <stdio.h>

int main(void) {
    LinkedList *list = createLinkedList();

    insertAtFront(list,(void *) 100);
    insertAtEnd(list,(void *) 300);
    insertAtEnd(list,(void *) 400);
    insertAtEnd(list,(void *) 800);
    insertAtEnd(list,(void *) 900);
    insertAtIndex(list, (void *) 8, 1);
    printList(list);

    Node* frontNode = getFront(list);
    printf("Front Node : %d\n", (int) frontNode->data);
    removeFront(list);
    printList(list);

    Node* endNode = getEnd(list);
    printf("End Node : %d\n", (int) endNode->data);

    removeEnd(list);
    printList(list);

    removeFromIndex(list,0);
    printList(list);

    Node* indexNode = getAtIndex(list, 2);
    printf("Index %d : %d\n", 2, (int) indexNode->data);


    printf("list size : %d\n",getSize(list));
    destroyLinkedList(list);
    return 0;
}
