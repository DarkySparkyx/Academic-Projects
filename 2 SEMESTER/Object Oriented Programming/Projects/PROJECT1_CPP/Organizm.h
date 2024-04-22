#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <list>

using namespace std;
class Swiat;

class Organizm
{
public:
    int sila;
    int inicjatywa;
    int X;
    int Y;
    int wiek;
    int zasieg;
    bool alive;
    char symbol;
    string gatunek;
    Swiat* world;
public:
    Organizm(int x, int y,int sila,int inicjatywa,char symbol,string gatunek,Swiat* world);
    void rysowanie();
    void zabij();
    virtual void kolizja(Organizm* atakujacyOrganizm)=0;
    virtual void akcja()=0;
    static int prio(Organizm* A, Organizm* B);
    static int losowa();

    void WylosujNowaPozycja(int& newX, int& newY);
    void WylosujNowaPozycjaNieZajeta(int& newX,int& newY);
    bool WybierzPozycjeDlaDziecka(int& newX, int& newY);
    bool CzyPozycjaZla(int newX,int newY);

    bool czyUcieczkaJestMozliwa();

    string DoStringa();
    virtual string DoPliku();


      //GETERY
    int GetSila();
    int GetInicjatywa();
    int GetX();
    int GetY();
    int GetWiek();
    int GetZasieg();
    bool IsAlive();
    char GetSymbol();
    string GetGatunek();
    //SETERY
    void SetSila(int val);
    void SetInicjatywa(int val);
    void SetPozycja(int x, int y);
    void SetWiek(int val);
    void SetZasieg(int val);
    void SetAlive(bool val);
    void SetSymbol(char val);
    void SetGatunek(string val);
};
