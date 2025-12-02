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

    AVL(){ root = nullptr; }

    int height(Node* n){ return n ? n->height : 0; }

    int balanceFactor(Node* n){ return n ? height(n->left) - height(n->right) : 0; }

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
        if (key < node->data) node->left = insert(node->left, key);
        else if (key > node->data) node->right = insert(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->data) return rightRotate(node);
        if (balance < -1 && key > node->right->data) return leftRotate(node);
        if (balance > 1 && key > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
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

    void kthSmallest(Node* node, int k, int &count, int &result){
        if (!node) return;
        kthSmallest(node->left, k, count, result);
        count++;
        if (count == k){ result = node->data; return; }
        kthSmallest(node->right, k, count, result);
    }

    void kthLargest(Node* node, int k, int &count, int &result){
        if (!node) return;
        kthLargest(node->right, k, count, result);
        count++;
        if (count == k){ result = node->data; return; }
        kthLargest(node->left, k, count, result);
    }
};

int main(){
    AVL t;
    int elements[] = {10, 5, 15, 3, 7, 12};

    for(int key : elements)
        t.root = t.insert(t.root, key);

    cout << "Inorder traversal: ";
    t.inorder(t.root);
    cout << endl;

    cout << "Left subtree height of root: " << t.height(t.root->left) << endl;
    cout << "Right subtree height of root: " << t.height(t.root->right) << endl;

    int k; string c;
    cout << "Enter k: "; cin >> k;
    if (k == 1){
        c = "st";
    } else if (k == 2){
        c = "nd";
    } else if (k == 3){
        c = "rd";
    } else c = "th";
    
    int count = 0, result = -1;
    t.kthSmallest(t.root, k, count, result);
    cout << k << c << " smallest value: " << result << endl;

    count = 0; result = -1;
    t.kthLargest(t.root, k, count, result);
    cout << k << c << " largest value: " << result << endl;

    return 0;
}
