#include <iostream>
using namespace std;

#define d 256
#define q 101

void rabinKarp(char* text, char* pattern) {
    int n=0, m=0;
    while(text[n]!='\0') n++;
    while(pattern[m]!='\0') m++;

    int h=1;
    for(int i=0;i<m-1;i++) h = (h*d)%q;

    int p=0, t=0;
    for(int i=0;i<m;i++){
        p=(d*p + pattern[i])%q;
        t=(d*t + text[i])%q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            int j;
            for(j=0;j<m;j++)
                if(text[i+j]!=pattern[j]) break;
            if(j==m) cout<<"Pattern found at index "<<i<<endl;
        }
        if(i<n-m){
            t = (d*(t - text[i]*h) + text[i+m])%q;
            if(t<0) t+=q;
        }
    }
}

int main(){
    char text[]="ABCCDDAEFG";
    char pattern[]="CDD";
    rabinKarp(text, pattern);
    return 0;
}