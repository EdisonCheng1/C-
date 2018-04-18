//usebrass2.cpp --plymorphic example
//compile with brass.cpp
#include <iostream>
#include <cstring>
#include "abc.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    abcDMA *p_clients[CLIENTS];
    char templabel[40];
    int temprating;
    char tempcolor[40];
    char tempstyle[40];
    char kind;
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter label: ";
        cin.getline(templabel, 40);
        cout << "Enter rating: ";
        cin >> temprating;
        
        
        cout << "Enter 1,2,3 ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            cout << "Enter 1,2 or 3: ";
        cin.get();
        if (kind == '1')
            p_clients[i] = new baseDMA(templabel,temprating);
        else if(kind == '2')
        {
            cout << "Enter color: ";
            
            cin.getline(tempcolor, 40);
            
            p_clients[i] = new lacksDMA(tempcolor,templabel,temprating);
        }
        else 
        {
            cout << "Enter style: ";
            
            cin.getline(tempstyle, 40);
        
            p_clients[i] = new hasDMA(tempstyle, templabel, temprating);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->View();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; //free memory
    }
    cout << "Done.\n";
    return 0;
}