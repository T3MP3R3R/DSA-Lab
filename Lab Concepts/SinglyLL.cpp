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

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = n;
        }
    }

    void insertAtFront(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
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
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtEnd(14);
    sll.insertAtFront(12);
    sll.insertAtEnd(20);
    sll.insertAtFront(10);

    cout << "Singly Linked List: ";
    sll.display();

    cout << "Searching 12: " << (sll.search(12) ? "Found" : "Not Found") << endl;
    cout << "Searching 15: " << (sll.search(15) ? "Found" : "Not Found") << endl;

    sll.deleteAtFront();
    cout << "After deleting front: ";
    sll.display();

    sll.deleteAtEnd();
    cout << "After deleting end: ";
    sll.display();

    return 0;
}