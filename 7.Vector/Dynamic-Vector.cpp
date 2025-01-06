#include <iostream>
using namespace std;
class Dynamic_Vector {
	private:
	    int *array, capacity, counter = 0;
	    void resize() {
	        int new_capacity = capacity * 2, *new_array = new int[new_capacity];
	        for (int i = 0; i < counter; i++)
	            new_array[i] = array[i];
	        delete[] array;
	        array = new_array;
	        capacity = new_capacity;
	    }
	public:
	    Dynamic_Vector(int initial_capacity = 10) : capacity(initial_capacity) {
	        array = new int[capacity];
	    }
	    void push(int value) {
	        if (counter == capacity) resize();
	        array[counter++] = value;
	    }
	    void insert(int index, int value) {
	        if (index >= 0 && index <= counter) {
	            if (counter == capacity) resize();
	            for (int i = counter; i > index; i--)
	                array[i] = array[i - 1];
	            array[index] = value;
	            counter++;
	        }
	    }
	    void remove(int index) {
	        if (index >= 0 && index < counter) {
	            for (int i = index; i < counter - 1; i++)
	                array[i] = array[i + 1];
	            counter--;
	        }
	    }
	    int at(int index) {
	        if (index >= 0 && index < counter)
	            return array[index];
	        return -1;
	    }
	    bool isEmpty() {
	        return counter == 0;
	    }
	    int size() {
	        return counter;
	    }
	    void print() {
	        if (counter == 0) return;
	        cout << "[#] TRVERSING DYNAMIC VECTOR : ";
	        for (int i = 0; i < counter; i++)
	            cout << array[i] << " ";
	        cout << endl;
	    }
	    int search(int target) {
	        for (int i = 0; i < counter; i++)
	            if (array[i] == target) return i;
	        return -1;
	    }
	    ~Dynamic_Vector() { delete[] array; }
};
int main() {
    Dynamic_Vector vector;
    vector.push(40);
    vector.push(30);
    vector.push(20);
    vector.push(10);
    vector.print();
    cout << "[#] IS THE VECTOR EMPTY? : " << (vector.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE VECTOR IS : " << vector.size() << endl;
    cout << "[#] ELEMENT 20 FOUND AT THE INDEX : " << vector.search(20) << endl;
    vector.insert(2, 50);
    vector.print();
    vector.remove(1);
    vector.print();
    cout << "[#] ELEMENT AT INDEX 2 IS : " << vector.at(2) << endl;
    return 0;
}
