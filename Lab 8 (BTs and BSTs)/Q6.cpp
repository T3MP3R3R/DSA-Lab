#include <iostream>
using namespace std;

class Node{
public:
    int id;
    int qty;
    Node* left;
    Node* right;

    Node(int i, int q){
        id = i;
        qty = q;
        left = right = NULL;
    }
};

class BST{
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* r, int id, int qty) {
        if (r == NULL) {
            r = new Node(id, qty);
        }
        else if (id < r->id) {
            r->left = insert(r->left, id, qty);
        }
        else if (id > r->id) {
            r->right = insert(r->right, id, qty);
        }
        else {
            r->qty = qty;
        }
        return r;
    }

    void insertProduct(int id, int qty) {
        root = insert(root, id, qty);
    }

    Node* search(Node* r, int id) {
        if (r == NULL) return NULL;

        if (id == r->id) return r;
        else if (id < r->id) return search(r->left, id);
        else return search(r->right, id);
    }

    Node* searchProduct(int id) {
        return search(root, id);
    }

    void maxProduct(Node* r, int &maxQty, int &maxID) {
        if (r == NULL) return;

        if (r->qty > maxQty) {
            maxQty = r->qty;
            maxID = r->id;
        }

        maxProduct(r->left, maxQty, maxID);
        maxProduct(r->right, maxQty, maxID);
    }

    void getMaxProduct() {
        if (root == NULL) {
            cout << "Inventory Empty " << endl;
            return;
        }

        int maxQty = -1;
        int maxID = -1;

        maxProduct(root, maxQty, maxID);

        cout << "Product with highest quantity: " << endl;
        cout << "ID: " << maxID << ", Quantity: " << maxQty << endl;
    }
};

int main() {
    BST t;
    t.insertProduct(10, 30);
    t.insertProduct(5, 12);
    t.insertProduct(20, 50);
    t.insertProduct(7, 70);

    Node* p = t.searchProduct(7);
    if (p != NULL)
        cout << "Found Product " << p->id << " with qty " << p->qty << endl;

    t.getMaxProduct();

    return 0;
}