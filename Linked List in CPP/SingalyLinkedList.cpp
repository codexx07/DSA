#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data, Node* next = nullptr) : data(data), next(next) {}

    ~Node() {
        delete next;
    }
};

template <typename T>
class SingalyLinkedList {
private:
    Node<T>* head;

public:
    SingalyLinkedList() : head(nullptr) {}

    // Inserting elements into the LinkedList
    void insertAtBeginning(T new_data) {
        Node<T>* new_node = new Node<T>(new_data, head);
        head = new_node;
    }

    void insertAfter(Node<T>* prev_node, T new_data) {
        if (prev_node == nullptr) {
            std::cout << "The given previous node is NULL." << std::endl;
            return;
        }

        Node<T>* new_node = new Node<T>(new_data, prev_node->next);
        prev_node->next = new_node;
    }

    void insertAtEnd(T new_data) {
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

    // Deleating elements from the LinkedList
    void deleteFromBeginning() {
       if (head == nullptr) {
            std::cout << "The linked list is empty" << std::endl;
            return;
        }

        Node<T>* temp = head->next;
        head = temp;
    }

    void deleteFromEnd() {
        Node<T>* end = head;
        Node<T>* prev = nullptr;
        while (end->next != nullptr) {
            prev = end;
            end = end->next;
        }

        prev->next = nullptr;
        delete end;
    }

    void deleteAtIndex(int index) {
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
        }
        else {
            std::cout << "Index out of range" << std::endl;
        }
    }

    void deleteElement(T element) {
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

    // Displaying the elements from the LinkedList
    void display() {
        Node<T>* node = head;
        while (node != nullptr) {
            std::cout << "[" << node->data << "] "
                    << "[" << node << "]->" << node->next << std::endl; 
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
    return 0;
}
