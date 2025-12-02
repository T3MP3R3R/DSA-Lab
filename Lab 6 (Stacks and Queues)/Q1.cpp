#include <iostream>
#include <string>
using namespace std;

class Stack{
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack(){
        delete[] arr;
    }

    void push(char c){
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop(){
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isPalindrome(string s){
    int n = s.length();
    int mid = n/2;

    Stack stk(mid);

    for (int i = 0; i < mid; i++) stk.push(s[i]);

    int start = (n % 2 == 0) ? mid : mid + 1;

    for (int i = start; i < n; i++) {
        if (s[i] != stk.pop()) return false;
    }
    return true;
}

int main(){
    string s = "BORROWROB";

    if (isPalindrome(s)) {
        cout << s << " is a palindrome" << endl;
    } else {
        cout << s << " is not a palindrome" << endl;
    }
    return 0;
}
