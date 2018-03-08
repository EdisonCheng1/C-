#include <iostream>
#include "plorg.h"

int main()
{
    using namespace std;
    Plorg plorg1;
    plorg1.show();
    Plorg plorg2("heyyroup",31);
    plorg2.show();
    plorg1.setCI(41);
    plorg1.show();
    return 0;
}