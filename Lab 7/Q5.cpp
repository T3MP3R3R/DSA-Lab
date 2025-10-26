#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node* &head, int data){
    Node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head){
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void swap(Node* a, Node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* start, Node* end){
    if (!start || start == end) return start;
    int pivot = end->data;
    Node* p = start;
    Node* q = start;
    while (q != end){
        if (q->data < pivot){
            swap(p, q);
            p = p->next;
        }
        q = q->next;
    }
    swap(p, end);
    return p;
}

void quickSort(Node* start, Node* end) {
    if (!start || start == end || !end) return;

    Node* pivot = partition(start, end);

    if (pivot != start){ // before pivot
        Node* temp = start;
        while (temp->next != pivot) temp = temp->next;
        quickSort(start, temp);
    }
    if (pivot != end) // after pivot
        quickSort(pivot->next, end);
}

Node* getTail(Node* head){
    while (head && head->next) head = head->next;
    return head;
}

int main(){
    Node* head = NULL;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    for (int i = 0; i < 7; i++) append(head, arr[i]);
    Node* tail = getTail(head);
    quickSort(head, tail);
    
    cout << "Sorted: ";
    printList(head);
    return 0;
}
