#ifndef ABC_H_
#define ABC_H_

#include <iostream>
//abstract Class Using DMA
class abcDMA
{
    private:
        char *label;
        int rating;
    public:
        abcDMA(const char *l = "null",int r = 0);
        abcDMA(const abcDMA &ad);
        virtual ~abcDMA();
        abcDMA &operator=(const abcDMA &ad);
        virtual void View() const = 0;
};
class baseDMA:public abcDMA
{ 
  public:
    baseDMA(const char *l = "null", int r = 0):abcDMA(l,r) { }
    baseDMA(const baseDMA &bs):abcDMA(bs) {}
    virtual ~baseDMA();
    virtual void View() const;
};

//derived class without DMA
class lacksDMA : public abcDMA
{
  private:
    char color[40];

  public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const abcDMA &ls);
    ~lacksDMA();
    virtual void View() const;
};

//derives class with DMA
class hasDMA : public abcDMA
{
  private:
    char *style;

  public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const abcDMA &hs);
    ~hasDMA();
    hasDMA(const hasDMA &hs);
    hasDMA &operator=(const hasDMA &hs);
    virtual void View() const;
};

#endif