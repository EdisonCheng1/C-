#include "complex0.h"

Complex::Complex(double rel,double img)
{
    real = rel;
    imaginary = img;
}
Complex::Complex(double rel)
{
    real = rel;
    imaginary = 0.0;
}
Complex::Complex()
{
    real = imaginary = 0.0;
}
Complex::~Complex()
{

}
Complex Complex::operator+(const Complex &t) const
{
    Complex sum;
    sum.real = real + t.real;
    sum.imaginary = imaginary + t.imaginary;
    return sum;
}
Complex Complex::operator-(const Complex &t) const
{
    Complex diff;
    diff.real = real - t.real;
    diff.imaginary = imaginary - t.imaginary;
    return diff;
}
Complex Complex::operator*(const Complex &t) const
{
    Complex result1;
    result1.real = real * t.real - imaginary * t.imaginary;
    result1.imaginary = real * t.imaginary + imaginary * t.real;
    return result1;
}

Complex Complex::operator~() const
{
    return Complex(real,-imaginary);
}
Complex Complex::operator*(double m) const
{
    Complex result2;
    result2.real = real * m;
    result2.imaginary = imaginary * m;
    return result2;
}

std::ostream & operator<<(std::ostream & os,const Complex & t)
{
    os << "(" << t.real << "," << t.imaginary << "i)";
    return os;
}
std::istream & operator>>(std::istream & is,Complex & t)
{
    std::cout << "Real:";
    if(is >> t.real)
    {
        std::cout << "imaginary: ";
        is >> t.imaginary;   
    }
    return is;
}