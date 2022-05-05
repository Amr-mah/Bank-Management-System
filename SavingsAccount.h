// Amr Mahmoud

#ifndef SavingsAccount_H_
#define SavingsAccount_H_

#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    static int newAccountNumber;
    int bal;

public:
    SavingsAccount();
    SavingsAccount(int bal);
    void deposit(int amount);
    bool withdraw(int amount);
    int getAccountNumber();
    int getBal();
    void printInfo();
    void selectionMenu();
    void selectionInput();
};

#endif