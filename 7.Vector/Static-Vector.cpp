#include <iostream>
using namespace std;
class Static_Vector {
	private:
	    int *array, max_size, counter = 0;
	public:
	    Static_Vector(int max) : max_size(max), array(new int[max_size]) {}
	    void push(int value) {
	        if (counter < max_size) array[counter++] = value;
	    }
	    void insert(int index, int value) {
	        if (counter < max_size && index <= counter) {
	            for (int i = counter; i > index; i--)
	                array[i] = array[i - 1];
	            array[index] = value;
	            counter++;
	        }
	    }
	    void remove(int index) {
	        if (index < counter) {
	            for (int i = index; i < counter - 1; i++)
	                array[i] = array[i + 1];
	            counter--;
	        }
	    }
	    int at(int index) {
	        if (index >= 0 && index < counter) return array[index];
	        return -1;
	    }
	    bool isEmpty() {
	        return counter == 0;
	    }
	    bool isFull() {
	        return counter >= max_size;
	    }
	    int size() {
	        return counter;
	    }
	    void print() {
	        if (counter == 0) return;
	        cout << "[#] TRAVERSING STATIC VECTOR : ";
	        for (int i = 0; i < counter; i++)
	            cout << array[i] << " ";
	        cout << endl;
	    }
	    int search(int target) {
	        for (int i = 0; i < counter; i++) {
	            if (array[i] == target) return i;
	        }
	        return -1;
	    }
	    ~Static_Vector() { delete[] array; }
};
int main() {
    Static_Vector vector(10);
    vector.push(40);
    vector.push(30);
    vector.push(20);
    vector.push(10);
    vector.print();
    cout << "[#] IS THE VECTOR EMPTY? : " << (vector.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] IS THE VECTOR FULL? : " << (vector.isFull() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE VECTOR IS : " << vector.size() << endl;
    cout << "[#] ELEMENT20 FOUND AT INDEX : " << vector.search(20) << endl;
    vector.insert(2, 50);
    vector.print();
    vector.remove(1);
    vector.print();
    cout << "[#] ELEMENT AT INDEX 2 IS : " << vector.at(2) << endl;
    return 0;
}
