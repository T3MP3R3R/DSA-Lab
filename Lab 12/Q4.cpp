#include <iostream>
using namespace std;

# Elem Sorting

class Sorter {
public:
    int arr[100];
    int n;

    Sorter() {
        n = 0;
    }

    void input(int size) {
        n = size;
        for(int i = 0; i < n; i++) cin >> arr[i];
    }

    void bubbleSort() {
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    void selectionSort() {
        for(int i = 0; i < n-1; i++) {
            int minIdx = i;
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[minIdx]) minIdx = j;
            }
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    void insertionSort() {
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    void display() {
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

void bubbleSortLL() {
    if(head == NULL) return;

    bool swapped;
    Node* t;
    Node* last = NULL;

    do {
        swapped = false;
        t = head;

        while(t->next != last) {
            if(t->data > t->next->data) {
                int temp = t->data;
                t->data = t->next->data;
                t->next->data = temp;
                swapped = true;
            }
            t = t->next;
        }
        last = t;
    } while(swapped);
}

void selectionSortLL() {
    if(head == NULL) return;

    Node* i = head;

    while(i != NULL) {
        Node* minNode = i;
        Node* j = i->next;

        while(j != NULL) {
            if(j->data < minNode->data) minNode = j;
            j = j->next;
        }

        int temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;

        i = i->next;
    }
}

void insertionSortLL() {
    if(head == NULL || head->next == NULL) return;

    Node* sorted = NULL;

    Node* curr = head;
    while(curr != NULL) {
        Node* next = curr->next;

        if(sorted == NULL || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* t = sorted;
            while(t->next != NULL && t->next->data < curr->data) {
                t = t->next;
            }
            curr->next = t->next;
            t->next = curr;
        }
        curr = next;
    }

    head = sorted;
}
