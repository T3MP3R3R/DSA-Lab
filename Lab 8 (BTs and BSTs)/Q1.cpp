#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = NULL;
    }
};

class BST{
public:
    Node* root;
    BST(){ root = NULL; }

    Node* insert(Node* node, int val){
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* find_min(Node* node){
        while (node && node->left) node = node->left;
        return node;
    }

    Node* delete_node(Node* node, int val){
        if (!node) return node;
        if (val < node->data) node->left = delete_node(node->left, val);
        else if (val > node->data) node->right = delete_node(node->right, val);
        else {
            if (!node->left && !node->right){
                delete node;
                return NULL;
            } else if (!node->left){
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right){
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
        return node;
    }

    bool search(Node* node, int val){
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    void inorder(Node* node){
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node){
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node){
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
};

int main(){
    BST tree;
    int choice, val;
    while (true){
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.root = tree.insert(tree.root, val);
                cout << "Node inserted" << endl;
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.root = tree.delete_node(tree.root, val);
                cout << "Node deleted" << endl;
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.search(tree.root, val) ? "Node found" : "Node not found");
                break;

            case 4:
                cout << "In-order Traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 5:
                cout << "Pre-order Traversal: ";
                tree.preorder(tree.root);
                cout << endl;
                break;

            case 6:
                cout << "Post-order Traversal: ";
                tree.postorder(tree.root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}
