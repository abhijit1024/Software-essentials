#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
using namespace std;

class Account {
    private:
        string accountNumber;
        string pin;
        double balance;
    public:
        Account(string accountNumber, string pin, double initialBalance = 0.0);

        string getAccountNumber() const;
        bool validatePin(const string& inputPin) const;
        double getBalance() const;

        bool deposit(double amount);
        bool withdraw(double amount);
        void displayBalance() const;
};

#endif