#include <iostream>
#include "FiguraPlaska.h"
#include <math.h>

using namespace std;

void Stozek::Wypisz(std::ostream& out) const
{
    cout << "Stozek o wysokosci: " << h << " promieniu: " << r << endl;
    cout << "Tworzaca: " << Tworzaca() << endl;
    cout << "Pole powierzchni bocznej: " << Pole_powierzchni_bocznej() << endl;
    cout << "Pole powierzchni ca³kowitej " << Pole_powierzchni() << endl;
}

Stozek::Stozek(double h,double r) : h(h), r(r)
{
}

void Stozek::setR(double r)
{
    this->r=r;
}

void Stozek::setH(double h)
{
    this->h=h;
}

double Stozek::getH() const
{
    return h;
}

double Stozek::getR() const
{
    return r;
}

double Stozek::Tworzaca() const
{
    return sqrt(r*r+h*h);
}

double Stozek::pole_podstawy() const
{
    return 3.14*r*r;
}

double Stozek::Pole_powierzchni_bocznej() const
{
    return 3.14*r*sqrt(r*r+h*h);
}

double Stozek::Pole_powierzchni() const
{
    return Pole_powierzchni_bocznej() + pole_podstawy();
}

Stozek::~Stozek()
{

}
