#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            return;
        } else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    cout << "Element not found" << endl;
}

void interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) cout << "Element found at index " << low << endl;
            else cout << "Element not found" << endl;
            return;
        }
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) {
            cout << "Element found at index " << pos << endl;
            return;
        } else if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    cout << "Element not found" << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Linear Search\n2. Binary Search (sorted required)\n3. Interpolation Search (sorted required)\n";
        cout << "4. Bubble Sort\n5. Selection Sort\n6. Insertion Sort\n7. Display Array\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int key; cout << "Enter key to search: "; cin >> key;
                linearSearch(arr, n, key);
                break;
            }
            case 2: {
                int key; cout << "Enter key to search: "; cin >> key;
                binarySearch(arr, n, key);
                break;
            }
            case 3: {
                int key; cout << "Enter key to search: "; cin >> key;
                interpolationSearch(arr, n, key);
                break;
            }
            case 4: bubbleSort(arr, n); cout << "Array sorted using Bubble Sort.\n"; break;
            case 5: selectionSort(arr, n); cout << "Array sorted using Selection Sort.\n"; break;
            case 6: insertionSort(arr, n); cout << "Array sorted using Insertion Sort.\n"; break;
            case 7: displayArray(arr, n); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}