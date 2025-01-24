#include <iostream>
using namespace std;

// Constant Space - O(1)
// When an algorithm uses a fixed amount of memory regardless of the size of the input.
// In this case, the algorithm uses a fixed amount of space (for the temp variable), so the space complexity is O(1).

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 3, b = 5;
    swap(a, b);
    cout << "a: " << a << ", b: " << b << endl; // Output: a: 5, b: 3
    return 0;
}
