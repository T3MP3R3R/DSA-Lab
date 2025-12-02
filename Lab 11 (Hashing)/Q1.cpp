#include <iostream>
#include <string>
using namespace std;

struct Node{
    string key;
    string value;
    Node* next;

    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];

    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printTable(){
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "[" << temp->key << ": " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main(){
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.printTable();
    return 0;
}
