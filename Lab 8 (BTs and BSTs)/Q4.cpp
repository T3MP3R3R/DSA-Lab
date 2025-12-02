#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    bool search(Node* node, int value) {
        if (node == NULL) return false;
        if (node->data == value) return true;

        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void Insert(int value) {
        root = insert(root, value);
    }

    void SearchOrInsert(int value) {
        if (search(root, value)) {
            cout << "Value already exists in the tree.\n";
        } 
        else {
            cout << "Value not found. Inserting " << value << "...\n";
            root = insert(root, value);
            cout << "Updated Tree (Inorder): ";
            inorder(root);
            cout << endl;
        }
    }

    void PrintTree() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.Insert(30);
    tree.Insert(15);
    tree.Insert(50);
    tree.Insert(10);
    tree.Insert(20);

    cout << "Initial Tree (Inorder): ";
    tree.PrintTree();

    int val;
    cout << "Enter value to search or insert: ";
    cin >> val;

    tree.SearchOrInsert(val);

    return 0;
}