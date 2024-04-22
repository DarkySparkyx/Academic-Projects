#pragma once
#include <iostream>
#include "Organizm.h"

using namespace std;

class Zwierze : public Organizm
{
    public:
    Zwierze(int x, int y,int sila,int inicjatywa,char symbol, string gatunek,Swiat* world);
    void akcja() override;
    void kolizja(Organizm* atakujacyOrganzim) override;
    virtual Zwierze* GetNew(int x,int y)=0;
    virtual bool czyUcieczka();
    virtual bool czyOdparcie(int silaAtakujacego);
    virtual bool dobryWech();
};
