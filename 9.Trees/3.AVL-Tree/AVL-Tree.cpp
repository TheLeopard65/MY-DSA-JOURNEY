#include <iostream>
using namespace std;
class Node {
    protected:
        int data, height;
        Node *left = NULL, *right = NULL;
    public:
        Node(int value) : data(value), left(NULL), right(NULL), height(1) {}
        friend class AVL_Tree;
};
class AVL_Tree {
private:
    Node* root = NULL;
    int height(Node* temp) {
    	return ((temp)? temp->height : 0 );
    }
    int balanceFactor(Node* temp) {
        return ((temp)? (height(temp->left) - height(temp->right)) : 0);
    }
    void updateHeight(Node* temp) {
        temp->height = 1 + max(height(temp->left), height(temp->right));
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* z = y->left;
        y->left = x;
        x->right = z;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        Node* z = y->right;
        y->right = x;
        x->left = z;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    Node* balance(Node* temp) {
        int bf = balanceFactor(temp);
        if (bf > 1) {
            if (balanceFactor(temp->left) < 0)
                temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }
        if (bf < -1) {
            if (balanceFactor(temp->right) > 0)
                temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }
        return temp;
    }
    Node* insert(int value, Node* temp) {
        if (!temp) return new Node(value);
        else if (value < temp->data) temp->left = insert(value, temp->left);
        else if (value > temp->data) temp->right = insert(value, temp->right);
        updateHeight(temp);
        return balance(temp);
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
    Node* remove(int target, Node* temp) {
        if (!temp) return temp;
        else if (target < temp->data) temp->left = remove(target, temp->left);
        else if (target > temp->data) temp->right = remove(target, temp->right);
        else {
        	if (!temp->left && !temp->right) {
        		delete temp;
        		return NULL;
        	} else if (!temp->left) {
                Node* NTBRL = temp->right;
                delete temp;
                return NTBRL;
            } else if (!temp->right) {
                Node* NTBRL = temp->left;
                delete temp;
                return NTBRL;
            }
            Node* MVN = minValue(temp->right);
            temp->data = MVN->data;
            temp->right = remove(MVN->data, temp->right);
        }
        updateHeight(temp);
        return balance(temp);
    }
public:
    void insert(int value) { root = insert(value, root); }
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    bool search(int target) { return search(target, root); }
    void minValue() { cout << minValue(root)->data << endl; }
    void maxValue() { cout << maxValue(root)->data << endl; }
    void remove(int target) { root = remove(target, root); }
};
int main() {
    AVL_Tree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(25);
    tree.insert(23);
    tree.insert(12);
    tree.insert(45);
    tree.insert(5);
    tree.insert(15);
    cout << "[#] PREORDER-TRAVERSAL : ";
    tree.preorder();
    cout << "(END)" << endl;
    cout << "[#] INORDER-TRAVERSAL : ";
    tree.inorder();
    cout << "(END)" << endl;
    cout << "[#] POSTORDER-TRAVERSAL : ";
    tree.postorder();
    cout << "(END)" << endl;
    cout << "[#] IS 40 PRESENT IN THE TREE? : " << (tree.search(40) ? "YES" : "NO") << endl;
    cout << "[#] IS 60 PRESENT IN THE TREE? : " << (tree.search(60) ? "YES" : "NO") << endl;
    tree.remove(20);
    cout << "[#] INORDER-TRAVERSAL AFTER REMOVAL : ";
    tree.inorder();
    cout << "(END)" << endl;
    return 0;
}
