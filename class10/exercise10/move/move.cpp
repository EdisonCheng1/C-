#include <iostream>
#include "move.h"
Move::Move(double a ,double b)
{
    x = a,
    y = b;
}
Move Move::add(const Move &m) const 
{
    Move temp ;
    temp.x = x + m.x;
    temp.y = y + m.y;
    return temp;
}
void Move::showMove() const
{
    using std::cout;
    using std::endl;
    cout << "x: " << x ;
    cout << " y: " << y << endl;
}
void Move::reset(double a,double b)
{
    x = a ;
    y = b ;
}