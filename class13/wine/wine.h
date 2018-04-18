#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <cstring>
using namespace std;
class Port
{
    private:
        char *brand;
        char style[20];   //i,e tawny,ruby,vintage
        int bottles;
    public:
        Port(const char *br = "none",const char *st = "none",int b = 0);
        Port(const Port &p);
        virtual ~Port() {delete [] brand;}
        Port & operator=(const Port & p);
        Port & operator+(int b);    //add b to bottles
        Port & operator-(int b);   //subtracts b from bottles ,if avaliable
        int BottleCount() const {return bottles;};
        virtual void Show() const ;
        friend ostream & operator<<(ostream & os,const Port & p);
};
class VitagePort:public Port
{
    private:
        char *nickname;
        int year;
    public:
        VitagePort();
        VitagePort(const char * br,int b,const char * nn,int y);
        VitagePort(const VitagePort & vp);
        ~VitagePort() { delete [] nickname;}
        VitagePort & operator=(const VitagePort & vp);
        void Show() const ;
        friend ostream & operator<<(ostream & os,const VitagePort & vp);
};

#endif