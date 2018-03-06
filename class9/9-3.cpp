#include <iostream>
#include <new>
#include <cstring>
using namespace std;
struct chaff
{
    char dross[20];
    int slag;
};
// int main()
// {
//     chaff * p = new chaff[20];
//     strcpy(p[0].dross,"Piffa like");
//     p[0].slag = 5;
//     strcpy(p[1].dross, "Fuck me so hard");
//     p[1].slag = 6;
//     for(int i = 0;i<2;i++)
//         cout << p[i].dross << " " << p[i].slag << endl;
//     return 0;
// }
char buffer[20];
int main()
{
    chaff *p;
    p = new(buffer) chaff[20];
    strcpy(p[0].dross, "Piffa like");
    p[0].slag = 5;
    strcpy(p[1].dross, "Fuck me so hard");
    p[1].slag = 6;
    for (int i = 0; i < 2; i++)
        cout << p[i].dross << " " << p[i].slag << endl;
    return 0;
}