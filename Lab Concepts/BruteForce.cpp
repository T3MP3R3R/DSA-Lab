#include <iostream>
using namespace std;

void bruteForceSearch(char* text, char* pattern) {
    int n=0, m=0;
    while(text[n]!='\0') n++;
    while(pattern[m]!='\0') m++;

    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && text[i+j]==pattern[j]) j++;
        if(j==m) cout<<"Pattern found at index "<<i<<endl;
    }
}

int main(){
    char text[] = "THIS IS A TEST TEXT";
    char pattern[] = "TEST";
    bruteForceSearch(text, pattern);
    return 0;
}