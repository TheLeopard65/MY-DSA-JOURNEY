#include <iostream>
using namespace std;
enum Color { RED, BLACK };
class Node {
	protected:
	    int data;
	    Color color;
	    Node *left = NULL, *right = NULL, *parent = NULL;
	public:
	    Node(int value) : data(value), color(RED), left(NULL), right(NULL), parent(NULL) {}
	    friend class RedBlackTree;
};
class RedBlackTree {
private:
    Node* root = NULL;
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NULL) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NULL) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
    void fixInsert(Node* k) {
        Node* u;
        while (k->parent && k->parent->color == RED) {
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right;
                if (u && u->color == RED) {
                    k->parent->color = BLACK;
                    u->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->left;
                if (u && u->color == RED) {
                    k->parent->color = BLACK;
                    u->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }
    Node* insertHelper(Node* root, int value) {
        if (root == NULL) return new Node(value);
        if (value < root->data) {
            root->left = insertHelper(root->left, value);
            root->left->parent = root;
        } else {
            root->right = insertHelper(root->right, value);
            root->right->parent = root;
        }
        return root;
    }
    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
            root->color = BLACK;
            return;
        }
        Node* newNode = insertHelper(root, value);
        newNode->color = RED;
        fixInsert(newNode);
    }
    void inorder(Node* temp) {
        if (!temp) return;
        inorder(temp->left);
        cout << temp->data << " - ";
        inorder(temp->right);
    }
    bool search(int target, Node* temp) {
        if (!temp) return false;
        if (temp->data == target) return true;
        else if (target < temp->data) return search(target, temp->left);
        else if (target > temp->data) return search(target, temp->right);
        return false;
    }
    Node* minValue(Node* temp) {
        if (!temp) return NULL;
        while (temp->left)
            temp = temp->left;
        return temp;
    }
    Node* maxValue(Node* temp) {
        if (!temp) return NULL;
        while (temp->right)
            temp = temp->right;
        return temp;
    }
public:
    RedBlackTree() : root(NULL) {}
    void insertRB(int value) { insert(value); }
    void preorder(Node* temp) {
        if (!temp) return;
        cout << temp->data << " - ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder() {
        inorder(root);
        cout << "(END)" << endl;
    }
    void preorder() {
        preorder(root);
        cout << "(END)" << endl;
    }
    bool search(int target) { return search(target, root); }
    void minValue() { cout << minValue(root)->data << endl; }
    void maxValue() { cout << maxValue(root)->data << endl; }
};
int main() {
    RedBlackTree tree;
    tree.insertRB(10);
    tree.insertRB(20);
    tree.insertRB(30);
    tree.insertRB(40);
    tree.insertRB(25);
    tree.insertRB(23);
    tree.insertRB(12);
    tree.insertRB(45);
    tree.insertRB(5);
    tree.insertRB(15);
    cout << "[#] PREORDER-TRAVERSAL : ";
    tree.preorder();
    cout << "[#] INORDER-TRAVERSAL : ";
    tree.inorder();
    cout << "[#] IS 40 PRESENT IN THE TREE? : " << (tree.search(40) ? "YES" : "NO") << endl;
    cout << "[#] IS 60 PRESENT IN THE TREE? : " << (tree.search(60) ? "YES" : "NO") << endl;
    cout << "[#] The LOWEST VALUE IN THE TREE IS : ";
    tree.minValue();
    cout << "[#] The HIGHEST VALUE IN THE TREE IS : ";
    tree.maxValue();
    return 0;
}
