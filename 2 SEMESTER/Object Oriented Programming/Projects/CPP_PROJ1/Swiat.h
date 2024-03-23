#ifndef SWIAT_H
#define SWIAT_H

class Swiat {
private:
    //WYMIARY SWIATA
    int x;
    int y;
public:
    Swiat();
    void wykonajTure();
    void rysujSwiat() const;
    int getX();
    int getY();

};


#endif //SWIAT_H
