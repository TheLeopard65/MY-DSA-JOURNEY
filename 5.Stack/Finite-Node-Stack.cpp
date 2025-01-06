#include <iostream>
using namespace std;
class Node {
	protected:
	    int data;
	    Node* next = NULL;
	public:
	    Node(int value) : data(value), next(NULL) {}
	    friend class Finite_Node_Stack;
};
class Finite_Node_Stack {
private:
    Node* top = NULL;
    int max_size, counter = 0;
public:
	Finite_Node_Stack(int max) : max_size(max), top(NULL) {};
    void push(int value) {
    	if (counter >= max_size) {
    		cout << "[#] STACL ALREADY FULL !!" << endl;
    		return;
    	}
        Node* newNode = new Node(value);
        if (!top) {
        	top = newNode;
        	counter++;
        } else {
	        newNode->next = top;
    	    top = newNode;
    	    counter++;
		}
    }
    void pop() {
    	if (!top) return;
    	else {
            Node* temp = top;
            top = top->next;
            delete temp;
            counter--;
		}
    }
    int peak() {
    	return ((top)? top->data : -1);
    }
    bool isEmpty() {
        return (!top);
    }
    bool isFull() {
    	return (counter >= max_size);
    }
    int size() {
        int count = 0;
        Node* current = top;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
    void print() {
        if (!top) return;
        cout << "[#] TRAVERSING LINKED LIST BASED STACK: ";
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
    Finite_Node_Stack stack(10);
    stack.push(40);
    stack.push(30);
    stack.push(20);
    stack.push(10);
    cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << stack.peak() << endl;
    stack.print();
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] IS THE STACK FULL? : " << (stack.isFull() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    cout << "[#] FOUND THE ELEMENT 20 AT INDEX : " << stack.search(20) << endl;
    stack.pop();
    stack.pop();
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    stack.push(50);
    stack.push(60);
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] IS THE STACK FULL? : " << (stack.isFull() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    cout << "[#] FOUND THE ELEMENT 30 AT INDEX : " << stack.search(30) << endl;
    stack.print();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.print();
    cout << "[#] THE SIZE OF THE STACK IS : " << stack.size() << endl;
    cout << "[#] IS THE STACK EMPTY? : " << (stack.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] IS THE STACK FULL? : " << (stack.isFull() ? "YES" : "NO") << endl;
    return 0;
}
