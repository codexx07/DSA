#include <iostream>

template <typename T, int MAX_SIZE>
class InputRestrictedQueueArray {
private:
    T* arr;
    int front;
    int rear;
    int size;

public:
    InputRestrictedQueueArray() : front(-1), rear(-1), size(0) {
        arr = new T[MAX_SIZE];
    }

    ~InputRestrictedQueueArray() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (rear == MAX_SIZE - 1) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear++;
        arr[rear] = value;

        if (front == -1)
            front = 0;

        size++;
    }

    void dequeueFront() {
        if (size == 0) {
            std::cout << "Queue is empty. Cannot dequeue from front." << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }

        size--;
    }

    void dequeueRear() {
        if (size == 0) {
            std::cout << "Queue is empty. Cannot dequeue from rear." << std::endl;
            return;
        }

        rear--;
        if (rear < front) {
            front = -1;
            rear = -1;
        }

        size--;
    }

    T getFront() {
        if (size == 0) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return T(); // Return a default value for T
        }

        return arr[front];
    }

    T getRear() {
        if (size == 0) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return T(); // Return a default value for T
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }
};

int main() {
    InputRestrictedQueueArray<int, 5> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Queue is full

    std::cout << "Front of the queue: " << queue.getFront() << std::endl;
    std::cout << "Rear of the queue: " << queue.getRear() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeuing from front: " << queue.getFront() << std::endl;
        queue.dequeueFront();
    }

    return 0;
}
