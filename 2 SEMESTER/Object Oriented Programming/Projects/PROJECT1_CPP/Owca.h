#include "Zwierze.h"

class Owca : public Zwierze
{
    public:
    Owca(int x, int y, Swiat* world);
    Zwierze* GetNew(int x, int y) override;
};
