#include <iostream>
using namespace std;
class Node {
	protected:
		int data;
		Node *next = NULL;
	public:
		Node (int value) : data(value), next(NULL) {}
		friend class Circular_Queue;
};
class Circular_Queue {
	private:
		Node *front = NULL, *end = NULL;
	public:
		void enqueue(int value){
			Node *newNode = new Node(value);
			if (!front) front = end = newNode;
			else {
				end->next = newNode;
				newNode->next = front;
				end = newNode;
			}
		}
		void dequeue(){
			if (!front) return;
			else {
				Node *temp = front;
				front = front->next;
				end->next = front;
				delete temp;
			}
		}
		int peak(){
			return ( (front)? front->data : NULL);
		}
		bool isEmpty(){
			return ((!front) ? 1 : 0 );
		}
		void print(){
			if (!front) return;
			else {
				Node *current = front;
				cout << "[#] TRAVERSING CIRCULAR QUEUE : ";
				do{
					cout << current->data << " - ";
					current = current->next;
				} while (current != front);
				cout << "(END)" << endl;
			}
		}
		int size(){
			if (!front) return 0;
			else {
				int count = 0;
				Node *current = front;
				do{
					current = current->next;
					count++;
				} while (current != front);
				return count;
			}
		}
};
int main() {
	Circular_Queue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.print();
	cout << "[#] THE SIZE OF THE QUEUE IS : " << queue.size() << endl;
	cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << queue.peak() << endl;
	queue.dequeue();
	queue.dequeue();
	queue.print();
	cout << "[#] IS THE QUEUE EMPTY? : " << (queue.isEmpty() ? "YES" : "NO") << endl;
	cout << "[#] THE TOP ELEMENT OF THE STACK IS : " << queue.peak() << endl;
	queue.dequeue();
	queue.dequeue();
	cout << "[#] IS THE QUEUE EMPTY? : " << (queue.isEmpty() ? "YES" : "NO") << endl;
	return 0;
}
