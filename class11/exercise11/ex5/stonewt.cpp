#include "stonewt.h"

Stonewt::Stonewt(double lbs, flag forms)
{
    form = forms;
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs, flag forms)
{   
    form = forms;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    stone = stn + int(lbs) / Lbs_per_stn;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()
{
    form = stone_form;
    stone = pds_left = pounds = 0;
}
Stonewt::~Stonewt()
{
   
}
void Stonewt::convert_to_stone()
{
    form = stone_form;
}
void Stonewt::convert_to_pounds_int()
{
    form = pounds_int;
}
void Stonewt::convet_to_pounds_double()
{
    form = pounds_double;
}

Stonewt Stonewt::operator+(const Stonewt &t) const
{
    if(form == stone_form)
    {
        return Stonewt(stone+t.stone,pds_left+t.pds_left);
    }
    else if(form == pounds_double)
    {
        return Stonewt(pounds+t.pounds);
    }
    else 
    {
        return Stonewt(int(pounds + t.pounds));
    }
}
Stonewt Stonewt::operator-(const Stonewt &t) const
{
    if (form == stone_form)
    {
        return Stonewt(stone - t.stone, pds_left - t.pds_left);
    }
    else if (form == pounds_double)
    {
        return Stonewt(pounds - t.pounds);
    }
    else
    {
        return Stonewt(int(pounds - t.pounds));
    }
}
Stonewt Stonewt::operator*(double m) const
{
    if (form == stone_form)
    {
        return Stonewt(stone * m, pds_left * m);
    }
    else if (form == pounds_double)
    {
        return Stonewt(pounds * m);
    }
    else
    {
        return Stonewt(int(pounds * m));
    }
}
Stonewt operator*(double m, const Stonewt &t)
{
    return t * m;
}

std::ostream & operator<<(std::ostream &os, Stonewt & t)
{
    if(t.form == Stonewt::stone_form)
        os << t.stone << " stone, " << t.pds_left << " pounds";
    else if(t.form == Stonewt::pounds_double)
        os << t.pounds << " pounds.\n";
    else
        os << t.stone << " stone, " << t.pds_left << " pounds";
    return os;
}