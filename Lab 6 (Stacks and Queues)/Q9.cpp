#include <iostream>
#include <string>
using namespace std;

struct Node {
    string message;
    Node* next;
    Node(string msg) {
        message = msg;
        next = NULL;
    }
};

class MessageQueue {
    Node* front;
    Node* rear;

public:
    MessageQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(const string &msg) {
        Node* newNode = new Node(msg);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Message added to queue: " << msg << endl;
    }

    // Process the next message
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No messages to process.\n";
            return;
        }
        Node* temp = front;
        cout << "Processing message: " << temp->message << endl;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty " << endl;
            return;
        }
        cout << "Current message queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->message << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    MessageQueue mq;

    mq.enqueue("Hello");
    mq.enqueue("How are you?");
    mq.enqueue("Are you free today?");
    mq.enqueue("Let's meet up");

    cout << endl;
    mq.printQueue();
    cout << endl;

    while (!mq.isEmpty()) {
        mq.dequeue();
    }

    cout << endl;
    mq.printQueue();

    return 0;
}