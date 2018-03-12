#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
#include <fstream>
int main()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream fout;
    fout.open("thewalk.txt");
    srand(time(0)); //seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    fout << result << endl;
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        
        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            fout << result << " ";
            steps++;
        }
        fout << endl;
        cout << "After " << steps << " steps ,the subject "
             << "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0,0.0);
        fout << result << endl;
        cout << "Enter target distance (q to quit ): ";
    }
    cout << "Bye.\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    return 0;
}