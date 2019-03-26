// Soo Min Kwon
// Stock Project

#include "accounts.h"

Account::Account() {
    cashBalance = 10000;
    price = amount = 0;
}

Account temp;
vector <Account> stockAccounts;

void Account::menu() {
    cout << endl << "Welcome to the Account Management System!" << endl
         << "Please select an account to access: " << endl
         << "1. Stock Portfolio Account" << endl
         << "2. Bank Account" << endl
         << "3. Exit" << endl
         << "Your Selection: ";
}

void Account::stockPrice() {
    string symbol;
    string line2;

    cout << "Enter stock symbol for checking price: ";
    cin >> symbol;

    vector <string> tokens;

    srand(time(NULL));
    int num = 1 + rand() % 4;
    string name = "stock" + to_string(num) + ".txt";
    ifstream infile;
    infile.open(name);

    while (getline(infile, line2)) {
        string line = line2;
        string delim = "\t";

        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                line = line.substr(line.rfind(delim) + 1, string::npos);
                line.resize(line.length() - 1);

                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }
    }
    bool correct = 1;
    for (int i = 0; i < tokens.size(); i++) {
        if (symbol == tokens[i]) {
            cout << endl << tokens[i] << "   " << tokens[++i] << "   " << tokens[++(++i)] << endl;
            correct = 0;
        }
    }
    if (correct == 1) {
        cout << endl << "This stock does not exist. Please try again." << endl;
    }

    infile.close();
}

void Account::buyStock() {
    string line2, a, b, c;
    string input;
    int store;

    cout << "Enter buy options (stock symbol / amount / price): ";
    cin >> stock >> amount >> price;

    vector <string> tokens;

    srand(time(NULL));
    int num = 1 + rand() % 4;
    string name = "stock" + to_string(num) + ".txt";
    ifstream infile;
    infile.open(name);

    while (getline(infile, line2)) {
        string line = line2;
        string delim = "\t";

        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                line = line.substr(line.rfind(delim) + 1, string::npos);
                line.resize(line.length() - 1);

                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (stock == tokens[i]) {
            a = tokens[i];
            b = tokens [++i];
            c = tokens [++(++i)];
        }
    }
    float stockPrice = stod(c);

    cout << "The stock price for " << a << " is " << stockPrice
         << ". Would you like to continue with this transaction? Press Y for Yes and N for No: ";
    cin >> input;

    if (input == "Y" && price >= stockPrice && cashBalance >= (amount*price)) {
        {
            cashBalance = cashBalance - (price * amount);
            temp.cashBalance = cashBalance;
            temp.stock = stock;
            temp.amount = amount;
            temp.price = price;
            temp.company = b;
            temp.total = temp.amount*temp.price;

            stockAccounts.push_back(temp);

            ofstream outFile;
            outFile.open("stock_transaction_history.txt", ios_base::app);
            outFile << endl << "Buy" << setw(20) << temp.stock << setw(20) << temp.amount << setw(20) << temp.price;
            outFile. close();

            cout << endl << "Transaction Complete!" << endl;
        }
    }
    else if (input == "N")
        cout << endl << "Transaction Incomplete. Returning to menu..." << endl;
    else if (price < stockPrice || cashBalance < (amount*price))
        cout << endl << "Cannot process transaction. Please try again." << endl;

    infile.close();
}

