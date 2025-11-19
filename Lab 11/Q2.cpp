#include <iostream>
#include <string>
using namespace std;

struct Node{
    string key;
    string value;
    Node* next;
};

class Dictionary{
private:
    static const int TABLE_SIZE = 100;
    Node* table[TABLE_SIZE];

    int hashFunction(const string& key){
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % TABLE_SIZE;
    }

public:
    Dictionary(){
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void Add_Record(const string& key, const string& value){
        int index = hashFunction(key);

        Node* newNode = new Node{key, value, nullptr};

        if (!table[index]){
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void Word_Search(const string& key){
        int index = hashFunction(key);

        Node* temp = table[index];
        while (temp != nullptr){
            if (temp->key == key){
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << key << "not found" << endl;
    }

    void Delete_Record(const string& key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << key << " deleted successfully" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key not found" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << "index " << i << ": ";
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main(){
    Dictionary dict;

    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "IT");
    dict.Word_Search("AB");
    dict.Delete_Record("EF");
    dict.Print_Dictionary();

    return 0;
}
