#include <iostream>
using namespace std;
class Node {
	protected:
	    int data;
	    Node* next;
	public:
	    Node(int value) : data(value), next(NULL) {}
	    friend class Quick_Sort;
};
class Quick_Sort {
public:
    Node* head = NULL;
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void printList() {
        Node* current = head;
        cout << "[#] LINKED LIST : ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "(END)" << endl;
    }
    Node* getLastNode() {
        if (!head) return NULL;
        Node* current = head;
        while (current->next)
            current = current->next;
        return current;
    }
    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node *i = low, *j = low;
        for (Node* k = low; k != high; k = k->next) {
            if (k->data < pivot) {
                if (i == NULL) i = low;
                else i = i->next;
                swap(i->data, k->data);
            }
        }
        swap(i->data, high->data);
        return i;
    }
    void quickSort(Node* low, Node* high) {
        if (low != high && low && high && low != high->next) {
            Node* pi = partition(low, high);
            quickSort(low, pi);
            quickSort(pi->next, high);
        }
    }
};
int main() {
    Quick_Sort list;
    list.push(11);
    list.push(22);
    list.push(12);
    list.push(25);
    list.push(64);
    list.printList();
    Node* last = list.getLastNode();
    list.quickSort(list.head, last);
    list.printList();
    return 0;
}
