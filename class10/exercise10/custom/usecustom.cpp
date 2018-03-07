#include <iostream>
#include <cctype>
#include "custom.h"
void get_customer(custom & cu);
int main()
{
    using namespace std;
    Stack st; //create an empty stack
    custom temp;
    char ch;
    double payment = 0;
    cout << "Please enter A to add a purchase order,\n"
         << " P to process a PO ,or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a PO number to add: ";
            if (st.isfull())
                cout << "stack is already full\n";
            else
            {
                get_customer(temp);
                st.push(temp);
            }
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack is already empty\n";
            else
            {
                st.pop(temp);
                payment += temp.payment;
                cout << temp.fullname << " processed. ";
                cout << "Payment now total $" << payment << '\n';
            }
            break;
        }
        cout << "Please enter A to add and a purchase order,\n"
                "P to process a PO,or Q to quit.\n";
    }
    cout << "Bye.\n";
    return 0;
}
void get_customer(custom & cu)
{
    using namespace std;
    cout << "Enter customer name: ";
    cin.getline(cu.fullname,35);
    cout << "Enter customer payment: ";
    cin >> cu.payment;
    while(cin.get()!= '\n')
        continue;
}