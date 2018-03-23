#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{   
    class Vector
    {
        public:
            enum  Mode{RECT,POL};
        private:
            double x;
            double y;
            
            Mode mode;
            double set_mag() const;
            double set_ang() const;
            void set_x(double mag,double ang);
            void set_y(double mag,double ang);
            
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval()  const {return x;}
            double yval() const {return y;}
            double magval() const {return set_mag();}
            double angval() const {return set_ang();}
            void polar_mode();
            void rect_mode();
            //operator overloading
            Vector operator+(const Vector &b) const;
            Vector operator-(const Vector &b) const;
            Vector operator-() const;
            Vector operator*(double n) const;
            //friends
            friend Vector operator*(double n,const Vector &a);
            friend std::ostream & operator<<(std::ostream & os,const Vector &v);
    };
   //end namespace
}
#endif