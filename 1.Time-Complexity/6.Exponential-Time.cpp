#include <iostream>
using namespace std;

// O(2^n) - Exponential Time Complexity
// Exponential time complexity is typically seen in algorithms that explore all possible solutions, such as the brute-force recursive approach to solving the Fibonacci sequence.
// Explanation: The fibonacci() function uses a recursive approach that recalculates the same values multiple times,
// 				leading to exponential time complexity of 𝑂(2𝑛).

int fibonacci(int n) {
    // O(2^n) - Exponential time complexity due to recursion
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;  // Time complexity is O(2^n)
    return 0;
}
