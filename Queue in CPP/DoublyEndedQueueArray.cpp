#include <iostream>

template <typename T, int MAX_SIZE>
class DequeArray {
private:
    T* arr;
    int front;
    int rear;
    int size;

public:
    DequeArray() : front(-1), rear(-1), size(0) {
        arr = new T[MAX_SIZE];
    }

    ~DequeArray() {
        delete[] arr;
    }

    void enqueueFront(T value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear + 1 == front)) {
            std::cout << "Deque is full. Cannot enqueue at front." << std::endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = MAX_SIZE - 1;
        else
            front = front - 1;

        arr[front] = value;
        size++;
    }

    void enqueueRear(T value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear + 1 == front)) {
            std::cout << "Deque is full. Cannot enqueue at rear." << std::endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1)
            rear = 0;
        else
            rear = rear + 1;

        arr[rear] = value;
        size++;
    }

    void dequeueFront() {
        if (front == -1) {
            std::cout << "Deque is empty. Cannot dequeue from front." << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1)
            front = 0;
        else
            front = front + 1;

        size--;
    }

    void dequeueRear() {
        if (front == -1) {
            std::cout << "Deque is empty. Cannot dequeue from rear." << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = MAX_SIZE - 1;
        else
            rear = rear - 1;

        size--;
    }

    T getFront() {
        if (size == 0) {
            std::cout << "Deque is empty. No front element." << std::endl;
            return T(); // Return a default value for T
        }

        return arr[front];
    }

    T getRear() {
        if (size == 0) {
            std::cout << "Deque is empty. No rear element." << std::endl;
            return T(); // Return a default value for T
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (rear + 1 == front);
    }
};

int main() {
    DequeArray<int, 5> deque;

    deque.enqueueRear(10);
    deque.enqueueFront(20);
    deque.enqueueRear(30);
    deque.enqueueFront(40);
    deque.enqueueRear(50);
    deque.enqueueFront(60); // Deque is full

    std::cout << "Front of the deque: " << deque.getFront() << std::endl;
    std::cout << "Rear of the deque: " << deque.getRear() << std::endl;

    while (!deque.isEmpty()) {
        std::cout << "Dequeuing from front: " << deque.getFront() << std::endl;
        deque.dequeueFront();
    }

    return 0;
}
