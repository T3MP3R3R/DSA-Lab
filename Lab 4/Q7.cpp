#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int n, string key, int &steps){
    steps = 0;
    for (int i = 0; i < n; i++){
        steps++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(string arr[], int n, string key, int &steps){
    int low = 0, high = n -1;
    steps = 0;
    while (low <= high){
        steps++;
        int mid = (low + high) /2;
        if (arr[mid] == key) return mid;
        else if (key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    string arr[] = {"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    int n = 10, int steps;

    cout << "Searching for Aftab:" << endl;
    cout << "Linear: " << linearSearch(arr, n, "Aftab", steps) << " | Steps = " << steps << endl;
    cout << "Binary: " << binarySearch(arr, n, "Aftab", steps) << " | Steps = " << steps << endl << endl;

    cout << "Searching for Rizwan: " << endl;
    cout << "Linear: " << linearSearch(arr, n, "Rizwan", steps) << " | Steps = " << steps << endl;
    cout << "Binary: " << binarySearch(arr, n, "Rizwan", steps) << " | Steps = " << steps << endl << endl;

    cout << "Searching for Tariq: " << endl;
    cout << "Linear: " << linearSearch(arr, n, "Tariq", steps) << " | Steps = " << steps << endl;
    cout << "Binary: " << binarySearch(arr, n, "Tariq", steps) << " | Steps = " << steps << endl << endl;

    return 0;
}
