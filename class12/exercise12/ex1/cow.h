#ifndef COW_H_
#define COW_H_
#include <iostream>
#include <cstring>
using namespace std;

class Cow
{
    private:
        char name[20];
        char *hobby;
        double weight;
    public:
        Cow();
        Cow(const char * nm ,const char * ho,double wt);
        Cow(const Cow &c);      //复制构造函数
        ~Cow();
        Cow & operator=(const Cow & c);    //赋值运算符重载
        void ShowCow() const;
};
#endif