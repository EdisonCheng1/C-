#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

using namespace std;
void getmax(long *step,int number);
void getmin(long *step,int number);
void getavg(long *step,int number);
int main()
{
    using VECTOR::Vector;
    srand(time(0)); //seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    cout << "Enter the number of test: " << endl;
    int n;
    cin >> n;
    long *steps = new long[n];
    for(int i=0;i<n;i++)
        steps[i] = 0;
    double target;
    double dstep;
    for(int i=0;i<n;i++)
    {
        cout << "Enter the target: ";
       if(!(cin >> target))
            break;
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        
        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            steps[i]++;
        }
        
        cout << "After " << steps[i] << " steps ,the subject "
             << "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps[i] << endl;
        result.reset(0.0,0.0);
    }
    
    cin.clear();
    while(cin.get() != '\n')
        continue;
    getmax(steps,n);
    getmin(steps,n);
    getavg(steps,n);
    cout << "Bye.\n";
    delete [] steps;
    return 0;
}
void getmax(long *step,int number)
{
    long max = step[0];
    for(int i=1;i<number;i++)
    {
        if(max < step[i])
            max = step[i];
    }
    cout << "the maximum steps is " << max << endl;
}
void getmin(long *step,int number)
{
    long min = step[0];
    for (int i = 1; i < number; i++)
    {
        if (min > step[i])
            min = step[i];
    }
    cout << "the minimum steps is " << min << endl;
}
void getavg(long *step,int number)
{
    long total = 0;
    for(int i=0;i<number;i++)
    {
        total += step[i];
    }
    cout << "the average steps is " << long(total/number) << endl;
}