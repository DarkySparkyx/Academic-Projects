#include "Zwierze.h"

class Antylopa : public Zwierze
{
    public:
    Antylopa(int x, int y, Swiat* world);
    Zwierze* GetNew(int x, int y) override;
    bool czyUcieczka() override;
};
