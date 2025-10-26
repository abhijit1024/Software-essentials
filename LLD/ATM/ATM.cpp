#include "ATM.hpp"
#include <iostream>
#include <limits>
using namespace std;

ATM::ATM() : currentAccount(nullptr), isAuthenticated(false) {}

ATM::~ATM() {
    for (auto account : accounts) {
        delete account;
    }
}

void ATM::addAccount(Account* account) {
    accounts.push_back(account);
}

bool ATM::authenticate(const string& accountNumber, const string& pin) {
    for (auto account : accounts) {
        if (account->getAccountNumber() == accountNumber && account->validatePin(pin)) {
            currentAccount = account;
            isAuthenticated = true;
            return true;
        }
    }
    return false;
}

void ATM::logout() {
    currentAccount = nullptr;
    isAuthenticated = false;
}

bool ATM::deposit(double amount) {
    if (!isAuthenticated || !currentAccount) return false;
    return currentAccount->deposit(amount);
}

bool ATM::withdraw(double amount) {
    if (!isAuthenticated || !currentAccount) return false;
    return currentAccount->withdraw(amount);
}

void ATM::checkBalance() const {
    if (!isAuthenticated || !currentAccount) return;
    currentAccount->displayBalance();
}

void ATM::displayMenu() const {
    cout << "\nATM Menu:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Logout" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void ATM::start() {
    string accountNumber, pin;
    int choice;
    double amount;

    while (true) {
        if (!isAuthenticated) {
            cout << "\nWelcome to ATM" << endl;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;

            if (!authenticate(accountNumber, pin)) {
                cout << "Invalid account number or PIN" << endl;
                continue;
            }
            cout << "Authentication successful!" << endl;
        }

        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                checkBalance();
                break;

            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (deposit(amount)) {
                    cout << "Deposit successful" << endl;
                    checkBalance();
                } else {
                    cout << "Invalid amount" << endl;
                }
                break;

            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (withdraw(amount)) {
                    cout << "Withdrawal successful" << endl;
                    checkBalance();
                } else {
                    cout << "Invalid amount or insufficient funds" << endl;
                }
                break;

            case 4:
                logout();
                cout << "Logged out successfully" << endl;
                break;

            case 5:
                cout << "Thank you for using ATM. Goodbye!" << endl;
                return;

            default:
                cout << "Invalid choice" << endl;
        }
    }
} 