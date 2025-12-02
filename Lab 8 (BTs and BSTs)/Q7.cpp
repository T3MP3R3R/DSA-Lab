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

    int count(Node* r) {
        if (r == NULL) return 0;
        return 1 + count(r->left) + count(r->right);
    }

    void inorderFind(Node* r, int &countNow, int target1, int target2,
                     int &val1, int &val2) 
    {
        if (r == NULL) return;

        inorderFind(r->left, countNow, target1, target2, val1, val2);

        countNow++;

        if (countNow == target1) val1 = r->data;
        if (countNow == target2) val2 = r->data;

        inorderFind(r->right, countNow, target1, target2, val1, val2);
    }

    float findMedian() {
        int n = count(root);

        if (n == 0) return -1;

        // If odd → both target1 and target2 same
        int target1, target2;

        if (n % 2 == 1) {
            target1 = target2 = (n + 1) / 2;
        }
        else {
            target1 = n / 2;
            target2 = target1 + 1;
        }

        int val1 = -1, val2 = -1;
        int countNow = 0;

        inorderFind(root, countNow, target1, target2, val1, val2);

        return (val1 + val2) / 2.0;
    }
};

int main() {
    BST t;
    t.insertNode(20);
    t.insertNode(10);
    t.insertNode(30);
    t.insertNode(5);
    t.insertNode(15);
    cout << "Median = " << t.findMedian() << endl;

    return 0;
}