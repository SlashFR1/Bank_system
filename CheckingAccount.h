//CheckingAccount.h

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;
public:
    CheckingAccount(int accNum, std::string name, double bal, double limit) 
        : Account(accNum, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= (balance + overdraftLimit)) {
            balance -= amount;
            history.push_back(Transaction("WITHDRAW", amount));
        }
    }

    std::string getAccountType() const override { return "CHECKING"; }
};
#endif