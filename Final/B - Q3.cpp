#include <iostream>
#include <string>
using namespace std;

struct Donor {
    int id;
    string name;
    string bloodGroup;
    Donor* next;
    Donor(int i, string n, string b) : id(i), name(n), bloodGroup(b), next(NULL) {}
};

Donor* mergeSortedLists(Donor* a, Donor* b) {
    if (!a) return b;
    if (!b) return a;

    Donor* result = NULL;

    if (a->id <= b->id) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

void splitList(Donor* source, Donor** frontRef, Donor** backRef) {
    Donor* fast;
    Donor* slow;
    slow = source;
    fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSortList(Donor** headRef) {
    Donor* head = *headRef;
    if (!head || !head->next) return;

    Donor* a;
    Donor* b;

    splitList(head, &a, &b);

    mergeSortList(&a);
    mergeSortList(&b);

    *headRef = mergeSortedLists(a, b);
}

class HashTable {
    static const int SIZE = 10;
    Donor* table[SIZE];

    int hashFunction(int id) { return id % SIZE; }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) table[i] = NULL;
    }

    void addDonor(int id, string name, string bloodGroup) {
        int idx = hashFunction(id);
        Donor* newDonor = new Donor(id, name, bloodGroup);
        newDonor->next = table[idx];
        table[idx] = newDonor;

        mergeSortList(&table[idx]);
        cout << "After adding donor at index " << idx << ":\n";
        displayIndex(idx);
    }

    void updateDonor(int id, string newName, string newBloodGroup) {
        int idx = hashFunction(id);
        Donor* curr = table[idx];
        bool found = false;
        while (curr) {
            if (curr->id == id) {
                curr->name = newName;
                curr->bloodGroup = newBloodGroup;
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (found) {
            mergeSortList(&table[idx]);
            cout << "After updating donor at index " << idx << ":\n";
            displayIndex(idx);
        } else cout << "Donor ID " << id << " not found.\n";
    }

    void deleteDonor(int id) {
        int idx = hashFunction(id);
        Donor* curr = table[idx];
        Donor* prev = NULL;
        bool found = false;

        while (curr) {
            if (curr->id == id) {
                found = true;
                if (!prev) table[idx] = curr->next;
                else prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (found) {
            mergeSortList(&table[idx]);
            cout << "After deleting donor at index " << idx << ":\n";
            displayIndex(idx);
        } else cout << "Donor ID " << id << " not found.\n";
    }

    void displayIndex(int idx) {
        Donor* curr = table[idx];
        if (!curr) { cout << "Index " << idx << " is empty.\n"; return; }
        while (curr) {
            cout << "ID: " << curr->id << ", Name: " << curr->name << ", Blood: " << curr->bloodGroup << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    HashTable bdt;

    bdt.addDonor(15, "Alice", "A+");
    bdt.addDonor(25, "Bob", "B+");
    bdt.addDonor(5, "Charlie", "O-");
    bdt.addDonor(35, "David", "AB+");

    bdt.updateDonor(25, "Bobby", "B+");

    bdt.deleteDonor(15);

    return 0;
}