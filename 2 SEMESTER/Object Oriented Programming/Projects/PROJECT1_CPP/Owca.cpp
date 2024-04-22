#include <iostream>
#include "Owca.h"

Owca::Owca(int x, int y, Swiat* world) : Zwierze(x,y,4,4,'O',"Owca",world)
{

}
Zwierze* Owca::GetNew(int x, int y)
{
    return new Owca(x,y,world);
}
