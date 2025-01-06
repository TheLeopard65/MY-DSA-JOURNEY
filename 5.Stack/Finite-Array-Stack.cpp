#include <iostream>
using namespace std;
void push(int Stack[], int &top, int value) {
    ++top;
    Stack[top] = value;
}
void pop(int Stack[], int &top) {
    if (top != -1) {
        Stack[top] = 0;
        --top;
    }
}
int peak(int Stack[], int &top) {
    return (top == -1) ? 0 : Stack[top];
}
bool isEmpty(int Stack[], int &top) {
    return (top == -1) ? true : false;
}
bool isFull(int Stack[], int &top) {
    return (top == 9) ? true : false;
}
int size(int Stack[], int &top) {
    return top + 1;
}
void traversing(int Stack[], int &top) {
    cout << "[#] TRAVERSING ARRAY BASED STACK: ";
    for (int i = top ; i >= 0; i--)
        cout << Stack[i] << " - ";
    cout << "(END)" << endl;
}
void reversing(int Stack[], int &top) {
    if (top == -1) {
        cout << "[!] STACK-UNDERFLOW: Stack is empty!" << endl;
        return;
    }
    cout << "[#] REVERSING ARRAY BASED STACK: ";
    for (int i = 0; i <= top; i++)
        cout << Stack[i] << " - ";
    cout << "(END)" << endl;
}
int search(int Stack[], int &top, int target) {
    for (int i = 0; i <= top; i++)
        if (Stack[i] == target)
            return i;
    return -1;
}
int main() {
    int Stack[10], top = -1;
    push(Stack, top, 40);
    push(Stack, top, 30);
    push(Stack, top, 30);
    push(Stack, top, 10);
    cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << peak(Stack, top) << endl;
    traversing(Stack, top);
    reversing(Stack, top);
    cout << "[#] IS THE STACK EMPTY? : " << (isEmpty(Stack, top) ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << size(Stack, top) << endl;
    cout << "[#] FOUND THE ELEMENT 20 AT INDEX : " << search(Stack, top, 20) << endl;
    pop(Stack, top);
    pop(Stack, top);
    cout << "[#] IS THE STACK FULL? : " << (isFull(Stack, top) ? "YES" : "NO") << endl;
    traversing(Stack, top);
    reversing(Stack, top);
    cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << peak(Stack, top) << endl;
    cout << "[#] IS THE STACK EMPTY? : " << (isEmpty(Stack, top) ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << size(Stack, top) << endl;
    pop(Stack, top);
    pop(Stack, top);
    return 0;
}
