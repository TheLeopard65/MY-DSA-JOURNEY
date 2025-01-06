#include <iostream>
using namespace std;
class Node {
	protected:
		int data;
		Node *next = NULL;
	public:
		Node (int value) : data(value), next(NULL) {}
		friend class Priority_Queue;
};
class Priority_Queue {
	private:
		Node *front = NULL;
		int Priority = 1;      // 1 for MAX Priority and 0 for MIN Priority
	public:
		Priority_Queue(int type) : Priority(type), front(NULL) {}
		void enqueue(int value){
			Node *newNode = new Node(value);
			if (!front) front = newNode;
			else {
				Node *current = front, *previous = NULL;
				if (Priority == 1){
					while (current->next && current->data >= newNode->data){
						previous = current;
						current = current->next;
					}
				} else {
					while (current && current->data <= newNode->data) {
                    	previous = current;
                    	current = current->next;
                	}
				}
				if (!previous) {
					newNode->next = front;
                	front = newNode;
                } else {
	                previous->next = newNode;
    	            newNode->next = current;
        	    }
        	}
		}
		void dequeue(){
			if (!front) return;
			else {
				Node *temp = front;
				front = front->next;
				delete temp;
			}
		}
		int peak(){
			return ((front)? front->data : 0);
		}
		bool isEmpty(){
			return ((!front) ? 1 : 0 );
		}
		void print(){
			if (!front) return;
			else {
				Node *current = front;
				cout << "[#] TRAVERSING LINEAR QUEUE : ";
				while (current){
					cout << current->data << " - ";
					current = current->next;
				}
				cout << "(END)" << endl;
			}
		}
		int size(){
			if (!front) return 0;
			else {
				int count = 0;
				Node *current = front;
				while (current){
					current = current->next;
					count++;
				}
				return count;
			}
		}
		void clear(){
			cout << "[#] CLEARING THE LINEAR QUEUE !!!" << endl;
			while (front){
				Node *temp = front;
				front = front->next;
				delete temp;
			}
		}
};
int main() {
	Priority_Queue queue(0);    // 1 for MAX Priority Queue and 0 for MIN Priority Queue
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.print();
	cout << "[#] THE SIZE OF THE QUEUE IS : " << queue.size() << endl;
	cout << "[#] THE TOP ELEMENT OF THE QUEUE IS : " << queue.peak() << endl;
	queue.dequeue();
	queue.dequeue();
	queue.print();
	cout << "[#] THE TOP ELEMENT OF THE QUEUE IS : " << queue.peak() << endl;
	cout << "[#] IS THE QUEUE EMPTY? : " << (queue.isEmpty() ? "YES" : "NO") << endl;
	cout << "[#] THE SIZE OF THE QUEUE IS : " << queue.size() << endl;
	queue.clear();
	cout << "[#] IS THE QUEUE EMPTY? : " << (queue.isEmpty() ? "YES" : "NO") << endl;
	return 0;
}
