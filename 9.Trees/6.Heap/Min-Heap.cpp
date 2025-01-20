#include <iostream>
#include <vector>
using namespace std;
class Node {
    protected:
        int data;
        Node *left = NULL, *right = NULL;
    public:
        Node(int value) : data(value), left(NULL), right(NULL) {}
        friend class MinHeap;
};
class MinHeap {
    private:
        Node* root = NULL;
        Node* insert(int value, Node* temp) {
            if (!temp) return new Node(value);
            if (!temp->left) temp->left = insert(value, temp->left);
            else if (!temp->right) temp->right = insert(value, temp->right);
            if (temp->left && temp->left->data < temp->data) swap(temp->data, temp->left->data);
            if (temp->right && temp->right->data < temp->data) swap(temp->data, temp->right->data);
            return temp;
        }
        void preorder(Node* temp) {
            if (!temp) return;
            cout << temp->data << " - ";
            preorder(temp->left);
            preorder(temp->right);
        }
        void inorder(Node* temp) {
            if (!temp) return;
            inorder(temp->left);
            cout << temp->data << " - ";
            inorder(temp->right);
        }
        void postorder(Node* temp) {
            if (!temp) return;
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " - ";
        }
        Node* search(int target, Node* temp) {
            if (!temp) return NULL;
            if (temp->data == target) return temp;
            Node* leftSearch = search(target, temp->left);
            if (leftSearch) return leftSearch;
            return search(target, temp->right);
        }
        Node* remove(int target, Node* temp) {
            if (!temp) return temp;
            if (temp->data == target) {
                if (!temp->left && !temp->right) {
                    delete temp;
                    return NULL;
                } else if (!temp->left) {
                    Node* tempRight = temp->right;
                    delete temp;
                    return tempRight;
                } else if (!temp->right) {
                    Node* tempLeft = temp->left;
                    delete temp;
                    return tempLeft;
                } else {
                    Node* tempRight = temp->right;
                    delete temp;
                    return tempRight;
                }
            }
            temp->left = remove(target, temp->left);
            temp->right = remove(target, temp->right);
            return temp;
        }
    public:
        void insert(int value) { root = insert(value, root); }
        void preorder() {
            cout << "[#] PREORDER-TRAVERSAL: ";
            preorder(root);
            cout << "(END)" << endl;
        }
        void inorder() {
            cout << "[#] INORDER-TRAVERSAL: ";
            inorder(root);
            cout << "(END)" << endl;
        }
        void postorder() {
            cout << "[#] POSTORDER-TRAVERSAL: ";
            postorder(root);
            cout << "(END)" << endl;
        }
        bool search(int target) { return (search(target, root) != NULL); }
        void remove(int target) { root = remove(target, root); }
};
int main() {
    MinHeap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.insert(40);
    heap.insert(25);
    heap.insert(23);
    heap.insert(12);
    heap.insert(45);
    heap.insert(5);
    heap.insert(15);
    heap.preorder();
    heap.inorder();
    heap.postorder();
    cout << "[#] IS 40 PRESENT IN THE TREE? : " << (heap.search(40) ? "YES" : "NO") << endl;
    cout << "[#] IS 60 PRESENT IN THE TREE? : " << (heap.search(60) ? "YES" : "NO") << endl;
    heap.remove(20);
    heap.inorder();
    return 0;
}
