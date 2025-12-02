#include <iostream>
using namespace std;

void radixSort(int arr[], int n, bool ascending=true){
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10){
        int output[n];         // counting sort start
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        if (ascending){
            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];
        } else {
            for (int i = 8; i >= 0; i--)
                count[i] += count[i + 1];
        }
        
        for (int i = n - 1; i >= 0; i--){
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
        // counting sort end
    }
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Ascending: ";
    radixSort(arr, n, true);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << "\nDescending: ";
    radixSort(arr, n, false);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
