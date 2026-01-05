//Transaction.h
    
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

struct Transaction {
    std::string type;
    double amount;
    std::string timestamp;

    Transaction(std::string t, double amt) : type(t), amount(amt) {
        time_t now = time(0);
        char* dt = ctime(&now);
        timestamp = std::string(dt);
        timestamp.pop_back(); // Remove newline
    }
};

#endif

  