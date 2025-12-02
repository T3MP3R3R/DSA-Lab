#include <iostream>
#include <cstring>
using namespace std;

struct Order {
    char item[50];
    int quantity;
    Order* next;

    Order(const char* it, int q) {
        strcpy(item, it);
        quantity = q;
        next = NULL;
    }
};

class Queue {
    Order* front;
    Order* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(const char* name, int qty) {
        Order* newOrder = new Order(name, qty);

        if (rear == NULL) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }

        cout << "Order added: " << name << " x" << qty << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to process (Queue Underflow)\n";
            return;
        }

        Order* temp = front;
        cout << "Processing order: " << temp->item << " x" << temp->quantity << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void printOrders() {
        if (isEmpty()) {
            cout << "No orders in queue.\n";
            return;
        }

        cout << "\n--- Orders in the queue ---" << endl;
        Order* temp = front;

        while (temp != NULL) {
            cout << temp->item << " x" << temp->quantity << endl;
            temp = temp->next;
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Burger", 2);
    q.enqueue("Pizza", 1);
    q.enqueue("Fries", 3);
    q.printOrders();
    q.dequeue();
    q.dequeue();
    q.printOrders();

    return 0;
}