//stack.h --class declaration for the stack ADT
#include <iostream>
typedef unsigned long Item;
using std::cout;
using std::endl;
class Stack
{
    private:
        enum { MAX = 10};
        Item * pitems;
        int size;
        int top;
    public:
        Stack(int n = MAX);   //create stack with n elements
        Stack(const Stack &st);    //copy function
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        //push() return false if stack already is full,true otherwise
        bool push(const Item & item);
        //pop() returns false if stack already is empty ,true othewise
        bool pop(Item & item);
        Stack & operator=(const Stack & st);    //赋值函数
        friend std::ostream & operator<<(std::ostream &os,const Stack & st);
};