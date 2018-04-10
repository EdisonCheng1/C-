#ifndef CD_H_
#define CD_H_
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
//base class
class Cd
{
    //represents a CD disk
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(const char * s1 = " " ,const char * s2 = " ",int n = 0,double x = 0.0);
        Cd(const Cd & d);
        virtual ~Cd();
        virtual void Report() const;  //reports all CD data
        Cd & operator=(const Cd & d);
};
class Classic:public Cd
{
    private:
        char describe[50];
    public:
        Classic(const char * des = " " ,const char * s1 = " " ,const char * s2 = " " ,int n = 0 ,double x = 0.0);
        Classic(const char * des,const Cd & d);
        ~Classic();
        void Report() const;
        Classic & operator=(const Classic & cs);
};
#endif