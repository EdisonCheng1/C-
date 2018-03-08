#include <iostream>
#include "mytime2.h"

int main()
{
    using std::cout ;
    using std::endl;
    Time weeding(4,35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();

    cout << "waxing time = ";
    waxing.Show();

    cout << "total work time = ";
    total = weeding + waxing;
    total.Show();

    cout << "weeding - waxing =  ";
    diff = weeding - waxing;
    diff.Show();

    cout << "weeding * waxing = ";
    adjusted = weeding * 1.5;
    adjusted.Show();
    adjusted = 1.5 * weeding;
    cout << "weeding * waxing = ";
    adjusted.Show();
    return 0;
}