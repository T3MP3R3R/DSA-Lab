#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == 99) return;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front > rear) return -1;
        return arr[front++];
    }

    int peek() {
        if (front > rear) return -1;
        return arr[front];
    }

    bool empty() {
        return front > rear;
    }
};

class CQ {
    int arr[100];
    int front, rear, count;
public:
    CQ() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == 100) return;
        rear = (rear + 1) % 100;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0) return -1;
        int val = arr[front];
        front = (front + 1) % 100;
        count--;
        return val;
    }

    int peek() {
        if (count == 0) return -1;
        return arr[front];
    }

    bool empty() {
        return count == 0;
    }
};

class LLQueue {
    Node* front;
    Node* rear;

public:
    LLQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;

        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }

    int dequeue() {
        if (front == NULL) return -1;

        int val = front->data;
        Node* temp = front;
        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
        return val;
    }

    int peek() {
        if (front == NULL) return -1;
        return front->data;
    }

    bool empty() {
        return front == NULL;
    }
};

struct Node {
    int data;
    Node* next;
};

class LLPQ {
    Node* head;

public:
    LLPQ() {
        head = NULL;
    }

    void insert(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;

        if (head == NULL || head->data > x) {
            n->next = head;
            head = n;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data <= x) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }

    int removeMin() {
        if (head == NULL) return -1;

        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    int getMin() {
        if (head == NULL) return -1;
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};
