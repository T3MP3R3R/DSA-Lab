#include <iostream>
using namespace std;

int main() {
    string text = "ACGTACGTGACG";
    string pattern = "ACG";
    int n = text.length();
    int m = pattern.length();

    int badChar[256];
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(char)pattern[i]] = i;

    int result[100];
    int countMatches = 0;

    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            result[countMatches] = shift;
            countMatches++;

            if (shift + m < n)
                shift += m - badChar[(char)text[shift + m]];
            else
                shift += 1;
        } else {
            int bcIndex = badChar[(char)text[shift + j]];
            int skip = j - bcIndex;
            if (skip < 1) skip = 1;
            shift += skip;
        }
    }

    cout << "Matches at positions: [ ";
    for (int k = 0; k < countMatches; k++)
        cout << result[k] << " ";
    cout << "]" << endl;

    return 0;
}
