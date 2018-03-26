#include "string2.h"
#include <cstring>
using std::cin;
using std::cout;

//initializing static class member

int String::num_strings = 0;

int String::HowMany()            //静态函数
{
    return num_strings;
}

//class methods
String::String(const char *s)    //构造函数
{
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}
String::String()                   //默认构造函数
{
    len = 4;
    str = new char[len+1];
    num_strings++;
}
String::String(const String & st)   //复制构造函数
{
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str); 
}
String::~String()                  //析构函数
{
    num_strings--;
    delete [] str;
}

//overloading operator methods
String & String::operator=(const String & st)    //赋值函数
{
    if( this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}
String & String::operator=(const char * s)       //字符串赋值函数
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    return *this;
}

char & String::operator[](int i)          //read and write
{
    return str[i];
}
const char & String::operator[](int i) const //onlyread
{
    return str[i];
}
//string2
void String::Stringlow()
{
    for(int i=0;i<len;i++)
      str[i] = tolower(str[i]);
}
void String::Stringup()
{
    for(int i=0;i<len;i++)
        str[i] = toupper(str[i]);
}
int String::has(char a)   const
{
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if( str[i] == a)
            count++;
    }
    return count;
}
//overloaded operator friend methods
bool operator<(const String &st, const String &s2) //有助于将String对象与常规到的C字符串比较
{
    return (std::strcmp(st.str,s2.str));
}
bool operator>(const String &st, const String &s2)
{
    return s2 < st;
}
bool operator==(const String &st, const String &s2)
{
    return (std::strcmp(st.str,s2.str) == 0);
}
String operator+(const String &st1, const String &st2)
{
    char *pstr = new char[st1.len + st2.len + 1];
    std::strcpy(pstr,st1.str);
    std::strcat(pstr,st2.str);
    String temp(pstr);
    delete [] pstr;
    return temp;
}
ostream &operator<<(ostream &os, const String &s2)
{
    os << s2.str;
    return os;
}
istream &operator>>(istream &is, String &s2)
{
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
        s2 = temp;
    while(is && is.get()!= '\n')
        continue;
    return is;
}