#include <iostream>
using namespace std;
void bubbleSort(int array[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " -> ";
    cout << "(END)" << endl;
}
int main() {
    int array[] = {5, 1, 4, 2, 8};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "[#] ORIGINAL ARRAY : ";
    printArray(array, size);
    bubbleSort(array, size);
    cout << "[#] SORTED ARRAY : ";
    printArray(array, size);
    return 0;
}
