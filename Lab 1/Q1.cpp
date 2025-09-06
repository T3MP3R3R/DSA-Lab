#include <iostream>
using namespace std;

class BankAccount{
private:
    double balance;
public:
    BankAccount(){     // Default
        balance = 0.0;
    }

    BankAccount(double initBal){     // Parameterized
        balance = initBal;
    }

    BankAccount(const BankAccount &other){    // Copy
        balance = other.balance;
    }
    void withdraw(double amount){
            balance -= amount;
    }
    double getBal() const{
        return balance;
    }
};

int main() {
    BankAccount acc1;
    cout << "Balance of account 1: $" << acc1.getBal() << endl;
    BankAccount acc2(1000.0);
    cout << "Balance of account 2: $" << acc2.getBal() << endl;
    BankAccount acc3(acc2);
    acc3.withdraw(200);
    cout << "Balance of account 3 after withdrawal: $" << acc3.getBal() << endl;
    cout << "Balance of account 2: $" << acc2.getBal() << endl; // Unchanged

    return 0;
}
