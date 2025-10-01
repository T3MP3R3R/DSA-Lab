#include <iostream>
using namespace std;

struct Node{
    int data; Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void insert(Node*& head, int val){
    Node* newNode = new Node{val};
    if (!head) { 
        head = newNode; 
        return;
    }
    Node* temp=head;
    while (temp->next) temp =temp->next;
    temp->next = newNode;
}

void displayRev(Node* head){
    if (!head) return;
    displayRev(head->next);
    cout << head->data << " ";
}

int main(){
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    cout << "List (reversed): ";
    displayRev(head);

    return 0;
}