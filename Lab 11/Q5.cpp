#include <iostream>
#include <cstring> // for strcpy only
using namespace std;

struct Student {
    int roll;
    char name[50];
    bool used;
};

class StudentHashTable {
    Student table[15];
    int size;

    int hashFunction(int roll) {
        return roll % size;
    }

public:
    StudentHashTable() {
        size = 15;
        for (int i = 0; i < size; i++) {
            table[i].used = false;
            table[i].roll = -1;
            table[i].name[0] = '\0';
        }
    }

    void InsertRecord(int roll, const char* name) {
        int index = hashFunction(roll);
        int attempt = 0;
        while (attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if (!table[newIndex].used) {
                table[newIndex].roll = roll;
                strcpy(table[newIndex].name, name);
                table[newIndex].used = true;
                return;
            }
            attempt++;
        }
        cout << "Hash table full" << endl;
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;
        while (attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if (!table[newIndex].used) {
                cout << "Record not found" << endl;
                return;
            }
            if (table[newIndex].roll == roll) {
                cout << "Student Name: " << table[newIndex].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(1, "Alice");
    sht.InsertRecord(16, "Bob");
    sht.InsertRecord(31, "Charlie");

    sht.SearchRecord(16);
    sht.SearchRecord(2);
    return 0;
}
