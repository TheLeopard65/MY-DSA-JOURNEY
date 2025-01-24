#include <iostream>
using namespace std;

// O(1) - Constant Time Complexity
// An algorithm with constant time complexity performs a fixed number of operations, regardless of the input size.
// Explanation: The function `printFirstElement()` always performs the same number of operations, regardless of the array size, making its time complexity O(1).

void printFirstElement(int arr[], int n) {
    // O(1) - Accessing the first element
    cout << "First Element: " << arr[0] << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    printFirstElement(arr, n);  // Time complexity is O(1)
    return 0;
}
