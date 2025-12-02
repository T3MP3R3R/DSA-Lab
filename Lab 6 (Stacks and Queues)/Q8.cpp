#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        front = 0;
        rear = -1;
        capacity = size;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = id;
        cout << "Customer " << id << " added to the queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int id = arr[front];
        front++;
        cout << "Customer " << id << " checked out" << endl;
        return id;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(100);

    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = sizeof(customers)/sizeof(customers[0]);

    for (int i = 0; i < n; i++)
        q.enqueue(customers[i]);

    cout << endl;
    q.printQueue();
    cout << endl;

    while (!q.isEmpty())
        q.dequeue();

    cout << endl;
    q.printQueue();

    return 0;
}