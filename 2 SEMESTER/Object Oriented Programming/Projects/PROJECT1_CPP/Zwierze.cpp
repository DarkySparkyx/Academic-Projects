#include "Zwierze.h"
#include "Swiat.h"
#include <algorithm>
#include <string>
using namespace std;

Zwierze::Zwierze(int x, int y,int sila,int inicjatywa,char symbol,string gatunek, Swiat* world) : Organizm(x,y,sila,inicjatywa,symbol,gatunek, world)
{

}

void Zwierze::akcja()
{
    wiek++;
    //LOSOWANIE I ZMIANA POZYCJI
    int newX,newY;
    WylosujNowaPozycja(newX,newY);
    //SPRAWDZENIE KOLIZJI
    if(world->CzyPoleZajete(newX,newY))
    {
        auto result = world->znajdzOrganizm(newX,newY);
        (*result)->kolizja(this);
    }
    else
    {
        world->DodajDoLog(this->DoStringa()+"przechodzi na pole ("+to_string(newX)+","+to_string(newY)+")");
        X=newX;
        Y=newY;
    }
}

bool Zwierze::czyOdparcie(int silaAtakujacego)
{
    return false;
}

bool Zwierze::czyUcieczka()
{
    return false;
}

void Zwierze::kolizja(Organizm* atakujacyOrganizm)
{
    Zwierze* atakujacy= (Zwierze*) atakujacyOrganizm;

    if(atakujacy->symbol==this->symbol)
    {
        int newX,newY;
        if(WybierzPozycjeDlaDziecka(newX,newY))
        {
            world->DodajOrganizm(GetNew(newX,newY));
            world->DodajDoLog(atakujacy->DoStringa()+" rozmnaza sie z " + this->DoStringa() + ". Ich potomek pojawi sie na pozycji ("+to_string(newX)+","+to_string(newY)+")");
        }
        else
        {
            world->DodajDoLog(atakujacy->DoStringa()+" probowal rozmnozyc sie z " + this->DoStringa() + ". Brak miejsca dla potomka");
        }
    }
    else
    {
        if(atakujacy->GetSila()>=this->GetSila())
        {
            if(this->czyUcieczka() && this->czyUcieczkaJestMozliwa())
            {
                int newX,newY;
                WylosujNowaPozycjaNieZajeta(newX,newY);
                world->DodajDoLog(atakujacy->DoStringa()+" atakuje "+this->DoStringa()+", ale ofiara ucieka na pole (" + to_string(newX) + "," + to_string(newY) + ").");
                atakujacy->SetPozycja(this->X,this->Y);
                this->SetPozycja(newX,newY);
            }
            else if(czyOdparcie(atakujacy->sila))
            {
                world->DodajDoLog(atakujacy->DoStringa()+" atakuje "+this->DoStringa()+", ale ofiara odpiera atak");
            }
            else
            {
                world->DodajDoLog(atakujacy->DoStringa()+" atakuje "+this->DoStringa()+" i wygrywa. " + this->DoStringa() + "ginie.");
                atakujacy->SetPozycja(this->X,this->Y);
                this->zabij();
            }
        }
        else
        {
            if(atakujacy->czyUcieczka())
            {
                world->DodajDoLog(atakujacy->DoStringa()+" natrafia na silniejszego "+this->DoStringa()+". Udaje sie jednak uniknac walki i wraca na poprzednie pole.");
            }
            else if(atakujacy->dobryWech())
            {
                world->DodajDoLog(atakujacy->DoStringa()+" zweszyl zagrozenie w postaci: " + this->DoStringa() + " i zostaje na swoim miejscu. ");
            }
            else
            {
                world->DodajDoLog(atakujacy->DoStringa()+" natrafia na silniejszego "+this->DoStringa()+" i ginie ");
                atakujacy->zabij();
            }
        }
    }
}

bool Zwierze::dobryWech()
{
    return false;
}
