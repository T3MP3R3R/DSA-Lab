#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(char c) {
        if (topIndex < 99)
            arr[++topIndex] = c;
    }

    char pop() {
        if (topIndex >= 0)
            return arr[topIndex--];
        return '\0';
    }

    bool isEmpty() { return topIndex == -1; }

    char top() {
        if (topIndex >= 0)
            return arr[topIndex];
        return '\0';
    }
};

bool validateBrackets(const char* text, const char* pattern) {
    Stack st;
    char openB, closeB;

    if (pattern[0] == '0') { // parentheses
        openB = '(';
        closeB = ')';
    } else if (pattern[0] == '1') { // curly braces
        openB = '{';
        closeB = '}';
    } else if (pattern[0] == '2') { // square brackets
        openB = '[';
        closeB = ']';
    } else {
        return false; // unknown pattern
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == openB)
            st.push(openB);
        else if (text[i] == closeB) {
            if (st.isEmpty())
                return false;
            st.pop();
        }
    }

    return st.isEmpty();
}

int main() {
    const char* text1 = "(a + b)";
    const char* text2 = "(a+b";
    const char* pattern = "0";

    cout << "Text: " << text1 << " | Result: "
         << (validateBrackets(text1, pattern) ? "VALID" : "INVALID") << endl;

    cout << "Text: " << text2 << " | Result: "
         << (validateBrackets(text2, pattern) ? "VALID" : "INVALID") << endl;

    return 0;
}