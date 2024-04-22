#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(int x, int y, Swiat* world);
    Roslina* GetNew(int x, int y) override;
    void wplywRosliny(Organizm* zjadajacy);
};
