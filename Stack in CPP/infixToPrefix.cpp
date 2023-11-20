#include <iostream>
#include <string>
#include <cctype>
#include "stack.hpp"
using namespace std;

void swapChar(string& str, char swapChar1, char swapChar2) {
    for (int unsigned i = 0; i < str.length(); i++) {
        if (str[i] == swapChar1) {
            str[i] = swapChar2;
        } else if (str[i] == swapChar2) {
            str[i] = swapChar1;
        }
    }
}

string reverseString(string str) {
    string reverseStr;
    for (int i = str.length() - 1; i >= 0; i--) {
        reverseStr += str[i];
    }
    swapChar(reverseStr, '(', ')');
    return reverseStr;
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string str) {
    str = "(" + str + ")";
    cout << str << endl;
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
            while (!stack.isEmpty() && precedence(c) < precedence(stack.peek())) {
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
    return postfix;
}

void postfixToPrefix(string str) {
    cout << reverseString(infixToPostfix(str)) << endl;
}

int main () {
    string str = ("x+y*z/w+u");
    postfixToPrefix(str);
}