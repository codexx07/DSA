#include <iostream>
#include <string>
#include <cctype>
#include "stack.hpp"
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

void infixToPostfix(string str) {
    Stack<char, 100> stack;
    string postfix;

    for (int unsigned i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (stack.peek() != '(') {
                postfix += stack.peek();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                postfix += stack.peek();
                stack.pop();
            }
            stack.push(c);
        }
    }
    
    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }
    
    cout << postfix << endl;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    // exp = "(C*B)+A";
  
    // Function call
    infixToPostfix(exp);
    
    return 0;
}