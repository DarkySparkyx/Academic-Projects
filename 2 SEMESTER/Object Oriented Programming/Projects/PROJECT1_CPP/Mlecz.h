#include "Roslina.h"

class Mlecz : public Roslina
{
public:
    Mlecz(int x, int y, Swiat* world);
    Roslina* GetNew(int x, int y) override;
    void akcja() override;
};
