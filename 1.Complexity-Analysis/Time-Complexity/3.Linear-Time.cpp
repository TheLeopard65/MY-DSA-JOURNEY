#include <iostream>
using namespace std;

// O(n) - Linear Time Complexity
// Linear time complexity means the algorithm's running time grows directly in proportion to the input size.
// Explanation: The function printAllElements() iterates through each element of the array once. As the array size 𝑛 n grows,
// 				the number of operations grows linearly, making the time complexity O(n).

void printAllElements(int arr[], int n) {
    // O(n) - Iterating through each element of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllElements(arr, n);  // Time complexity is O(n)
    return 0;
}
