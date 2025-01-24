#include <iostream>
#include <vector>
using namespace std;

// Quadratic Space - O(n^2)
// When the algorithm uses a 2D data structure like a matrix.
// In this case, the space complexity is O(n^2) because we are storing an n x n matrix.

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Create an n x n matrix
    return matrix;
}

int main() {
    int n = 3;
    vector<vector<int>> matrix = create_matrix(n);
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
