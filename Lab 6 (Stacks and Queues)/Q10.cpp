#include <iostream>
using namespace std;

class LibraryQueue {
    int arr[100];
    int front;
    int rear;
    int capacity;

public:
    LibraryQueue(int size) {
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

    void enqueue(int patronID) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = patronID;
        cout << "Patron " << patronID << " added to the queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        int patronID = arr[front];
        cout << "Patron " << patronID << " is being serviced" << endl;
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No patrons are waiting " << endl;
            return;
        }
        cout << "Current queue of patrons: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    LibraryQueue lq(100);

    lq.enqueue(101);
    lq.enqueue(102);
    lq.enqueue(103);
    lq.enqueue(104);

    cout << endl;
    lq.displayQueue();
    cout << endl;

    lq.dequeue();
    lq.dequeue();

    cout << endl;
    lq.displayQueue();
    cout << endl;

    lq.enqueue(105);
    lq.enqueue(106);

    cout << endl;
    lq.displayQueue();
    cout << endl;

    while (!lq.isEmpty())
        lq.dequeue();

    cout << endl;
    lq.displayQueue();

    return 0;
}