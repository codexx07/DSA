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

void postfixToPrefix (string postfix) {
    Stack<string, 100> stack;

    for (int unsigned i = 0; i < postfix.length(); i++) {
        if (isOperator (postfix[i])) {
            string op1 = stack.peek(); stack.pop();
            string op2 = stack.peek(); stack.pop();
            string temp = postfix[i] + op2 + op1 ;
            stack.push(temp);
        } else {
            stack.push(string(1, postfix[i]));
        }
    }

    cout << "Prefix: " << stack.peek() << endl;
}

int main() {
    string post_exp = "ABC/-AK/L-*";
    postfixToPrefix(post_exp);
    return 0;
}