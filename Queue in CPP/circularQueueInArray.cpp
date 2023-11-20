#include <iostream>

template <typename T, int MAX_SIZE>
class CircularQueueArray {
private:
    T* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueueArray() : front(-1), rear(-1), size(0) {
        arr = new T[MAX_SIZE];
    }

    ~CircularQueueArray() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (size == MAX_SIZE) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;

        if (front == -1)
            front = rear;

        size++;
    }

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
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

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }
};

int main() {
    CircularQueueArray<int, 5> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Queue is full

    std::cout << "Front of the queue: " << queue.getFront() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeuing: " << queue.getFront() << std::endl;
        queue.dequeue();
    }

    return 0;
}
