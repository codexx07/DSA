// stack.hpp
#ifndef _STACK_HPP
#define _STACK_HPP

#include <array>
#include <iostream>


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
        std::cout << data << " pushed into stack" << std::endl;
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
        std::cout << data_popped << " poped out of stack" << std::endl;
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

#endif