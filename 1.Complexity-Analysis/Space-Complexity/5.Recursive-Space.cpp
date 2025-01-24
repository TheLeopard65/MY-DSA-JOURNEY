#include <iostream>
using namespace std;

// Recursive Fibonacci with Space Complexity - O(n)
// In a recursive Fibonacci function, the space complexity depends on the maximum depth of the recursion stack.
// Here, the maximum recursion depth is n, so the space complexity is O(n) due to the recursive call stack.

int fibonacci(int n) {
    if (n <= 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n = 5;
    int result = fibonacci(n);
    cout << "Fibonacci of " << n << ": " << result << endl;  // Output: 5
    return 0;
}
