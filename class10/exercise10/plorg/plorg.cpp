#include <iostream>
#include "plorg.h"

Plorg::Plorg(const char * na,const int man)
{
    strncpy(name,na,SIZE-1);
    name[SIZE-1] = '\0';
    CI = man;
}
void Plorg::setCI(int num) 
{
    CI = num;
}
void Plorg::show() const
{
    using std::cout ;
    using std::endl ;
    cout << "Name: " << name << endl;
    cout << "CI: " << CI << endl;
}