#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class QueueLL {
    Node* front;
    Node* rear;
public:
    QueueLL() { front = rear = nullptr; }
    bool isEmpty() { return front == nullptr; }

    void enqueue(int val) {
        Node* n = new Node(val);
        if (isEmpty()) { front = rear = n; return; }
        rear->next = n;
        rear = n;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        Node* temp = front;
        cout << "Queue: ";
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    QueueLL q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
