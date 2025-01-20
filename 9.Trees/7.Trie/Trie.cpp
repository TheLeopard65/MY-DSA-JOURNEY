#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
    public:
        unordered_map<char, Node*> children;
        bool isEndOfWord;
        Node() : isEndOfWord(false) {}
};
class Trie {
    private:
        Node* root;
        void insert(string word, Node* temp) {
            for (char c : word) {
                if (temp->children.find(c) == temp->children.end())
                    temp->children[c] = new Node();
                temp = temp->children[c];
            }
            temp->isEndOfWord = true;
        }
        bool search(string word, Node* temp) {
            for (char c : word) {
                if (temp->children.find(c) == temp->children.end()) return false;
                temp = temp->children[c];
            }
            return temp->isEndOfWord;
        }
        bool startsWith(string prefix, Node* temp) {
            for (char c : prefix) {
                if (temp->children.find(c) == temp->children.end()) return false;
                temp = temp->children[c];
            }
            return true;
        }
    public:
        Trie() { root = new Node(); }
        void insert(string word) { insert(word, root); }
        bool search(string word) { return search(word, root); }
        bool startsWith(string prefix) { return startsWith(prefix, root); }
};
int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("he");
    trie.insert("her");
    cout << "[#] IS 'hello' PRESENT IN THE TRIE? : " << (trie.search("hello") ? "YES" : "NO") << endl;
    cout << "[#] IS 'hell' PRESENT IN THE TRIE? : " << (trie.search("hell") ? "YES" : "NO") << endl;
    cout << "[#] IS 'hi' PRESENT IN THE TRIE? : " << (trie.search("hi") ? "YES" : "NO") << endl;
    cout << "[#] DOES ANY WORD START WITH 'he'? : " << (trie.startsWith("he") ? "YES" : "NO") << endl;
    cout << "[#] DOES ANY WORD START WITH 'wor'? : " << (trie.startsWith("wor") ? "YES" : "NO") << endl;
    cout << "[#] DOES ANY WORD START WITH 'good'? : " << (trie.startsWith("good") ? "YES" : "NO") << endl;
    return 0;
}
