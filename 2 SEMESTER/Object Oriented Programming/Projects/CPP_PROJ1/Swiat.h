#ifndef SWIAT_H
#define SWIAT_H

class Swiat {
private:
    //WYMIARY SWIATA
    int x;
    int y;
    void rysujPlansze() const;
public:
    Swiat();
    void wykonajTure();
    void rysujSwiat() const;

};


#endif //SWIAT_H
