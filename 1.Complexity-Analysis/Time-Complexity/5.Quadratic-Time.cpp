#include <iostream>
using namespace std;

// O(n^2) - Quadratic Time Complexity
// Quadratic time complexity is common in algorithms with nested loops, where the number of operations grows quadratically with the input size.
// Explanation: The bubbleSort() function uses nested loops to compare and swap adjacent elements, resulting in 𝑂(𝑛^2) time complexity.

void bubbleSort(int arr[], int n) {
    // O(n^2) - Nested loops
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);  // Time complexity is O(n^2)
    cout << "SORTED ARRAY: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
