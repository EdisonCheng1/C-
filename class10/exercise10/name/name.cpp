#include <iostream>
#include "name.h"

Person::Person(const string &ln, const char *fn )
{
    lname = ln;
    strncpy(fname,fn,LIMIT-1);
}
void Person::Show() const
{
    using std::cout;
    using std::endl;
    cout << "first name: " << fname << endl;
    cout << "last name: " << lname << endl;
}
void Person::FormalShow() const
{
    using std::cout;
    using std::endl;
    cout << "last name: " << lname << endl;
    cout << "first name: " << fname << endl;
}