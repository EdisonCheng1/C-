#ifndef STOCK_H_
#define STOCK_H_
#include <iostream>

class Stock
{
    private:
        char *str;    //company
        int shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val;}
        
    public:
        static const int LIMLEN = 10;
        Stock();
        Stock(const char * strs,long n = 0,double pr = 0.0);
        ~Stock();
        void buy(long num,double price);
        void sell(long num,double price);
        void update(double price);
        const Stock & topval(const Stock & s) const;
        friend std::ostream & operator<<(std::ostream & os,const Stock & s);
};
#endif