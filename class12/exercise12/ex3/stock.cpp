#include "stock.h"
#include <cstring>

Stock::Stock()
{
    str = new char[Stock::LIMLEN];
    std::strcpy(str,"no name");
    shares = share_val = total_val = 0.0;
}
Stock::Stock(const char * strs,long n ,double pr )
{
    str = new char[std::strlen(strs) + 1];
    std::strcpy(str,strs);
    if(n<0)
    {
        std::cout << "Number of shares can't be negative; "
                  << str << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}
Stock::~Stock()
{
    delete [] str;
}
void Stock::buy(long num, double price)
{
    if(num<0)
    {
        std::cout<< "Number of shares can't be negative. "
                 << "Tanscation is aborted.\n";             
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "Number of shares sold can't be negative."
             << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cout << "You can't sell more than you have: "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -=num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
const Stock & Stock::topval(const Stock &s) const
{
    if(total_val > s.total_val)
        return *this;
    else
        return s;
}

std::ostream & operator<<(std::ostream &os, const Stock &s)
{
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << s.str
       << "  Shares: " << s.shares << '\n'
       << " Shares price :$ " << s.share_val;
    os.precision(2);
    os << " Total Worth: $" << s.total_val << '\n';

    os.setf(orig,ios_base::floatfield);
    os.precision(prec);
    return os;
}
