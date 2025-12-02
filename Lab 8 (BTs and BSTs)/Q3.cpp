#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int score;
};

struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) {
        data = s;
        left = right = NULL;
    }
};

class StudentBST {
    Node* root;

    Node* insert(Node* node, Student s) {
        if (node == NULL) return new Node(s);

        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else
            node->right = insert(node->right, s);

        return node;
    }

    Node* search(Node* node, string name) {
        if (node == NULL || node->data.name == name)
            return node;

        if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteByScore(Node* node) {
        if (node == NULL) return NULL;

        node->left = deleteByScore(node->left);
        node->right = deleteByScore(node->right);

        if (node->data.score < 10) {
            if (node->left == NULL) {
                Node* r = node->right;
                delete node;
                return r;
            }
            else if (node->right == NULL) {
                Node* l = node->left;
                delete node;
                return l;
            }
            else {
                Node* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = deleteNode(node->right, minNode->data.name);
                return node;
            }
        }

        return node;
    }

    Node* deleteNode(Node* node, string name) {
        if (node == NULL) return NULL;

        if (name < node->data.name)
            node->left = deleteNode(node->left, name);
        else if (name > node->data.name)
            node->right = deleteNode(node->right, name);
        else {
            // normal BST delete
            if (node->left == NULL) {
                Node* r = node->right;
                delete node;
                return r;
            }
            else if (node->right == NULL) {
                Node* l = node->left;
                delete node;
                return l;
            }
            else {
                Node* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = deleteNode(node->right, minNode->data.name);
            }
        }
        return node;
    }

    void findMaxScore(Node* node, Student &best) {
        if (node == NULL) return;

        if (node->data.score > best.score)
            best = node->data;

        findMaxScore(node->left, best);
        findMaxScore(node->right, best);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.name << " - Roll: " << node->data.roll
             << " Score: " << node->data.score << endl;
        inorder(node->right);
    }

public:
    StudentBST() {
        root = NULL;
    }

    void Insert(Student s) {
        root = insert(root, s);
    }

    void Search(string name) {
        Node* res = search(root, name);
        if (res == NULL)
            cout << "Record not found\n";
        else
            cout << "Found: " << res->data.name << " (Roll " << res->data.roll
                 << ", Score " << res->data.score << ")\n";
    }

    void DeleteScoreBelow10() {
        root = deleteByScore(root);
    }

    void MaxScore() {
        if (root == NULL) {
            cout << "Tree empty" << endl;
            return;
        }

        Student best;
        best.score = -1;

        findMaxScore(root, best);

        cout << "Highest Scoring Student: " << best.name
             << " (Roll " << best.roll
             << ", Score " << best.score << ")" << endl;
    }

    void Display() {
        inorder(root);
    }
};

int main() {
    Student all[10] = {
        {"Ali", 1, 12},
        {"Sara", 2, 5},
        {"Bilal", 3, 18},
        {"Hina", 4, 9},
        {"Danish", 5, 22},
        {"Kiran", 6, 3},
        {"Omar", 7, 14},
        {"Zara", 8, 25},
        {"Farah", 9, 7},
        {"Imran", 10, 19}
    };

    StudentBST bst;
    bst.Insert(all[0]);
    bst.Insert(all[3]);
    bst.Insert(all[7]);
    bst.Insert(all[2]);
    bst.Insert(all[9]);
    bst.Insert(all[5]);
    bst.Insert(all[1]);

    cout << "BST Inorder Traversal: " << endl;
    bst.Display();

    cout << "\nSearching for Omar: " << endl;
    bst.Search("Omar");

    cout << "\nRemoving students with score < 10... " << endl;
    bst.DeleteScoreBelow10();

    cout << "\nBST After Deletion: " << endl;
    bst.Display();

    cout << "\nStudent with Max Score: " << endl;
    bst.MaxScore();

    return 0;
}