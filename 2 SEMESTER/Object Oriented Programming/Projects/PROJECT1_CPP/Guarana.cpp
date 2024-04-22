#include "Guarana.h"

Guarana::Guarana(int x, int y, Swiat* world) : Roslina(x, y, 0, 0, 'G', "Guarana", world) {}

Roslina* Guarana::GetNew(int x, int y) {
    return new Guarana(x, y, world);
}

void Guarana::wplywRosliny(Organizm* zjadajacy) {
    zjadajacy->SetSila(zjadajacy->GetSila() + 3);
    world->DodajDoLog(this->DoStringa() + " zwieksza sile " + zjadajacy->DoStringa());
}
