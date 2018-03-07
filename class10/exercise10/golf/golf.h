#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
    private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
    public:
    Golf();
    Golf(const char * fn ,const int hc);
    const Golf & setgolf(const Golf & g);
    void sethandicap(int hc);
    void showgolf() const;
};
#endif 