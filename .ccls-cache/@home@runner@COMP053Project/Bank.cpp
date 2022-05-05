// Amr Mahmoud

#include "Bank.h"

Bank::Bank() {
    name = "NoName";
    address = "NoAddress";
    workingHours = "None";
}

void Bank::openBank() {
    cout << "Enter the name of the bank:";
    getline(cin, name);
    cout << "Enter the address of the bank:";
    getline(cin, address);
    cout << "Enter the working hours:";
    getline(cin, workingHours);
}

void Bank::selectionMenu() {
    cout << "\nEligiable services for " << name << endl;
    cout << "\tA -- Number of Bank-Accounts" << endl;
    cout << "\tS -- Number of Saving-Accounts" << endl;
    cout << "\tH -- Number of Checking-Accounts" << endl;
    cout << "\tO -- Open Bank-Account" << endl;
    cout << "\tC -- Close Bank-Account" << endl;
    cout << "\tM -- Modify Bank-Account" << endl;
    cout << "\tD -- Detailed Bank-Accounts" << endl;
    cout << "\tB -- Brief Bank-Accounts Info Sorted Based on Aggregated Balances" << endl;
    cout << "\tX -- Exit" << endl;
    cout << "Please enter your selection:";
}

void Bank::selectionInput() {

    char selection;
    selectionMenu();
    cin >> selection;
    while (selection != 'x') {
        switch(selection) {
            case 'a':
			case 'A':
                numBankAccounts();
                break;
            case 's':
			case 'S':
                numSavingAccounts();
                break;
			case 'H':
            case 'h':
                numCheckingAccounts();
                break;
			case 'O':
            case 'o':
                openBankAccount();
                break;
            case 'c':
			case 'C':
                closeBankAccount();
                break;
			case 'M':
            case 'm':
                modifyBankAccount();
                break;
			case 'D':
            case 'd':
                printDetailedInfo();
                break;
			case 'B':
            case 'b':
                printInfo();
                break;
			default:
				cout << "\tInvalid selection" << endl;
        }

        selectionMenu();
        cin >> selection;
    }
    cout << "\t| End of service for bank " << name << endl;
}

void Bank::openBankAccount() {
    string firstName;
    string lastName;
    string SSN;
    cout << "\tEnter the first name of the account holder:";
    cin >> firstName;
    cout << "\tEnter the last name of the account holder:";
    cin >> lastName;
    cout << "\tEnter the SSN of the account holder:";
    cin >> SSN;

    BankAccount newAccount(firstName, lastName, SSN);

    cout << "\n\t| A new Bank Account BNK" << newAccount.getAccountNumber() << " was successfully created." << endl << endl;

    newAccount.selectionInput();
    v.push_back(newAccount);
}

void Bank::numBankAccounts() {
    cout << "\tThe number of bank accounts is " << v.size() << endl;
}

void Bank::numSavingAccounts() {
    int total = 0;
    for (auto account : v) {
        total += account.getTotalSavingAccounts();
    }

    cout << "The number of Saving-Accounts is " << total << endl;
}

void Bank::numCheckingAccounts() {
    int total = 0;

    for (auto account : v) {
        total += account.getTotalCheckingAccounts();
    }
    cout << "The number of Checking-Accounts is " << total << endl;
}

void Bank::printInfo() {
    cout << "\t| Bank Name: " << name << endl;
    cout << "\t| Bank Address: " << address << endl;
    cout << "\t| Bank Working Hours: " << workingHours << endl;
    cout << "\t| Aggregated Balance: " << getTotalBal() << endl;
    cout << "\t| Consists of " << v.size() << " Bank-Accounts" << endl;
    for (auto account : v) {
        account.printInfo();
    }
}

int Bank::getTotalBal() {
    int totalBal = 0;
    for (auto account : v) {
        totalBal += account.getTotalBal();
    }
    return totalBal;
}

void Bank::printDetailedInfo() {
    cout << "\t| Bank Name: " << name << endl;
    cout << "\t| Bank Address: " << address << endl;
    cout << "\t| Bank Working Hours: " << workingHours << endl;
    cout << "\t| Aggregated Balance: " << getTotalBal() << endl;
    cout << "\t| Consists of " << v.size() << " Bank-Accounts" << endl;

    for (auto account : v) {
        cout << "\t| Bank Account Number: BNK" << account.getAccountNumber() << endl;
        cout << "\t| Account Holder Full Name: " << account.getFirstName() << " " << account.getLastName() << endl;
        cout << "\t| Account Holder SSN: " << account.getSSN() << endl;
        cout << "\t| Aggregated Balance: " << account.getTotalBal() << endl;
        cout << "\t| Consists of " << account.getTotalSavingAccounts() + account.getTotalCheckingAccounts() << " Sub-Accounts" << endl;
        account.printDetailedInfo();
    }

}

void Bank::modifyBankAccount() {
    string fullAccountNum;
    int num;
    cout << "\tEnter the bank account number to be modified:";
    cin >> fullAccountNum;
    if (fullAccountNum.substr(0,3) != "BNK")
        cout << "No matching account" << endl;
    num = stoi(fullAccountNum.substr(3,5));
    for (auto &account : v) {
        if (account.getAccountNumber() == num)
            account.selectionInput();
        else
            cout << "No matching account" << endl;
    }
}

void Bank::closeBankAccount() {
    string fullAccountNum;
    int num;
    cout << "\tEnter the bank account number to be closed:";
    cin >> fullAccountNum;
    if (fullAccountNum.substr(0,3) != "BNK") {
        cout << "No matching account" << endl;
        return;
    }
    num = stoi(fullAccountNum.substr(3,5));
    vector<BankAccount>::iterator i = v.begin();
    while (i != v.end()) {
        if(i->getAccountNumber() == num) {
            v.erase(i);
            cout << "Bank-account " << fullAccountNum << " was successfully closed" << endl;
            return;
        }
        i++;
    }
    cout << "No matching account" << endl;
}
