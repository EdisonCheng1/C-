#include "stack.h"
#include <cstring>

Stack::Stack(int n)
{
    pitems = new Item[n];
    top = 0;
    size = 0;
}
Stack::Stack(const Stack &st)   //copy function
{
    pitems = new Item[st.size];
    top = 0;
    size = 0;
    for(int i=0;i<st.size;i++)
    {
       pitems[i] = st.pitems[i];
       size++;
       top++;
    }
}
Stack::~Stack()
{
    delete [] pitems;
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
   return top == MAX;
}
//push() return false if stack already is full,true otherwise
bool Stack::push(const Item &item)
{
    if(top < MAX)
    {
        pitems[top++] = item;
        size++;
        return true;
    }
    else
        return false;
}
//pop() returns false if stack already is empty ,true othewise
bool Stack::pop(Item &item)
{
    if(top > 0)
    {
        item = pitems[--top];
        size--;
        return true; 
    }
    else 
        return false;
}
Stack & Stack::operator=(const Stack &st) //赋值函数
{
    delete [] pitems;
    pitems = new Item[st.size];
    top = 0;
    size = 0;
    for(int i=0;i<st.size;i++)
    {
        pitems[i] = st.pitems[i];
        size++;
        top++;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Stack &st)
{
    os << "The Stack is:\n" << std::endl;
    int len = st.top-1;
    while(len!=-1)
    {
        cout << st.pitems[len] << endl;
        len--;
    } 
    return os;
}