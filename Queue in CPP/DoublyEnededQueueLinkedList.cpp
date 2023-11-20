#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DequeLinkedList {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    DequeLinkedList() : front(nullptr), rear(nullptr) {}

    ~DequeLinkedList() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueueFront(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot dequeue from front." << std::endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;

        if (front != nullptr)
            front->prev = nullptr;

        delete temp;
    }

    void dequeueRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot dequeue from rear." << std::endl;
            return;
        }

        Node<T>* temp = rear;
        rear = rear->prev;

        if (rear != nullptr)
            rear->next = nullptr;

        delete temp;
    }

    T getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. No front element." << std::endl;
            return T(); // Return a default value for T
        }

        return front->data;
    }

    T getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. No rear element." << std::endl;
            return T(); // Return a default value for T
        }

        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    DequeLinkedList<int> deque;

    deque.enqueueRear(10);
    deque.enqueueFront(20);
    deque.enqueueRear(30);
    deque.enqueueFront(40);
    deque.enqueueRear(50);
    deque.enqueueFront(60);

    std::cout << "Front of the deque: " << deque.getFront() << std::endl;
    std::cout << "Rear of the deque: " << deque.getRear() << std::endl;

    while (!deque.isEmpty()) {
        std::cout << "Dequeuing from front: " << deque.getFront() << std::endl;
        deque.dequeueFront();
    }

    return 0;
}
