#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[i] < arr[l]) return false;
        if (r < n && arr[i] < arr[r]) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[5] = {8, 7, 6, 5, 4};
    int n = 5;
    cout << "Is this a Max Heap? " << (isMaxHeap(arr, n) ? "Yes" : "No") << endl;
    heapSort(arr, n);
    cout << "Sorted array: ";
    print(arr, n);

    return 0;
}
