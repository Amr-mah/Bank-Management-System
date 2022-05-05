// Amr Mahmoud

#ifndef Bank_H_
#define Bank_H_

#include "BankAccount.h"
#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    string name;
    string address;
    string workingHours;
    vector<BankAccount> v;

public:
    Bank();
    void openBank();
    void openBankAccount();
    void numBankAccounts();
    void numSavingAccounts();
    void numCheckingAccounts();
    void printInfo();
    void printDetailedInfo();
    void selectionMenu();
    void selectionInput();
    int getTotalBal();
    void modifyBankAccount();
    void closeBankAccount();
};



#endif