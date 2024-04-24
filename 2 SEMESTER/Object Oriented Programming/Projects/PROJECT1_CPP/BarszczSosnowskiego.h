#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(int x, int y, Swiat* world);
    Roslina* GetNew(int x, int y) override;
    void akcjaSpecjalna() override;
};
