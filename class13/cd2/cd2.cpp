#include "cd2.h"

Cd::Cd(const char * s1 ,const char * s2 ,int n,double x)
{
    performers = new char[std::strlen(s1) + 1];
    std::strcpy(performers,s1);
    label = new char[std::strlen(s2) + 1];
    std::strcpy(label,s2);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd & d)
{
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers,d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}
void Cd::Report() const
{
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
    {
        return *this;
    }
    delete [] performers;
    delete [] label;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers,d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
//classic methods
Classic::Classic(const char * des,const char * s1,const char * s2,int n ,double x):Cd(s1,s2,n,x)
{
    describe = new char[std::strlen(des) + 1];
    std::strcpy(describe,des);
}
Classic::Classic(const char * des,const Cd & d):Cd(d)
{
    describe = new char[std::strlen(des) + 1];
    std::strcpy(describe,des);
}
Classic::~Classic()
{
    delete [] describe;
}
//复制
Classic::Classic(const Classic & cs):Cd(cs)
{
    describe = new char[std::strlen(cs.describe) + 1];
    std::strcpy(describe,cs.describe);
}
void Classic::Report() const
{
    Cd::Report();
    cout << "describe: " << describe << endl; 
}
//赋值
Classic & Classic::operator=(const Classic & cs)
{
    if(this == &cs)
    {
        return *this;
    }
    Cd::operator=(cs);
    describe = new char[std::strlen(cs.describe) + 1];
    std::strcpy(describe,cs.describe);
    return *this;
}

