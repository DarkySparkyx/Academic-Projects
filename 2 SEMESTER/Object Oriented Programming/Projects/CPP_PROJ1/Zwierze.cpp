#include "Zwierze.h"
#include <iostream>

using namespace std;

Zwierze::Zwierze(int inicjatywa, int sila, Swiat *swiat, string nazwa, char symbol) : Organizm(inicjatywa,sila,swiat)
{
    this->nazwa=nazwa;
    this->symbol=symbol;
}

void Zwierze::akcja() {
    int x=-1;
    int y=-1;
    while(!(x>=0 && x<=swiat->getX() && y>=0 && y<=swiat->getY())) {
         x=getX()+(getRandomNumber(3)-1);
         y=getY()+(getRandomNumber(3)-1);
    }
    positionX=x;
    positionY=y;
}




