#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList() : head(NULL) {}
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int val, int pos){
        if (pos == 0){
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val){
        if (!head) return;
        Node* curr = head;
        Node* prev = NULL;
        while (curr->data != val && curr->next != head){
            prev = curr;
            curr = curr->next;
        }

        if (curr->data != val) {
            cout << "Value " << val << " not found in the list" << endl;
            return;
        }

        if (curr == head && curr->next == head){
            delete head;
            head = NULL;
            return;
        }

        if (curr == head){
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = head->next;
            head = head->next;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    void printList(){
        if (!head){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList CLL;
    CLL.insertAtEnd(10);
    CLL.insertAtEnd(20);
    CLL.insertAtEnd(30);
    CLL.insertAtBeginning(5);
    CLL.insertAtPosition(15, 2);
    cout << "Circular List: ";
    CLL.printList();
    CLL.deleteNode(20);
    cout << "After deleting 20: ";
    CLL.printList();

    return 0;
}