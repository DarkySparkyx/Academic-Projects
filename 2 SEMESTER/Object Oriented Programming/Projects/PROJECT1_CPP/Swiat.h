#pragma once
#include <iostream>
#include <list>
#include "Organizm.h"

using namespace std;

class Swiat
{
private:
    //WYMIARY SWIATA
    int x;
    int y;
    int tura;
    //LISTA ORGANIZMOW
    list<Organizm*> organizmy;
    string logi;
public:
    //KONSTRUKTOR
    Swiat();
    Swiat(FILE* plik);
    //DESTRUKTOR
    ~Swiat();
    //METODY OPERUJACE NA LISCIE OGRANIZMOW
    bool CzyPoleZajete(int newX,int newY);
    void DodajOrganizm(Organizm* org);
    list<Organizm*>::iterator znajdzOrganizm(int x, int y);
    Organizm* getOrganizm(list<Organizm*>::iterator it);
    static void gotoxy(int x,int y);
    void Sprzatacz();

    //FUNKCJONALNOSCI SWIATA
    void wykonajTure();
    void rysujSwiat() const;
    void DodajDoLog(string tekst);
    void WyswietlLog();

    //GETERY
    int getX() const;
    int getY() const;

    //ZAPIS
    void zapiszDoPliku();

};
