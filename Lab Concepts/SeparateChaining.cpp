#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;
    Node(int k){ key=k; next=NULL; }
};

class HashChain {
    Node** table;
    int size;
public:
    HashChain(int s){
        size=s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i]=NULL;
    }

    int hashFunc(int key){ return key%size; }

    void insert(int key){
        int idx=hashFunc(key);
        Node* n=new Node(key);
        n->next=table[idx];
        table[idx]=n;
    }

    bool search(int key){
        int idx=hashFunc(key);
        Node* temp=table[idx];
        while(temp){
            if(temp->key==key) return true;
            temp=temp->next;
        }
        return false;
    }

    void remove(int key){
        int idx=hashFunc(key);
        Node* temp=table[idx];
        Node* prev=NULL;
        while(temp){
            if(temp->key==key){
                if(prev) prev->next=temp->next;
                else table[idx]=temp->next;
                delete temp;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<i<<": ";
            Node* temp=table[i];
            while(temp){ cout<<temp->key<<"->"; temp=temp->next; }
            cout<<"NULL\n";
        }
    }
};

int main(){
    HashChain hc(7);
    hc.insert(10); hc.insert(20); hc.insert(15); hc.insert(7); hc.insert(14);
    cout<<"Separate Chaining Table:\n"; hc.display();
    cout<<"Search 15: "<<(hc.search(15)?"Found":"Not Found")<<endl;
    hc.remove(20);
    cout<<"After Removal:\n"; hc.display();
    return 0;
}