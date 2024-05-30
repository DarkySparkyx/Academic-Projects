#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    int k;
    cin >> k;

    for(int i=0; i<k; i++)
    {
        Graph graf;
        //CIAG STOPNIOWY
        graf.getSortedDegreeTable();

        //LICZBA SKLADOWYCH SPOJNOSCI
        graf.calculateNumberOfComponents();

        //DWUDZIELNOSC
        graf.Bipartition();

        //ACENTRYCZNOSC
        cout << "?" << endl;

        //PLANARNOSC
        cout << "?" << endl;

        //ZACHLANNY
        graf.naiveColoring();

        //LF
        cout << "?" << endl;

        //SLF
        cout << "?" << endl;

        //C4
        cout << "?" << endl;

        //LICZBA KRAWEDZI DOPELNIENIA
        graf.getLiczbaKrawedziDoplenienia();

        //KONIEC ZESTAWU
        cout << endl;
    }

}
