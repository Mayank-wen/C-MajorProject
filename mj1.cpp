#include <iostream>
using namespace std;

class Account {
protected:
    string name;
    string acc_number;
    string acc_type;
    float balance;

public:
    Account(string name, string acc_number, string acc_type) : name(name), acc_number(acc_number), acc_type(acc_type), balance(0) {}

    void deposit(float amount) {
        balance += amount;
        cout << "Deposit of " << amount << " successfully made. New balance: " << balance << endl;
    }

    void display_balance() {
        cout << "Account Balance: " << balance << endl;
    }
};

class CurrentAccount : public Account {
private:
    float min_balance;

public:
    CurrentAccount(string name, string acc_number) : Account(name, acc_number, "Current"), min_balance(1000) {}

    void check_minimum_balance() {
        if (balance < min_balance) {
            float penalty = 100; // Penalty for going below minimum balance
            balance -= penalty;
            cout << "Minimum balance not maintained. Penalty of " << penalty << " imposed." << endl;
        }
    }

    void withdraw(float amount) {
        if (balance - amount < min_balance) {
            cout << "Cannot withdraw. Minimum balance constraint will be violated." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successfully made. New balance: " << balance << endl;
        }
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string name, string acc_number) : Account(name, acc_number, "Savings") {}

    void compute_interest(float rate) {
        float interest = balance * (rate / 100);
        balance += interest;
        cout << "Interest of " << interest << " computed and deposited. New balance: " << balance << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successfully made. New balance: " << balance << endl;
        }
    }
};

int main() {
    CurrentAccount current_acc("John Doe", "C1001");
    current_acc.deposit(5000);
    current_acc.display_balance();
    current_acc.check_minimum_balance();
    current_acc.withdraw(3000);
    current_acc.check_minimum_balance();
    current_acc.display_balance();

    SavingsAccount savings_acc("Jane Smith", "S2001");
    savings_acc.deposit(10000);
    savings_acc.display_balance();
    savings_acc.compute_interest(5); // 5% interest rate
    savings_acc.display_balance();
    savings_acc.withdraw(2000);
    savings_acc.display_balance();

    return 0;
}
