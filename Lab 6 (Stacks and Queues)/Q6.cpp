#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(const string &infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == ' ') continue;

        if (isalnum(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && ((precedence(st.top()) > precedence(c)) ||
                   (precedence(st.top()) == precedence(c) && c != '^')) && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

int main() {
    string expr = "a+b*(c^d-e)^(f+g*h)-i";

    string postfix = infixToPostfix(expr);

    cout << "Postfix Expression:" << endl << postfix << endl;

    return 0;
}