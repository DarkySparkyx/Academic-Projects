#include "Swiat.h"
#include <iostream>
#include <windows.h>

using namespace std;

Swiat::Swiat() {
    cout << "SYMULATOR ŻYCIA 2024 by MICHAŁ JASIAK" << endl;
    cout << "Podaj wymiary planszy, na której chcesz przeprowadzić symulację" << endl;
    cout << " X: ";
    int x;
    cin >> x;
    cout << " Y: ";
    int y;
    cin >> y;

    this->x=x;
    this->y=y;
}

void Swiat::rysujSwiat() const
{
    //WYSWIETL 1 LINIE
    for(int i=0;i<x;i++)
    {
        if(i<9) {
            cout << " " << i+1 << " ";
        }
        else {
            cout << i+1 << " ";
        }
    }
    cout << endl;
    //WYSWIETL GÓRNĄ GRANICE
    for(int i=0;i<x;i++) {
        cout << "  V";
    }
    cout << endl;
    //WYSWIETL LEWY BRZEG
    for(int i=0;i<y;i++)
    {
        cout << i+1 << ">" << endl;
    }


}

int Swiat::getX() {
    return x;
}

int Swiat::getY() {
    return y;
}




