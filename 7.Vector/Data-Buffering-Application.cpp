#include <iostream>
using namespace std;
class Buffer {
private:
    int *buffer, capacity, size, front, rear;
public:
    Buffer(int cap) {
        capacity = cap;
        buffer = new int[capacity];
        size = front = 0;
        rear = -1;
    }
    ~Buffer() { delete[] buffer; }
    bool isFull() { return (size == capacity); }
    bool isEmpty() { return (size == 0); }
    void addData(int data) {
        if (isFull()) {
            cout << "[@] ERROR: Buffer is FULL, cannot Add Data !!!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        buffer[rear] = data;
        size++;
    }
    int removeData() {
        if (isEmpty()) {
            cout << "[@] ERROR: Buffer is EMPTY, cannot Remove Data!" << endl;
            return -1;
        }
        int data = buffer[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }
    int getSize() { return size; }
    void displayBuffer() {
        if (isEmpty()) {
            cout << "[!] INFO: BUFFER IS EMPTY !!!" << endl;
            return;
        }
        cout << "[!] CURRENT BUFFER: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << buffer[index] << " ";
        }
        cout << endl;
    }
};
int main() {
    Buffer buffer(5);
    buffer.addData(10);
    buffer.addData(20);
    buffer.addData(30);
    buffer.displayBuffer();
    cout << "[#] REMOVED DATA: " << buffer.removeData() << endl;
    buffer.displayBuffer();
    buffer.addData(40);
    buffer.addData(50);
    buffer.addData(60);
    buffer.displayBuffer();
    cout << "[#] REMOVED DATA: " << buffer.removeData() << endl;
    buffer.displayBuffer();
    return 0;
}
