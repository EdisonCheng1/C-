//usestock.cpp --using the Stock class
//compile with stock20.cpp
#include <iostream>
#include "stock20.h"

const int SIZE = 4;
int main()
{
    Stock stocks[SIZE]=
    {
        Stock("A",12,20.0),
        Stock("B",200,2.0),
        Stock("C",130,3.25),
        Stock("D",60,6.5)
    };

    std::cout << "Stock holding:\n";
    int st;
    for(st = 0;st < SIZE;st++)
    {
        stocks[st].show();
    }
    const Stock *top = &stocks[0];
    for(st =1;st<SIZE;st++)
    {
        top = &top->topval(stocks[st]);
    }
    std::cout << "\nMost valuable holding:\n";
    top->Stock::show();
    return 0;
}