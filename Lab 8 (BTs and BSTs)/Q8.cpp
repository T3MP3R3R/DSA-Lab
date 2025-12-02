#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

class BST{
public:
    Node* root;

    BST(){
        root = NULL;
    }

    Node* insert(Node* r, int val) {
        if (r == NULL) return new Node(val);

        if (val < r->data) 
            r->left = insert(r->left, val);
        else
            r->right = insert(r->right, val);

        return r;
    }

    void insertNode(int val) {
        root = insert(root, val);
    }

    int countInRange(Node* r, int a, int b) {
        if (r == NULL) return 0;

        // Node is inside range → count it + explore both children
        if (r->data >= a && r->data <= b) {
            return 1 + countInRange(r->left, a, b)
                     + countInRange(r->right, a, b);
        }

        if (r->data < a) {
            return countInRange(r->right, a, b);
        }

        return countInRange(r->left, a, b);
    }
};

int main() {
    BST t;
    t.insertNode(10);
    t.insertNode(5);
    t.insertNode(50);
    t.insertNode(1);
    t.insertNode(40);
    t.insertNode(100);

    int a = 5, b = 45;
    cout << "Nodes in range = " << t.countInRange(t.root, a, b) << endl;

    return 0;
}