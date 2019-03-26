// Soo Min Kwon
// Stock Project

#include "bankaccounts.h"

bankAccounts::bankAccounts(){
    //constructor
}

void bankAccounts::bank_accounts() {
    int select;

    cout << endl << "Please select an option:" << endl
         << "1. View account balance" << endl
         << "2. Deposit money" << endl
         << "3. Withdraw money" << endl
         << "4. Display transactions history" << endl
         << "5. Return to previous menu" << endl
         << "Your Selection: ";
    cin >> select;

    if (select == 1)
        account_balance();
    else if (select == 2)
        deposit();
    else if (select == 3)
        withdraw();
    else if (select == 4)
        banktransaction();
    else if (select == 5) {
        return;
    }
}