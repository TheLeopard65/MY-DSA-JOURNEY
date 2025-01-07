#include <iostream>
#include <list>
using namespace std;
void merge(list<int>& input, list<int>& left, list<int>& right) {
    auto l = left.begin();
    auto r = right.begin();
    while (l != left.end() && r != right.end()) {
        if (*l < *r) input.push_back(*l++);
        else input.push_back(*r++);
    }
    while (l != left.end()) input.push_back(*l++);
    while (r != right.end()) input.push_back(*r++);
}
void mergeSort(list<int>& input) {
    if (input.size() <= 1) return;
    auto middle = input.begin();
    advance(middle, input.size() / 2);
    list<int> left(input.begin(), middle);
    list<int> right(middle, input.end());
    mergeSort(left);
    mergeSort(right);
    input.clear();
    merge(input, left, right);
}
void printList(const list<int>& list) {
    for (int value : list)
        cout << value << " -> ";
    cout << "(END)" << endl;
}
int main() {
    list<int> inputList = {38, 27, 43, 3, 9, 82, 10};
    cout << "[#] ORIGINAL LIST : ";
    printList(inputList);
    mergeSort(inputList);
    cout << "[#] SORTED LIST : ";
    printList(inputList);
    return 0;
}
