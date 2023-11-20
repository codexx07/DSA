// singalyLinkedList.hpp
#ifndef _SINGALY_LINKED_LIST_HPP
#define _SINGALY_LINKED_LIST_HPP

#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T data, Node* next = nullptr);
        ~Node();
};

template <typename T>
class SingalyLinkedList {
    private:
        Node<T>* head;

    public:
        SingalyLinkedList();
        ~SingalyLinkedList();

        // Inserting elements into the LinkedList
        void insertAtBeginning(T new_data);
        void insertAfter(Node<T>* prev_node, T new_data);
        void insertAtEnd(T new_data);

        // Deleating elements from the LinkedList
        void deleteFromBeginning();
        void deleteFromEnd();
        void deleteAtIndex(int index);
        void deleteElement(T element);

        // Displaying the elements from the LinkedList
        void display();

        // Length of the LinkedList
        int length();
};

// Node constructor
template <typename T>
Node<T>::Node(T data, Node* next) : data(data), next(next) {}

// Node destructor
template <typename T>
Node<T>::~Node() {
    delete next;
}

// SingalyLinkedList constructor
template <typename T>
SingalyLinkedList<T>::SingalyLinkedList() : head(nullptr) {}

// SingalyLinkedList destructor
template <typename T>
SingalyLinkedList<T>::~SingalyLinkedList() {
    delete head;
}

// Inserting at beginning function
template <typename T>
void SingalyLinkedList<T>::insertAtBeginning(T new_data) {
    Node<T>* new_node = new Node<T>(new_data, head);
    head = new_node;
}

// Inserting after function
template <typename T>
void SingalyLinkedList<T>::insertAfter(Node<T>* prev_node, T new_data) {
    if (prev_node == nullptr) {
        std::cout << "The given previous node is NULL." << std::endl;
        return;
    }

    Node<T>* new_node = new Node<T>(new_data, prev_node->next);
    prev_node->next = new_node;
}

// Inserting at end function
template <typename T>
void SingalyLinkedList<T>::insertAtEnd(T new_data) {
    Node<T>* new_node = new Node<T>(new_data);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node<T>* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Deleting from beginning function
template <typename T>
void SingalyLinkedList<T>::deleteFromBeginning() {
    if (head == nullptr) {
        std::cout << "The linked list is empty" << std::endl;
        return;
    }

    Node<T>* temp = head->next;
    head = temp;
}

// Deleting from end function
template <typename T>
void SingalyLinkedList<T>::deleteFromEnd() {
    Node<T>* end = head;
    Node<T>* prev = nullptr;
    while (end->next != nullptr) {
        prev = end;
        end = end->next;
    }

    prev->next = nullptr;
    delete end;
}

// Deleting at index function
template <typename T>
void SingalyLinkedList<T>::deleteAtIndex(int index) {
    if (head == nullptr) {
        std::cout << "The linked list is empty" << std::endl;
        return;
    }

    if (index == 0) {
        Node<T>* temp = head->next;
        head = temp;
        return;
    }

    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    while (temp != nullptr && index > 0) {
        prev = temp;
        temp = temp->next;
        index--;
    }

    if (index == 0 && temp != nullptr) {
        prev->next = temp->next;
        std::cout << "Deleting " << temp->data << std::endl;
    } else {
        std::cout << "Index out of range" << std::endl;
    }
}

// Deleting element function
template <typename T>
void SingalyLinkedList<T>::deleteElement(T element) {
    if (head == nullptr) {
        std::cout << "The linked list is empty" << std::endl;
        return;
    }

    if (head->data == element) {
        Node<T>* temp = head->next;
        head = temp;
        return;
    }

    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    while(temp != nullptr && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp!= nullptr) {
        prev->next = temp->next;
        delete temp;
    } else {
        std::cout << "Element not found" << std::endl;
    }
}

// Displaying function
template <typename T>
void SingalyLinkedList<T>::display() {
    Node<T>* node = head;
    while (node != nullptr) {
        std::cout << "[" << node->data << "] "
                        << "[" << node << "]->" << node->next << std::endl; 
        node = node->next;
    }

    std::cout << std::endl << std::endl;
}

// Length of the LinkedList
template <typename T>
int SingalyLinkedList<T>::length() {
    Node<T>* node = head;
    int count = 0;
    while (node != nullptr) {
        count++;
        node = node->next;
    }

    return count;
}

#endif