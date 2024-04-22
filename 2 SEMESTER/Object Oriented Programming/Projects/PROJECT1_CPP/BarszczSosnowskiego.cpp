#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* world) : Roslina(x, y, 10, 0, 'B', "Barszcz Sosnowskiego", world) {}

Roslina* BarszczSosnowskiego::GetNew(int x, int y) {
    return new BarszczSosnowskiego(x, y, world);
}

void BarszczSosnowskiego::akcjaSpecjalna() {
    std::string log = this->DoStringa() + " zabija: ";
    bool czyCokolwiek = false;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Organizm* temp = world->getOrganizm(world->znajdzOrganizm(this->X + i, this->Y + j));
            if (temp != nullptr && temp->GetInicjatywa() != 0) {
                log = log + temp->DoStringa() + " ";
                temp->zabij();
                czyCokolwiek = true;
            }
        }
    }
    if (czyCokolwiek) {
        world->DodajDoLog(log);
    }
}
