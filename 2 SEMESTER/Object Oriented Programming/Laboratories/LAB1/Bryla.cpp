#include <iostream>
#include "FiguraPlaska.h"

using namespace std;

ostream& operator<<(ostream& os, const Bryla& bryl)
{
    bryl.Wypisz(os);
    return os;
}

Bryla::~Bryla()
{
}
