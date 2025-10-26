#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[20], R[20];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr1[10] = {29, 10, 14, 37, 13, 55, 6, 41, 19, 23};
    int arr2[10] = {50, 32, 11, 25, 45, 62, 9, 38, 20, 5};

    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[i + 10] = arr2[i];

    int n = 20;
    mergeSort(combined, 0, n - 1);
    
    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << combined[i] << " ";
    cout << endl;

    return 0;
}
