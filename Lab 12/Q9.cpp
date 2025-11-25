#include <iostream>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;
public:
    MaxHeap() { size = 0; }

    void insert(int x) { 
        arr[size] = x;
        int i = size++;
        while(i != 0 && arr[(i-1)/2] < arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int extractMax() {
        if(size==0) return -1;
        int root = arr[0];
        arr[0] = arr[--size];
        maxHeapify(0);
        return root;
    }

    void maxHeapify(int i) {
        int largest = i, l=2*i+1, r=2*i+2;
        if(l<size && arr[l]>arr[largest]) largest=l;
        if(r<size && arr[r]>arr[largest]) largest=r;
        if(largest!=i) { swap(arr[i], arr[largest]); maxHeapify(largest); }
    }
};

class MinHeap {
    int arr[100];
    int size;
public:
    MinHeap() { size=0; }

    void insert(int x) {
        arr[size]=x;
        int i=size++;
        while(i!=0 && arr[(i-1)/2] > arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    int extractMin() {
        if(size==0) return -1;
        int root=arr[0];
        arr[0]=arr[--size];
        minHeapify(0);
        return root;
    }

    void minHeapify(int i) {
        int smallest=i, l=2*i+1, r=2*i+2;
        if(l<size && arr[l]<arr[smallest]) smallest=l;
        if(r<size && arr[r]<arr[smallest]) smallest=r;
        if(smallest!=i) { swap(arr[i], arr[smallest]); minHeapify(smallest); }
    }
};
