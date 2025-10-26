#include "Account.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Account::Account(string accountNumber, string pin, double initialBalance)
    : accountNumber(accountNumber), pin(pin), balance(initialBalance) {}

string Account::getAccountNumber() const {
    return accountNumber;
}

bool Account::validatePin(const string& inputPin) const {
    return pin == inputPin;
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount) {
    if (amount <= 0) return false;
    
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    
    balance -= amount;
    return true;
}

void Account::displayBalance() const {
    cout << "Current balance: $" << fixed << setprecision(2) << balance << endl;
} 