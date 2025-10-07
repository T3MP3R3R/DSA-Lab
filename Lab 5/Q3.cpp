#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n = NULL) : data(d), next(n) {}
};

int findLength(Node* head, int count = 0) {
    if (head == nullptr)
        return count;
    return findLength(head->next, count+1);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout << "Length of linked list: " << findLength(head);
}
