#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class InputRestrictedQueueLinkedList {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    InputRestrictedQueueLinkedList() : front(nullptr), rear(nullptr) {}

    ~InputRestrictedQueueLinkedList() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(T value) {
        Node<T>* new_node = new Node<T>(value);

        if (rear == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeueFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue from front." << std::endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void dequeueRear() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue from rear." << std::endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node<T>* temp = front;
            while (temp->next != rear)
                temp = temp->next;

            delete rear;
            rear = temp;
            rear->next = nullptr;
        }
    }

    T getFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return T(); // Return a default value for T
        }

        return front->data;
    }

    T getRear() {
        if (rear == nullptr) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return T(); // Return a default value for T
        }

        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    InputRestrictedQueueLinkedList<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front of the queue: " << queue.getFront() << std::endl;
    std::cout << "Rear of the queue: " << queue.getRear() << std::endl;

    std::cout << "Dequeuing from front: " << std::endl;
    queue.dequeueFront();
    std::cout << "Front of the queue: " << queue.getFront() << std::endl;

    std::cout << "Dequeuing from rear: " << std::endl;
    queue.dequeueRear();
    std::cout << "Rear of the queue: " << queue.getRear() << std::endl;

    return 0;
}
