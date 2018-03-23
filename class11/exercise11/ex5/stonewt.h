#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
    public:
    enum flag{stone_form,pounds_int,pounds_double};
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        flag form;
    public:
        Stonewt(double lbs,flag forms = pounds_double);
        Stonewt(int stn,double lbs,flag forms = stone_form);
        Stonewt();
        ~Stonewt();
        void convert_to_stone();
        void convert_to_pounds_int();
        void convet_to_pounds_double();

        Stonewt operator+(const Stonewt & t) const;
        Stonewt operator-(const Stonewt & t) const;
        Stonewt operator*(double m) const;

        friend Stonewt operator*(double m,const Stonewt & t);
        friend std::ostream & operator<<(std::ostream & os ,Stonewt & t);
};
#endif