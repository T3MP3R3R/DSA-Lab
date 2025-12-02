#include <iostream>
using namespace std;

int main() {
    string text = "ababababc";
    string pattern = "abab";
    int n = text.length();
    int m = pattern.length();

    int lps[100];
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int result[100];
    int countMatches = 0;
    int t = 0;
    int p = 0;

    while (t < n) {
        if (pattern[p] == text[t]) {
            t++;
            p++;
        }
        if (p == m) {
            result[countMatches] = t - p;
            countMatches++;
            p = lps[p - 1];
        } else if (t < n && pattern[p] != text[t]) {
            if (p != 0)
                p = lps[p - 1];
            else
                t++;
        }
    }

    cout << "LPS array: [ ";
    for (int k = 0; k < m; k++)
        cout << lps[k] << " ";
    cout << "]" << endl;
    cout << "Matches at positions: [ ";
    for (int k = 0; k < countMatches; k++)
        cout << result[k] << " ";
    cout << "]" << endl;
    
    return 0;
}
