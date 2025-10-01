#include <iostream>
using namespace std;

struct Node{
    int data; Node* next;
};

void insert(Node*& head, int val){
    Node* newNode = new Node{val, NULL};
    if (!head) { 
        head = newNode; 
        return;
    }
    Node* temp=head;
    while (temp->next) temp =temp->next;
    temp->next = newNode;
}

void displayReverse(Node* head){
    if (!head) return;
    displayReverse(head->next);
    cout << head->data << " ";
}

int main(){
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    cout << "List (reversed): ";
    displayReverse(head);

    return 0;
}