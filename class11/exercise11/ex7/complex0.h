#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
class Complex
{
    private:
        double real;
        double imaginary;
    public:
        Complex(double rel,double img);
        Complex(double rel);
        Complex();
        ~Complex();

        Complex operator+(const Complex &t) const;
        Complex operator-(const Complex &t) const;
        Complex operator*(const Complex &t) const;
        Complex operator*(double m) const;
        Complex operator~() const;

        friend Complex operator*(double m,const Complex & t )
        { return t * m;}
        friend std::ostream & operator<<(std::ostream & os ,const Complex & t );
        friend std::istream & operator>>(std::istream & is, Complex &t);
};
#endif