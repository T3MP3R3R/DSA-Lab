#include <iostream>
using namespace std;

class MaxHeap{
public:
    int arr[100];
    int size;

    MaxHeap(){
        size = 0;
    }

    void insert(int val){
        size++;
        int i = size;
        arr[i] = val;

        while(i > 1 && arr[i/2] < arr[i]){
            swap(arr[i/2], arr[i]);
            i = i / 2;
        }
    }

    void heapifyDown(int i){
        while(true){
            int l = i * 2;
            int r = i * 2 + 1;
            int largest = i;

            if(l <= size && arr[l] > arr[largest]) largest = l;
            if(r <= size && arr[r] > arr[largest]) largest = r;

            if(largest != i){
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }

    void heapifyUp(int i){
        while(i > 1 && arr[i/2] < arr[i]){
            swap(arr[i/2], arr[i]);
            i /= 2;
        }
    }

    void update_key(int i, int new_val){
        if(i < 1 || i > size) return;
        int old_val = arr[i];
        arr[i] = new_val;
        if(new_val > old_val)
            heapifyUp(i);
        else
            heapifyDown(i);
    }

    void delete_key(int i){
        if(i < 1 || i > size) return;
        arr[i] = arr[size];
        size--;
        heapifyUp(i);
        heapifyDown(i);
    }

    void print(){
        for(int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    MaxHeap h;
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Initial Heap: ";
    h.print();
    h.update_key(3, 10);
    cout << "New Heap (Updated 3rd element): ";
    h.print();
    h.delete_key(2);
    cout << "New Heap (Deleted 2nd element): ";
    h.print();
  
    return 0;
}
