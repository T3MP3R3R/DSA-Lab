#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class StackLL {
    Node* top;
public:
    StackLL() { top = nullptr; }
    bool isEmpty() { return top == nullptr; }

    void push(int val) {
        Node* n = new Node(val);
        n->next = top;
        top = n;
    }

    void pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return; }
        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return top->data;
    }

    void display() {
        if (isEmpty()) { cout << "Stack is empty\n"; return; }
        Node* temp = top;
        cout << "Stack: ";
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    StackLL s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.display();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}