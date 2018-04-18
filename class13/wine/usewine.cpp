#include "wine.h"

int main()
{
    Port port1("gallo", "tawny", 20);
    cout << port1 << endl;
    VitagePort vp("gallo", 24, "nice", 16);
    VitagePort vp2(vp);
    cout << vp2 << endl;
    VitagePort vp3;
    vp3 = vp;
    cout << vp3 << endl;
    Port *p_port;
    p_port = &port1;
    p_port->Show();
    cout << endl;
    p_port = &vp;
    p_port->Show();
    cout << endl;
}