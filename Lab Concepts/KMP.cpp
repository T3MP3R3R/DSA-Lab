#include <iostream>
using namespace std;

void computeLPS(char* pattern, int m, int* lps){
    int len=0, i=1;
    lps[0]=0;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++; lps[i]=len; i++;
        } else {
            if(len!=0) len = lps[len-1];
            else { lps[i]=0; i++; }
        }
    }
}

void KMPSearch(char* text, char* pattern){
    int n=0, m=0;
    while(text[n]!='\0') n++;
    while(pattern[m]!='\0') m++;

    int lps[m];
    computeLPS(pattern,m,lps);

    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++; j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j = lps[j-1];
        } else if(i<n && text[i]!=pattern[j]){
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
}

int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}