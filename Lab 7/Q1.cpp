#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    int score;
    Node* next;
};

void addNode(Node*& head, string name, int score){
    Node* newNode = new Node{name, score, NULL};
    if (head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int getMax(Node* head){
    int maxVal = head->score;
    while (head != NULL){
        if (head->score > maxVal)
            maxVal = head->score;
        head = head->next;
    }
    return maxVal;
}

int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void radixSort(Node*& head) {
    if (!head) return;

    int exp = 1; // could've used cmath but nope
    int maxScore = getMax(head);

    while (maxScore / exp>0) {
        Node* bucket[10] = {NULL};
        Node* bucketTail[10] = {NULL};
        Node* curr = head;
        while (curr){
            int digit = (curr->score / exp) % 10;
            Node* nextNode = curr->next;
            curr->next = NULL;

            if (!bucket[digit]) {
                bucket[digit] = curr;
                bucketTail[digit] = curr;
            } else {
                bucketTail[digit]->next = curr;
                bucketTail[digit] = curr;
            }
            curr = nextNode;
        }

        Node* newHead = NULL;
        Node* newTail = NULL;
        for (int i = 0; i < 10; i++) {
            if (bucket[i]) {
                if (!newHead) {
                    newHead = bucket[i];
                    newTail = bucketTail[i];
                } else {
                    newTail->next = bucket[i];
                    newTail = bucketTail[i];
                }
            }
        }
        head = newHead;
        exp *= 10;
    }
}

int binarySearch(Node* head, string name, int score) {
    int len = getLength(head);
    int left = 0, right = len - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        Node* temp = head;
        for (int i = 0; i < mid; i++)
            temp = temp->next;

        if (temp->score == score && temp->name == name)
            return mid;
        else if (temp->score < score)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void deleteNode(Node*& head, int pos){
    if (!head) return;

    if (pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp || !temp->next) return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void display(Node* head){
    while (head){
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main(){
    Node* head = NULL;

    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);

    cout << "Original:" << endl;
    display(head);

    radixSort(head);
    cout << "\nSorted:" << endl;
    display(head);
    string sName;
    int sScore;
    cout << "\nEnter a name and score to delete: "; 
    cin >> sName >> sScore;

    int pos = binarySearch(head, sName, sScore);
    if (pos != -1){
        deleteNode(head, pos);
        cout << "\nUpdated List:" << endl;
        display(head);
    } else {
        cout << "\nRecord not found" << endl;
    }

    return 0;
}
