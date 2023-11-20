#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class CircularQueueLinkedList {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    CircularQueueLinkedList() : front(nullptr), rear(nullptr) {}

    ~CircularQueueLinkedList() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(T value) {
        Node<T>* new_node = new Node<T>(value);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
            rear->next = front; // Circular linkage
        } else {
            rear->next = new_node;
            rear = new_node;
            rear->next = front; // Circular linkage
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node<T>* temp = front;
            front = front->next;
            rear->next = front; // Circular linkage
            delete temp;
        }
    }

    T getFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return T(); // Return a default value for T
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    CircularQueueLinkedList<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front of the queue: " << queue.getFront() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeuing: " << queue.getFront() << std::endl;
        queue.dequeue();
    }

    return 0;
}
