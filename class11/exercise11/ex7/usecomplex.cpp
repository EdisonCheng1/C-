#include "complex0.h"
using namespace std;
#include <iostream>
int main()
{
    Complex a(3.0, 4.0);
    Complex c;
    char ch;
    cout << " q to quit,other to continue: ";
    while (cin >> ch)
    {
        if (ch == 'q' || ch == 'Q')
            break;
        else
        {
            cout << "Enter a complex number :\n ";
            cin >> c;
            cout << "c is " << c << '\n';
            cout << "Complex conjugate is " << ~c << '\n';
            cout << "a is " << a << '\n';
            cout << "a + c is " << a + c << '\n';
            cout << "a - c is " << a - c << '\n';
            cout << "a * c is " << a * c << '\n';
            cout << "2 * c is " << 2 * c << '\n';
        }
        cout << "Enter a complex number (q to quit): ";
    }
    cout << "Done!\n";
    cin.get();
    cin.get();
    return 0;
}
