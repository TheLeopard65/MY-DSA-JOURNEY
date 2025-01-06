#include <iostream>
using namespace std;

// CODE FOR: Tail Recursion
// The recursive call is the last operation in the function. The result of the recursive call is directly returned without further computation after it.

// Tail recursive function to calculate factorial
int factorial_tail(int n, int result = 1) {
    if (n == 0) return result;                 // Base Case
    return factorial_tail(n - 1, n * result);  // Recursive Case
}
int main() {
    int n = 5;
    cout << "[#] FACTORIAL OF " << n << " IS : " << factorial_tail(n) << endl;
    return 0;
}

/*

- EXPLANANTION:

1. factorial_tail takes two arguments: n and result. The default value of result is 1, which is used as an accumulator to store intermediate results.
2. Each recursive call updates the result parameter with the intermediate product.
3. The recursion stops when n reaches 0, and the accumulated result is returned.

*/
