#include "Lis.h"
#include <iostream>

using namespace std;

Lis::Lis(int x, int y, Swiat* world) : Zwierze(x,y,3,7,'L',"Lis",world)
{

}

Zwierze* Lis::GetNew(int x, int y)
{
    return new Lis(x,y,world);
}

bool Lis::dobryWech()
{
    return true;
}
