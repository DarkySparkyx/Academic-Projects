#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
    bool czyUmiejetnoscAktywna;
    int cooldown;
    int czasTrwaniaUmiejetnosci;
public:
    Czlowiek(int x, int y, Swiat* world);
    void akcja() override;
    void superUmiejetnosc();
    Zwierze* GetNew(int x, int y) override;
    void WyswietlInterfejs();

    bool getCzyUmiejetnoscJestAktywna();
    int getCooldown();
    int getCzasTrwaniaUmiejetnosci();

    void setCzyUmiejetnoscJestAktywna(bool val);
    void setCooldown(int val);
    void setCzasTrwaniaUmiejetnosci(int val);

    string DoPliku() override;
};
