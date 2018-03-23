#include <iostream>
#include "mystone.h"
using namespace std;

int main()
{
    Stonewt st[6] = 
    {
        191,
        181,
        171
    };
    
    for(int i=3;i<6;i++)
    {
        double temp;
        cout << "#" << i+1 << endl;
        cin >> temp;
        st[i] = temp;
    }
    int count =0;
    Stonewt temp(11,0);
    Stonewt Min = st[0];
    Stonewt Max = st[0];
    for(int i=0;i<6;i++)
    {
        if(Min>st[i])
            Min = st[i];
        if(Max<st[i])
            Max = st[i];
        if(st[i] >= temp)
            count++;
    }
    cout << "Min " << Min <<endl;
    cout << "Max " << Max << endl;
    cout << "numbers " << count << endl;
    cin.get();
    cin.get();
    return 0;
}
