#include <iostream>
#include <array>
using namespace std;

template <typename T, int MAX_SIZE> class Stack {
    private:
        int top;
        std::array<T, MAX_SIZE> arr;
    public:
        Stack();
        bool push(T data);
        T pop();
        T peek();
        bool isEmpty();
};

// define the methods of the template class in the same header file
template <typename T, int MAX_SIZE>
Stack<T, MAX_SIZE>::Stack() : top(-1) {}

template <typename T, int MAX_SIZE>
bool Stack<T, MAX_SIZE>::push(T data) {
    if (top > MAX_SIZE) {
        std::cout << "Stack overflow" << std::endl;
        return false;
    } else {
        arr[++top] = data;
        return true;
    }
}

template <typename T, int MAX_SIZE>
T Stack<T, MAX_SIZE>::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow" << std::endl;
        return 0;
    } else {
        T data_popped = arr[top--];
        // std::cout << data_popped << " poped out of stack" << std::endl;
        return data_popped;
    }
}

template <typename T, int MAX_SIZE>
T Stack<T, MAX_SIZE>::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty" << std::endl;
        return 0;
    } else {
        T top_val = arr[top];
        return top_val;
    }
}

template <typename T, int MAX_SIZE>
bool Stack<T, MAX_SIZE>::isEmpty() {
    return (top < 0);
}

// Reverse a stack
template <typename T, int MAX_SIZE>
void insertAtBottom(Stack<T, MAX_SIZE>& stack, int element) {
    if(stack.isEmpty()) {
        stack.push(element);
        return;
    }

    int topElement = stack.peek();
    stack.pop();
    insertAtBottom(stack, element);
    stack.push(topElement);
}

template <typename T, int MAX_SIZE> 
void reverse(Stack<T, MAX_SIZE>& stack) {
    if (stack.isEmpty()) return;

    int elements = stack.peek();
    stack.pop();
    reverse(stack);
    insertAtBottom(stack, elements);
}

void Question1() {
    Stack<int, 100> stack;
    stack.push(2); stack.push(1); stack.push(0); stack.push(0);

    int size = 4;
    for (int i = 0; i < size; i++) {
        if (stack.peek() == 0) stack.pop();
        else cout << stack.pop() << " ";
    }
    cout << endl;
}

// Question 2
void Question2() {
    const int n = 5;
    Stack<int, n> stack;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        stack.push(val);
    }

    int stamina = 0, prev = 0;
    reverse(stack);
    for (int i = 0; i < n; i++) {
        if (stack.peek() < prev) {
            break;
        } else {
            stamina ^= stack.peek();
            prev = stack.pop();
        }
    }
    cout << "Stamina: " << stamina << endl;
}

// Question3
#include <vector>
void rorateArrayClockwise(vector<int> &arr) {
    int lastElement = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

void Question3() {
    int size;
    cin >> size;

    vector<int> arrA, arrB;

    cout << "Array A" << endl;
    for (int i = 0; i < size; i++) {
        int val;
        cin >> val;
        arrA.push_back(val);
    }

    cout << "Array B" << endl;
    for (int i = 0; i < size; i++) {
        int val;
        cin >> val;
        arrB.push_back(val);
    }

    int seconds = 0;
    while(arrA.size() != 0 && arrB.size() != 0) {
        if (arrA[0] == arrB[0]) {
            arrA.erase(arrA.begin());
            arrB.erase(arrB.begin());
            seconds ++;
        } else {
            rorateArrayClockwise(arrA);
            seconds ++;
        }
    }
    cout << "Totol Seconds: " << seconds << endl;
}

int main() {
    Question1();
    // Question2();
    // Question3();
}