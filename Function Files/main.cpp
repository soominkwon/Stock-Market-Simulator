// Soo Min Kwon
// Stock Programming Project #2
// Classes are defined in .h files and functions are defined in .cpp files!

// *Please buy a stock before performing transactions!*

#include "bankaccounts.h"

int main() {
    int selection;

    stockAccount a;
    bankAccounts b;

    while (selection != 3) {
        a.menu();
        cin >> selection;

        if (selection == 1)
            a.stock_account();
        else if (selection == 2)
            b.bank_accounts();
        else if (selection == 3) {
            cout << endl << "Thank you for visiting our Account Management System. We hope to see you again!";
        }
    }
    return 0;
}