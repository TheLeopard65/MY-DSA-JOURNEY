#include <iostream>
#include <vector>
using namespace std;

// Logarithmic Space - O(log n)
// When an algorithm uses space that grows logarithmically with the input size, typically due to recursion.
// This example uses an iterative binary search that has O(log n) space complexity because the space used does not depend on recursion depth, but only on a few variables.

int binary_search(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  // Return -1 if not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 7;
    int index = binary_search(arr, target);
    cout << "Index of " << target << ": " << index << endl;  // Output: 3
    return 0;
}
