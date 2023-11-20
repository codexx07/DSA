#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {}

    ~Node() {
        // Since this is a doubly linked list, we need to delete the previous node's reference as well
        if (prev != nullptr) {
            delete prev;
        }
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(T new_data) {
        Node<T>* new_node = new Node<T>(new_data, head, nullptr);
        if (head != nullptr) {
            head->prev = new_node;
        }   
        head = new_node;
    }

    void insertAfter(Node<T>* prev_node, T new_data) {
        if (prev_node == nullptr) {
            std::cout << "The given previous node is NULL." << std::endl;
            return;
        }

        Node<T>* new_node = new Node<T>(new_data, prev_node->next, prev_node);
        prev_node->next = new_node;

        if (new_node->next != nullptr) {
            new_node->next->prev = new_node;
        }
    }

    void insertAtEnd(T new_data) {
        Node<T>* new_node = new Node<T>(new_data, nullptr, nullptr);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node<T>* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = new_node;
        new_node->prev = last;
    }

    // Deletion functions

    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "The linked list is empty" << std::endl;
            return;
        }

        Node<T>* temp = head->next;
        if (temp != nullptr) {
            temp->prev = nullptr;
        }

        head = temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "The linked list is empty" << std::endl;
            return;
        }

        Node<T>* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        if (last->prev != nullptr) {
            last->prev->next = nullptr;
        } else {
            head = nullptr; // If this was the only element in the list
        }

        delete last;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) {
            std::cout << "The linked list is empty" << std::endl;
            return;
        }

        Node<T>* temp = head;
        for (int i = 0; temp != nullptr && i < index; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Index out of range" << std::endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Update head if deleting the first node
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void deleteElement(T element) {
        if (head == nullptr) {
            std::cout << "The linked list is empty" << std::endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Element not found" << std::endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Update head if deleting the first node
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Displaying the elements from the LinkedList
    void display() {
        Node<T>* node = head;
        while (node != nullptr) {
            std::cout << "[" << node->data << "] "
                      << "[" << node << "]->"
                      << "prev:[" << node->prev << "], next:[" << node->next << "]" << std::endl;
            node = node->next;
        }

        std::cout << std::endl << std::endl;
    }

    // Length of the LinkedList
    int length() {
        Node<T>* node = head;
        int count = 0;
        while (node != nullptr) {
            count++;
            node = node->next;
        }

        return count;
    }
};

int main() {
    DoublyLinkedList<int> dll;

    dll.insertAtBeginning(0);
    dll.insertAtBeginning(1);
    dll.insertAtBeginning(2);
    dll.insertAtBeginning(3);
    dll.insertAtEnd(4);
    dll.display();
    
    dll.deleteAtIndex(0);
    dll.display();
}
