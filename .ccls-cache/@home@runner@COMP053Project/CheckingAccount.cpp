#include "CheckingAccount.h"

int CheckingAccount::newAccountNumber = 6000;

CheckingAccount::CheckingAccount() {
    bal = 0;
    maxCap = 0;
    locked = false;
    accountNumber = newAccountNumber;
    newAccountNumber++;
}

CheckingAccount::CheckingAccount(int bal, int maxCap, bool locked) {
    this->bal = bal;
    this->maxCap = maxCap;
    this->locked = locked;
    accountNumber = newAccountNumber;
    newAccountNumber++;
}

int CheckingAccount::getAccountNumber() {
    return accountNumber;
}

int CheckingAccount::getBal() {
    return bal;
}

bool CheckingAccount::deposit(int amount) {
    if (locked) {
        cout << "\t| The account is currently locked!" << endl;
        cout << "\t| The deposit was unsuccessful" << endl;
        return false;
    }
    else if (bal + amount > maxCap) {
        cout << "\t| Unable to deposit - funds exceed max capacity" << endl;
        return false;
    }
    bal += amount;
    cout << "\t| Deposit was successful." << endl;
    cout << "\t| The current balance is " << bal << endl << endl;
    return true;
}

bool CheckingAccount::withdraw(int amount) {
    if (locked) {
        cout << "\t| The account is currently locked!" << endl;
        cout << "\t| The withdraw was unsuccessful" << endl;
        return false;
    }
    else if (bal < amount) {
        cout << "\t| Unable to withdraw - insufficient funds" << endl;
        return false;
    }
    bal -= amount;
    cout << "\t| Withdraw was successful." << endl;
    cout << "\t| The current balance is " << bal << endl << endl;
    return true;
}

void CheckingAccount::setMaxCap(unsigned int maxCap) {
    this->maxCap = maxCap;
}

void CheckingAccount::lockAccount() {
    locked = true;
    cout << "\t| The sub-account CHK" << accountNumber << " is now locked" << endl;
}

void CheckingAccount::unlockAccount() {
    locked = false;
    cout << "\t| The sub-account CHK" << accountNumber << " is now unlocked" << endl;
}

void CheckingAccount::printInfo() {
    cout << "\t| Sub-account number: CHK" << accountNumber << endl;
    cout << "\t| Balance: " << bal << endl << endl;

    cout << "\t| The maximum capacity is: " << maxCap << endl;
    cout << "\t| The sub-account is ";
    if (locked)
        cout << "locked";
    else
        cout << "unlocked";
    cout << endl << endl;
}

void CheckingAccount::selectionMenu() {
    cout << "\nEligible services for Sub-Account CHK" << accountNumber << endl;
    cout << "\tD -- Deposit" << endl;
    cout << "\tW -- Withdraw" << endl;
    cout << "\tC -- Max Capacity" << endl;
    cout << "\tL -- Lock Sub-Account" << endl;
    cout << "\tU -- Unlock Sub-Account" << endl;
    cout << "\tX -- Exit" << endl;
    cout << "Please enter you selection: ";
}

void CheckingAccount::selectionInput() {
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
            case 'c':
                changeMaxCap();
                break;
            case 'l':
                lockAccount();
                break;
            case 'u':
                unlockAccount();
                break;
        }
        selectionMenu();
        cin >> selection;
    }
    cout << "\t| End of service for sub-account CHK" << accountNumber << endl;
}

void CheckingAccount::changeMaxCap() {
    char input;
    cout << "The maximum capacity on this account is currently: " << maxCap << endl;
    cout << "Would you like to change it(Y/N)?";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "New maximum capacity: ";
        cin >> maxCap;
    }
}