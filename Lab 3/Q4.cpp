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

    void rearrangeEvenOdd(){
        if (!head || !head->next) return;
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* current = head;

        while (current){
            int val = current->data;

            if (val % 2 == 0) { // check for even numbers
                if (!evenStart){
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            } else { // check for odd numbers
                if (!oddStart){
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }

        if (!evenStart || !oddStart) { return; }

        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }

    void printList(){
        Node* temp = head;
        while (temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList LL;

    int arr1[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int val : arr1) LL.append(val);
    cout << "Original List: ";
    LL.printList();
    LL.rearrangeEvenOdd();
    cout << "Rearranged List: ";
    LL.printList();
    return 0;
}