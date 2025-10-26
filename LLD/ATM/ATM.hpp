#ifndef ATM_HPP
#define ATM_HPP

#include "Account.hpp"
#include <vector>
#include <string>
using namespace std;

class ATM {
private:
    vector<Account*> accounts;
    Account* currentAccount;
    bool isAuthenticated;

public:
    ATM();
    ~ATM();
    
    void addAccount(Account* account);
    bool authenticate(const string& accountNumber, const string& pin);
    void logout();
    
    bool deposit(double amount);
    bool withdraw(double amount);
    void checkBalance() const;
    
    void displayMenu() const;
    void start();
};

#endif 