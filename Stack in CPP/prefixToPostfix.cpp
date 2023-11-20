#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isOperator (char c) {
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

void prefixToPostfix (string prefix) {
    Stack<string, 100> stack;

    for (int i = prefix.size () - 1; i >= 0; i--) {
        if (isOperator (prefix[i])) {
            string op1 = stack.peek(); stack.pop();
            string op2 = stack.peek(); stack.pop();
            string temp = op1 + op2 + prefix[i];
            stack.push(temp);
        } else {
            stack.push(string(1, prefix[i]));
        }
    }

    cout << "Postfix: " << stack.peek() << endl;
}

int main() {
    string pre_exp = "*-A/BC-/AKL";
    prefixToPostfix(pre_exp);
    return 0;
}