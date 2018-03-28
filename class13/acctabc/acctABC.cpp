#include <iostream>
#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

AcctABC::AcctABC(const string & s,long an,double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}
void AcctABC::Deposit(double amt)
{
    if(amt < 0)
        cout << "not allowed.\n";
    else
      balance += amt;
}
void AcctABC::Withdraw(double amt)
{
    balance -= amt;
} 
//protected methods for formatting
AcctABC::Formatting AcctABC::setFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}
void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout << "not allowed.\n";
    else if(amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "error!\n";
}
void Brass::ViewAcct() const
{
    Formatting f = setFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balace: $" << Balance() << endl;
    Restore(f);
}
//BrassPlus methods
BrassPlus::BrassPlus(const string &s , long an, double bal,
                     double ml , double r):AcctABC(s,an,bal)
{
    maxloan = ml;
    owesBank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass & ba, double ml, double r):AcctABC(ba)
{
    maxloan = ml;
    owesBank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const
{
    Formatting f = setFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxloan << endl;
    cout << "owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100*rate << "%\n";
    Restore(f);
}
void BrassPlus::Withdraw(double amt)
{
    Formatting f = setFormat();
    double bal = Balance();
    if(amt <= bal)
        AcctABC::Withdraw(amt);
    else if( amt < bal + maxloan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance *(1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else 
        cout << "error!\n";
    Restore(f);
} 