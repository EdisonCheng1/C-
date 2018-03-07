#include <iostream>
#include "balance.h"

const int SIZE =4;
int main()
{
    BankAccount balances[SIZE] = 
    {
        BankAccount("AAAAAAAA","11111111111",100.0),
        BankAccount("BBBBBBBB","22222222222",200.0),
        BankAccount("CCCCCCCC","33333333333",300.0),
        BankAccount("DDDDDDDD","44444444444",400.0)
    };
    int bl ;
    for(bl = 0;bl<SIZE;bl++)
        balances[bl].show();
    balances[0].deposit(200);
    balances[0].show();
    balances[1].withdraw(300);
    balances[2].withdraw(-100);
    balances[3].withdraw(200);
    balances[3].show();
    std::cout << "Done.\n";
    return 0;
}