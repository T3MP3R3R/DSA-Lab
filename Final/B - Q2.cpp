#include <iostream>
using namespace std;

struct AVLNode {
    long long key;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(long long k) : key(k), height(1), left(NULL), right(NULL) {}
};

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insert(AVLNode* node, long long key) {
    if (!node) return new AVLNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left) current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, long long key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) { temp = root; root = NULL; }
            else *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(AVLNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

class FixedWindowDataCache {
    AVLNode* root;
    int N_max;
    int currentSize;
public:
    FixedWindowDataCache(int N) : root(NULL), N_max(N), currentSize(0) {}

    void process_new_tick(long long new_timestamp) {
        root = insert(root, new_timestamp);
        currentSize++;
        if (currentSize > N_max) {
            AVLNode* minNode = minValueNode(root);
            root = deleteNode(root, minNode->key);
            currentSize--;
        }
    }

    void printWindow() {
        cout << "Current timestamps: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    FixedWindowDataCache cache(4);

    long long ticks[] = {100, 200, 300, 400};
    for (int i = 0; i < 4; i++) cache.process_new_tick(ticks[i]);

    cout << "Before new tick: ";
    cache.printWindow();

    cache.process_new_tick(500);

    cout << "After new tick: ";
    cache.printWindow();

    return 0;
}