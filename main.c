#include "DataStructures/Singly_Linked_List/SinglyLinkedList.h"
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
    printf("list size : %d",getSize(list));
    destroyLinkedList(list);
    return 0;
}
