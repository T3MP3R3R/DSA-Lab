#include <iostream>
using namespace std;

class PriorityQueue{
    int* pq;
    int capacity;
    int size;
public:
    PriorityQueue(int cap){ capacity=cap; size=0; pq=new int[cap]; }

    int parent(int i){ return (i-1)/2; }
    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i+2; }

    void insert(int val){
        if(size==capacity){ cout<<"Full\n"; return; }
        pq[size]=val;
        int i=size;
        size++;
        while(i!=0 && pq[parent(i)] < pq[i]){
            swap(pq[i], pq[parent(i)]);
            i=parent(i);
        }
    }

    int extractMax(){
        if(size<=0) return -1;
        int root=pq[0];
        pq[0]=pq[size-1];
        size--;
        int i=0;
        while(true){
            int l=left(i), r=right(i), largest=i;
            if(l<size && pq[l]>pq[largest]) largest=l;
            if(r<size && pq[r]>pq[largest]) largest=r;
            if(largest!=i){ swap(pq[i], pq[largest]); i=largest; }
            else break;
        }
        return root;
    }

    void display(){ for(int i=0;i<size;i++) cout<<pq[i]<<" "; cout<<endl; }
};

int main(){
    PriorityQueue pq(10);
    pq.insert(5); pq.insert(20); pq.insert(3); pq.insert(25);
    cout<<"Queue: "; pq.display();
    cout<<"Extract Max: "<<pq.extractMax()<<endl;
    cout<<"Queue now: "; pq.display();
    return 0;
}