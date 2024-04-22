#include "Roslina.h"
#include <iostream>

using namespace std;

Roslina::Roslina(int x, int y,int sila,int inicjatywa,char symbol,string gatunek, Swiat* world) : Organizm(x,y,sila,inicjatywa,symbol,gatunek, world)
{

}

void Roslina::wplywRosliny(Organizm* zjadajacy)
{

}
void Roslina::akcjaSpecjalna()
{

}
void Roslina::akcja()
{
    //ROZMNAZANIE - 5% SZANS
    int czyRozmnazac=losowa()%100;
    if(czyRozmnazac==1)
    {
        int newX,newY;
        if(WybierzPozycjeDlaDziecka(newX,newY))
        {
            world->DodajDoLog(this->DoStringa()+" rozmnaza sie. Nowy organizm typu: " + this->gatunek + "pojawi sie na pozycji ("+to_string(newX)+","+to_string(newY)+")");
            world->DodajOrganizm(GetNew(newX,newY));
        }
    }
    akcjaSpecjalna();
}

void Roslina::kolizja(Organizm* atakujacyOrganizm)
{
    if(atakujacyOrganizm->GetSila()>=this->GetSila())
    {
        world->DodajDoLog(atakujacyOrganizm->DoStringa() + "zjada " + this->DoStringa());
        atakujacyOrganizm->SetPozycja(X,Y);
        this->zabij();
    }
    else
    {
        world->DodajDoLog(atakujacyOrganizm->DoStringa() + "zjada " + this->DoStringa() + "i ginie");
        this->zabij();
        atakujacyOrganizm->zabij();
    }

}

