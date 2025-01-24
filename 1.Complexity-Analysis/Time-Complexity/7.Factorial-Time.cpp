#include <iostream>
#include <vector>
using namespace std;

// O(n!) - Factorial Time Complexity
// Factorial time complexity typically arises in problems involving permutations, such as generating all permutations of a set of elements.
// Explanation: The permute() function generates all permutations of the input array, which leads to a factorial time complexity of
//				𝑂(𝑛!) as it must explore every possible permutation.

void permute(vector<int>& arr, int l, int r) {
    if (l == r) {
        // O(n!) - Printing each permutation
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);
            permute(arr, l + 1, r);
            swap(arr[l], arr[i]);  // Backtrack
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    permute(arr, 0, arr.size() - 1);  // Time complexity is O(n!)
    return 0;
}
