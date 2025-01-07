#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& array, int l, int m, int r) {
    int Y = m - l + 1, Z = r - m;
    vector<int> leftArray(Y), rightArray(Z);
    for (int i = 0; i < Y; i++) leftArray[i] = array[l + i];
    for (int i = 0; i < Z; i++) rightArray[i] = array[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < Y && j < Z) {
        if (leftArray[i] <= rightArray[j]) array[k++] = leftArray[i++];
        else array[k++] = rightArray[j++];
    }
    while (i < Y) array[k++] = leftArray[i++];
    while (j < Z) array[k++] = rightArray[j++];
}
void mergeSort(vector<int>& array, int l, int r) {
    if (l >= r) return;
    int m = ( l + r ) / 2;
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
}
void printArray(const vector<int>& array) {
    for (int number : array)
        cout << number << " -> ";
    cout << "(END)" << endl;
}
int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    cout << "[#] ORIGINAL ARRAY : ";
    printArray(array);
    mergeSort(array, 0, array.size() - 1);
    cout << "[#] SORTED ARRAY : ";
    printArray(array);
    return 0;
}
