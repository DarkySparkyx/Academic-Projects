#include <iostream>
#include "Czlowiek.h"
#include "Swiat.h"
#include <conio.h>
#include <sstream>
using namespace std;

Czlowiek::Czlowiek(int x, int y, Swiat* world) : Zwierze(x,y,5,4,'C',"Czlowiek",world)
{

}

void Czlowiek::akcja()
{
    world->rysujSwiat();
    world->WyswietlLog();
    if(czyUmiejetnoscAktywna)
    {
        if(czasTrwaniaUmiejetnosci<=3)
        {
            zasieg=2;
        }
        else
        {
            if(losowa()%2==1)
            {
                zasieg=2;
            }
            else
            {
                zasieg=1;
            }
        }
    }
    else if(cooldown!=0)
    {
        cooldown--;
    }
    WyswietlInterfejs();
    char znak;
    int newX=this->X;
    int newY=this->Y;
    while((X==newX && Y==newY) || CzyPozycjaZla(newX,newY))
    {
        newX=this->X;
        newY=this->Y;
        Swiat::gotoxy(world->getX()*3+3,5);
        znak=getch();
        if(znak==-32)
        {
            znak=getch();
            switch(znak)
            {
            case 75:
                newX=newX-zasieg;
                break;
            case 72:
                newY=newY-zasieg;
                break;
            case 77:
                newX=newX+zasieg;
                break;
            case 80:
                newY=newY+zasieg;
                break;
            default:
                break;
            }
        }
        else if(znak=='R' || znak=='r')
        {
            if(!czyUmiejetnoscAktywna)
            {
                if(cooldown==0)
                {
                    zasieg=2;
                    czasTrwaniaUmiejetnosci=0;
                    cooldown=5;
                    czyUmiejetnoscAktywna=true;
                    WyswietlInterfejs();
                    cout << "Aktywowano umiejetnosc" << endl;

                }
                else
                {
                    cout << "Nie mozesz jeszcze uzyc umiejetnosci" << endl;
                }

            }
            else
            {
                cout << "Umiejetnosc juz jest aktywna" << endl;
            }
        }
        else if(znak==27)
        {
             world->zapiszDoPliku();
            exit(0);
        }
    }

    if(world->CzyPoleZajete(newX,newY))
    {
        auto result = world->znajdzOrganizm(newX,newY);
        (*result)->kolizja(this);
    }
    else
    {
        world->DodajDoLog(this->DoStringa()+"przechodzi na pole ("+to_string(newX)+","+to_string(newY)+")");
        this->SetPozycja(newX,newY);
    }

    if(czasTrwaniaUmiejetnosci==5)
    {
        czyUmiejetnoscAktywna=false;
        zasieg=1;
    }
    else
    {
        czasTrwaniaUmiejetnosci++;
    }
}

Zwierze* Czlowiek::GetNew(int x, int y)
{
    return new Czlowiek(x,y,world);
}

void Czlowiek::WyswietlInterfejs()
{
    Swiat::gotoxy(world->getX()*3+5,1);
    cout << "---> INTERFEJS CZLOWIEKA <----" << endl;
    Swiat::gotoxy(world->getX()*3+9,3);
    cout << "Aktualna pozycja: " << this->GetX() << " " << this->GetY() << " " << sila << endl;
    Swiat::gotoxy(world->getX()*3+9,4);
    cout << "STATUS UMIEJETNOSCI: ";
    if(czyUmiejetnoscAktywna)
        cout << "AKTYWNA -> ILOSC RUND DO KONCA DZIALANIA: " << 6-czasTrwaniaUmiejetnosci << endl;
    else
        cout << "NIEAKTYWNA" << endl;
    Swiat::gotoxy(world->getX()*3+9,5);
    cout << "COOLDOWN: " << cooldown << endl;
    Swiat::gotoxy(world->getX()*3+9,6);
    cout << "ZASIEG RUCHU: " << zasieg << endl;
    Swiat::gotoxy(world->getX()*3+9,7);
}

bool Czlowiek::getCzyUmiejetnoscJestAktywna()
{
    return czyUmiejetnoscAktywna;
}

int Czlowiek::getCooldown()
{
    return cooldown;
}

int Czlowiek::getCzasTrwaniaUmiejetnosci()
{
    return czasTrwaniaUmiejetnosci;
}

void Czlowiek::setCzyUmiejetnoscJestAktywna(bool val)
{
    czyUmiejetnoscAktywna=val;
}

void Czlowiek::setCooldown(int val)
{
    cooldown=val;
}

void Czlowiek::setCzasTrwaniaUmiejetnosci(int val)
{
    czasTrwaniaUmiejetnosci=val;
}

string Czlowiek::DoPliku()
{
    stringstream ss;
    ss << Organizm::DoPliku() << " " << czyUmiejetnoscAktywna << " " << cooldown << " " << czasTrwaniaUmiejetnosci;
    return ss.str();
}
