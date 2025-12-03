#include <iostream>
using namespace std;

class CircularQueue {
    int arr[50], front, rear, size;
public:
    CircularQueue() { front = rear = -1; size = 50; }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % size == front; }

    void enqueue(int val) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    return 0;
}