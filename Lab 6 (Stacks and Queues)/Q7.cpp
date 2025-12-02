#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) { data = val; next = NULL; }
};

class Stack {
    Node* topNode;
public:
    Stack() { topNode = NULL; }
    void push(const string &val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }
    string top() { return topNode ? topNode->data : ""; }
    void printStack() {
        Node* temp = topNode;
        cout << "Stack (top -> bottom): ";
        while(temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    Stack s;

    string expr[] = {"x", "=", "12", "+", "13", "-", "5", "*", "(", "0.5", "+", "0.5", ")", "+", "1"};
    for(int i = 0; i < 15; i++)
        s.push(expr[i]);
    cout << "Initial stack:\n";
    s.printStack();

    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;

    s.push(to_string(result));
    cout << "\nStack after pushing result: " << endl;
    s.printStack();
    cout << "\nTop of stack (final result): " << s.top() << endl;

    return 0;
}