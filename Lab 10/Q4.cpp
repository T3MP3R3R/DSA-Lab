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

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void conversion(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main(){
    int n;
    cout << "Enter n: "; cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    conversion(arr, n);
    cout << "Max Heap: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
