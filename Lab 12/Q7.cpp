#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* createNode(int x) {
        Node* n = new Node;
        n->data = x;
        n->left = n->right = NULL;
        return n;
    }

    Node* insert(Node* node, int x) {
        if(node == NULL) return createNode(x);
        if(x < node->data) node->left = insert(node->left, x);
        else node->right = insert(node->right, x);
        return node;
    }

    Node* search(Node* node, int x) {
        if(node == NULL || node->data == x) return node;
        if(x < node->data) return search(node->left, x);
        else return search(node->right, x);
    }

    Node* minValueNode(Node* node) {
        Node* curr = node;
        while(curr && curr->left != NULL) curr = curr->left;
        return curr;
    }

    Node* deleteNode(Node* node, int x) {
        if(node == NULL) return node;

        if(x < node->data) node->left = deleteNode(node->left, x);
        else if(x > node->data) node->right = deleteNode(node->right, x);
        else {
            if(node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if(node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if(node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if(node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};
