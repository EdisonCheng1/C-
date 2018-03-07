#include <iostream>
#include "golf.h"
Golf::Golf()
{
    strcpy(fullname,"No Name");
    handicap = 0;
}
Golf::Golf(const char *fn, const int hc)
{
    strncpy(fullname,fn,Len-1);
    fullname[Len-1] = '\0';
    handicap = hc;
}
const Golf & Golf::setgolf(const Golf &g)
{
    strcpy(fullname,g.fullname);
    handicap = g.handicap;
    return *this;
}
void Golf::sethandicap(int hc)
{
    this->handicap = hc;
}


void Golf::showgolf() const
{
    std::cout << "fullname: " << fullname << std::endl;
    std::cout << "handicap: " << handicap << std::endl;
}
