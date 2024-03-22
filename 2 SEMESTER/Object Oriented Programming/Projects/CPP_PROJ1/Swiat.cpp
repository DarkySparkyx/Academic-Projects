#include "Swiat.h"
#include <iostream>

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

void Swiat::rysujPlansze() const
{
    for(int i=0;i<x;i++) {
        if(i<9) {
            cout << " " << i+1 << " ";
        }
        else {
            cout << i+1 << " ";
        }
    }
    cout << endl;
    for(int i=0;i<x;i++) {
        cout << "  V";
    }
    cout << endl;
    for(int i=0;i<y;i++)
        {
            cout << i+1 << ">" << "LOOOOLLLL" << endl;
        }
}

void Swiat::rysujSwiat() const {
    rysujPlansze();
}




