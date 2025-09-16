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
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtFront(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int val, int pos){
        if (pos == 0) {
            insertAtFront(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++){
            temp = temp->next;
        }
        if (!temp) return; // position out of range
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val){
        if (!head) return;
        if (head->data == val){
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val){
            temp = temp->next;
        }
        if (temp->next){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void printList(){
        Node* temp = head;
        while (temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int arr[5] = {3, 1, 2, 5, 8};
    cout << "Arr: ";
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    LinkedList LL;
    for (int i = 0; i < 5; i++){
        LL.append(arr[i]);
    }
    LL.append(9);
    LL.insertAtPosition(11, 2); // 2 because we want to insert after 2 elements and it starts from 0
    LL.insertAtFront(4);
    LL.deleteValue(1);
    LL.deleteValue(2);
    LL.deleteValue(5);
    cout << "List: ";
    LL.printList();

    return 0;
}
