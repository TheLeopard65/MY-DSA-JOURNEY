#include <iostream>
#include <cstring>
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
// Function to check if the character is an opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}
// Function to check if the character is a closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}
// Function to check if the opening and closing brackets match
bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}
// Function to check bracket order in the expression
bool checkBracketsOrder(string expression) {
    Stack S;
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (isOpeningBracket(ch)) S.push(ch);                  // If the character is an opening bracket, push it onto the stack
        else if (isClosingBracket(ch))                         // If the character is a closing bracket, check for matching opening bracket
            if (S.isEmpty() || !isMatchingPair(S.pop(), ch))   // If stack is empty or top element doesn't match, return false
                return false;
    }
    return S.isEmpty();                                        // If stack is empty, all brackets matched properly
}
int main() {
    string expression;
    cout << "[#] ENTER AN EXPRESSION TO EVALUATE: ";
    cin >> expression;
    if (checkBracketsOrder(expression)) cout << "[!] GOOD: Brackets are balanced and properly ordered.\n";
    else cout << "[@] BAD: Brackets are not balanced or improperly ordered.\n";
    return 0;
}
