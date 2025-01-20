#include <iostream>
#include <vector>
using namespace std;
class Node {
    private:
        vector<int> keys;
        vector<Node*> children;
        bool leaf;
    public:
        Node(bool isLeaf) : leaf(isLeaf) {}
        friend class BTree;
};
class BTree {
    private:
        Node* root;
        int t;
        void insertNonFull(Node* node, int key);
        void splitChild(Node* parent, int index, Node* child);
        void traverse(Node* node);
        Node* search(Node* node, int key);
        Node* remove(Node* node, int key);
        void removeFromLeaf(Node* node, int index);
        void removeFromNonLeaf(Node* node, int index);
        int getPredecessor(Node* node, int index);
        int getSuccessor(Node* node, int index);
        void fill(Node* node, int index);
        void borrowFromPrev(Node* node, int index);
        void borrowFromNext(Node* node, int index);
        void merge(Node* node, int index);
    public:
        BTree(int degree) : t(degree) { root = new Node(true); }
        void insert(int key) { insertNonFull(root, key); }
        void traverse() { traverse(root); }
        Node* search(int key) { return search(root, key); }
        void remove(int key) { root = remove(root, key); }
};
void BTree::insertNonFull(Node* node, int key) {
    int i = node->keys.size() - 1;
    if (node->leaf) {
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {
        while (i >= 0 && key < node->keys[i]) i--;
        i++;
        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) i++;
        }
        insertNonFull(node->children[i], key);
    }
}
void BTree::splitChild(Node* parent, int index, Node* child) {
    Node* newNode = new Node(child->leaf);
    int midKey = child->keys[t - 1];
    newNode->keys.assign(child->keys.begin() + t, child->keys.end());
    child->keys.resize(t - 1);
    if (!child->leaf) {
        newNode->children.assign(child->children.begin() + t, child->children.end());
        child->children.resize(t);
    }
    parent->keys.insert(parent->keys.begin() + index, midKey);
    parent->children.insert(parent->children.begin() + index + 1, newNode);
}
void BTree::traverse(Node* node) {
    if (node) {
        for (int i = 0; i < node->keys.size(); i++) {
            if (!node->leaf) traverse(node->children[i]);
            cout << node->keys[i] << " ";
        }
        if (!node->leaf) traverse(node->children[node->keys.size()]);
    }
}
Node* BTree::search(Node* node, int key) {
    int i = 0;
    while (i < node->keys.size() && key > node->keys[i]) i++;
    if (i < node->keys.size() && key == node->keys[i]) return node;
    if (node->leaf) return nullptr;
    return search(node->children[i], key);
}
Node* BTree::remove(Node* node, int key) {
    int index = 0;
    while (index < node->keys.size() && node->keys[index] < key) index++;
    if (index < node->keys.size() && node->keys[index] == key) {
        if (node->leaf) removeFromLeaf(node, index);
        else removeFromNonLeaf(node, index);
    } else if (!node->leaf) {
        fill(node, index);
        remove(node->children[index], key);
    }
    return node;
}
void BTree::removeFromLeaf(Node* node, int index) { node->keys.erase(node->keys.begin() + index); }
void BTree::removeFromNonLeaf(Node* node, int index) {
    int key = node->keys[index];
    if (node->children[index]->keys.size() >= t) {
        int pred = getPredecessor(node, index);
        node->keys[index] = pred;
        remove(node->children[index], pred);
    } else if (node->children[index + 1]->keys.size() >= t) {
        int succ = getSuccessor(node, index);
        node->keys[index] = succ;
        remove(node->children[index + 1], succ);
    } else {
        merge(node, index);
        remove(node->children[index], key);
    }
}
int BTree::getPredecessor(Node* node, int index) {
    Node* current = node->children[index];
    while (!current->leaf)
        current = current->children[current->keys.size()];
    return current->keys.back();
}
int BTree::getSuccessor(Node* node, int index) {
    Node* current = node->children[index + 1];
    while (!current->leaf)
        current = current->children[0];
    return current->keys.front();
}
void BTree::fill(Node* node, int index) {
    if (index > 0 && node->children[index - 1]->keys.size() >= t) borrowFromPrev(node, index);
    else if (index < node->keys.size() && node->children[index + 1]->keys.size() >= t) borrowFromNext(node, index);
    else {
        if (index < node->keys.size()) merge(node, index);
        else merge(node, index - 1);
    }
}
void BTree::borrowFromPrev(Node* node, int index) {
    Node* child = node->children[index];
    Node* sibling = node->children[index - 1];
    child->keys.insert(child->keys.begin(), node->keys[index - 1]);
    node->keys[index - 1] = sibling->keys.back();
    if (!sibling->leaf) {
        child->children.insert(child->children.begin(), sibling->children.back());
        sibling->children.pop_back();
    }
    sibling->keys.pop_back();
}
void BTree::borrowFromNext(Node* node, int index) {
    Node* child = node->children[index];
    Node* sibling = node->children[index + 1];
    child->keys.push_back(node->keys[index]);
    node->keys[index] = sibling->keys.front();
    if (!sibling->leaf) {
        child->children.push_back(sibling->children.front());
        sibling->children.erase(sibling->children.begin());
    }
    sibling->keys.erase(sibling->keys.begin());
}
void BTree::merge(Node* node, int index) {
    Node* child = node->children[index];
    Node* sibling = node->children[index + 1];
    child->keys.push_back(node->keys[index]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
    child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
    node->keys.erase(node->keys.begin() + index);
    node->children.erase(node->children.begin() + index + 1);
    delete sibling;
}
int main() {
    BTree tree(2);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    cout << "[#] B-TREE TARVERSAL: ";
    tree.traverse();
    cout << endl;
    cout << "[#] SEARCHING FOR KEY 6: ";
    cout << (tree.search(6) ? "FOUND" : "NOT FOUND") << endl;
    cout << "[#] REMOVING KEY 6 !!!" << endl;
    tree.remove(6);
    cout << "[#] B-TREE TRAVERSAL: ";
    tree.traverse();
    cout << endl;
    return 0;
}
