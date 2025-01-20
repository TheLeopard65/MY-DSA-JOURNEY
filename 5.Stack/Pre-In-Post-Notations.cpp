#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
class Node {
	protected:
	    char data;
	    Node* next;
	public:
	    Node(char value) : data(value), next(NULL) {}
	    friend class Stack;
};
class Stack {
private:
    Node* top = NULL;
public:
    bool isEmpty() { return (top == NULL); }
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (isEmpty()) {
            cout << "[@] ERROR (STACK UNDERFLOW) : Stack is Empty !!!\n";
            return '\0';
        }
        Node* temp = top;
        top = top->next;
        char poppedValue = temp->data;
        delete temp;
        return poppedValue;
    }
    char peek() { return (isEmpty() ? '\0' : top->data); }
};
// Function to check precedence of operators
int precedence(char character) {
    if (character == '+' || character == '-') return 1;
    if (character == '*' || character == '/') return 2;
    if (character == '^') return 3;
    return 0;
}
// Function to check if a character is an operator
bool operator_check(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}
// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack S;
    for (char c : postfix) {
        if (isdigit(c))
            S.push(c - '0');
        else if (operator_check(c)) {
            int b = S.pop();
            int a = S.pop();
            switch (c) {
                case '+': S.push(a + b); break;
                case '-': S.push(a - b); break;
                case '*': S.push(a * b); break;
                case '/': S.push(a / b); break;
                case '^': S.push(pow(a, b)); break;
            }
        }
    }
    return S.pop();
}
// Function to evaluate prefix expression
int evaluatePrefix(string prefix) {
    Stack S;
    reverse(prefix.begin(), prefix.end());
    for (char c : prefix) {
        if (isdigit(c))
            S.push(c - '0');
        else if (operator_check(c)) {
            int a = S.pop();
            int b = S.pop();
            switch (c) {
                case '+': S.push(a + b); break;
                case '-': S.push(a - b); break;
                case '*': S.push(a * b); break;
                case '/': S.push(a / b); break;
                case '^': S.push(pow(a, b)); break;
            }
        }
    }
    return S.pop();
}
// Function to evaluate infix expression
int evaluateInfix(string infix) {
    Stack operands;
    Stack operators;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isdigit(c)) operands.push(c - '0');
        else if (c == '(') operators.push(c);
        else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                int b = operands.pop();
                int a = operands.pop();
                char op = operators.pop();
                switch (op) {
                    case '+': operands.push(a + b); break;
                    case '-': operands.push(a - b); break;
                    case '*': operands.push(a * b); break;
                    case '/': operands.push(a / b); break;
                    case '^': operands.push(pow(a, b)); break;
                }
            }
            operators.pop();
        }
        else if (operator_check(c)) {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) {
                int b = operands.pop();
                int a = operands.pop();
                char op = operators.pop();
                switch (op) {
                    case '+': operands.push(a + b); break;
                    case '-': operands.push(a - b); break;
                    case '*': operands.push(a * b); break;
                    case '/': operands.push(a / b); break;
                    case '^': operands.push(pow(a, b)); break;
                }
            }
            operators.push(c);
        }
    }
    while (!operators.isEmpty()) {
        int b = operands.pop();
        int a = operands.pop();
        char op = operators.pop();
        switch (op) {
            case '+': operands.push(a + b); break;
            case '-': operands.push(a - b); break;
            case '*': operands.push(a * b); break;
            case '/': operands.push(a / b); break;
            case '^': operands.push(pow(a, b)); break;
        }
    }
    return operands.pop();
}
int main() {
    string infix = "(3+2)*(4-1)";
    string prefix = "*+32-41";
    string postfix = "32+41-*";
    cout << "[#] EVALUATING INFIX EXPRESSION: " << evaluateInfix(infix) << endl;
    cout << "[#] EVALUATING POSTFIX EXPRESSION: " << evaluatePostfix(postfix) << endl;
    cout << "[#] EVALUATING PREFIX EXPRESSION: " << evaluatePrefix(prefix) << endl;
    return 0;
}
