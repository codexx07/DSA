#include <iostream>
#include <string>
#include <array>
#include <cctype>

template <typename T, int MAX_SIZE>
class Stack {
private:
    T top;

public:
    std::array<T, MAX_SIZE> arr;

    Stack() : top(-1) {}

    bool push(T data) {
        if (top >= MAX_SIZE - 1) {
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

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluateInfix(const std::string& expression) {
    Stack<int, 100> operands;
    Stack<char, 100> operators;

    for (char c : expression) {
        if (std::isdigit(c)) {
            operands.push(c - '0');
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) {
                int b = operands.pop();
                int a = operands.pop();
                char op = operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.push(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                int b = operands.pop();
                int a = operands.pop();
                char op = operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.pop(); // Pop '('
        }
    }

    while (!operators.isEmpty()) {
        int b = operands.pop();
        int a = operands.pop();
        char op = operators.pop();
        operands.push(applyOperation(a, b, op));
    }

    return operands.peek();
}

int evaluatePrefix(const std::string& expression) {
    Stack<int, 100> operands;

    for (int i = expression.length() - 1; i >= 0; --i) {
        char c = expression[i];

        if (std::isdigit(c)) {
            operands.push(c - '0');
        } else if (isOperator(c)) {
            int operand1 = operands.pop();
            int operand2 = operands.pop();
            int result = applyOperation(operand1, operand2, c);
            operands.push(result);
        }
    }

    return operands.peek();
}

int evaluatePostfix(const std::string& expression) {
    Stack<int, 100> operands;

    for (char c : expression) {
        if (std::isdigit(c)) {
            operands.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = operands.pop();
            int operand1 = operands.pop();
            int result = applyOperation(operand1, operand2, c);
            operands.push(result);
        }
    }

    return operands.peek();
}

int main() {
    std::string infixExpression = "3 + 5 * ( 2 - 8 )";
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    int infixResult = evaluateInfix(infixExpression);
    std::cout << "Result of Infix Evaluation: " << infixResult << std::endl;

    std::string prefixExpression = "- + 3 * 5 2 8";
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;
    int prefixResult = evaluatePrefix(prefixExpression);
    std::cout << "Result of Prefix Evaluation: " << prefixResult << std::endl;

    std::string postfixExpression = "3 5 2 * 8 - +";
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
    int postfixResult = evaluatePostfix(postfixExpression);
    std::cout << "Result of Postfix Evaluation: " << postfixResult << std::endl;

    return 0;
}
