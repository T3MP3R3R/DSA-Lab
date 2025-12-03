#include <iostream>
using namespace std;

class HashQuadratic {
    int* table;
    int size;
public:
    HashQuadratic(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
    }

    int hashFunc(int key){ return key%size; }

    void insert(int key){
        int idx = hashFunc(key);
        int i=0;
        while(table[(idx+i*i)%size]!=-1){
            i++;
            if(i==size){ cout<<"Table Full\n"; return; }
        }
        table[(idx+i*i)%size] = key;
    }

    bool search(int key){
        int idx = hashFunc(key);
        int i=0;
        while(i<size && table[(idx+i*i)%size]!=key){
            if(table[(idx+i*i)%size]==-1) return false;
            i++;
        }
        return i<size;
    }

    void remove(int key){
        int idx = hashFunc(key);
        int i=0;
        while(i<size && table[(idx+i*i)%size]!=key){
            if(table[(idx+i*i)%size]==-1) return;
            i++;
        }
        if(i<size) table[(idx+i*i)%size]=-1;
    }

    void display(){
        for(int i=0;i<size;i++) cout<<i<<": "<<table[i]<<endl;
    }
};

int main(){
    HashQuadratic hq(7);
    hq.insert(10); hq.insert(20); hq.insert(15); hq.insert(7);
    cout<<"Quadratic Probing Table:\n"; hq.display();
    cout<<"Search 15: "<<(hq.search(15)?"Found":"Not Found")<<endl;
    hq.remove(10);
    cout<<"After Removal:\n"; hq.display();
    return 0;
}