#include "mytime3.h"

Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}
Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time Time::operator-(const Time &t) const
{
    Time result;
    int tot1, tot2;
    tot1 = minutes + hours * 60;
    tot2 = t.minutes + t.hours * 60;
    result.minutes = (tot1 - tot2) % 60;
    result.hours = (tot1 - tot2) / 60;
    return result;
}
Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = minutes * n + hours * 60 * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}
std::ostream & operator<<(std::ostream & os,const Time & t)
{
    os << t.hours << " hours " << t.minutes << " minutes";
    return os;
}
