#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val){ data = val; left = right = nullptr; height = 1; }
};

class AVL{
public:
    Node* root;

    AVL(){
        root = nullptr;
    }

    int height(Node* n){
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n){
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);

        // LL
        if (balance > 1 && key < node->left->data) return rightRotate(node);

        // RR
        if (balance < -1 && key > node->right->data) return leftRotate(node);

        // LR
        if (balance > 1 && key > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && key < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node){
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main(){
    AVL t;

    int elements[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : elements)
        t.root = t.insert(t.root, key);
    t.root = t.insert(t.root, 55);
    t.root = t.leftRotate(t.root);

    cout << "Inorder traversal: " << endl;
    t.inorder(t.root);
    cout << endl;

    return 0;
}
