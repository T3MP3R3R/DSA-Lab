#include <iostream>
using namespace std;

struct Node{
    int data; Node* prev; Node* next;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}

};

void insert(Node*& head, int pos, int val){
    Node* newNode = new Node{val};
    if (pos == 1){
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) return;
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void del(Node*& head, int pos){
    if (!head) return;
    Node* temp = head;
    if (pos == 1){
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void display(Node* head){
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 1, 10);
    insert(head, 2, 20);
    insert(head, 3, 30);
    insert(head, 2, 15);
    insert(head, 1, 5);
    display(head);
    del(head, 1);
    del(head, 3);
    display(head);

    return 0;
}