#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);
    double p_wt = poppins;
    cout << "Convert to double => ";
    cout << "poplins: " << p_wt << " pounds.\n";
    cout << "convert to int => ";
    cout << "poppins: " << int(poppins) << " pounds.\n";
    return 0;
}