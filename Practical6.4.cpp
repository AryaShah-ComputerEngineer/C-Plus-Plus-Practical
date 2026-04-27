#include <iostream>
using namespace std;


class Account {
protected:
    int accNumber;
    double balance;
    string transactions[10];  
    int count;

public:
    Account(int acc, double bal) {
        accNumber = acc;
        balance = bal;
        count = 0;
        cout << "Account Created\n";
    }

    ~Account() {
        cout << "Account Deleted\n";
        
    }

    void deposit(double amount) {
        balance += amount;
        if (count < 10) {
            transactions[count++] = "Deposited: " + to_string(amount);
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            if (count < 10) {
                transactions[count++] = "Withdrawn: " + to_string(amount);
            }
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < count; i++) {
            cout << transactions[i] << endl;
        }
    }

    void undoLastTransaction() {
        if (count == 0) {
            cout << "No transactions to undo\n";
            return;
        }

        string last = transactions[count - 1];
        count--;

        if (last.find("Deposited") != string::npos) {
            double amt = stod(last.substr(last.find(":") + 1));
            balance -= amt;
        } else if (last.find("Withdrawn") != string::npos) {
            double amt = stod(last.substr(last.find(":") + 1));
            balance += amt;
        }

        cout << "Last transaction undone\n";
    }

    void display() {
        cout << "Account No: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};


class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(int acc, double bal, double rate)
        : Account(acc, bal) {
        interestRate = rate;
    }

    ~SavingsAccount() {
        cout << "Savings Account Closed\n";
    }

    void displaySavings() {
        display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};


class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(int acc, double bal, double limit)
        : Account(acc, bal) {
        overdraftLimit = limit;
    }

    ~CurrentAccount() {
        cout << "Current Account Closed\n";
    }

    void withdrawCurrent(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            if (count < 10) {
                transactions[count++] = "Withdrawn: " + to_string(amount);
            }
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void displayCurrent() {
        display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};


int main() {
    SavingsAccount s(101, 5000, 3.5);
    s.deposit(1000);
    s.withdraw(2000);
    s.displaySavings();
    s.showTransactions();
    s.undoLastTransaction();
    s.displaySavings();

    cout << "\n------------------\n";

    CurrentAccount c(202, 3000, 2000);
    c.deposit(500);
    c.withdrawCurrent(4000);
    c.displayCurrent();
    c.showTransactions();

    return 0;
}