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
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(T value) {
        Node<T>* new_node = new Node<T>(value);

        if (rear == nullptr) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;

        std::cout << temp->data << " dequeued from the queue." << std::endl;
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

    void display() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node<T>* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue elements: ";
    queue.display();

    std::cout << "Front of the queue: " << queue.getFront() << std::endl;

    queue.dequeue();
    std::cout << "Queue after dequeue: ";
    queue.display();

    return 0;
}
