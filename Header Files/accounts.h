// Soo Min Kwon
// Stock Project

#ifndef PROGRAM_PROJECT_DOS_ACCOUNTS_H
#define PROGRAM_PROJECT_DOS_ACCOUNTS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
public:
    Account();
    void menu();
    void stockPrice();
    void buyStock();
    void sellStock();
    void displayPortfolio();
    void transaction();
    void account_balance();
    void deposit();
    void withdraw();
    void banktransaction();
protected:
    float cashBalance;
    float price;
    float amount;
    float total;
    string stock;
    string company;

};
#endif //PROGRAM_PROJECT_DOS_ACCOUNTS_H