#include <iostream>
using namespace std;

class HashTable {
    int* table;
    int capacity;
    int size;

public:
    HashTable(int cap){
        capacity = cap;
        size = 0;
        table = new int[capacity];
        for(int i=0;i<capacity;i++) table[i] = -1;
    }

    int hashFunc(int key, int cap){ return key % cap; }

    void rehash(){
        int oldCapacity = capacity;
        int* oldTable = table;

        capacity *= 2;
        table = new int[capacity];
        for(int i=0;i<capacity;i++) table[i] = -1;

        size = 0;
        for(int i=0;i<oldCapacity;i++){
            if(oldTable[i]!=-1) insert(oldTable[i]);
        }

        delete [] oldTable;
        cout<<"Rehashed! New capacity: "<<capacity<<endl;
    }

    void insert(int key){
        if((size+1) > 0.7*capacity) rehash();

        int idx = hashFunc(key, capacity);
        int start = idx;
        while(table[idx]!=-1){
            idx = (idx+1)%capacity;
            if(idx==start){ cout<<"Table Full!\n"; return; }
        }
        table[idx] = key;
        size++;
    }

    bool search(int key){
        int idx = hashFunc(key, capacity);
        int start = idx;
        while(table[idx]!=key){
            if(table[idx]==-1) return false;
            idx = (idx+1)%capacity;
            if(idx==start) return false;
        }
        return true;
    }

    void remove(int key){
        int idx = hashFunc(key, capacity);
        int start = idx;
        while(table[idx]!=key){
            if(table[idx]==-1) return;
            idx = (idx+1)%capacity;
            if(idx==start) return;
        }
        table[idx] = -1;
        size--;
    }

    void display(){
        for(int i=0;i<capacity;i++)
            cout<<i<<": "<<table[i]<<endl;
    }
};

int main(){
    HashTable ht(5);
    ht.insert(10); ht.insert(20); ht.insert(15);
    ht.insert(7); ht.insert(12); // triggers rehash
    ht.insert(25);

    cout<<"Hash Table:\n"; ht.display();

    cout<<"Search 15: "<<(ht.search(15)?"Found":"Not Found")<<endl;
    ht.remove(20);
    cout<<"After Removal:\n"; ht.display();

    return 0;
}