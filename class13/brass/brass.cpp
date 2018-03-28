//brass.cpp --bank account class methods
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

//formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis p);

//brass 
Brass::Brass(const string & s,long an,double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;   
}
void Brass::Deposite(double amt)
{
    if(amt < 0)
    {
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    }
    else
        balance += amt;
}
void Brass::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt < 0)
    {
        cout << "Withdraw amount must be positive;" 
             << "withdraw canceled.\n";
    }
    else if(amt <= balance)
        balance -= amt;
    else
       cout << "Withdraw amount if $" << amt
            << " exceeds your balance.\n"
            << "Withdrawl canceled.\n";
    restore(initialState,prec);
}
double Brass::Balance()  const
{
    return balance;
}
void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState,prec);
}
//BrassPlus Methods
BrassPlus::BrassPlus(const string & s,long an,double bal,
                    double m1,double r):Brass(s,an,bal)
{
    maxloan = m1;
    owesbank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass & ba,double m1,double r):Brass(ba)
{
    maxloan = m1;
    owesbank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxloan << endl;
    cout << "Owed to bank: $" << owesbank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState,prec);
}
void BrassPlus::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();

    if(amt <= bal)
        Brass::Withdraw(amt);
    else if(amt < bal + maxloan - owesbank)  //(bal+maxloan)为最大可支出-owesbank(为当前的透支总额)
    {
        double advance = amt - bal;   //提前花的钱
        owesbank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finace charge: $" << advance*rate << endl;
        Deposite(advance);    //提前支出
        Brass::Withdraw(amt); //取出
    }
    else 
        cout << "Credit limit exceeded.Transaction canceled.\n";
    restore(initialState,prec);
} 
format setFormat()
{
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}
void restore(format f,precis p)
{
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}