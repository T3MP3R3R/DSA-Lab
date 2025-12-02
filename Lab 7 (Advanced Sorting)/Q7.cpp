#include <iostream>
#include <cstdlib> // for rand/srand()
#include <ctime> // for time()
using namespace std;

int comparisons;

int partition(int arr[], int low, int high, int pivotType){
    int pivotIndex;
    if (pivotType == 1) pivotIndex = low; // first elem
    else if (pivotType == 2) pivotIndex = rand() % (high - low + 1) + low;  // rand
    else if (pivotType == 3) pivotIndex = (low + high) / 2; // mid
    else { // median of 3
        int mid = (low + high) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        if ((a > b) != (a > c)) pivotIndex = low;
        else if ((b > a) != (b > c)) pivotIndex = mid;
        else pivotIndex = high;
    }

    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int pivotType){
    if (low < high){
        int pi = partition(arr, low, high, pivotType);
        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    srand(time(0));
    int arr[] = {3, 8, 30, 92, 24, 69, 12};
    int n = 7;

    for (int type = 1; type <= 4; type++){
        int temp[7];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        comparisons = 0;
        quickSort(temp, 0, n - 1, type);

        cout << "Pivot Type " << type << " ("
             << (type == 1 ? "First" :
                 type == 2 ? "Random" :
                 type == 3 ? "Middle" : "Median")
             << ") -> Comparisons: " << comparisons << " | Sorted: ";
        printArray(temp, n);
    }

    return 0;
}
