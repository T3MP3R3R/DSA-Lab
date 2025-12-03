#include <iostream>
using namespace std;

class HashLinear {
    int* table;
    int size;
public:
    HashLinear(int s){
        size = s;
        table = new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
    }

    int hashFunc(int key){ return key % size; }

    void insert(int key){
        int idx = hashFunc(key);
        int start = idx;
        while(table[idx]!=-1){
            idx = (idx+1)%size;
            if(idx == start){ cout<<"Table Full\n"; return; }
        }
        table[idx] = key;
    }

    void remove(int key){
        int idx = hashFunc(key);
        int start=idx;
        while(table[idx]!=key){
            idx = (idx+1)%size;
            if(idx==start){ cout<<"Not Found\n"; return; }
        }
        table[idx]=-1;
    }

    bool search(int key){
        int idx=hashFunc(key);
        int start=idx;
        while(table[idx]!=key){
            if(table[idx]==-1) return false;
            idx=(idx+1)%size;
            if(idx==start) return false;
        }
        return true;
    }

    void display(){
        for(int i=0;i<size;i++)
            cout<<i<<": "<<table[i]<<endl;
    }
};

int main(){
    HashLinear h(7);
    h.insert(10); h.insert(20); h.insert(15); h.insert(7);
    cout<<"Hash Table:\n"; h.display();
    cout<<"Search 15: "<<(h.search(15)?"Found":"Not Found")<<endl;
    h.remove(20);
    cout<<"After Removal:\n"; h.display();
    return 0;
}