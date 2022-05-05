// Amr Mahmoud

#include "BankAccount.h"

int BankAccount::newAccountNumber = 10000;

BankAccount::BankAccount() {
    firstName = "None";
    lastName = "None";
    SSN = "None";
    accountNumber = newAccountNumber;
    newAccountNumber++;
	numberOfSavingAccounts = 0;
}

BankAccount::BankAccount(string firstName, string lastName, string SSN) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->SSN = SSN;
    accountNumber = newAccountNumber;
    newAccountNumber++;
	numberOfSavingAccounts = 0;
}

int BankAccount::getAccountNumber() {
    return accountNumber;
}

int BankAccount::getTotalBal() {
    int totalBalance = 0;
    for (auto account : savingSubAccounts)
        totalBalance += account.getBal();
    for (auto account : checkingSubAccounts)
        totalBalance += account.getBal();
    return totalBalance;
}

string BankAccount::getFirstName() {
    return firstName;
}

string BankAccount::getLastName() {
    return lastName;
}

string BankAccount::getSSN() {
    return SSN;
}

void BankAccount::selectionMenu() {
    cout << "\nEligible services for Bank-Account BNK" << accountNumber << endl;
    cout << "\tS -- Open Saving Sub-Account" << endl;
    cout << "\tC -- Open Checking Sub-Account" << endl;
    cout << "\tM -- Modify a Sub-Account" << endl;
    cout << "\tE -- Close a Sub-Account" << endl;
    cout << "\tD -- Detailed Bank Account Info" << endl;
    cout << "\tB -- Brief Bank Account Info" << endl;
    cout << "\tX -- Exit" << endl;
    cout << "Please enter you selection: ";
}

void BankAccount::selectionInput() {
    char selection;
    selectionMenu();
    cin >> selection;
    while (selection != 'x') {
        switch(selection) {
			case 'S':
            case 's':
                openSavingAccount();
                break;
			case 'C':
            case 'c':
                openCheckingAccount();
                break;
			case 'M':
            case 'm':
                modifyAccount();
                break;
			case 'E':
            case 'e':
                closeAccount();
                break;
			case 'D':
            case 'd':
                printDetailedInfo();
                break;
			case 'B':
            case 'b':
                printInfo();
                break;
        }
        selectionMenu();
        cin >> selection;
    }
    cout << "\t| End of service for bank-account BNK" << accountNumber << endl;
}

void BankAccount::openSavingAccount() {
    int initBalance = 0;
    cout << "\tEnter the initial balance: ";
    cin >> initBalance;
    SavingsAccount newAccount(initBalance);

    cout << "\n\t| A new Saving Sub-Account SAV" << newAccount.getAccountNumber() << " was successfully created." << endl << endl;

    incrementNumberOfSavingAccounts();
    savingSubAccounts.push_back(newAccount);
}

void BankAccount::openCheckingAccount() {
    int initBalance = 0;
    int maxCap = 0;
    char locked;
    cout << "\tEnter the initial balance: ";
    cin >> initBalance;
    cout << "\tEnter the desired maximum capacity: ";
    cin >> maxCap;
    cout << "\tDefine initial state: (L - Locked, Otherwise - Unlocked)";
    cin >> locked;
    CheckingAccount newAccount(initBalance, maxCap, locked == 'l');
    checkingSubAccounts.push_back(newAccount);
    cout << "\n\t| A new Checking Sub-Account CHK" << newAccount.getAccountNumber() << " was successfully created." << endl << endl;
}

void BankAccount::printInfo() {
    cout << "\t| Aggregated Balance of the bank account : BNK" << accountNumber << " with " << savingSubAccounts.size() + checkingSubAccounts.size() << " Sub-Accounts is " << getTotalBal() << endl << endl;
}

void BankAccount::printDetailedInfo() {
    cout << endl;
    for (auto account : savingSubAccounts)
        account.printInfo();
    for (auto account : checkingSubAccounts)
        account.printInfo();
}

void BankAccount::modifyAccount() {
    string fullAccountNum;
    string accountType;
    int num;
    cout << "\tEnter the sub-account number to modify:";
    cin >> fullAccountNum;

    accountType = fullAccountNum.substr(0,3);
    num = stoi(fullAccountNum.substr(3,4));

    if (accountType == "CHK") {
        for(auto &account : checkingSubAccounts) {
            if (account.getAccountNumber() == num)
                account.selectionInput();
        }
    }
    else if (accountType == "SAV") {
        for (auto &account : savingSubAccounts) {
            if (account.getAccountNumber() == num)
                account.selectionInput();
        }
    }
}

void BankAccount::closeAccount() {
    string fullAccountNum;
    string accountType;
    int num;
    cout << "\tEnter the sub-account to be closed:";
    cin >> fullAccountNum;

    accountType = fullAccountNum.substr(0,3);
    num = stoi(fullAccountNum.substr(3,4));

    if (accountType == "CHK") {
        vector<CheckingAccount>::iterator i = checkingSubAccounts.begin();
        while (i != checkingSubAccounts.end()) {
            if (i->getAccountNumber() == num) {
                checkingSubAccounts.erase(i);
				decrementNumberOfSavingAccounts();
                cout << "\t| Sub-account " << fullAccountNum << " was successfully closed" << endl;
                i--;
            }
            i++;
        }
    }

    else if (accountType == "SAV") {
        vector<SavingsAccount>::iterator i = savingSubAccounts.begin();
        while (i != savingSubAccounts.end()){
            if(i->getAccountNumber() == num) {
                savingSubAccounts.erase(i);
				decrementNumberOfSavingAccounts();
                cout << "\t| Sub-account " << fullAccountNum << " was successfully closed" << endl;
                i--;
            }
            i++;
        }
    }
}

int BankAccount::getTotalSavingAccounts() {
    return numberOfSavingAccounts;
}

void BankAccount::incrementNumberOfSavingAccounts() {
    this->numberOfSavingAccounts++;
}

void BankAccount::decrementNumberOfSavingAccounts() {
	this->numberOfSavingAccounts--;
}

int BankAccount::getTotalCheckingAccounts() {
    return checkingSubAccounts.size();
}