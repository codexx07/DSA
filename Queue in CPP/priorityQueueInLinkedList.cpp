#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int value, int prio) : data(value), priority(prio), next(nullptr) {}
};

class PriorityQueueLinkedList {
private:
    Node* front;

public:
    PriorityQueueLinkedList() : front(nullptr) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int getFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Return a default value for an empty queue
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

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueueLinkedList pq;

    pq.enqueue(30, 3);
    pq.enqueue(20, 2);
    pq.enqueue(40, 4);
    pq.enqueue(10, 1);

    std::cout << "Priority Queue elements (linked list implementation): ";
    pq.display();

    std::cout << "Front of the queue: " << pq.getFront() << std::endl;

    pq.dequeue();
    std::cout << "Queue after dequeue: ";
    pq.display();

    return 0;
}
