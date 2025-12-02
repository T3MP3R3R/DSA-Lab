#include <iostream>
#include <string>
using namespace std;

struct Runner{
    string name;
    int time; 
};

void merge(Runner arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // start merge
    while (i < n1 && j < n2){
        if (L[i].time <= R[j].time)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    const int size = 10;
    Runner runners[size];

    for (int i = 0; i < size; i++){
        cout << "Enter name and finish time for runner " << i+1 << ": ";
        cin >> runners[i].name >> runners[i].time;
    }
    mergeSort(runners, 0, size - 1);

    cout << "\nTop 5 fastest runners: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << i+1 << ". " << runners[i].name << " - " << runners[i].time << " seconds" << endl;
    }

    return 0;
}
