#include <iostream>
#include <list>
using namespace std;
void bubbleSort(list<int>& list) {
    bool swapped;
    do {
        swapped = false;
        auto it1 = list.begin();
        auto it2 = next(it1);
        while (it2 != list.end()) {
            if (*it1 > *it2) {
                swap(*it1, *it2);
                swapped = true;
            }
            ++it1;
            ++it2;
        }
    } while (swapped);
}
void printList(const list<int>& list) {
    for (int value : list) {
        cout << value << " -> ";
    }
    cout << "(END)" << endl;
}
int main() {
    list<int> list = {5, 1, 4, 2, 8};
    cout << "[#] ORIGINAL LIST: ";
    printList(list);
    bubbleSort(list);
    cout << "[#] SORTED LIST: ";
    printList(list);

    return 0;
}
