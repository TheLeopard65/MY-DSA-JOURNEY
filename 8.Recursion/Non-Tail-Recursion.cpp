#include <iostream>
using namespace std;

// CODE FOR: Non-Tail Recursion
// There are operations that occur after the recursive call. These operations happen after the function returns from the recursive call.

// Non-tail recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n == 0) return 0;                       // BASE CASE 1
    if (n == 1) return 1;                       // BASE CASE 2
    return fibonacci(n - 1) + fibonacci(n - 2); // RECURSIVE CASE
}
int main() {
    int n = 5;
    cout << "[#] FIBONACCI NUMBER AT POSITION " << n << " IS : " << fibonacci(n) << endl;
    return 0;
}
/*

- Explanation:

1. The function fibonacci calculates the nth Fibonacci number.
2. This recursive function calls itself twice: once for fibonacci(n - 1) and once for fibonacci(n - 2).
3. The recursion continues until n reaches 0 or 1, at which point the base cases return 0 and 1.

*/
