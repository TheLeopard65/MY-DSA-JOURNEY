#include <iostream>
using namespace std;

// O(log n) - Logarithmic Time Complexity
// Logarithmic time complexity occurs when an algorithm reduces the problem size by a constant factor with each step, such as binary search.
// Explanation: The function binarySearch() halves the search space with each iteration, resulting in a logarithmic time complexity of O(log n).

int binarySearch(int arr[], int left, int right, int target) {
    // O(log n) - Binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;         // Check if target is present at mid
        if (arr[mid] > target) right = mid - 1;     // If target is smaller, ignore the right half
        else left = mid + 1;                        // If target is greater, ignore the left half
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {2, 5, 9, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = binarySearch(arr, 0, n - 1, target);  // Time complexity is O(log n)
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
