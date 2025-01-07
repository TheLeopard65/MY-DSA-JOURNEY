#include <iostream>
using namespace std;
class Node {
	protected:
	    int data;
	    Node *left = NULL, *right = NULL;
	public:
	    Node(int value) : data(value), left(NULL), right(NULL) {}
	    friend class Binary_Search_Tree;
};
class Binary_Search_Tree {
private:
    Node *root = NULL;
    Node* insert(int value, Node *temp) {
        if (!temp) return new Node(value);
        else if (value < temp->data) temp->left = insert(value, temp->left);
        else if (value > temp->data) temp->right = insert(value, temp->right);
        return temp;
    }
    void preorder(Node *temp) {
        if (!temp) return;
        cout << temp->data << " - ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder(Node *temp) {
        if (!temp) return;
        inorder(temp->left);
        cout << temp->data << " - ";
        inorder(temp->right);
    }
    void postorder(Node *temp) {
        if (!temp) return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " - ";
    }
    bool search(int target, Node *temp) {
        if (!temp) return false;
        if (temp->data == target) return true;
        else if (target < temp->data) return search(target, temp->left);
        else if (target > temp->data) return search(target, temp->right);
        return false;
    }
    Node* minValue(Node *temp) {
    	if (!temp) return NULL;
        Node *current = temp;
        while (current->left)
            current = current->left;
        return current;
    }
    Node* maxValue(Node *temp) {
    	if (!temp) return NULL;
        Node *current = temp;
        while (current->right)
            current = current->right;
        return current;
    }
    Node* remove(int target, Node *temp) {
        if (!temp) return NULL;
        else if (target < temp->data) temp->left = remove(target, temp->left);
        else if (target > temp->data) temp->right = remove(target, temp->right);
        else {
        	if (!temp->left && !temp->right){
        		delete temp;
        		return NULL;
        	} else if (!temp->left) {
                Node *NTBRL = temp->right;        // NTBRL == Node to be Re-Located
                delete temp;
                return NTBRL;
            } else if (!temp->right) {
                Node *NTBRL = temp->left;
                delete temp;
                return NTBRL;
            }
            Node *MVN = minValue(temp->right);   // MVN = Minimum Value Node
            temp->data = MVN->data;
            temp->right = remove(MVN->data, temp->right);
        }
        return temp;
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
    Binary_Search_Tree tree;
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
