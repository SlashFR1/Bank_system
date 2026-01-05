//main.cpp

#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>

int main() {
    Bank engineeringBank;

    // Creating sample accounts
    engineeringBank.addAccount(std::make_unique<SavingsAccount>(101, "Alice", 5000.0, 3.5));
    engineeringBank.addAccount(std::make_unique<CheckingAccount>(102, "Bob", 1000.0, 500.0));

    int choice, id;
    double amt;

    while (true) {
        std::cout << "\n1. List Accounts\n2. Deposit\n3. Withdraw\n4. History\n5. Exit\nSelection: ";
        std::cin >> choice;

        if (choice == 5) break;

        if (choice >= 2 && choice <= 4) {
            std::cout << "Enter Account ID: ";
            std::cin >> id;
            Account* acc = engineeringBank.findAccount(id);
            if (!acc) { std::cout << "Not found!\n"; continue; }

            if (choice == 2) { 
                std::cout << "Amount: "; std::cin >> amt; acc->deposit(amt); 
            } else if (choice == 3) { 
                std::cout << "Amount: "; std::cin >> amt; acc->withdraw(amt); 
            } else { 
                acc->showHistory(); 
            }
        } else if (choice == 1) {
            engineeringBank.listAccounts();
        }
    }

    engineeringBank.saveToFile();
    return 0;
}