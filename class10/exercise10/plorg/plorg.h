#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
    private:
        static const int SIZE = 20;
        char name[SIZE];
        int CI;
    public:
        Plorg(const char * na = "Plorga",const int man = 50);
        void setCI(int num) ;
        void show() const;       
};
#endif