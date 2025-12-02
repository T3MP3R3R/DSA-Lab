#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp){
    int output[20]; 
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr1[10] = {29, 10, 14, 37, 13, 55, 6, 41, 19, 23};
    int arr2[10] = {50, 32, 11, 25, 45, 62, 9, 38, 20, 5};

    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[i + 10] = arr2[i];

    int n = 20;
    radixSort(combined, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << combined[i] << " ";
    cout << endl;

    return 0;
}
