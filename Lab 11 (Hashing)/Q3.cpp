#include <iostream>
#include <list>
using namespace std;

class Hash {
    int bucket;
    list<int>* table;

public:
    Hash(int b) {
        bucket = b;
        table = new list<int>[bucket];
    }

    int hashFunction(int key) {
        return key % bucket;
    }

    void insertItem(int key) {
        int i = hashFunction(key);
        table[i].push_back(key);
    }

    void deleteItem(int key) {
        int i = hashFunction(key);
        table[i].remove(key);
    }

    bool searchItem(int key) {
        int i = hashFunction(key);
        for (int x : table[i]) {
            if (x == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < bucket; i++) {
            cout << i << " : ";
            for (int x : table[i]) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    Hash h(7);

    h.insertItem(15);
    h.insertItem(11);
    h.insertItem(27);
    h.insertItem(8);
    h.insertItem(12);

    h.display();

    cout << h.searchItem(27) << endl;

    h.deleteItem(27);

    h.display();

    return 0;
}
