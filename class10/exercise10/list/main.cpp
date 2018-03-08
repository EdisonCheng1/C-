#include <iostream>
#include <cstdlib>
#include "list.h"
void showfilm(Item & item);
//void reshowfilm(Item &item);
 int main()
{
    using namespace std;
    List movies;
    Item temp;
    if(movies.isfull())
    {
        cout << "No more room in list!Bye!\n";
        exit(1);
    }
    cout << "Enter first movie title:\n";
    while(cin.getline(temp.title,TSIZE) && temp.title[0]!='\0')
    {
        cout << "Enter your rating <1-10>: ";
        cin >> temp.rating;
        while(cin.get()!='\n')
            continue;
        if(movies.additem(temp) == false)
        {
            cout << "List already is full!\n";
            break;
        }
        if(movies.isfull())
        {
            cout << "You have filled the list.\n";
            break;
        }
        cout << "Enter next movie title(empty line to stop):\n";
    }
    if(movies.isempty())
        cout << "No data entered.\n";
    else
    {
        cout << "Here is the movie list:\n";
        movies.visit(showfilm);
        //movies.visit(reshowfilm);
    }    
    cout << "Bye!\n";
    return 0;
}
void showfilm(Item & item)
{
    std::cout << "Movie: " << item.title << " Rating: " 
              << item.rating << std::endl;
}
// void reshowfilm(Item & item)
// {
//     std::cout << "Rating :" << item.rating << " Movie: "
//               << item.title << std::endl;
// }