#include <iostream>
using namespace std;

// O(n log n) - Linearithmic Time Complexity
// An algorithm with 𝑂(𝑛.log 𝑛) time complexity combines linear operations with a logarithmic process. Merge Sort is a classic example.
// Explanation: The mergeSort() function splits the array recursively and merges the subarrays, leading to a time complexity of 𝑂(𝑛.log 𝑛).

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);        // Sort the first half
        mergeSort(arr, m + 1, r);    // Sort the second half
        merge(arr, l, m, r);         // Merge the sorted halves
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);  // Time complexity is O(n log n)
    cout << "SORTED ARRAY: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
