#include <iostream>
using namespace std;

class Stack {
public:
    int arr[100];
    int top;

    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 99;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if(isFull()) return;
        arr[++top] = x;
    }

    int pop() {
        if(isEmpty()) return -1;
        return arr[top--];
    }

    int peek() {
        if(isEmpty()) return -1;
        return arr[top];
    }

    void display() {
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

struct Node {
    int data;
    Node* next;
};

class LLStack {
public:
    Node* top;

    LLStack() {
        top = NULL;
    }

    void push(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = top;
        top = n;
    }

    int pop() {
        if(top == NULL) return -1;
        Node* t = top;
        int val = t->data;
        top = top->next;
        delete t;
        return val;
    }

    int peek() {
        if(top == NULL) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        Node* t = top;
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};
