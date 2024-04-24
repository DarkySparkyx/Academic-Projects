#include <iostream>
#include "Swiat.h"
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "1. Uruchom nowa gre" << endl;
    cout << "2. Zaladuj gre z pliku" << endl;
    int wybor;
    cin >> wybor;
    if(wybor==1)
    {
        Swiat gra;
        gra.rysujSwiat();
        while(true)
        {
            gra.wykonajTure();
        }
    }
    else
    {
        FILE* plik;
        plik=fopen("zapis.csv","r");
        Swiat gra(plik);
        gra.rysujSwiat();
        while(true)
        {
            gra.wykonajTure();
        }
    }


    return 0;
}
