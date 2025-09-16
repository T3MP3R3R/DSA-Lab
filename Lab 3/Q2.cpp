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

    void rotate(int k){
        if (!head || k == 0){
            return;
        }
        Node* tail = head;
        int length = 1;
        while (tail->next){
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0){
            return;
        }
        Node* temp = head;
        for (int i = 1; i < k; i++){
            temp = temp->next;
        }

        Node* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        head = newHead;
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
    LinkedList LL;
    int arr[] = {5, 3, 1, 8, 6, 4, 2};
    for (int val : arr) LL.append(val);

    cout << "Original List: ";
    LL.printList();

    int k;
    cout << "Enter no. of elements to rotate: ";
    cin >> k;
    LL.rotate(k);
    cout << "List after rotation: ";
    LL.printList();

    return 0;
}