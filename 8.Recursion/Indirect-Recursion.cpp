#include <iostream>
using namespace std;

// CODE FOR: Indirect Recursion
// In indirect recursion, a function calls another function, which in turn calls the original function, forming a cycle.

void functionA(int n);
void functionB(int n) {
    if (n > 0) {
        cout << "[#] IN FUNCTION-B > N = " << n << endl;
        functionA(n - 1);
    }
}
void functionA(int n) {
    if (n > 0) {
        cout << "[#] IN FUNCTION-A > N = " << n << endl;
        functionB(n - 1);
    }
}
int main() {
    int n = 5;
    functionA(n);
    return 0;
}
/*

- Explanation:

1. In this example, functionA calls functionB, and functionB calls functionA, creating an indirect recursion.
2. The recursion alternates between functionA and functionB until the base case (n <= 0) is reached.
3. This type of recursion is more complex, as it involves multiple functions calling each other recursively.

*/
