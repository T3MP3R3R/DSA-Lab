#include <iostream>
using namespace std;

bool dupCheck(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {4, 7, 2, 9, 5, 2, 8, 1};
    int n = 8;

    if (dupCheck(arr, n))
        cout << "Array contains duplicates" << endl;
    else
        cout << "Array doesnt contain duplicates" << endl;
    return 0;
}
