#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
    public:
    Lis(int x, int y, Swiat* world);
    Zwierze* GetNew(int x, int y) override;
    bool dobryWech() override;
};
