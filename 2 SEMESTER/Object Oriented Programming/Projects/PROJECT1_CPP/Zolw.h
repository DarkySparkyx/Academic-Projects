#include "Zwierze.h"

class Zolw : public Zwierze
{
    public:
    Zolw(int x, int y, Swiat* world);
    Zwierze* GetNew(int x, int y) override;
    bool czyOdparcie(int silaAtakujacego) override;
    void akcja() override;
};
