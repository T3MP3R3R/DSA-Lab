#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int kthLargest(int arr[], int n, int k){
    buildHeap(arr, n);

    for (int i = n - 1; i >= n - k + 1; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    return arr[0];
}

int main(){
    int n, k;
    cout << "Enter no of elements: "; cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter K (Should be <= n): "; cin >> k;

    cout << "K-th largest element: "
         << kthLargest(arr, n, k) << endl;

    return 0;
}
