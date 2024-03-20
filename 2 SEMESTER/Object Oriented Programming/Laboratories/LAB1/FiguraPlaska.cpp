#include <iostream>
#include "FiguraPlaska.h"

using namespace std;

ostream& operator<<(ostream& os, const FiguraPlaska& figura)
{
    figura.Wypisz(os);
    return os;
}

FiguraPlaska::~FiguraPlaska()
{
}
