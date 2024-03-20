#include <iostream>
#include "FiguraPlaska.h"

using namespace std;

Kolo::Kolo(double r) : r(r)
{
}

double Kolo::getR() const
{
    return r;
}

void Kolo::setR(double r)
{
    this->r=r;
}

double Kolo::Obwod() const
{
    return 2*3.14*r;
}

double Kolo::Pole() const
{
    return 3.14*r*r;
}

void Kolo::Wypisz(ostream& out) const
{
    cout << "Kolo o promienu: " << r << " Pole -> " << Pole() << " Obwod -> " << Obwod() << endl;
}
Kolo::~Kolo()
{

}


