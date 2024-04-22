#include "Organizm.h"
#include "Swiat.h"
#include <windows.h>
#include <algorithm>
#include <sstream>
using namespace std;

Organizm::Organizm(int x, int y, int sila,int inicjatywa,char symbol,string gatunek,Swiat* world) : X(x),Y(y),sila(sila),inicjatywa(inicjatywa),symbol(symbol),gatunek(gatunek),world(world)
{
    wiek=0;
    zasieg=1;
    alive=true;
    if(x==0 && y==0)
    {
        while(true)
        {
            this->X=losowa()%world->getX()+1;
            this->Y=losowa()%world->getY()+1;
            if(!world->CzyPoleZajete(X,Y))
                break;
        }
    }
}


int Organizm::GetSila() {
    return sila;
}

int Organizm::GetInicjatywa() {
    return inicjatywa;
}

int Organizm::GetX() {
    return X;
}

int Organizm::GetY() {
    return Y;
}

int Organizm::GetWiek() {
    return wiek;
}

int Organizm::GetZasieg() {
    return zasieg;
}

bool Organizm::IsAlive() {
    return alive;
}

char Organizm::GetSymbol() {
    return symbol;
}

string Organizm::GetGatunek() {
    return gatunek;
}

void Organizm::SetSila(int val) {
    sila = val;
}

void Organizm::SetInicjatywa(int val) {
    inicjatywa = val;
}

void Organizm::SetPozycja(int x, int y)
{
    this->X=x;
    this->Y=y;
}

void Organizm::SetWiek(int val) {
    wiek = val;
}

void Organizm::SetZasieg(int val) {
    zasieg = val;
}

void Organizm::SetAlive(bool val) {
    alive = val;
}

void Organizm::SetSymbol(char val) {
    symbol = val;
}

void Organizm::SetGatunek(string val) {
    gatunek = val;
}

int Organizm::prio(Organizm* A, Organizm* B)
{
    if(A->inicjatywa>B->inicjatywa)
    {
        return 1;
    }
    else if(A->inicjatywa==B->inicjatywa)
    {
        if(A->wiek>=B->wiek)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int Organizm::losowa()
{
    return rand();
}
void Organizm::rysowanie()
{
    Swiat::gotoxy(3+((X-1)*3),Y+1);
    cout << symbol;
}

void Organizm::zabij()
{
    X=-1;
    Y=-1;
    alive=false;
}

void Organizm::WylosujNowaPozycja(int& newX,int& newY)
{
    newX=X+(zasieg*(losowa()%3-1));
    newY=Y+(zasieg*(losowa()%3-1));
    while(CzyPozycjaZla(newX,newY))
    {
        newX=X+(zasieg*(losowa()%3-1));
        newY=Y+(zasieg*(losowa()%3-1));
    }
}
void Organizm::WylosujNowaPozycjaNieZajeta(int& newX,int& newY)
{
    newX=X+(zasieg*(losowa()%3-1));
    newY=Y+(zasieg*(losowa()%3-1));
    while(CzyPozycjaZla(newX,newY) || world->CzyPoleZajete(newX,newY))
    {
        newX=X+(zasieg*(losowa()%3-1));
        newY=Y+(zasieg*(losowa()%3-1));
    }
}
bool Organizm::WybierzPozycjeDlaDziecka(int& newX, int& newY)
{
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            if(!world->CzyPoleZajete(X+j,Y+i) && !CzyPozycjaZla(X+j,Y+i))
            {
                newX=X+j;
                newY=Y+i;
                return 1;
            }
        }
    }
    return 0;
}

bool Organizm::CzyPozycjaZla(int newX,int newY)
{
    return newX>world->getX() || newX<1 || newY>world->getY() || newY<1 || (newX==X && newY==Y);
}

bool Organizm::czyUcieczkaJestMozliwa()
{
    for(int i=-zasieg;i<=zasieg;i=i+zasieg)
    {
        for(int j=-zasieg;j<=zasieg;j=j+zasieg)
        {
            if(i!=0 && j!=0)
            {
                if(!world->CzyPoleZajete(this->GetX()+i,this->GetY()+j))
                   {
                       return true;
                   }
            }
        }
    }
    return false;
}

string Organizm::DoStringa()
{
    char x[10];
    char y[10];
    itoa(X,x,10);
    itoa(Y,y,10);
    string result = gatunek + "(" + x + "," + y + ")";
    return result;
}

string Organizm::DoPliku()
{
    stringstream ss;
    ss << symbol << " " << X << " " << Y << " " << wiek << " " << alive;
    return ss.str();
}
