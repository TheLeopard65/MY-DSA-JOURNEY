#include <iostream>
using namespace std;
class Node {
	protected:
	    int data;
	    Node *next = NULL, *prev = NULL;
	public:
	    Node(int value) : data(value), next(NULL), prev(NULL) {}
	    friend class Doubly_Circular_Linked_List;
};
class Doubly_Circular_Linked_List {
	private:
	    Node *head = NULL, *tail = NULL;
	public:
	    void add_head(int value) {
	        Node *newNode = new Node(value);
	        if (!head) {
	            head = tail = newNode;
	            head->next = head;
	            head->prev = head;
	        } else {
	            newNode->next = head;
	            newNode->prev = tail;
	            tail->next = newNode;
	            head->prev = newNode;
	            head = newNode;
	        }
	    }
	    void add_tail(int value) {
	        Node *newNode = new Node(value);
	        if (!head) {
	            head = tail = newNode;
	            head->next = head;
	            head->prev = head;
	        } else {
	            newNode->next = head;
	            newNode->prev = tail;
	            tail->next = newNode;
	            head->prev = newNode;
	            tail = newNode;
	        }
	    }
	    void insert(int value, int location) {
	        if (!head || location == 0) {
	            add_head(value);
	            return;
	        }
	        Node *newNode = new Node(value);
	        Node *current = head;
	        int count = 0;
	        while (current->next != head && count < location - 1) {
	            current = current->next;
	            count++;
	        }
	        newNode->next = current->next;
	        newNode->prev = current;
	        current->next->prev = newNode;
	        current->next = newNode;
	        if (current == tail) tail = newNode;
	    }
	    void remove_head() {
	        if (!head) return;
	        Node *temp = head;
	        if (head == tail) head = tail = NULL;
	        else {
	            head = head->next;
	            head->prev = tail;
	            tail->next = head;
	        }
	        delete temp;
	    }
	    void remove_tail() {
	        if (!head) return;
	        Node *temp = tail;
	        if (head == tail) head = tail = NULL;
	        else {
	            tail = tail->prev;
	            tail->next = head;
	            head->prev = tail;
	        }
	        delete temp;
	    }
	    void remove_middle(int location) {
	        if (!head) return;
	        Node *current = head;
	        int count = 0;
	        while (current->next != head && count < location) {
	            current = current->next;
	            count++;
	        }
	        if (current != head) {
	            current->prev->next = current->next;
	            current->next->prev = current->prev;
	            if (current == tail) tail = current->prev;
	            delete current;
	        }
	    }
	    void traversing() {
	        if (!head) return;
	        Node *current = head;
	        cout << "[#] FORWARD CIRCULAR DOUBLY LINKED LIST: ";
	        do {
	            cout << current->data << " - ";
	            current = current->next;
	        } while (current != head);
	        cout << "(END)" << endl;
	    }

	    void reversing() {
	        if (!head) return;
	        Node *current = tail;
	        cout << "[#] REVERSE CIRCULAR DOUBLY LINKED LIST: ";
	        do {
	            cout << current->data << " - ";
	            current = current->prev;
	        } while (current != tail);
	        cout << "(END)" << endl;
	    }
	    int length() {
	        if (!head) return 0;
	        int count = 0;
	        Node *current = head;
	        do {
	            current = current->next;
	            count++;
	        } while (current != head);
	        return count;
	    }
	    Node* searching(int target) {
	        if (!head) return NULL;
	        Node *current = head;
	        do {
	            if (current->data == target) return current;
	            current = current->next;
	        } while (current != head);
	        return NULL;
	    }
	    ~Doubly_Circular_Linked_List() {
	        if (head) {
	            Node *current = head;
	            do {
	                Node *temp = current;
	                current = current->next;
	                delete temp;
	            } while (current != head);
	        }
	    }
};
int main() {
    Doubly_Circular_Linked_List list;
    list.add_head(30);
    list.add_head(20);
    list.add_head(10);
    list.add_tail(50);
    list.add_tail(60);
    list.add_tail(70);
    list.insert(40, 4);
    list.traversing();
    list.reversing();
    cout << "[#] TOTAL NODES IN THE LIST ARE: " << list.length() << endl;
    list.remove_middle(5);
    list.remove_head();
    list.remove_tail();
    list.traversing();
    list.reversing();
    cout << "[#] TOTAL NODES IN THE LIST ARE: " << list.length() << endl;
    Node *found = list.searching(60);
    cout << "[#] IS 60 PRESENT IN THE LIST: " << (found ? "YES" : "NO") << endl;
    found = list.searching(65);
    cout << "[#] IS 65 PRESENT IN THE LIST: " << (found ? "YES" : "NO") << endl;
    return 0;
}
