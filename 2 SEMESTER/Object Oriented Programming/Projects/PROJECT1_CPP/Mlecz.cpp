#include "Mlecz.h"

Mlecz::Mlecz(int x, int y, Swiat* world) : Roslina(x, y, 0, 0, 'M', "Mlecz", world) {}

Roslina* Mlecz::GetNew(int x, int y) {
    return new Mlecz(x, y, world);
}

void Mlecz::akcja() {
    for (int i = 0; i < 3; i++) {
        Roslina::akcja();
    }
}
