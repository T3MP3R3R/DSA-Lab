#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char url[100];
    Node* next;
    Node(const char* u) {
        strcpy(url, u);
        next = NULL;
    }
};

struct StackNode {
    char url[100];
    StackNode* next;
    StackNode(const char* u) {
        strcpy(url, u);
        next = NULL;
    }
};

class Browser {
    Node* historyHead;
    StackNode* backStack;
    
public:
    Browser() {
        historyHead = NULL;
        backStack = NULL;
    }

    void visit(const char* url) {
        Node* newNode = new Node(url);
        newNode->next = historyHead;
        historyHead = newNode;

        StackNode* newStackNode = new StackNode(url);
        newStackNode->next = backStack;
        backStack = newStackNode;

        cout << "Visited: " << url << endl;
    }

    void back(int n) {
        for (int i = 0; i < n; i++){
            if (backStack == NULL) {
                cout << "No more pages to go back.\n";
                return;
            }

            StackNode* tempStack = backStack;
            cout << "Going back from: " << tempStack->url << endl;
            backStack = backStack->next;
            delete tempStack;

            if (historyHead != NULL) {
                Node* tempHistory = historyHead;
                historyHead = historyHead->next;
                delete tempHistory;
            }
        }

        if (historyHead != NULL)
            cout << "Current page: " << historyHead->url << endl;
        else
            cout << "No pages left in history " << endl;
    }

    void printHistory() {
        cout << "\nBrowsing History: " << endl;
        Node* temp = historyHead;
        while (temp != NULL) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Browser b;

    b.visit("Google");
    b.visit("Facebook");
    b.visit("Twitter");
    b.visit("LinkedIn");
    b.visit("Instagram");

    b.printHistory();

    b.back(2);

    b.printHistory();

    return 0;
}