#include <iostream>
#include <vector>
using namespace std;
class Double_Hashing {
private:
    vector<int> table;
    int size;
    int hashFunction(int key) { return key % size; }
    int secondHash(int key) { return 7 - (key % 7); }
    bool isFull() {
        for (int i = 0; i < size; i++)
            if (table[i] == -1) return false;
        return true;
    }
public:
    Double_Hashing(int tableSize) {
        size = tableSize;
        table.resize(size, -1);
    }
    void insert(int key) {
        if (isFull()) {
            cout << "[#] HASH-MAP IS FULL! CAN-NOT INSERT : " << key << endl;
            return;
        }
        int index = hashFunction(key);
        int stepSize = secondHash(key);
        while (table[index] != -1)
            index = (index + stepSize) % size;
        table[index] = key;
    }
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int stepSize = secondHash(key);
        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + stepSize) % size;
            if (index == originalIndex) break;
        }
        return false;
    }
    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int stepSize = secondHash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + stepSize) % size;
            if (index == originalIndex) break;
        }
        cout << "[#] KEY (" << key << ") NOT FOUND !!!" << endl;
    }
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) cout << ">>>[!] INDEX [" << i << "] : " << table[i] << endl;
            else cout << ">>>[!] INDEX [" << i << "] : EMPTY !!!" << endl;
        }
    }
};
int main() {
    Double_Hashing map(10);
    map.insert(10);
    map.insert(20);
    map.insert(30);
    map.insert(40);
    map.display();
    cout << "[#] SEARCHING FOR 20 : " << (map.search(20) ? "FOUND" : "NOT FOUND") << endl;
    map.remove(20);
    cout << "[#] SEARCHING FOR 20 : " << (map.search(20) ? "FOUND" : "NOT FOUND") << endl;
    return 0;
}
