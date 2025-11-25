#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

# Circular LL

class CLL {
public:
    Node* head;

    CLL() {
        head = NULL;
    }

    Node* createNode(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;
        return n;
    }

    void insertHead(int x) {
        Node* n = createNode(x);
        if(head == NULL) {
            head = n;
            n->next = n;
            return;
        }
        Node* t = head;
        while(t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }

    void insertTail(int x) {
        Node* n = createNode(x);
        if(head == NULL) {
            head = n;
            n->next = n;
            return;
        }
        Node* t = head;
        while(t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void insertPos(int x, int pos) {
        if(pos == 0) {
            insertHead(x);
            return;
        }
        Node* t = head;
        for(int i=0;i<pos-1 && t->next!=head;i++) t = t->next;
        if(t == NULL) return;
        Node* n = createNode(x);
        n->next = t->next;
        t->next = n;
    }

    void deleteHead() {
        if(head == NULL) return;
        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* t = head;
        while(t->next != head) t = t->next;
        Node* d = head;
        head = head->next;
        t->next = head;
        delete d;
    }

    void deleteTail() {
        if(head == NULL) return;
        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* t = head;
        while(t->next->next != head) t = t->next;
        Node* d = t->next;
        t->next = head;
        delete d;
    }

    void deletePos(int pos) {
        if(pos == 0) {
            deleteHead();
            return;
        }
        Node* t = head;
        for(int i=0;i<pos-1 && t->next!=head;i++) t = t->next;
        Node* d = t->next;
        if(d == head) return;
        t->next = d->next;
        delete d;
    }

    Node* search(int x) {
        if(head == NULL) return NULL;
        Node* t = head;
        do {
            if(t->data == x) return t;
            t = t->next;
        } while(t != head);
        return NULL;
    }

    void display() {
        if(head == NULL) {
            cout << endl;
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while(t != head);
        cout << endl;
    }
};
