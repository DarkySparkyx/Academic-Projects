#pragma once
#include "Roslina.h"
#include "Swiat.h"

class Trawa : public Roslina
{
public:
    Trawa(int x, int y,Swiat* world) : Roslina(x,y,0,0,'T',"Trawa",world) {};
    Roslina* GetNew(int x, int y)
    {
        return new Trawa(x,y,world);
    }
};
