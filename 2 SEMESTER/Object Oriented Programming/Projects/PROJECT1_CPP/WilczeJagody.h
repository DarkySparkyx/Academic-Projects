#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody(int x, int y, Swiat* world);
    Roslina* GetNew(int x, int y) override;
};
