#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

# Singly LL

class LinkedList {
public:
    Node* head;

    LinkedList() {
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
        n->next = head;
        head = n;
    }

    void insertTail(int x) {
        Node* n = createNode(x);
        if(head == NULL) {
            head = n;
            return;
        }
        Node* t = head;
        while(t->next != NULL) t = t->next;
        t->next = n;
    }

    void insertPos(int x, int pos) {
        if(pos == 0) {
            insertHead(x);
            return;
        }
        Node* t = head;
        for(int i=0;i<pos-1 && t!=NULL;i++) t = t->next;
        if(t == NULL) return;
        Node* n = createNode(x);
        n->next = t->next;
        t->next = n;
    }

    void deleteHead() {
        if(head == NULL) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteTail() {
        if(head == NULL) return;
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* t = head;
        while(t->next->next != NULL) t = t->next;
        Node* d = t->next;
        t->next = NULL;
        delete d;
    }

    void deletePos(int pos) {
        if(pos == 0) {
            deleteHead();
            return;
        }
        Node* t = head;
        for(int i=0;i<pos-1 && t!=NULL;i++) t = t->next;
        if(t == NULL || t->next == NULL) return;
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }

    Node* search(int x) {
        Node* t = head;
        while(t != NULL) {
            if(t->data == x) return t;
            t = t->next;
        }
        return NULL;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    void display() {
        Node* t = head;
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};
