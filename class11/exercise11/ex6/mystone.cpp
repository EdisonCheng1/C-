#include "mystone.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
    pds_left = lbs ;
    stone = stn ;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()
{
    pds_left = stone = pounds = 0;
}
Stonewt::~Stonewt()
{

}
bool Stonewt::operator>(const Stonewt &t) const
{
    if(pounds > t.pounds)
        return true;
    else
        return false;     
}
bool Stonewt::operator>=(const Stonewt &t) const
{
    if (pounds >= t.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator==(const Stonewt &t) const
{
    if (pounds == t.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator<(const Stonewt &t) const
{
    if (pounds < t.pounds)
        return true;
    else
        return false;
}

bool Stonewt::operator<=(const Stonewt &t) const
{
    if (pounds <= t.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator!=(const Stonewt &t) const
{
    if (pounds != t.pounds)
        return true;
    else
        return false;
}
std::ostream &operator<<(std::ostream &os, Stonewt &t)
{
    os << t.pounds << " pounds" << std::endl;
    return os;
}
