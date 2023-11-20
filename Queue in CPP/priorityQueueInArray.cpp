#include <iostream>
#include <vector>

class PriorityQueueArray {
private:
    std::vector<int> arr;

public:
    void enqueue(int value) {
        arr.push_back(value);
        int currentIndex = arr.size() - 1;

        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (arr[currentIndex] > arr[parentIndex]) {
                std::swap(arr[currentIndex], arr[parentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    void dequeue() {
        if (arr.empty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        std::swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapify(0);
    }

    int getFront() {
        if (arr.empty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1;  // Return a default value for an empty queue
        }
        return arr[0];
    }

    bool isEmpty() {
        return arr.empty();
    }

    void display() {
        if (arr.empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        for (const int& value : arr) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    void heapify(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < arr.size() && arr[leftChild] > arr[largest])
            largest = leftChild;

        if (rightChild < arr.size() && arr[rightChild] > arr[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
};

int main() {
    PriorityQueueArray pq;

    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(40);
    pq.enqueue(10);

    std::cout << "Priority Queue elements (array implementation): ";
    pq.display();

    std::cout << "Front of the queue: " << pq.getFront() << std::endl;

    pq.dequeue();
    std::cout << "Queue after dequeue: ";
    pq.display();

    return 0;
}
