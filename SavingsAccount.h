//SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(int accNum, std::string name, double bal, double rate) 
        : Account(accNum, name, bal), interestRate(rate) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("WITHDRAW", amount));
        }
    }
    
    std::string getAccountType() const override { return "SAVINGS"; }
};
#endif