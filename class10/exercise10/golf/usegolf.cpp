#include <iostream>
#include "golf.h"
const int SIZE = 4;
int main()
{
    Golf golfs[SIZE]=
    {
        Golf("AAA",1),
        Golf("BBB",2),
        Golf("CCC",3),
        Golf()
    };
    int i ;
    for(i=0;i<SIZE;i++)
    {
        std::cout << i+1 << ": \n";
        golfs[i].showgolf();
    }
    golfs[3].setgolf(golfs[2]);
    golfs[3].showgolf();
    golfs[3].sethandicap(5);
    golfs[3].showgolf();
    return 0;

}