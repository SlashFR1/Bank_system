//Bank.h


#ifndef BANK_H
#define BANK_H

#include <vector>
#include <memory>
#include "Account.h"

class Bank {
private:
    std::vector<std::unique_ptr<Account>> accounts;
    const std::string dbFile = "bank_data.csv";

public:
    void addAccount(std::unique_ptr<Account> acc);
    Account* findAccount(int accNum);
    void listAccounts() const;
    void saveToFile() const;
    void loadFromFile();
};

#endif