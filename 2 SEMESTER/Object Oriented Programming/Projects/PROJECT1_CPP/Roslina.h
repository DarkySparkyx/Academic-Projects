#pragma once
#include "Organizm.h"
#include "Swiat.h"

using namespace std;

class Roslina : public Organizm
{
    public:
    Roslina(int x, int y,int sila,int inicjatywa,char symbol,string gatunek, Swiat* world);
    void akcja() override;
    void kolizja(Organizm* atakujacy) override;
    virtual Roslina* GetNew(int x,int y)=0;
    virtual void wplywRosliny(Organizm* zjadajacy);
    virtual void akcjaSpecjalna();
};
