#include <iostream>
#include "mytime0.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << "coding time = ";
    coding.Show();
    cout << "fixing time = ";
    fixing.Show();

    total = coding.Sum(fixing);
    cout << "total time = ";
    total.Show();

    coding.Reset(3,40);
    cout << "reseting coding time = ";
    coding.Show();
    cout << "adding 20 mitutes to coding: ";
    coding.AddMin(20);
    cout << "after adding,coding time = ";
    coding.Show();
    cout << "adding 2 hours to fixing time: ";
    fixing.AddHr(2);
    cout << "after adding,fixing time = ";
    fixing.Show();
    cout << "Done.\n";
    return 0;
}