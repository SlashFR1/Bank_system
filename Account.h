//Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
protected:
    int accountNumber;
    std::string holderName;
    double balance;
    std::vector<Transaction> history;

public:
    Account(int accNum, std::string name, double initialBalance);
    virtual ~Account() {}

    // Encapsulation: Getters
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    std::string getHolderName() const { return holderName; }

    // Logic
    void deposit(double amount);
    virtual void withdraw(double amount) = 0; // Pure virtual for polymorphism
    void showHistory() const;
    
    virtual std::string getAccountType() const = 0;
};

#endif