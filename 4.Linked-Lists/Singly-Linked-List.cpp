#include <iostream>
using namespace std;
class Node {
	protected:
		int data;
		Node *next = NULL;
	public:
		Node (int value) : data(value), next(NULL) {}
		friend class Singly_Linked_List;
};
class Singly_Linked_List {
	private:
		Node *head = NULL;
	public:
		void add_head(int value){
			Node *newNode = new Node(value);
			if (!head) head = newNode;
			else {
				newNode->next = head;
				head = newNode;
			}
		}
		void add_tail(int value){
			Node *newNode = new Node(value);
			if (!head) head = newNode;
			else {
				Node *current = head;
				while (current->next)
					current = current->next;
				current->next = newNode;
			}
		}
		void insert(int value, int location){
			Node *newNode = new Node(value), *current = head;
			if (!head) head = newNode;
			else {
				int count = 1;
				while (current->next && count++ < location){
					current = current->next;
					count++;
				}
				newNode->next = current->next;
				current->next = newNode;
			}
		}
		void remove_head(){
			if (head){
				Node *temp = head;
				head = head->next;
				delete temp;
			}
		}
		void remove_tail(){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				Node *previous = head, *current = head->next;
				while (current->next){
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
				delete current;
			}
		}
		void remove_middle(int location){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				int count = 0;
				Node *current = head;
				while (current->next && count++ < location){
					current = current->next;
					count++;
				}
				Node *temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
		}
		void traversing(){
			if (!head) return;
			Node *current = head;
			cout << "[#] LINKED LIST: ";
			while (current){
				cout << current->data << " - ";
				current = current->next;
			}
			cout << "(END)" << endl;
		}
		void reverse() {
		    if (!head || !head->next) return;
			Node *prev = NULL, *current = head, *next = NULL;
		    while (current) {
		        next = current->next;
		        current->next = prev;
		        prev = current;
		        current = next;
		    }
		    head = prev;
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
		~Singly_Linked_List() {
			while (head){
				Node *temp = head;
				head = head->next;
				delete temp;
			}
		}
};
int main() {
	Singly_Linked_List list;
	list.add_head(30);
	list.add_head(20);
	list.add_head(10);
	list.add_tail(50);
	list.add_tail(60);
	list.add_tail(70);
	list.insert(40, 4);
	list.traversing();
	cout << "[#] TOTAL NODES IN THE LIST ARE: " << list.length() << endl;
	list.remove_middle(5);
	list.remove_head();
	list.remove_tail();
	list.traversing();
	cout << "[#] TOTAL NODES IN THE LIST ARE: " << list.length() << endl;
	Node *found = list.searching(60);
	cout << "[#] IS 60 PRESENT IN THE LIST: " << (found ? "YES" : "NO") << endl;
	found = list.searching(65);
	cout << "[#] IS 65 PRESENT IN THE LIST: " << (found ? "YES" : "NO") << endl;
	return 0;
}
