#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void insertAtFront(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteAtFront() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(14);
    dll.insertAtFront(12);
    dll.insertAtEnd(20);
    dll.insertAtFront(10);

    cout << "Doubly Linked List: ";
    dll.display();

    cout << "Searching 12: " << (dll.search(12) ? "Found" : "Not Found") << endl;
    cout << "Searching 15: " << (dll.search(15) ? "Found" : "Not Found") << endl;

    dll.deleteAtFront();
    cout << "After deleting front: ";
    dll.display();

    dll.deleteAtEnd();
    cout << "After deleting end: ";
    dll.display();

    return 0;
}