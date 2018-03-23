#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3,35);
    Time tosca(2,48);
    Time temp1;
    Time temp2;
    Time temp3;

    cout << "Aida and Tosca:\n";
    cout << aida << ";" << tosca << endl;
    temp1 = aida + tosca;
    cout << "aida + tosca:\n";
    cout << temp1 << endl;
    temp2 = aida - tosca;
    cout << "aida - tosca:\n";
    cout << temp2 << endl;
    temp3 = aida * 1.7;
    cout << "aida * 1.7:\n";
    cout << temp3 << endl;
    temp3 = 1.7 * aida ;
    cout << "1.7 * aida:\n";
    cout << temp3 << endl;

    return 0;
}