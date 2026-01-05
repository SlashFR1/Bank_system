//Bank.cpp


#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Implementation of Account methods (defined here for brevity)
Account::Account(int accNum, std::string name, double bal) 
    : accountNumber(accNum), holderName(name), balance(bal) {}

void Account::deposit(double amount) {
    balance += amount;
    history.push_back(Transaction("DEPOSIT", amount));
}

void Account::showHistory() const {
    std::cout << "\nHistory for #" << accountNumber << ":" << std::endl;
    for (const auto& tx : history) {
        std::cout << tx.timestamp << " | " << tx.type << " | $" << tx.amount << std::endl;
    }
}

// Bank methods
void Bank::addAccount(std::unique_ptr<Account> acc) {
    accounts.push_back(std::move(acc));
}

Account* Bank::findAccount(int accNum) {
    for (auto& acc : accounts) {
        if (acc->getAccountNumber() == accNum) return acc.get();
    }
    return nullptr;
}

void Bank::saveToFile() const {
    std::ofstream file(dbFile);
    for (const auto& acc : accounts) {
        file << acc->getAccountType() << "," << acc->getAccountNumber() << "," 
             << acc->getHolderName() << "," << acc->getBalance() << "\n";
    }
}

void Bank::listAccounts() const {
    for (const auto& acc : accounts) {
        std::cout << acc->getAccountType() << " | ID: " << acc->getAccountNumber() 
                  << " | Name: " << acc->getHolderName() << " | Bal: $" << acc->getBalance() << std::endl;
    }
}