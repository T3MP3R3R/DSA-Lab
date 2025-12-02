#include <iostream>
using namespace std;

int main() {
    string text = "Data structures and Algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int n = text.length();
    int m = pattern.length();

    int base = 256;
    int mod = 101;

    int result[100]; 
    int countMatches = 0;

    int collisions[100];
    int countCollisions = 0;

    long long patternHash = 0;
    long long windowHash = 0;
    long long h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {

        if (windowHash == patternHash) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                result[countMatches] = i;
                countMatches++;
            } else {
                collisions[countCollisions] = i;
                countCollisions++;
            }
        }
        if (i < n - m) {
            windowHash = (base * (windowHash - text[i] * h) + text[i + m]) % mod;
            if (windowHash < 0)
                windowHash += mod;
        }
    }

    cout << "Matches at positions: [ ";
    for (int i = 0; i < countMatches; i++)
        cout << result[i] << " ";
    cout << "]" << endl;
    cout << "False-positive hashes: ";
    for (int i = 0; i < countCollisions; i++)
        cout << collisions[i] << " ";

    return 0;
}
