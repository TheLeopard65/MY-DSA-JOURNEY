#include <iostream>
using namespace std;
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[minIndex]) minIndex = j;
        swap(array[i], array[minIndex]);
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " -> ";
    cout << "(END)" << endl;
}
int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
	cout << "[#] ORIGINAL ARRAY : ";
    printArray(array, size);
    selectionSort(array, size);
	cout << "[#] SORTED ARRAY : ";
    printArray(array, size);
    return 0;
}
