#include <iostream>
using namespace std;

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int n = text.length();
    int m = pattern.length();
    int indices[100]; 
    int matchCount = 0;
    int comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            comparisons++;
            if (text[i+j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match){
            indices[matchCount] = i;
            matchCount++;
        }
    }

    cout << "Indices: ";
    for (int k = 0; k < matchCount; k++) {
        cout << indices[k] << " ";
    }
    cout << endl;
    cout << "Total Comparisons: " << comparisons;

    return 0;
}
