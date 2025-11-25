#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

# Doubly LL

class DLL {
public:
    Node* head;

    DLL() {
        head = NULL;
    }

    Node* createNode(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;
        n->prev = NULL;
        return n;
    }

    void insertHead(int x) {
        Node* n = createNode(x);
        if(head == NULL) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
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
        n->prev = t;
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
        n->prev = t;
        if(t->next != NULL) t->next->prev = n;
        t->next = n;
    }

    void deleteHead() {
        if(head == NULL) return;
        Node* t = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
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
        while(t->next != NULL) t = t->next;
        t->prev->next = NULL;
        delete t;
    }

    void deletePos(int pos) {
        if(pos == 0) {
            deleteHead();
            return;
        }
        Node* t = head;
        for(int i=0;i<pos && t!=NULL;i++) t = t->next;
        if(t == NULL) return;
        t->prev->next = t->next;
        if(t->next != NULL) t->next->prev = t->prev;
        delete t;
    }

    Node* search(int x) {
        Node* t = head;
        while(t != NULL) {
            if(t->data == x) return t;
            t = t->next;
        }
        return NULL;
    }

    void displayForward() {
        Node* t = head;
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if(head == NULL) return;
        Node* t = head;
        while(t->next != NULL) t = t->next;
        while(t != NULL) {
            cout << t->data << " ";
            t = t->prev;
        }
        cout << endl;
    }
};
