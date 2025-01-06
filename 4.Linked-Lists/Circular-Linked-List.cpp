#include <iostream>
using namespace std;
class Node {
	protected:
		int data;
		Node *next = NULL;
	public:
		Node (int value) : data(value), next(NULL) {}
		friend class Circular_Linked_List;
};
class Circular_Linked_List {
	private:
		Node *head = NULL, *last = NULL;
	public:
		void add_head(int value){
			Node *newNode = new Node(value);
			if (!head) head = last = newNode;
			else {
				newNode->next = head;
				head = last->next = newNode;
			}
		}
		void add_tail(int value){
			Node *newNode = new Node(value);
			if (!head) head = last = newNode;
			else {
				last->next = newNode;
				newNode->next = head;
				last = newNode;
			}
		}
		void insert(int value, int location){
			Node *newNode = new Node(value), *current = head;
			if (!head) head = newNode;
			else {
				int count = 1;
				while ((current != last) && count++ < location){
					current = current->next;
					count++;
				}
				newNode->next = current->next;
				current->next = newNode;
				if (newNode->next == head) last = newNode;
			}
		}
		void remove_head(){
			if (head){
				Node *temp = head;
				head = head->next;
				last->next = head;
				delete temp;
			}
		}
		void remove_tail(){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				Node *current = head;
				while (current->next != last)
					current = current->next;
				Node *temp = last;
				current->next = last->next;
				last = current;
				delete temp;
			}
		}
		void remove_middle(int location){
			if (!head) return;
			else if (!head->next) delete head;
			else {
				int count = 0;
				Node *current = head;
				while ((current->next != last) && count++ < location){
					current = current->next;
					count++;
				}
				Node *temp = current->next;
				current->next = current->next->next;
				if (current->next == head) last = current;
				delete temp;
			}
		}
		void traversing(){
			if (!head) return;
			Node *current = head;
			cout << "[#] CIRCULAR LINKED LIST: ";
			do {
				cout << current->data << " - ";
				current = current->next;
			} while( current != head);
			cout << "(END)" << endl;
		}
		void reverse() {
		    if (!head || head == last) return;
			Node *prev = NULL, *current = head, *next = NULL;
		    do {
		        next = current->next;
		        current->next = prev;
		        prev = current;
		        current = next;
		    } while (current != head);
		    last = head;
		    head = prev;
		    last->next = head;
		}
		int length(){
			if (!head) return 0;
			int count = 0;
			Node *current = head;
			do {
				current = current->next;
				count++;
			} while (current != head);
			return count;
		}
		Node* searching(int target){
			if (!head) return NULL;
			Node *current = head;
			do {
				if (current->data == target)
					return current;
				current = current->next;
			} while (current != head);
			return NULL;
		}
		~Circular_Linked_List() {
			if (head){
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
	Circular_Linked_List list;
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
