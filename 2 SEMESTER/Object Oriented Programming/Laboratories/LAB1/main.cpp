#include <iostream>
#include "FiguraPlaska.h"
using namespace std;

int main()
{
    Stozek *wsk[3];
    for(int i=0;i<3;i++)
    {
        wsk[i]=new Stozek(i+1,i);
    }
    for(int i=0;i<3;i++)
    {
        cout << *wsk[i] << endl;
    }
    for(int i=0;i<3;i++)
    {
        delete wsk[i];
    }
    return 0;
}
