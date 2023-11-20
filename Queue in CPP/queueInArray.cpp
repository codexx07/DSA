#include <iostream>
#include <vector>

template <typename T> class Queue {
private:
    int front, rear, size;
    std::vector<T> arr;

public:
    Queue() {
        this->front = 0;
        this->rear = -1;
        this->size = 0;
    }

    void enqueue(T value) {
        this->arr.push_back(value);
        this->rear++;
        this->size++;
        std::cout << value << " enqueued to the queue. New size: " << this->size << std::endl;
    }

    void dequeue() {
        if (this->size == 0) {
            std::cout << "Queue Empty!" << std::endl;
            return;
        }
        std::cout << this->arr[this->front] << " dequeued from the queue. New size: " << --this->size << std::endl;
        this->front++;
    }

    T getFront() {
        if (this->size == 0) {
            std::cout << "Queue Empty!" << std::endl;
            return T(); // Return a default value for T
        }
        return this->arr[this->front];
    }

    T getRear() {
        if (this->size == 0) {
            std::cout << "Queue Empty!" << std::endl;
            return T(); // Return a default value for T
        }
        return this->arr[this->rear];
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    void display() {
        for (int i = this->front; i <= this->rear; ++i) {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.display();
    queue.enqueue(3);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(4);
    queue.display();

    return 0;
}
