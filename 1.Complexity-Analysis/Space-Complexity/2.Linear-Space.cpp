#include <iostream>
#include <vector>
using namespace std;

// Linear Space - O(n)
// When the space required grows linearly with the size of the input.
// Here, new_arr takes up the same amount of memory as arr, so the space complexity is O(n).

vector<int> create_copy(const vector<int>& arr) {
    vector<int> new_arr = arr;  // Copy the entire array
    return new_arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> new_arr = create_copy(arr);
    for (int num : new_arr)
        cout << num << " ";
    cout << endl;  // Output: 1 2 3 4 5
    return 0;
}
