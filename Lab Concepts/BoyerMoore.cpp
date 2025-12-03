#include <iostream>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(char* pattern, int size, int badchar[]){
    for(int i=0;i<NO_OF_CHARS;i++) badchar[i]=-1;
    for(int i=0;i<size;i++) badchar[(int)pattern[i]]=i;
}

void BMSearch(char* text, char* pattern){
    int n=0,m=0;
    while(text[n]!='\0') n++;
    while(pattern[m]!='\0') m++;

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pattern,m,badchar);

    int s=0;
    while(s<=n-m){
        int j=m-1;
        while(j>=0 && pattern[j]==text[s+j]) j--;
        if(j<0){
            cout<<"Pattern found at index "<<s<<endl;
            s += (s+m<n)? m - badchar[text[s+m]] : 1;
        } else {
            int shift = j - badchar[text[s+j]];
            s += (shift>1)? shift:1;
        }
    }
}

int main(){
    char text[]="ABAAABCD";
    char pattern[]="ABC";
    BMSearch(text, pattern);
    return 0;
}