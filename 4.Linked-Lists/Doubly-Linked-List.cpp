#include <iostream>
using namespace std;
class Node {
	protected:
		int data;
		Node *next = NULL, *prev = NULL;
	public:
		Node (int value) : data(value), next(NULL), prev(NULL) {}
		friend class Doubly_Linked_List;
};
class Doubly_Linked_List {
	private:
		Node *head = NULL, *tail = NULL;
	public:
		void add_head(int value){
			Node *newNode = new Node(value);
			if (!head) head = tail = newNode;
			else {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
		}
		void add_tail(int value){
			Node *newNode = new Node(value);
			if (!head) head = tail = newNode;
			else {
				newNode->prev = tail;
				tail->next = newNode;
				tail = newNode;
			}
		}
		void insert(int value, int location){
			Node *newNode = new Node(value), *current = head;
			if (!head) head = tail = newNode;
			else {
				int count = 1;
				while (current->next && count++ < location){
					current = current->next;
					count++;
				}
				newNode->next = current->next;
				current->next->prev = newNode;
				newNode->prev = current;
				current->next = newNode;
				if (!newNode->next) tail = newNode;
			}
		}
		void remove_head(){
			if (head){
				Node *temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
		}
		void remove_tail(){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				Node *temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
		}
		void remove_middle(int location){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				int count = 0;
				Node *previous = head, *current = head->next;
				while (current->next && count++ < location){
					previous = current;
					current = current->next;
					count++;
				}
				previous->next = current->next;
				previous->next->prev = previous;
				delete current;
				if (!previous->next->next) tail = previous->next;
			}
		}
		void traversing(){
			if (!head) return;
			Node *current = head;
			cout << "[#] FORWARD DOUBLY LINKED LIST: ";
			while (current) {
				cout << current->data << " - ";
				current = current->next;
			}
			cout << "(END)" << endl;
		}
		void reversing(){
			if (!head) return;
			Node *current = tail;
			cout << "[#] REVERSE DOUBLY LINKED LIST: ";
			while (current) {
				cout << current->data << " - ";
				current = current->prev;
			}
			cout << "(END)" << endl;
		}
		int length(){
			if (!head) return 0;
			int count = 0;
			Node *current = head;
			while (current){
				current = current->next;
				count++;
			}
			return count;
		}
		Node* searching(int target){
			if (!head) return NULL;
			Node *current = head;
			while (current){
				if (current->data == target)
					return current;
				current = current->next;
			}
			return NULL;
		}
		~Doubly_Linked_List(){
			while (head){
				Node *temp = head;
				head = head->next;
				delete temp;
			}
		}
};
int main() {
	Doubly_Linked_List list;
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
