#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Transaction{
public:
    int id;
    double amount;
    string description;
    int flag;
    Transaction() : id(0), amount(0), description(""), flag(1) {}
    
    Transaction(int id, double amount, string desc) : id(id), amount(amount), description(desc){
        flag = (amount >= 0) ? 1 : 0;
    }
};

struct Node{
    Transaction data;
    Node* next;
    Node(Transaction t) : data(t), next(nullptr) {}
};

class Stack{
private:
    Node* topNode;
    int nextID;

    string truncateDesc(const string& desc) {
        if ((int)desc.length() > 20)
            return desc.substr(0, 17) + "...";
        return desc;
    }

    double applyDiscount(double amt) {
        if (amt >= 1500) return amt * 0.7;
        else if (amt >= 1000) return amt * 0.85;
        else if (amt >= 500) return amt * 0.95;
        else return amt;
    }

public:
    Stack() : topNode(nullptr), nextID(1) {}

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(Transaction t) {
        t.id = nextID++;
        t.description = truncateDesc(t.description);

        if (t.amount >= 0) {
            t.amount = applyDiscount(t.amount);
            t.flag = 1;
        } else {
            t.flag = 0;
        }

        Node* newNode = new Node(t);
        newNode->next = topNode;
        topNode = newNode;

        cout << t.id << ". " << (t.flag == 1 ? "Sale: " : "Refund: ") << t.description
             << " (" << t.amount << ")";
        if (t.flag == 1) {
            if (t.amount >= 1500) cout << " -> Discount 30%";
            else if (t.amount >= 1000) cout << " -> Discount 15%";
            else if (t.amount >= 500) cout << " -> Discount 5%";
            else cout << " -> No discount";
        }
        cout << endl;
    }

    Transaction pop(){
        if (isEmpty()) {
            cout << "Stack empty, cannot pop." << endl;
            return Transaction();
        }
        Node* temp = topNode;
        topNode = topNode->next;

        temp->data.amount *= -1;
        temp->data.description += " [REVERSED]";
        temp->data.flag = 2;

        Transaction popped = temp->data;
        delete temp;
        return popped;
    }

    void display(){
        cout << "Current Stack (top to bottom):" << endl;
        Node* curr = topNode;
        while (curr) {
            cout << "[id=" << curr->data.id << ", amt=" << curr->data.amount
                 << ", desc=\"" << curr->data.description << "\", flag=" << curr->data.flag << "]" << endl;
            curr = curr->next;
        }
    }
};

int main() {
    srand(time(0));
    Transaction transactions[7] = {
        Transaction(0, 1200, "Sale: Blue Jacket"),
        Transaction(0, 450, "Sale: Cotton Socks"),
        Transaction(0, -300, "Refund: Defective Shirt"),
        Transaction(0, 1700, "Sale: Leather Jacket"),
        Transaction(0, 1600, "Sale: High-End Watch"),
        Transaction(0, -150, "Refund: Broken Umbrella"),
        Transaction(0, 700, "Sale: Casual Sneakers")
    };

    Stack stack;

    cout << "Pushing Transactions:" << endl;
    for (int i = 0; i < 4; i++) {
        int idx = rand() % 7;
        stack.push(transactions[idx]);
    }

    cout << endl;
    stack.display();
    cout << endl << "Popping one transaction:" << endl;
    Transaction popped = stack.pop();
    cout << "Popped Transaction: " << popped.description << endl << "Amount changed to " << popped.amount
         << endl << "Flag updated to " << popped.flag << endl;
    cout << endl << "Stack after pop:" << endl;
    stack.display();

    return 0;

}
