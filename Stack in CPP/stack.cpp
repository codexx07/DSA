#include <iostream>
#include <array>

template <typename T, int MAX_SIZE> class Stack {
    private:
        T top;

    public:
        std::array<T, MAX_SIZE> arr;

        Stack() : top(-1) {}
        
        bool push(T data) {
            if (top > MAX_SIZE) {
                std::cout << "Stack overflow" << std::endl;
                return false;
            } else {
                arr[++top] = data;
                std::cout << data << " pushed into stack" << std::endl;
                return true;
            }
        }

        T pop() {
            if (top < 0) {
                std::cout << "Stack Underflow" << std::endl;
                return 0;
            } else {
                T data_popped = arr[top--];
                return data_popped;
            }
        }

        T peek() {
            if (top < 0) {
                std::cout << "Stack is Empty" << std::endl;
                return 0;
            } else {
                T top_val = arr[top];
                return top_val;
            }
        }

        bool isEmpty() {
            return (top < 0);
        }
};

int main() {
    return 0;
}