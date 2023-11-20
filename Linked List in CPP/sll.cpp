#include <iostream>
#include "singalyLinkedList.hpp"

int main() {
    SingalyLinkedList<int> llist;
    
    llist.insertAtBeginning(3);
    llist.insertAtBeginning(2);
    llist.insertAtBeginning(1);
    llist.insertAtBeginning(0);
    llist.display();
    llist.insertAtEnd(4);

    llist.display();

    llist.deleteFromBeginning();
    llist.deleteFromEnd();
    llist.deleteAtIndex(0);
    llist.deleteElement(2);
    llist.deleteElement(1);

    llist.display();
    llist.~SingalyLinkedList();
    return 0;
}