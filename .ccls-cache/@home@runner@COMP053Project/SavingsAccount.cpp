// Amr Mahmoud

#include "SavingsAccount.h"

int SavingsAccount::newAccountNumber = 1000;

SavingsAccount::SavingsAccount() {
    bal = 0;
    accountNumber = newAccountNumber;
    newAccountNumber++;
}

SavingsAccount::SavingsAccount(int bal) {
    this->bal = bal;
    accountNumber = newAccountNumber;
    newAccountNumber++;
}

void SavingsAccount::deposit(int amount) {
    bal += amount;
    cout << "\t| Deposit was successful." << endl;
    cout << "\t| The current balance is " << bal << endl << endl;
}

bool SavingsAccount::withdraw(int amount) {
    if (bal < amount)
        return false;
    bal -= amount;
    cout << "\t| Withdraw was successful." << endl;
    cout << "\t| The current balance is " << bal << endl << endl;
    return true;
}

int SavingsAccount::getAccountNumber() {
    return accountNumber;
}

int SavingsAccount::getBal() {
    return bal;
}

void SavingsAccount::printInfo() {
    cout << "\t| Sub-account number: SAV" << accountNumber << endl;
    cout << "\t| Balance: " << bal << endl << endl;
}

void SavingsAccount::selectionMenu() {
    cout << "\nEligible services for Sub-Account SAV" << accountNumber << endl;
    cout << "\tD -- Deposit" << endl;
    cout << "\tW -- Withdraw" << endl;
    cout << "\tX -- Exit" << endl;
    cout << "Please enter you selection: ";
}

void SavingsAccount::selectionInput() {
    int amount;
    char selection;
    selectionMenu();
    cin >> selection;
    while (selection != 'x') {
        switch(selection) {
            case 'd':
                cout << "\tEnter the amount to deposit: ";
                cin >> amount;
                deposit(amount);
                break;
            case 'w':
                cout << "\tEnter the amount to withdraw: ";
                cin >> amount;
                withdraw(amount);
                break;
        }
        selectionMenu();
        cin >> selection;
    }
    cout << "\t| End of service for sub-account SAV" << accountNumber << endl;
}