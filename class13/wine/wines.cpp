#include "wine.h"

Port::Port(const char *br , const char *st , int b )
{
    brand = new char[strlen(br) + 1];
    strcpy(brand,br);
    strncpy(style,st,19);
    style[19] = '\0';
    bottles = b;  
}
Port::Port(const Port &p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style,p.style,19);
    style[19] = '\0';
    bottles = p.bottles;
}
Port & Port::operator=(const Port &p)
{
    if(this == &p)
    {
        return *this;
    }
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}
Port & Port::operator+(int b) //add b to bottles
{
    bottles = bottles + b;
    return *this;
}
Port & Port::operator-(int b) //subtracts b from bottles ,if avaliable
{
    if(bottles >= b)
        bottles = bottles - b;
    else
        cout << "error!the number of bottles don't change!";
    return *this;
}
void Port::Show() const
{
    cout << "brand: " << brand << endl;
    cout << "style: " << style << endl;
    cout << "bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << " " << p.style << " " << p.bottles << " " ;
    return os;
}
//VitagePort methods
VitagePort::VitagePort():Port("none","vitage",0)
{
    nickname = new char[strlen("none") + 1];
    strcpy(nickname, "none");
    year = 0;
}
VitagePort::VitagePort(const char *br, int b, const char *nn, int y):Port(br, "vitage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
VitagePort::VitagePort(const VitagePort &vp):Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VitagePort & VitagePort::operator=(const VitagePort &vp)
{
    if (this == &vp)
    {
        return *this;
    }
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}
void VitagePort::Show() const
{
    Port::Show();
    cout << "nickname: " << nickname << endl;
    cout << "year: " << year << endl;
}
ostream &operator<<(ostream &os, const VitagePort &vp)
{
    os << (const Port &) vp << " " << vp.nickname << " " << vp.year << endl; 
    return os;
}