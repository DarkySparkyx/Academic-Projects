#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat* world) : Roslina(x, y, 99, 0, 'J', "Wilcze Jagody", world) {}

Roslina* WilczeJagody::GetNew(int x, int y) {
    return new WilczeJagody(x, y, world);
}
