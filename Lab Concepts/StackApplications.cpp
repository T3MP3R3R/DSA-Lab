#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack {
    int top;
    char arr[100];
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }
    void push(char c) {
        if (isFull()) { cout << "Stack Overflow\n"; return; }
        arr[++top] = c;
    }
    char pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return '\0'; }
        return arr[top--];
    }
    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// Utility functions
int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

bool isOperator(char c) { return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

// ---------------- Infix to Postfix ----------------
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int k=0;
    for(int i=0; infix[i]!='\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) postfix[k++] = c;
        else if(c=='(') s.push(c);
        else if(c==')') {
            while(!s.isEmpty() && s.peek()!='(') postfix[k++] = s.pop();
            s.pop(); // remove '('
        } else if (isOperator(c)) {
            while(!s.isEmpty() && precedence(s.peek())>=precedence(c)) postfix[k++] = s.pop();
            s.push(c);
        }
    }
    while(!s.isEmpty()) postfix[k++] = s.pop();
    postfix[k]='\0';
}

// ---------------- Infix to Prefix ----------------
void reverseStr(char str[]) {
    int len = strlen(str);
    for(int i=0,j=len-1;i<j;i++,j--) { char t=str[i]; str[i]=str[j]; str[j]=t; }
}

void infixToPrefix(char infix[], char prefix[]) {
    reverseStr(infix);
    for(int i=0; infix[i]!='\0'; i++) {
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }
    char postfix[100];
    infixToPostfix(infix,postfix);
    reverseStr(postfix);
    strcpy(prefix,postfix);
}

// ---------------- Postfix Evaluation ----------------
int evalPostfix(char postfix[]) {
    int stack[50], top=-1;
    for(int i=0; postfix[i]!='\0'; i++){
        char c = postfix[i];
        if(isdigit(c)) stack[++top] = c - '0';
        else {
            int b=stack[top--]; int a=stack[top--];
            if(c=='+') stack[++top]=a+b;
            else if(c=='-') stack[++top]=a-b;
            else if(c=='*') stack[++top]=a*b;
            else if(c=='/') stack[++top]=a/b;
        }
    }
    return stack[top];
}

// ---------------- Prefix Evaluation ----------------
int evalPrefix(char prefix[]) {
    int stack[50], top=-1;
    int len = strlen(prefix);
    for(int i=len-1;i>=0;i--){
        char c=prefix[i];
        if(isdigit(c)) stack[++top] = c-'0';
        else {
            int a=stack[top--]; int b=stack[top--];
            if(c=='+') stack[++top]=a+b;
            else if(c=='-') stack[++top]=a-b;
            else if(c=='*') stack[++top]=a*b;
            else if(c=='/') stack[++top]=a/b;
        }
    }
    return stack[top];
}

int main() {
    char infix[100];
    cout<<"Enter infix expression (single-digit operands): ";
    cin>>infix;

    char postfix[100], prefix[100];
    infixToPostfix(infix,postfix);
    infixToPrefix(infix,prefix);

    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Prefix: "<<prefix<<endl;
    cout<<"Postfix Evaluation: "<<evalPostfix(postfix)<<endl;
    cout<<"Prefix Evaluation: "<<evalPrefix(prefix)<<endl;

    return 0;
}