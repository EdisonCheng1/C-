#ifndef NAME_H_
#define NAME_H_
#include <string>
using std::string;
class Person
{
    private:
        static const int LIMIT = 25;
        string lname;
        char fname[LIMIT];
    public:
        Person() {lname = "",fname[0]= '\0';}                 //#1
        Person(const string &ln,const char *fn = "Heyyou"); //#2
        //the following methods display lname and fname;
        void Show() const;
        void FormalShow() const;
};
#endif