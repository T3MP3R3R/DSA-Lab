#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Circular {
public:
    Node* head;
    Node* tail;

    Circular() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
            tail->next = head;
        } else {
            tail->next = n;
            tail = n;
            tail->next = head;
        }
    }

    void insertAtFront(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
            tail->next = head;
        } else {
            n->next = head;
            head = n;
            tail->next = head;
        }
    }

    bool search(int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deleteAtFront() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        delete tail;
        tail = curr;
        tail->next = head;
    }
};

int main() {
    Circular cll;
    cll.insertAtEnd(14);
    cll.insertAtFront(12);
    cll.insertAtEnd(20);
    cll.insertAtFront(10);

    cout << "Current Circular List: ";
    cll.display();

    cout << "Searching 12: " << (cll.search(12) ? "Found" : "Not Found") << endl;
    cout << "Searching 15: " << (cll.search(15) ? "Found" : "Not Found") << endl;

    cll.deleteAtFront();
    cout << "After deleting front: ";
    cll.display();

    cll.deleteAtEnd();
    cout << "After deleting end: ";
    cll.display();

    return 0;
}