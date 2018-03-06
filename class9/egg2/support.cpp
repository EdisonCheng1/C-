//support.cpp --use external variable
//compile with external.cpp
#include <iostream>
extern double warming;

void update(double dt);
void local();

using std::cout;
void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degree.\n" ;
}
void local()
{
    double warming = 0.8;

    cout << "Local warming = " << warming << " degree.\n";
    cout << "But global warmnig = " << ::warming;
    cout << " degree.\n";
}
