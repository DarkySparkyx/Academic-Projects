#include "Zolw.h"
#include <iostream>
using namespace std;

Zolw::Zolw(int x, int y, Swiat* world) : Zwierze(x,y,2,1,'Z',"Zolw",world)
{

};

Zwierze* Zolw::GetNew(int x, int y)
{
    return new Zolw(x,y,world);
}

bool Zolw::czyOdparcie(int silaAtakujacego)
{
    if(silaAtakujacego<5)
        return true;
    else
        return false;
}

void Zolw::akcja()
{
    int liczba=losowa()%4;
    if(liczba==1)
    {
        Zwierze::akcja();
    }

}
