#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVL {
public:
    Node* root;

    AVL() {
        root = NULL;
    }

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* createNode(int x) {
        Node* n = new Node;
        n->data = x;
        n->left = n->right = NULL;
        n->height = 1;
        return n;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* insert(Node* node, int x) {
        if(!node) return createNode(x);

        if(x < node->data) node->left = insert(node->left, x);
        else if(x > node->data) node->right = insert(node->right, x);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // LL
        if(balance > 1 && x < node->left->data) return rightRotate(node);

        // RR
        if(balance < -1 && x > node->right->data) return leftRotate(node);

        // LR
        if(balance > 1 && x > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if(balance < -1 && x < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if(!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};
