#include <iostream>
#include "cow.h"
using namespace std;

int main()
{
    Cow ccc("asaasa","asasasa",34);
    ccc.ShowCow();
    Cow cow = ccc;
    cow.ShowCow();
    Cow caa("asasasa","qweweweqw",21);
    caa.ShowCow();
    caa = cow;
    caa.ShowCow();
    
    return 0;
}