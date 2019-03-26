// Soo Min Kwon
// Stock Project

#include "stockaccounts.h"

stockAccount :: stockAccount () {
    //constructor
}

void stockAccount:: stock_account() {
    int select;

    cout << endl << "Please select an option\n"
            "1. Display current price for a stock symbol\n"
            "2. Buy stock\n"
            "3. Sell stock\n"
            "4. Display current portfolio\n"
            "5. Display transactions history\n"
            "6. Return to main menu\n"
            "Your selection: ";

    cin >> select;

    if (select == 1)
        stockPrice();
    else if (select == 2)
        buyStock();
    else if (select ==3)
        sellStock();
    else if (select == 4)
        displayPortfolio();
    else if (select == 5)
        transaction();
    else if (select == 6)
        return;
}