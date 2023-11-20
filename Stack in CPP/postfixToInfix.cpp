#include <iostream>
#include <string>
#include "stack.hpp"
#include <cctype>
using namespace std;

void postfixToInfix(string postfix) {
    Stack<string, 100> stack;

    for (int unsigned i = 0; i < postfix.length(); i++) {
        if (isalnum(postfix[i])) {
            stack.push(string(1, postfix[i]));
        } else {
            string op1 = stack.peek(); stack.pop();
            string op2 = stack.peek(); stack.pop();
            stack.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    cout << "Infix: " << stack.peek() << endl;
}

int main() {
    string postfix = "ab*c+";
    postfixToInfix(postfix);
    return 0;
}