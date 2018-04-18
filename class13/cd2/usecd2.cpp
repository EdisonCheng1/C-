#include "cd2.h"
using namespace std;
void Bravo(const Cd & disk)
{
    disk.Report();
}
int main()
{
    Cd c1("zzz","xxx",14,35.5);
    Classic c2 = Classic("aaa","bbb","ccc",2,57.17);

    Cd *pcd = &c1;

    cout << "Using object directli:\n";
    c1.Report();
    c2.Report();

    cout << "Using type of * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: " ;
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}