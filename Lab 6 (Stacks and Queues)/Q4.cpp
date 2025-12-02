#include <iostream>
#include <cstring>
using namespace std;

struct Task {
    char description[100];
    Task* next;

    Task(const char* desc) {
        strcpy(description, desc);
        next = NULL;
    }
};

class ToDoStack {
    Task* top;

public:
    ToDoStack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(const char* desc) {
        Task* newTask = new Task(desc);
        newTask->next = top;
        top = newTask;

        cout << "Added task: " << desc << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty (Underflow)\n";
            return;
        }

        Task* temp = top;
        cout << "Completed task: " << temp->description << endl;

        top = top->next;
        delete temp;
    }
};

int main() {
    ToDoStack s;

    s.push("Finish the project report");
    s.push("Reply to client emails");
    s.push("Attend the design meeting");

    if (!s.isEmpty()) {
        cout << "Stack has tasks" << endl;
    }

    s.pop();
    s.pop();

    return 0;
}