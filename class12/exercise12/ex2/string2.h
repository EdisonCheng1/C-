//string1.h --fixed and augment string class definition
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
#include <cctype>
using std::istream;
using std::ostream;

class String
{
  private:
    char *str;
    int len;
    static int num_strings;

  public:
    static const int CINLIM = 80;
    //constructors and other methods
    String(const char *s);
    String();
    String(const String &); //copy constructor
    ~String();              //deconstructor
    int length() { return len; }
    //overloaded operator methods

    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);             //read and write
    const char &operator[](int i) const; //onlyread

    //string2
    void Stringlow();
    void Stringup();
    int has(char a) const;


    //overloaded operator friends
    friend bool operator<(const String &st, const String &s2);   //有助于将String对象与常规到的C字符串比较
    friend bool operator>(const String &st, const String &s2);
    friend bool operator==(const String &st, const String &s2);
    friend String operator+(const String &st1,const String &st2);
    friend ostream &operator<<(ostream &os, const String &s2);
    friend istream &operator>>(istream &is, String &s2);
    //static function
    static int HowMany();
};
#endif