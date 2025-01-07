#include <iostream>
#include <list>
#include <vector>
using namespace std;
#define TABLE_SIZE 10
class Separate_Chaining {
private:
    vector<list<int>> table;
    int hashFunction(int key) { return key % TABLE_SIZE; }
public:
    Separate_Chaining() { table.resize(TABLE_SIZE); }
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
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
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << ">>>[!] BUCKET [" << i << "] : ";
            for (int item : table[i])
                cout << item << " - ";
            cout << "(END)" << endl;
        }
    }
};
int main() {
    Separate_Chaining map;
    map.insert(10);
    map.insert(20);
    map.insert(15);
    map.insert(25);
    map.insert(35);
    map.display();
    cout << "[#] SEARCHING FOR 15 : " << (map.search(15) ? "FOUND" : "NOT FOUND") << endl;
    map.remove(15);
    cout << "[#] SEARCHING FOR 15 : " << (map.search(15) ? "FOUND" : "NOT FOUND") << endl;
    return 0;
}
