#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    void append(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val){
        if (!head){
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val){
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted value " << val << " from the list.\n";
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr && curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        if (!curr){
            cout << "Value " << val << " not found in list" << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Deleted value " << val << " from the list" << endl;
    }

    void printList(){
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList LL;
    int arr[] = {10, 20, 30, 40, 50};
    for (int val : arr) LL.append(val);

    cout << "Original List: ";
    LL.printList();
    LL.deleteValue(30);
    LL.printList();
    LL.deleteValue(10);
    LL.printList();
    LL.deleteValue(99);
    LL.printList();

    return 0;
}