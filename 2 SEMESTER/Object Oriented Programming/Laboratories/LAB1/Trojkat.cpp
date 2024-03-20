#include <iostream>
#include "FiguraPlaska.h"
#include <math.h>

using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c)
{
    cout << "Konstruktor Trojkata : " << a << "x" << b << "x" << c << endl;
}

double Trojkat::getA() const
{
    return a;
}

double Trojkat::getB() const
{
    return b;
}

double Trojkat::getC() const
{
    return c;
}

void Trojkat::setA(double a)
{
    this->a=a;
}

void Trojkat::setB(double b)
{
    this->b=b;
}

void Trojkat::setC(double c)
{
    this->c=c;
}

double Trojkat::Obwod() const
{
    return a+b+c;
}
double Trojkat::Pole() const
{
    double p=Obwod()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void Trojkat::Wypisz(ostream& out) const
{
    cout << "Trojkat o wymiarach: " << a << "x" << b << "x" << c << " Pole -> " << Pole() << " Obwod -> " << Obwod() << endl;
}
Trojkat::~Trojkat()
{
    cout << "DESTRUKTOR TROJKATA" << endl;
    cout << a << " " << b << " " << c << endl;
}


