#ifndef ZWIERZE_H
#define ZWIERZE_H
#include <string>
#include "organizm.h"

using namespace std;


class Zwierze : public Organizm {
private:
    string nazwa;
    char symbol;
public:
    Zwierze(int inicjatywa,int sila,Swiat* swiat,string nazwa,char symbol);
    void akcja() override;
    void kolizja() override;

};



#endif //ZWIERZE_H
