#include "organizm.h"

using namespace std;


class Zwierze : public Organizm {
public:
    Zwierze(int inicjatywa,int sila,Swiat* swiat,string nazwa,char symbol);
    void akcja() override;
    void kolizja() override;

};