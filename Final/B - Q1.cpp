#include <iostream>
#include <string>
using namespace std;

class DocumentQueue {
    string arr[100];
    int front, rear;
public:
    DocumentQueue() { front = 0; rear = -1; }

    void enqueue(string docName) {
        rear++;
        arr[rear] = docName;
        cout << "Enqueued Document: " << docName << endl;
    }

    string dequeue() {
        if (isEmpty()) return "";
        string doc = arr[front];
        front++;
        return doc;
    }

    bool isEmpty() { return front > rear; }
};

class ReferenceStack {
    string arr[100];
    int topIndex;
public:
    ReferenceStack() { topIndex = -1; }

    void push(string filename) {
        topIndex++;
        arr[topIndex] = filename;
        cout << "Pushed reference: " << filename << endl;
    }

    void pop() {
        if (!isEmpty())
            cout << "Popped reference: " << arr[topIndex--] << endl;
    }

    string topElement() {
        if (!isEmpty()) return arr[topIndex];
        return "";
    }

    bool isEmpty() { return topIndex == -1; }
};

void buildLPS(string pattern, int lps[]) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();
    int lps[m];
    buildLPS(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) { i++; j++; }
        if (j == m) {
            cout << "A Detected term: \"" << pattern << "\" at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    DocumentQueue dq;
    ReferenceStack rs;

    dq.enqueue("Document A");
    dq.enqueue("Document B");
    dq.enqueue("Document C");

    string doc = dq.dequeue();
    cout << "Processing: " << doc << endl;
    string docText = "This is a confidential memo regarding case number 88221. The details are sensitive and must be handled carefully.";
    cout << "Document Text: " << docText << endl;

    rs.push("Legal Notes");
    rs.push("Amendment Summary");
    cout << "Current reference: " << rs.topElement() << endl;
    cout << "Scanning for important legal terms..." << endl;
    string legalTerms[] = {"confidential", "case number", "privileged", "unauthorized"};
    for (int i = 0; i < 4; i++) {
        KMPSearch(docText, legalTerms[i]);
    }

    rs.pop();
    rs.pop();

    return 0;
}