#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Rehashing {
private:
    vector<list<int>> table;
    int size, currentSize;
    int hashFunction(int key) { return key % size; }
    void rehash() {
        vector<list<int>> oldTable = table;
        size *= 2;
        table.clear();
        table.resize(size);
        currentSize = 0;
        for (auto &bucket : oldTable)
            for (int key : bucket)
                insert(key);
    }
    float loadFactor() { return (float)currentSize / size; }
public:
    Rehashing(int initialSize = 10) {
        size = initialSize;
        table.resize(size);
        currentSize = 0;
    }
    void insert(int key) {
        if (loadFactor() >= 0.7) rehash();
        int index = hashFunction(key);
        table[index].push_back(key);
        currentSize++;
    }
    bool search(int key) {
        int index = hashFunction(key);
        for (int item : table[index])
            if (item == key) return true;
        return false;
    }
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
        currentSize--;
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << ">>>[!] BUCKET [" << i << "] : ";
            for (int item : table[i])
                cout << item << " - ";
            cout << "(END)" << endl;
        }
    }
};
int main() {
    Rehashing map(3);
    map.insert(10);
    map.insert(20);
    map.insert(15);
    map.insert(25);
    map.insert(30);
    cout << "[#] HASH-TABLE AFTER INSERTING 5 ELEMENTS : (REHASHING) !!!" << endl;
    map.display();
    cout << "[#] SEARCHING FOR 15 : " << (map.search(15) ? "FOUND" : "NOT FOUND") << endl;
    map.remove(15);
    cout << "[#] SEARCHING FOR 15 : " << (map.search(15) ? "FOUND" : "NOT FOUND") << endl;
    return 0;
}
