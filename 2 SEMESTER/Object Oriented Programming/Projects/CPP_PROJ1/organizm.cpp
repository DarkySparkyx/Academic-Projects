#include "organizm.h"

using namespace std;

int Organizm::getRandomNumber(int range) {
    srand(time(NULL));
    return rand()%range;
}

Organizm::Organizm(int inicjatywa, int sila, Swiat* swiat,string nazwa,char symbol) : inicjatywa(inicjatywa),sila(sila),swiat(swiat),nazwa(nazwa),symbol(symbol)
{
    positionX=getRandomNumber(positionX);
    positionY=getRandomNumber(positionY);
}

