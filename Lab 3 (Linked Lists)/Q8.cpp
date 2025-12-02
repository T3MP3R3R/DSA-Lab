#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

struct DoublyLinkedList{
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(NULL), tail(NULL) {}
    void append(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printList(){
        Node* temp = head;
        while (temp){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void concatenate(DoublyLinkedList& L, DoublyLinkedList& M){
    if (!L.head){
        L.head = M.head;
        L.tail = M.tail;
        return;
    }
    if (!M.head) return;

    L.tail->next = M.head;
    M.head->prev = L.tail;
    L.tail = M.tail;
}

int main(){
    DoublyLinkedList L, M;
    
    L.append(1); L.append(2); L.append(3);
    M.append(4); M.append(5); M.append(6);
    cout << "List L: ";
    L.printList();
    cout << "List M: ";
    M.printList();
    concatenate(L, M);
    cout << "After concatenation: ";
    L.printList();
    return 0;
}