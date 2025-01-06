#include <iostream>
using namespace std;
class Node {
	protected:
	    int data;
	    Node* next = NULL;
	public:
	    Node(int value) : data(value), next(NULL) {}
	    friend class Infinite_Node_Stack;
};
class Infinite_Node_Stack {
	private:
	    Node* top = NULL;
	public:
	    void push(int value) {
	        Node* newNode = new Node(value);
	        if (!top) top = newNode;
	        else {
		        newNode->next = top;
	    	    top = newNode;
			}
	    }
	    void pop() {
	    	if (!top) return;
	    	else {
	            Node* temp = top;
	            top = top->next;
	            delete temp;
			}
	    }
	    int peak() {
	    	return ((top)? top->data : -1);
	    }
	    bool isEmpty() {
	        return (!top);
	    }
	    int size() {
	    	if (!top) return 0;
	        int count = 0;
	        Node* current = top;
	        while (current) {
	            current = current->next;
	            count++;
	        }
	        return count;
	    }
	    void print() {
	        if (!top) return;
	        cout << "[#] TRAVERSING NODE BASED STACK: ";
	        Node* current = top;
	        while (current) {
	            cout << current->data << " - ";
	            current = current->next;
	        }
	        cout << "(END)" << endl;
	    }
	    int search(int target) {
	        int index = 0;
	        Node* current = top;
	        while (current) {
	            if (current->data == target) return index;
	            current = current->next;
	            index++;
	        }
	        return -1;
	    }
};

int main() {
    Infinite_Node_Stack stack;
    stack.push(40);
    stack.push(30);
    stack.push(20);
    stack.push(10);
    cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << stack.peak() << endl;
    stack.print();
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    cout << "[#] FOUND THE ELEMENT 20 AT INDEX : " << stack.search(20) << endl;
    stack.pop();
    stack.pop();
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    stack.push(50);
    stack.push(60);
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    stack.print();
    return 0;
}
