#include <iostream>
#include "organizm.h"
#include <windows.h>

using namespace std;

int Organizm::getRandomNumber(int range) {
    srand(time(NULL));
    return rand()%range;
}
Organizm::Organizm(int inicjatywa, int sila, Swiat* swiat) {
    positionX=getRandomNumber(positionX);
    positionY=getRandomNumber(positionY);
    this->inicjatywa=inicjatywa;
    this->sila=sila;
    this->swiat=swiat;
}
int Organizm::getX() {
    return positionX;
}
int Organizm::getY() {
    return positionY;
}

void Organizm::Wyrysuj() {
    COORD coord;
    coord.X = positionX;
    coord.Y = positionY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    cout << symbol;
}


