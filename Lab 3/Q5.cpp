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

    bool isPalindrome(){
        if (!head || !head->next) return true;
        
        Node* slow = head;  // So this might be a bit of a weird approach
        Node* fast = head;  // but I'm using slow and fast pointers to find the middle of the list
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverseList(slow->next);
        Node* firstHalf = head;
        Node* tempSecond = secondHalf;
        bool palindrome = true;

        while (tempSecond) {
            if (firstHalf->data != tempSecond->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }
        slow->next = reverseList(secondHalf);

        return palindrome;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList LL;
    int arr1[] = {1, 0, 2, 0, 1};
    for (int val : arr1) LL.append(val);
    cout << "List: ";
    LL.printList();
    cout << (LL.isPalindrome() ? "Linked List is a Palindrome" : "Linked List is not a Palindrome") << endl;
    return 0;
}