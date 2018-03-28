//brass.h --bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

//brass account class
class Brass
{
    private:
        std::string fullName;
        long acctNum;   //账号
        double balance;  //当前结余
    public:
        Brass(const std::string & s = "Nobody",long an = -1,double bal = 0.0);
        void Deposite(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct() const;
        virtual ~Brass() {};
};

class BrassPlus:public Brass
{
    private:
        double maxloan;
        double rate;
        double owesbank;
    public:
        BrassPlus(const std::string &s = "Nobody", long an = -1, double bal = 0.0,
                  double ml = 500,double r = 0.1125);
        BrassPlus(const Brass & ba,double ml = 500,double r = 0.1125);

        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        void ResetMax(double m) { maxloan = m;}
        void ResetRate(double r) { rate = r;}
        void ResetOwns() { owesbank = 0;}   
};
#endif