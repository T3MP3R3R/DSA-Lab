#include <iostream>
using namespace std;

class MaxHeap {
    int* heap;
    int capacity;
    int size;
public:
    MaxHeap(int cap){
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    int parent(int i){ return (i-1)/2; }
    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i+2; }

    void insert(int val){
        if(size == capacity){ cout<<"Heap full\n"; return; }
        heap[size] = val;
        int i = size;
        size++;
        // Bubble up
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i);
        int largest = i;
        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;
        if(largest != i){
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int extractMax(){
        if(size <= 0) return -1;
        if(size == 1){ size--; return heap[0]; }
        int root = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapify(0);
        return root;
    }

    void display(){
        for(int i=0;i<size;i++) cout<<heap[i]<<" ";
        cout<<endl;
    }
};

int main(){
    MaxHeap h(10);
    h.insert(10); h.insert(20); h.insert(5); h.insert(30);
    cout<<"Heap: "; h.display();
    cout<<"Extract Max: "<<h.extractMax()<<endl;
    cout<<"Heap now: "; h.display();
    return 0;
}