void Account::sellStock() {
    string line2;
    string a, b, c;
    string d; //stock
    float e; //amount
    float f; //price
    int blah;

    cout << "Enter sell options (stock symbol / amount / price): ";
    cin >> d >> e >> f;

    for (int i = 0; i < stockAccounts.size() ; i++) {
        if (d == stockAccounts[i].stock)
            blah = i;
    }

    vector <string> tokens;

    srand(time(NULL));
    int num = 1 + rand() % 4;
    string name = "stock" + to_string(num) + ".txt";
    ifstream infile;
    infile.open(name);

    while (getline(infile, line2)) {
        string line = line2;
        string delim = "\t";

        for (int i = 0; i < 3; i++) {
            if (i == 2) {
                line = line.substr(line.rfind(delim) + 1, string::npos);
                line.resize(line.length() - 1);

                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (d == tokens[i]) {
            a = tokens[i];
            b = tokens[++i];
            c = tokens[++(++i)];
        }
    }
    float stockPrice = stod(c);
    string option;

    cout << "The price per stock for this stock is currently " << c
         << ". Would you like to perform this transaction? Press Y for Yes and N for No: ";
    cin >> option;

    if (option == "Y" && f <= stockPrice && e <= stockAccounts[blah].amount)
    {
        stockAccounts[blah].cashBalance = stockAccounts[blah].cashBalance + (e*f);
        stockAccounts[blah].amount = stockAccounts[blah].amount - e;

        ofstream outFile;
        outFile.open("stock_transaction_history.txt", ios_base::app);
        outFile << endl << "Sell" << setw(20) << d << setw(20) << e << setw(20) << f;

        outFile.close();

        cout << endl << "Transaction Complete!" << endl;
    }
    else if (option == "N")
    {
        cout << endl << "Transaction Incomplete. Returning to menu..." << endl;
    }
    else if (f > stockPrice || e > stockAccounts[blah].amount) {
        cout << endl << "Cannot process transaction. Please try again." << endl;
    }

    infile.close();
}

void Account::displayPortfolio() {
    int j;
    {
        for (int i = 0; i < stockAccounts.size(); i++) {
            j = i;
        }
        cout << "Cash Balance = " << stockAccounts[j].cashBalance << endl << endl;
    }
    cout << "Symbol" << setw(20) << "Company" << setw(35) << "Number" << setw(25) << "Price" << setw(25) << "Total"
         << endl;

    for (int i = 0; i < stockAccounts.size(); i++) {
        cout << stockAccounts[i].stock << setw(35) << stockAccounts[i].company << setw(20)
             << stockAccounts[i].amount << setw(25) << stockAccounts[i].price << setw(25)
             << (stockAccounts[i].amount * stockAccounts[i].price) << endl;
    }
}


void Account::transaction() {
    cout << endl;

    ifstream inFile;
    inFile.open("stock_transaction_history.txt");
    string line;
    while (getline(inFile,line)) {
        cout << line << endl;
    }

    cout << endl;
}

void Account::account_balance() {
    int store;
    double sum = 0;

    displayPortfolio();

    for (int i = 0; i < stockAccounts.size(); i++) {
        store = i;
    }

    for (int i = 0; i < stockAccounts.size(); i++) {
        sum += stockAccounts[i].total;
    }
    cout << endl << "Total Portfolio Value: " << stockAccounts[store].cashBalance + sum << endl;
}

void Account::deposit() {
    double amount;
    string option;

    cout << "Enter an amount for deposit: ";
    cin >> amount;

    cout << "Are you sure you would like to deposit $" << amount << " into this account? Press Y for Yes and N for No: ";
    cin >> option;

    for (int i = 0; i < stockAccounts.size(); i++){
        if (option == "Y" && amount > 0) {
            stockAccounts[i].cashBalance = stockAccounts[i].cashBalance + amount;

            ofstream outFile;
            outFile.open ("bank_transaction_history.txt", ios_base::app);
            outFile << endl << "Deposit" << setw(20) << amount << setw(20) << stockAccounts[i].cashBalance;
            outFile.close();
        }
    }
    if (amount < 0){
        cout << endl << "This transaction could NOT be completed. Please try again." << endl;
        return;
    }
    else if (option == "N"){
        cout << endl << "Returning to menu..." << endl;
        return;
    }
    account_balance();
}

void Account::withdraw() {
    double amount;
    string option;
    int store;

    cout << "Enter an amount for withdrawl: ";
    cin >> amount;

    cout << "Are you sure you would like to withdraw $" << amount << " from this account? Press Y for Yes and N for No: ";
    cin >> option;

    for (int i = 0; i < stockAccounts.size(); i++){
        store = i;
    }
    if (amount <= stockAccounts[store].cashBalance && option == "Y"){
        stockAccounts[store].cashBalance = stockAccounts[store].cashBalance - amount;

        ofstream outFile;
        outFile.open ("bank_transaction_history.txt", ios_base::app);
        outFile << endl << "Withdraw" << setw(20) << amount << setw(20) << stockAccounts[store].cashBalance;
        outFile.close();
    }
    else if (amount > stockAccounts[store].cashBalance){
        cout << endl << "There are insufficient funds for this transaction. Please try again." << endl;
        return;
    }
    else if (option == "N"){
        cout << endl << "Returning to menu... " << endl;
        return;
    }
    account_balance();
}

void Account::banktransaction() {
    ifstream inFile;
    inFile.open("bank_transaction_history.txt");
    string line;

    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}