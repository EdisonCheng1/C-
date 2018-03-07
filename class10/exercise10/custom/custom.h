#ifndef CUSTOM_H_
#define CUSTOM_H_

struct custom
{
    char fullname[35];
    double payment;
};
typedef custom Item;
class Stack
{
    private:
        static const int MAX =10;
        Item items[MAX];
        int top;
    public:
        Stack();
        bool isfull() const;
        bool isempty() const;
        bool push(const Item & item);
        bool pop(Item &item);
};

#endif