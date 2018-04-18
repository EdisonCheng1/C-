#include "abc.h"
#include <cstring>
using std::cout;
using std::endl;
//abstract methods
abcDMA::abcDMA(const char *l,int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
abcDMA::abcDMA(const abcDMA &ad)
{
    label = new char(std::strlen(ad.label) + 1);
    std::strcpy(label, ad.label);
    rating = ad.rating;
}
abcDMA::~abcDMA()
{
    delete [] label;
}
abcDMA & abcDMA::operator=(const abcDMA &ad)
{
    if (this == &ad)
    {
        return *this;
    }
    delete[] label;
    label = new char[std::strlen(ad.label) + 1];
    std::strcpy(label, ad.label);
    rating = ad.rating;
    return *this;
}
void abcDMA::View() const
{
    cout << "label: " << label << endl;
    cout << "rating: " << rating << endl;
}
//baseDMA methods
baseDMA::~baseDMA()
{

}
void baseDMA::View() const
{
    abcDMA::View();
}
//lacksDMA methods
lacksDMA::lacksDMA(const char *c , const char *l , int r):abcDMA(l,r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}
lacksDMA::lacksDMA(const char *c, const abcDMA &ls):abcDMA(ls)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}
lacksDMA::~lacksDMA()
{

}
void lacksDMA::View() const
{
    abcDMA::View();
    cout << "color: " << color << endl;
}
//hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r):abcDMA(l,r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const abcDMA &hs):abcDMA(hs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA::hasDMA(const hasDMA &hs):abcDMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}
hasDMA & hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
    {
        return *this;
    }
    abcDMA::operator=(hs);
    delete[] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
void hasDMA::View() const
{
    abcDMA::View();
    cout << "style: " << style << endl;
}