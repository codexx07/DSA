#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* tail;  // Points to the last node
    int count;      // Count of nodes in the circular linked list

public:
    CircularLinkedList() : tail(nullptr), count(0) {}

    ~CircularLinkedList() {
        if (tail == nullptr)
            return;

        Node<T>* current = tail->next;  // Start from the first node
        while (current != tail) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }

        delete tail;  // Delete the tail node
    }

    void append(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (tail == nullptr) {
            // The list is empty, create a new node and make it the tail
            tail = newNode;
            tail->next = tail;  // Circular linkage
        } else {
            newNode->next = tail->next;  // Make the new node point to the first node
            tail->next = newNode;  // Make the tail point to the new node
            tail = newNode;  // Update the tail to the new node
        }

        count++;
    }


    void display() {
        if (tail == nullptr) {
            std::cout << "Circular linked list is empty." << std::endl;
            return;
        }

        Node<T>* current = tail->next;  // Start from the first node

        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);

        std::cout << std::endl;
    }

    int length() const {
        return count;
    }
};

int main() {
    CircularLinkedList<int> circularList;
    circularList.append(10);
    circularList.append(20);
    circularList.append(30);
    circularList.display();

    std::cout << "Length of the circular linked list: " << circularList.length() << std::endl;

    return 0;
}
