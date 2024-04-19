#include "Swiat.h"

using namespace std;

class   Organizm {
protected:
    int positionX;
    int positionY;
    int inicjatywa;
    int sila;
    string nazwa;
    char symbol;
    int getRandomNumber(int range);
    Swiat* swiat;
public:
    Organizm(int inicjatywa=0,int sila=0,Swiat* swiat=nullptr,string nazwa="",char symbol='X');
    virtual void akcja()=0;
    virtual void kolizja()=0;
    virtual void rysuj()=0;
    ~Organizm();
    void Wyrysuj();

    //GETERY
    int getX();
    int getY();
};