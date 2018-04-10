#include "cd.h"


Cd::Cd(const char * s1,const char * s2,int n,double x)
{
    std::strncpy(performers,s1,49);
    performers[49] = '\0';
    std::strncpy(label,s2,19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::strncpy(performers,d.performers,49);
    performers[49] = '\0';
    std::strncpy(label,d.label,19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}
Cd::~Cd()
{

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
    std::strncpy(performers,d.performers,49);
    performers[49] = '\0';
    std::strncpy(label,d.label,19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
//classic methods
Classic::Classic(const char * des,const char * s1,const char * s2,int n ,double x):Cd(s1,s2,n,x)
{
    std::strncpy(describe,des,49);
    describe[49] = '\0'; 

}
Classic::Classic(const char * des,const Cd & d):Cd(d)
{
    std::strncpy(describe,des,49);
    describe[49] = '\0';
}
Classic::~Classic()
{

}
void Classic::Report() const
{
    Cd::Report();
    cout << "describe: " << describe << endl; 
}
Classic & Classic::operator=(const Classic & cs)
{
    if(this == &cs)
    {
        return *this;
    }
    Cd::operator=(cs);
    std::strncpy(describe,cs.describe,49);
    describe[49] = '\0';
    return *this;
}

