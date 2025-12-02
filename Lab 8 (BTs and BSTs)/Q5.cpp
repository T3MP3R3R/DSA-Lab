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
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void Insert(int value) {
        root = insert(root, value);
    }

    bool isBST(Node* node, int minVal, int maxVal) {
        if (node == NULL) return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return isBST(node->left, minVal, node->data) &&
               isBST(node->right, node->data, maxVal);
    }

    bool CheckBST() {
        return isBST(root, -1000000, 1000000);
    }
};

int main() {
    BST bst;
    bst.root = new Node(10);
    bst.root->left = new Node(5);
    bst.root->right = new Node(20);
    bst.root->left->left = new Node(25);
    bst.root->left->right = new Node(30);

    if (bst.CheckBST())
        cout << "This is a Binary Search Tree\n";
    else
        cout << "This is NOT a Binary Search Tree\n";

    return 0;
}