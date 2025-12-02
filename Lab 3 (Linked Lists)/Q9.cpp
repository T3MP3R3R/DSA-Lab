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

    Node* reverseList(Node* node){
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        while (curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
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

    void rearrange(){
        if (!head || !head->next) return;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        while (even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        Node* reversedEven = reverseList(evenHead);
        odd->next = reversedEven;
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

int main() {
    LinkedList LL;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int val : arr) LL.append(val);
    cout << "Original List: ";
    LL.printList();
    LL.rearrange();
    cout << "Rearranged List: ";
    LL.printList();

    return 0;
}