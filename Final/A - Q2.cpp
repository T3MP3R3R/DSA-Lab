#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* left;
    Node* right;
    Node(int p) { price = p; left = right = NULL; }
};

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    Node* succ = NULL;
    Node* curr = root;
    while (curr) {
        if (node->price < curr->price) {
            succ = curr;
            curr = curr->left;
        } else if (node->price > curr->price) {
            curr = curr->right;
        } else {
            if (curr->right) {
                curr = curr->right;
                while (curr->left) curr = curr->left;
                succ = curr;
            }
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    Node* pred = NULL;
    Node* curr = root;
    while (curr) {
        if (node->price > curr->price) {
            pred = curr;
            curr = curr->right;
        } else if (node->price < curr->price) {
            curr = curr->left;
        } else {
            if (curr->left) {
                curr = curr->left;
                while (curr->right) curr = curr->right;
                pred = curr;
            }
            break;
        }
    }
    return pred;
}

int countPairs(Node* root, int target) {
    Node* left = minNode(root);
    Node* right = maxNode(root);
    int count = 0;

    while (left && right && left != right) {
        int sum = left->price + right->price;
        if (sum == target) {
            count++;
            left = inorderSuccessor(root, left);
            right = inorderPredecessor(root, right);
        } else if (sum < target) {
            left = inorderSuccessor(root, left);
        } else {
            right = inorderPredecessor(root, right);
        }
        if (left && right && left->price >= right->price) break;
    }

    return count;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int rootPrice = root->price;
    int result = countPairs(root, rootPrice);
    cout << "Number of distinct pairs: " << result << endl;

    return 0;
}