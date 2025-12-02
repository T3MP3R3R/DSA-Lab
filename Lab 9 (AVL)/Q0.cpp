#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
    int height;
};

int height(Node* n){
    if (!n) return 0;
    return n->height;
}

int getBalance(Node* n){
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* balance(Node* root){
    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int bal = getBalance(root);

    if (bal > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (bal < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (bal > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* convertA(){
    Node* root = new Node{10, nullptr, nullptr, 1};
    root->left = new Node{6, nullptr, nullptr, 1};
    root->left->left  = new Node{4, nullptr, nullptr, 1};
    root->left->right = new Node{8, nullptr, nullptr, 1};
    return balance(root);
}

Node* convertB(){
    Node* root = new Node{10, nullptr, nullptr, 1};
    root->right = new Node{16, nullptr, nullptr, 1};
    root->right->left  = new Node{12, nullptr, nullptr, 1};
    root->right->right = new Node{18, nullptr, nullptr, 1};
    return balance(root);
}

int main(){
    convertA();
    convertB();
    return 0;
}
