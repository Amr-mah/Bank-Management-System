// Amr Mahmoud

#ifndef BankAccount_H_
#define BankAccount_H_

#include <string>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <vector>
using namespace std;

class BankAccount {
private:
    string firstName;
    string lastName;
    string SSN;
    int accountNumber;
    int numberOfSavingAccounts;
    static int newAccountNumber;
    vector<SavingsAccount> savingSubAccounts;
    vector<CheckingAccount> checkingSubAccounts;

public:
    BankAccount();
    BankAccount(string firstName, string lastName, string SSN);
    void openSavingAccount();
    void openCheckingAccount();
    void modifyAccount();
    void closeAccount();
    void printDetailedInfo();
    void printInfo();
    int getAccountNumber();
    string getFirstName();
    string getLastName();
    string getSSN();
    void selectionMenu();
    void selectionInput();
    int getTotalBal();
    int getTotalSavingAccounts();
    void incrementNumberOfSavingAccounts();
	void decrementNumberOfSavingAccounts();
    int getTotalCheckingAccounts();

};

#endif