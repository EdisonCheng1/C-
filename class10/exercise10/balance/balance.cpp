#include <iostream>
#include "balance.h"

BankAccount::BankAccount(const char *client, const char *num, double bal)
{
    strncpy(name,client,39);
    name[39] = '\0';
    strncpy(acctnum,num,24);
    acctnum[24] = '\0';
    balance = bal;
}

void BankAccount::show() const
{
    using std::cout;
    using std::endl;
    cout << "The information is:\n" ;
    cout << "name: " << name << endl;
    cout << "acctnum: " << acctnum << endl;
    cout << "balance: " << balance << endl; 
}
void BankAccount::deposit(double cash)
{
    if(cash < 0)
        std::cout << "error.\n";
    else 
        balance += cash;
}
void BankAccount::withdraw(double cash)
{
    if(cash < 0 )
        std::cout << "error.\n";
    else if(cash > balance)
        std::cout << "more than your balance!error!\n";
    else 
        balance -= cash;
}
