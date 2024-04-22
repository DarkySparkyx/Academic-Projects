#pragma once
#include <iostream>
#include "Zwierze.h"

class Wilk : public Zwierze
{
    public:
    Wilk(int x, int y,Swiat* world);
    Zwierze* GetNew(int x, int y) override;
};
