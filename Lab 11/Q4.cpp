#include <iostream>
using namespace std;

struct Pair{
    int a, b;
    bool used;
};

int hashFunction(int x, int size) {
    return (x % size + size) % size;
}

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    const int TABLE_SIZE = 100;
    Pair table[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) table[i].used = false;

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            int index = hashFunction(sum, TABLE_SIZE);

            while (table[index].used && table[index].a + table[index].b != sum) {
                index = (index + 1) % TABLE_SIZE;
            }

            if (table[index].used) {
                int a = table[index].a;
                int b = table[index].b;

                if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                    cout << "(" << a << ", " << b << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    found = true;
                    break;
                }
            }
            else {
                table[index].used = true;
                table[index].a = arr[i];
                table[index].b = arr[j];
            }
        }
        if (found) break;
    }

    if (!found) cout << "No pairs found" << endl;

    return 0;
}
