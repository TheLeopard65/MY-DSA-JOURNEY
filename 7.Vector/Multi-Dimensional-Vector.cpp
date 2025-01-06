#include <iostream>
using namespace std;
class MultiDimensional_Vector {
private:
    int **array, rows, cols;
public:
    MultiDimensional_Vector(int r, int c) : rows(r), cols(c) {
        array = new int*[rows];
        for (int i = 0; i < rows; i++)
            array[i] = new int[cols];
    }
    void push(int row, int col, int value) {
        if (row < rows && col < cols)
            array[row][col] = value;
    }
    void insert(int row, int col, int value) {
        if (row < rows && col < cols)
            array[row][col] = value;
    }
    void remove(int row, int col) {
        if (row < rows && col < cols)
            array[row][col] = 0;
    }
    int at(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
            return array[row][col];
        return -1;
    }
    bool isEmpty() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (array[i][j] != 0) return false;
        return true;
    }
    int size() {
        return rows * cols;
    }
    void print() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << array[i][j] << " ";
            cout << endl;
    }
    int search(int target) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (array[i][j] == target)
                    return i * cols + j;
        return -1;
    }
    ~MultiDimensional_Vector() {
        for (int i = 0; i < rows; i++)
            delete[] array[i];
        delete[] array;
    }
};
int main() {
    MultiDimensional_Vector vector(3, 3);
    vector.push(0, 0, 40);
    vector.push(0, 1, 30);
    vector.push(0, 2, 20);
    vector.push(1, 0, 10);
    vector.print();
    cout << "[#] IS THE VECTOR EMPTY? : " << (vector.isEmpty() ? "YES" : "NO") << endl;
    cout << "[#] THE SIZE OF THE VECTOR IS : " << vector.size() << endl;
    cout << "[#] ELEMENT 20 FOUND AT INDEX : " << vector.search(20) << endl;
    vector.insert(1, 1, 50);
    vector.print();
    vector.remove(0, 1);
    vector.print();
    cout << "[#] ELEMENT AT (1, 2) IS : " << vector.at(1, 2) << endl;
    return 0;
}
