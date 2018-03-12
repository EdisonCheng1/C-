#include <iostream>
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    Vector v1 = Vector(2,2);
    cout << "v1 " << v1 << endl;
    Vector v2 = Vector(5,1,Vector::POL);
    cout << "v2 " << v2 << endl;
    Vector v3;
    v3.reset(3,4);
    v3.polar_mode();
    cout << "v3 " << v3 << endl;
    v3 = v1 + v2 ;
    cout << "after change ,v3 " << v3 << endl;
    Vector v4;
    v4 = v2 - v1;
    cout << "v4 " << v4 << endl << endl;
    v4 = -v4;
    cout << "after change v4 " << v4 << endl;
    Vector v5;
    v5 = 6 * v1;
    cout << "v5 = 6 * v1 " << v5 << endl;
    return 0;
}