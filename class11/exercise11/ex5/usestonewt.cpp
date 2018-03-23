#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    using std::endl;
    Stonewt st1(10,10.1);
    Stonewt st2(91.1);
    cout << "st1,st2 = " << st1 <<", " << st2 <<endl;
    Stonewt temp;
    st1.convet_to_pounds_double();
    temp = st1 + st2;
    cout << "after convet to double,st1 + st2 = " << temp << endl;
    st1.convert_to_pounds_int();
    temp = st1 - st2;
    cout << "after convet to int,st1 + st2 = " << temp << endl;
    temp = 1.7 * st2;
    temp.convert_to_stone();
    cout << "1.7 * st2 = " << temp << endl; 

    return 0;

}