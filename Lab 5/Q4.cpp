#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n = nullptr) : data(d), next(n) {}
};

bool search(Node* head, int val) {
    if (head == nullptr)
        return false;
    if (head->data == val)
        return true;
    return search(head->next, val);
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);
    int value;
    cout << "Enter value to search: "; cin >> value;
    if (search(head, value))
        cout << value << " found in list";
    else
        cout << value << " not found";
}
