#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return true;
    }
    return false;
}

void prefixToInfix(string str) {
    Stack<string,100> stack;

    for (int i = str.length() - 1; i >= 0 ; i--) {
        if (isOperator(str[i])) {
            string operand1 = stack.peek(); stack.pop();
            string operand2 = stack.peek(); stack.pop();
            string temp = "(" + operand1 + str[i] + operand2 + ")";
            stack.push(temp);
        } else {
            stack.push(string(1, str[i]));
        }
    }

    cout << "Infix: " << stack.peek() << endl;
}

int main() {
    string pre_exp = "*-A/BC-/AKL";
    prefixToInfix(pre_exp);
    return 0;
}
