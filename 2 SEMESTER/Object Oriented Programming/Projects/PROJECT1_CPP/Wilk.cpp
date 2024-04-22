#include <iostream>
#include "Wilk.h"

using namespace std;

Wilk::Wilk(int x, int y,Swiat* world) : Zwierze(x,y,9,5,'W',"Wilk",world)
{

}

Zwierze* Wilk::GetNew(int x, int y)
{
    return new Wilk(x,y, world);
}
