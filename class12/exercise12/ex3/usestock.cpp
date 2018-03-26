#include <iostream>
#include "stock.h"

const int SIZE = 4;
using std::cout;
int main()
{
    Stock stocks[SIZE] = 
    {
        Stock("AA",12,20.0),
        Stock("BB",200,2.0),
        Stock("CC",130,3.25),
        Stock("DD",60,6.5)
    };

    std::cout << " Stock holding:\n";
    int st =0;
    for(st = 0;st < SIZE;st++)
    {
        cout << stocks[st];
    }
    const Stock *top = &stocks[0];
    for(st = 1;st < SIZE;st++)
    {
        top = &top->topval(stocks[st]);
    } 
    cout << "\nMost valuable holding:\n";
    cout << *top;
    return 0;
}