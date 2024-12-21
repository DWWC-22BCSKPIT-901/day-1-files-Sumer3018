#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double bal) : balance(bal) {}
    virtual void calculateInterest() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double rate;
    int time;
public:
    SavingsAccount(double bal, double r, int t) : Account(bal), rate(r), time(t) {}
    void calculateInterest() override {
        double interest = balance * (rate / 100) * time;
        cout << fixed << setprecision(2) << "Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
    double maintenanceFee;
public:
    CurrentAccount(double bal, double fee) : Account(bal), maintenanceFee(fee) {}
    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << fixed << setprecision(2) << "Remaining Balance after Maintenance Fee: " << balance << endl;
    }
};

int main() {
    int accountType;
    cout<<"1: for Savings Account\n2: for Current Account";
    cin >> accountType;

    if (accountType == 1) {
        double balance, rate;
        int time;
        cout<<"Balance,Rate,Time";
        cin >> balance >> rate >> time;
        SavingsAccount sa(balance, rate, time);
        sa.calculateInterest();
    } else if (accountType == 2) {
        double balance, maintenanceFee;
        cout<<"Balance,Maintenance Fee";
        cin >> balance >> maintenanceFee;
        CurrentAccount ca(balance, maintenanceFee);
        ca.calculateInterest();
    }

    return 0;
}
