#include "Swiat.h"
#ifndef ORGANIZM_H
#define ORGANIZM_H



class   Organizm {
protected:
    int positionX;
    int positionY;
    int inicjatywa;
    int sila;
    int getRandomNumber(int range);
    Swiat* swiat;
public:
    Organizm(int inicjatywa=0,int sila=0,Swiat* swiat=nullptr);
    virtual void akcja()=0;
    virtual void kolizja()=0;
    virtual void rysuj()=0;
    ~Organizm();
    void Wyrysuj();

    //GETERY
    int getX();
    int getY();
};



#endif //ORGANIZM_H
