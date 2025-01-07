#include <iostream>
#include <list>
using namespace std;
void selectionSort(list<int>& list) {
    for (auto i = list.begin(); i != list.end(); ++i) {
        auto minIndex = i;
        for (auto j = next(i); j != list.end(); ++j)
            if (*j < *minIndex) minIndex = j;
        if (minIndex != i) swap(*i, *minIndex);
    }
}
void printList(const list<int>& list) {
    for (auto i = list.begin(); i != list.end(); ++i)
        cout << *i << " -> ";
    cout << "(END)" << endl;
}
int main() {
    list<int> list = {64, 25, 12, 22, 11};
    cout << "[#] ORIGINAL LIST : ";
    printList(list);
    selectionSort(list);
    cout << "[#] SORTED LIST : ";
    printList(list);
    return 0;
}
