#include <iostream>
#include "Antylopa.h"

using namespace std;

Antylopa::Antylopa(int x, int y, Swiat* world) : Zwierze(x,y,4,4,'A',"Antylopa",world)
{
    zasieg=2;
};

Zwierze* Antylopa::GetNew(int x, int y)
{
    return new Antylopa(x,y,world);
}

bool Antylopa::czyUcieczka()
{
    int cache=losowa()%2;
    if(cache==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
