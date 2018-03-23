#include "mytime.h"
Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h,int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes = minutes % 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h,int m)
{
    hours = h;
    minutes = m;
}
Time operator+(const Time & t1,const Time & t2)
{
    Time sum;
    sum.minutes = (t1.minutes + t2.minutes) % 60;
    sum.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) /60;
    return sum;
}

Time operator-(const Time & t1, const Time & t2)
{
    Time diff;
    int tot1,tot2;
    tot1 = t1.minutes + t1.hours * 60;
    tot2 = t2.minutes + t2.hours * 60;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}
Time operator*(const Time &t, double m)
{
    Time result;
    int tot;
    tot = (t.minutes + t.hours *60) * m;
    result.minutes = tot % 60;
    result.hours = tot / 60;
    return result;
}
std::ostream & operator<<(std::ostream & os,const Time t)
{
    os << t.hours << " hours " << t.minutes << " minutes";
    return os;
}