// Amr Mahmoud

#ifndef CheckingAccount_H_
#define CheckingAccount_H_

#include <iostream>
using namespace std;

class CheckingAccount {
private:
    int accountNumber;
    static int newAccountNumber;
    unsigned int maxCap;
    bool locked;
    int bal;

public:
    CheckingAccount();
    CheckingAccount(int bal, int maxCap, bool locked);
    bool deposit(int amount);
    bool withdraw(int amount);
    void setMaxCap(unsigned int maxCap);
    void lockAccount();
    void unlockAccount();
    int getAccountNumber();
    int getBal();
    void printInfo();
    void selectionMenu();
    void selectionInput();
    void changeMaxCap();
};

#endif