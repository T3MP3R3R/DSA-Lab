#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int size = 10;
    int roll;
    cout << "Enter last two digits of roll no: ";
    cin >> roll;

    int found = binarySearch(arr, size, roll);

    if (found == -1) {
        cout << roll<< " not in array, so we insert" << endl;
        arr[size] = roll;
        size++;

        // Insertion sort
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    int result = binarySearch(arr, size, roll);
    if (result != -1)
        cout << "Value " << result << " found" << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}
